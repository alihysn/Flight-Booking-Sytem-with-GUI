#include "fsp.h"
#include "ui_fsp.h"
#include <QMessageBox>
#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlQuery>

fsp::fsp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fsp)
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

fsp::~fsp()
{
    delete ui;
}

void fsp::on_pushButton_clicked()
{
    QMessageBox box;
    QString fromm=ui->comboBox->currentText();
    QString too=ui->comboBox_2->currentText();



}
