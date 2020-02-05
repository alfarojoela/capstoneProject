/* Project Name: Capstone Project
   Class: CS 467
   Team: Team Thing- Ryan Alcorn, Joel Alfaro, Neil Gayeta
   File: Jump.hpp
   Description: Class header for derived class Jump.*/

#pragma once

#include "Verb.hpp"

class Jump : public Verb {

public:
    Jump();
    std::string getName();
    VERBS getActionEvent();

};