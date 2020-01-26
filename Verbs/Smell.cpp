/* Project Name: Capstone Project
   Class: CS 467
   Team: Team Thing- Ryan Alcorn, Joel Alfaro, Neil Gayeta
   File: Smell.cpp
   Description: Class implementation for derived class Smell. */

#include "Smell.hpp"

/* Parameterless constructor calls base class constructor */
Smell::Smell() : Verb(SMELL_NAME, VERBS::SMELL) {}

/* Function returns name this verb */
std::string Smell::getName() 
{
    return this->name;
}

/* Function returns the enum value of this verb */
VERBS Smell::getActionEvent() 
{
    return this->actionEvent;
}