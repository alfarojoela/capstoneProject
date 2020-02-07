/* Project Name: Capstone Project
   Class: CS 467
   Team: Team Thing- Ryan Alcorn, Joel Alfaro, Neil Gayeta
   File: Go.cpp
   Description: Class implementation for derived class Go. */

#include "Go.hpp"

/* Parameterless constructor calls base class constructor */
Go::Go() : Verb(GO_NAME, VERBS::GO) {}

/* Function returns name this verb */
std::string Go::getName() 
{
    return this->name;
}

/* Function returns the enum value of this verb */
VERBS Go::getActionEvent() 
{
    return this->actionEvent;
}