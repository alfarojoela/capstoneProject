/* Project Name: Capstone Project
   Class: CS 467
   Team: Team Thing- Ryan Alcorn, Joel Alfaro, Neil Gayeta
   File: Talk.cpp
   Description: Class implementation for derived class Talk. */

#include "Talk.hpp"

/* Parameterless constructor calls base class constructor */
Talk::Talk() : Verb(TALK_NAME, VERBS::TALK) {}

/* Function returns name this verb */
std::string Talk::getName() 
{
    return this->name;
}

/* Function returns the enum value of this verb */
VERBS Talk::getActionEvent() 
{
    return this->actionEvent;
}