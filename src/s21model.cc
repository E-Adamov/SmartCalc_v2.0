#include "s21model.h"

void s21::Model::clear() {
  input.clear();
  stack.clear();
  output.clear();
  result.clear();
}

double s21::Model::get_result() {
  clear();
  check_bracket(str_input_);
  split_to_elements(str_input_, x_input_);
  to_polish();
  from_polish_to_result();
  return result.front();
}

bool s21::Model::get_check_result() {
  clear();
  bool res = false;
  if (check_bracket(str_input_)) {
    if (split_to_elements(str_input_, x_input_)) {
      if (check_string()) {
        to_polish();
        if (from_polish_to_result()) {
          res = true;
        }
      }
    }
  }
  return res;
}

bool s21::Model::check_string() {
  bool res = true;
  for (auto it = input.begin(); it < input.end(); ++it) {
    if (res == false) break;
    elem_t elem = *it.base();
    str func = "asinacosatanlnlogsqrt";

    if (func.find(elem.name) != str::npos) {
      if (std::next(it, 1).base()->name != "(") {
        res = false;
      }
    }

    if (str("*/^mod").find(elem.name) != str::npos) {
      if (it == input.begin()) {
        res = false;
      } else if (!(str("x)digital").find(std::prev(it, 1).base()->name) !=
                   str::npos) ||
                 (str("*/^mod)").find(std::next(it, 1).base()->name) !=
                  str::npos)) {
        res = false;
      }
    }
  }
  return res;
}

bool s21::Model::check_bracket(str str_input_) {
  bool res = true;
  int bracket_open{0};
  int bracket_close{0};
  for (auto it = str_input_.begin(); it < str_input_.end(); ++it) {
    if (bracket_close > bracket_open) {
      res = false;
      break;
    }
    if (*it == '(') ++bracket_open;
    if (*it == ')') ++bracket_close;
  }
  if (bracket_close != bracket_open) res = false;
  return res;
}

bool s21::Model::split_to_elements(str str_input_, double x_input_) {
  bool res = true;
  for (auto it = str_input_.begin(); it < str_input_.end();) {
    str digit = "1234567890";
    size_t shift{0};
    elem_t new_elem{};
    str temp_str = it.base();

    if (digit.find(*it) != str::npos) {
      shift = 0;
      double num = std::stod(temp_str, &shift);
      new_elem = {num, "digital", 0};
    } else if (temp_str.compare(0, 1, "x") == 0) {
      shift = 1;
      new_elem = {x_input_, "digital", 0};
    } else if (temp_str.compare(0, 1, "^") == 0) {
      shift = 1;
      new_elem = {0, "^", 5};
    } else if (temp_str.compare(0, 3, "mod") == 0) {
      shift = 3;
      new_elem = {0, "mod", 3};
    } else if (temp_str.compare(0, 3, "cos") == 0) {
      shift = 3;
      new_elem = {0, "cos", 6};
    } else if (temp_str.compare(0, 3, "sin") == 0) {
      shift = 3;
      new_elem = {0, "sin", 6};
    } else if (temp_str.compare(0, 3, "tan") == 0) {
      shift = 3;
      new_elem = {0, "tan", 6};
    } else if (temp_str.compare(0, 4, "acos") == 0) {
      shift = 4;
      new_elem = {0, "acos", 6};
    } else if (temp_str.compare(0, 4, "asin") == 0) {
      shift = 4;
      new_elem = {0, "asin", 6};
    } else if (temp_str.compare(0, 4, "atan") == 0) {
      shift = 4;
      new_elem = {0, "atan", 6};
    } else if (temp_str.compare(0, 4, "sqrt") == 0) {
      shift = 4;
      new_elem = {0, "sqrt", 5};
    } else if (temp_str.compare(0, 2, "ln") == 0) {
      shift = 2;
      new_elem = {0, "ln", 6};
    } else if (temp_str.compare(0, 3, "log") == 0) {
      shift = 3;
      new_elem = {0, "log", 6};
    } else if (temp_str.compare(0, 1, "(") == 0) {
      shift = 1;
      new_elem = {0, "(", 0};
    } else if (temp_str.compare(0, 1, ")") == 0) {
      shift = 1;
      new_elem = {0, ")", 0};
    } else if (temp_str.compare(0, 1, "*") == 0) {
      shift = 1;
      new_elem = {0, "*", 3};
    } else if (temp_str.compare(0, 1, "/") == 0) {
      shift = 1;
      new_elem = {0, "/", 3};
    } else if (temp_str.compare(0, 1, "+") == 0) {
      shift = 1;
      auto prev = std::prev(it, 1);
      str prev_plus = "(+-*/d";
      if (prev_plus.find(*prev) != str::npos || it == str_input_.begin()) {
        new_elem = {0, "un_plus", 4};
      } else if (*prev == '^') {
        new_elem = {0, "st+", 6};
      } else {
        new_elem = {0, "+", 2};
      }
    } else if (temp_str.compare(0, 1, "-") == 0) {
      shift = 1;
      auto prev = std::prev(it, 1);
      str prev_minus = "(+-*/d";
      if ((prev_minus.find(*prev) != str::npos) || it == str_input_.begin()) {
        new_elem = {0, "un_min", 4};
      } else if (*prev == '^') {
        new_elem = {0, "st-", 6};
      } else {
        new_elem = {0, "-", 2};
      }
    } else {
      res = false;
      break;
    }
    input.push_back(new_elem);
    if (shift) std::advance(it, (shift));
  }
  return res;
}

void s21::Model::to_polish() {
  for (auto it = input.begin(); it < input.end(); ++it) {
    str right_associative = "^un_minun_plus";
    elem_t element = *it.base();
    if (element.name == "digital") {
      output.push_back(element);

    } else if (element.name != ")") {
      if (stack.empty() || element.name == "(") {
        stack.push_back(element);
      } else {
        while ((!(right_associative.find(element.name) != str::npos) &&
                stack.back().priority >= element.priority) ||
               ((right_associative.find(element.name) != str::npos) &&
                stack.back().priority > element.priority)) {
          stackback_move_output();
          if (stack.empty()) break;
        }
        stack.push_back(element);
      }

    } else {  // остаётся только ")"
      while (stack.back().name != "(") {
        stackback_move_output();
      }
      if (stack.back().name == "(") stack.pop_back();
    }
  }
  while (!stack.empty()) {
    stackback_move_output();
  }
}

void s21::Model::func_one_arg(double func_res) {
  result.pop_back();
  result.push_back(func_res);
}

void s21::Model::func_two_arg(double func_res) {
  result.pop_back();
  result.pop_back();
  result.push_back(func_res);
}

void s21::Model::stackback_move_output() {
  output.push_back(stack.back());
  stack.pop_back();
}

bool s21::Model::check_count_result(s21::Model::str name) {
  bool res = true;
  if (str("+-*/^mod").find(name) != str::npos) {
    if (result.size() < 2) res = false;
  } else {
    if (result.size() < 1) res = false;
  }
  return res;
}

bool s21::Model::from_polish_to_result() {
  bool res = true;
  for (auto it = output.begin(); it < output.end(); ++it) {
    elem_t element = *it.base();
    if (element.name == "digital") {
      result.push_back(element.number);
    } else {
      double a{0}, b{0};
      if (check_count_result(element.name)) {
        if (result.size() > 1) a = *(result.end() - 2);
        b = *(result.end() - 1);
      } else {
        res = false;
        break;
      }
      if (element.name == "+")
        func_two_arg(a + b);
      else if (element.name == "-")
        func_two_arg(a - b);
      else if (element.name == "*")
        func_two_arg(a * b);
      else if (element.name == "/")
        func_two_arg(a / b);
      else if (element.name == "^")
        func_two_arg(pow(a, b));
      else if (element.name == "mod")
        func_two_arg(fmod(a, b));
      else if (element.name == "un_plus")
        func_one_arg(b);
      else if (element.name == "un_min")
        func_one_arg(-1 * b);
      else if (element.name == "cos")
        func_one_arg(cos(b));
      else if (element.name == "sin")
        func_one_arg(sin(b));
      else if (element.name == "tan")
        func_one_arg(tan(b));
      else if (element.name == "acos")
        func_one_arg(acos(b));
      else if (element.name == "asin")
        func_one_arg(asin(b));
      else if (element.name == "atan")
        func_one_arg(atan(b));
      else if (element.name == "sqrt")
        func_one_arg(sqrt(b));
      else if (element.name == "ln")
        func_one_arg(log(b));
      else if (element.name == "log")
        func_one_arg(log10(b));
      else if (element.name == "st+")
        func_one_arg(b);
      else if (element.name == "st-")
        func_one_arg(-1 * b);
    }
  }

  if (result.size() == 1) {
    if (std::isnan(result.front())) res = false;
    if (std::isinf(result.front())) res = false;
  } else {
    res = false;
  }

  return res;
}

void s21::Model::calc_cred_annu(double ost_kr, int srok, double pr_stav, int x,
                                double *plat_mes, double *plat_dolg,
                                double *plat_proc, double *vse_dolg,
                                double *vse_proc) {
  *vse_proc = 0;
  *vse_dolg = ost_kr;
  double dol_proc = pr_stav / 1200.0;

  *plat_mes =
      ost_kr * (dol_proc + (dol_proc / (pow((1.0 + dol_proc), srok) - 1.0)));

  for (int i = 0; i < x; i++) {
    *plat_proc = ost_kr * dol_proc;
    *plat_dolg = *plat_mes - *plat_proc;
    ost_kr = ost_kr - *plat_dolg;
    *vse_proc += *plat_proc;
  }
  *vse_dolg += *vse_proc;
}

void s21::Model::calc_cred_diff(double ost_kr, int srok, double pr_stav, int x,
                                double *plat_mes, double *plat_dolg,
                                double *plat_proc, double *vse_dolg,
                                double *vse_proc) {
  *vse_proc = 0;
  *vse_dolg = ost_kr;
  double dol_proc = pr_stav / 1200.0;

  *plat_dolg = ost_kr / srok;

  for (int i = 0; i < x; i++) {
    *plat_proc = ost_kr * dol_proc;
    *plat_mes = *plat_dolg + *plat_proc;
    ost_kr = ost_kr - *plat_dolg;
    *vse_proc += *plat_proc;
  }
  *vse_dolg += *vse_proc;
}
