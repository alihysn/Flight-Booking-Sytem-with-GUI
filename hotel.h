#ifndef HOTEL_H
#define HOTEL_H
#include<QString>

class Hotel
{
private:
    QString Name;
    float Rating;
    int AvailableRooms;
    QString Location;
public:
    Hotel(QString name, float rating, int available, QString location);
    Hotel();
};

#endif // HOTEL_H
