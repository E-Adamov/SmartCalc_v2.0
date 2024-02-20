#include <gtest/gtest.h>

#include <cmath>

#include "s21model.h"
const double eps = 1e-7;

TEST(calc_test, test_add1) {
  s21::Model model;

  model.set_string("1.23456789+0.987654");
  ASSERT_TRUE(model.get_check_result());
  double result = 1.23456789 + 0.987654;
  EXPECT_NEAR(model.get_result(), result, eps);
}

TEST(calc_test, test_add2) {
  s21::Model model;

  model.set_string("1.23456789+x");
  model.set_x(0.987654321);
  ASSERT_TRUE(model.get_check_result());
  double result = 1.23456789 + 0.987654321;
  EXPECT_NEAR(model.get_result(), result, eps);
}

TEST(calc_test, test_sud1) {
  s21::Model model;

  model.set_string("1.23456789-0.987654");
  ASSERT_TRUE(model.get_check_result());
  double result = 1.23456789 - 0.987654;
  EXPECT_NEAR(model.get_result(), result, eps);
}

TEST(calc_test, test_sub2) {
  s21::Model model;

  model.set_string("1.23456789-x");
  model.set_x(0.987654);
  ASSERT_TRUE(model.get_check_result());
  double result = 1.23456789 - 0.987654;
  EXPECT_NEAR(model.get_result(), result, eps);
}

TEST(calc_test, test_mul1) {
  s21::Model model;

  model.set_string("1.23456789*0.987654");
  ASSERT_TRUE(model.get_check_result());
  double result = 1.23456789 * 0.987654;
  EXPECT_NEAR(model.get_result(), result, eps);
}

TEST(calc_test, test_mul2) {
  s21::Model model;

  model.set_string("1.23456789*x");
  model.set_x(0.987654);
  ASSERT_TRUE(model.get_check_result());
  double result = 1.23456789 * 0.987654;
  EXPECT_NEAR(model.get_result(), result, eps);
}

TEST(calc_test, test_div1) {
  s21::Model model;

  model.set_string("1.23456789/0.987654");
  ASSERT_TRUE(model.get_check_result());
  double result = 1.23456789 / 0.987654;
  EXPECT_NEAR(model.get_result(), result, eps);
}

TEST(calc_test, test_div2) {
  s21::Model model;

  model.set_string("1.23456789/x");
  model.set_x(0.987654);
  ASSERT_TRUE(model.get_check_result());
  double result = 1.23456789 / 0.987654;
  EXPECT_NEAR(model.get_result(), result, eps);
}

TEST(calc_test, test_pow1) {
  s21::Model model;

  model.set_string("1.23456789^0.987654");
  ASSERT_TRUE(model.get_check_result());
  double result = pow(1.23456789, 0.987654);
  EXPECT_NEAR(model.get_result(), result, eps);
}

TEST(calc_test, test_pow2) {
  s21::Model model;

  model.set_string("1.23456789^x");
  model.set_x(0.987654);
  ASSERT_TRUE(model.get_check_result());
  double result = pow(1.23456789, 0.987654);
  EXPECT_NEAR(model.get_result(), result, eps);
}

TEST(calc_test, test_pow3) {
  s21::Model model;

  model.set_string("2^2^3");
  ASSERT_TRUE(model.get_check_result());
  double result = (pow(2, pow(2, 3)));
  EXPECT_NEAR(model.get_result(), result, eps);
}

TEST(calc_test, test_pow4) {
  s21::Model model;

  model.set_string("5^(3^3)");
  ASSERT_TRUE(model.get_check_result());
  double result = (pow(5, pow(3, 3)));
  EXPECT_NEAR(model.get_result(), result, eps);
}

TEST(calc_test, test_pow5) {
  s21::Model model;

  model.set_string("(4^10)^3");
  ASSERT_TRUE(model.get_check_result());
  double result = pow(pow(4, 10), 3);
  EXPECT_NEAR(model.get_result(), result, eps);
}

TEST(calc_test, test_mod1) {
  s21::Model model;

  model.set_string("1.23456789mod0.987654");
  ASSERT_TRUE(model.get_check_result());
  double result = fmod(1.23456789, 0.987654);
  EXPECT_NEAR(model.get_result(), result, eps);
}

TEST(calc_test, test_mod2) {
  s21::Model model;

  model.set_string("1.23456789modx");
  model.set_x(0.987654);
  ASSERT_TRUE(model.get_check_result());
  double result = fmod(1.23456789, 0.987654);
  EXPECT_NEAR(model.get_result(), result, eps);
}

TEST(calc_test, test_un1) {
  s21::Model model;

  model.set_string("-1.23456789");
  ASSERT_TRUE(model.get_check_result());
  double result = -1.23456789;
  EXPECT_NEAR(model.get_result(), result, eps);
}

TEST(calc_test, test_un2) {
  s21::Model model;

  model.set_string("+1.23456789");
  ASSERT_TRUE(model.get_check_result());
  double result = +1.23456789;
  EXPECT_NEAR(model.get_result(), result, eps);
}

TEST(calc_test, test_un3) {
  s21::Model model;

  model.set_string("+x");
  model.set_x(1.23456789);
  ASSERT_TRUE(model.get_check_result());
  double result = +1.23456789;
  EXPECT_NEAR(model.get_result(), result, eps);
}

TEST(calc_test, test_un4) {
  s21::Model model;

  model.set_string("-x");
  model.set_x(1.23456789);
  ASSERT_TRUE(model.get_check_result());
  double result = -1.23456789;
  EXPECT_NEAR(model.get_result(), result, eps);
}

TEST(calc_test, test_cos1) {
  s21::Model model;

  model.set_string("2*cos(2*x)-2");
  model.set_x(1);
  ASSERT_TRUE(model.get_check_result());
  double result = 2 * cos(2 * 1) - 2;
  EXPECT_NEAR(model.get_result(), result, eps);
}

TEST(calc_test, test_sin1) {
  s21::Model model;

  model.set_string("2*sin(2*x)-2");
  model.set_x(1);
  ASSERT_TRUE(model.get_check_result());
  double result = 2 * sin(2 * 1) - 2;
  EXPECT_NEAR(model.get_result(), result, eps);
}

TEST(calc_test, test_tan1) {
  s21::Model model;

  model.set_string("2*tan(2*x)-2");
  model.set_x(1);
  ASSERT_TRUE(model.get_check_result());
  double result = 2 * tan(2 * 1) - 2;
  EXPECT_NEAR(model.get_result(), result, eps);
}

TEST(calc_test, test_acos1) {
  s21::Model model;

  model.set_string("2*acos(x)-2");
  model.set_x(0.5);
  ASSERT_TRUE(model.get_check_result());
  double result = 2 * acos(0.5) - 2;
  EXPECT_NEAR(model.get_result(), result, eps);
}

TEST(calc_test, test_asin1) {
  s21::Model model;

  model.set_string("2*asin(x)-2");
  model.set_x(0.5);
  ASSERT_TRUE(model.get_check_result());
  double result = 2 * asin(0.5) - 2;
  EXPECT_NEAR(model.get_result(), result, eps);
}

TEST(calc_test, test_atan1) {
  s21::Model model;

  model.set_string("2*atan(2*x)-2");
  model.set_x(1);
  ASSERT_TRUE(model.get_check_result());
  double result = 2 * atan(2 * 1) - 2;
  EXPECT_NEAR(model.get_result(), result, eps);
}

TEST(calc_test, test_sqrt1) {
  s21::Model model;

  model.set_string("2*sqrt(2*x)-2");
  model.set_x(1);
  ASSERT_TRUE(model.get_check_result());
  double result = 2 * sqrt(2 * 1) - 2;
  EXPECT_NEAR(model.get_result(), result, eps);
}

TEST(calc_test, test) {
  s21::Model model;

  model.set_string("-5^-1");
  ASSERT_TRUE(model.get_check_result());
  double result = pow(-5, -1);
  EXPECT_NEAR(model.get_result(), result, eps);
}

TEST(calc_test, test_un_pow1) {
  s21::Model model;

  model.set_string("-5^x");
  model.set_x(-1);
  ASSERT_TRUE(model.get_check_result());
  double result = pow(-5, -1);
  EXPECT_NEAR(model.get_result(), result, eps);
}

TEST(calc_test, test_un_pow2) {
  s21::Model model;

  model.set_string("-5^+x");
  model.set_x(-1);
  ASSERT_TRUE(model.get_check_result());
  double result = pow(-5, +(-1));
  EXPECT_NEAR(model.get_result(), result, eps);
}

TEST(calc_test, test_ln1) {
  s21::Model model;

  model.set_string("2*ln(2*x)-2");
  model.set_x(1);
  ASSERT_TRUE(model.get_check_result());
  double result = 2 * log(2 * 1) - 2;
  EXPECT_NEAR(model.get_result(), result, eps);
}

TEST(calc_test, test_log1) {
  s21::Model model;

  model.set_string("2*log(2*x)-2");
  model.set_x(1);
  ASSERT_TRUE(model.get_check_result());
  double result = 2 * log10(2 * 1) - 2;
  EXPECT_NEAR(model.get_result(), result, eps);
}

TEST(calc_test, test_diff1) {
  s21::Model model;

  model.set_string("(-cos(-2^4)^2)*5/3+(ln(sqrt(25))+-(sin(-4)))");
  ASSERT_TRUE(model.get_check_result());
  double result = -0.6758840499614303;
  EXPECT_NEAR(model.get_result(), result, eps);
}

TEST(calc_test, test_diff2) {
  s21::Model model;

  model.set_string("(5+10/1.1+sin(1))/sqrt(2)");
  ASSERT_TRUE(model.get_check_result());
  double result = 10.558787210794447;
  EXPECT_NEAR(model.get_result(), result, eps);
}

TEST(calc_test, test_diff3) {
  s21::Model model;

  model.set_string("atan(x+2)-cos(1+x/(3-x))^(2*x^(1/2))");
  model.set_x(0.1);
  ASSERT_TRUE(model.get_check_result());
  double result = 0.472383675629815421127129;
  EXPECT_NEAR(model.get_result(), result, eps);
}

TEST(calc_test, test_diff4) {
  s21::Model model;

  model.set_string("-(-acos(0.5))");
  model.set_x(0.1);
  ASSERT_TRUE(model.get_check_result());
  double result = -(-acos(0.5));
  EXPECT_NEAR(model.get_result(), result, eps);
}

TEST(calc_test, test_calc_cred_annu_1) {
  s21::Model model;

  double ost_kr = 100000;
  int srok = 12;
  double pr_stav = 12;
  int x = 11;

  double plat_mes, plat_dolg, plat_proc, vse_dolg, vse_proc;
  double check_origin = 8884.88;

  model.calc_cred_annu(ost_kr, srok, pr_stav, x, &plat_mes, &plat_dolg,
                       &plat_proc, &vse_dolg, &vse_proc);
  EXPECT_NEAR(plat_mes, check_origin, 1e-2);
}

TEST(calc_test, test_calc_cred_diff_1) {
  s21::Model model;

  double ost_kr = 100000;
  int srok = 12;
  double pr_stav = 12;
  int x = 11;

  double plat_mes, plat_dolg, plat_proc, vse_dolg, vse_proc;
  double check_origin = 8333.33;

  model.calc_cred_diff(ost_kr, srok, pr_stav, x, &plat_mes, &plat_dolg,
                       &plat_proc, &vse_dolg, &vse_proc);
  EXPECT_NEAR(plat_dolg, check_origin, 1e-2);
}

TEST(calc_test, test_err) {
  s21::Model model;

  std::string inputStr = "34.4+34/3";
  model.set_string(inputStr);
  ASSERT_TRUE(model.get_check_result());

  inputStr = "34..4+5";
  model.set_string(inputStr);
  ASSERT_FALSE(model.get_check_result());

  inputStr = "34./.4+5";
  model.set_string(inputStr);
  ASSERT_FALSE(model.get_check_result());

  inputStr = "--34+5";
  model.set_string(inputStr);
  ASSERT_TRUE(model.get_check_result());

  inputStr = "*34+5";
  model.set_string(inputStr);
  ASSERT_FALSE(model.get_check_result());

  inputStr = "34*-5";
  model.set_string(inputStr);
  ASSERT_TRUE(model.get_check_result());

  inputStr = "34-*5";
  model.set_string(inputStr);
  ASSERT_FALSE(model.get_check_result());

  inputStr = "-(2*2)";
  model.set_string(inputStr);
  ASSERT_TRUE(model.get_check_result());

  inputStr = "mod";
  model.set_string(inputStr);
  ASSERT_FALSE(model.get_check_result());

  inputStr = "2mod";
  model.set_string(inputStr);
  ASSERT_FALSE(model.get_check_result());

  inputStr = "2mod/3";
  model.set_string(inputStr);
  ASSERT_FALSE(model.get_check_result());

  inputStr = "2mod(3)";
  model.set_string(inputStr);
  ASSERT_TRUE(model.get_check_result());

  inputStr = ")2+2";
  model.set_string(inputStr);
  ASSERT_FALSE(model.get_check_result());

  inputStr = "2(+)3";
  model.set_string(inputStr);
  ASSERT_FALSE(model.get_check_result());

  inputStr = "2+(*3)";
  model.set_string(inputStr);
  ASSERT_FALSE(model.get_check_result());

  inputStr = "*mod20";
  model.set_string(inputStr);
  ASSERT_FALSE(model.get_check_result());

  inputStr = "sin2";
  model.set_string(inputStr);
  ASSERT_FALSE(model.get_check_result());
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
