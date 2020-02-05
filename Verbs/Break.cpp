/* Project Name: Capstone Project
   Class: CS 467
   Team: Team Thing- Ryan Alcorn, Joel Alfaro, Neil Gayeta
   File: Break.cpp
   Description: Class implementation for derived class Break. */

#include "Break.hpp"

/* Parameterless constructor calls base class constructor */
Break::Break() : Verb(BREAK_NAME, VERBS::BREAK) {}

/* Function returns name this verb */
std::string Break::getName() 
{
    return this->name;
}

/* Function returns the enum value of this verb */
VERBS Break::getActionEvent() 
{
    return this->actionEvent;
}