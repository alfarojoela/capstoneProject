/* Project Name: Capstone Project
   Class: CS 467
   Team: Team Thing- Ryan Alcorn, Joel Alfaro, Neil Gayeta
   File: Talk.hpp
   Description: Class header for derived class Talk.*/

#pragma once

#include "Verb.hpp"

class Talk : public Verb {

public:
    Talk();
    std::string getName();
    VERBS getActionEvent();

};