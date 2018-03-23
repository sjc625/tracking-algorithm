/*!
 * @file
 */

// Copyright 2018 SPACEHAUC Groundstation Team, David Baumann

#ifndef INCLUDE_SATELLITE_H_
#define INCLUDE_SATELLITE_H_

#include <string>
#include "../include/Dish.h"
#include "../libsgp4/CoordGeodetic.h"
#include "../libsgp4/CoordTopocentric.h"
#include "../libsgp4/Observer.h"
#include "../libsgp4/SGP4.h"

class Satellite {
 private:
  const Tle mTle;

 public:
  Satellite();
  explicit Satellite(const Tle &tle) : mTle(tle) {}
  Satellite(const std::string &satelliteName, const std::string &tleLine1,
            const std::string &tleLine2)
      : mTle(Tle(satelliteName, tleLine1, tleLine2)) {}
  bool isVisibleFrom(const Dish &location);
};

#endif  // INCLUDE_SATELLITE_H_
