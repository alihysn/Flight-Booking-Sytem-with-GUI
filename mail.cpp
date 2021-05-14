#include "mail.h"
#include "ui_mail.h"
#include<QMessageBox>

mail::mail(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mail)
{
    ui->setupUi(this);
}

mail::~mail()
{
    delete ui;
}

void mail::on_pushButton_clicked()
{
    QMessageBox::StandardButton reply=QMessageBox::question(this, "Mail Confirmation","Do you want an email confirmation?",QMessageBox::Yes|QMessageBox::No);
     QMessageBox Box;
    if (reply==QMessageBox::No)
    {
        Box.setText(" An email will not be sent");
        Box.setWindowTitle("Mail Confrimation");
        Box.exec();
        this->close();}
    else

       { Box.setText(" An email has been sent");
         Box.setWindowTitle(" Mail Confrimation");
         Box.exec();
         this->close();
}
}
