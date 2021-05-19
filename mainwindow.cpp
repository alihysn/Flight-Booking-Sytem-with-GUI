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
#include<QMessageBox>
#include "fsp.h"
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
    ui->calendar1->setVisible(false);
    ui->calendar2->setVisible(false);
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
    if (isLoggedIn == false)
    {
        QMessageBox box;
        box.setText("User is not logged in !");
        box.setWindowTitle("Error");
        box.exec();
    }
    else
    {
        Invoice *newInvoice = new Invoice();
        newInvoice->ShowInvoice(data[custIndex]);
    }
}

void MainWindow::on_pushButton_8_clicked()
{

}

void MainWindow::on_pushButton_9_clicked()
{
    QMessageBox Box1;
   QMessageBox:: StandardButton reply= QMessageBox::question(this, "Payment","Would you like to pay through card?",QMessageBox::Yes|QMessageBox::No);

    if (reply==QMessageBox::No)
       {
            QMessageBox:: StandardButton reply1= QMessageBox::question(this, "Payment","Would you like to pay through wallet?",QMessageBox::Yes|QMessageBox::No);
            if (reply1==QMessageBox::Yes)
            {
            Box1.setText(" Your package has been paid");
            Box1.setWindowTitle("Payment");
            Box1.exec();
            this->close();
            }
            else
            {
            Box1.setText("No deduction has been done");
            Box1.setWindowTitle(" Payment");
            Box1.exec();
            this->close();
            }
      }
    else {
            Box1.setText("No deduction has been done");
         Box1.setWindowTitle("Payment");
        }
}

void MainWindow::on_Inquiries_clicked()
{
    fsp *pagefour =new fsp;
    pagefour->show();
}

void MainWindow::on_pushButton_6_clicked()
{

}

void MainWindow::on_calendar1_selectionChanged()
{
    QString str = QString::number(ui->calendar1->selectedDate().month());
    if (str == "1")
    {
        QString str2 = QString::number(ui->calendar1->selectedDate().year());
        QString str3 = QString::number(ui->calendar1->selectedDate().day());
        ui->lineEdit->setText( str2+"-"+"1"+"-"+str3);
    }
    else if (str == "2")
    {
        QString str2 = QString::number(ui->calendar1->selectedDate().year());
        QString str3 = QString::number(ui->calendar1->selectedDate().day());
        ui->lineEdit->setText( str2+"-"+"2"+"-"+str3);
    }
    else if (str == "3")
    {
        QString str2 = QString::number(ui->calendar1->selectedDate().year());
        QString str3 = QString::number(ui->calendar1->selectedDate().day());
        ui->lineEdit->setText( str2+"-"+"3"+"-"+str3);
    }
    else if (str == "4")
    {
        QString str2 = QString::number(ui->calendar1->selectedDate().year());
        QString str3 = QString::number(ui->calendar1->selectedDate().day());
        ui->lineEdit->setText( str2+"-"+"4"+"-"+str3);
    }
    else if (str == "5")
    {
        QString str2 = QString::number(ui->calendar1->selectedDate().year());
        QString str3 = QString::number(ui->calendar1->selectedDate().day());
        ui->lineEdit->setText( str2+"-"+"5"+"-"+str3);
    }
    else if (str == "6")
    {
        QString str2 = QString::number(ui->calendar1->selectedDate().year());
        QString str3 = QString::number(ui->calendar1->selectedDate().day());
        ui->lineEdit->setText( str2+"-"+"6"+"-"+str3);
    }
    else if (str == "7")
    {
        QString str2 = QString::number(ui->calendar1->selectedDate().year());
        QString str3 = QString::number(ui->calendar1->selectedDate().day());
        ui->lineEdit->setText( str2+"-"+"7"+"-"+str3);
    }
    else if (str == "8")
    {
        QString str2 = QString::number(ui->calendar1->selectedDate().year());
        QString str3 = QString::number(ui->calendar1->selectedDate().day());
        ui->lineEdit->setText( str2+"-"+"8"+"-"+str3);
    }
    else if (str == "9")
    {
        QString str2 = QString::number(ui->calendar1->selectedDate().year());
        QString str3 = QString::number(ui->calendar1->selectedDate().day());
        ui->lineEdit->setText( str2+"-"+"9"+"-"+str3);
    }
    else if (str == "10")
    {
        QString str2 = QString::number(ui->calendar1->selectedDate().year());
        QString str3 = QString::number(ui->calendar1->selectedDate().day());
        ui->lineEdit->setText( str2+"-"+"10"+"-"+str3);
    }
    else if (str == "11")
    {
        QString str2 = QString::number(ui->calendar1->selectedDate().year());
        QString str3 = QString::number(ui->calendar1->selectedDate().day());
        ui->lineEdit->setText( str2+"-"+"11"+"-"+str3);
    }
    else if (str == "12")
    {
        QString str2 = QString::number(ui->calendar1->selectedDate().year());
        QString str3 = QString::number(ui->calendar1->selectedDate().day());
        ui->lineEdit->setText( str2+"-"+"12"+"-"+str3);
    }
}

void MainWindow::on_calendar2_selectionChanged()
{
    QString str = QString::number(ui->calendar2->selectedDate().month());
    if (str == "1")
    {
        QString str2 = QString::number(ui->calendar2->selectedDate().year());
        QString str3 = QString::number(ui->calendar2->selectedDate().day());
        ui->lineEdit_2->setText( str2+"-"+"1"+"-"+str3);
    }
    else if (str == "2")
    {
        QString str2 = QString::number(ui->calendar2->selectedDate().year());
        QString str3 = QString::number(ui->calendar2->selectedDate().day());
        ui->lineEdit_2->setText( str2+"-"+"2"+"-"+str3);
    }
    else if (str == "3")
    {
        QString str2 = QString::number(ui->calendar2->selectedDate().year());
        QString str3 = QString::number(ui->calendar2->selectedDate().day());
        ui->lineEdit_2->setText( str2+"-"+"3"+"-"+str3);
    }
    else if (str == "4")
    {
        QString str2 = QString::number(ui->calendar2->selectedDate().year());
        QString str3 = QString::number(ui->calendar2->selectedDate().day());
        ui->lineEdit_2->setText( str2+"-"+"4"+"-"+str3);
    }
    else if (str == "5")
    {
        QString str2 = QString::number(ui->calendar2->selectedDate().year());
        QString str3 = QString::number(ui->calendar2->selectedDate().day());
        ui->lineEdit_2->setText( str2+"-"+"5"+"-"+str3);
    }
    else if (str == "6")
    {
        QString str2 = QString::number(ui->calendar2->selectedDate().year());
        QString str3 = QString::number(ui->calendar2->selectedDate().day());
        ui->lineEdit_2->setText( str2+"-"+"6"+"-"+str3);
    }
    else if (str == "7")
    {
        QString str2 = QString::number(ui->calendar2->selectedDate().year());
        QString str3 = QString::number(ui->calendar2->selectedDate().day());
        ui->lineEdit_2->setText( str2+"-"+"7"+"-"+str3);
    }
    else if (str == "8")
    {
        QString str2 = QString::number(ui->calendar2->selectedDate().year());
        QString str3 = QString::number(ui->calendar2->selectedDate().day());
        ui->lineEdit_2->setText( str2+"-"+"8"+"-"+str3);
    }
    else if (str == "9")
    {
        QString str2 = QString::number(ui->calendar2->selectedDate().year());
        QString str3 = QString::number(ui->calendar2->selectedDate().day());
        ui->lineEdit_2->setText( str2+"-"+"9"+"-"+str3);
    }
    else if (str == "10")
    {
        QString str2 = QString::number(ui->calendar2->selectedDate().year());
        QString str3 = QString::number(ui->calendar2->selectedDate().day());
        ui->lineEdit_2->setText( str2+"-"+"10"+"-"+str3);
    }
    else if (str == "11")
    {
        QString str2 = QString::number(ui->calendar2->selectedDate().year());
        QString str3 = QString::number(ui->calendar2->selectedDate().day());
        ui->lineEdit_2->setText( str2+"-"+"11"+"-"+str3);
    }
    else if (str == "12")
    {
        QString str2 = QString::number(ui->calendar2->selectedDate().year());
        QString str3 = QString::number(ui->calendar2->selectedDate().day());
        ui->lineEdit_2->setText( str2+"-"+"12"+"-"+str3);
    }
}
