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
    ui->comboBox->addItem("Cairo");
    ui->comboBox->addItem("Rome");
    ui->comboBox->addItem("Paris");
    ui->comboBox->addItem("California");
    ui->comboBox->addItem("Capetown");
    ui->comboBox_2->addItem("Cairo");
    ui->comboBox_2->addItem("Rome");
    ui->comboBox_2->addItem("Paris");
    ui->comboBox_2->addItem("California");
    ui->comboBox_2->addItem("Capetown");
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
    int i=0;
       do
       {
       QString str= QString::number(final[i]);
       QSqlQuery query;
       query.exec("SELECT ID, Price FROM Flights WHERE Price= "+str+"");
       QString test;
       QString test1;
       while (query.next())
       {
           test = query.value(0).toString();
           test1 = query.value(1).toString();
           break;
       }
       box.setWindowTitle("sorted by price");
       box.setText(test);
       box.exec();
       box.setText(test1);
       box.exec();
       i=i+1;
       } while(i<final.size());
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
    int i=0;
       do
       {
       QString str= QString::number(final[i]);
       QSqlQuery query;
       query.exec("SELECT Airline, Price, Rating FROM Flights WHERE Rating= "+str+"");
       QString test;
       while (query.next())
       {
           test = query.value(0).toString();
       break;
       }
       box.setWindowTitle("Sorted by rating");
      box.setText(test);
       box.exec();
       i=i+1;
       }while(i<final.size());
    database.close();
}

void SFlights::on_orderoflocation_clicked()
{
    QMessageBox box;
    QString fromm=ui->comboBox->currentText();
    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("/media/mohamed/01D674211A1C18801/AUC/Freshman/Spring 2021/CSCE1101-03 - Fundamentals of Computing II/Project/ProjectDB");
    database.open();
   int i=0;
    do {
    QSqlQuery query;
    query.prepare("SELECT Airline, Price, Rating FROM Flights WHERE from= "+fromm+"");
    query.exec();
    QString test;
    while (query.next())
    {
        test = query.value(0).toString();
    }
    box.setWindowTitle("list of planes ");
    box.setText(test);
    box.exec();
    i=i+1;
}while (i<18);
    database.close();
}
void SFlights::on_orderfordestination_clicked()
{
    QMessageBox box;
    QString too=ui->comboBox_2->currentText();
    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("/media/mohamed/01D674211A1C18801/AUC/Freshman/Spring 2021/CSCE1101-03 - Fundamentals of Computing II/Project/ProjectDB");
    database.open();
    int i=0;
     do {
    QSqlQuery query;
    query.prepare("SELECT Airline, Price, Rating FROM Flights WHERE to= "+too+"");
    query.exec();
    QString test;
    while (query.next())
    {
        test = query.value(0).toString();
    }
    box.setWindowTitle("list of planes ");
    box.setText(test);
    box.exec();
    i=i+1;
    }while (i<18);
    database.close();
}
