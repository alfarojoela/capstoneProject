/* Project Name: Capstone Project
   Class: CS 467
   Team: Team Thing- Ryan Alcorn, Joel Alfaro, Neil Gayeta
   File: Parser.cpp
   Description: Class implementation for main text Parser class */

#include "Parser.hpp"

/* Function initializes the class verbs vector with all the valid verb objects */
std::vector<Verb *> initializeActions() 
{
    std::vector<Verb *> actions;

    actions.emplace_back(new Talk());
    actions.emplace_back(new Smell());
    actions.emplace_back(new Drink());
    // TODO: MORE VERBS TO BE ADDED

    return actions;
}

/* Static class vector initialized with all valid verb objects */
std::vector<Verb *> Parser::validActions = initializeActions();

/* Destructor */
Parser::~Parser()
{
    std::cout << this->validActions.size() << std::endl;
    for (auto verb = validActions.begin(); verb != validActions.end(); verb++)
    {
        auto tempVerb = *verb;
        delete tempVerb;
    }

    this->validActions.clear();
}