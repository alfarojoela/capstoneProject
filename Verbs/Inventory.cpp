/* Project Name: Capstone Project
   Class: CS 467
   Team: Team Thing- Ryan Alcorn, Joel Alfaro, Neil Gayeta
   File: Inventory.cpp
   Description: Class implementation for derived class Inventory. */

#include "Inventory.hpp"

/* Parameterless constructor calls base class constructor */
Inventory::Inventory() : Verb(INVENTORY_NAME, VERBS::INVENTORY) {}

/* Function returns name this verb */
std::string Inventory::getName() 
{
    return this->name;
}

/* Function returns the enum value of this verb */
VERBS Inventory::getActionEvent() 
{
    return this->actionEvent;
}