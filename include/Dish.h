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
  Dish();
  Dish(double latitude, double longitude, double elevation);
  void transmit();
  void track();
  inline DISH_STATUS status() const;
  void wait();
  void moveToNext();
  inline void setTarget(const Satellite &target);
};

#endif  // INCLUDE_DISH_H_
