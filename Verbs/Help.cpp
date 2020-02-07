/* Project Name: Capstone Project
   Class: CS 467
   Team: Team Thing- Ryan Alcorn, Joel Alfaro, Neil Gayeta
   File: Help.cpp
   Description: Class implementation for derived class Help. */

#include "Help.hpp"

/* Parameterless constructor calls base class constructor */
Help::Help() : Verb(HELP_NAME, VERBS::HELP) {}

/* Function returns name this verb */
std::string Help::getName() 
{
    return this->name;
}

/* Function returns the enum value of this verb */
VERBS Help::getActionEvent() 
{
    return this->actionEvent;
}