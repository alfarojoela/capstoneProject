/* 
PRELIMINARY LIST

Talk- chat, communicate, says, tell
Drink - consume, gulp, guzzle, inhale, sip, slurp, suck, downs, indulges, swig, wash down
Smell - breathe, detect, sniff, whiff
Drop - abandon, dump, give up, lower, release, shed
Attack - charge, strike, advance
Eat - devour, dine, feed, ingest, nibble, swallow, bite
Use - apply, handle, spend, expend
Jump - bounce, hurdle, rise, upsurge, vault, hop, leap, pounce, skip, spring
Flee - depart, desert, retreat, take off, vanish, evade
Break - crack, breach, fracture, rupture, fracture
Look - eye, peek, stare, view, glimpse, glance
Look at - detect, acknowledge, discern, recognize, note, see
Go - progress, move, pass, continue 
Take - grab, get
Help - advice, aid, guidance, helping hand, support, assist, assistance, utility
Inventory - reserve, supply, supplies, stockpile, bag, backpack, items, pouch, gear, kit, pack, sack, knapsack

*/
#pragma once

#include <iostream>
#include <vector>
#include <string>

namespace similar
{
    std::vector<std::string> getTalkVerbs();
    std::vector<std::string> getSmellVerbs();
    std::vector<std::string> getDrinkVerbs();
    std::vector<std::string> getDropVerbs();
    std::vector<std::string> getAttackVerbs();
    std::vector<std::string> getEatVerbs();
    std::vector<std::string> getUseVerbs();
    std::vector<std::string> getJumpVerbs();
    std::vector<std::string> getFleeVerbs();

    // TODO: ADDING MORE ACTIONS

} 
