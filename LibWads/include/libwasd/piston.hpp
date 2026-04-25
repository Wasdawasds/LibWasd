// wasdlcd.h

#ifndef WASDPISTON_HPP
#define WASDPISTON_HPP

#pragma once

#include "pros/adi.hpp"

namespace wasd {

class Piston {
public:
    Piston(char port);
    Piston(int port);

    /** @brief Get the current state of the piston
     * @return true if extended, false if retracted
     */
    bool get() const;

    /** @brief Set the state of the piston
     * @param newState true if extended, false if retracted
     */
    void set(bool newState);

    /** 
     * @brief Extend the piston
     */
    void extend();
    /**
     * @brief Retract the piston
     */
    void retract();

    /** @brief Toggle the state of the piston
     * @param toggleState Toggles the piston when true
     */
    void toggle(bool toggleState);

private:
    pros::adi::DigitalOut piston;
    bool state = false; // false for retracted, true for extended
    bool lastToggleState = false; // To track the last toggle state
};

} //namespace wasd

#endif