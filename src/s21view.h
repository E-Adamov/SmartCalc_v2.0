#ifndef CALC_SRC_S21VIEW_H_
#define CALC_SRC_S21VIEW_H_

#include <QMainWindow>
#include <QString>
#include <QVector>

#include "cred_calc.h"
#include "s21controller.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

namespace s21 {
class View : public QMainWindow {
  Q_OBJECT

 public:
  explicit View(s21::Controller *c, QWidget *parent = nullptr);
  ~View();

 private:
  Ui::MainWindow *ui;
  Cred_calc *uicr;
  s21::Controller *controller;
  int FlagX;

 private slots:
  void digits_numbers();
  void funcion();
  void on_pushButton_ac_clicked();
  void on_pushButton_equals_clicked();
  void on_radioButton_2_clicked();
  void on_radioButton_clicked();
  void on_pushButton_graf_clicked();
  void on_pushButton_cred_calc_clicked();
};
}  // namespace s21
#endif  // CALC_SRC_S21VIEW_H_
