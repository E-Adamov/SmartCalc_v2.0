#include "s21controller.h"

void s21::Controller::set_string(const std::string &str_input) {
  model_->set_string(str_input);
}
void s21::Controller::set_x(double x_input) { model_->set_x(x_input); }
double s21::Controller::get_result() { return model_->get_result(); }
bool s21::Controller::get_check_result() { return model_->get_check_result(); }
void s21::Controller::calc_cred_annu(double ost_kr, int srok, double pr_stav,
                                     int x, double *plat_mes, double *plat_dolg,
                                     double *plat_proc, double *vse_dolg,
                                     double *vse_proc) {
  model_->calc_cred_annu(ost_kr, srok, pr_stav, x, plat_mes, plat_dolg,
                         plat_proc, vse_dolg, vse_proc);
}
void s21::Controller::calc_cred_diff(double ost_kr, int srok, double pr_stav,
                                     int x, double *plat_mes, double *plat_dolg,
                                     double *plat_proc, double *vse_dolg,
                                     double *vse_proc) {
  model_->calc_cred_diff(ost_kr, srok, pr_stav, x, *&plat_mes, *&plat_dolg,
                         *&plat_proc, *&vse_dolg, *&vse_proc);
}
