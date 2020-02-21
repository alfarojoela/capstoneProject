#include "SimilarVerbHelper.hpp"

// TODO: STILL ADDING SIMILAR WORDS & FUNCTIONS

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
        "advance"
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
        "expend"
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
        "glance"
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
        "loadgame"
    };

    return similarMiscVerbs;
}
