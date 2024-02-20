#include "cred_calc.h"

#include "ui_cred_calc.h"

s21::Cred_calc::Cred_calc(QWidget *parent)
    : QDialog(parent), ui(new Ui::Cred_calc) {
  ui->setupUi(this);
}

s21::Cred_calc::~Cred_calc() { delete ui; }

void s21::Cred_calc::on_pushButton_res_clicked() {
  s21::Controller controller;
  double ost_kr;
  int srok;
  double pr_stav;
  double plat_mes, plat_dolg, plat_proc, vse_dolg, vse_proc;
  QString toStr;

  ost_kr = ui->ost_kr->toPlainText().toDouble();
  srok = ui->srok->toPlainText().toInt();
  pr_stav = ui->pr_stav->toPlainText().toDouble();
  toStr.append("месяц\tплатеж\tплат/долг\tплат/проц\n");
  for (int x = 1; x < srok + 1; x++) {
    if (FlagCred == 1) {
      controller.calc_cred_diff(ost_kr, srok, pr_stav, x, &plat_mes, &plat_dolg,
                                &plat_proc, &vse_dolg, &vse_proc);
    } else {
      controller.calc_cred_annu(ost_kr, srok, pr_stav, x, &plat_mes, &plat_dolg,
                                &plat_proc, &vse_dolg, &vse_proc);
    }
    QString toStrx = QString::number(x, 'g', 6);
    QString toStr1 = QString::number(plat_mes, 'd', 2);
    QString toStr2 = QString::number(plat_dolg, 'd', 2);
    QString toStr3 = QString::number(plat_proc, 'd', 2);
    toStr.append(
        tr("%1\t%2\t%3\t%4\n").arg(toStrx).arg(toStr1).arg(toStr2).arg(toStr3));
  }
  ui->display->setText(toStr);
  QString toStr4 = QString::number(vse_dolg, 'd', 2);
  ui->vse_dolg->setText(toStr4);
  QString toStr5 = QString::number(vse_proc, 'd', 2);
  ui->vse_proc->setText(toStr5);
}

void s21::Cred_calc::on_annu_clicked() { FlagCred = 0; }

void s21::Cred_calc::on_diff_clicked() { FlagCred = 1; }
