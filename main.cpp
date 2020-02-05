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
#include "help.hpp"
#include "gameEnd.hpp"

/*action functions after parser translation*/
/*
 *  *  * #include "lookAtAction.hpp"
 *   *   * #include "look.hpp"
 *    *    * #include "useAction.hpp"
 *     *     * #include "dropAction.hpp"
 *      *      * #include "goAction.hpp"
 *       *       * */



/*Player class.  Player object keeps game status such as grit level, victory, death, etc.*/
#include "Player.hpp"

/*Room class*/
#include "Basement.hpp"
#include "ConferenceRoom.hpp"
#include "DogKennel.hpp"
#include "EquipmentRoom.hpp"
#include "Galley.hpp"
#include "Garage.hpp"
#include "Hallway1.hpp"
#include "Hallway2.hpp"
#include "Latrine.hpp"
#include "Macready.hpp"
#include "MessHall.hpp"
#include "RadioRoom.hpp"
#include "ResearchLab.hpp"
#include "SickBay.hpp"
#include "ToolShed.hpp"

/*Parser class*/
#include "Attack.hpp"
#include "Drink.hpp"
#include "Drop.hpp"
#include "Eat.hpp"
#include "Parser.hpp"
#include "SimilarVerbHelper.hpp"
#include "Smell.hpp"
#include "Talk.hpp"
#include "VerbEnum.hpp"
#include "Verb.hpp"



/*REFACTOR FUNCTION LATER*/

/*discard this function.  only a test*/
void joelsbadParser(std::string userInput, std::string (&commands) [3])
{
	if (userInput == "eat the redherring")
	{
		commands[0] = "eat";
		commands[1] = "the";
		commands[2] = "redherring";
	}

	if (userInput == "drink the vodka")
	{
		commands[0] = "drink";
		commands[1] = "the";
		commands[2] = "vodka";
	}

	if (userInput == "drink the beer")
	{
		commands[0] = "drink";
		commands[1] = "the";
		commands[2] = "beer";
	}

	if (userInput == "drink the gin")
	{
		commands[0] = "drink";
		commands[1] = "the";
		commands[2] = "gin";
	}

	if (userInput == "drink the whiskey")
	{
		commands[0] = "drink";
		commands[1] = "the";
		commands[2] = "whiskey";
	}

	if (userInput == "drink the pabst")
	{
		commands[0] = "drink";
		commands[1] = "the";
		commands[2] = "pabst";
	}

	if (userInput == "drink the matarata")
	{
		commands[0] = "drink";
		commands[1] = "the";
		commands[2] = "matarata";
	}

	if (userInput == "drink the tequila")
	{
		commands[0] = "drink";
		commands[1] = "the";
		commands[2] = "tequila";
	}

	if (userInput == "take the mask")
	{
		commands[0] = "take";
		commands[1] = "the";
		commands[2] = "mask";
	}
	
	if (userInput == "drop vodka")
	{
		commands[0] = "drop";
		commands[1] = "vodkaTest";
		commands[2] = "vodkaTest";
	}

	if (userInput == "look at room")
	{
		commands[0] = "look";
		commands[1] = "at";
		commands[2] = "room";
	}
	if (userInput=="look for booze")
	{
		commands[0] = "look";
		commands[1] = "for";
		commands[2] = "booze";
	}

	if (userInput == "look at bed")
	{
		commands[0] = "look";
		commands[1] = "at";
		commands[2] = "bed";
	}

	if (userInput=="look at computer")
	{
		commands[0] = "look";
		commands[1] = "at";
		commands[2] = "computer";
	}

	if (userInput == "use the computer")
	{
		commands[0] = "use";
		commands[1] = "the";
		commands[2] = "computer";
	}

	if (userInput=="go to hallway1")
	{
		commands[0] = "go";
		commands[1] = "to";
		commands[2] = "hallway1";
	}
}

/*Uncertain of how to send the Item object to the room function.*/
void take(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList, int roomNumber)
{
	std::string itemToTake = commands[2];
	int inventoryIndex = playerLocation->findItemIndex(itemToTake);
	/*playerLocation->removeItem( , playerPtr);*/
}

void eat(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList, int roomNumber)
{
	std::string food = commands[2];
	/*bool check = playerPtr->checkInventory(food);*/
	if (playerPtr->checkInventory(food) == 1)
	{
		Item redherring("redherring");
		playerPtr->setGrit("redherring");
	}
	else
		std::cout << "Sorry.  You can't eat what you don't have in your inventory." << std::endl;
}

void drink(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList, int roomNumber)
{
	std::string beverage = commands[2];
	/*bool check = playerPtr->checkInventory(food);*/
	if (playerPtr->checkInventory(beverage) == 1)
	{
		playerPtr->setGrit(beverage);
	}
	else
		std::cout << "Sorry.  You can't drink what you don't have in your inventory." << std::endl;
}


/*Function called from roomInteraction function if drop command is sent.*/
void drop(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList, int roomNumber)
{
	std::string itemToCheck = commands[2];

	if (playerPtr->checkInventory(itemToCheck) == 1)
	{
		Item itemToDrop = playerPtr->transferItem(itemToCheck);
		Item* itemToDropPtr = &itemToDrop;
		int number = playerPtr->getIndex(itemToCheck);
		playerLocation->addItem(itemToDrop, playerPtr, number);
		playerPtr->deletePlayerItem(itemToCheck);
	}
}

/*go function.  helper function for roomInteraction functions.  Takes playerLocation pointer, vector of room pointers, and an int for the roomNumber.*/
/*rooms will be listed 0-14.*/
void go(Room* &playerLocation, std::vector<Room*> &roomList, int roomNumber)
{
	playerLocation = roomList[roomNumber];
	std::string roomName = playerLocation->getName();
	std::cout << "You go to " << roomName << std::endl;
}

/*Function to interact with macready room*/
/*Based on commands within array, conditions are set up to control interactions with room.*/
/*If a condition is met a room function is called for more interaction.  return is then used to get back to the main function.*/
/*If no conditions are met, it moves to the bottom of the function and a message is printed that whatever the user typed cannot be done.*/
void roomInteractionMacready(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList)
{
	std::cout << "IN roomInteractionMacready FUNCTION: " << std::endl;
	
	if (commands[0] == "drink")
	{
		drink(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "eat")
	{
		eat(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "take")
	{
		take(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "drop")
	{
		drop(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}
	/*Macready room*/
	if (commands[0] == "look" && commands[1] == "at" && commands[2] == "room")
	{
		std::cout << "CHECKING getLongDescrip() " << std::endl;
		std::string longDescription = playerLocation->getLongDescrip();
		std::cout << longDescription << std::endl;
		return;
	}

	if (commands[0] == "look" && commands[1] == "for" && commands[2] == "booze")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "You already checked under the bed and the room.  No booze.  Drat!" << std::endl;
			return;
		}

		if (playerLocation->getFeatureOneHap() == 0)
		{
			playerLocation->featureOne(playerPtr);
			return;
		}
	}

	if (commands[0] == "look" && commands[1] == "at" && commands[2] == "bed")
	{
		std::cout << "The bed has not been made.  MacReady's quarters are a pig sty." << std::endl;
		return;
	}

	if (commands[0] == "look" && commands[1] == "at" && commands[2] == "computer")
	{
		std::cout << "It's a state of the art Commodore 64." << std::endl;
		std::cout << "The CPU is 1.023 MHz!" << std::endl;
		std::cout << "The memory is 64 KB of RAM!" << std::endl;
		std::cout << "This must have set MacReady back by $519.00" << std::endl;
		std::cout << "He is quite the spender." << std::endl;
		return;
	}

	if (commands[0] == "use" && commands[1] == "the" && commands[2]=="computer")
	{
		if (playerLocation->getFeatureTwoHap()==1)
		{
			std::cout << "You already played with the computer." << std::endl;
			return;
		}

		if (playerLocation->getFeatureTwoHap() == 0)
		{
			playerLocation->featureTwo(playerPtr);
			return;
		}
	}

	/*calls helper go function with playerLocation pointer, list of rooms and room number to go to.*/
	if (commands[0] == "go" && commands[1] == "to" && commands[2]=="hallway1")
	{
		go(playerLocation, roomList, 1);
		return;
	}

	{
		std::cout << "You can't do that here." << std::endl;
	}
}

int main()
{
srand(time(NULL));
intro();
/*menu(); */
map();
help();


	/*Creation of Objects*/
	Player rj;
	Macready macready;
	Hallway1 hallway1;
	SickBay sickbay;
	Latrine latrine;
	Galley galley;



	/*Note to self: need to call setRoom function to fill data members before calling functions*/
	/*Alternative to using new command and perhaps preventing memory leaks*/

/*Each room gets its own pointer to call setRoom function and then be pushed into roomList vector.*/
/*The roomList vector will be sent to roomInteraction function*/
/****************************************************************************/
Room* macreadyRoomPtr = &macready;
macreadyRoomPtr->setRoom();

Room* hallway1Ptr = &hallway1;
hallway1Ptr->setRoom();

Room* sickbayPtr = &sickbay;
sickbayPtr->setRoom();

Room* latrinePtr = &latrine;
latrinePtr->setRoom();

Room* galleyPtr = &galley;
galleyPtr->setRoom();

/****************************************************************************/
Room* playerLocation = &macready;
Player* playerPtr = &rj;

	

std::vector<Room*> roomList;
roomList.push_back(macreadyRoomPtr);
roomList.push_back(hallway1Ptr);
roomList.push_back(sickbayPtr);
roomList.push_back(latrinePtr);
roomList.push_back(galleyPtr);


std::string commands[3];
std::string userInput = "";

/**********************************************/
/*Test to add inventory to player object*/
Item alcohol("vodkaTest");
Item* alcoholPtr = &alcohol;
alcoholPtr->setUse();
playerPtr->setInventory(alcohol);

Item mask("mask");
Item* maskPtr = &mask;

macreadyRoomPtr->addItem(mask, playerPtr, 0);

Item vodka("vodka");
Item whiskey("whiskey");
Item tequila("tequila");
Item beer("beer");
Item matarata("matarata");
Item pabst("pabst");
Item gin("gin");
Item redHerring("redherring");

playerPtr->setInventory(vodka);
playerPtr->setInventory(whiskey);
playerPtr->setInventory(tequila);
playerPtr->setInventory(beer);
playerPtr->setInventory(matarata);
playerPtr->setInventory(pabst);
playerPtr->setInventory(gin);
playerPtr->setInventory(redHerring);











/*********************************************/

/*Loop starts*/
do {
/*Checks victory status at start of loop.*/
if (rj.getVictory() != 0)
{
gameEnd(rj);
}

userInput = "";

playerLocation->displayDescrip();
playerLocation->displayExits();

std::cout << "What do you want to do?" << std::endl;
/*Discards anything left in the input buffer. Source: https://www.geeksforgeeks.org/clearing-the-input-buffer-in-cc/ */
getline(std::cin, userInput);

/*userInput will be sent to parser along with a 3 slot array for strings.  the parser will process string into array slots.*/
joelsbadParser(userInput, commands);

/*Might refactor the code into separate function files.*/
/*If current player location is the macready room, then roomInteractionMacready will be called.*/
if (playerLocation->getName() == "macready")
{
	roomInteractionMacready(commands, playerLocation, playerPtr, roomList);
}

if (playerLocation->getName() == "hallway1")
{
	/*chooseActionMacready(commands, playerLocation, rj, hallway1);*/
	std::cout << "Hallway function not ready." << std::endl;
}




}while(userInput != "exit");

}




