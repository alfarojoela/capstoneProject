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
    actions.emplace_back(new Use());
    actions.emplace_back(new Jump());
    actions.emplace_back(new Flee());
    actions.emplace_back(new Break());
    actions.emplace_back(new Look());
    actions.emplace_back(new LookAt());
    actions.emplace_back(new Go());
    actions.emplace_back(new Take());
    actions.emplace_back(new Help());
    actions.emplace_back(new Inventory());

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

    similarActions.insert ( { validActions.front()->getName(), similar::getUseVerbs() } );
    validActions.erase(validActions.begin());

    similarActions.insert ( { validActions.front()->getName(), similar::getJumpVerbs() } );
    validActions.erase(validActions.begin());

    similarActions.insert ( { validActions.front()->getName(), similar::getFleeVerbs() } );
    validActions.erase(validActions.begin());

    similarActions.insert ( { validActions.front()->getName(), similar::getBreakVerbs() } );
    validActions.erase(validActions.begin());

    similarActions.insert ( { validActions.front()->getName(), similar::getLookVerbs() } );
    validActions.erase(validActions.begin());

    similarActions.insert ( { validActions.front()->getName(), similar::getLookAtVerbs() } );
    validActions.erase(validActions.begin());

    similarActions.insert ( { validActions.front()->getName(), similar::getGoVerbs() } );
    validActions.erase(validActions.begin());

    similarActions.insert ( { validActions.front()->getName(), similar::getTakeVerbs() } );
    validActions.erase(validActions.begin());

    similarActions.insert ( { validActions.front()->getName(), similar::getHelpVerbs() } );
    validActions.erase(validActions.begin());

    similarActions.insert ( { validActions.front()->getName(), similar::getInventoryVerbs() } );
    validActions.erase(validActions.begin());

    return similarActions;
}

/* Static class unordered map which contains all similar verbs that will be compared against the valid actions */
std::unordered_map<std::string, std::vector<std::string>> Parser::similarActions = initializeSimilarActions();

std::unordered_map<std::string, std::vector<std::string>> Parser::getSimilarActions()
{
    return similarActions;
}

/* Predicate for stripping non-alphanumeric characters */
bool parserPredicate(char character)
{
    std::locale locale;
    return (std::isalpha(character, locale) || character == ' ') ? false : true;
}

/* Main text parser */
void Parser::parseInput(std::string userInput, std::string (&commands)[CONST_THREE])
{
    bool verbSet = false, prepSet = false, nounSet = false;
    commands[0] = commands[1] = commands[2] = "";

    /* Strip all non-alphanumeric characters */
    // userInput.erase(std::remove_if(userInput.begin(), userInput.end(), parserPredicate), userInput.end());

    /* Change every character to a lower-case for parsing */
    std::transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);

    /* Stream */
    std::istringstream inputStream;
    inputStream.str(userInput);

    std::string tempValue;
    while (inputStream >> tempValue)
    {
        /* Check verbs */
        if (!verbSet) 
        {
            const auto actions = getValidActions();
            const auto similarActions = getSimilarActions();

            for (Verb *verb : actions)
            {
                auto similar = similarActions.find(verb->getName())->second;
                for (const auto &similarValue : similar)
                {
                    if (tempValue == similarValue) 
                    {
                        commands[0] = verb->getName();

                        verbSet = true;
                        break;
                    }
                }

                if (verbSet) break;
            }

            if (verbSet) continue;
        }

        /* Check prepositions */
        if (!prepSet)
        {
            const auto prepositions = preposition::getPrepositions();

            for (const auto &prep : prepositions)
            {
                if (tempValue == prep) 
                {
                    commands[1] = tempValue;

                    prepSet = true;
                    break;
                }
            }
            
            if (prepSet) continue;
        }

        /* Check feature/item */
        if (!nounSet)
        {
            const auto nouns = noun::getNouns();

            for (const auto &noun : nouns) 
            {
                if (tempValue == noun)
                {
                    commands[2] = tempValue;

                    nounSet = true;
                    break;
                }
            }
            
            if (nounSet) continue;
        }
    }
}