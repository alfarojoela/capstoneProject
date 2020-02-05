/* Project Name: Capstone Project
   Class: CS 467
   Team: Team Thing- Ryan Alcorn, Joel Alfaro, Neil Gayeta
   File: Look.hpp
   Description: Class header for derived class Look.*/

#pragma once

#include "Verb.hpp"

class Look : public Verb {

public:
    Look();
    std::string getName();
    VERBS getActionEvent();

};