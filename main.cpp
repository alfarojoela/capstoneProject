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
void roomRouter(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList, Parser* parserPtr);
void lookAt(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector<Room*> &roomList, int roomNumber);

void roomInteractionHallway1(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList, Parser* parserPtr);
void roomInteractionMacready(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList, Parser* parserPtr);
void roomInteractionLatrine(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList, Parser* parserPtr);
void roomInteractionEquipmentRoom(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList, Parser* parserPtr);
void roomInteractionToolShed(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList, Parser* parserPtr);


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

	if(playerLocation->checkItem(itemToTake) ==999 && playerLocation->getName() == "macready")
	{
		std::cout <<"You can't take that." << std::endl;
		std::cout << "Besides, it's not a good idea trying to take Macready's stuff without asking.  You're liable to get on his wrongside.  And you don't wanna be on his wrongside." << std::endl;
		return;
	}

	if (playerLocation->checkItem(itemToTake) == 999)
	{
		std::cout << "You can't take that." << std::endl;
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

/*lookAt function.  Allows player to look at items in player inventory or room inventory*/
/*Does a check of both inventories to see if item is in inventory.  if it is, matches condition to print out a description.*/
void lookAt(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector<Room*> &roomList, int roomNumber)
{
	std::string item = commands[2];
	if (playerPtr->checkInventory(item) == 1 || playerLocation->checkItem(item) !=999)
	{
		if (item == "blowtorch")
		{
			std::cout << "The blow torch can be used for applying flame to things.  It is almost full." << std::endl;
			return;
		}

		if (item == "petri dish")
		{
			std::cout << "It's a plastic dish with a lid." << std::endl;
			std::cout << "You could use it to collect specimens like blood for instance." << std::endl;
			return;
		}

		if (item == "copper wire")
		{
			std::cout << "You have a small spool of copper wire." << std::endl;
			std::cout << "It looks like you could apply flame to it.  And then you could use the wire to apply heat to things." << std::endl;
			return;
		}

		if (item == "blood sample")
		{
			std::cout << "You hold the blood sample up to the light." << std::endl;
			std::cout << "It looks like ordinary human blood, but is it?" << std::endl;
			std::cout << "Maybe there is some kind of test." << std::endl;
			return;
		}

		if (item == "flamethrower")
		{
			std::cout << "You wouldn't want to be on the wrong side of this thing.  It's nearly full.  It has a range of 110 feet." << std::endl;
			std::cout << "It is in fine operating condition." << std::endl;
			return;
		}

		if (item == "gun")
		{
			std::cout << "You aren't quite sure why a gun would be needed at this facility." << std::endl;
			std::cout << "Maybe some people on the team use it to shoot penguins?" << std::endl;
			std::cout << "Whatever reason it's here, you feel a little bit safer with it." << std::endl;
			return;
		}

		if (item == "rope")
		{
			std::cout << "The rope is quite strong and should be able to take a lot of stress." << std::endl;
			return;
		}

		if (item == "scalpel")
		{
			std::cout << "The scalpel's handle fits within your hand.  The bladed end gleams in the light." << std::endl;
			std::cout << "This definitely can be used to cut." << std::endl;
			return;
		}

		if (item == "toilet paper")
		{
			std::cout << "You have the code that someone wrote on the toilet paper: 5932." << std::endl;
			return;
		}

		if (item == "redherring")
		{
			std::cout << "It is a dented can of red herring.  It looks like it should be edible." << std::endl;
			return;
		}

		if (item == "axe")
		{
			std::cout << "It is a fireaxe in case of emergencies.  It looks sturdy enough to break through doors, barriers, and debris if necessary." << std::endl;
			return;
		}

		if (item == "statue")
		{
			std::cout << "It's a minature of Auguste Rodin's 'The Thinker.' " << std::endl;
			return;
		}

		if (item == "vodka")
		{
			std::cout << "Someone got to this bottle before you did.  There are a few swigs left.  Looking at the clear contents, makes you feel a little thirsty." << std::endl;
			return;
		}

		if (item == "gin")
		{
			std::cout << "You shake the blue bottle.  There is maybe a single serving left of the gin." << std::endl;
			return;
		}

		if (item == "whiskey")
		{
			std::cout << "It's a single malt whiskey.  Aged to perfection in oak casks." << std::endl;
			return;
		}

		if (item == "tequila")
		{
			std::cout << "The tequila is in a strange bottle that resembles a skull.  It looks like a fancy brand.  The label assures smoothness with notes of fruit." <<std::endl;
			return;
		}

		if (item == "beer")
		{
			std::cout << "You inspect the bottle of beer.  The bottle is green so you expect a skunky one." << std::endl;
			return;
		}

		if (item == "pabst")
		{
			std::cout << "It's an aluminum can of beer.  The label reads, 'Pabst.'  Your stomach turns at the thought of swilling this down." << std::endl;
			return;
		}

		if (item == "matarata")
		{
			std::cout << "This homemade tequila's container is a plastic gallon jug that looks like it was previously used to keep either distilled water or milk in.  The jug is completely full." << std::endl;
			std::cout << "No one has bothered to touch this yet which makes it immediately suspect." << std::endl;
			return;
		}

		if (item == "red herring")
		{
			std::cout << "It is a dented can of red herring.  It looks like it should be edible." << std::endl;
			return;
		}
	}

	else
	{
		std::cout << "You can't examine that item.  The " << item << " is not in your inventory." << std::endl;
		return;
	}
}

void drink(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList, int roomNumber)
{
	std::string beverage = commands[2];
	/*bool check = playerPtr->checkInventory(food);*/
	if (playerPtr->checkInventory(beverage) == 1)
	{
		playerPtr->setGrit(beverage);
		return;
	}
	
		std::cout << "Sorry.  You can't drink what you don't have in your inventory." << std::endl;
		return;
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
void roomRouter(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList, Parser* parserPtr)
{
	/*Plan is to refactor the code into separate function files for routing which interaction is called.*/
	/*If current player location is the macready room, then roomInteractionMacready will be called.*/
	if (playerLocation->getName() == "macready")
	{
		roomInteractionMacready(commands, playerLocation, playerPtr, roomList, parserPtr);
		return;
	}

	if (playerLocation->getName() == "hallway1")
	{
		roomInteractionHallway1(commands, playerLocation, playerPtr, roomList, parserPtr);
		return;
	}

	if (playerLocation->getName() == "latrine")
	{
		roomInteractionLatrine(commands, playerLocation, playerPtr, roomList, parserPtr);
		return;
	}

	if (playerLocation->getName() == "equipment room")
	{
		roomInteractionEquipmentRoom(commands, playerLocation, playerPtr, roomList, parserPtr);
		return;
	}

	if (playerLocation->getName() == "tool shed")
	{
		roomInteractionToolShed(commands, playerLocation, playerPtr, roomList, parserPtr);
		return;
	}


}

/*Function to interact with macready room*/
/*Based on commands within array, conditions are set up to control interactions with room.*/
/*If a condition is met a room function is called for more interaction.  return is then used to get back to the main function.*/
/*If no conditions are met, it moves to the bottom of the function and a message is printed that whatever the user typed cannot be done.*/
void roomInteractionMacready(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList, Parser* parserPtr)
{

	/*Set of commands to check room inventory.  Mainly for testing purposes rather than for the player.  May keep condition to allow player a cheat.  Won't put in help list.*/
	if (commands[0] == "look" && commands[1] == "for" && commands[2] == "booze")
	{
		std::cout << "You start looking for booze and notice..." << std::endl;
		playerLocation->itemsInRoom();
		return;
	}

	if (commands[0] == "talk")
	{
		std::cout << "There is no one in Macready's quarters to talk to except yourself.  So you try to have a conversation, but it doesn't work out so well." << std::endl;
		std::cout << "Maybe you should leave the room to find someone to talk to." << std::endl;
		return;
	}

	if (commands[0] == "drink")
	{
		drink(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "smell" && commands[1] == "the" && commands[2] == "bed")
	{
		std::cout << "You take a deep whiff from the bed...It smells like a chimp sleeps here.  And you should know, as you have worked with chimps before." << std::endl;
		return;
	}

	if (commands[0] == "smell" && commands[1] == "the" && commands[2] == "computer")
	{
		std::cout << "It smells like a new computer.  The chimpesque odor of Macready's room has not had the opportunity to be absorbed by the computer yet." << std::endl;
		return;
	}

	if (commands[0] == "drop")
	{
		drop(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "attack")
	{
		std::cout << "The room is full of inanimate objects.  There's no one and nothing to attack." << std::endl;
		return;
	}

	if (commands[0] == "eat")
	{
		eat(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "use" && commands[1] == "the" && commands[2] == "computer")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
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

	if (commands[0] == "use" && commands[1] == "the" && commands[2] == "bed")
	{
		std::cout << "You consider taking a nap in Macready's bed.  But then reconsider.  You don't wanna smell like a chimp." << std::endl;
		return;
	}

	if (commands[0] == "jump" && commands[1] == "on" && commands[2] == "bed")
	{
		std::cout << "You climb onto Macready's bed and start jumping on it to test the springs.  You hear something snap and stop your jumping." << std::endl;
		std::cout << "You have the benefit of plausible deniability.  If he complains about a broken bed, you are just going to deny all knowledge." << std::endl;
		return;
	}

	if (commands[0] == "jump" && commands[1] == "on" && commands[2] == "computer")
	{
		std::cout << "The computer is not meant for jumping on.  You can't do that here." << std::endl;
		return;
	}

	if (commands[0] == "flee")
	{
		std::cout << "The room is full of inanimate objects.  There is nothing to flee from." << std::endl;
		return;
	}

	if (commands[0] == "break" && commands[1] == "the" && commands[2] == "computer")
	{
		std::cout << "You're jealous of Macready's outstanding computer and for a split second you consider breaking it out of spite." << std::endl;
		std::cout << "However, you come to your senses and decide not to break Macready's computer." << std::endl;
		return;
	}

	if (commands[0] == "break" && commands[1] == "the" && commands[2] == "bed")
	{
		std::cout << "You don't want to break Macready's bed.  That will get you on his wrongside." << std::endl;
		return;
	}

	if (commands[0] == "look" && commands[1] == "" && commands[2] == "")
	{
		std::string longDescription = playerLocation->getLongDescrip();
		std::cout << longDescription << std::endl;
		return;
	}

	if (commands[0] == "look" && commands[1] == "at" && commands[2] == "bed")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "You already checked under the bed and the room.  No booze.  Drat!" << std::endl;
			return;
		}

		if (playerLocation->getFeatureOneHap() == 0)
		{
			std::cout << "You look at Macready's bed.  It's not made.  You decide to take a look under the bed for some hidden booze." << std::endl;
			playerLocation->featureOne(playerPtr);
			return;
		}
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

	if (commands[0] == "look" && commands[1] == "at")
	{
		lookAt(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "current" && commands[2] == "room")
	{
		std::cout << "CURRENT ROOM: " << playerLocation->getName() << std::endl;
		return;
	}

	/*calls helper go function with playerLocation pointer, list of rooms and room number to go to.*/
	if (commands[0] == "go" && commands[1] == "to" && commands[2] == "hallway1")
	{
		go(playerLocation, roomList, 1, playerPtr);
		return;
	}

	if (commands[0] == "take")
	{
		take(commands, playerLocation, playerPtr, roomList, 0);
		return;
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

	if (commands[0] == "savegame")
	{
		std::cout << "Place holder for save" << std::endl;
		return;
	}

	if (commands[0] == "loadgame")
	{
		std::cout << "Place holder for load" << std::endl;
		return;
	}

		std::cout << "You can't do that here." << std::endl;
		return;
}

void roomInteractionHallway1(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList, Parser* parserPtr)
{

	/*Set of commands to check room inventory.  Mainly for testing purposes rather than for the player.  May keep condition to allow player a cheat.  Won't put in help list.*/
	if (commands[0] == "look" && commands[1] == "for" && commands[2] == "booze")
	{
		std::cout << "You start looking for booze and notice..." << std::endl;
		playerLocation->itemsInRoom();
		return;
	}

	if (commands[0] == "talk")
	{
		std::cout << "There is no one in the hallway to talk to except yourself.  So you try to have a conversation, but it doesn't work out so well." << std::endl;
		std::cout << "Maybe you could leave this room to find someone to talk to?" << std::endl;
		return;
	}

	if (commands[0] == "drink")
	{
		drink(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "smell" && commands[1] == "the" && commands[2] == "floor")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "'What happened here?'  You wonder aloud." << std::endl;
			return;
		}

		else
		{
			std::cout << "The hallway has a faint metallic smell to it.  You now realize you have been smelling fresh spilt blood.  You now see tha the hallway is charged with a desperate violence..." << std::endl;
			playerLocation->featureOne(playerPtr);
			return;
		}
	}

	if (commands[0] == "smell" && commands[1] == "the" && commands[2] == "lights")
	{
		std::cout << "You tilt your head up to point your nostrils up at the ceiling and away from the terrible smell.  Some of the flourescent lights burned out and are stinking up the place.  It reminds you of burnt marshmallows on a campfire." << std::endl;
		return;
	}

	if (commands[0] == "drop")
	{
		drop(commands, playerLocation, playerPtr, roomList, 1);
		return;
	}

	if (commands[0] == "attack")
	{
		std::cout << "There's no one and nothing to attack now." << std::endl;
		return;
	}

	if (commands[0] == "eat")
	{
		eat(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "use" && commands[1] == "the" && commands[2] == "lights")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "The lighst continue to flicker on and off..." << std::endl;
			return;
		}

		else
		{
			playerLocation->featureTwo(playerPtr);
			return;
		}
	}

	if (commands[0] == "use" && commands[1] == "the" && commands[2] == "floor")
	{
		std::cout << "You are already using the floor to stand on.  What other possible use could it be to you?" << std::endl;
		return;
	}

	if (commands[0] == "jump" && commands[1] == "on" && commands[2] == "floor")
	{
		std::cout << "You jump up and down on the floor.  It seems stable." << std::endl;
		return;
	}


	if (commands[0] == "jump" && commands[1] == "on" && commands[2] == "lights")
	{
		std::cout << "That just doesn't make any sense.  There is no way you can do that." << std::endl;
		return;
	}

	if (commands[0] == "flee")
	{
		std::cout << "There is nothing to flee from." << std::endl;
		return;
	}

	if (commands[0] == "break" && commands[1] == "the" && commands[2] == "floor")
	{
		std::cout << "The floor is linoleum glued to concrete.  There is no way you are going to be able to break it." << std::endl;
		return;
	}

	if (commands[0] == "break" && commands[1] == "the" && commands[2] == "lights")
	{
		std::cout << "That is a bad idea.  Breaking the lights is going to make this room completely dark.  You could trip over something and crack your head!" << std::endl;
		return;
	}

	if (commands[0] == "look" && commands[1] == "" && commands[2] == "")
	{
		std::string longDescription = playerLocation->getLongDescrip();
		std::cout << longDescription << std::endl;
		return;
	}

	if (commands[0] == "look" && commands[1] == "at" && commands[2] == "floor")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "You realize now that the trail of red streaks on the floor is blood." << std::endl;
			return;
		}

		else		
		{
			std::cout << "You take a closer look at the floor..." << std::endl;
			playerLocation->featureOne(playerPtr);
			return;
		}
	}

	if (commands[0] == "look" && commands[1] == "at" && commands[2] == "lights")
	{
		std::cout << "The lights flicker on and off.  Maybe you should use the lights." << std::endl;
		return;
	}

	if (commands[0] == "look" && commands[1] == "at")
	{
		lookAt(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "current" && commands[2] == "room")
	{
		std::cout << "CURRENT ROOM: " << playerLocation->getName() << std::endl;
		return;
	}

	/*calls helper go function with playerLocation pointer, list of rooms and room number to go to.*/
	
	if (commands[0] == "go" && commands[1] == "to" && commands[2] == "latrine")
	{
		go(playerLocation, roomList, 2, playerPtr);
		return;
	}
	
	if (commands[0] == "go" && commands[1] == "to" && commands[2] == "macready")
	{
		go(playerLocation, roomList, 0, playerPtr);
		return;
	}

	if (commands[0] == "go" && commands[1] == "to" && commands[2] == "equipment room")
	{
		go(playerLocation, roomList, 3, playerPtr);
		return;
	}

	if (commands[0] == "go" && commands[1] == "to" && commands[2] == "radio room")
	{
		go(playerLocation, roomList, 6, playerPtr);
		return;
	}

	if (commands[0] == "go" && commands[1] == "to" && commands[2] == "hallway2")
	{
		go(playerLocation, roomList, 9, playerPtr);
		return;
	}

	if (commands[0] == "go" && commands[1] == "to" && commands[2] == "research lab")
	{
		go(playerLocation, roomList, 7, playerPtr);
		return;
	}

	if (commands[0] == "go" && commands[1] == "to" && commands[2] == "sickbay")
	{
		go(playerLocation, roomList, 5, playerPtr);
		return;
	}

	if (commands[0] == "take")
	{
		take(commands, playerLocation, playerPtr, roomList, 0);
		return;
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

	if (commands[0] == "savegame")
	{
		std::cout << "Place holder for save" << std::endl;
		return;
	}

	if (commands[0] == "loadgame")
	{
		std::cout << "Place holder for load" << std::endl;
		return;
	}

	std::cout << "You can't do that here." << std::endl;
	return;
}

void roomInteractionLatrine(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList, Parser* parserPtr)
{

	/*Set of commands to check room inventory.  Mainly for testing purposes rather than for the player.  May keep condition to allow player a cheat.  Won't put in help list.*/
	if (commands[0] == "look" && commands[1] == "for" && commands[2] == "booze")
	{
		playerLocation->itemsInRoom();
		return;
	}

	if (commands[0] == "talk")
	{
		std::cout << "There is no one in the latrine to talk with.  You feel quite lonely now." << std::endl;
		return;
	}

	if (commands[0] == "drink")
	{
		drink(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "smell" && commands[1] == "the" && commands[2] == "toilet paper")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "It has the faint smell of charcoal on it.  Probably from the smudged writing on it." << std::endl;
			return;
		}

		else
		{
			playerLocation->featureOne(playerPtr);
			return;
		}
	}

	if (commands[0] == "smell" && commands[1] == "the" && commands[2] == "toilet")
	{
		std::cout << "You observe that despite the carnage in the hallway, the toilet smells like it was recently cleaned." << std::endl;
		return;
	}

	if (commands[0] == "drop")
	{
		drop(commands, playerLocation, playerPtr, roomList, 2);
		return;
	}

	if (commands[0] == "attack")
	{
		std::cout << "There's no one and nothing to attack now." << std::endl;
		return;
	}

	if (commands[0] == "eat" && commands[1] == "the" && commands[2] == "toilet paper")
	{
		std::cout << "Not a good idea to eat the toilet paper.  You don't want to forget the code that's written on it." << std::endl;
		return;
	}

	if (commands[0] == "eat")
	{
		eat(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "use" && commands[1] == "the" && commands[2] == "toilet")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "You don't have to do that right now.  You used the toilet before you got attack by whatever that thing was." << std::endl;
			return;
		}

		else
		{
			playerLocation->featureTwo(playerPtr);
			return;
		}
	}

	if (commands[0] == "use" && commands[1] == "the" && commands[2] == "toilet paper")
	{
		std::cout << "You decide against using the toilet paper.  It has a code on it.  The code may come in handy." << std::endl;
		return;
	}

	if (commands[0] == "jump" && commands[1] == "on" && commands[2] == "toilet")
	{
		std::cout << "You jump up on the toilet and take a look at the room.  You notice some writing on the wall.  Is it code?  It reads: 'CS352SUX.'" << std::endl;
		std::cout << "Is that another code or just graffiti?" << std::endl;
		return;
	}


	if (commands[0] == "jump" && commands[1] == "on" && commands[2] == "toilet paper")
	{
		std::cout << "That just doesn't make any sense.  There is no reason to do that." << std::endl;
		return;
	}

	if (commands[0] == "flee")
	{
		std::cout << "There is nothing to flee from..At least not at this time." << std::endl;
		return;
	}

	if (commands[0] == "break" && commands[1] == "the" && commands[2] == "toilet")
	{
		std::cout << "You decide against it.  'I would sooner destroy a stained glass window than a piece of art like yourself,' you say to the toilet." << std::endl;
		return;
	}

	if (commands[0] == "break" && commands[1] == "the" && commands[2] == "toilet paper")
	{
		std::cout << "You might need it for later.  Besides, how do you break toilet paper?" << std::endl;
		return;
	}

	if (commands[0] == "look" && commands[1] == "" && commands[2] == "")
	{
		std::string longDescription = playerLocation->getLongDescrip();
		std::cout << longDescription << std::endl;
		return;
	}

	if (commands[0] == "look" && commands[1] == "at" && commands[2] == "toilet paper")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "Why did someone write code on the toilet paper?  5392 is written on it.  The code to the flamethrower locker." << std::endl;
			return;
		}

		else
		{
			playerLocation->featureOne(playerPtr);
			return;
		}
	}

	if (commands[0] == "look" && commands[1] == "at" && commands[2] == "toilet")
	{
		std::cout << "You behold the majesty of the porcelain throne.  It is a one piece, American Standard Madera, flushing at 1.6 gallons per flush, with an elongated bowl. " << std::endl;
		return;
	}

	if (commands[0] == "look" && commands[1] == "at" && commands[2] == "creature")
	{
		std::cout << "You are not sure what it is that just attacked you.  But you are sure it is not of this world.  Maybe it or one of its kind caused all the carnage in the hallway." << std::endl;
		return;
	}

	if (commands[0] == "look" && commands[1] == "at")
	{
		lookAt(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "current" && commands[2] == "room")
	{
		std::cout << "CURRENT ROOM: " << playerLocation->getName() << std::endl;
		return;
	}

	/*calls helper go function with playerLocation pointer, list of rooms and room number to go to.*/

	if (commands[0] == "go" && commands[1] == "to" && commands[2] == "hallway1")
	{
		go(playerLocation, roomList, 1, playerPtr);
		return;
	}

	if (commands[0] == "take")
	{
		take(commands, playerLocation, playerPtr, roomList, 0);
		return;
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

	if (commands[0] == "savegame")
	{
		std::cout << "Place holder for save" << std::endl;
		return;
	}

	if (commands[0] == "loadgame")
	{
		std::cout << "Place holder for load" << std::endl;
		return;
	}

	std::cout << "You can't do that here." << std::endl;
	return;
}

void roomInteractionEquipmentRoom(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList, Parser* parserPtr)
{

	/*Set of commands to check room inventory.*/
	if (commands[0] == "look" && commands[1] == "for" && commands[2] == "booze")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			playerLocation->itemsInRoom();
			return;
		}

		else
		{
			std::cout << "Since the lights are off, you can't do that right now." << std::endl;
			return;
		}
	}

	if (commands[0] == "talk")
	{
		if (playerLocation->getFeatureOneHap() == 0)
		{
			std::cout << "You call out to the darkness.  'Hello?  Is anyone in here?'  There is no response.  Perhaps you should use the lights." << std::endl;
			return;
		}

		else
		{
			std::cout << "With the lights on, you can see there is no one to talk to." << std::endl;
			return;
		}
	}

	if (commands[0] == "drink")
	{
		drink(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "smell" && commands[1] == "the" && commands[2] == "lights")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "You smell the light switch for some reason.  It smells faintly of the Dorito dust that is still on your fingers from last night's drinking session." << std::endl;
			return;
		}

		else
		{
			std::cout << "Your olfactory acuity is not strong enough to find the lights in the darkn." << std::endl;
			std::cout << "Perhaps you should use the sense of touch instead to feel for the light switch." << std::endl;
			return;
		}
	}

	if (commands[0] == "smell" && commands[1] == "the" && commands[2] == "case")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "The case doesn't smell like anything." << std::endl;
			return;
		}

		else
		{
			std::cout << "Although the room is dark, you remember there is a case in it.  You try to smell it and pick up nothing." << std::endl;
			return;
		}
	}

	if (commands[0] == "drop")
	{
		drop(commands, playerLocation, playerPtr, roomList, 2);
		return;
	}

	if (commands[0] == "attack")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "There's nothing to attack in here." << std::endl;
			return;
		}

		else
		{
			std::cout << "With the lights off you are unsure if there is anything to attack.  You blindly start punching at the darkness.  Your fists connect with nothing." << std::endl;
			return;
		}

	}

	if (commands[0] == "eat" && commands[1] == "the" && commands[2] == "lights")
	{
		std::cout << "Nope.  You can't do that." << std::endl;
		return;
	}

	if (commands[0] == "eat")
	{
		eat(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "use" && commands[1] == "the" && commands[2] == "lights")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "You think about turning the lights off, but reconsider.  It might be a good idea to leave them on for now." << std::endl;
			return;
		}

		else
		{
			playerLocation->featureOne(playerPtr);
			return;
		}
	}

	if (commands[0] == "use" && commands[1] == "the" && commands[2] == "case")
	{
		std::cout << "You fumble with the case.  It appears to be locked." << std::endl;
		return;
	}

	if (commands[0] == "jump" && commands[1] == "on" && commands[2] == "case")
	{
		std::cout << "You jump up and down on the case and fall onto the floor." << std::endl;
		std::cout << "'Ouch,' you exclaim." << std::endl;
		return;
	}

	if (commands[0] == "flee")
	{
		std::cout << "There is nothing to flee from...At least not at this time." << std::endl;
		return;
	}

	if (commands[0] == "break" && commands[1] == "the" && commands[2] == "lights")
	{
		std::cout << "You decide against it.  You might have to come back here.  So it is a good idea to not break the light switch or lights." << std::endl;
		return;
	}

	if (commands[0] == "break" && commands[1] == "the" && commands[2] == "case")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "You already broke into the case." << std::endl;
		}

		else
		{
			playerLocation->featureTwo(playerPtr);
			return;
		}
	}

	if (commands[0] == "look" && commands[1] == "" && commands[2] == "")
	{
		std::string longDescription = playerLocation->getLongDescrip();
		std::cout << longDescription << std::endl;
		return;
	}

	if (commands[0] == "look" && commands[1] == "at" && commands[2] == "lights")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "The lightswitch has a little bit of Dorito dust smeared on it.  You are the culprit." << std::endl;
			return;
		}

		else
		{
			std::cout << "The room is too dark to see the light switch." << std::endl;
			return;
		}
	}

	if (commands[0] == "look" && commands[1] == "at" && commands[2] == "case")
	{
		if (playerLocation->getFeatureOneHap() == 1 && playerLocation->getFeatureTwoHap()==1)
		{
			std::cout << "You look at the broken glass from the case.  You have an odd sense of satisfaction about your handy work." << std::endl;
			return;
		}

		if (playerLocation->getFeatureOneHap() == 1 && playerLocation->getFeatureTwoHap() == 0)
		{
			std::cout << "You see the case holding the blowtorch is locked." << std::endl;
			std::cout << "It looks like you could break the glass of the case to get the blowtorch." << std::endl;
			return;
		}


	}

	if (commands[0] == "look" && commands[1] == "at" && commands[2] == "other equpipment")
	{
		std::cout << "The other equipment in the room is of no interest to you right now." << std::endl;
		return;
	}

	if (commands[0] == "look" && commands[1] == "at")
	{
		lookAt(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "current" && commands[2] == "room")
	{
		std::cout << "CURRENT ROOM: " << playerLocation->getName() << std::endl;
		return;
	}

	/*calls helper go function with playerLocation pointer, list of rooms and room number to go to.*/

	if (commands[0] == "go" && commands[1] == "to" && commands[2] == "hallway1")
	{
		go(playerLocation, roomList, 1, playerPtr);
		return;
	}

	if (commands[0] == "go" && commands[1] == "to" && commands[2] == "toolshed")
	{
		go(playerLocation, roomList, 4, playerPtr);
		return;
	}


	if (commands[0] == "take")
	{
		take(commands, playerLocation, playerPtr, roomList, 0);
		return;
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

	if (commands[0] == "savegame")
	{
		std::cout << "Place holder for save" << std::endl;
		return;
	}

	if (commands[0] == "loadgame")
	{
		std::cout << "Place holder for load" << std::endl;
		return;
	}

	std::cout << "You can't do that here." << std::endl;
	return;
}

/*Change toolshed*/
void roomInteractionToolShed(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList, Parser* parserPtr)
{

	/*Set of commands to check room inventory.*/
	if (commands[0] == "look" && commands[1] == "for" && commands[2] == "booze")
	{
		playerLocation->itemsInRoom();
		return;
	}

	if (commands[0] == "talk")
	{
		if (playerLocation->featureOne(playerPtr) == 0)
		{
			std::cout << "You call out in the snow in the direction you heard the groaning.  There is no response" << std::endl;
			return;
		}

		else
		{
			std::cout << "Are you sure you want to try that again?" << std::endl;
			return;
		}
	}

	if (commands[0] == "drink")
	{
		drink(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "smell" && commands[1] == "the" && commands[2] == "groaning")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "Do you really want to do that again?" << std::endl;
			return;
		}

		else
		{
			std::cout << "You tilt your head in the direction the groan came from.  You smell nothing out of the ordinary." << std::endl;
			return;
		}
	}

	if (commands[0] == "smell" && commands[1] == "the" && commands[2] == "shining")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "Do you really want to do that again?" << std::endl;
			return;
		}

		else
		{
			std::cout << "You tilt your head in the direction the groan came from.  You smell nothing out of the ordinary." << std::endl;
			return;
		}
	}

	if (commands[0] == "drop")
	{
		drop(commands, playerLocation, playerPtr, roomList, 2);
		std::cout << "Hopefully you can find it in the snow after dropping it." << std::endl;
		return;
	}

	if (commands[0] == "attack")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "There's nothing to attack out here now." << std::endl;
			return;
		}

		else
		{
			std::cout << "If you are going to attack anything, you're going to need to get closer." << std::endl;
			return;
		}

	}

	if (commands[0] == "eat" && commands[1] == "the" && commands[2] == "groaning")
	{
		std::cout << "Whatever is groaning out there is probably not easily eaten." << std::endl;
		return;
	}

	if (commands[0] == "eat" && commands[1] == "the" && commands[2] == "shining")
	{
		std::cout << "Whatever is shining out there probably is not edible." << std::endl;
		return;
	}

	if (commands[0] == "eat")
	{
		eat(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "use" && commands[1] == "the" && commands[2] == "groaning")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{

		}

		else
		{
			playerLocation->featureOne(playerPtr);
			return;
		}
	}

	if (commands[0] == "use" && commands[1] == "the" && commands[2] == "shining")
	{
		std::cout << "You fumble with the case.  It appears to be locked." << std::endl;
		return;
	}

	if (commands[0] == "jump" && commands[1] == "on" && commands[2] == "groaning")
	{
	
		return;
	}

	if (commands[0] == "jump" && commands[1] == "on" && commands[2] == "shining")
	{

		return;
	}

	if (commands[0] == "flee")
	{
		std::cout << "There is nothing to flee from...At least not at this time." << std::endl;
		return;
	}

	if (commands[0] == "break" && commands[1] == "the" && commands[2] == "groaning")
	{
		std::cout << "You decide against it.  You might have to come back here.  So it is a good idea to not break the light switch or lights." << std::endl;
		return;
	}

	if (commands[0] == "break" && commands[1] == "the" && commands[2] == "shining")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "You already broke into the case." << std::endl;
		}

		else
		{
			playerLocation->featureTwo(playerPtr);
			return;
		}
	}

	if (commands[0] == "look" && commands[1] == "" && commands[2] == "")
	{
		std::string longDescription = playerLocation->getLongDescrip();
		std::cout << longDescription << std::endl;
		return;
	}

	if (commands[0] == "look" && commands[1] == "at" && commands[2] == "groaning")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			return;
		}

		else
		{
			return;
		}
	}

	if (commands[0] == "look" && commands[1] == "at" && commands[2] == "groaning")
	{
		if (playerLocation->getFeatureOneHap() == 1 && playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "You look at the broken glass from the case.  You have an odd sense of satisfaction about your handy work." << std::endl;
			return;
		}

		if (playerLocation->getFeatureOneHap() == 1 && playerLocation->getFeatureTwoHap() == 0)
		{
			std::cout << "You see the case holding the blowtorch is locked." << std::endl;
			std::cout << "It looks like you could break the glass of the case to get the blowtorch." << std::endl;
			return;
		}


	}

	if (commands[0] == "look" && commands[1] == "at" && commands[2] == "shining")
	{
		std::cout << "The other equipment in the room is of no interest to you right now." << std::endl;
		return;
	}

	if (commands[0] == "look" && commands[1] == "at")
	{
		lookAt(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "current" && commands[2] == "room")
	{
		std::cout << "CURRENT ROOM: " << playerLocation->getName() << std::endl;
		return;
	}

	/*calls helper go function with playerLocation pointer, list of rooms and room number to go to.*/

	if (commands[0] == "go" && commands[1] == "to" && commands[2] == "equipment room")
	{
		go(playerLocation, roomList, 3, playerPtr);
		return;
	}

	if (commands[0] == "go" && commands[1] == "to" && commands[2] == "groaning")
	{
		return;
	}

	if (commands[0] == "go" && commands[1] == "to" && commands[2] == "shining")
	{
		return;
	}


	if (commands[0] == "take")
	{
		take(commands, playerLocation, playerPtr, roomList, 0);
		return;
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

	if (commands[0] == "savegame")
	{
		std::cout << "Place holder for save" << std::endl;
		return;
	}

	if (commands[0] == "loadgame")
	{
		std::cout << "Place holder for load" << std::endl;
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
	MessHall messhall;
	Hallway2 hallway2;
	Garage garage;
	Galley galley;
	DogKennel dogkennel;
	Basement basement;
	ConferenceRoom conferenceroom;

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

hallway1Ptr->addItem(axe);
latrinePtr->addItem(toiletPaper);
equipmentroomPtr->addItem(blowTorch);
toolshedPtr->addItem(whiskey);
toolshedPtr->addItem(rope);
sickbayPtr->addItem(scalpel);




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
playerPtr->gritWarning();

}
userInput = "";




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


if (userInput == "exit")
{
	std::cout << "Ending game." << std::endl;
	parserPtr->freeStaticActions();
	exit(0);
}

roomRouter(commands, playerLocation, playerPtr, roomList, parserPtr);

/*playerLocation->displayExits();*/

}while(userInput != "exit");

}











