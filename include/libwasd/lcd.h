// wasdlcd.h

#ifndef WASDLCD_H
#define WASDLCD_H

#pragma once

#include "autonomous_registry.h" // IWYU pragma: keep
#include "api.h" // IWYU pragma: keep

namespace wasd::lcd {
    // Wasdlcd Version
    inline const char* ver = "0.1.0";

    extern pros::Mutex lvgl_mutex;

    extern pros::Imu *imu;

    struct Pos {
        float x;
        float y;
        float theta;
    };

    /**
     * @brief Initializes the custom brain screen powered by lvgl
     * @param imu Currently used imu
     * @param imuCalibrateFn Function used to calibrate imu. Set to NULL if none exists
     * @param blockCoordTabTask Whether to block the coordinate tab task from being created.
     * Use for custom printing logic with print_coord_tab()
     * @param skip_welcome If true, will skip the welcome screen and proceed to the main ui
     * @return 0 if successful, otherwise an error
     */
    int initLCD(pros::Imu &imu, std::function<void()> imuCalibrateFn, const char * teamName, bool blockCoordTabTask = false, bool skipwelcome = false);

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
    void create_menu_tab(lv_obj_t *parent);

    /**
     * @brief Creates the autonomous selection tab
     * @param parent The parent object
     */
    void create_auton_tab(lv_obj_t *parent);

    /**
     * @brief Creates the coordinate tab
     * @param parent The parent object
     * @param blockCoordTask Whether to block the coordinate task
     */
    void create_coord_tab(lv_obj_t *parent, bool blockCoordTask);

    /**
     * @brief Initializes the selected autonomous screen
     * @param parent The screen object
     * @param selectedAuton The name of the selected autonomous
     */
    void initSelectScreen(lv_obj_t *parent, const std::string& selectedAuton);

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

    /** 
     * @brief Returns a string based on the imu status
     * @param status The pros::ImuStatus of the IMU
     * @return "Calibrating" if imu is calibrating, "Ready" if imu is ready, "Error" in all other cases
     * @note From testing, function may return "Error" from imu.getStatus(); even if imu is ready. No idea why
     */
    std::string imuStatus(const pros::ImuStatus &status);

    /**
     * @brief Prints x, y, and theta (heading) coordinates to the coordinate tab
     *
     * Updates the label associated with the coordinate tab in the GUI.
     * By default, the text is only updated when the coordinate tab is
     * currently selected to avoid unnecessary rendering overhead.
     *
     * @param x X coordinate
     * @param y Y coordinate
     * @param theta Theta coordinate (heading)
     * @param imuStatus Status of the imu as a string
     * @param forcePrint  If true, updates the label regardless of the
     *                    currently selected tab. If false, the function
     *                    returns early unless the coordinate tab is active.
     *
     * @note It is recommended to keep forcePrint = false during loops or
     *       frequent updates to reduce GUI rendering overhead.
     *
     * @warning This function is thread-safe via a mutex, but excessive
     *          forced updates may still impact performance.
     */
    void print_coord_tab(const double& x, const double& y, const double& theta, const char *imuStatus = "Error", bool forcePrint = false);

    /**
     * @brief Prints x, y, and theta (heading) coordinates to the coordinate tab
     *
     * Updates the label associated with the coordinate tab in the GUI.
     * By default, the text is only updated when the coordinate tab is
     * currently selected to avoid unnecessary rendering overhead.
     *
     * @param xyt X, Y, and theta (heading) coordinate
     * @param imuStatus Status of the imu as a string
     * @param forcePrint  If true, updates the label regardless of the
     *                    currently selected tab. If false, the function
     *                    returns early unless the coordinate tab is active.
     *
     * @note It is recommended to keep forcePrint = false during loops or
     *       frequent updates to reduce GUI rendering overhead.
     *
     * @warning This function is thread-safe via a mutex, but excessive
     *          forced updates may still impact performance.
     */
    void print_coord_tab(Pos xyt, const char *imuStatus = "Error", const bool forcePrint = false);

    /**
     * @brief Prints text to the coordinate tab label.
     *
     * Updates the label associated with the coordinate tab in the GUI.
     * By default, the text is only updated when the coordinate tab is
     * currently selected to avoid unnecessary rendering overhead.
     *
     * @param text        Null-terminated string to display.
     * @param forcePrint  If true, updates the label regardless of the
     *                    currently selected tab. If false, the function
     *                    returns early unless the coordinate tab is active.
     * @param longMode    LVGL long mode used to control text wrapping
     *                    and overflow behavior (default: LV_LABEL_LONG_WRAP).
     *
     * @note It is recommended to keep forcePrint = false during loops or
     *       frequent updates to reduce GUI rendering overhead.
     *
     * @warning This function is thread-safe via a mutex, but excessive
     *          forced updates may still impact performance.
     */
    void print_coord_tab(const char *text, bool forcePrint = false, lv_label_long_mode_t longMode = LV_LABEL_LONG_WRAP);
}
#endif //wasdlcd