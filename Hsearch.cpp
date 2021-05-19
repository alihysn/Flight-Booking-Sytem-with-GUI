#include "Hsearch.h"
#include "ui_Hsearch.h"
#include <QMessageBox>
#include "search.h"
#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlQuery>
#include <QString>

Hsearch::Hsearch(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Hsearch)
{
    ui->setupUi(this);
}

Hsearch::~Hsearch()
{
    delete ui;
}

void Hsearch::on_pushButton_clicked()
{

    QMessageBox box;
    QVector<float> final;
    Search *searcher = new Search();
    final = searcher->SearchByPriceH();
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

void Hsearch::on_pushButton_2_clicked()
{

    QMessageBox box;
    QVector<float> final;
    Search *searcher = new Search();
    final = searcher->SearchByRatingH();
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
    box.setWindowTitle("hotels by rating");
    box.setText(test);
    box.exec();
    database.close();
}

void Hsearch::on_pushButton_3_clicked()
{
    QMessageBox box;
    QVector<float> final;
    Search *searcher = new Search();
    final = searcher->SearchByDistancefromairport();
    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("/media/mohamed/01D674211A1C18801/AUC/Freshman/Spring 2021/CSCE1101-03 - Fundamentals of Computing II/Project/ProjectDB");
    database.open();
    QSqlQuery query;
    query.prepare("SELECT Price, Rating FROM Flights WHERE DistanceFromAirport = final");
    query.exec();
    QString test;
    while (query.next())
    {
        test = query.value(0).toString();
    }
    box.setWindowTitle("hotels by distance");
    box.setText(test);
    box.exec();
    database.close();
}

void Hsearch::on_pushButton_4_clicked()
{

    QMessageBox box;
    QVector <QString>  city;
    //Search *searcher = new Search();
    //final = searcher->SearchByRatingH();
    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("/media/mohamed/01D674211A1C18801/AUC/Freshman/Spring 2021/CSCE1101-03 - Fundamentals of Computing II/Project/ProjectDB");
    database.open();
    QSqlQuery query;
    query.prepare("SELECT Price, Rating FROM Hotels WHERE to = city");
    query.exec();
    QString test;
    while (query.next())
    {
        test = query.value(0).toString();
    }
    box.setWindowTitle("hotels by cities");
    box.setText(test);
    box.exec();
    database.close();
}
