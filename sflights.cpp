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


void SFlights::on_orderbyprice_clicked()
{
    QMessageBox box;
    QVector<float> final;
    Search *searcher = new Search();
    final = searcher->SearchByPriceF();
    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("/media/mohamed/01D674211A1C18801/AUC/Freshman/Spring 2021/CSCE1101-03 - Fundamentals of Computing II/Project/ProjectDB");
    database.open();
    QSqlQuery query;
    query.prepare("SELECT Airline, Price, Rating FROM Flights WHERE Price=10");
    query.exec();
    QString test;
    while (query.next())
    {
        test = query.value(0).toString();
    }
    box.setWindowTitle("sorted by price");
    box.setText(test);
    box.exec();
    database.close();
}

void SFlights::on_orderbyrating_clicked()
{
    QMessageBox box;
    QVector<float> final;
    Search *searcher = new Search();
    final = searcher->SearchByRatingF();
    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("/media/mohamed/01D674211A1C18801/AUC/Freshman/Spring 2021/CSCE1101-03 - Fundamentals of Computing II/Project/ProjectDB");
    database.open();
    QSqlQuery query;
    query.prepare("SELECT Airline, Price, Rating FROM Flights WHERE Rating= final");
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

void SFlights::on_orderoflocation_clicked()
{
    QMessageBox box;
    QString fromm;
   // Search *searcher = new Search();
    //fromm = searcher->SearchByRatingF();
    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("/media/mohamed/01D674211A1C18801/AUC/Freshman/Spring 2021/CSCE1101-03 - Fundamentals of Computing II/Project/ProjectDB");
    database.open();
    QSqlQuery query;
    query.prepare("SELECT Airline, Price, Rating FROM Flights WHERE from= fromm");
    query.exec();
    QString test;
    while (query.next())
    {
        test = query.value(0).toString();
    }
    box.setWindowTitle("list of planes ");
    box.setText(test);
    box.exec();
    database.close();
}
void SFlights::on_orderfordestination_clicked()
{
    QMessageBox box;
    QString too;
   // Search *searcher = new Search();
    //fromm = searcher->SearchByRatingF();
    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("/media/mohamed/01D674211A1C18801/AUC/Freshman/Spring 2021/CSCE1101-03 - Fundamentals of Computing II/Project/ProjectDB");
    database.open();
    QSqlQuery query;
    query.prepare("SELECT Airline, Price, Rating FROM Flights WHERE to= too");
    query.exec();
    QString test;
    while (query.next())
    {
        test = query.value(0).toString();
    }
    box.setWindowTitle("list of planes ");
    box.setText(test);
    box.exec();
    database.close();
}
