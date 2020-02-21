/* Project Name: Capstone Project
   Class: CS 467
   Team: Team Thing- Ryan Alcorn, Joel Alfaro, Neil Gayeta
   File: PrepositionHelper.cpp
   Description: Class implementation for the preposition helper utilized in the parser */

#include "PrepositionHelper.hpp"

std::vector<std::string> preposition::getPrepositions() 
{
    std::vector<std::string> prepositions {
        "about", 
        "on", 
        "onto", 
        "above" , 
        "the", 
        "into",
        "over",
        "under",
        "in",
        "off",
        "at",
        "to",
        "by",
        "above",
        "near",
        "with",
        "since",
        "for",
        "from",
        "upon",
        "onto",
        "atop"
    };

    return prepositions;
}