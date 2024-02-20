#ifndef CALC_SRC_S21CONTROLLER_H_
#define CALC_SRC_S21CONTROLLER_H_
#include "s21model.h"

namespace s21 {
class Controller {
 private:
  Model *model_;

 public:
  Controller() {}
  explicit Controller(Model *m) : model_(m) {}

  void set_string(const std::string &str_input);
  void set_x(double x_input);
  double get_result();
  bool get_check_result();
  void calc_cred_annu(double ost_kr, int srok, double pr_stav, int x,
                      double *plat_mes, double *plat_dolg, double *plat_proc,
                      double *vse_dolg, double *vse_proc);
  void calc_cred_diff(double ost_kr, int srok, double pr_stav, int x,
                      double *plat_mes, double *plat_dolg, double *plat_proc,
                      double *vse_dolg, double *vse_proc);
};
}  // namespace s21

#endif  // CALC_SRC_S21CONTROLLER_H_
