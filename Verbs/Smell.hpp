/* Project Name: Capstone Project
   Class: CS 467
   Team: Team Thing- Ryan Alcorn, Joel Alfaro, Neil Gayeta
   File: Smell.hpp
   Description: Class header for derived class Smell.*/

#pragma once

#include "Verb.hpp"

class Smell : public Verb {

public:
    Smell();
    std::string getName();
    VERBS getActionEvent();

};