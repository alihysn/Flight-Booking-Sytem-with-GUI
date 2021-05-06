#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "customer.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_customerOptions_currentIndexChanged(int index)
{
    if (index == 0)
    {
        //do nothing
    }
    else if (index == 1)
    {
        Customer *cust = new Customer();
        cust->show();
        ui->customerOptions->setCurrentIndex(0);
    }
}
