/* Project Name: Capstone Project
   Class: CS 467
   Team: Team Thing- Ryan Alcorn, Joel Alfaro, Neil Gayeta
   File: Eat.hpp
   Description: Class header for derived class Eat.*/

#pragma once

#include "Verb.hpp"

class Eat : public Verb {

public:
    Eat();
    std::string getName();
    VERBS getActionEvent();

};