/* Project Name: Capstone Project
   Class: CS 467
   Team: Team Thing- Ryan Alcorn, Joel Alfaro, Neil Gayeta
   File: Break.hpp
   Description: Class header for derived class Break.*/

#pragma once

#include "Verb.hpp"

class Break : public Verb {

public:
    Break();
    std::string getName();
    VERBS getActionEvent();

};