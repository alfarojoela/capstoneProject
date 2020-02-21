/* Project Name: Capstone Project
   Class: CS 467
   Team: Team Thing- Ryan Alcorn, Joel Alfaro, Neil Gayeta
   File: NounHelper.hpp
   Description: Class header for the noun helper utilized in the parser */

#pragma once

#include <iostream>
#include <vector>
#include <string>

namespace noun 
{
    std::vector<std::string> getNouns();
    std::string checkCombinedNoun(std::string, std::string);
}