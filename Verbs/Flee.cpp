/* Project Name: Capstone Project
   Class: CS 467
   Team: Team Thing- Ryan Alcorn, Joel Alfaro, Neil Gayeta
   File: Flee.cpp
   Description: Class implementation for derived class Flee. */

#include "Flee.hpp"

/* Parameterless constructor calls base class constructor */
Flee::Flee() : Verb(FLEE_NAME, VERBS::FLEE) {}

/* Function returns name this verb */
std::string Flee::getName() 
{
    return this->name;
}

/* Function returns the enum value of this verb */
VERBS Flee::getActionEvent() 
{
    return this->actionEvent;
}