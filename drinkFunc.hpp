#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <ios>
#include <limits>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Functions accessed by main*/
#include "map.hpp"
#include "intro.hpp"
#include "menu.hpp"
#include "helpFunc.hpp"
#include "gameEnd.hpp"

/*Functions to interact with item objects*/
#include "takeFunc.hpp"
#include "eatFunc.hpp"
#include "lookAtFunc.hpp"
#include "drinkFunc.hpp"
#include "dropFunc.hpp"
#include "goFunc.hpp"
#include "roomRouterFunc.hpp"

/*Function to interact with room objects*/
#include "roomInteractionMacready.hpp"
#include "roomInteractionHallway1.hpp"
#include "roomInteractionLatrine.hpp"
#include "roomInteractionEquipmentRoom.hpp"
#include "roomInteractionToolShed.hpp"
#include "roomInteractionSickBay.hpp"
#include "roomInteractionRadioRoom.hpp"
#include "roomInteractionResearchLab.hpp"
#include "roomInteractionMessHall.hpp"
#include "roomInteractionHallway2.hpp"
#include "roomInteractionGarage.hpp"
#include "roomInteractionGalley.hpp"
#include "roomInteractionDogKennel.hpp"
#include "roomInteractionBasement.hpp"
#include "roomInteractionConferenceRoom.hpp"


/*Player class.  Player object keeps game status such as grit level, victory, death, etc.*/
#include "Player.hpp"

/*Room class all 15 files included.*/
#include "Rooms/Basement.hpp"
#include "Rooms/ConferenceRoom.hpp"
#include "Rooms/DogKennel.hpp"
#include "Rooms/EquipmentRoom.hpp"
#include "Rooms/Galley.hpp"
#include "Rooms/Garage.hpp"
#include "Rooms/Hallway1.hpp"
#include "Rooms/Hallway2.hpp"
#include "Rooms/Latrine.hpp"
#include "Rooms/Macready.hpp"
#include "Rooms/MessHall.hpp"
#include "Rooms/RadioRoom.hpp"
#include "Rooms/ResearchLab.hpp"
#include "Rooms/SickBay.hpp"
#include "Rooms/ToolShed.hpp"

/*Parser class*/
#include "Verbs/Attack.hpp"
#include "Verbs/Break.hpp"
#include "Verbs/Drink.hpp"
#include "Verbs/Drop.hpp"
#include "Verbs/Eat.hpp"
#include "Verbs/Flee.hpp"
#include "Verbs/Go.hpp"
#include "Verbs/Help.hpp"
#include "Verbs/Inventory.hpp"
#include "Verbs/Jump.hpp"
#include "Verbs/Look.hpp"
#include "Verbs/LookAt.hpp"
#include "Verbs/Smell.hpp"
#include "Verbs/Take.hpp"
#include "Verbs/Talk.hpp"
#include "Verbs/Use.hpp"
#include "Verbs/VerbEnum.hpp"
#include "Verbs/Verb.hpp"
#include "Verbs/Parser.hpp"

#include "SaveLoad.hpp"

void drink(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList, int roomNumber);
