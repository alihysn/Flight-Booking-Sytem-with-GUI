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

void CustomerLogin::startWindow(QVector<Customer *> custs, int *index, bool *isLoggedIN)
{
    CustomerLogin *login = new CustomerLogin();
    login->currData = custs;
    login->number = index;
    login->loggedIn = isLoggedIN;
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

            QMessageBox box;
            box.setText("Logged in successfully !");
            box.exec();
            *number = i;
            wrong = false;
            *loggedIn = true;
            this->close();
            break;
        }
        else
        {
            wrong = true;
            *loggedIn = false;
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
