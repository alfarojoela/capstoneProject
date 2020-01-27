/* Project Name: Capstone Project
   Class: CS 467
   Team: Team Thing- Ryan Alcorn, Joel Alfaro, Neil Gayeta
   File: Verb.hpp
   Description: Base class for Verb children classes */

#pragma once

#include <iostream>
#include <string>
#include "VerbEnum.hpp"

class Verb {

public:

    Verb(std::string name, VERBS action) 
    {
        this->name = name;
        this->actionEvent = action;

    }
    virtual std::string getName() = 0;
    virtual VERBS getActionEvent() = 0;

protected:

    std::string name;
    VERBS actionEvent;

};