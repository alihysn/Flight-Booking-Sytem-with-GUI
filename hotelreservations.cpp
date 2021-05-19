#include "hotelreservations.h"
#include "ui_hotelreservations.h"
#include <QMessageBox>
#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlQuery>
#include <QString>
#include<string>
#include<qinputdialog.h>

hotelreservations::hotelreservations(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::hotelreservations)
{
    ui->setupUi(this);
}

hotelreservations::~hotelreservations()
{
    delete ui;
}

void hotelreservations::on_pushButton_clicked()
{
    QString enteredid = QInputDialog::getText(this, "enter","enter the id of your desired hotel");
    QMessageBox box;
    foundhotel = false;
    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("/media/mohamed/01D674211A1C18801/AUC/Freshman/Spring 2021/CSCE1101-03 - Fundamentals of Computing II/Project/ProjectDB");
    database.open();
    QSqlQuery query;
    QString str = ui->lineEdit->text();
    query.exec("SELECT * from Hotel Where ID="+str+"");
    query.exec();
    QString id;
    while (query.next()&& foundhotel == false)
    {
       id = query.value(0).toString();
       if (id == enteredid){
       box.setWindowTitle("your flight has been successfully reserved at:");
       box.setText(id);
       }
    }
    if(foundhotel == false){
    box.setWindowTitle("Failure!");
    box.setText("Your flight could not be found");
    }
    box.exec();
    database.close();
}
