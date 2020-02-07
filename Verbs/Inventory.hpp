/* Project Name: Capstone Project
   Class: CS 467
   Team: Team Thing- Ryan Alcorn, Joel Alfaro, Neil Gayeta
   File: Inventory.hpp
   Description: Class header for derived class Inventory.*/

#pragma once

#include "Verb.hpp"

class Inventory : public Verb {

public:
    Inventory();
    std::string getName();
    VERBS getActionEvent();

};