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
    actions.emplace_back(new Drop());
    actions.emplace_back(new Attack());
    actions.emplace_back(new Eat());
    // TODO: MORE VERBS TO BE ADDED

    return actions;
}

/* Static class vector initialized with all valid verb objects */
std::vector<Verb *> Parser::validActions = initializeActions();

/* Static getter for valid action vector */
std::vector<Verb *> Parser::getValidActions() 
{
    return Parser::validActions;
}

/* Function initializes the similar verbs unordered map with all valid similar verbs */
std::unordered_map<std::string, std::vector<std::string>> initializeSimilarActions()
{
    std::unordered_map<std::string, std::vector<std::string>> similarActions;

    auto validActions = Parser::getValidActions();

    similarActions.insert( { validActions.front()->getName(), similar::getTalkVerbs() } );
    validActions.erase(validActions.begin());

    similarActions.insert( { validActions.front()->getName(), similar::getSmellVerbs() } );
    validActions.erase(validActions.begin());

    similarActions.insert( { validActions.front()->getName(), similar::getDrinkVerbs() } );
    validActions.erase(validActions.begin());

    similarActions.insert( { validActions.front()->getName(), similar::getDropVerbs() } );
    validActions.erase(validActions.begin());

    similarActions.insert( { validActions.front()->getName(), similar::getAttackVerbs() } );
    validActions.erase(validActions.begin());

    similarActions.insert( { validActions.front()->getName(), similar::getEatVerbs() } );
    validActions.erase(validActions.begin());

    // TODO: ADDING MORE SIMILAR ACTIONS

    return similarActions;
}

/* Static class unordered map which contains all similar verbs that will be compared against the valid actions */
std::unordered_map<std::string, std::vector<std::string>> Parser::similarActions = initializeSimilarActions();

/* Destructor */
Parser::~Parser()
{
    /* Clear vector allocation */
    std::cout << this->validActions.size() << std::endl;
    for (auto verb = validActions.begin(); verb != validActions.end(); verb++)
    {
        auto tempVerb = *verb;
        delete tempVerb;
    }

    this->validActions.clear();
}