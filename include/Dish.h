/*!
 * @file
 */

// Copyright 2018 SPACEHAUC Groundstation Team, David Baumann

#ifndef INCLUDE_DISH_H_
#define INCLUDE_DISH_H_

#include "../include/Satellite.h"
#include "../libsgp4/CoordGeodetic.h"
#include "../libsgp4/CoordTopocentric.h"
#include "../libsgp4/Observer.h"
#include "../libsgp4/SGP4.h"

enum DISH_STATUS { WAITING, ON_TARGET, MOVING, TRANSMITING };

class Dish {
 private:
  Observer mLocation;
  DISH_STATUS mCurrentStatus;
  Satellite mTarget;
  void move();

 public:
  Dish(double latitude, double longitude, double elevation)
      : mLocation(latitude, longitude, elevation), mTarget("", "", "") {}
  void transmit();
  void track();
  DISH_STATUS status() const { return mCurrentStatus; }
  void wait();
  void moveToNextAppearance();
  void setTarget(const Satellite &target) { mTarget = target; }
  bool targetVisible() const;
};

#endif  // INCLUDE_DISH_H_
