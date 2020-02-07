/* Project Name: Capstone Project
   Class: CS 467
   Team: Team Thing- Ryan Alcorn, Joel Alfaro, Neil Gayeta
   File: Go.hpp
   Description: Class header for derived class Go.*/

#pragma once

#include "Verb.hpp"

class Go : public Verb {

public:
    Go();
    std::string getName();
    VERBS getActionEvent();

};