#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    button_enabled();
}

Widget::~Widget()
{

    delete ui;
}

void Widget::button_enabled(){
    ui->pbReset->setEnabled(0 < money);
    ui->pbcoffee->setEnabled(100 <= money);
    ui->pbmilk->setEnabled(150 <= money);
    ui->pbtea->setEnabled(200 <= money);
}
void Widget::increase_money(int value){
    money += value;
    ui->lcdNumber->display(money);
}

void Widget::Reset(){
    int values[] = {500, 100, 50, 10};
    int num[] = {0, 0, 0, 0};
    int temp = money;
    QString msg;
    for (int i = 0; i < sizeof(values)/sizeof(int); ++i) {
        num[i] = temp / values[i];
        temp %= values[i];
        if (money >= values[i]) {
            msg = msg.append(QString("%1: %2\n").arg(values[i]).arg(num[i]));
            money -= num[i] * values[i];
        }
    }
    QMessageBox mb;
    mb.information(this, "change", msg);
    Q_ASSERT(money==0);
    button_enabled();
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

