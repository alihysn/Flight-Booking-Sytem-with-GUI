#ifndef TRIP_H
#define TRIP_H
#include<QString>
#include"hotel.h"
#include"flight.h"

class Trip
{
private:
    Hotel currHotel;
    Flight currFlight;
    QString dateCreated;
    float avgRate;
    float hotelRate;
    float flightRate;
    QString problem;
    bool isThereAProblem;
    float totalPrice;

public:
    Trip();
    void createTrip(QString fD, QString tD, QString flight);
    void updateTrip();
    float rate();
    void problemSetter();
    float getTotalPrice();
    int getPrice();
};

#endif // TRIP_H
