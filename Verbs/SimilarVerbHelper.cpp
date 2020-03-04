/* Project Name: Capstone Project
   Class: CS 467
   Team: Team Thing- Ryan Alcorn, Joel Alfaro, Neil Gayeta
   File: SimilarVerbHelper.cpp
   Description: Class implementation for the similar verb helper utilized in the parser */

#include "SimilarVerbHelper.hpp"

std::vector<std::string> similar::getTalkVerbs()
{
    std::vector<std::string> similarTalkVerbs {
        "talk",
        "chat", 
        "communicate", 
        "says", 
        "tell"
    };

    return similarTalkVerbs;
}

std::vector<std::string> similar::getDrinkVerbs()
{
    std::vector<std::string> similarDrinkVerbs {
        "drink",
        "consume", 
        "gulp", 
        "guzzle", 
        "inhale", 
        "sip", 
        "slurp", 
        "suck", 
        "downs", 
        "indulges", 
        "swig", 
        "wash down"
    };

    return similarDrinkVerbs;
}

std::vector<std::string> similar::getSmellVerbs()
{
    std::vector<std::string> similarSmellVerbs {
        "smell",
        "breathe", 
        "detect", 
        "sniff", 
        "whiff"
    };

    return similarSmellVerbs;
}

std::vector<std::string> similar::getDropVerbs()
{
    std::vector<std::string> similarDropVerbs {
        "drop",
        "abandon", 
        "dump", 
        "give up", 
        "lower", 
        "release", 
        "shed"
    };

    return similarDropVerbs;
}
std::vector<std::string> similar::getAttackVerbs()
{
    std::vector<std::string> similarAttackVerbs {
        "attack",
        "charge", 
        "strike", 
        "advance",
        "hit"
    };

    return similarAttackVerbs;
}
std::vector<std::string> similar::getEatVerbs()
{
    std::vector<std::string> similarEatVerbs {
        "eat",
        "devour", 
        "dine", 
        "feed", 
        "ingest", 
        "nibble", 
        "swallow", 
        "bite"
    };

    return similarEatVerbs;
}

std::vector<std::string> similar::getUseVerbs() 
{
    std::vector<std::string> similarUseVerbs {
        "use", 
        "apply", 
        "handle", 
        "spend", 
        "expend",
        "turn"
    };

    return similarUseVerbs;
}

std::vector<std::string> similar::getJumpVerbs() 
{
    std::vector<std::string> similarJumpVerbs {
        "jump", 
        "bounce", 
        "hurdle", 
        "rise", 
        "upsurge", 
        "vault", 
        "hop", 
        "leap", 
        "pounce", 
        "skip", 
        "spring"
    };

    return similarJumpVerbs;
}

std::vector<std::string> similar::getFleeVerbs() 
{
    std::vector<std::string> similarFleeVerbs {
        "flee", 
        "depart", 
        "desert", 
        "retreat", 
        "take off", 
        "vanish", 
        "evade"
    };

    return similarFleeVerbs;
}

std::vector<std::string> similar::getBreakVerbs()
{
    std::vector<std::string> similarBreakVerbs {
        "break",
        "crack", 
        "breach", 
        "fracture", 
        "rupture"
    };

    return similarBreakVerbs;
}

std::vector<std::string> similar::getLookVerbs() 
{
    std::vector<std::string> similarLookVerbs {
        "look",
        "eye", 
        "peek", 
        "stare", 
        "view", 
        "glimpse", 
        "glance",
        "check",
        "inspect",
        "examine"
    };

    return similarLookVerbs;
}

std::vector<std::string> similar::getLookAtVerbs()
{
    std::vector<std::string> similarLookAtVerbs {
        "look at",
        "detect", 
        "acknowledge", 
        "discern", 
        "recognize", 
        "note", 
        "see"
    };

    return similarLookAtVerbs;
}

std::vector<std::string> similar::getGoVerbs()
{
    std::vector<std::string> similarGoVerbs {
        "go",
        "progress",
        "move", 
        "pass", 
        "continue" 
    };

    return similarGoVerbs;
}
std::vector<std::string> similar::getTakeVerbs()
{
    std::vector<std::string> similarTakeVerbs {
        "take",
        "grab",
        "get",
        "pick up"
    };

    return similarTakeVerbs;
}
std::vector<std::string> similar::getHelpVerbs()
{
    std::vector<std::string> similarHelpVerbs {
        "help",
        "advice", 
        "aid", 
        "guidance", 
        "helping hand", 
        "support", 
        "assist", 
        "assistance", 
        "utility"
    };

    return similarHelpVerbs;
}
std::vector<std::string> similar::getInventoryVerbs()
{
    std::vector<std::string> similarInventoryVerbs {
        "inventory",
        "reserve", 
        "supply", 
        "supplies", 
        "stockpile", 
        "bag", 
        "backpack", 
        "items", 
        "pouch", 
        "gear", 
        "kit", 
        "pack", 
        "sack", 
        "knapsack"
    };

    return similarInventoryVerbs;
}

std::vector<std::string> similar::getMiscVerbs()
{
    std::vector<std::string> similarMiscVerbs {
        "room",
        "current",
        "map",
        "savegame",
        "loadgame",
        "show",
        "deus"
    };

    return similarMiscVerbs;
}

std::string similar::parseMiscEdgeInput(std::string input) 
{
    std::istringstream inputStream;
    inputStream.str(input);

    std::string tempString, returnInput = "";

    if (input.find("turn on") != std::string::npos || input.find("turnon") != std::string::npos) 
    {
        while (inputStream >> tempString) 
        {
            if (tempString == "turn" || tempString == "turnon") 
                returnInput += "use ";

            else if (tempString == "on") 
                continue;

            else
                returnInput += tempString + " ";
        }

        return returnInput;
    }
    
    if (input.find("hallway 2") != std::string::npos || input.find("hallway2") != std::string::npos) 
    {
        while (inputStream >> tempString) 
        {
            if (tempString == "hallway" || tempString == "hallway2") 
                returnInput += "hallway2 ";
            else 
                returnInput += tempString + " ";
        }

        return returnInput;
    }

    if (input.find("check") != std::string::npos)
    {
        while (inputStream >> tempString) 
        {
            if (tempString == "check")
                returnInput += "look at ";
            else
                returnInput += tempString + " ";
        }

        return returnInput;
    }

    if (input.find("dr") != std::string::npos)
    {
        while (inputStream >> tempString)
        {
            if (tempString == "dr") 
                returnInput += "doctor ";
            else
                returnInput += tempString + " ";
        }

        return returnInput;
    }

    // TODO: REFACTOR AND ADD
    while (inputStream >> tempString) 
    {
        if (tempString == "macready's" || tempString == "macreadys" || tempString == "macready's quarter" || 
            tempString == "macready's quarters" || tempString == "mcready's" || tempString == "mcreadys" ||
            tempString == "mcready's quarters" || tempString == "mcready's quarter" || tempString == "mcreadys quarters" ||
            tempString == "macreadys quarters") 
            returnInput += "macready ";

        else if (tempString == "movies" || tempString == "movie" || tempString == "films" || tempString == "film") 
            returnInput += "tapes ";
        else 
            returnInput += tempString + " ";
    }

    return returnInput;
}