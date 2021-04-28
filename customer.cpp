#include "customer.h"
#include "ui_customer.h"
#include <QFileDialog>
#include <QtSql/QSqlDatabase>
#include<QtSql/QSqlQuery>

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

void Customer::setProfile(QString currName, QString currEmail)
{
    name = currName;
    email = currEmail;
    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("/media/mohamed/01D674211A1C18801/AUC/Freshman/Spring 2021/CSCE1101-03 - Fundamentals of Computing II/Project/ProjectDB");
    QSqlQuery query;
    if(database.open())
    {
    ui->EmailLabel->setText("DONEEE");
    query.prepare("INSERT INTO Customers (ID,Name,Email,Photo,Points,NumberOfTrips) VALUES (25,'"+name+"','"+email+"','"+photo+"',0,0)");
    query.exec();
    database.close();
    }
}

void Customer::on_createButton_clicked()
{
    QString currName;
    QString currEmail;
    currName = ui->nameSlot->toPlainText();
    currEmail = ui->emailSlot->toPlainText();
    setProfile(currName,currEmail);
}
void Customer::on_photoButton_clicked()
{
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::AnyFile);
    QString photopath = dialog.getOpenFileName();
    setPhotoPath(photopath);
}
