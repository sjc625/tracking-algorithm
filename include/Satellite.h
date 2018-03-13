/*!
 * @file
 */

// Copyright 2018 SPACEHAUC Groundstation Team, David Baumann

#ifndef INCLUDE_SATELLITE_H_
#define INCLUDE_SATELLITE_H_

#include "../libsgp4/CoordTopocentric.h"
#include "../libsgp4/CoordGeodetic.h"
#include "../libsgp4/Observer.h"
#include "../libsgp4/SGP4.h"
#include "Dish.h"
#include <string>


class Satellite {
 private:
    Tle mTle;

 public:
    Satellite();
    Satellite(const Tle &tle) : mTle(tle) {}
    Satellite(const std::string &satelliteName, 
        const std::string &tleLine1, const std::string &tleLine2) :
        mTle(Tle(satelliteName, tleLine1, tleLine2)) {}
    bool isVisibleFrom(const Dish &location);
    

};



#endif  //INCLUDE_SATELLITE_H