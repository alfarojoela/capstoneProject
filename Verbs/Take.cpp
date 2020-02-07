/* Project Name: Capstone Project
   Class: CS 467
   Team: Team Thing- Ryan Alcorn, Joel Alfaro, Neil Gayeta
   File: Take.cpp
   Description: Class implementation for derived class Take. */

#include "Take.hpp"

/* Parameterless constructor calls base class constructor */
Take::Take() : Verb(TAKE_NAME, VERBS::TAKE) {}

/* Function returns name this verb */
std::string Take::getName() 
{
    return this->name;
}

/* Function returns the enum value of this verb */
VERBS Take::getActionEvent() 
{
    return this->actionEvent;
}