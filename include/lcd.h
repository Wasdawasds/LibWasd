// wasdlcd.h

#ifndef WASDLCD_H
#define WASDLCD_H

#pragma once

#include "pros/apix.h" // IWYU pragma: keep
#include "autonomous_registry.h" // IWYU pragma: keep
#include <string> // IWYU pragma: keep
#include <vector> // IWYU pragma: keep
#include "pros/misc.hpp" // IWYU pragma: keep
#include "main.h" // IWYU pragma: keep
#include "liblvgl/core/lv_obj.h" // IWYU pragma: keep

namespace wasd::lcd {
    // Wasdlcd Version
    inline const char* ver = "0.1.0";

    extern pros::Mutex lvgl_mutex;

    extern pros::Imu *imu;

    /**
     * @brief Initializes the custom brain screen powered by lvgl
     * @param skip_welcome If true, will skip the welcome screen and go straight to the main ui
     * @return 0 if successful, otherwise an error
     */
    int initLCD(bool skipwelcome = false);

    /**
    * @brief finds an auto by the name, and runs it
    * @return Returns true if auton is found, false if not
    * @return Will also return false if an error occurs, (e.g. no registered autons)
    */
    bool runSelectedAuton(void);

    /**
     * @brief Creates the menu tab
     * @param parent The parent object
     */
    void create_menu_tab(lv_obj_t* parent);

    /**
     * @brief Creates the autonomous selection tab
     * @param parent The parent object
     */
    void create_auton_tab(lv_obj_t* parent);

    /**
     * @brief Creates the coordinate tab
     * @param parent The parent object
     */
    void create_coord_tab(lv_obj_t* parent);

    /**
     * @brief Initializes the selected autonomous screen
     * @param screen The screen object
     * @param selectedAuton The name of the selected autonomous
     */
    void initSelectScreen(lv_obj_t * screen, const std::string& selectedAuton);

    /**
     * @brief Called when the IMU is calibrated
     * Allows the user to proceed to the main screen
     */
    void imuCalibrated(void);

    /**
     * @return Returns -1 if the tabview has not been initialized
     * @return Other wise will return the 0 based index of the active tab
     */
    int getSelectedTab(void);
}
#endif //wasdlcd