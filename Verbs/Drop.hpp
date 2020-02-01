/* Project Name: Capstone Project
   Class: CS 467
   Team: Team Thing- Ryan Alcorn, Joel Alfaro, Neil Gayeta
   File: Drop.hpp
   Description: Class header for derived class Drop.*/

#pragma once

#include "Verb.hpp"

class Drop : public Verb {

public:
    Drop();
    std::string getName();
    VERBS getActionEvent();

};