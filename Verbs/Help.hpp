/* Project Name: Capstone Project
   Class: CS 467
   Team: Team Thing- Ryan Alcorn, Joel Alfaro, Neil Gayeta
   File: Help.hpp
   Description: Class header for derived class Help.*/

#pragma once

#include "Verb.hpp"

class Help : public Verb {

public:
    Help();
    std::string getName();
    VERBS getActionEvent();

};