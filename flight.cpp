#include "flight.h"
#include<QMessageBox>
#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlQuery>

Flight::Flight()
{

}

void Flight::reserve(QString fT, QString tT, QString fNumber)
{
    flightID = fNumber.toInt();
    fDate = fT;
    tDate = tT;
    QMessageBox box;
    box.setText("Flight number. "+fNumber+" is reserved succesfully from: "+fT+" to: "+tT+"");
    box.exec();
}

int Flight::getPrice()
{
    int price = 0;
    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("/media/mohamed/01D674211A1C18801/AUC/Freshman/Spring 2021/CSCE1101-03 - Fundamentals of Computing II/Project/ProjectDB");
    QSqlQuery query;
    QString str = QString::number(flightID);
    query.exec("Select Price from Flights where ID = "+str+"");
    while (query.next())
    {
        price = query.value(0).toInt();
    }
    database.close();
    return price;
}
