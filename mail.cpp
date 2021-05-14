#include "mail.h"
#include "ui_mail.h"
#include<QMessageBox>
Mail::Mail(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Mail)
{
    ui->setupUi(this);
}

Mail::~Mail()
{
    delete ui;
}

void Mail::on_pushButton_clicked()
{
    QMessageBox::question(this, "Mail Confirmation","Do you want an email confirmation?",
                              QMessageBox::Yes|QMessageBox::No);

}
