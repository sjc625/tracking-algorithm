/*!
 * @file
 */

// Copyright 2018 SPACEHAUC Groundstation Team, David Baumann

#ifndef INCLUDE_DISH_H_
#define INCLUDE_DISH_H_

#include <list>
#include <string>
#include "Satellite.h"
#include "passpredict.h"
#include "positionDish.h"
#include "../libsgp4/CoordGeodetic.h"
#include "../libsgp4/CoordTopocentric.h"
#include "../libsgp4/Observer.h"
#include "../libsgp4/SGP4.h"

enum DISH_STATUS {
  NO_TARGET,
  ON_TARGET,
  OFF_TARGET,
  WAITING,
  MOVING,
  TRANSMITING
};

class Dish {
 private:
  Observer *mpLocation;
  Satellite *mpTarget;
  SGP4 *mpSGP4;
  DISH_STATUS mCurrentStatus;
  void move(double azimuth, double elevation);
  Patch PA, PB;
 public:
  Dish(double latitude, double longitude, double elevation, std::string pa, std::string pb)
      : mpLocation(new Observer(latitude, longitude, elevation)),
        mpTarget(nullptr),
        mpSGP4(nullptr),
        mCurrentStatus(NO_TARGET),
        PA(pa), PB(pb) {};
  ~Dish();
  void transmit();
  void track();
  DISH_STATUS status() const { return mCurrentStatus; }
  void wait();
  void moveToNextAppearance();
  void setTarget(const Satellite &target);
  bool targetVisible() const;
  std::list<PassDetails_t> generatePassList();
  std::list<PassDetails_t> generatePassList(const DateTime &start_time,
                                            const DateTime &end_time);
};

#endif  // INCLUDE_DISH_H_
