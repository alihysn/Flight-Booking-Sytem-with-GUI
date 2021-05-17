#include "sflights.h"
#include "ui_sflights.h"
#include"search.h"
#include<QMessageBox>
#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlQuery>

SFlights::SFlights(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SFlights)
{
    ui->setupUi(this);
}

SFlights::~SFlights()
{
    delete ui;
}


void SFlights::on_pushButton_clicked()
{
    QMessageBox box;
    QVector<float> final;
    Search *searcher = new Search();
    final = searcher->SearchByPrice();
    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("/media/mohamed/01D674211A1C18801/AUC/Freshman/Spring 2021/CSCE1101-03 - Fundamentals of Computing II/Project/ProjectDB");
    database.open();
    QSqlQuery query;
    query.prepare("SELECT Airline, Price FROM Flights WHERE Price=10");
    query.exec();
    QString test;
    while (query.next())
    {
        test = query.value(0).toString();
    }
    box.setWindowTitle(test);
    box.exec();
    database.close();
}
