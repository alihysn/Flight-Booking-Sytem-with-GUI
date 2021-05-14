#include "customerlogin.h"
#include "ui_customerlogin.h"
#include"QMessageBox"

CustomerLogin::CustomerLogin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CustomerLogin)
{
    ui->setupUi(this);
}

CustomerLogin::~CustomerLogin()
{
    delete ui;
}

void CustomerLogin::startWindow(QVector<Customer *> custs, Customer *currCust)
{
    CustomerLogin *login = new CustomerLogin();
    login->currData = custs;
    login->cust = currCust;
    login->show();
}

void CustomerLogin::on_loginButton_clicked()
{
    bool wrong;
    QString u = ui->usernameSlotLogin->text();
    QString p = ui->passwordSlotLogin->text();
    for(int i=0; i<currData.size(); i++)
    {
        if (currData[i]->checker(u,p))
        {
            cust = currData[i];
            QMessageBox box;
            box.setText("Logged in successfully !");
            box.exec();
            wrong = false;
            this->close();
            break;
        }
        else
        {
            wrong = true;
        }
    }
    if (wrong)
    {
        QMessageBox box;
        box.setText("Invalid username/password");
        box.exec();
    }
}

void CustomerLogin::on_showP_clicked()
{
    if (ui->showP->isChecked() == true)
    {
        ui->passwordSlotLogin->setEchoMode(QLineEdit::Normal);
    }
    else if (ui->showP->isChecked() == false)
    {
        ui->passwordSlotLogin->setEchoMode(QLineEdit::Password);
    }
}
