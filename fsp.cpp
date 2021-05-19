#include "fsp.h"
#include "ui_fsp.h"
#include <QMessageBox>
#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlQuery>
#include "findshortestpath.h"
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
FindShortestPath TR;
void fsp::on_pushButton_clicked()
{
    QMessageBox box;
    QString fromm=ui->comboBox->currentText();
    QString too=ui->comboBox_2->currentText();
    int F=90;
    int T=90;
    if(fromm=="Cairo")
        F=0;
    else if(fromm=="Rome")
        F=1;
    else if(fromm=="Paris")
        F=2;
    else if(fromm=="Capetown")
        F=3;
    else if(fromm=="California")
        F=4;
    if(fromm=="Cairo")
        T=0;
    else if(fromm=="Rome")
        T=1;
    else if(fromm=="Paris")
        T=2;
    else if(fromm=="Capetown")
        T=3;
    else if(fromm=="California")
        T=4;
TR.FindShortestPathf(graph,F,T);
}
