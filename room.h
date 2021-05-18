#ifndef ROOM_H
#define ROOM_H


class Room
{
private:
    int NumberOfBeds;
    int NumberOfToilets;
    bool view;
    bool reserved;
public:
    Room();
    Room(int NoB, int NoT, bool v);
    void PresentRooms();
};

#endif // ROOM_H
