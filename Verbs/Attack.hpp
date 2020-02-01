/* Project Name: Capstone Project
   Class: CS 467
   Team: Team Thing- Ryan Alcorn, Joel Alfaro, Neil Gayeta
   File: Attack.hpp
   Description: Class header for derived class Attack.*/

#pragma once

#include "Verb.hpp"

class Attack : public Verb {

public:
    Attack();
    std::string getName();
    VERBS getActionEvent();

};