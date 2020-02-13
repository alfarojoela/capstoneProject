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
 *  *  *  *  * #include "lookAtAction.hpp"
 *   *   *   *   * #include "look.hpp"
 *    *    *    *    * #include "useAction.hpp"
 *     *     *     *     * #include "dropAction.hpp"
 *      *      *      *      * #include "goAction.hpp"
 *       *       *       *       * */



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

/*Prototypes*/
void roomRouter(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList);

void roomInteractionHallway1(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList);
void roomInteractionMacready(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList);
void roomInteractionLatrine(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList);
void roomInteractionSickBay(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList);


/*REFACTOR FUNCTION LATER*/

/*discard this function.  only a test*/
void parserPrototype(std::string userInput, std::string(&commands)[3])
{

	if (userInput == "go to sickbay")
	{
	commands[0] = "go";
	commands[1] = "to";
	commands[2] = "sickbay";
	}
	if (userInput == "go to macready")
	{
		commands[0] = "go";
		commands[1] = "to";
		commands[2] = "macready";
	}

	if (userInput == "use the toilet")
	{
		commands[0] = "use";
		commands[1] = "the";
		commands[2] = "toilet";
	}
	if (userInput == "take the toilet paper")
	{
		commands[0] == "take";
		commands[1] == "the";
		commands[2] == "toilet paper";
	}

	if (userInput == "take the vodka")
	{
		commands[0] = "take";
		commands[1] = "the";
		commands[2] = "vodka";
	}

	if (userInput == "take the whiskey")
	{
		commands[0] = "take";
		commands[1] = "the";
		commands[2] = "whiskey";
	}

	if (userInput == "take the tequila")
	{
		commands[0] = "take";
		commands[1] = "the";
		commands[2] = "tequila";
	}


	if (userInput == "room inventory")
	{
		commands[0] = "room";
		commands[1] = "";
		commands[2] = "inventory";
	}

	if (userInput == "inventory")
	{
		commands[0] = "inventory";
		commands[1] = "inventory";
		commands[2] = "inventory";
	}

	if (userInput == "map")
	{
		commands[0] = "map";
		commands[1] = "map";
		commands[2] = "map";
	}
	if (userInput == "help")
	{
		commands[0] = "help";
		commands[1] = "help";
		commands[2] = "help";
	}
	if (userInput == "look at wall")
	{
		commands[0] = "look";
		commands[1] = "at";
		commands[2] = "wall";
	}

	if (userInput == "look at lights")
	{
		commands[0] = "look";
		commands[1] = "at";
		commands[2] = "lights";
	}

	if (userInput == "use the lights")
	{
		commands[0] = "use";
		commands[1] = "the";
		commands[2] = "lights";
	}


	if (userInput == "smell the room")
	{
		commands[0] = "smell";
		commands[1] = "the";
		commands[2] = "room";
	}
	
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
		commands[1] = "the";
		commands[2] = "vodka";
	}

	if (userInput == "drop whiskey")
	{
		commands[0] = "drop";
		commands[1] = "the";
		commands[2] = "whiskey";
	}

	if (userInput == "drop tequila")
	{
		commands[0] = "drop";
		commands[1] = "the";
		commands[2] = "tequila";
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

	if (userInput == "go to latrine")
	{
		commands[0] = "go";
		commands[1] = "to";
		commands[2] = "latrine";
	}

	if (userInput == "look at toilet paper")
	{
		commands[0] = "look";
		commands[1] = "at";
		commands[2] = "toilet paper";
	}

	if (userInput == "current room")
	{
		commands[0] = "current";
		commands[1] = "room";
		commands[2] = "room";
	}

	if (userInput == "look at creature")
	{
		commands[0] = "look";
		commands[1] = "at";
		commands[2] = "creature";
	}

}

/*Gets a string out of the commands vector.  Sends the string to the room removeItem function with the player pointer.  Room function handles the transition of inventory to player inventory and then deletes the appropriate cell.*/
void take(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList, int roomNumber)
{
	std::string itemToTake = commands[2];
	if (playerLocation->checkItem(itemToTake) != 999)
	{
		std::cout << "'Yoinks!'you say.  Just like Shaggy from Scooby Doo.  You found the " << itemToTake << std::endl;
		std::cout << "You're taking it with you." << std::endl;
		playerLocation->removeItem(itemToTake, playerPtr);
		return;
	}

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
		playerLocation->addItem(itemToDrop);
		playerPtr->deletePlayerItem(itemToCheck);
		std::cout << "You dropped the " << itemToCheck << std::endl;
		std::cout << "Don't believe me?" << std::endl;
		std::cout << "Check your inventory." << std::endl;
		return;
	}
	else
		std::cout << "You can't drop what's not in your inventory. " << std::endl;


}

/*go function.  helper function for roomInteraction functions.  Takes playerLocation pointer, vector of room pointers, and an int for the roomNumber.*/
/*rooms will be listed 0-14.*/
void go(Room* &playerLocation, std::vector<Room*> &roomList, int roomNumber, Player* &playerPtr)
{
	playerLocation = roomList[roomNumber];
	std::string roomName = playerLocation->getName();
	std::cout << "You go to " << roomName << std::endl;
	std::cout << "CURRENT LOCATION: " << playerLocation->getName() << std::endl;
	playerPtr->setBearings(1);
}

/*Based on conditions, calls appropriate roomInteractionFunction.*/
void roomRouter(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList)
{
	/*Plan is to refactor the code into separate function files for routing which interaction is called.*/
	/*If current player location is the macready room, then roomInteractionMacready will be called.*/
	if (playerLocation->getName() == "macready")
	{
		roomInteractionMacready(commands, playerLocation, playerPtr, roomList);
		return;
	}

	if (playerLocation->getName() == "hallway1")
	{
		roomInteractionHallway1(commands, playerLocation, playerPtr, roomList);
		return;
	}

	if (playerLocation->getName() == "latrine")
	{
		roomInteractionLatrine(commands, playerLocation, playerPtr, roomList);
		return;
	}

	if (playerLocation->getName() == "sickBay")
	{
		roomInteractionSickBay(commands, playerLocation, playerPtr, roomList);
		return;
	}

}
/*Function to interact with macready room*/
/*Based on commands within array, conditions are set up to control interactions with room.*/
/*If a condition is met a room function is called for more interaction.  return is then used to get back to the main function.*/
/*If no conditions are met, it moves to the bottom of the function and a message is printed that whatever the user typed cannot be done.*/
void roomInteractionMacready(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList)
{

	/*Set of commands to check room inventory.  Mainly for testing purposes rather than for the player.  May keep condition to allow player a cheat.  Won't put in help list.*/
	if (commands[0] == "room" && commands[2] == "inventory")
	{
		std::cout << "Room Inventory:" << std::endl;
		playerLocation->itemsInRoom();
		return;
	}

	if (commands[0] == "current" && commands[2] == "room")
	{
		std::cout << "CURRENT ROOM: " << playerLocation->getName() << std::endl;
		return;
	}

	if (commands[0] == "take")
	{
		take(commands, playerLocation, playerPtr, roomList, 0);
	}


	if (commands[0] == "help")
	{
		help();
		return;
	}

	if (commands[0] == "inventory")
	{
		playerPtr->getInventory();
		return;
	}

	if (commands[0] == "map")
	{
		map();
		return;
	}

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
		go(playerLocation, roomList, 1, playerPtr);
		return;
	}

	
		std::cout << "You can't do that here." << std::endl;
	
}



void roomInteractionHallway1(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList)
{
	if (commands[0] == "room" && commands[2] == "inventory")
	{
		std::cout << "Room Inventory:" << std::endl;
		playerLocation->itemsInRoom();
		return;
	}

	if (commands[0] == "help")
	{
		help();
		return;
	}

	if (commands[0] == "map")
	{
		map();
		return;
	}

	if (commands[0] == "inventory")
	{
		playerPtr->getInventory();
		return;
	}


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
	
	/*Hallway1 room*/
	if (commands[0] == "look" && commands[1] == "at" && commands[2] == "room")
	{
		std::cout << "CHECKING getLongDescrip() " << std::endl;
		std::string longDescription = playerLocation->getLongDescrip();
		std::cout << longDescription << std::endl;
		return;
	}

	if (commands[0] == "smell" && commands[1] == "the" && commands[2] == "room")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "'What happened here?' You wonder aloud." << std::endl;
			return;
		}

		if (playerLocation->getFeatureOneHap() == 0)
		{
			std::cout << "The hallway smells of copper.  You now realize you have been smelling fresh spilt blood.  You now see that the hallway is charged with a desperate violence..." << std::endl;
			playerLocation->featureOne(playerPtr);
			return;
		}
	}

	if (commands[0] == "look" && commands[1] == "at" && commands[2] == "wall")
	{
		std::cout << "You feel sick.  The smell is stifling..." << std::endl;
		return;
	}

	if (commands[0] == "use" && commands[1] == "the" && commands[2] == "lights")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "The lights continue to flicker on and off..." << std::endl;
			return;
		}

		if (playerLocation->getFeatureTwoHap() == 0)
		{
			playerLocation->featureTwo(playerPtr);
			std::cout << "Whatever ran past you has freaked you out.  You loose some of your resolve." << std::endl;
			playerPtr->decrementGrit();

			return;
		}
	}



	/*calls helper go function with playerLocation pointer, list of rooms and room number to go to.*/
	if (commands[0] == "go" && commands[1] == "to" && commands[2] == "macready")
	{
		go(playerLocation, roomList, 0, playerPtr);
		return;
	}

	if (commands[0] == "go" && commands[1] == "to" && commands[2] == "latrine")
	{
		go(playerLocation, roomList, 2, playerPtr);
		return;
	}

	if (commands[0] == "go" && commands[1] == "to" && commands[2] == "sickbay")
	{
		go(playerLocation, roomList, 5, playerPtr);
		return;
	}

		std::cout << "You can't do that here." << std::endl;
		return;
	
}

/*Rewrite this function here.*/
void roomInteractionSickBay(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList)
{
	if (commands[0] == "room" && commands[2] == "inventory")
	{
		std::cout << "Room Inventory:" << std::endl;
		playerLocation->itemsInRoom();
		return;
	}

	if (commands[0] == "help")
	{
		help();
		return;
	}

	if (commands[0] == "map")
	{
		map();
		return;
	}

	if (commands[0] == "inventory")
	{
		playerPtr->getInventory();
		return;
	}


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

	/*Hallway1 room*/
	if (commands[0] == "look" && commands[1] == "at" && commands[2] == "room")
	{
		std::cout << "CHECKING getLongDescrip() " << std::endl;
		std::string longDescription = playerLocation->getLongDescrip();
		std::cout << longDescription << std::endl;
		return;
	}

	if (commands[0] == "smell" && commands[1] == "the" && commands[2] == "room")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "'What happened here?' You wonder aloud." << std::endl;
			return;
		}

		if (playerLocation->getFeatureOneHap() == 0)
		{
			std::cout << "The hallway smells of copper.  You now realize you have been smelling fresh spilt blood.  You now see that the hallway is charged with a desperate violence..." << std::endl;
			playerLocation->featureOne(playerPtr);
			return;
		}
	}



	if (commands[0] == "talk" && commands[1] == "to" && commands[2] == "crew member")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "Jack is slumped over in the bed.  You are too cautious to get close to him and give him another chance to attack you.  He doesn't respond any further to any of your calls." << std::endl;
			return;
		}

		if (playerLocation->getFeatureTwoHap() == 0)
		{
			playerLocation->featureTwo(playerPtr);
			return;
		}
	}



	/*calls helper go function with playerLocation pointer, list of rooms and room number to go to.*/
	if (commands[0] == "go" && commands[1] == "to" && commands[2] == "macready")
	{
		go(playerLocation, roomList, 0, playerPtr);
		return;
	}
	if (commands[0] == "go" && commands[1] == "to" && commands[2] == "latrine")
	{
		go(playerLocation, roomList, 2, playerPtr);
		return;
	}


	std::cout << "You can't do that here." << std::endl;
	return;
}

void roomInteractionLatrine(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList)
{

	/*Set of commands to check room inventory.  Mainly for testing purposes rather than for the player.  May keep condition to allow player a cheat.  Won't put in help list.*/
	if (commands[0] == "room" && commands[2] == "inventory")
	{
		std::cout << "Room Inventory:" << std::endl;
		playerLocation->itemsInRoom();
		return;
	}

	if (commands[0] == "take")
	{
		take(commands, playerLocation, playerPtr, roomList, 0);
	}


	if (commands[0] == "help")
	{
		help();
		return;
	}

	if (commands[0] == "inventory")
	{
		playerPtr->getInventory();
		return;
	}

	if (commands[0] == "map")
	{
		map();
		return;
	}

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

	if (commands[0] == "take" && commands[2] == "vodka")
	{
		take(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "take" && commands[2] == "whiskey")
	{
		take(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "take" && commands[2] == "tequila")
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
			std::cout << "You lift the lid off the toilet tank of the toilet that is out of order." << std::endl;
			std::cout << "Success!  You found half a bottle of vodka chilling in the toilet tank." << std::endl;
			std::cout << "This could come in handy.  It could give you a bit of liquid courage to help you face whatever terrors are running loose." << std::endl;
			std::cout << "You can choose to take the vodka or just leave it where you found it." <<std::endl;			
		return;

	}

	if (commands[0] == "look" && commands[1] == "at" && commands[2] == "toilet paper")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "You already did that." << std::endl;
			return;
		}

		if (playerLocation->getFeatureOneHap() == 0)
		{
			playerLocation->featureOne(playerPtr);
			return;
		}
	}

	if (commands[0] == "use" && commands[1] == "the" && commands[2] == "toilet")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "Are you sure you want to try that again?  Remember what happened last time you did that?" << std::endl;
			return;
		}

		if (playerLocation->getFeatureTwoHap() == 0)
		{
			playerLocation->featureTwo(playerPtr);
			return;
		}
	}

	if (commands[0] == "look" && commands[1] == "at" && commands[2] == "creature" && playerLocation->getFeatureTwoHap() == 1)
	{
		std::cout << "You have never seen anything like this creature before.  You suspect it is not of this Earth." << std::endl;
		std::cout << "Is this what caused all the carnage in the Hallway?" << std::endl;
		return;
	}

	/*calls helper go function with playerLocation pointer, list of rooms and room number to go to.*/
	if (commands[0] == "go" && commands[1] == "to" && commands[2] == "hallway1")
	{
		std::cout << "BACK TO HALLWAY1..." << std::endl;
		go(playerLocation, roomList, 1, playerPtr);
		return;
	}


	std::cout << "You can't do that here." << std::endl;
	return;

}

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


	Galley galley;


	Item vodka("vodka");

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
latrinePtr->addItem(vodka);

Room* equipmentroomPtr = &equipmentroom;
equipmentroomPtr->setRoom();

Room* toolshedPtr = &toolshed;
toolshedPtr -> setRoom();

Room* radioroomPtr = &radioroom;
radioroomPtr->setRoom();

Room* researchlabPtr = &researchlab;
researchlabPtr->setRoom();








Room* galleyPtr = &galley;
galleyPtr->setRoom();

/****************************************************************************/
Room* playerLocation = &macready;
Player* playerPtr = &rj;

	

std::vector<Room*> roomList;
/*macready=0, hallway1=1, latrine=2, equipmentroom=3, toolshed=4, sickbay=5, radioroom=6, researchlab = 7*/
roomList.push_back(macreadyRoomPtr);
roomList.push_back(hallway1Ptr);
roomList.push_back(latrinePtr);
roomList.push_back(equipmentroomPtr);
roomList.push_back(toolshedPtr);
roomList.push_back(sickbayPtr);
roomList.push_back(radioroomPtr);
roomList.push_back(researchlabPtr);


std::string commands[3];
std::string userInput = "";

/**********************************************/
/*Test to add inventory to player object*/

Item whiskey("whiskey");
Item tequila("tequila");
Item redHerring("redherring");

playerPtr->setInventory(vodka);
playerPtr->setInventory(whiskey);
playerPtr->setInventory(tequila);
playerPtr->setInventory(redHerring);

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

/*parserPrototype(userInput, commands);*/
Parser::parseInput(userInput, commands);

roomRouter(commands, playerLocation, playerPtr, roomList);

/*playerLocation->displayExits();*/

}while(userInput != "exit");

}







