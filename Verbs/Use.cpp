/* Project Name: Capstone Project
   Class: CS 467
   Team: Team Thing- Ryan Alcorn, Joel Alfaro, Neil Gayeta
   File: Use.cpp
   Description: Class implementation for derived class Use. */

#include "Use.hpp"

/* Parameterless constructor calls base class constructor */
Use::Use() : Verb(USE_NAME, VERBS::USE) {}

/* Function returns name this verb */
std::string Use::getName() 
{
    return this->name;
}

/* Function returns the enum value of this verb */
VERBS Use::getActionEvent() 
{
    return this->actionEvent;
}