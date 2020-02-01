/* Project Name: Capstone Project
   Class: CS 467
   Team: Team Thing- Ryan Alcorn, Joel Alfaro, Neil Gayeta
   File: Eat.cpp
   Description: Class implementation for derived class Eat. */

#include "Eat.hpp"

/* Parameterless constructor calls base class constructor */
Eat::Eat() : Verb(EAT_NAME, VERBS::EAT) {}

/* Function returns name this verb */
std::string Eat::getName() 
{
    return this->name;
}

/* Function returns the enum value of this verb */
VERBS Eat::getActionEvent() 
{
    return this->actionEvent;
}