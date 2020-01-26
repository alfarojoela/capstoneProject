/* Project Name: Capstone Project
   Class: CS 467
   Team: Team Thing- Ryan Alcorn, Joel Alfaro, Neil Gayeta
   File: Drink.cpp
   Description: Class implementation for derived class Drink. */

#include "Drink.hpp"

/* Parameterless constructor calls base class constructor */
Drink::Drink() : Verb(DRINK_NAME, VERBS::DRINK) {}

/* Function returns name this verb */
std::string Drink::getName() 
{
    return this->name;
}

/* Function returns the enum value of this verb */
VERBS Drink::getActionEvent() 
{
    return this->actionEvent;
}