/* Project Name: Capstone Project
   Class: CS 467
   Team: Team Thing- Ryan Alcorn, Joel Alfaro, Neil Gayeta
   File: Drink.hpp
   Description: Class header for derived class Drink.*/

#pragma once

#include "Verb.hpp"

class Drink : public Verb {

public:
    Drink();
    std::string getName();
    VERBS getActionEvent();

};

