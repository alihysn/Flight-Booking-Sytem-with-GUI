#include "customer.h"
#include "ui_customer.h"
#include <QFileDialog>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QMessageBox>

Customer::Customer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Customer)
{
    ui->setupUi(this);
}

Customer::~Customer()
{
    delete ui;
}

void Customer::setPhotoPath(QString path)
{
    photo = path;
}

void Customer::setProfile(QString currName, QString currEmail, QString currUsername, QString passKey)
{
    int lastID;
    password = passKey;
    name = currName;
    email = currEmail;
    username = currUsername;
    NumberOfTrips=0;
    points=0;
    walletMoney=0;
    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("/media/mohamed/01D674211A1C18801/AUC/Freshman/Spring 2021/CSCE1101-03 - Fundamentals of Computing II/Project/ProjectDB");
    QSqlQuery query;
    if(database.open())
    {
    query.exec("Select ID from Customers");
    while (query.next() == true)
    {
        lastID = query.value(0).toInt();
    }
    lastID = lastID+1;
    id = lastID;
    QString lastIDString = QString::number(lastID);
    query.exec("INSERT INTO Customers (ID,Name,Email,Username,Password,Photo,WalletMoney,Points,NumberOfTrips) VALUES ("+lastIDString+",'"+name+"','"+email+"','"+username+"','"+password+"','"+photo+"',0,0,0)");
    database.close();
    }
    ui->emailSlot->setEnabled(false);
    ui->nameSlot->setEnabled(false);
    ui->photoButton->setEnabled(false);
    ui->usernameSlot->setEnabled(false);
    ui->passwordSlot->setEnabled(false);
    QMessageBox message;
    message.setText("Account created successfully !");
    message.exec();
    this->close();
}

void Customer::readData(int idT, QString nam, QString mail, QString userName,QString pass, QString pic, float wall, int pts, int numTrips)
{
    id = idT;
    name = nam;
    email = mail;
    username = userName;
    password = pass;
    photo = pic;
    walletMoney = wall;
    points = pts;
    NumberOfTrips = numTrips;
}

void Customer::on_createButton_clicked()
{
    QString chosenUsername;
    QString currName;
    QString currEmail;
    QString currPass;
    currName = ui->nameSlot->toPlainText();
    currEmail = ui->emailSlot->toPlainText();
    chosenUsername = ui->usernameSlot->toPlainText();
    currPass = ui->passwordSlot->text();
    setProfile(currName,currEmail, chosenUsername, currPass);
}
void Customer::on_photoButton_clicked()
{
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::AnyFile);
    QString photopath = dialog.getOpenFileName();
    setPhotoPath(photopath);
}

void Customer::on_showPassKey_clicked()
{
    if (ui->showPassKey->isChecked() == true)
    {
        ui->passwordSlot->setEchoMode(QLineEdit::Normal);
    }
    else if (ui->showPassKey->isChecked() == false)
    {
        ui->passwordSlot->setEchoMode(QLineEdit::Password);
    }
}
