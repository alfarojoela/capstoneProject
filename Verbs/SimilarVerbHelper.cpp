#include "SimilarVerbHelper.hpp"

// TODO: STILL ADDING SIMILAR WORDS & FUNCTIONS

std::vector<std::string> similar::getTalkVerbs()
{
    std::vector<std::string> similarTalkVerbs {
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
        "wash down"};

    return similarDrinkVerbs;
}

std::vector<std::string> similar::getSmellVerbs()
{
    std::vector<std::string> similarSmellVerbs {
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
        "charge", 
        "strike", 
        "advance"
    };

    return similarAttackVerbs;
}
std::vector<std::string> similar::getEatVerbs()
{
    std::vector<std::string> similarEatVerbs {
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