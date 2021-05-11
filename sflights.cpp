#include "sflights.h"
#include "ui_sflights.h"

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
