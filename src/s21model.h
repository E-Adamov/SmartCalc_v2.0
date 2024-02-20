#ifndef CALC_SRC_S21MODEL_H_
#define CALC_SRC_S21MODEL_H_

#include <cmath>
#include <string>
#include <vector>

namespace s21 {
class Model {
  using str = std::string;

 public:
  void set_string(const str &str_input) { str_input_ = str_input; }
  void set_x(double x_input) { x_input_ = x_input; }
  double get_result();
  bool get_check_result();
  void calc_cred_annu(double ost_kr, int srok, double pr_stav, int x,
                      double *plat_mes, double *plat_dolg, double *plat_proc,
                      double *vse_dolg, double *vse_proc);
  void calc_cred_diff(double ost_kr, int srok, double pr_stav, int x,
                      double *plat_mes, double *plat_dolg, double *plat_proc,
                      double *vse_dolg, double *vse_proc);

 private:
  typedef struct {
    double number;
    str name;
    int priority;
  } elem_t;

  str str_input_{};
  double x_input_{};
  std::vector<elem_t> input{};  // для перевода из строки в элементы
  std::vector<elem_t> stack{};  // для обратная польская нотация 
  std::vector<elem_t> output{};  // для обратная польская нотация
  std::vector<double> result{};  // для получения результата

  bool split_to_elements(str str_input_, double x_input_);
  void to_polish();
  bool from_polish_to_result();

  bool check_string();
  bool check_bracket(str str_input_);
  bool check_count_result(str name);

  void func_one_arg(double func_res);
  void func_two_arg(double func_res);
  void stackback_move_output();

  void clear();
};
}  // namespace s21

#endif  // CALC_SRC_S21MODEL_H_