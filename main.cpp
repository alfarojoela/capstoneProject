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

int main()
{
srand(time(NULL));
intro();
/*menu(); */
/*map();*/
/*help();*/


	/*Creation of Objects*/
	Player rj;
	Macready macready;
	Hallway1 hallway1;
	Latrine latrine;
	EquipmentRoom equipmentroom;
	ToolShed toolshed;
	SickBay sickbay;
	RadioRoom radioroom;
	ResearchLab researchlab;
	MessHall messhall;
	Hallway2 hallway2;
	Garage garage;
	Galley galley;
	DogKennel dogkennel;
	Basement basement;
	ConferenceRoom conferenceroom;

	SaveLoad gameSave;
	SaveLoad* gameSavePtr = &gameSave;


	/*Note to self: need to call setRoom function to fill data members before calling functions*/
	/*Alternative to using new command and perhaps preventing memory leaks*/

/*Each room gets its own pointer to call setRoom function and then be pushed into roomList vector.*/
/*The roomList vector will be sent to roomInteraction function*/
/****************************************************************************/
Room* macreadyRoomPtr = &macready;
macreadyRoomPtr->setRoom();

Room* hallway1Ptr = &hallway1;
hallway1Ptr->setRoom();

Room* latrinePtr = &latrine;
latrinePtr->setRoom();

Room* equipmentroomPtr = &equipmentroom;
equipmentroomPtr->setRoom();

Room* toolshedPtr = &toolshed;
toolshedPtr->setRoom();

Room* sickbayPtr = &sickbay;
sickbayPtr->setRoom();

Room* radioroomPtr = &radioroom;
radioroomPtr->setRoom();

Room* researchlabPtr = &researchlab;
researchlabPtr->setRoom();

Room* messhallPtr = &messhall;
messhallPtr->setRoom();

Room* hallway2Ptr = &hallway2;
hallway2Ptr->setRoom();

Room* garagePtr = &garage;
garagePtr->setRoom();

Room* galleyPtr = &galley;
galleyPtr->setRoom();

Room* dogkennelPtr = &dogkennel;
dogkennelPtr->setRoom();

Room* basementPtr = &basement;
basementPtr->setRoom();

Room* conferenceroomPtr = &conferenceroom;
conferenceroomPtr->setRoom();

/****************************************************************************/
Room* playerLocation = &macready;
Player* playerPtr = &rj;

std::vector<Room*> roomList;
/*macready=0, hallway1=1, latrine=2, equipmentroom=3, toolshed=4, sickbay=5, radioroom=6, researchlab = 7*/
/*messhall = 8, hallway2=9, garage =10, galley=11, dogkennel=12, basement=13, conferenceroom = 14*/
roomList.push_back(macreadyRoomPtr);
roomList.push_back(hallway1Ptr);
roomList.push_back(latrinePtr);
roomList.push_back(equipmentroomPtr);
roomList.push_back(toolshedPtr);
roomList.push_back(sickbayPtr);
roomList.push_back(radioroomPtr);
roomList.push_back(researchlabPtr);
roomList.push_back(messhallPtr);
roomList.push_back(hallway2Ptr);
roomList.push_back(garagePtr);
roomList.push_back(galleyPtr);
roomList.push_back(dogkennelPtr);
roomList.push_back(basementPtr);
roomList.push_back(conferenceroomPtr);


std::string commands[3];
std::string userInput = "";

/**********************************************/
/*List of Items */
Item toiletPaper("toilet paper");
Item blowTorch("blowtorch");
Item scalpel("scalpel");
Item petri("petri dish");
Item gun("gun");
Item axe("axe");
Item gin("gin");
Item rope("rope");
Item whiskey("whiskey");
Item flamethrower("flamethrower");
Item redHerring("red herring");
Item copperWire("copper wire");

/*miscellaneous items to place*/
Item tequila("tequila");
Item beer("beer");
Item mataRata("matarata");
Item vodka("vodka");

galleyPtr-> addItem(redHerring);
hallway1Ptr->addItem(axe);
sickbayPtr->addItem(scalpel);
latrinePtr->addItem(toiletPaper);
equipmentroomPtr->addItem(blowTorch);
toolshedPtr->addItem(whiskey);
toolshedPtr->addItem(rope);
messhallPtr->addItem(gin);
dogkennelPtr->addItem(petri);
garagePtr->addItem(flamethrower);
radioroomPtr->addItem(copperWire);
basementPtr->addItem(gun);

latrinePtr->addItem(beer);
garagePtr->addItem(mataRata);




/*********************************************/
/*Loop starts*/
do {
/*Checks victory status at start of loop.*/
if (rj.getVictory() != 0)
{
gameEnd(rj);
}

if(playerPtr->getBearings() == 1)
{
playerLocation->displayDescrip();
playerLocation->displayExits();
playerPtr->setBearings(0);
}
userInput = "";
playerPtr->gritWarning();

std::cout << "________________________________________________________________________________________________________" << std::endl;
std::cout << "What do you want to do?" << std::endl;
/*Discards anything left in the input buffer. Source: https://www.geeksforgeeks.org/clearing-the-input-buffer-in-cc/ */
getline(std::cin, userInput);
std::cout << "________________________________________________________________________________________________________" << std::endl;

/*userInput will be sent to parser along with a 3 slot array for strings.  the parser will process string into array slots.*/

/*commented out.  using pointer to parser in this iteration.*/
/*Parser::parseInput(userInput, commands);*/

Parser parser;
Parser* parserPtr = &parser;

parserPtr->parseInput(userInput, commands);

if (commands[0] == "savegame")
{
	std::string currentLocationName = playerLocation->getName();
	gameSavePtr->save(playerPtr, roomList, currentLocationName);
}

if (commands[0] == "loadgame")
{
	playerLocation = gameSavePtr->load(playerPtr, roomList);
}


if (userInput == "exit")
{
	std::cout << "Ending game." << std::endl;
	parserPtr->freeStaticActions();
	return(0);
}



roomRouter(commands, playerLocation, playerPtr, roomList, parserPtr);

/*playerLocation->displayExits();*/
if (playerPtr->getAlive() == 0)
{
	userInput = "exit";
	parserPtr->freeStaticActions();
	return(0);
}


}while(userInput != "exit");

}
