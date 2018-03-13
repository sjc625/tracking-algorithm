/*!
 * @file
 */
 
 // Copyright 2018 SPACEHAUC Groundstation Team, David Baumann

#ifndef INCLUDE_DISH_H_
#define INCLUDE_DISH_H_

#include "../libsgp4/CoordTopocentric.h"
#include "../libsgp4/CoordGeodetic.h"
#include "../libsgp4/Observer.h"
#include "../libsgp4/SGP4.h"

enum DISH_STATUS {
    isWaiting,
    isTracking,
    isTransmitting
};


class Dish {
 private:
    Observer location;
 public:
    Dish();
    Dish(double latitude, double longitude, double elevation);
    void transmit();
    void track();
    DISH_STATUS status() const;
    void wait();
    void moveToNext();
};



#endif  // INCLUDE_DISH_H_
