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

    similarActions.insert({validActions.front()->getName(), similar::getTalkVerbs()});
    validActions.erase(validActions.begin());

    similarActions.insert({validActions.front()->getName(), similar::getSmellVerbs()});
    validActions.erase(validActions.begin());

    similarActions.insert({validActions.front()->getName(), similar::getDrinkVerbs()});
    validActions.erase(validActions.begin());

    similarActions.insert({validActions.front()->getName(), similar::getDropVerbs()});
    validActions.erase(validActions.begin());

    similarActions.insert({validActions.front()->getName(), similar::getAttackVerbs()});
    validActions.erase(validActions.begin());

    similarActions.insert({validActions.front()->getName(), similar::getEatVerbs()});
    validActions.erase(validActions.begin());

    similarActions.insert({validActions.front()->getName(), similar::getUseVerbs()});
    validActions.erase(validActions.begin());

    similarActions.insert({validActions.front()->getName(), similar::getJumpVerbs()});
    validActions.erase(validActions.begin());

    similarActions.insert({validActions.front()->getName(), similar::getFleeVerbs()});
    validActions.erase(validActions.begin());

    similarActions.insert({validActions.front()->getName(), similar::getBreakVerbs()});
    validActions.erase(validActions.begin());

    similarActions.insert({validActions.front()->getName(), similar::getLookVerbs()});
    validActions.erase(validActions.begin());

    similarActions.insert({validActions.front()->getName(), similar::getLookAtVerbs()});
    validActions.erase(validActions.begin());

    similarActions.insert({validActions.front()->getName(), similar::getGoVerbs()});
    validActions.erase(validActions.begin());

    similarActions.insert({validActions.front()->getName(), similar::getTakeVerbs()});
    validActions.erase(validActions.begin());

    similarActions.insert({validActions.front()->getName(), similar::getHelpVerbs()});
    validActions.erase(validActions.begin());

    similarActions.insert({validActions.front()->getName(), similar::getInventoryVerbs()});
    validActions.erase(validActions.begin());

    return similarActions;
}

/* Static class unordered map which contains all similar verbs that will be compared against the valid actions */
std::unordered_map<std::string, std::vector<std::string>> Parser::similarActions = initializeSimilarActions();

/* Static getter for similar actions */
std::unordered_map<std::string, std::vector<std::string>> Parser::getSimilarActions()
{
    return similarActions;
}

/* REFERENCE: https://en.wikibooks.org/wiki/Algorithm_Implementation/Strings/Levenshtein_distance for below
   implementation of the Levenshtein distance algorithm. Instead of returning only the difference int, a pair
   of the difference int and word string is returned as this is called  */
std::pair<int, std::string> Parser::similarWordDistance(const std::string &userInput, const std::string &listWord)
{
    const auto inputLength = userInput.size(), wordLength = listWord.size();
    std::vector<std::vector<int>> matrix(inputLength + 1, std::vector<int>(wordLength + 1));

    matrix[0][0] = 0;

    for (int i = 1; i <= inputLength; i++)
        matrix[i][0] = i;

    for (int i = 1; i <= wordLength; i++)
        matrix[0][i] = i;

    for (int i = 1; i <= inputLength; i++)
        for (int j = 1; j <= wordLength; j++)
            matrix[i][j] = std::min({matrix[i - 1][j] + 1, matrix[i][j - 1] + 1, matrix[i - 1][j - 1] + (userInput[i - 1] == listWord[j - 1] ? 0 : 1)});

    return make_pair(matrix[inputLength][wordLength], listWord);
}

/* Static compare function that takes in the user input and checks for misspelled words against the verbs,
   nouns, and preposition lists. This utilizes the Levenshtein distance algorithm 
   (REFERENCE: https://medium.com/@ethannam/understanding-the-levenshtein-distance-equation-for-beginners-c4285a5604f0). 
   It is utilized by checking the distance/difference between the two words by characters. */
std::string Parser::compareWords(std::string input)
{
    std::istringstream inputStream;
    inputStream.str(input);

    const auto actions = getValidActions();
    const auto similarActions = getSimilarActions();

    std::vector<std::string> values;
    std::string tempStr, returnStr = "";

    /* Add verbs */
    for (Verb *verb : actions)
    {
        auto similar = similarActions.find(verb->getName())->second;
        for (const auto similarValue : similar)
            values.push_back(similarValue);
    }

    /* Misc verbs */
    for (const auto misc : similar::getMiscVerbs())
        values.push_back(misc);
    
    /* Prepositions */
    for (const auto prep : preposition::getPrepositions())
        values.push_back(prep);

    /* Nouns */
    for (const auto noun : noun::getNouns())
        values.push_back(noun);

    /* Iterate through stream checking the similarity between the lists of nouns, prepositions, and verb 
       with each word in the stream (i.e. original user input) */
    while (inputStream >> tempStr) 
    {
        for (const auto word : values)
        {
            const auto distance = similarWordDistance(tempStr, word);
            returnStr += (distance.first == 1) ? word + " " : tempStr + " ";
            
        }
    }

    return returnStr;
}

/* Main text parser */
void Parser::parseInput(std::string userInput, std::string (&commands)[CONST_THREE])
{
    bool verbSet = false, prepSet = false, nounSet = false;
    commands[0] = commands[1] = commands[2] = "";

    /* Change every character to a lower-case for parsing */
    std::transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);

    /* TODO: UNCOMMENT WHEN DONE TESTING */
    // userInput = compareWords(userInput);

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

                if (verbSet)
                    break;
            }

            if (!verbSet)
            {
                for (const auto &similarValue : similar::getMiscVerbs())
                {
                    if (tempValue == similarValue)
                    {
                        commands[0] = tempValue;

                        verbSet = true;
                        break;
                    }
                }
            }

            if (verbSet)
                continue;
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

            if (prepSet)
                continue;
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

            if (nounSet)
            {
                inputStream >> tempValue;
                commands[2] = noun::checkCombinedNoun(commands[2], tempValue);
                continue;
            }
        }
    }
}