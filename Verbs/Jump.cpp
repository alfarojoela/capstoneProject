/* Project Name: Capstone Project
   Class: CS 467
   Team: Team Thing- Ryan Alcorn, Joel Alfaro, Neil Gayeta
   File: Jump.cpp
   Description: Class implementation for derived class Jump. */

#include "Jump.hpp"

/* Parameterless constructor calls base class constructor */
Jump::Jump() : Verb(JUMP_NAME, VERBS::JUMP) {}

/* Function returns name this verb */
std::string Jump::getName() 
{
    return this->name;
}

/* Function returns the enum value of this verb */
VERBS Jump::getActionEvent() 
{
    return this->actionEvent;
}