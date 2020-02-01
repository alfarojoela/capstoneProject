/* Project Name: Capstone Project
   Class: CS 467
   Team: Team Thing- Ryan Alcorn, Joel Alfaro, Neil Gayeta
   File: Attack.cpp
   Description: Class implementation for derived class Attack. */

#include "Attack.hpp"

/* Parameterless constructor calls base class constructor */
Attack::Attack() : Verb(ATTACK_NAME, VERBS::ATTACK) {}

/* Function returns name this verb */
std::string Attack::getName() 
{
    return this->name;
}

/* Function returns the enum value of this verb */
VERBS Attack::getActionEvent() 
{
    return this->actionEvent;
}