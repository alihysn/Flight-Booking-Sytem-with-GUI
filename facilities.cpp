#include "facilities.h"

Facilities::Facilities() {
    Pool = true;
    Gym = false;
    StorageArea = true;
    Parking = true;
    Bar = true;
}
Facilities::Facilities(bool pool, bool gym, bool storage, bool parking, bool bar) {
    Pool = pool;
    Gym = gym;
    StorageArea = storage;
    Parking = parking;
    Bar = bar;
}
