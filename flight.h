#ifndef FLIGHT_H
#define FLIGHT_H
#include<QString>

class Flight
{
private:
    int flightID;
    QString airline;
    float price;
    float rating;
    int seatsAvailable;
    float duration;
    QString from;
    QString to;
    QString fDate;
    QString tDate;

public:
    Flight();
    void reserve(QString fT, QString tT, QString fNumber);
    int getPrice();
};

#endif // FLIGHT_H
