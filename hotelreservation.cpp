#include "hotelreservation.h"
#include "ui_hotelreservation.h"
#include<QMessageBox>
#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlQuery>

hotelreservation::hotelreservation(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::hotelreservation)
{
    ui->setupUi(this);
}

hotelreservation::~hotelreservation()
{
    delete ui;
}

void hotelreservation::on_pushButton_clicked()
{
    QString enteredid = ui->lineEdit->text();
    QMessageBox box;
    bool foundhotel = false;
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
