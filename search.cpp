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
QVector<float> Search::SearchByPrice()
{
    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("/media/mohamed/01D674211A1C18801/AUC/Freshman/Spring 2021/CSCE1101-03 - Fundamentals of Computing II/Project/ProjectDB");
    database.open();
    QSqlQuery query;
    query.exec("SELECT Price from Flights");
    while(query.next())
    {
        sort.push_back(query.value(0).toFloat());
    }
    database.close();
    for(int i = 0; i<sort.size(); i++)
    {
        for (int j=0; j<sort.size(); j++)
        {
            if (sort[j] > sort[i])
            {
                float temp = sort[i];
                sort[i] = sort[j];
                sort[j] = temp;
            }
        }
    }
    return sort;
}
QVector<float> Search::SearchByRatingF()
{
    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("/media/mohamed/01D674211A1C18801/AUC/Freshman/Spring 2021/CSCE1101-03 - Fundamentals of Computing II/Project/ProjectDB");
    database.open();
    QSqlQuery query;
    query.exec("SELECT Rating from Flights");
    while(query.next())
    {
        sort.push_back(query.value(0).toFloat());
    }
    database.close();
    for(int i = 0; i<sort.size(); i++)
    {
        for (int j=0; j<sort.size(); j++)
        {
            if (sort[j] > sort[i])
            {
                float temp = sort[i];
                sort[i] = sort[j];
                sort[j] = temp;
            }
        }
    }
    return sort;
}
QVector<float> Search::SearchByRatingH()
{
    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("/media/mohamed/01D674211A1C18801/AUC/Freshman/Spring 2021/CSCE1101-03 - Fundamentals of Computing II/Project/ProjectDB");
    database.open();
    QSqlQuery query;
    query.exec("SELECT Rating from Hotels");
    while(query.next())
    {
        sort.push_back(query.value(0).toFloat());
    }
    database.close();
    for(int i = 0; i<sort.size(); i++)
    {
        for (int j=0; j<sort.size(); j++)
        {
            if (sort[j] > sort[i])
            {
                float temp = sort[i];
                sort[i] = sort[j];
                sort[j] = temp;
            }
        }
    }
    return sort;
}
QVector<float> Search::SearchByDistancefromairport()
{
    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("/media/mohamed/01D674211A1C18801/AUC/Freshman/Spring 2021/CSCE1101-03 - Fundamentals of Computing II/Project/ProjectDB");
    database.open();
    QSqlQuery query;
    query.exec("SELECT DistanceFromAirport from Hotels");
    while(query.next())
    {
        sort.push_back(query.value(0).toFloat());
    }
    database.close();
    for(int i = 0; i<sort.size(); i++)
    {
        for (int j=0; j<sort.size(); j++)
        {
            if (sort[j] > sort[i])
            {
                float temp = sort[i];
                sort[i] = sort[j];
                sort[j] = temp;
            }
        }
    }
    return sort;
}
//QString Search::SearchByFacilities()
//{
  //  QSqlDatabase database;
   // database = QSqlDatabase::addDatabase("QSQLITE");
  //  database.setDatabaseName("/media/mohamed/01D674211A1C18801/AUC/Freshman/Spring 2021/CSCE1101-03 - Fundamentals of Computing II/Project/ProjectDB");
 //   database.open();
//    QSqlQuery query;
 //   query.exec("SELECT DistanceFromAirport from Hotels");
  //  while(query.next())
  //  {
   //     sort.push_back(query.value(0).toFloat());
   // }
    //database.close();
    //for(int i = 0; i<sort.size(); i++)
    //{
      //  for (int j=0; j<sort.size(); j++)
        //{
          //  if (sort[j] > sort[i])
         //   {
           //     float temp = sort[i];
             //   sort[i] = sort[j];
               // sort[j] = temp;
          //  }
       // }
    //}
    //return answer;
//}
