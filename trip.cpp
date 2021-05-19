#include "trip.h"

Trip::Trip()
{

}

float Trip::getTotalPrice()
{
    return totalPrice;
}

void Trip::createTrip(QString fD, QString tD, QString flight)
{
    currFlight.reserve(fD, tD,flight);
}

int Trip::getPrice()
{
    return currFlight.getPrice();
}
