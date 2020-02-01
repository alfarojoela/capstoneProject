/* Project Name: Capstone Project
   Class: CS 467
   Team: Team Thing- Ryan Alcorn, Joel Alfaro, Neil Gayeta
   File: Parser.hpp
   Description: Class header for Parser class .*/

#pragma once

#include <unordered_map>
#include <vector>
#include <utility>

#include "SimilarVerbHelper.hpp"

#include "Drink.hpp"
#include "Smell.hpp"
#include "Talk.hpp"
#include "Drop.hpp"
#include "Attack.hpp"
#include "Eat.hpp"

class Parser {

private:
    static std::vector<Verb *> validActions;
    static std::unordered_map<std::string, std::vector<std::string>> similarActions;
    // TODO: CONTINUE ADDING PARSER MEMBERS & FUNCTIONALITY

public:
    ~Parser();
    static std::vector<std::string> parseInput(std::string);
    static std::vector<Verb *> getValidActions();
    static std::unordered_map<std::string, std::vector<std::string>> getSimilarActions();



};