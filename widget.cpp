#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    button_disabled();
}

Widget::~Widget()
{

    delete ui;
}

void Widget::button_disabled(){
    ui->pbReset->setEnabled(false);
    ui->pbcoffee->setEnabled(false);
    ui->pbmilk->setEnabled(false);
    ui->pbtea->setEnabled(false);
}
void Widget::button_enabled(){
    ui->pbReset->setEnabled(0 < money);
    ui->pbcoffee->setEnabled(100 <= money);
    ui->pbmilk->setEnabled(150 <= money);
    ui->pbtea->setEnabled(200<= money);
}
void Widget::increase_money(int value){
    money += value;
    ui->lcdNumber->display(money);
}

void Widget::Reset(){
    int values[] = {500, 100, 50, 10};
    int num[] = {0, 0, 0, 0};
    int temp = money;

    for (int i = 0; i < 4; ++i) {
        num[i] = temp / values[i];
        temp %= values[i];
    }

    QString msg;
    QStringList parts;

    if (money >= 500) {
        parts.append(QString("500: %1").arg(num[0]));
        money -= num[0] * 500;
    }
    if (money >= 100) {
        parts.append(QString("100: %1").arg(num[1]));
        money -= num[1] * 100;
    }
    if (money >= 50) {
        parts.append(QString("50: %1").arg(num[2]));
        money -= num[2] * 50;
    }
    if (money >= 10) {
        parts.append(QString("10: %1").arg(num[3]));
        money -= num[3] * 10;
    }

    msg = parts.join("\n");

    QMessageBox mb;
    mb.information(this, "change", msg);
    money = 0;
    ui->lcdNumber->display(money);
}

void Widget::on_pb10_clicked()
{
    increase_money(10);
    button_enabled();
}


void Widget::on_pb50_clicked()
{
    increase_money(50);
    button_enabled();
}


void Widget::on_pb100_clicked()
{
    increase_money(100);
    button_enabled();
}


void Widget::on_pb500_clicked()
{
    increase_money(500);
    button_enabled();
}


void Widget::on_pbcoffee_clicked()
{
    increase_money(-100);
    button_enabled();
}


void Widget::on_pbmilk_clicked()
{
    increase_money(-150);
    button_enabled();
}


void Widget::on_pbtea_clicked()
{
    increase_money(-200);
    button_enabled();
}


void Widget::on_pbReset_clicked()
{
    Reset();
}

