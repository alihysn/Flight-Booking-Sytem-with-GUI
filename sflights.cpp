#include "sflights.h"
#include "ui_sflights.h"
#include"search.h"
#include<QMessageBox>

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

void SFlights::on_radioButton_toggled(bool checked)
{
    QVector<float> final;
    if (checked)
    {
        Search searcher;
        searcher.SearchByPrice(&final);
        for(int i =0; i<final.size(); i++)
        {
            QMessageBox box;
            float test = final[i];
            QString st = QString::number(test);
            box.setText(st);
            box.exec();
        }
    }
}
