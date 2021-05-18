#ifndef ROOM_H
#define ROOM_H
#include<iostream>
using namespace std;
class Room
{
    int NumberOfBeds;
    int NumberOfToilets;
    bool view;
    bool reserved;
public:
    Room();
    Room(int NoB, int NoT, bool v);
    void PresentRooms();
};

#endif
