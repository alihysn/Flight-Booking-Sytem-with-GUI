#include "hotel.h"

Hotel::Hotel(QString name, float rating, int available, QString location) {
    Name = name;
    Rating = rating;
    AvailableRooms = available;
    Location = location;
}
Hotel::Hotel() {
    Name = "Default";
    Rating = 3;
    AvailableRooms = 10;
    Location = "Default";
}
