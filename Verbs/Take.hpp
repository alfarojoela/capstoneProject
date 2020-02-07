/* Project Name: Capstone Project
   Class: CS 467
   Team: Team Thing- Ryan Alcorn, Joel Alfaro, Neil Gayeta
   File: Take.hpp
   Description: Class header for derived class Take.*/

#pragma once

#include "Verb.hpp"

class Take : public Verb {

public:
    Take();
    std::string getName();
    VERBS getActionEvent();

};