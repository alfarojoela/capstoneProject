/* Project Name: Capstone Project
   Class: CS 467
   Team: Team Thing- Ryan Alcorn, Joel Alfaro, Neil Gayeta
   File: Drop.cpp
   Description: Class implementation for derived class Drop. */

#include "Drop.hpp"

/* Parameterless constructor calls base class constructor */
Drop::Drop() : Verb(DROP_NAME, VERBS::DROP) {}

/* Function returns name this verb */
std::string Drop::getName() 
{
    return this->name;
}

/* Function returns the enum value of this verb */
VERBS Drop::getActionEvent() 
{
    return this->actionEvent;
}