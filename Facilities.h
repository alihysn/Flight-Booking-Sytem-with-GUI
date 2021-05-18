#ifndef FACILITIES_H
#define FACILITIES_H
#include<iostream>
using namespace std;
class Facilities {
    bool Pool;
    bool Gym;
    bool StorageArea;
    bool Parking;
    bool Bar;
public:
    Facilities();
    Facilities(bool pool, bool gym, bool storage, bool parking, bool bar);

};

#endif
