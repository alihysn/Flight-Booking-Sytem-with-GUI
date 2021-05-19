#include "creditpay.h"
#include "ui_creditpay.h"
#include"card.h"

creditPay::creditPay(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::creditPay)
{
    ui->setupUi(this);
}

creditPay::~creditPay()
{
    delete ui;
}

void creditPay::on_pushButton_clicked()
{
    QString number = ui->lineEdit->text();
    QString pin = ui->lineEdit->text();
    QString expiry = ui->lineEdit_4->text();
    QString from = ui->lineEdit_3->text();
    Card cardClass;
    cardClass.Pay(number, pin, from, expiry);
}
