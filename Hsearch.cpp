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
    ui->comboBox->addItem("Cairo");
    ui->comboBox->addItem("Rome");
    ui->comboBox->addItem("Paris");
    ui->comboBox->addItem("California");
    ui->comboBox->addItem("Capetown");
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
    int i=0;
    do
    {
    QString str= QString::number(final[i]);
    QSqlQuery query;
    query.exec("SELECT * FROM Hotels WHERE Price="+str+"");
    QString test;
    while (query.next())
    {
        test = query.value(0).toString();
break;
}
    box.setWindowTitle("sorted by price");
    box.setText(test);
    box.exec();
    i=i+1;
    }while(i<final.size());
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
    int i=0;
       do
       {
       QString str= QString::number(final[i]);
       QSqlQuery query;
       query.exec("SELECT Airline, Price, Rating FROM Hotels WHERE Rating= "+str+"");
       QString test;
       while (query.next())
       {
           test = query.value(0).toString();
       break;
       }
       box.setWindowTitle("hotels by rating");
      box.setText(test);
       box.exec();
       i=i+1;
       }while(i<final.size());
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
    int i=0;
    do
    {
           QString str= QString::number(final[i]);
    QSqlQuery query;
    query.exec("SELECT Price, Rating FROM Flights WHERE DistanceFromAirport = "+str+"");
    QString test;
    while (query.next())
    {
        test = query.value(0).toString();
        break;
    }
    box.setWindowTitle("hotels by distance");
    box.setText(test);
    box.exec();
    i=i+1;
    } while(i<final.size());
    database.close();
}
void Hsearch::on_pushButton_4_clicked()
{

    QMessageBox box;
    QString  city=ui->comboBox->currentText();
    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("/media/mohamed/01D674211A1C18801/AUC/Freshman/Spring 2021/CSCE1101-03 - Fundamentals of Computing II/Project/ProjectDB");
    database.open();
    int i=0;
    do{
    QSqlQuery query;
    query.prepare("SELECT * FROM Hotels WHERE to = "+city+"");
    query.exec();
    QString test;
    while (query.next())
    {
        test = query.value(0).toString();
    }
    box.setWindowTitle("hotels by cities");
    box.setText(test);
    box.exec();
    i=i+1;
    }while(i<18);
    database.close();
}
