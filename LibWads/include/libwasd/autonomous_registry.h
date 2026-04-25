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

namespace wasd::AutonomousRegistry {
    /**
     * @brief adds an auton to the registry by name and its void function
     * @param name name of the auton as a string
     * @param function a void autonomous function
     * @param description a description for the function
     * @return Returns true if successful, false if not (e.g. name already is registered)
     */
    bool registerAuton(const std::string& name, std::function<void()> function, const std::string& description = "");

    /**
    * @brief finds an auto by the name, and runs it
    * @param name name of the auton as a string
    * @return Returns true if auton is found, false if not
    */
    bool run(const std::string& name);

    /**
     * @brief Find an autonomous' description from its name
     * @param name Name of the autonomous
     * @return Description of an autonomous if it exists, otherwise returns ""
     * @note If a description was not registered for the autonomous function will return ""
     */
    std::string getDescription(const std::string& name );

    /**
     * @brief Iterates over all registered autonomous functions
     * @return std::vector of all names
     */
    std::vector<std::string> listAutons(void);
}//namespace wasd::AutonomousRegistry
#endif //wasdautoregistry