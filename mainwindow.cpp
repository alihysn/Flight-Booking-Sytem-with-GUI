#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "customer.h"
#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlQuery>
#include "sflights.h"
#include "Hsearch.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("/media/mohamed/01D674211A1C18801/AUC/Freshman/Spring 2021/CSCE1101-03 - Fundamentals of Computing II/Project/ProjectDB");
    database.open();
    QSqlQuery query;
    query.exec("SELECT * from Customers");
    while(query.next())
    {
        Customer currCust;
        if (query.value(0).toInt() != 0)
        {
        currCust.readData(query.value(0).toInt(), query.value(1).toString(), query.value(2).toString(), query.value(3).toString(),query.value(4).toString(),query.value(5).toString(),query.value(6).toFloat(),query.value(7).toInt(), query.value(8).toInt());
        data.push_back(&currCust);
        }
    }
    database.close();
}

void MainWindow::refresher()
{
    data.clear();
    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("/media/mohamed/01D674211A1C18801/AUC/Freshman/Spring 2021/CSCE1101-03 - Fundamentals of Computing II/Project/ProjectDB");
    database.open();
    QSqlQuery query;
    query.exec("SELECT * from Customers");
    while(query.next())
    {
        Customer currCust;
        if (query.value(0).toInt() != 0)
        {
        currCust.readData(query.value(0).toInt(), query.value(1).toString(), query.value(2).toString(), query.value(3).toString(),query.value(4).toString(),query.value(5).toString(),query.value(6).toFloat(),query.value(7).toInt(), query.value(8).toInt());
        data.push_back(&currCust);
        }
    }
    database.close();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_customerOptions_currentIndexChanged(int index)
{
    refresher();
    if (index == 1)
    {
        Customer *cust = new Customer();
        cust->show();
    }
}

void MainWindow::on_pushButton_clicked()
{
    SFlights *pagetwo =new SFlights;
    pagetwo->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    Hsearch *pagethree =new Hsearch;
    pagethree->show();
}
