#ifndef TRIP_H
#define TRIP_H
#include<QString>

class Trip
{
private:
    //Hotel currHotel;
    //Flight currFlight
    QString dateCreated;
    float avgRate;
    float hotelRate;
    float flightRate;
    QString problem;
    bool isThereAProblem;
    float totalPrice;

public:
    Trip();
    void createTrip();
    void updateTrip();
    float rate();
    void problemSetter();

};

#endif // TRIP_H
