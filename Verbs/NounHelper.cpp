#include "NounHelper.hpp"

std::vector<std::string> noun::getNouns() 
{
    std::vector<std::string> nouns {
        "wall",
        "lights",
        "latrine",
        "basement",
        "conference",
        "conference room",
        "conferenceroom",
        "dog",
        "kennel",
        "dog kennel",
        "dogkennel",
        "equipment",
        "equipment room",
        "equipmentroom",
        "galley",
        "garage",
        "hallway1",
        "hallway2",
        "macready",
        "mess",
        "hall",
        "mess hall",
        "messhall",
        "radio room",
        "radioroom",
        "research",
        "lab",
        "research lab",
        "researchlab",
        "room",
        "sick",
        "bay",
        "sick bay",
        "sickbay",
        "tool",
        "shed",
        "tool shed",
        "toolshed",
        "computer",
        "bed",
        "booze",
        "red",
        "herring",
        "red herring",
        "redherring",
        "toilet",
        "creature",
        "toilet paper",
        "toiletpaper",
        "beer",
        "vodka",
        "mask",
        "tequila",
        "lights",
        "wall",
        "macready",
        "matarata",
        "whiskey",
        "gin",
        "back",
        "doppelganger"
        "fists",
        "petri",
        "dish",
        "petri dish",
        "petridish",
        "gun",
        "flame",
        "thrower",
        "flamethrower",
        "flame thrower",
        "axe",
        "creature",
        "blow",
        "torch",
        "blow torch",
        "blowtorch",
        "inventory",
        "crew",
        "member",
        "crew member",
        "crewmember",
        "floor",
        "alien",
        "alien dog",
        "aliendog",
        "scalpel",
        "copper",
        "copper wire",
        "copperwire",
        "wild",
        "wild turkey",
        "rope",
        "hollow",
        "hollow statue",
        "snow",
        "snow mobile",
        "snowmobile",
        "makers",
        "makers mark"
    };

    return nouns;
}

std::string noun::checkCombinedNoun(std::string str, std::string streamString)
{ 
    std::string returnString = str;

    for (const auto &noun : getNouns()) 
    {
        if (str + " " + streamString == noun)
        {
            returnString = noun;
            break;
        }
    }

    return returnString;
}