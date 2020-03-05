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

#include "SaveLoad.hpp"

/*Prototypes*/
void roomRouter(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList, Parser* parserPtr);
void lookAt(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector<Room*> &roomList, int roomNumber);

void roomInteractionMacready(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList, Parser* parserPtr);
void roomInteractionHallway1(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList, Parser* parserPtr);
void roomInteractionLatrine(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList, Parser* parserPtr);
void roomInteractionEquipmentRoom(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList, Parser* parserPtr);
void roomInteractionToolShed(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList, Parser* parserPtr);
void roomInteractionSickBay(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList, Parser* parserPtr);
void roomInteractionRadioRoom(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList, Parser* parserPtr);
void roomInteractionResearchLab(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList, Parser* parserPtr);
void roomInteractionMessHall(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList, Parser* parserPtr);
void roomInteractionHallway2(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList, Parser* parserPtr);

void roomInteractionGarage(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList, Parser* parserPtr);
void roomInteractionGalley(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList, Parser* parserPtr);
void roomInteractionDogKennel(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList, Parser* parserPtr);
void roomInteractionBasement(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList, Parser* parserPtr);
void roomInteractionConferenceRoom(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList, Parser* parserPtr);



/*REFACTOR FUNCTIONS LATER*/

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
		std::cout <<"You can't do that." << std::endl;
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
	std::string roomName;

	if (playerLocation->getName() == "macready")
	{
		roomName = "MacReady's Quarters";
		std::cout << "You go to " << roomName << std::endl;
		std::cout << "CURRENT LOCATION: " << roomName<< std::endl;
	}

	if (playerLocation->getName() == "hallway1")
	{
		roomName = "Hallway 1";
		std::cout << "You go to " << roomName << std::endl;
		std::cout << "CURRENT LOCATION: " << roomName << std::endl;
	}

	if (playerLocation->getName() == "latrine")
	{
		roomName = "The Latrine";
		std::cout << "You go to " << roomName << std::endl;
		std::cout << "CURRENT LOCATION: " << roomName << std::endl;
	}

	if (playerLocation->getName() == "equipment room")
	{
		roomName = "The Equipment Room";
		std::cout << "You go to " << roomName << std::endl;
		std::cout << "CURRENT LOCATION: " << roomName << std::endl;
	}

	if (playerLocation->getName() == "tool shed")
	{
		roomName = "The Toolshed";
		std::cout << "You go to " << roomName << std::endl;
		std::cout << "CURRENT LOCATION: " << roomName << std::endl;
	}

	if (playerLocation->getName() == "sickBay")
	{
		roomName = "The Sick Bay";
		std::cout << "You go to " << roomName << std::endl;
		std::cout << "CURRENT LOCATION: " << roomName << std::endl;
	}

	if (playerLocation->getName() == "radioRoom")
	{
		roomName = "The Radio Room";
		std::cout << "You go to " << roomName << std::endl;
		std::cout << "CURRENT LOCATION: " << roomName << std::endl;
	}

	if (playerLocation->getName() == "researchLab")
	{
		roomName = "The Research Lab";
		std::cout << "You go to " << roomName << std::endl;
		std::cout << "CURRENT LOCATION: " << roomName << std::endl;
	}

	if (playerLocation->getName() == "hallway2")
	{
		roomName = "Hallway 2";
		std::cout << "You go to " << roomName << std::endl;
		std::cout << "CURRENT LOCATION: " << roomName << std::endl;
	}

	if (playerLocation->getName() == "messHall")
	{
		roomName = "The Mess Hall";
		std::cout << "You go to " << roomName << std::endl;
		std::cout << "CURRENT LOCATION: " << roomName << std::endl;
	}

	if (playerLocation->getName() == "galley")
	{
		roomName = "The Galley";
		std::cout << "You go to " << roomName << std::endl;
		std::cout << "CURRENT LOCATION: " << roomName << std::endl;
	}

	if (playerLocation->getName() == "dogKennel")
	{
		roomName = "The Dog Kennel";
		std::cout << "You go to " << roomName << std::endl;
		std::cout << "CURRENT LOCATION: " << roomName << std::endl;
	}

	if (playerLocation->getName() == "basement")
	{
		roomName = "The Basement";
		std::cout << "You go to " << roomName << std::endl;
		std::cout << "CURRENT LOCATION: " << roomName << std::endl;
	}

	if (playerLocation->getName() == "conferenceRoom")
	{
		roomName = "The Conference Room";
		std::cout << "You go to " << roomName << std::endl;
		std::cout << "CURRENT LOCATION: " << roomName << std::endl;
	}
	
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

	if (playerLocation->getName() == "sickBay")
	{
		roomInteractionSickBay(commands, playerLocation, playerPtr, roomList, parserPtr);
		return;
	}

	if (playerLocation->getName() == "radioRoom")
	{
		roomInteractionRadioRoom(commands, playerLocation, playerPtr, roomList, parserPtr);
		return;
	}

	if (playerLocation->getName() == "researchLab")
	{
		roomInteractionResearchLab(commands, playerLocation, playerPtr, roomList, parserPtr);
		return;
	}

	if (playerLocation->getName() == "hallway2")
	{
		roomInteractionHallway2(commands, playerLocation, playerPtr, roomList, parserPtr);
		return;
	}

	if (playerLocation->getName() == "messHall")
	{
		roomInteractionMessHall(commands, playerLocation, playerPtr, roomList, parserPtr);
		return;
	}

	if (playerLocation->getName() == "galley")
	{
		roomInteractionGalley(commands, playerLocation, playerPtr, roomList, parserPtr);
		return;
	}

		if (playerLocation->getName() == "garage")
	{
		roomInteractionGarage(commands, playerLocation, playerPtr, roomList, parserPtr);
		return;
	}
	
	if (playerLocation->getName() == "dogKennel")
	{
		roomInteractionDogKennel(commands, playerLocation, playerPtr, roomList, parserPtr);
		return;
	}

	if (playerLocation->getName() == "basement")
	{
		roomInteractionBasement(commands, playerLocation, playerPtr, roomList, parserPtr);
		return;
	}

	if (playerLocation->getName() == "conferenceRoom")
	{
		roomInteractionConferenceRoom(commands, playerLocation, playerPtr, roomList, parserPtr);
		return;
	}



}

/*Function to interact with macready room*/
/*Based on commands within array, conditions are set up to control interactions with room.*/
/*If a condition is met a room function is called for more interaction.  return is then used to get back to the main function.*/
/*If no conditions are met, it moves to the bottom of the function and a message is printed that whatever the user typed cannot be done.*/
void roomInteractionMacready(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList, Parser* parserPtr)
{
	if (commands[0] == "savegame" || commands[0] == "loadgame")
	{
		return;

	}
	/*helper phrase.*/
	if (commands[0] == "look" && commands[1] == "for" && commands[2] == "booze")
	{
		std::cout << "You start looking for booze and notice..." << std::endl;
		std::string freeBooze = "beer";

		if (playerLocation->checkItem(freeBooze) != 999)
		{
			std::cout << "You notice a bottle of beer on the floor." << std::endl;
			std::cout << "You don't think MacReady will miss it." << std::endl;
			std::cout << "He thinks this one is nasty." << std::endl;
			std::cout << "After checking the room for booze, you also notice some other potentially useful items." << std::endl;
		}

		playerLocation->itemsInRoom();
		return;
	}

	if ((commands[0] == "use" && commands[2] == "blood test") || (commands[0] == "look" && commands[1] == "at" && commands[2] == "blood"))
	{
		std::cout << "Hmm..." << std::endl;
		std::cout << "There's no one around to do a blood test on." << std::endl;
		std::cout << "And you have no reason to test your blood." << std::endl;
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
		std::cout << "You take a deep whiff from the bed...It smells like a chimp sleeps here.  And you should know because you worked a summer at the zoo once." << std::endl;
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

	if (commands[0] == "break" && commands[2] == "computer")
	{
		std::cout << "You're jealous of Macready's outstanding computer and for a split second you consider breaking it out of spite." << std::endl;
		std::cout << "However, you come to your senses and decide not to break Macready's computer." << std::endl;
		return;
	}

	if (commands[0] == "break" && commands[2] == "bed")
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

	if (commands[0] == "look" &&  commands[2] == "bed")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "You already checked under the bed and the room.  No booze.  Drat!" << std::endl;
			return;
		}

		if (playerLocation->getFeatureOneHap() == 0)
		{
			std::cout << "You look at Macready's bed.  It's not made." << std::endl;
			playerLocation->featureOne(playerPtr);
			return;
		}
	}

	if (commands[0] == "look" && commands[2] == "computer")
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

	if (commands[0] == "room")
	{
		/*Asks pointer to get name*/
		std::cout << "CURRENT ROOM: " << playerLocation->getName() << std::endl;
		return;
	}

	if (commands[0] == "current" && commands[2] == "room")
	{
		std::cout << "You are in Macreqdy's Quarters." << std::endl;
		mapMacready();
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

		std::cout << "You can't do that here." << std::endl;
		return;
}

void roomInteractionHallway1(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList, Parser* parserPtr)
{
	if (commands[0] == "savegame" || commands[0] == "loadgame")
	{
		return;

	}
	/*Set of commands to check room inventory.  Mainly for testing purposes rather than for the player.  May keep condition to allow player a cheat.  Won't put in help list.*/
	if (commands[0] == "look" && commands[1] == "for" && commands[2] == "booze")
	{
		std::cout << "You start looking for booze and notice..." << std::endl;
		std::string freeBooze = "beer";

		if (playerLocation->checkItem(freeBooze) != 999)
		{
			std::cout << "You notice a bottle of beer on the floor." << std::endl;
			std::cout << "What luck it didn't break during the outbreak of carnage." << std::endl;
			std::cout << "After checking the room for booze, you also notice some other potentially useful items." << std::endl;
		}

		playerLocation->itemsInRoom();
		return;
	}

	if ((commands[0] == "use" && commands[2] == "blood test") || (commands[0] == "look" && commands[1] == "at" && commands[2] == "blood"))
	{
		std::cout << "Though this room does have its share of blood, none of it is fresh." << std::endl;
		std::cout << "Also you aren't sure of the source of blood." << std::endl;
		std::cout << "Without this information, it wouldn't be helpful to run a test." << std::endl;
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

	if (commands[0] == "smell" && commands[2] == "lights")
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

	if (commands[0] == "use" && commands[2] == "lights")
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

	if (commands[0] == "room")
	{
		std::cout << "CURRENT ROOM: " << playerLocation->getName() << std::endl;
		return;
	}

	if (commands[0] == "current" && commands[2] == "room")
	{
		std::cout << "You are in Hallway 1. " << std::endl;
		mapHallway1();
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

	if ((commands[0] == "go" && commands[1] == "to" && commands[2] == "equipment room") || (commands[0] == "go" && commands[1] == "to" && commands[2] == "equipmentroom"))
	{
		go(playerLocation, roomList, 3, playerPtr);
		return;
	}

	if ((commands[0] == "go" && commands[1] == "to" && commands[2] == "radio room") || (commands[0] == "go" && commands[1] == "to" && commands[2] == "radioroom"))
	{
		go(playerLocation, roomList, 6, playerPtr);
		return;
	}

	if (commands[0] == "go" && commands[1] == "to" && commands[2] == "hallway2")
	{
		go(playerLocation, roomList, 9, playerPtr);
		return;
	}

	if ((commands[0] == "go" && commands[1] == "to" && commands[2] == "research lab") || (commands[0] == "go" && commands[1] == "to" && commands[2] == "researchlab"))
	{
		go(playerLocation, roomList, 7, playerPtr);
		return;
	}

	if ((commands[0] == "go" && commands[1] == "to" && commands[2] == "sickbay") || commands[0] == "go" && commands[1] == "to" && commands[2] == "sick bay")
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

	std::cout << "You can't do that here." << std::endl;
	return;
}

void roomInteractionLatrine(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList, Parser* parserPtr)
{
	if (commands[0] == "savegame" || commands[0] == "loadgame")
	{
		return;

	}

	/*Set of commands to check room inventory.  Mainly for testing purposes rather than for the player.  May keep condition to allow player a cheat.  Won't put in help list.*/
	if (commands[0] == "look" && commands[1] == "for" && commands[2] == "booze")
	{
		std::cout << "You start looking for booze and notice..." << std::endl;
		std::string freeBooze = "beer";

		if (playerLocation->checkItem(freeBooze) != 999)
		{
			std::cout << "You notice a bottle of beer in the sink." << std::endl;
			std::cout << "After checking the room for booze, you also notice some other potentially useful items." << std::endl;

		}

		playerLocation->itemsInRoom();
		return;
	}

	if ((commands[0] == "use" && commands[2] == "blood test") || (commands[0] == "look" && commands[1] == "at" && commands[2] == "blood"))
	{
		std::cout << "It would make sense to do that with a human specimen." << std::endl;
		std::cout << "You are the only human here and there is no reason to test your own blood." << std::endl;
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
		std::cout << "You jump up on the toilet and take a look at the room.  You notice some writing on the wall.  Is it code?  It reads: 'Snake was here.'" << std::endl;
		std::cout << "What kind of name is Snake?" << std::endl;
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
		if (playerLocation->getFeatureTwoHap() == 0)
		{
			std::cout << "What creature?  What are you talking about?" << std::endl;
			return;
		}

		else
		{
			std::cout << "You are not sure what it is that just attacked you.  But you are sure it is not of this world.  Maybe it or one of its kind caused all the carnage in the hallway." << std::endl;
			return;
		}



	}

	if (commands[0] == "look" && commands[1] == "at")
	{
		lookAt(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "room")
	{
		/*Asks pointer to get name*/
		std::cout << "CURRENT ROOM: " << playerLocation->getName() << std::endl;
		return;
	}

	if (commands[0] == "current" && commands[2] == "room")
	{
		std::cout << "You are in the Latrine." << std::endl;
		mapLatrine();
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

	std::cout << "You can't do that here." << std::endl;
	return;
}

void roomInteractionEquipmentRoom(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList, Parser* parserPtr)
{
	if (commands[0] == "savegame" || commands[0] == "loadgame")
	{
		return;

	}
	/*Set of commands to check room inventory.*/
	if (commands[0] == "look" && commands[1] == "for" && commands[2] == "booze")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "You start looking for booze and notice..." << std::endl;
			std::string freeBooze = "beer";

			if (playerLocation->checkItem(freeBooze) != 999)
			{
				std::cout << "You notice a bottle of beer on the floor." << std::endl;
				std::cout << "Amazingly, it was not broken when all the carnage went down." << std::endl;
				std::cout << "If you want to add it to your inventory, type: 'take beer' " << std::endl;
				std::cout << "After checking the room for booze, you also notice some other potentially useful items." << std::endl;

			}

			playerLocation->itemsInRoom();
			return;
		}

		else
		{
			std::cout << "Turn on the lights before you start looking for booze!" << std::endl;
			std::cout << "You might trip and crack your head." << std::endl;
			return;
		}
	}

	if ((commands[0] == "use" && commands[2] == "blood test") || (commands[0] == "look" && commands[1] == "at" && commands[2] == "blood"))
	{
		std::cout << "It would make sense to do that with a human specimen." << std::endl;
		std::cout << "You are the only human here and there is no reason to test your own blood." << std::endl;
		return;
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

	if (commands[0] == "look" && commands[1] == "at" && commands[2] == "other equipment")
	{
		std::cout << "The other equipment in the room is of no interest to you right now." << std::endl;
		return;
	}

	if (commands[0] == "look" && commands[1] == "at")
	{
		lookAt(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "room")
	{
		/*Asks pointer to get name*/
		std::cout << "CURRENT ROOM: " << playerLocation->getName() << std::endl;
		return;
	}

	if (commands[0] == "current" && commands[2] == "room")
	{
		std::cout << "You are in the Equipment Room." << std::endl;
		mapEquipmentRoom();
		return;
	}

	/*calls helper go function with playerLocation pointer, list of rooms and room number to go to.*/

	if (commands[0] == "go" && commands[1] == "to" && commands[2] == "hallway1")
	{
		go(playerLocation, roomList, 1, playerPtr);
		return;
	}

	if ((commands[0] == "go" && commands[1] == "to" && commands[2] == "toolshed") || (commands[0] == "go" && commands[1] == "to" && commands[2] == "tool shed"))
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

	std::cout << "You can't do that here." << std::endl;
	return;
}

/*Change toolshed*/
void roomInteractionToolShed(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList, Parser* parserPtr)
{
	if (commands[0] == "savegame" || commands[0] == "loadgame")
	{
		return;

	}
	/*phrase for looking at room inventory*/
	if (commands[0] == "look" && commands[1] == "for" && commands[2] == "booze")
	{
		std::cout << "You start looking for booze and notice..." << std::endl;
		std::string freeBooze = "beer";

		if (playerLocation->checkItem(freeBooze) != 999)
		{
			std::cout << "You notice a bottle of beer in the snow." << std::endl;
			std::cout << "It's like it was waiting for you all along!" << std::endl;
			std::cout << "After checking the room for booze, you also notice some other potentially useful items." << std::endl;
		}

		playerLocation->itemsInRoom();
		return;
	}

	if ((commands[0] == "use" && commands[2] == "blood test") || (commands[0] == "look" && commands[1] == "at" && commands[2] == "blood"))
	{
		std::cout << "It would make sense to do that with a human specimen." << std::endl;
		std::cout << "You are the only human here and there is no reason to test your own blood." << std::endl;
		return;
	}

	if (commands[0] == "talk")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "Are you crazy?" << std::endl;
			std::cout << "That thing attacked you!" << std::endl;
			std::cout << "Why tempt fate and call attention to yourself again?" << std::endl;
			return;
		}

		if (playerLocation->getFeatureOneHap() == 0)
		{
			std::cout << "You may want to get closer to the groaning sound." << std::endl;
			std::cout << "Why don't you go closer to whatever is making that sound?" << std::endl;
			std::cout << "Just a little bit closer..." << std::endl;
			std::cout << "Just a little bit closer..." << std::endl;
			std::cout << "Hahhahaha!" << std::endl;
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
		std::cout << "You don't smell anything decipherable coming from the direction of whatever is groaning." << std::endl;
		std::cout << "You should probably get a little bit closer to whatever is making that sound." << std::endl;
		return;
	}

	if (commands[0] == "smell" && commands[1] == "the" && commands[2] == "shining")
	{
		std::cout << "Whatever is shining out here is not casting off any kind of odor." << std::endl;
		std::cout << "Maybe you should get a little closer." << std::endl;
		return;
	}

	if (commands[0] == "drop")
	{
		drop(commands, playerLocation, playerPtr, roomList, 2);
		return;
	}

	if (commands[0] == "attack" && commands[1] == "the" && commands[2] == "groaning")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "You decide to stay away from whatever is making that sound." << std::endl;
			return;
		}

		else
		{
			std::cout << "You steel yourself to be ready to attack whatever is making that groaning sound." << std::endl;
			std::cout << "You then realize it may be a team member making that sound, and you don't want to attack your teammates." << std::endl;
			std::cout << "So you decide to approach cautiously and be ready for the situation.  Like a Plisskin Snake ready to strike..." << std::endl;
			playerLocation->featureOne(playerPtr);
			return;
		}
	}


	if (commands[0] == "eat" && commands[2] == "snow")
	{
		std::cout << "You grab some snow and stuff it in your mouth." << std::endl;
		std::cout << "Suddenly your face goes numb..." << std::endl;
		std::cout << "Then everything goes black." << std::endl;
		playerPtr->setAlive(0);
		return;
	}

	if (commands[0] == "eat" && commands[1] == "the" &&commands[2] == "groaning")
	{
		std::cout << "Whatever is groaning is still alive." << std::endl;
		std::cout << "It could be human or a wounded animal." << std::endl;
		std::cout << "Whatever it is, you decide that it won't be appetizing." << std::endl;
		std::cout << "But you could at least find out what it is, if you get a little closer to it." << std::endl;
		return;
	}

	if (commands[0] == "eat" && commands[1] == "the" && commands[2] == "shining")
	{
		std::cout << "Whatever is shining, it looks like it is glass.  And you probably don't want to eat glass." << std::endl;
		std::cout << "Maybe you should get closer to get a better look." << std::endl;
		return;
	}

	if (commands[0] == "eat")
	{
		eat(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "use" && commands[1] == "the" && commands[2] == "groaning")
	{
		std::cout << "Whatever is groaning out here doesn't seem useable." << std::endl;
		return;
	}

	if (commands[0] == "use" && commands[1] == "the" && commands[2] == "shining")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "If you want to drink the bottle you found, use the drink command." << std::endl;
			return;
		}

		if (playerLocation->getFeatureTwoHap() == 0)
		{
			std::cout << "You don't know what is shining out here." << std::endl;
			std::cout << "You need to get closer to it first before you can decide if you can drink it." << std::endl;
			return;
		}
	}

	if (commands[0] == "jump" && commands[1] == "on" && commands[2] == "groaning")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "Whatever that thing was, you don't want to tangle with it again." << std::endl;
			std::cout << "You decide to steer clear of it." << std::endl;
			return;
		}

		if (playerLocation->getFeatureOneHap() == 0)
		{
			std::cout << "What are you thinking of doing?" << std::endl;
			std::cout << "Seeing if whatever is making that sound wants to play a game of leap frog?" << std::endl;
			return;
		}
	}


	if (commands[0] == "jump" && commands[1] == "on" && commands[2] == "shining")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "You decide you don't want to jump on the bottle of whiskey." << std::endl;
			std::cout << "It has good whiskey in it, and you don't want to break the bottle." << std::endl;
			return;
		}

		if (playerLocation->getFeatureTwoHap() == 0)
		{
			std::cout << "Not sure why you would want to jump on whatever is shining out here." << std::endl;
			std::cout << "But if you want to try that out, you need to get closer first." << std::endl;
			return;
		}
	}

	if (commands[0] == "flee" &&commands[1] == "from" &&commands[2] == "groaning")
	{

		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "Whatever that thing was, it doesn't seem to be aware of you right now." << std::endl;
			std::cout << "You don't need to flee from it unless you get close to it." << std::endl;
			return;
		}

		if (playerLocation->getFeatureOneHap() == 0)
		{
			std::cout << "As you have approached whatever is groaning, it doesn't seem like you need to flee from it yet." << std::endl;
			std::cout << "Maybe you should get closer to it first?" << std::endl;
			return;
		}
	}

	if (commands[0] == "flee" &&commands[1] == "from" &&commands[2] == "shining")
	{

		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "It was a bottle of Maker's Mark." << std::endl;
			std::cout << "Why would you need to flee from that?" << std::endl;
			return;
		}

		if (playerLocation->getFeatureTwoHap() == 0)
		{
			std::cout << "As you have not approached whatever is groaning, it doesn't seem like you need to flee from it just yet." << std::endl;
			std::cout << "Maybe you should get closer to it first to decide if you need to flee from it?" << std::endl;
			return;
		}
	}


	if (commands[0] == "break" && commands[1] == "the" && commands[2] == "groaning")
	{
		std::cout << "That doesn't make any sense." << std::endl;
		std::cout << "Do you mean you want to attack the thing that's groaning?" << std::endl;
		std::cout << "If so, maybe you should get closer to the thing that's groaning." << std::endl;
		return;
	}

	if (commands[0] == "break" && commands[1] == "the" && commands[2] == "shining")
	{
		std::cout << "If you want to break the thing that's shining, you should probably get closer to it." << std::endl;
		return;
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
			std::cout << "You strain your eyes in the direction of the groaning." << std::endl;
			std::cout << "You aren't sure what the heck attacked you, but you don't want to tangle with it again." << std::endl;
			return;
		}

		else
		{
			std::cout << "You look off into the distance where you hear the groaning." << std::endl;
			std::cout << "You cannot make out what you are seeing." << std::endl;
			std::cout << "You need to get closer." << std::endl;
			std::cout << "So you cautiously walk in the direction where you hear the groaning." << std::endl;
			std::cout << "It gets louder with each step you take..." << std::endl;
			playerLocation->featureOne(playerPtr);
			return;
		}
	}

	if (commands[0] == "look" && commands[1] == "at" && commands[2] == "shining")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "You already picked up what was shining." << std::endl;
			std::cout << "It was a bottle of Maker's Mark." << std::endl;
			std::cout << "This mystery has already been solved." << std::endl;
			return;
		}

		else
		{
			std::cout << "You stare off into the distance from where the shining is coming from." << std::endl;
			std::cout << "You can't make it out." << std::endl;
			std::cout << "You need to get closer to it to get a better look." << std::endl;
			return;
		}

	}

	if (commands[0] == "look" && commands[1] == "at" && commands[2] == "creature")
	{

		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "You are not sure what it is that just attacked you." << std::endl;
			std::cout << "You are sure it is not of this world." << std::endl;
			std::cout << "Maybe it or one of its kind caused all the carnage in the hallway." << std::endl;
			std::cout << "It has returned to its original spot and continues to groan in the distance." << std::endl;
			return;
		}
	}

	if (commands[0] == "look" && commands[1] == "at")
	{
		lookAt(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "current" && commands[2] == "room")
	{
		std::cout << "CURRENT ROOM: " << playerLocation->getName() << std::endl;
		mapToolShed();
		return;
	}

	if (commands[0] == "room")
	{
		/*Asks pointer to get name*/
		std::cout << "CURRENT ROOM: " << playerLocation->getName() << std::endl;
		return;
	}

	if (commands[0] == "current" && commands[2] == "room")
	{
		std::cout << "You are near the Tool Shed." << std::endl;
		mapToolShed();
		return;
	}


	/*calls helper go function with playerLocation pointer, list of rooms and room number to go to.*/

	if (commands[0] == "go" && commands[1] == "to" && commands[2] == "equipment room")
	{
		go(playerLocation, roomList, 3, playerPtr);
		return;
	}

	if (commands[0] == "go" && commands[1] == "to" &&commands[2] == "groaning")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "You narrowly escaped death the last time you went in the direction of the groaning." << std::endl;
			std::cout << "You decide to tempt fate again." << std::endl;
			std::cout << "This time the creature gets the upper hand and rips your head off." << std::endl;
			playerPtr->setAlive(0);
			return;
		}

		if (playerLocation->getFeatureOneHap() == 0)
		{
			playerLocation->featureOne(playerPtr);
			return;
		}
	}

	if (commands[0] == "go" && commands[1] == "to" &&commands[2] == "shining")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "You already approached what was shining." << std::endl;
			std::cout << "It was a bottle of Maker's Mark." << std::endl;
			return;
		}

		if (playerLocation->getFeatureTwoHap() == 0)
		{
			playerLocation->featureTwo(playerPtr);
			return;
		}
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

	std::cout << "You can't do that here." << std::endl;
	return;
}

void roomInteractionSickBay(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList, Parser* parserPtr)
{
	if (commands[0] == "savegame" || commands[0] == "loadgame")
	{
		return;
	}
	/*phrase for looking at room inventory*/
	if (commands[0] == "look" && commands[1] == "for" && commands[2] == "booze")
	{
		std::cout << "You start looking for booze and notice..." << std::endl;

		playerLocation->itemsInRoom();
		return;
	}

	if ((commands[0] == "use" && commands[2] == "blood test") || (commands[0] == "look" && commands[1] == "at" && commands[2] == "blood"))
	{
		std::cout << "Now is not the time to do a blood test." << std::endl;
		return;
	}

	if (commands[0] == "talk" && commands[1] == "to" && commands[2] == "crew member")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "Although he attacked you previously, you decide to call out to him to get his attention." << std::endl;
			std::cout << "You try talking to Jack from a safe distance." << std::endl;
			std::cout << "He is nonresponsive." << std::endl;
			return;
		}

		if (playerLocation->getFeatureTwoHap() == 0)
		{
			playerLocation->featureTwo(playerPtr);
			return;
		}
	}

	if (commands[0] == "drink")
	{
		drink(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "smell" && commands[1] == "the" && commands[2] == "medical supplies")
	{
		std::cout << "The medical supplies have that sterile smell only medical supplies can have." << std::endl;
		return;
	}

	if (commands[0] == "smell" && commands[1] == "the" && commands[2] == "crew member")
	{
		std::cout << "You can smell Jack from a good distance." << std::endl;
		std::cout << "He doesn't smell quite right." << std::endl;
		std::cout << "It reminds you of putrefication." << std::endl;
		return;
	}

	if (commands[0] == "drop")
	{
		drop(commands, playerLocation, playerPtr, roomList, 2);
		return;
	}

	if (commands[0] == "attack" && commands[1] == "the" && commands[2] == "crew member")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "You are not anxious to tangle with Jack again." << std::endl;
			std::cout << "There was something unnatural about the way he was moving." << std::endl;
			std::cout << "There was an inhuman quality to the way he moved." << std::endl;
			return;
		}

		else
		{
			std::cout << "Although Jack is a crew member, and you have nothing against him, you decide you are going to walk over and punch him in the face." << std::endl;
			playerLocation->featureTwo(playerPtr);
			return;
		}
	}


	if (commands[0] == "eat" && commands[2] == "medical supplies")
	{
		std::cout << "You look through the medical supplies and start eating them although they are for external use only." << std::endl;
		std::cout << "You should have used them as directed." << std::endl;
		playerPtr->setAlive(0);
		return;
	}

	if (commands[0] == "eat" && commands[1] == "the" &&commands[2] == "crew member")
	{
		std::cout << "What is wrong with you?" << std::endl;
		std::cout << "This game is not a Donner Party simulator!" << std::endl;
		std::cout << "Maybe you should check the galley for food before you think about cannibalism." << std::endl;
		return;
	}

	if (commands[0] == "eat")
	{
		eat(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "use" && commands[1] == "the" && commands[2] == "medical supplies")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "You already used the medical supplies." << std::endl;
			return;
		}

		if (playerLocation->getFeatureOneHap() == 0)
		{
			playerLocation->featureOne(playerPtr);
			return;
		}
	}

	if (commands[0] == "use" && commands[1] == "the" && commands[2] == "crew member")
	{
		std::cout << "You are not a master manipulator." << std::endl;
		std::cout << "You don't have the charisma to use people." << std::endl;
		return;
	}



	if (commands[0] == "jump" && commands[1] == "on" && commands[2] == "medical supplies")
	{
		std::cout << "There is no point in jumping on the medical supplies." << std::endl;
		return;
	}


	if (commands[0] == "jump" && commands[1] == "on" && commands[2] == "crew member")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "Even if you get the jump on the guy this time, you may not walk away from the encounter." << std::endl;
			std::cout << "You decide not to try it." << std::endl;
			return;
		}

		if (playerLocation->getFeatureTwoHap() == 0)
		{
			std::cout << "You consider jumping and tackling a bedridden patient." << std::endl;
			std::cout << "But you decide that would be too cruel." << std::endl;
			return;
		}
	}

	if (commands[0] == "flee" &&commands[1] == "from" &&commands[2] == "crew member")
	{

		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "You decide to run away from Jack since he attacked you." << std::endl;
			std::cout << "You run back to the hallway." << std::endl;
			go(playerLocation, roomList, 1, playerPtr);
			return;
		}

		if (playerLocation->getFeatureTwoHap() == 0)
		{
			std::cout << "The crew member is bedridden." << std::endl;
			std::cout << "There is no reason to flee from him right now." << std::endl;
			return;
		}
	}

	if (commands[0] == "break" && commands[1] == "the" && commands[2] == "medical supplies")
	{
		std::cout << "There is no reason to wase good medical supplies." << std::endl;
		return;
	}

	if (commands[0] == "break" && commands[1] == "the" && commands[2] == "crew member")
	{
		std::cout << "He's already pretty broken up from the look of him." << std::endl;
		std::cout << "There's no need for overkill." << std::endl;
		return;
	}

	if (commands[0] == "look" && commands[1] == "" && commands[2] == "")
	{
		std::string longDescription = playerLocation->getLongDescrip();
		std::cout << longDescription << std::endl;
		return;
	}

	if (commands[0] == "look" && commands[1] == "at" && commands[2] == "crew member")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "Jack looked so weak and non-threatening." << std::endl;
			std::cout << "But looks can be deceiving." << std::endl;
			return;
		}

		else
		{
			playerLocation->featureTwo(playerPtr);
			return;
		}
	}

	if (commands[0] == "look" && commands[1] == "at" && commands[2] == "medical supplies")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "The medical supplies have been reduced to some opened boxes of bandages, gauze, and used alcohol swabs which you used to clean your wounds." << std::endl;
			return;
		}

		else
		{
			std::cout << "The medical supplies have not been used yet." << std::endl;
			std::cout << "They can be used to clean and dress your wounds." << std::endl;
			return;
		}

	}

	if (commands[0] == "look" && commands[1] == "at")
	{
		lookAt(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "room")
	{
		/*Asks pointer to get name*/
		std::cout << "CURRENT ROOM: " << playerLocation->getName() << std::endl;
		return;
	}

	if (commands[0] == "current" && commands[2] == "room")
	{
		std::cout << "You are in the Sick Bay." << std::endl;
		mapSickBay();
		return;
	}

	/*calls helper go function with playerLocation pointer, list of rooms and room number to go to.*/

	if (commands[0] == "go" && commands[1] == "to" && commands[2] == "hallway1")
	{
		go(playerLocation, roomList, 1, playerPtr);
		return;
	}

	if (commands[0] == "go" && commands[1] == "to" &&commands[2] == "crew member")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "Although he was violent and attacked you in your prior encounter with him, you approach Jack again." << std::endl;
			std::cout << "Your efforts are rewarded this time with tentacles popping out of Jack's hands and wrapping around your neck." << std::endl;
			std::cout << "You lose conciousness before Jack's face morphes in a gaping maw of teeth that bites your head off." << std::endl;
			playerPtr->setAlive(0);
			return;
		}

		if (playerLocation->getFeatureOneHap() == 0)
		{
			playerLocation->featureTwo(playerPtr);
			return;
		}
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

	std::cout << "You can't do that here." << std::endl;
	return;
}

void roomInteractionRadioRoom(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList, Parser* parserPtr)
{
	if (commands[0] == "savegame" || commands[0] == "loadgame")
	{
		return;
	}
	/*phrase for looking at room inventory*/
	if (commands[0] == "look" && commands[1] == "for" && commands[2] == "booze")
	{
		std::cout << "You start looking for booze and notice..." << std::endl;
		std::string freeBooze = "beer";

		if (playerLocation->checkItem(freeBooze) != 999)
		{
			std::cout << "You notice a cold one beside the radio equipment." << std::endl;
			std::cout << "It has MacReady's name on it with a message taped to it." << std::endl;
			std::cout << "'Don't drink my beer -RJ' it reads." << std::endl;
			std::cout << "For all you know, MacReady may not be around anymore." << std::endl;
			std::cout << "After checking the room for booze, you also notice some other potentially useful items." << std::endl;

		}

		playerLocation->itemsInRoom();
		return;
	}

	if ((commands[0] == "use" && commands[2] == "blood test") || (commands[0] == "look" && commands[1] == "at" && commands[2] == "blood"))
	{
		std::cout << "Now is not the time to do a blood test." << std::endl;
		std::cout << "You are in the Radio Room by yourself." << std::endl;
		std::cout << "No need to test your own blodo." << std::endl;
		return;
	}

	if (commands[0] == "talk" && commands[1] == "on" && commands[2] == "radio")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "It wasn't working well anyway." << std::endl;
			std::cout << "At least you have some copper wire for you troubles." << std::endl;
			return;
		}

		if (playerLocation->getFeatureOneHap() == 0)
		{
			playerLocation->featureOne(playerPtr);
			return;
		}
	}

	if (commands[0] == "talk" && commands[1] == "on" && commands[2] == "military radio")
	{
		playerLocation->featureTwo(playerPtr);
	}


	if (commands[0] == "drink")
	{
		drink(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "smell" && commands[1] == "the" && commands[2] == "civilian radio")
	{
		std::cout << "It doesn't really smell like much of anything." << std::endl;
		return;
	}

	if (commands[0] == "smell" && commands[1] == "the" && commands[2] == "military radio")
	{
		std::cout << "It doesn't really smell like much of anything." << std::endl;
		return;
	}

	if (commands[0] == "drop")
	{
		drop(commands, playerLocation, playerPtr, roomList, 2);
		return;
	}

	if (commands[0] == "attack" && commands[1] == "the" && commands[2] == "civilian radio")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "Why are you going to take your frustration out on inanimate objects today?" << std::endl;
			std::cout << "Is all that violence really necessary?" << std::endl;
			return;
		}

		else
		{
			std::cout << "Before you attack the radio, why don't you try using it first?" << std::endl;
			return;
		}
	}

	if (commands[0] == "attack" && commands[1] == "the" && commands[2] == "military radio")
	{
		std::cout << "You make a fist to punch the radio, but then think better of it." << std::endl;
		std::cout << "It is after all a radio for contacting the military." << std::endl;
		std::cout << "You aren't sure if there is some law you would be breaking for attacking equipment used to contact the military." << std::endl;
		return;
	}

	if ((commands[0] == "eat" && commands[1] == "the" && commands[2] == "civilian radio") || (commands[0] == "eat" && commands[1] =="the" && commands[2] =="military radio"))
	{
		std::cout << "You remember reading about some guy in the Guinness Book of Records who ate metal and glass object and even a plane." << std::endl;
		std::cout << "You look at the radio and decide you don't have the intenstinal fortitude to do such feats of stupidity." << std::endl;
		return;
	}

	if (commands[0] == "eat")
	{
		eat(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "use" && commands[1] == "the" && commands[2] == "civilian radio")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "You already did that.  At least you got the copperwire for your troubles." << std::endl;
			return;
		}

		if (playerLocation->getFeatureOneHap() == 0)
		{
			playerLocation->featureOne(playerPtr);
			return;
		}
	}

	if (commands[0] == "use" && commands[1] == "the" && commands[2] == "military radio")
	{
		playerLocation->featureTwo(playerPtr);
		return;
	}

	if (commands[0] == "jump" && commands[1] == "on" && commands[2] == "civilian radio")
	{
		std::cout << "You decide to climb up on the desk and jump on the radio." << std::endl;
		std::cout << "You fall off the desk and do a face plant on the floor." << std::endl;
		std::cout << "You suffer a slight concussion." << std::endl;
		playerPtr->gritHit(1);
		return;
	}


	if (commands[0] == "jump" && commands[1] == "on" && commands[2] == "military radio")
	{
		std::cout << "You reconsider jumping on the equipment used to contact the military." << std::endl;
		return;
	}

	if (commands[0] == "flee" &&commands[1] == "from" &&commands[2] == "civilian radio")
	{

		std::cout << "You don't need to be afraid of the radio." << std::endl;
		std::cout << "It won't bite." << std::endl;
		return;
	}

	if (commands[0] == "flee" &&commands[1] == "from" &&commands[2] == "military radio")
	{

		std::cout << "You don't need to be afraid of the radio." << std::endl;
		std::cout << "It won't bite." << std::endl;
		return;
	}


	if (commands[0] == "break" && commands[1] == "the" && commands[2] == "civilian radio")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "You can't do that again." << std::endl;
			return;
		}

		if (playerLocation->getFeatureOneHap() == 0)
		{
			std::cout << "Before you break it, try using it first." << std::endl;
			return;
		}
	}

	if (commands[0] == "break" && commands[1] == "the" && commands[2] == "military radio")
	{
		std::cout << "You decide against breaking the radio used to contact the military." << std::endl;
		std::cout << "What if you need to use it later?" << std::endl;
		return;
	}

	if (commands[0] == "look" && commands[1] == "" && commands[2] == "")
	{
		std::string longDescription = playerLocation->getLongDescrip();
		std::cout << longDescription << std::endl;
		return;
	}

	if (commands[0] == "look" && commands[1] == "at" && commands[2] == "civilian radio")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "It has seen better days." << std::endl;
			std::cout << "It looks like its ready for the junk heap." << std::endl;
			return;
		}

		else
		{
			std::cout << "You are curious about the radio." << std::endl;
			std::cout << "You decide to try and use it." << std::endl;
			playerLocation->featureOne(playerPtr);
			return;
		}
	}

	if (commands[0] == "look" && commands[1] == "at" && commands[2] == "military radio")
	{
		std::cout << "This radio is newer than the civilian radio." << std::endl;
		return;

	}

	if (commands[0] == "look" && commands[1] == "at")
	{
		lookAt(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "room")
	{
		/*Asks pointer to get name*/
		std::cout << "CURRENT ROOM: " << playerLocation->getName() << std::endl;
		return;
	}

	if (commands[0] == "current" && commands[2] == "room")
	{
		std::cout << "You are in the Radio Room." << std::endl;
		mapRadioRoom();
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

	std::cout << "You can't do that here." << std::endl;
	return;
}

void roomInteractionResearchLab(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList, Parser* parserPtr)
{
	if (commands[0] == "savegame" || commands[0] == "loadgame")
	{
		return;

	}
	/*phrase for looking at room inventory*/
	if (commands[0] == "look" && commands[1] == "for" && commands[2] == "booze")
	{
		std::cout << "You start looking for booze and notice..." << std::endl;
		std::string freeBooze = "beer";

		if (playerLocation->checkItem(freeBooze) != 999)
		{
			std::cout << "You notice a bottle of beer by the computer." << std::endl;
			std::cout << "After checking the room for booze, you also notice some other potentially useful items." << std::endl;

		}

		playerLocation->itemsInRoom();
		return;
	}

	if ((commands[0] == "use" && commands[2] == "blood test") || (commands[0] == "look" && commands[1] == "at" && commands[2] == "blood"))
	{
		std::cout << "Now is not the time to do a blood test." << std::endl;
		return;
	}


	if (commands[0] == "talk" && commands[1] == "to" && commands[2] == "doctor")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "The good doctor is no more." << std::endl;
			std::cout << "He is incapable of speaking now." << std::endl;
			return;
		}

		if (playerLocation->getFeatureTwoHap() == 0)
		{
			playerLocation->featureTwo(playerPtr);
			return;
		}
	}

	if (commands[0] == "talk" && commands[1] == "to" && commands[2] == "computer")
	{
		std::cout << "Although this computer is more sophisticated than Macready's, it is not voice activated." << std::endl;
		std::cout << "You'll have to use it like any other computer." << std::endl;
		return;
	}

	if (commands[0] == "talk" && commands[1] == "to" && commands[2] == "captain")
	{
		std::cout << "He's not going to be able to tell  you anything." << std::endl;
		std::cout << "As the saying goes, 'Dead men tell no tales.' " << std::endl;
		return;
	}

	if (commands[0] == "drink")
	{
		drink(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "smell" && commands[1] == "the" && commands[2] == "computer")
	{
		std::cout << "It doesn't smell out of the ordinary." << std::endl;
		return;
	}

	if (commands[0] == "smell" && commands[1] == "the" && commands[2] == "doctor")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "The smell of the doctor's viscera reminds you of a slaughter house." << std::endl;
			std::cout << "You might want to leave here.  You feel sick." << std::endl;
			return;
		}

		if (playerLocation->getFeatureTwoHap() == 0)
		{
			std::cout << "Before all this happened, you had always wondered what kind of fabric softener the doctor used." << std::endl;
			std::cout << "It has a slight floral scent to it." << std::endl;
			std::cout << "Definitely spring fresh." << std::endl;
			std::cout << "If you survive this mess, you plan on asking the doctor." << std::endl;
			return;
		}
	}

	if (commands[0] == "drop")
	{
		drop(commands, playerLocation, playerPtr, roomList, 2);
		return;
	}

	if (commands[0] == "attack" && commands[1] == "the" && commands[2] == "computer")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "Although the computer had some disturbing news, you don't really want to attack it." << std::endl;
			std::cout << "Don't shoot the messenger as they say." << std::endl;
			return;
		}

		else
		{
			std::cout << "Before you attack the computer, why don't you try using it first?" << std::endl;
			return;
		}
	}

	if (commands[0] == "attack" && commands[1] == "the" && commands[2] == "doctor")
	{
		if (playerLocation->getFeatureTwoHap() == 0)
		{
			std::cout << "Although you are frustrated and hung over, that's no reason to take it out on the doctor." << std::endl;
			std::cout << "You decide to curb your violent tendencies and not attack the doctor." << std::endl;
			return;
		}

		else
		{
			std::cout << "You walk over to the doctor's corpse." << std::endl;
			std::cout << "'Thanks for the warning!'  You scream." << std::endl;
			std::cout << "You decide to not punch the corpse." << std::endl;
			return;

		}
	}


	if (commands[0] == "eat")
	{
		eat(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "use" && commands[1] == "the" && commands[2] == "computer")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "It doesn't seem like the simuation is going to change." << std::endl;
			std::cout << "But you decide to rerun it anyway..." << std::endl;
			playerLocation->featureOne(playerPtr);
			return;
		}

		if (playerLocation->getFeatureOneHap() == 0)
		{
			playerLocation->featureOne(playerPtr);
			return;
		}
	}

	if (commands[0] == "jump" && commands[1] == "on" && commands[2] == "doctor")
	{
		std::cout << "You decide against tackling the doctor." << std::endl;
		return;
	}


	if (commands[0] == "jump" && commands[1] == "on" && commands[2] == "computer")
	{
		std::cout << "You don't want to take the chance of breaking some pricey equipment." << std::endl;
		return;
	}

	if (commands[0] == "flee" &&commands[1] == "from" &&commands[2] == "doctor")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "You decide against fleeing from the doctor." << std::endl;
			std::cout << "Instead you check his pulse." << std::endl;
			std::cout << "He is beyond saving." << std::endl;
			return;
		}

		else
		{
			std::cout << "You see the doctor has not noticed you yet." << std::endl;
			std::cout << "You decide to leave the room quietly before he notices." << std::endl;
			std::cout << "Too late!" << std::endl;
			std::cout << "He has noticed you." << std::endl;
			std::cout << "He beckons you over." << std::endl;
			playerLocation->featureTwo(playerPtr);
			return;
		}
	}

	if (commands[0] == "flee" &&commands[1] == "from" &&commands[2] == "computer")
	{

		std::cout << "You don't need to be afraid of the computer." << std::endl;
		std::cout << "It won't bite." << std::endl;
		return;
	}


	if (commands[0] == "break" && commands[1] == "the" && commands[2] == "computer")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "So the computer simulation had some bad news." << std::endl;
			std::cout << "Breaking the computer won't make the news any better." << std::endl;
			return;
		}

		if (playerLocation->getFeatureOneHap() == 0)
		{
			std::cout << "Before you break it, try using it first." << std::endl;
			return;
		}
	}

	if (commands[0] == "break" && commands[1] == "the" && commands[2] == "doctor")
	{
		std::cout << "Not a viable option." << std::endl;
		return;
	}

	if (commands[0] == "look" && commands[1] == "" && commands[2] == "")
	{
		std::string longDescription = playerLocation->getLongDescrip();
		std::cout << longDescription << std::endl;
		return;
	}

	if (commands[0] == "look" && commands[1] == "at" && commands[2] == "doctor")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "The doctor's body is slumped over the table." << std::endl;
			return;
		}

		else
		{
			playerLocation->featureTwo(playerPtr);
			return;
		}
	}

	if (commands[0] == "look" && commands[1] == "at" && commands[2] == "computer")
	{
		playerLocation->featureOne(playerPtr);
		return;

	}

	if (commands[0] == "look" && commands[1] == "at")
	{
		lookAt(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "room")
	{
		/*Asks pointer to get name*/
		std::cout << "CURRENT ROOM: " << playerLocation->getName() << std::endl;
		return;
	}

	if (commands[0] == "current" && commands[2] == "room")
	{
		std::cout << "You are in the Research Lab." << std::endl;
		mapResearchLab();
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

	std::cout << "You can't do that here." << std::endl;
	return;
}

void roomInteractionHallway2(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList, Parser* parserPtr)
{
	if (commands[0] == "savegame" || commands[0] == "loadgame")
	{
		return;

	}
	/*phrase for looking at room inventory*/
	if (commands[0] == "look" && commands[1] == "for" && commands[2] == "booze")
	{
		std::cout << "You start looking for booze and notice..." << std::endl;
		std::string freeBooze = "beer";

		if (playerLocation->checkItem(freeBooze) != 999)
		{
			std::cout << "There is a case of beer on the floor beside Barry." << std::endl;
			std::cout << "You deduce it isn't Barry's because he is a teetotaler." << std::endl;
			std::cout << "He probably won't mind if you take one." << std::endl;
			std::cout << "After checking the room for booze, you also notice some other potentially useful items." << std::endl;

		}

		playerLocation->itemsInRoom();
		return;
	}

	if ((commands[0] == "use" && commands[2] == "blood test") || (commands[0] == "look" && commands[1] == "at" && commands[2] == "blood"))
	{
		std::cout << "Now is not the time to do a blood test." << std::endl;
		return;
	}

	if (commands[0] == "talk" && commands[1] == "to" && commands[2] == "jeff")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "He has already left." << std::endl;
			std::cout << "He seems off today." << std::endl;
			return;
		}

		if (playerLocation->getFeatureOneHap() == 0)
		{
			playerLocation->featureOne(playerPtr);
			return;
		}
	}

	if (commands[0] == "talk" && commands[1] == "to" && commands[2] == "barry")
	{
			playerLocation->featureTwo(playerPtr);
			return;

	}

	if (commands[0] == "drink")
	{
		drink(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "smell" && commands[2] == "jeff")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "If you wanted to smell him, you missed your chance." << std::endl;
			return;
		}
	
		else
		{
			std::cout << "You get in close and smell Jeff." << std::endl;
			std::cout << "Everything seems normal about his scent." << std::endl;
			std::cout << "However, he is oblivious to your strange behavior." << std::endl;
			return;
		}
	}

	if (commands[0] == "smell" && commands[2] == "barry")
	{
		std::cout << "You smell Barry." << std::endl;
		std::cout << "Since he works in the galley, he smells a little like the kitchen: a mix of vegetable soup and meatloaf with a bit of dishwater." << std::endl;
		std::cout << "Barry notices your strange behavior of sniffing him." << std::endl;
		std::cout << "He eyes you warily." << std::endl;
		return;
	}

	if (commands[0] == "drop")
	{
		drop(commands, playerLocation, playerPtr, roomList, 2);
		return;
	}

	if (commands[0] == "attack" && commands[2] == "jeff")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "You missed your chance to attack Jeff." << std::endl;
			std::cout << "He has left the room." << std::endl;
			return;
		}

		else
		{
			std::cout << "You clench your fist and cock it back to give Jeff a haymaker." << std::endl;
			std::cout << "Before it lands, his face morphs into a gaping maw of teeth." << std::endl;
			std::cout << "Your fist gets caught in this maw of teeth and is abruptly chewed off." << std::endl;
			std::cout << "The figure formerly known as Jeff approaches you to finish the job." << std::endl;
			playerPtr->setAlive(0);
			return;
		}
	}

	if (commands[0] == "attack" && commands[2] == "barry")
	{
		std::cout << "You clench your fist and cock it back to give Barry a haymaker." << std::endl;
		std::cout << "Barry is quicker and pulls out a meat cleaver and buries it into your skull." << std::endl;
		playerPtr->setAlive(0);
		return;
	}

	if ((commands[0] == "eat" && commands[2] == "barry") || (commands[0] == "eat" && commands[2] == "jeff"))
	{
		std::cout << "Look, I know it's been a few hours since you ate last." << std::endl;
		std::cout << "But that's no reason to try and eat your crew mates." << std::endl;
		std::cout << "Go to the galley or mess hall to look for food." << std::endl;
		return;
	}

	if (commands[0] == "eat")
	{
		eat(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "jump" && commands[1] == "on" && commands[2] == "jeff")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "Jeff has left." << std::endl;
			std::cout << "You missed your chance." << std::endl;
			return;
		}

		else
		{
			std::cout << "You walk up to Jeff nonchalantly." << std::endl;
			std::cout << "You resolve to tackle him." << std::endl;
			std::cout << "He is too quick for you in your hungover condition!" << std::endl;
			std::cout << "Jeff's hands become tentacles and wrap around your neck." << std::endl;
			std::cout << "You struggle to breathe, but the tentacles are too strong." << std::endl;
			std::cout << "Everything goes black." << std::endl;
			return;
		}
	}

	if (commands[0] == "jump" && commands[1] == "on" && commands[2] == "barry")
	{
	
			std::cout << "You walk up to Barry nonchalantly." << std::endl;
			std::cout << "You resolve to tackle him." << std::endl;
			std::cout << "He is too quick for you in your hungover condition!" << std::endl;
			std::cout << "He pulls out a meat tenderizer mallet and bashes you over the head with it." << std::endl;
			std::cout << "You come to and are a tied up in a chair besides Palmer." << std::endl;
			std::cout << "Macready is standing in front of you and holding a petri dish in one hand and copper wire in the other." << std::endl;
			std::cout << "Palmer begins to shake violently and morphs into an inhuman creature." << std::endl;
			std::cout << "He bursts through the ropes holding him down and attacks you." << std::endl;
			std::cout << "Everything goes black." << std::endl;
			playerPtr->setAlive(0);
			return;
	}


	if (commands[0] == "flee" &&commands[1] == "from" &&commands[2] == "jeff")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "Jeff has already left the room." << std::endl;
			std::cout << "You don't need to flee from him." << std::endl;
			return;
		}

		else
		{
			std::cout << "Jeff didn't seem to notice you at first, but your sprinting away from him has made you quite noticeable." << std::endl;
			std::cout << "He gives chase and tackles you to the ground." << std::endl;
			std::cout << "His face melts away into a huge mouth." << std::endl;
			std::cout << "It closes around you and everything goes black." << std::endl;
			playerPtr->setAlive(0);
			return;
		}
	}

	if (commands[0] == "flee" &&commands[1] == "from" &&commands[2] == "barry")
	{

		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "Jeff has already left the room." << std::endl;
			std::cout << "You don't need to flee from him." << std::endl;
			return;
		}

		else
		{
			std::cout << "Jeff didn't seem to notice you at first, but your sprinting away from Barry has made you quite noticeable." << std::endl;
			std::cout << "He gives chase and tackles you to the ground." << std::endl;
			std::cout << "His face melts away into a huge mouth." << std::endl;
			std::cout << "It closes around you and everything goes black." << std::endl;
			playerPtr->setAlive(0);
			return;
		}
	}


	if (commands[0] == "break" && commands[2] == "jeff")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "He has already left the hallway." << std::endl;
			std::cout << "You missed your chance." << std::endl;
			return;
		}

		else
		{
			std::cout << "You walk up to Jeff nonchalantly." << std::endl;
			std::cout << "You resolve to break his face for him." << std::endl;
			std::cout << "He is too quick for you in your hungover condition!" << std::endl;
			std::cout << "Jeff's hands become tentacles and wrap around your neck." << std::endl;
			std::cout << "You struggle to breathe, but the tentacles are too strong." << std::endl;
			std::cout << "Everything goes black." << std::endl;
			playerPtr->setAlive(0);
			return;
		}
	}

	if (commands[0] == "break" && commands[2] == "barry")
	{
		std::cout << "You walk up to Barry nonchalantly." << std::endl;
		std::cout << "You resolve to break his face for him." << std::endl;
		std::cout << "He is too quick for you in your hungover condition!" << std::endl;
		std::cout << "He pulls out a meat tenderizer mallet and bashes you over the head with it." << std::endl;
		std::cout << "You come to and are a tied up in a chair besides Palmer." << std::endl;
		std::cout << "Macready is standing in front of you and holding a petri dish in one hand and copper wire in the other." << std::endl;
		std::cout << "Palmer begins to shake violently and morphs into an inhuman creature." << std::endl;
		std::cout << "He bursts through the ropes holding him down and attacks you." << std::endl;
		std::cout << "Everything goes black." << std::endl;
		playerPtr->setAlive(0);
		return;
	}

	if (commands[0] == "look" && commands[1] == "" && commands[2] == "")
	{
		std::string longDescription = playerLocation->getLongDescrip();
		std::cout << longDescription << std::endl;
		return;
	}

	if (commands[0] == "look" && commands[1] == "at" && commands[2] == "barry")
	{
		std::cout << "Barry appears to be quite worried." << std::endl;
		std::cout << "You can't blame him." << std::endl;
		std::cout << "You feel the same way." << std::endl;
		return;
	}

	if (commands[0] == "look" && commands[1] == "at" && commands[2] == "Jeff")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "He has already left the hallway." << std::endl;
			std::cout << "You missed your chance for a second look." << std::endl;
			return;
		}

		else
		{
			std::cout << "His appearance is the same as the Jeff you know." << std::endl;
			std::cout << "But there is something off about his demeanor." << std::endl;
			std::cout << "Something you can't quite put your finger on." << std::endl;
			return;
		}

	}

	if (commands[0] == "look" && commands[1] == "at")
	{
		lookAt(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "room")
	{
		/*Asks pointer to get name*/
		std::cout << "CURRENT ROOM: " << playerLocation->getName() << std::endl;
		return;
	}

	if (commands[0] == "current" && commands[2] == "room")
	{
		std::cout << "You are in Hallway 2." << std::endl;
		mapHallway2();
		return;
	}

	/*calls helper go function with playerLocation pointer, list of rooms and room number to go to.*/

	if (commands[0] == "go" && commands[1] == "to" && commands[2] == "hallway1")
	{
		go(playerLocation, roomList, 1, playerPtr);
		return;
	}

	if ((commands[0] == "go" && commands[1] == "to" && commands[2] == "mess hall") || (commands[0] == "go" && commands[1] == "to" && commands[2] == "messhall"))
	{
		go(playerLocation, roomList, 8, playerPtr);
		return;
	}

	if (commands[0] == "go" && commands[1] == "to" && commands[2] == "garage")
	{
		go(playerLocation, roomList, 10, playerPtr);
		return;
	}

	if ((commands[0] == "go" && commands[1] == "to" && commands[2] == "dog kennel") || (commands[0] == "go" && commands[1] == "to" && commands[2] == "dogkennel"))
	{
		go(playerLocation, roomList, 12, playerPtr);
		return;
	}

	if (commands[0] == "go" && commands[1] == "to" && commands[2] == "basement")
	{
		go(playerLocation, roomList, 13, playerPtr);
		return;
	}

	if ((commands[0] == "go" && commands[1] == "to" && commands[2] == "conference room") || (commands[0] == "go" && commands[1] == "to" && commands[2] == "conferenceroom"))
	{
		go(playerLocation, roomList, 14, playerPtr);
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

	std::cout << "You can't do that here." << std::endl;
	return;
}

void roomInteractionMessHall(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList, Parser* parserPtr)
{
	if (commands[0] == "savegame" || commands[0] == "loadgame")
	{
		return;

	}
	/*phrase for looking at room inventory*/
	if (commands[0] == "look" && commands[1] == "for" && commands[2] == "booze")
	{
		std::cout << "You start looking for booze and notice..." << std::endl;
		std::string freeBooze = "beer";

		if (playerLocation->checkItem(freeBooze) != 999)
		{
			std::cout << "You notice a bottle of beer all alone on a table." << std::endl;
			std::cout << "It looks lonely." << std::endl;
			std::cout << "Maybe you should take it with you and give it a good home." << std::endl;
			std::cout << "After checking the room for booze, you also notice some other potentially useful items." << std::endl;

		}

		playerLocation->itemsInRoom();
		return;
	}

	if ((commands[0] == "use" && commands[2] == "blood test") || (commands[0] == "look" && commands[1] == "at" && commands[2] == "blood"))
	{
		std::cout << "Now is not the time to do a blood test." << std::endl;
		std::cout << "You are in the Mess Hall by yourself." << std::endl;
		std::cout << "No need to test your own blood." << std::endl;
		return;
	}


	if (commands[0] == "talk")
	{
		std::cout << "There is no one here in the mess hall." << std::endl;
		std::cout << "Therefore, talking is pointless." << std::endl;
		return;
	}

	if (commands[0] == "drink" && commands[2] == "booze")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "It was just a bitter disappointment." << std::endl;
			return;
		}
		else
		{
			std::cout << "You decide to get closer to drink from the bottle." << std::endl;
			playerLocation->featureTwo(playerPtr);
			return;
		}
	}

	if (commands[0] == "drink")
	{
		drink(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "smell" && commands[2] == "meal")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "It was a semi-warm plate of spaghetti." << std::endl;
			std::cout << "It hit the spot though." << std::endl;
			return;
		}

		else
		{
			std::cout << "You smell basil, oregano, onions, and garlic." << std::endl;
			std::cout << "You get closer to investigate futher." << std::endl;
			playerLocation->featureOne(playerPtr);
			return;
		}
	}

	if (commands[0] == "smell" && commands[2] == "booze")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "There isn't any point in doing that." << std::endl;
			return;
		}
		else
		{
			std::cout << "You decide to get closer to sniff the bottle further." << std::endl;
			playerLocation->featureTwo(playerPtr);
			return;
		}
	}

	if (commands[0] == "drop")
	{
		drop(commands, playerLocation, playerPtr, roomList, 2);
		return;
	}

	if (commands[0] == "attack" && commands[2] == "meal")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "You already attacked that harmless plate of spaghetti." << std::endl;
			return;
		}

		else
		{
			std::cout << "You decide you are going to attack the untouched meal with gusto." << std::endl;
			playerLocation->featureOne(playerPtr);
			return;
		}
	}

	if (commands[0] == "attack" && commands[2] == "booze")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "That was just bitter disappointment." << std::endl;
			return;
		}

		else
		{
			std::cout << "You decide you are going to attack that bottle of booze with gusto and swig it all down." << std::endl;
			playerLocation->featureTwo(playerPtr);
			return;
		}
	}

	if (commands[0] == "eat" && commands[2] == "meal")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "You already attacked that harmless plate of spaghetti." << std::endl;
			return;
		}

		else
		{
			std::cout << "You decide you are going to eat the untouched meal." << std::endl;
			playerLocation->featureOne(playerPtr);
			return;
		}
	}

	if (commands[0] == "eat")
	{
		eat(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "jump" && commands[1] == "on" && commands[2] == "meal")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "That just won't be helpful at this time." << std::endl;
			return;
		}

		else
		{
			std::cout << "As you are hungry, you refrain from jumping on the plate of food." << std::endl;
			return;
		}
	}

	if (commands[0] == "jump" && commands[1] == "on" && commands[2] == "booze")
	{
		std::cout << "You decide against it." << std::endl;
		return;
	}


	if (commands[0] == "flee")
	{
		std::cout << "What are you going to run away from here in the mess hall?" << std::endl;
		std::cout << "There is no one and nothing to flee from." << std::endl;
		return;
	}

	if (commands[0] == "break")
	{
		std::cout << "What did it ever do to you?" << std::endl;
		return;
	}

	if (commands[0] == "look" && commands[1] == "" && commands[2] == "")
	{
		std::string longDescription = playerLocation->getLongDescrip();
		std::cout << longDescription << std::endl;
		return;
	}

	if (commands[0] == "look" && commands[1] == "at" && commands[2] == "meal")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "It looks like spaghetti was on the menu for today." << std::endl;
			return;
		}

		else
		{
			std::cout << "You decide to approach the meal to find out what it is." << std::endl;
			playerLocation->featureOne(playerPtr);
			return;
		}
	}

	if (commands[0] == "look" && commands[1] == "at" && commands[2] == "booze")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "That was just bitter disappointment." << std::endl;
			return;
		}

		else
		{
			std::cout << "What could be in the bottle?" << std::endl;
			std::cout << "You approach the bottle to investigate further." << std::endl;
			playerLocation->featureOne(playerPtr);
			return;
		}
	}

	if (commands[0] == "look" && commands[1] == "at")
	{
		lookAt(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "room")
	{
		/*Asks pointer to get name*/
		std::cout << "CURRENT ROOM: " << playerLocation->getName() << std::endl;
		return;
	}

	if (commands[0] == "current" && commands[2] == "room")
	{
		std::cout << "You are in the Mess Hall." << std::endl;
		mapMessHall();
		return;
	}

	/*calls helper go function with playerLocation pointer, list of rooms and room number to go to.*/

	if (commands[0] == "go" && commands[1] == "to" && commands[2] == "hallway2")
	{
		go(playerLocation, roomList, 9, playerPtr);
		return;
	}

	if (commands[0] == "go" && commands[1] == "to" && commands[2] == "galley")
	{
		go(playerLocation, roomList, 11, playerPtr);
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

	std::cout << "You can't do that here." << std::endl;
	return;
}


/*New ones 2/27/2020*/
void roomInteractionGarage(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList, Parser* parserPtr)
{
	if (commands[0] == "savegame" || commands[0] == "loadgame")
	{
		return;

	}
	/*phrase for looking at room inventory*/
	if (commands[0] == "look" && commands[1] == "for" && commands[2] == "booze")
	{
		std::cout << "You start looking for booze and notice..." << std::endl;
		std::string freeBooze = "beer";

		if (playerLocation->checkItem(freeBooze) != 999)
		{
			std::cout << "You notice a bottle of beer on a tool box." << std::endl;
			std::cout << "You don't see anyone's name on it." << std::endl;
			std::cout << "After checking the room for booze, you also notice some other potentially useful items." << std::endl;

		}

		playerLocation->itemsInRoom();
		return;
	}

	if ((commands[0] == "use" && commands[2] == "blood test") || (commands[0] == "look" && commands[1] == "at" && commands[2] == "blood"))
	{
		std::cout << "Now is not the time to do a blood test." << std::endl;
		std::cout << "You are in the Garage by yourself." << std::endl;
		std::cout << "No need to test your own blood." << std::endl;
		return;
	}

	if (commands[0] == "talk")
	{
		std::cout << "There is no one here in the garage for you to speak to." << std::endl;
		std::cout << "Therefore, talking is pointless." << std::endl;
		return;
	}

	if (commands[0] == "drink")
	{
		drink(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "smell" && commands[2] == "case")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "You place your nostrils on the case and inhale deeply." << std::endl;
			std::cout << "It doesn't smell like fuel, so you are fairly certain the flaimethrower does not have a leak." << std::endl;
			return;
		}
	}

	if (commands[0] == "smell" && commands[2] == "snowmobile")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "Although the engine did not turn over, you notice the faint smell of fuel." << std::endl;
			return;
		}
		else
		{
			std::cout << "You observe a very faint smell of fuel. " << std::endl;
			std::cout << "You approach the snowmobile to investigate further." << std::endl;
			playerLocation->featureTwo(playerPtr);
			return;
		}
	}

	if (commands[0] == "drop")
	{
		drop(commands, playerLocation, playerPtr, roomList, 2);
		return;
	}

	if (commands[0] == "attack" && commands[2] == "case")
	{
		std::cout << "You slam your fists agains the case, but only cause yourself pain." << std::endl;
		std::cout << "The case is unaffected." << std::endl;
		return;
	}

	if (commands[0] == "attack" && commands[2] == "snowmobile")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "'You blasted machine!' You scream at the snowmobile.'" << std::endl;
			std::cout << "You give it a kick out of frustration." << std::endl;
			return;
		}

		else
		{
			std::cout << "That could be your only ticket out of here and to safety." << std::endl;
			std::cout << "Why not try to use it first?" << std::endl;
			return;
		}
	}

	if (commands[0] == "eat")
	{
		eat(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "use" && commands[2] == "case")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "You open the case again." << std::endl;
			return;
		}

		else
		{
			playerLocation->featureOne(playerPtr);
		}
	}

	if (commands[0] == "use" && commands[2] == "snowmobile")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "The snowmobile is not working." << std::endl;
			return;
		}

		else
		{
			playerLocation->featureTwo(playerPtr);
		}
	}


	if (commands[0] == "use" && commands[2] == "flamethrower")
	{
		if (playerPtr->checkInventory("flamethrower") == 1)
		{
			std::cout << "You decide to try out the flamethrower in the garage." << std::endl;
			std::cout << "Unfortunately, the snowmobile has a gas leak." << std::endl;
			std::cout << "You cause an explosion and blow yourself up." << std::endl;
			playerPtr->setAlive(0);
			return;
		}

	}

	if (commands[0] == "jump" && commands[1] == "on" && commands[2] == "case")
	{
		std::cout << "You jump on the case to get a better look at the room." << std::endl;
		std::cout << "You look up at the ceiling tiles and notice some one has written very faintly on the one above your head." << std::endl;
		std::cout << "It reads, 'Lo Pan was here.' " << std::endl;
		std::cout << "Who is that?" << std::endl;
		std::cout << "A member of the last crew that went back to the States?" << std::endl;
		return;

	}

	if (commands[0] == "jump" && commands[1] == "on" && commands[2] == "snowmobile")
	{
		std::cout << "You climb up on a work bench and pretend the snowmobile is a horse." << std::endl;
		std::cout << "You try jumping into the saddle like a cowboy from a movie." << std::endl;
		std::cout <<  "The handlebars knock the wind out of you and you fall to the floor." << std::endl;
		std::cout << "Enough horsing around!" << std::endl;
		return;

	}

	if (commands[0] == "flee" || commands[1] == "flee" || commands[2] == "flee")
	{
		
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "The snowmobile is not working." << std::endl;
			std::cout << "Escaping with it is not possible." << std::endl;
			return;
		}

		else
		{
			playerLocation->featureTwo(playerPtr);
			return;
		}

	}

	if (commands[0] == "break" && commands[2] == "case")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "There is no need to break it as you already opened it with the code." << std::endl;
			return;
		}

		else
		{
			std::cout << "It is too sturdy to break." << std::endl;
			std::cout << "You determine the only way to open it is with the code." << std::endl;
			
			if (playerPtr->checkInventory("toilet paper"))
			{
				playerLocation->featureOne(playerPtr);
				return;
			}
			std::cout << "You will have to look around the base for the code." << std::endl;
			return;
		}
	}

	if (commands[0] == "look" && commands[1] == "" && commands[2] == "")
	{
		std::string longDescription = playerLocation->getLongDescrip();
		std::cout << longDescription << std::endl;
		return;
	}

	if (commands[0] == "look" && commands[1] == "at" && commands[2] == "case")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "The case is now empty." << std::endl;
			return;
		}

		else
		{
			std::cout << "You decide to examine the case and see about getting the flamethrower out." << std::endl;
			playerLocation->featureOne(playerPtr);
			return;
		}
	}

	if (commands[0] == "look" && commands[1] == "at")
	{
		lookAt(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "room")
	{
		/*Asks pointer to get name*/
		std::cout << "CURRENT ROOM: " << playerLocation->getName() << std::endl;
		return;
	}

	if (commands[0] == "current" && commands[2] == "room")
	{
		std::cout << "You are in the Garage." << std::endl;
		mapGarage();
		return;
	}

	/*calls helper go function with playerLocation pointer, list of rooms and room number to go to.*/

	if (commands[0] == "go" && commands[1] == "to" && commands[2] == "hallway2")
	{
		go(playerLocation, roomList, 9, playerPtr);
		return;
	}

	if (commands[0] == "take" && commands[2] == "flamethrower")
	{
		if (playerLocation->getFeatureOneHap() == 1 && playerPtr->checkInventory("flamethrower")==1)
		{
			std::cout << "You already took the flamethrower." << std::endl;
			return;
		}

		if (playerLocation->getFeatureOneHap() == 1 && playerPtr->checkInventory("flamethrower") == 0)
		{
			take(commands, playerLocation, playerPtr, roomList, 0);
			return;
		}

		else
		{
			std::cout << "You decide to examine the case and see about getting the flamethrower out." << std::endl;
			playerLocation->featureOne(playerPtr);
			return;
		}
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

	std::cout << "You can't do that here." << std::endl;
	return;
}

void roomInteractionGalley(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList, Parser* parserPtr)
{
	if (commands[0] == "savegame" || commands[0] == "loadgame")
	{
		return;

	}
	/*phrase for looking at room inventory*/
	if (commands[0] == "look" && commands[1] == "for" && commands[2] == "booze")
	{
		std::cout << "You start looking for booze and notice..." << std::endl;
		std::string freeBooze = "beer";

		if (playerLocation->checkItem(freeBooze) != 999)
		{
			std::cout << "You notice a bottle of beer on a counter." << std::endl;
			std::cout << "After checking the room for booze, you also notice some other potentially useful items." << std::endl;
		}

		playerLocation->itemsInRoom();
		return;
	}

	if ((commands[0] == "use" && commands[2] == "blood test") || (commands[0] == "look" && commands[1] == "at" && commands[2] == "blood"))
	{
		std::cout << "Now is not the time to do a blood test." << std::endl;
		std::cout << "You are in the Galley by yourself." << std::endl;
		std::cout << "No need to test your own blood." << std::endl;
		return;
	}

	if (commands[0] == "talk")
	{
		std::cout << "There is no one here in the mess hall." << std::endl;
		std::cout << "Therefore, talking is pointless." << std::endl;
		return;
	}

	if (commands[0] == "drink")
	{
		drink(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "smell" && commands[2] == "counter")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "You've determined the foul odor is not coming from the counter." << std::endl;
			std::cout << "It just had a can of sea food." << std::endl;
			return;
		}

		else
		{
			std::cout << "You are not sure if the bad smell is from the counter or not." << std::endl;
			std::cout << "You decide to get closer for a better whiff." << std::endl;
			playerLocation->featureOne(playerPtr);
			return;
		}
	}

	if (commands[0] == "smell" && commands[2] == "odor")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "You've already determined the bad smell is just rotting leftovers." << std::endl;

			return;
		}
		else
		{
			std::cout << "You decide to investigate the odor more closely." << std::endl;
			playerLocation->featureTwo(playerPtr);
			return;
		}
	}

	if (commands[0] == "drop")
	{
		drop(commands, playerLocation, playerPtr, roomList, 2);
		return;
	}

	if (commands[0] == "attack" && commands[2] == "counter")
	{
		std::cout << "The counter does not look threatening to warrant an attack." << std::endl;
		return;
	}

	if (commands[0] == "attack" && commands[2] == "odor")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "It was just rotting leftovers." << std::endl;
			std::cout << "You decide against eating them." << std::endl;
			return;
		}

		else
		{
			std::cout << "You aren't sure what the smell is, so you go in its direction to investigate." << std::endl;
			std::cout << "Stay frosty." << std::endl;
			playerLocation->featureTwo(playerPtr);
			return;
		}
	}



	if (commands[0] == "eat")
	{
		eat(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "jump" && commands[1] == "on" && commands[2] == "counter")
	{
		std::cout << "You jump on the counter to get a better look at the room." << std::endl;
		std::cout << "You look up at the ceiling tiles and notice some one has written very faintly on the one above your head." << std::endl;
		std::cout << "It reads, 'Jack Burton was here.' " << std::endl;
		std::cout << "Who is that?" << std::endl;
		std::cout << "A member of the last crew that went back to the States?" << std::endl;
		return;

	}


	if (commands[0] == "flee")
	{
		std::cout << "What are you going to run away from here in the Galley?" << std::endl;
		std::cout << "Like a chicken, you run back to the mess hall." << std::endl;
		go(playerLocation, roomList, 8, playerPtr);
		return;
	}

	if (commands[0] == "break")
	{
		std::cout << "What did it ever do to you?" << std::endl;
		return;
	}

	if (commands[0] == "look" && commands[1] == "" && commands[2] == "")
	{
		std::string longDescription = playerLocation->getLongDescrip();
		std::cout << longDescription << std::endl;
		return;
	}

	if (commands[0] == "look" && commands[1] == "at" && commands[2] == "counter")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "The counter has nice marble surface." << std::endl;
			return;
		}

		else
		{
			std::cout << "You decide to excamine the counter more closely." << std::endl;
			playerLocation->featureOne(playerPtr);
			return;
		}
	}



	if (commands[0] == "look" && commands[1] == "at")
	{
		lookAt(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "room")
	{
		/*Asks pointer to get name*/
		std::cout << "CURRENT ROOM: " << playerLocation->getName() << std::endl;
		return;
	}

	if (commands[0] == "current" && commands[2] == "room")
	{
		std::cout << "You are in the Galley." << std::endl;
		mapGalley();
		return;
	}

	/*calls helper go function with playerLocation pointer, list of rooms and room number to go to.*/

	if (commands[0] == "go" && commands[1] == "to" && commands[2] == "mess hall")
	{
		go(playerLocation, roomList, 8, playerPtr);
		return;
	}

	if (commands[0] == "go" && commands[1] == "to" && commands[2] == "odor")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "It was just rotting leftovers." << std::endl;
			std::cout << "You decide against eating them." << std::endl;
			return;
		}

		else
		{
			std::cout << "You aren't sure what the smell is, so you go in its direction to investigate." << std::endl;
			std::cout << "Stay frosty." << std::endl;
			playerLocation->featureTwo(playerPtr);
			return;
		}
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

	std::cout << "You can't do that here." << std::endl;
	return;
}

void roomInteractionDogKennel(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList, Parser* parserPtr)
{
	if (commands[0] == "savegame" || commands[0] == "loadgame")
	{
		return;

	}
	/*phrase for looking at room inventory*/
	if (commands[0] == "look" && commands[1] == "for" && commands[2] == "booze")
	{
		std::cout << "You start looking for booze and notice..." << std::endl;
		std::string freeBooze = "beer";

		if (playerLocation->checkItem(freeBooze) != 999)
		{
			std::cout << "You notice a bottle of beer on a shelf." << std::endl;
			std::cout << "After checking the room for booze, you also notice some other potentially useful items." << std::endl;


		}

		playerLocation->itemsInRoom();
		return;
	}

	if ((commands[0] == "use" && commands[2] == "blood test") || (commands[0] == "look" && commands[1] == "at" && commands[2] == "blood"))
	{
		std::cout << "Now is not the time to do a blood test." << std::endl;
		std::cout << "You are the only human in the Dog Kennel right now." << std::endl;
		return;
	}
	if (commands[0] == "talk" && commands[2] == "panting")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "Whatever that thing was, it looked like a malformed dog, it's scurried off." << std::endl;
			std::cout << "I don't think you will be able to communicate with it in a meaningful way." << std::endl;
			std::cout << "The only language it seems to understand is violence." << std::endl;
			return;
		}

		if (playerLocation->getFeatureOneHap() == 0)
		{
			std::cout << "You call out to whatever is making the panting noise." << std::endl;
			std::cout << "You receive no response." << std::endl;
			return;
		}

	}

	if (commands[0] == "drink")
	{
		drink(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "smell" && commands[2] == "panting")
	{
		std::cout << "The dog kennel smells the same as it always does." << std::endl;
		std::cout << "A bit like mildew and a bit like dog hair." << std::endl;
		return;
	}

	if (commands[0] == "smell" && commands[2] == "shimmering")
	{
		std::cout << "It is not producing any distinctive smell." << std::endl;
		return;
	}

	if (commands[0] == "drop")
	{
		drop(commands, playerLocation, playerPtr, roomList, 2);
		return;
	}

	if (commands[0] == "attack" && commands[2] == "panting")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "Whatever that thing was, you don't want to tangle with it again." << std::endl;
			std::cout << "You reconsider attacking it." << std::endl;
			return;
		}

		if (playerLocation->getFeatureOneHap() == 0)
		{
			std::cout << "You decide you are going to attack whatever is making that panting sound." << std::endl;
			std::cout << "Get them before they get you!" << std::endl;
			playerLocation->featureOne(playerPtr);

			return;
		}
	}

	if (commands[0] == "attack" && commands[2] == "shimmering")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "Petri dishes cannot hurt you." << std::endl;
			return;
		}

		if (playerLocation->getFeatureOneHap() == 0)
		{
			std::cout << "Whatever is shimmering, it looks like an inanimate object." << std::endl;
			std::cout << "It just doesn't make sent to attack it." << std::endl;
			return;
		}
	}

	if (commands[0] == "eat")
	{
		eat(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "jump" && commands[1] == "on" && commands[2] == "panting")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "Whatever that thing was, you don't want to tangle with it again." << std::endl;
			std::cout << "You reconsider attacking it." << std::endl;
			std::cout << "You don't think you can get the jump on it now." << std::endl;
			return;
		}

		if (playerLocation->getFeatureOneHap() == 0)
		{
			std::cout << "You decide you are going to tackle whatever is making that panting sound." << std::endl;
			std::cout << "Time to take out the trash and kick some tail!" << std::endl;
			playerLocation->featureOne(playerPtr);

			return;
		}
	}

	if (commands[0] == "jump" && commands[2] == "shimmering")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "You already retrieved it." << std::endl;
			return;
		}

		if (playerLocation->getFeatureTwoHap() == 0)
		{
			std::cout << "You aren't sure if you can reach it by jumping." << std::endl;
			playerLocation->featureTwo(playerPtr);
			return;
		}
	}

	if (commands[0] == "flee" && commands[2] == "panting")
	{

		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "You decide you don't want to be in the same room with whatever just attacked you." << std::endl;
			std::cout << "You make a run for Hallway 2 ." << std::endl;
			go(playerLocation, roomList, 9, playerPtr);
			return;
		}

		else
		{
			std::cout << "Whatever is panting is freaking you out." << std::endl;
			std::cout << "You make a run for Hallway 2 ." << std::endl;
			go(playerLocation, roomList, 9, playerPtr);
			return;
		}

	}

	if (commands[0] == "break" && commands[2] == "shimmmering")
	{
		std::cout << "Before you break it, maybe you should get a better look at it." << std::endl;
		return;
	}



	if (commands[0] == "look" && commands[1] == "" && commands[2] == "")
	{
		std::string longDescription = playerLocation->getLongDescrip();
		std::cout << longDescription << std::endl;
		return;
	}

	if (commands[0] == "look" && commands[1] == "at" && commands[2] == "panting")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "You could not bear to look at it again." << std::endl;
			std::cout << "It's real nightmare fuel." << std::endl;
			return;
		}

		else
		{
			playerLocation->featureOne(playerPtr);
			return;
		}
	}

	if (commands[0] == "look" && commands[1] == "at" && commands[2] == "shimmering")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "You already picked it up." << std::endl;
			std::cout << "It was a petri dish." << std::endl;
			return;
		}

		else
		{
			playerLocation->featureTwo(playerPtr);
			return;
		}
	}

	if (commands[0] == "use" && commands[2] == "shimmering")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "You already picked it up." << std::endl;
			std::cout << "You can't use it here." << std::endl;
			return;
		}

		else
		{
			std::cout << "To use it, you need to get it first." << std::endl;
			playerLocation->featureTwo(playerPtr);
			return;
		}
	}


	if (commands[0] == "look" && commands[1] == "at")
	{
		lookAt(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "go" && commands[2] == "hallway2")
	{
		go(playerLocation, roomList, 9, playerPtr);
		return;
	}

	if (commands[0] == "room")
	{
		/*Asks pointer to get name*/
		std::cout << "CURRENT ROOM: " << playerLocation->getName() << std::endl;
		return;
	}

	if (commands[0] == "current" && commands[2] == "room")
	{
		std::cout << "You are in the Dog Kennel." << std::endl;
		mapDogKennel();
		return;
	}

	/*calls helper go function with playerLocation pointer, list of rooms and room number to go to.*/

	if (commands[0] == "take" && commands[2] == "shimmering")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "You already took it." << std::endl;
			return;
		}

		else
		{
			playerLocation->featureTwo(playerPtr);
		}
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

	std::cout << "You can't do that here." << std::endl;
	return;
}

void roomInteractionBasement(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList, Parser* parserPtr)
{
	if (commands[0] == "savegame" || commands[0] == "loadgame")
	{
		return;

	}
	/*phrase for looking at room inventory*/
	if (commands[0] == "look" && commands[1] == "for" && commands[2] == "booze")
	{
		std::cout << "You start looking for booze and notice..." << std::endl;
		playerLocation->itemsInRoom();
		return;
	}

	if ((commands[0] == "talk" && commands[2] == "figure" && playerPtr->getDrOutcome() == 0) || (commands[0] == "talk" && commands[2] == "hunched" && playerPtr->getDrOutcome() == 0)
		|| (commands[0] == "talk" && commands[2] == "thing" && playerPtr->getDrOutcome() == 0) || (commands[0] == "talk" && commands[2] == "shape"&& playerPtr->getDrOutcome() == 0)
		|| (commands[0] == "talk" && commands[2] == "doctor"&& playerPtr->getDrOutcome() == 0) || (commands[0] == "talk" && commands[2] == "person"&& playerPtr->getDrOutcome() == 0)
		|| (commands[0] == "talk" && commands[2] == "blair"&& playerPtr->getDrOutcome() == 0))
	{
		playerLocation->featureOne(playerPtr);
		return;
	}

	if ((commands[0] == "talk" && commands[2] == "figure" && playerPtr->getDrOutcome() == 1) || (commands[0] == "talk" && commands[2] == "hunched" && playerPtr->getDrOutcome() == 1)
		|| (commands[0] == "talk" && commands[2] == "thing" && playerPtr->getDrOutcome() == 1) || (commands[0] == "talk" && commands[2] == "shape"&& playerPtr->getDrOutcome() == 1)
		|| (commands[0] == "talk" && commands[2] == "doctor"&& playerPtr->getDrOutcome() == 1) || (commands[0] == "talk" && commands[2] == "person"&& playerPtr->getDrOutcome() == 1)
		|| (commands[0] == "talk" && commands[2] == "blair"&& playerPtr->getDrOutcome() == 1))
	{
		std::cout << "After your talk with the doctor, you feel assured that he is at least mostly ok." << std::endl;
		std::cout << "You decide to leave him to his business." << std::endl;
		return;
	}

	if ((commands[0] == "talk" && commands[2] == "figure" && playerPtr->getDrOutcome() == 2) || (commands[0] == "talk" && commands[2] == "hunched" && playerPtr->getDrOutcome() == 2)
		|| (commands[0] == "talk" && commands[2] == "thing" && playerPtr->getDrOutcome() == 2) || (commands[0] == "talk" && commands[2] == "shape"&& playerPtr->getDrOutcome() == 2)
		|| (commands[0] == "talk" && commands[2] == "doctor"&& playerPtr->getDrOutcome() == 2) || (commands[0] == "talk" && commands[2] == "person"&& playerPtr->getDrOutcome() == 2)
		|| (commands[0] == "talk" && commands[2] == "blair"&& playerPtr->getDrOutcome() == 2))
	{
		std::cout << "The doctor shot you and ran off." << std::endl;
		std::cout << "What are you going to talk to him about? " << std::endl;
		std::cout << "'Why did you shoot me, Doc?'" << std::endl;
		return;
	}

	if ((commands[0] == "talk" && commands[2] == "figure" && playerPtr->getDrOutcome() > 2 && playerPtr->getDrOutcome() < 6) ||
		(commands[0] == "talk" && commands[2] == "hunched" && playerPtr->getDrOutcome() > 2 && playerPtr->getDrOutcome() < 6)
		|| (commands[0] == "talk" && commands[2] == "thing" && playerPtr->getDrOutcome() > 2 && playerPtr->getDrOutcome() < 6) ||
		(commands[0] == "talk" && commands[2] == "shape"&& playerPtr->getDrOutcome() > 2 && playerPtr->getDrOutcome() < 6)
		|| (commands[0] == "talk" && commands[2] == "doctor"&& playerPtr->getDrOutcome() > 2 && playerPtr->getDrOutcome() < 6) ||
		(commands[0] == "talk" && commands[2] == "person"&& playerPtr->getDrOutcome() > 2 && playerPtr->getDrOutcome() < 6)
		|| (commands[0] == "talk" && commands[2] == "blair"&& playerPtr->getDrOutcome() > 2 && playerPtr->getDrOutcome() < 6)
		)
	{
		std::cout << "The docotr is unresponsive." << std::endl;
		return;
	}

	if ((commands[0] == "talk" && commands[2] == "figure" && playerPtr->getDrOutcome() == 6) || (commands[0] == "talk" && commands[2] == "hunched" && playerPtr->getDrOutcome() == 6)
		|| (commands[0] == "talk" && commands[2] == "thing" && playerPtr->getDrOutcome() == 6) || (commands[0] == "talk" && commands[2] == "shape"&& playerPtr->getDrOutcome() == 6)
		|| (commands[0] == "talk" && commands[2] == "doctor"&& playerPtr->getDrOutcome() == 6) || (commands[0] == "talk" && commands[2] == "person"&& playerPtr->getDrOutcome() == 6)
		|| (commands[0] == "talk" && commands[2] == "blair"&& playerPtr->getDrOutcome() == 6))
	{
		std::cout << "That is a hoot and holler!" << std::endl;
		std::cout << "Whatever it was, you can't talk to it now because it is a smoldering heap of burning remains." << std::endl;
		return;
	}


	if (commands[0] == "drink")
	{
		drink(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if ((commands[0] == "smell" && commands[2] == "figure" && playerPtr->getDrOutcome() == 6) || (commands[0] == "smell" && commands[2] == "hunched" && playerPtr->getDrOutcome() == 6)
		|| (commands[0] == "smell" && commands[2] == "thing" && playerPtr->getDrOutcome() == 6) || (commands[0] == "smell" && commands[2] == "shape"&& playerPtr->getDrOutcome() == 6)
		|| (commands[0] == "smell" && commands[2] == "doctor"&& playerPtr->getDrOutcome() == 6) || (commands[0] == "smell" && commands[2] == "person"&& playerPtr->getDrOutcome() == 6)
		|| (commands[0] == "smell" && commands[2] == "blair"&& playerPtr->getDrOutcome() == 6))
	{
		std::cout << "The room is filled with a not unpleasent smell of cooked meat." << std::endl;
		std::cout << "Whatver was posing as the doctor, its species does smell appetizing when it is cooking." << std::endl;
		std::cout << "You wonder if this species could be harvested as an alternative to conventional sources of animal protein." << std::endl;
		return;
	}

	if ((commands[0] == "smell" && commands[2] == "figure" && playerPtr->getDrOutcome() == 2) || (commands[0] == "smell" && commands[2] == "hunched" && playerPtr->getDrOutcome() == 2)
		|| (commands[0] == "smell" && commands[2] == "thing" && playerPtr->getDrOutcome() == 2) || (commands[0] == "smell" && commands[2] == "shape"&& playerPtr->getDrOutcome() == 2)
		|| (commands[0] == "smell" && commands[2] == "doctor"&& playerPtr->getDrOutcome() == 2) || (commands[0] == "smell" && commands[2] == "person"&& playerPtr->getDrOutcome() == 2)
		|| (commands[0] == "smell" && commands[2] == "blair"&& playerPtr->getDrOutcome() == 2))
	{
		std::cout << "You didn't notice any bizarre smells about the guy before he shot you." << std::endl;
		std::cout << "He didn't smell drunk." << std::endl;
		return;
	}

	if ((commands[0] == "smell" && commands[2] == "figure" && playerPtr->getDrOutcome() == 0) || (commands[0] == "smell" && commands[2] == "hunched" && playerPtr->getDrOutcome() == 0)
		|| (commands[0] == "smell" && commands[2] == "thing" && playerPtr->getDrOutcome() == 0) || (commands[0] == "smell" && commands[2] == "shape"&& playerPtr->getDrOutcome() == 0)
		|| (commands[0] == "smell" && commands[2] == "doctor"&& playerPtr->getDrOutcome() == 0) || (commands[0] == "smell" && commands[2] == "person"&& playerPtr->getDrOutcome() == 0)
		|| (commands[0] == "smell" && commands[2] == "blair"&& playerPtr->getDrOutcome() == 0))
	{
		std::cout << "You start sniffing the air to check if the doctor smells different than usual." << std::endl;
		std::cout << "You notice nothing out of the ordinary about him." << std::endl;
		std::cout << "He is oblvious to your strange behavior." << std::endl;
		return;
	}

	if ((commands[0] == "smell" && commands[2] == "figure") || (commands[0] == "smell" && commands[2] == "hunched")
		|| (commands[0] == "smell" && commands[2] == "thing") || (commands[0] == "smell" && commands[2] == "shape")
		|| (commands[0] == "smell" && commands[2] == "doctor") || (commands[0] == "smell" && commands[2] == "person")
		|| (commands[0] == "smell" && commands[2] == "blair"))
	{
		std::cout << "The doctor doesn't smell like he has been drinking." << std::endl;
		std::cout << "The only alcohol you smell is the stuff on your own clothes and coming out of your own pores." << std::endl;
		return;
	}

	if (commands[0] == "drop")
	{
		drop(commands, playerLocation, playerPtr, roomList, 2);
		return;
	}

	if ((commands[0] == "attack" && commands[2] == "figure") || (commands[0] == "attack" && commands[2] == "hunched")
		|| (commands[0] == "attack" && commands[2] == "thing") || (commands[0] == "attack" && commands[2] == "shape")
		|| (commands[0] == "attack" && commands[2] == "doctor") || (commands[0] == "attack" && commands[2] == "person")
		|| (commands[0] == "attack" && commands[2] == "blair"))
	{
		std::cout << "You walk up ready with a sucker punch." << std::endl;
		std::cout << "Whatever it is, it looks like Dr. Blair, but the familiar face melts away into a maw of teeth." << std::endl;
		std::cout << "The teeth enclose around your face and you see only darkness." << std::endl;
		playerPtr->setAlive(0);
	}


	if ((commands[0] == "eat" && commands[2] == "figure" && playerPtr->getDrOutcome() == 6) || (commands[0] == "eat" && commands[2] == "hunched" && playerPtr->getDrOutcome() == 6)
		|| (commands[0] == "eat" && commands[2] == "thing" && playerPtr->getDrOutcome() == 6) || (commands[0] == "eat" && commands[2] == "shape"&& playerPtr->getDrOutcome() == 6)
		|| (commands[0] == "eat" && commands[2] == "doctor"&& playerPtr->getDrOutcome() == 6) || (commands[0] == "eat" && commands[2] == "person"&& playerPtr->getDrOutcome() == 6))
	{
		std::cout << "Smelling the burnt heap of remains, and noting no one else is around, you grab hunk of burning meat and have a few bites." << std::endl;
		std::cout << "It isn't bad." << std::endl;
		std::cout << "It could use some salt and pepper." << std::endl;
		std::cout << "And since this wasn't human, technically you are not a cannibal." << std::endl;
		std::cout << "You have the higher moral ground here." << std::endl;
		return;
	}

	if ((commands[0] == "eat" && commands[2] == "figure") || (commands[0] == "eat" && commands[2] == "hunched" && playerPtr)
		|| (commands[0] == "eat" && commands[2] == "thing") || (commands[0] == "eat" && commands[2] == "shape")
		|| (commands[0] == "eat" && commands[2] == "doctor") || (commands[0] == "eat" && commands[2] == "person")
		|| (commands[0] == "eat" && commands[2] == "blair"))
	{
		std::cout << "There is a time and place to eat." << std::endl;
		std::cout << "This isn't the right time for that right now." << std::endl;
		return;
	}

	if ((commands[0] == "jump" && commands[2] == "figure") || (commands[0] == "jump" && commands[2] == "hunched")
		|| (commands[0] == "jump" && commands[2] == "thing") || (commands[0] == "jump" && commands[2] == "shape")
		|| (commands[0] == "jump" && commands[2] == "doctor") || (commands[0] == "jump" && commands[2] == "person")
		|| (commands[0] == "jump" && commands[2] == "blair"))
	{
		std::cout << "You plan to get the jump on 'em." << std::endl;
		std::cout << "In your hungover state, you are too slow!" << std::endl;
		std::cout << "Whatever it is that you were going to jump, it looks like Dr. Blair, but the familiar face melts away into a maw of teeth." << std::endl;
		std::cout << "The teeth enclose around your face and you see only darkness." << std::endl;
		playerPtr->setAlive(0);
	}

	if ((commands[0] == "flee" && commands[2] == "figure"  && playerPtr->getDrOutcome() == 0) || (commands[0] == "flee" && commands[2] == "hunched" && playerPtr->getDrOutcome() == 0)
		|| (commands[0] == "flee" && commands[2] == "thing" &&playerPtr->getDrOutcome() == 0) || (commands[0] == "flee" && commands[2] == "shape" && playerPtr->getDrOutcome() == 0)
		|| (commands[0] == "flee" && commands[2] == "doctor" && playerPtr->getDrOutcome() == 0) || (commands[0] == "flee" && commands[2] == "person" && playerPtr->getDrOutcome() == 0)
		|| (commands[0] == "flee" && commands[2] == "blair" && playerPtr->getDrOutcome() == 0))
	{
		if (playerLocation->getFeatureTwoHap() == 0)
		{
			std::cout << "You decide to flee and face whatever that rattling noise is instead." << std::endl;
			return;
		}

		else
		{
			std::cout << "You decide to bolt and run." << std::endl;
			std::cout << "Courage isn't your strong suit." << std::endl;
			go(playerLocation, roomList, 9, playerPtr);
			return;
		}

	}

	if ((commands[0] == "flee" && commands[2] == "figure") || (commands[0] == "flee" && commands[2] == "hunched")
		|| (commands[0] == "flee" && commands[2] == "thing") || (commands[0] == "flee" && commands[2] == "shape")
		|| (commands[0] == "flee" && commands[2] == "doctor") || (commands[0] == "flee" && commands[2] == "person")
		|| (commands[0] == "flee" && commands[2] == "blair"))
	{
		if (playerLocation->getFeatureTwoHap() == 0)
		{
			std::cout << "You decide to flee and face whatever that rattling noise is instead." << std::endl;
			return;
		}

		else
		{
			std::cout << "You decide to bolt and run." << std::endl;
			std::cout << "Courage isn't your strong suit." << std::endl;
			go(playerLocation, roomList, 9, playerPtr);
			return;
		}

	}

	if ((commands[0] == "break" && commands[2] == "figure") || (commands[0] == "break" && commands[2] == "hunched")
		|| (commands[0] == "break" && commands[2] == "thing") || (commands[0] == "break" && commands[2] == "shape")
		|| (commands[0] == "break" && commands[2] == "doctor") || (commands[0] == "break" && commands[2] == "person")
		|| (commands[0] == "break" && commands[2] == "blair"))
	{
		std::cout << "You walk up ready with a sucker punch." << std::endl;
		std::cout << "Whatever it is, it looks like Dr. Blair, but the familiar face melts away into a maw of teeth." << std::endl;
		std::cout << "The teeth enclose around your face and you see only darkness." << std::endl;
		playerPtr->setAlive(0);
	}





	if (commands[0] == "look" && commands[1] == "" && commands[2] == "")
	{
		std::string longDescription = playerLocation->getLongDescrip();
		std::cout << longDescription << std::endl;
		return;
	}

	if (commands[0] == "look" && commands[1] == "at")
	{
		lookAt(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if ((commands[0] == "look" && commands[2] == "figure" && playerPtr->getDrOutcome() == 0) || (commands[0] == "look" && commands[2] == "hunched" && playerPtr->getDrOutcome() == 0)
		|| (commands[0] == "look" && commands[2] == "thing" && playerPtr->getDrOutcome() == 0) || (commands[0] == "look" && commands[2] == "shape"&& playerPtr->getDrOutcome() == 0)
		|| (commands[0] == "look" && commands[2] == "doctor"&& playerPtr->getDrOutcome() == 0) || (commands[0] == "look" && commands[2] == "person"&& playerPtr->getDrOutcome() == 0)
		|| (commands[0] == "look" && commands[2] == "blair"&& playerPtr->getDrOutcome() == 0))
	{
		playerLocation->featureOne(playerPtr);
		return;
	}

	if ((commands[0] == "look" && commands[2] == "figure" && playerPtr->getDrOutcome() == 1) || (commands[0] == "look" && commands[2] == "hunched" && playerPtr->getDrOutcome() == 1)
		|| (commands[0] == "look" && commands[2] == "thing" && playerPtr->getDrOutcome() == 1) || (commands[0] == "look" && commands[2] == "shape"&& playerPtr->getDrOutcome() == 1)
		|| (commands[0] == "look" && commands[2] == "doctor"&& playerPtr->getDrOutcome() == 1) || (commands[0] == "look" && commands[2] == "person" && playerPtr->getDrOutcome() == 1)
		|| (commands[0] == "look" && commands[2] == "blair" && playerPtr->getDrOutcome() == 1))
	{
		std::cout << "Dr. Blair seems a little distracted." << std::endl;
		std::cout << "So Dr. Blair is acting a little weird." << std::endl;
		std::cout << "He mostly answered all your stupid questions correctly." << std::endl;
		return;
	}

	if ((commands[0] == "look" && commands[2] == "figure" && playerPtr->getDrOutcome() == 2) || (commands[0] == "look" && commands[2] == "hunched" && playerPtr->getDrOutcome() == 2)
		|| (commands[0] == "look" && commands[2] == "thing" && playerPtr->getDrOutcome() == 2) || (commands[0] == "look" && commands[2] == "shape"&& playerPtr->getDrOutcome() == 2)
		|| (commands[0] == "look" && commands[2] == "doctor"&& playerPtr->getDrOutcome() == 2) || (commands[0] == "look" && commands[2] == "person"&& playerPtr->getDrOutcome() == 2)
		|| (commands[0] == "look" && commands[2] == "blair"&& playerPtr->getDrOutcome() == 2))
	{
		std::cout << "You can't get a second look at Dr. Blair." << std::endl;
		std::cout << "He shot you and ran off." << std::endl;
		return;
	}

	if ((commands[0] == "look" && commands[2] == "figure" && playerPtr->getDrOutcome() == 6) || (commands[0] == "look" && commands[2] == "hunched" && playerPtr->getDrOutcome() == 6)
		|| (commands[0] == "look" && commands[2] == "thing" && playerPtr->getDrOutcome() == 6) || (commands[0] == "look" && commands[2] == "shape"&& playerPtr->getDrOutcome() == 6)
		|| (commands[0] == "look" && commands[2] == "doctor"&& playerPtr->getDrOutcome() == 6) || (commands[0] == "look" && commands[2] == "doctor"&& playerPtr->getDrOutcome() == 6)
		|| (commands[0] == "look" && commands[2] == "blair"&& playerPtr->getDrOutcome() == 6))
	{
		std::cout << "The sight of burning remains takes you back to family cook outs and barbecues from your childhood." << std::endl;
		return;
	}

	if ((commands[0] == "look" && commands[2] == "figure") || (commands[0] == "look" && commands[2] == "hunched")
		|| (commands[0] == "look" && commands[2] == "thing") || (commands[0] == "look" && commands[2] == "shape")
		|| (commands[0] == "look" && commands[2] == "doctor") || (commands[0] == "look" && commands[2] == "person")
		|| (commands[0] == "look" && commands[2] == "blair"))
	{
		std::cout << "He looks like Dr. Blair, but you are convinced it isn't really him." << std::endl;
		return;
	}

	if ((commands[0] == "use" && commands[2] == "blood test") || (commands[0] == "look" && commands[1] == "at" && commands[2] == "blood"))
	{
		playerLocation->checkBlood(playerPtr);
	}

	if (commands[0] == "go" && commands[2] == "hallway2")
	{
		std::cout << "Whatever was making that noise isn't here right now..." << std::endl;
		go(playerLocation, roomList, 9, playerPtr);
		return;
	}

	if ((commands[0] == "talk" && commands[2] == "rattling") || (commands[0] == "talk" && commands[2] == "rattling nosie") || (commands[0] == "talk" && commands[2] == "thing")
		|| (commands[0] == "talk" && commands[2] == "creature") || (commands[0] == "talk" && commands[2] == "dog"))

	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "That thing attacked you, and now you want to have a conversation with it?" << std::endl;
			std::cout << "Bad idea." << std::endl;
			std::cout << "You stupidly go back to Hallway 2 to converse with the creature." << std::endl;
			std::cout << "Thankfully it isn't there, and you go back to the Basement." << std::endl;
			return;
		}

		else
		{
			std::cout << "You call out in the direction of the rattling noise." << std::endl;
			std::cout << "Maybe whoever made that noise can't hear you." << std::endl;
			std::cout << "So you climb the steps out of the basement." << std::endl;
			playerLocation->featureTwo(playerPtr);
			return;
		}
	}


	if ((commands[0] == "smell" && commands[2] == "rattling") || (commands[0] == "smell" && commands[2] == "rattling nosie") || (commands[0] == "smell" && commands[2] == "thing")
		|| (commands[0] == "smell" && commands[2] == "creature") || (commands[0] == "smell" && commands[2] == "dog"))
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "You decide it would be foolish to go back and try to smell the creature that attacked you." << std::endl;
			return;
		}

		else
		{
			std::cout << "You must think you are part bloodhound." << std::endl;
			std::cout << "You smell the air in the direction of the rattling noise." << std::endl;
			std::cout << "Your sense of smell is not that strong." << std::endl;
			std::cout << "You can't smell it." << std::endl;
			return;
		}
	}

	if ((commands[0] == "attack" && commands[2] == "rattling") || (commands[0] == "attack" && commands[2] == "rattling nosie") || (commands[0] == "attack" && commands[2] == "thing")
		|| (commands[0] == "attack" && commands[2] == "creature") || (commands[0] == "attack" && commands[2] == "dog"))
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "That thing attacked you, and now you want to go for round two with it?" << std::endl;
			std::cout << "Bad idea." << std::endl;
			std::cout << "You stupidly go back to Hallway 2 to attack the creature." << std::endl;
			std::cout << "The creature pounces on you and rips your head off this time." << std::endl;
			playerPtr->setAlive(0);
			return;
		}

		else
		{
			std::cout << "You are not sure what is making that noise." << std::endl;
			std::cout << "But you are convinced you are ready to tangle with it if necessary." << std::endl;
			playerLocation->featureTwo(playerPtr);
			return;
		}
	}

	if ((commands[0] == "eat" && commands[2] == "rattling") || (commands[0] == "eat" && commands[2] == "rattling nosie") || (commands[0] == "eat" && commands[2] == "thing")
		|| (commands[0] == "eat" && commands[2] == "creature") || (commands[0] == "eat" && commands[2] == "dog"))
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "That thing attacked you, and now you want to go for round two with it?" << std::endl;
			std::cout << "Bad idea." << std::endl;
			std::cout << "You stupidly go back to Hallway 2 to hunt the creature for food." << std::endl;
			std::cout << "The creature pounces on you and rips your head off this time." << std::endl;
			playerPtr->setAlive(0);
			return;
		}

		else
		{
			std::cout << "You decide you don't want to eat what was making the rattling sound." << std::endl;
			std::cout << "At least not at this time." << std::endl;
			return;
		}
	}

	if ((commands[0] == "use" && commands[2] == "rattling") || (commands[0] == "use" && commands[2] == "rattling nosie") || (commands[0] == "use" && commands[2] == "thing")
		|| (commands[0] == "use" && commands[2] == "creature") || (commands[0] == "use" && commands[2] == "dog"))
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "That thing attacked you, and now you want to go for round two with it?" << std::endl;
			std::cout << "You stupidly go back to Hallway 2 to attempt capturing the creature." << std::endl;
			std::cout << "'If I can capture the creature and train it, it may be useful,' you think." << std::endl;
			std::cout << "The creature pounces on you and rips your head off this time." << std::endl;
			playerPtr->setAlive(0);
			return;
		}

		else
		{
			std::cout << "There is no way to tell if the source of the rattling noise will be useful to you." << std::endl;
			return;
		}
	}

	if ((commands[0] == "jump" && commands[2] == "rattling") || (commands[0] == "jump" && commands[2] == "rattling nosie") || (commands[0] == "jump" && commands[2] == "thing")
		|| (commands[0] == "jump" && commands[2] == "creature") || (commands[0] == "jump" && commands[2] == "dog"))
	{

		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "That thing attacked you, and now you want to go for round two with it?" << std::endl;
			std::cout << "You stupidly go back to Hallway 2 to attempt to get the jump on the creature." << std::endl;
			std::cout << "'You want payback!" << std::endl;
			std::cout << "The creature pounces on you and rips your head off this time." << std::endl;
			playerPtr->setAlive(0);
			return;
		}

		else
		{
			std::cout << "You decide to approach whatever is making the noise cautiously." << std::endl;
			std::cout << "You want to get the jump on it." << std::endl;
			playerLocation->featureTwo(playerPtr);
			return;
		}
	}

	if ((commands[0] == "flee" && commands[2] == "rattling") || (commands[0] == "flee" && commands[2] == "rattling nosie") || (commands[0] == "flee" && commands[2] == "thing")
		|| (commands[0] == "flee" && commands[2] == "creature") || (commands[0] == "flee" && commands[2] == "dog"))
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "You being here and not in Hallway 2 is kind of like having fleed from whatever that was, isn't it?" << std::endl;
			return;
		}

		else
		{
			std::cout << "Whatever is making that noise is in Hallway 2." << std::endl;
			std::cout << "You are in the Basement." << std::endl;
			std::cout << "There really isn't a need to flee." << std::endl;
			return;
		}

	}

	if ((commands[0] == "break" && commands[2] == "rattling") || (commands[0] == "break" && commands[2] == "rattling nosie") || (commands[0] == "break" && commands[2] == "thing")
		|| (commands[0] == "break" && commands[2] == "creature") || (commands[0] == "break" && commands[2] == "dog"))
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "That thing attacked you, and now you want to go for round two with it?" << std::endl;
			std::cout << "Bad idea." << std::endl;
			std::cout << "You stupidly go back to Hallway 2 to attack the creature." << std::endl;
			std::cout << "The creature pounces on you and rips your head off this time." << std::endl;
			playerPtr->setAlive(0);
			return;
		}

		else
		{
			std::cout << "You are not sure what is making that noise." << std::endl;
			std::cout << "But you are convinced you are ready to tangle with it if necessary." << std::endl;
			playerLocation->featureTwo(playerPtr);
			return;
		}
}

	if ((commands[0] == "look at" && commands[2] == "rattling") || (commands[0] == "look at" && commands[2] == "rattling nosie") || (commands[0] == "look at" && commands[2] == "thing")
		|| (commands[0] == "look at" && commands[2] == "creature") || (commands[0] == "look at" && commands[2] == "dog"))

	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "You never want to look at that thing again." << std::endl;
			std::cout << "You decide to not go looking for it." << std::endl;
			return;
		}

		else
		{
			std::cout << "You are not sure what is making that noise." << std::endl;
			std::cout << "You plan on getting a look at it." << std::endl;
			playerLocation->featureTwo(playerPtr);
			return;
		}
	}

	if ((commands[0] == "go" && commands[2] == "rattling") || (commands[0] == "go" && commands[2] == "rattling nosie") || (commands[0] == "go" && commands[2] == "thing")
		|| (commands[0] == "go" && commands[2] == "creature") || (commands[0] == "go" && commands[2] == "dog"))
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "That thing attacked you, and now you want to go for round two with it?" << std::endl;
			std::cout << "Bad idea." << std::endl;
			std::cout << "You stupidly go back to Hallway 2 to attack the creature." << std::endl;
			std::cout << "The creature pounces on you and rips your head off this time." << std::endl;
			playerPtr->setAlive(0);
			return;
		}

		else
		{
			std::cout << "You are not sure what is making that noise." << std::endl;
			std::cout << "You choose to go to whatever is making that sound." << std::endl;
			playerLocation->featureTwo(playerPtr);
			return;
		}
	}





	if (commands[0] == "room")
	{
		/*Asks pointer to get name*/
		std::cout << "CURRENT ROOM: " << playerLocation->getName() << std::endl;
		return;
	}

	if (commands[0] == "current" && commands[2] == "room")
	{
		std::cout << "You are in the Dog Kennel." << std::endl;
		mapHallway2();
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

	if (commands[0] == "eat")
	{
		eat(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	std::cout << "You can't do that here." << std::endl;
	return;
}

void roomInteractionConferenceRoom(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList, Parser* parserPtr)
{
	if (commands[0] == "savegame" || commands[0] == "loadgame")
	{
		return;

	}
	/*phrase for looking at room inventory*/
	if (commands[0] == "look" && commands[1] == "for" && commands[2] == "booze")
	{
		std::cout << "You start looking for booze and notice..." << std::endl;
		std::string freeBooze = "beer";

		if (playerLocation->checkItem(freeBooze) != 999)
		{
			std::cout << "You notice a bottle of beer beside the projector." << std::endl;
			std::cout << "After checking the room for booze, you also notice some other potentially useful items." << std::endl;

	
		}
		

		playerLocation->itemsInRoom();
		return;
	}

	if ((commands[0] == "use" && commands[2] == "blood test") || (commands[0] == "look" && commands[1] == "at" && commands[2] == "blood"))
	{
		std::cout << "Now is not the time to do a blood test." << std::endl;
		std::cout << "You are in the Conference Room by yourself." << std::endl;
		std::cout << "No need to test your own blood." << std::endl;
		return;
	}
	if (commands[0] == "talk")
	{
		std::cout << "You call out to the room." << std::endl;
		std::cout << "No one responds to your calls." << std::endl;
		return;
	}

	if (commands[0] == "drink" && commands[2] == "booze")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "You've had enough of that cheap brand." << std::endl;
			std::cout << "You resolve to find something better." << std::endl;
			return;
		}

		else
		{
			playerLocation->featureOne(playerPtr);
			return;
		}
	}

	if (commands[0] == "drink")
	{
		drink(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "smell" && commands[2] == "booze")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "You decide you are going to smell the bottle of booze on the main table even though you already downed some." << std::endl;
			std::cout << "You are glad you drank gulped it down without savoring it." << std::endl;
			std::cout << "The smell reminds you of floor cleaner." << std::endl;
			return;
		}

		else
		{
			std::cout << "You feel too impatient for that!  Instead..." << std::endl;
			playerLocation->featureOne(playerPtr);
			return;
		}
	}

	if (commands[0] == "smell" && commands[2] == "projector")
	{
		std::cout << "You notice it has the faint smell of cigarettes." << std::endl;
		std::cout << "Some of the crew members have their own films they watch in their quarters while relaxing and smoking." << std::endl;
		return;
	}

	if (commands[0] == "drop")
	{
		drop(commands, playerLocation, playerPtr, roomList, 2);
		return;
	}

	if (commands[0] == "attack" && commands[2] == "booze")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "Although you already had a few swigs off the bottle, you decide to look for something better." << std::endl;
			return;
		}

		else
		{
			std::cout << "You feel an incredible thirst." << std::endl;
			playerLocation->featureOne(playerPtr);
			return;
		}
	}

	if (commands[0] == "attack" && commands[2] == "projector")
	{
		std::cout << "The projector is innocent of any crimes." << std::endl;
		std::cout << "You decide to not attack it." << std::endl;
		return;
	}

	if (commands[0] == "eat")
	{
		eat(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "jump" && commands[2] == "table")
	{
		std::cout << "You jump up on the table to get a better view of the room." << std::endl;
		std::cout << "You notice on the ceiling panel above your head it says, 'Wang Chi was here.' " << std::endl;
		std::cout << "You remember him from a few months ago." << std::endl;
		std::cout << "He left the base and went to San Francisco to open a restaurant." << std::endl;
		return;
	}

	if (commands[0] == "jump" && commands[2] == "projector")
	{
		std::cout << "You don't want to tackle the projector." << std::endl;
		return;
	}

	if (commands[0] == "flee")
	{
		std::cout << "You feel quite safe in the Conference Room." << std::endl;
		std::cout << "There is no one to flee from." << std::endl;
		return;

	}

	if (commands[0] == "break" && commands[2] == "table")
	{
		std::cout << "You feel frustrated and decide to break the table by giving it a karate chop." << std::endl;
			std::cout << "WHACK!" << std::endl;
			std::cout << "You have only succeeded in hurting your hand." << std::endl;
		return;
	}

	if (commands[0] == "break" && commands[2] == "projector")
	{
		std::cout << "You don't want to break the projector." << std::endl;
		std::cout << "It is one of the few things the crew members can rely on for entertainment." << std::endl;
		return;
	}

	if (commands[0] == "look" && commands[1] == "" && commands[2] == "")
	{
		std::string longDescription = playerLocation->getLongDescrip();
		std::cout << longDescription << std::endl;
		return;
	}

	if (commands[0] == "look" && commands[2] == "table")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "It is an ordinary table with the bottle of booze you drank from and some tapes." << std::endl;
			return;
		}

		else
		{
			playerLocation->featureOne(playerPtr);
			return;
		}
	}

	if (commands[0] == "look" && commands[2] == "projector")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "It is a good projector." << std::endl;
			std::cout << "It would just be nice if there was a bigger library of movies to choose from." << std::endl;
			return;
		}

		else
		{
			playerLocation->featureTwo(playerPtr);
			return;
		}
	}

	if (commands[0] == "look" && commands[2] == "tapes")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "You don't feel like watching those movies again." << std::endl;
			return;
		}

		else
		{
			playerLocation->featureTwo(playerPtr);
			return;
		}
	}

	if (commands[0] == "use" && commands[2] == "projector")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "You already watched all the tapes you could find." << std::endl;
			std::cout << "You don't want to sit through them again." << std::endl;
			return;
		}

		else
		{
			playerLocation->featureTwo(playerPtr);
			return;
		}
	}


	if (commands[0] == "look" && commands[1] == "at")
	{
		lookAt(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "go" && commands[2] == "hallway2")
	{
		go(playerLocation, roomList, 9, playerPtr);
		return;
	}

	if (commands[0] == "room")
	{
		/*Asks pointer to get name*/
		std::cout << "CURRENT ROOM: " << playerLocation->getName() << std::endl;
		return;
	}

	if (commands[0] == "current" && commands[2] == "room")
	{
		std::cout << "You are in the Conference Room." << std::endl;
		mapConferenceRoom();
		return;
	}

	/*calls helper go function with playerLocation pointer, list of rooms and room number to go to.*/

	if (commands[0] == "take" && commands[2] == "booze")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "You've had enough of it." << std::endl;
			return;
		}

		else
		{
			playerLocation->featureOne(playerPtr);
		}
	}

	if (commands[0] == "take" && commands[2] == "tapes")
	{
		std::cout << "You would rather leave the tapes in here than take them with you." << std::endl;
		return;
	}

	if (commands[0] == "take")
	{
		take(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "go" && commands[2] == "hallway2")
	{
		go(playerLocation, roomList, 14, playerPtr);
		return;
	}

	if (commands[0] == "go" && commands[2] == "projector")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "You already watched all the tapes you could find." << std::endl;
			std::cout << "You don't want to sit through them again." << std::endl;
			return;
		}

		else
		{
			playerLocation->featureTwo(playerPtr);
			return;
		}
	}

	if (commands[0] == "go" && commands[2] == "table")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "You already drank all the booze you wanted from the bottle on the table." << std::endl;
			return;
		}

		else
		{
			playerLocation->featureOne(playerPtr);
			return;
		}
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







