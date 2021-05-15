#include "search.h"
#include <iostream>
#include <QMainWindow>
#include<mainwindow.h>
#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlQuery>
#include<QVector>

using namespace std;
Search::Search()
{

}
void Search::SearchByPrice(QVector<float> *fin)
{
    QVector<float> allPrices;
    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("/media/mohamed/01D674211A1C18801/AUC/Freshman/Spring 2021/CSCE1101-03 - Fundamentals of Computing II/Project/ProjectDB");
    database.open();
    QSqlQuery query;
    query.prepare("SELECT Price from Flights");
    while(query.next())
    {
        query.exec();
        allPrices.push_back(query.value(0).toFloat());
    }
    database.close();
    for(int i = 0; i<allPrices.size(); i++)
    {
        for (int j=1; j<allPrices.size(); j++)
        {
            if (allPrices[j] < allPrices[i])
            {
                float temp = allPrices[i];
                allPrices[i] = allPrices[j];
                allPrices[j] = temp;
            }
        }
    }
    *fin = allPrices;
}
void Search::SearchByRatings()
{

}
void Search::SearchByDistancefromairport()
{

}
void Search::SearchByFacilities()
{

}
