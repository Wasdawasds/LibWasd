// wasdlcd.h

#ifndef WASDAUTOREGISTRY_H
#define WASDAUTOREGISTRY_H

#pragma once

#include <functional>
#include <string>
#include <unordered_map> // IWYU pragma: keep

    /**
     * Registers an Autonomous without needing to use a name (uses the functions name)
     * Should NOT be used with overloads
     */
#define REGISTER_AUTON(fn, desc) \
    wasd::AutonomousRegistry::registerAuton(#fn, fn, desc)    
    
    /**
     * Registers an Autonomous without needing to use a name (uses the functions name)
     * Should NOT be used with overloads
     * If Auton already exists, it will be overwritten
     */
#define REGISTER_AUTON_OVERWRITE(fn, desc) \
    wasd::AutonomousRegistry::registerAuton(#fn, fn, desc, true)

namespace wasd::AutonomousRegistry {
    /**
     * @brief adds an auton to the registry by name and its void function
     * @param name name of the auton as a string
     * @param function a void autonomous function
     * @param description a description for the function
     * @param overwrite whether to overwrite an auton if the name is already registered
     * @return Returns true if successful, false if not (e.g. name already is registered)
     */
    bool registerAuton(const std::string& name, std::function<void()> function, const std::string& description = "", const bool overwrite = false);

    /**
    * @brief finds an auto by the name, and runs it
    * @param name name of the auton as a string
    * @return Returns true if auton is found, false if not
    */
    bool run(const std::string& name);

    //returns the description of an auto if exists, otherwise returns ""
    std::string getDescription(const std::string& name );

    //lists all autons
    std::vector<std::string> listAutons();
}//namespace wasd::AutonomousRegistry
#endif //wasdautoregistry