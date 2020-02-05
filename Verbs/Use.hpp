/* Project Name: Capstone Project
   Class: CS 467
   Team: Team Thing- Ryan Alcorn, Joel Alfaro, Neil Gayeta
   File: Use.hpp
   Description: Class header for derived class Use.*/

#pragma once

#include "Verb.hpp"

class Use : public Verb {

public:
    Use();
    std::string getName();
    VERBS getActionEvent();

};