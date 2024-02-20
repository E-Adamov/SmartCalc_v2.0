#ifndef CALC_SRC_CRED_CALC_H_
#define CALC_SRC_CRED_CALC_H_

#include <QDialog>

#include "s21controller.h"
#include "s21model.h"

namespace Ui {
class Cred_calc;
}

namespace s21 {
class Cred_calc : public QDialog {
  Q_OBJECT

 public:
  explicit Cred_calc(QWidget *parent = nullptr);
  ~Cred_calc();

 private slots:
  void on_pushButton_res_clicked();
  void on_annu_clicked();
  void on_diff_clicked();

 private:
  Ui::Cred_calc *ui;
  int FlagCred;
};
}  // namespace s21

#endif  // CALC_SRC_CRED_CALC_H_
