/* Project Name: Capstone Project
   Class: CS 467
   Team: Team Thing- Ryan Alcorn, Joel Alfaro, Neil Gayeta
   File: Look.cpp
   Description: Class implementation for derived class Look. */

#include "Look.hpp"

/* Parameterless constructor calls base class constructor */
Look::Look() : Verb(LOOK_NAME, VERBS::LOOK) {}

/* Function returns name this verb */
std::string Look::getName() 
{
    return this->name;
}

/* Function returns the enum value of this verb */
VERBS Look::getActionEvent() 
{
    return this->actionEvent;
}