/* Project Name: Capstone Project
   Class: CS 467
   Team: Team Thing- Ryan Alcorn, Joel Alfaro, Neil Gayeta
   File: LookAt.hpp
   Description: Class header for derived class LookAt.*/

#pragma once

#include "Verb.hpp"

class LookAt : public Verb {

public:
    LookAt();
    std::string getName();
    VERBS getActionEvent();

};