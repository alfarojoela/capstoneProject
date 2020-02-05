/* Project Name: Capstone Project
   Class: CS 467
   Team: Team Thing- Ryan Alcorn, Joel Alfaro, Neil Gayeta
   File: LookAt.cpp
   Description: Class implementation for derived class LookAt. */

#include "LookAt.hpp"

/* Parameterless constructor calls base class constructor */
LookAt::LookAt() : Verb(LOOK_AT_NAME, VERBS::LOOK_AT) {}

/* Function returns name this verb */
std::string LookAt::getName() 
{
    return this->name;
}

/* Function returns the enum value of this verb */
VERBS LookAt::getActionEvent() 
{
    return this->actionEvent;
}