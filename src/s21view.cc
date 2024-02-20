#include "s21view.h"

#include "s21controller.h"
#include "ui_mainwindow.h"

s21::View::View(s21::Controller *c, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), controller(c) {
  ui->setupUi(this);

  connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_dot, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_minus, SIGNAL(clicked()), this,
          SLOT(digits_numbers()));
  connect(ui->pushButton_mult, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_deg, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(funcion()));
  connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(funcion()));
  connect(ui->pushButton_tan, SIGNAL(clicked()), this, SLOT(funcion()));
  connect(ui->pushButton_acos, SIGNAL(clicked()), this, SLOT(funcion()));
  connect(ui->pushButton_asin, SIGNAL(clicked()), this, SLOT(funcion()));
  connect(ui->pushButton_atan, SIGNAL(clicked()), this, SLOT(funcion()));
  connect(ui->pushButton_log, SIGNAL(clicked()), this, SLOT(funcion()));
  connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(funcion()));
  connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(funcion()));
  connect(ui->pushButton_iks, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_open, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_close, SIGNAL(clicked()), this,
          SLOT(digits_numbers()));
}

s21::View::~View() { delete ui; }

void s21::View::on_pushButton_graf_clicked() {
  float step = 0.001;
  QVector<double> x, y;

  QString str = ui->display_main->toPlainText();
  const QByteArray stringData = str.toLocal8Bit();
  std::string s = stringData.data();
  controller->set_string(s);

  double xBegin = ui->xBegin->toPlainText().toDouble();
  double xEnd = ui->xEnd->toPlainText().toDouble();
  ui->widget->clearGraphs();
  x.clear();
  y.clear();

  for (float X = xBegin; X <= xEnd; X += step) {
    controller->set_x(X);
    if (controller->get_check_result()) {
      x.push_back(X);
      y.push_back(controller->get_result());
    }
  }

  ui->widget->addGraph();
  ui->widget->graph(0)->setLineStyle(QCPGraph::lsNone);
  ui->widget->graph(0)->setScatterStyle(
      QCPScatterStyle(QCPScatterStyle::ssDisc, 1));
  ui->widget->graph(0)->addData(x, y);

  ui->widget->xAxis->setRange(-5, 5);
  ui->widget->yAxis->setRange(-5, 5);

  ui->widget->replot();

  ui->widget->setInteraction(QCP::iRangeZoom, true);
  ui->widget->setInteraction(QCP::iRangeDrag, true);
  on_pushButton_ac_clicked();
}

void s21::View::on_radioButton_2_clicked() { FlagX = 1; }

void s21::View::on_radioButton_clicked() { FlagX = 0; }

void s21::View::digits_numbers() {
  QPushButton *button = (QPushButton *)sender();
  if (FlagX == 1) {
    ui->display_x->setText(ui->display_x->toPlainText() + button->text());
  } else {
    ui->display_main->setText(ui->display_main->toPlainText() + button->text());
  }
}

void s21::View::funcion() {
  QPushButton *button = (QPushButton *)sender();
  ui->display_main->setText(ui->display_main->toPlainText() + button->text() +
                            "(");
}

void s21::View::on_pushButton_ac_clicked() {
  ui->display_main->setText("");
  ui->display_x->setText("");
}

void s21::View::on_pushButton_equals_clicked() {
  double x = ui->display_x->toPlainText().toDouble();
  QString str = ui->display_main->toPlainText();
  const QByteArray stringData = str.toLocal8Bit();
  std::string s = stringData.data();

  controller->set_x(x);
  controller->set_string(s);

  if (controller->get_check_result()) {
    QString toStr = QString::number(controller->get_result(), 'g', 8);
    ui->display_main->setText(toStr);
  } else {
    QString toStr = "ERROR";
    ui->display_main->setText(toStr);
  }
}

void s21::View::on_pushButton_cred_calc_clicked() {
  uicr = new s21::Cred_calc(this);
  uicr->show();
}
