#include "../include/Dish.h"
#include <chrono>
#include <thread>

void Dish::transmit() {
    // stub, do nothing
}

void Dish::track() {
    // stub, do nothing
}

DISH_STATUS Dish::status() const {
    return mCurrentStatus;
}

void Dish::wait() {
    // TODO: update states
    // sleep for 1 second
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

void moveToNext() {
    // figure out where next appearance will be
    // move there
}