#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "customer.h"
#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlQuery>
#include "sflights.h"
#include "Hsearch.h"
#include"customerlogin.h"
#include"mail.h"
#include "invoice.h"

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
        Customer *currCust = new Customer();
        if (query.value(0).toInt() != 0)
        {
        currCust->readData(query.value(0).toInt(), query.value(1).toString(), query.value(2).toString(), query.value(3).toString(),query.value(4).toString(),query.value(5).toString(),query.value(6).toFloat(),query.value(7).toInt(), query.value(8).toInt());
        data.push_back(currCust);
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
        Customer *currCust = new Customer();
        if (query.value(0).toInt() != 0)
        {
        currCust->readData(query.value(0).toInt(), query.value(1).toString(), query.value(2).toString(), query.value(3).toString(),query.value(4).toString(),query.value(5).toString(),query.value(6).toFloat(),query.value(7).toInt(), query.value(8).toInt());
        data.push_back(currCust);
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
    if (index == 1)
    {
        refresher();
        Customer *cust = new Customer();
        cust->show();
        ui->customerOptions->setCurrentIndex(0);
    }
    else if (index == 2)
    {
        refresher();
        CustomerLogin *login = new CustomerLogin();
        login->startWindow(data, &custIndex, &isLoggedIn);
        ui->customerOptions->setCurrentIndex(0);
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

void MainWindow::on_pushButton_3_clicked()
{
    if(isLoggedIn == true)
    {
        ui->helloMsg->setText(data[custIndex]->getName());
    }
}

void MainWindow::on_pushButton_7_clicked()
{
    Invoice *newInvoice = new Invoice();
    newInvoice->ShowInvoice(data[custIndex]);
}
