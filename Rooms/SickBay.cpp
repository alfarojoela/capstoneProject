/* Project Name: Capstone Project
   Class: CS 467
   Team: Team Thing- Ryan Alcorn, Joel Alfaro, Neil Gayeta
   File: SickBay.cpp
   Description: Class implementation for SickBay room.*/

#include "SickBay.hpp"

/* Function sets the attributes of this room so they can be called by get functions.*/
void SickBay::setRoom()
{
	name = "sickBay";
	longDes = "You enter the sick bay. This is not an area of the base you want to be on a regular basis.\n"
		"The crew has luckily not had too many members stay here for long. You notice that the room contains medical supplies for the base."
		" There is also a member of the crew current laying on the bed. You can't tell there condition from this distance.\n";
	shortDes = "You return to the sick bay. This is the room where the sick or injured are cared for.\n";
	exitLong = "The hallway which connects to many rooms in the base including the research lab and radio room is from the way you came.\n";
	exitShort = "There is a hallway from the direction you came.\n";
	fOneHappened = 0;
	fTwoHappened = 0;
	roomEntered = 0;
}

/* Function returns the name of the room. */
std::string SickBay::getName()
{
	return name;
}

/* Function returns the long description of the room. */
std::string SickBay::getLongDescrip()
{
	return longDes;
}

/* Function returns the short description of the room. */
std::string SickBay::getShortDescrip()
{
	return shortDes;
}

/* Function returns the long version of the exits description of the room. */
std::string SickBay::getExitLong()
{
	return exitLong;
}

/* Function returns the short version of the exits description of the room. */
std::string SickBay::getExitShort()
{
	return exitShort;
}

/* Function returns the boolean value that represents whether a feature happened.*/
bool SickBay::getFeatureOneHap()
{
	return fOneHappened;
}

/* Function returns the boolean value that represents whether a feature happened.*/
bool SickBay::getFeatureTwoHap()
{
	return fTwoHappened;
}

/* Function performs the action for the first feature of the room.*/
int SickBay::featureOne(Player* user)
{
	int outcome = 0;

	std::cout << "Player inspects the toilet paper." << std::endl;

	++fOneHappened;

	return outcome;
}

/* Function performs the action for the second feature of the room.*/
int SickBay::featureTwo(Player* user)
{
	int outcome = 0;

	std::cout << "Player uses the bathroom." << std::endl;

	++fTwoHappened;

	return outcome;
}

/* Function adds an item to the vector of items in the room. It receives a Player instance
* in case the player wishes to drop an item from their inventory into the room. */
void SickBay::addItem(Item* newItem, Player* user, int number)
{
	if (number == 0)
	{
		items.push_back(newItem);
		newItem->setLocation(name);
	}
	else
	{
		items.push_back(newItem);

		//Call Player function to remove item from player's inventory
	}
}

/* Function removes an item from the vector of items in the room and adds it to the player's inventory.*/
void SickBay::removeItem(Item* removeItem, Player* user)
{
	if (items.size() > 0)
	{
		for (unsigned int i = 0; i < items.size(); ++i)
		{
			if (items[i]->getName() == removeItem->getName())
			{
				user->setInventory(removeItem);
				items.erase(items.begin() + i);
				removeItem->setLocation("player's inventory");
			}
		}
	}
}

/* Function displays the items currently in the room.*/
void SickBay::itemsInRoom()
{
	if (items.size() > 0)
	{
		std::cout << "The current items in the " << getName() << " are: ";
		for (unsigned int i = 0; i < items.size(); i++)
		{
			if (i != (items.size() - 1))
			{
				std::cout << items[i]->getName() << ", ";
			}
			else
			{
				std::cout << items[i]->getName() << std::endl;
				std::cout << std::endl;
			}
		}
	}
	else
	{
		std::cout << "There are no items to pick up in the room." << std::endl;
	}
}

/* Function displays either the short or long description based off a boolean value.*/
void SickBay::displayDescrip()
{
	if (roomEntered == 0)
	{
		std::cout << longDes << std::endl;
	}
	else
	{
		std::cout << shortDes << std::endl;
	}
	++roomEntered;
}

/* Function displays the exit descriptions based on whether it is the first time the user entered the room.*/
void SickBay::displayExits()
{
	if (roomEntered == 1)
	{
		std::cout << exitLong << std::endl;
	}
	else
	{
		std::cout << exitShort << std::endl;
	}
}

/* Function receives the list of rooms and a phrase from the user. It then selects a room to move to based on
* the phrase. It returns a pointer to that room to main so the game can move to that room. */
Room* SickBay::changeRooms(std::vector<Room*> rooms, std::string phrase)
{
	Room* nextRoom = NULL;
	std::string roomName = "";

	if (phrase == "go back" || phrase == "back" || phrase == "go hallway" || phrase == "hallway")
	{
		roomName = "hallway1";
	}

	for (int x = 0; x < 15; ++x)
	{
		if (rooms[x]->getName() == roomName)
		{
			nextRoom = rooms[x];
			x = 15;
		}
	}

	return nextRoom;
}
