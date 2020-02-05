/* Project Name: Capstone Project
   Class: CS 467
   Team: Team Thing- Ryan Alcorn, Joel Alfaro, Neil Gayeta
   File: Flee.hpp
   Description: Class header for derived class Flee.*/

#pragma once

#include "Verb.hpp"

class Flee : public Verb {

public:
    Flee();
    std::string getName();
    VERBS getActionEvent();

};