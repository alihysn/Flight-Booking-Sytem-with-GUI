#include "room.h"

void Room::PresentRooms(){
   // cout << "The number of beds in the room are: " << NumberOfBeds << endl;
  //  cout << "The number of toilets in the room are: " << NumberOfToilets << endl;
 //   if (view == true) {
  //      cout << "The room has a view" << endl;
 //   }
  //  else {
   //     cout << "The room does not have a view" << endl;
   // }
};
Room::Room(){
    NumberOfBeds = 1;
    NumberOfToilets = 1;
    view = false;
}
Room::Room(int NoB, int NoT, bool v){
    NumberOfBeds = NoB;
    NumberOfToilets = NoT;
    view = v;
}
