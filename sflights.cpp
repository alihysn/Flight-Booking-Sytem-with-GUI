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
    QVector<float> final;
    Search *searcher = new Search();
    final = searcher->SearchByPrice();
}
