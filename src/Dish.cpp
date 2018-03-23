// Copyright 2018 SPACEHAUC Groundstation Team, David Baumann

#include "../include/Dish.h"
#include <unistd.h>

void Dish::transmit() {
  // stub, do nothing
}

void Dish::track() {
  // stub, do nothing
}

void Dish::wait() {
  // TODO(djbaumann): update states
  // sleep for 1 second
  sleep(1);
}

void Dish::moveToNextAppearance() {
  // figure out where next appearance will be
  // move there
}

bool Dish::targetVisible() const {
  // stub, do nothing
  return false;
}
