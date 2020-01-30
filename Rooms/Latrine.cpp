/* Project Name: Capstone Project
   Class: CS 467
   Team: Team Thing- Ryan Alcorn, Joel Alfaro, Neil Gayeta
   File: Latrine.cpp
   Description: Class implementation for Latrine room.*/

#include "Latrine.hpp"

/* Function sets the attributes of this room so they can be called by get functions.*/
void Latrine::setRoom()
{
	name = "latrine";
	longDes = "You enter the latrine. This is the area of the base where the team that contains the restroom.\n"
		"This room usually does not smell good. It's not a room you want to stay in for long, but you think you remember booze being in here.\n"
		" You notice some toilet paper in an odd location in the room. You also have the need to use the restroom.\n";
	shortDes = "You return to the latrine. It's a bathroom.\n";
	exitLong = "The hallway which connects to many rooms in the base including the research lab and sick bay is from the way you came.\n";
	exitShort = "There is a hallway from the direction you came.\n";
	fOneHappened = 0;
	fTwoHappened = 0;
	roomEntered = 0;
}

/* Function returns the name of the room. */
std::string Latrine::getName()
{
	return name;
}

/* Function returns the long description of the room. */
std::string Latrine::getLongDescrip()
{
	return longDes;
}

/* Function returns the short description of the room. */
std::string Latrine::getShortDescrip()
{
	return shortDes;
}

/* Function returns the long version of the exits description of the room. */
std::string Latrine::getExitLong()
{
	return exitLong;
}

/* Function returns the short version of the exits description of the room. */
std::string Latrine::getExitShort()
{
	return exitShort;
}

/* Function returns the boolean value that represents whether a feature happened.*/
bool Latrine::getFeatureOneHap()
{
	return fOneHappened;
}

/* Function returns the boolean value that represents whether a feature happened.*/
bool Latrine::getFeatureTwoHap()
{
	return fTwoHappened;
}

/* Function performs the action for the first feature of the room.*/
int Latrine::featureOne(std::vector<Item*> inventory)
{
	int outcome = 0;

	std::cout << "Player inspects the toilet paper." << std::endl;

	++fOneHappened;

	return outcome;
}

/* Function performs the action for the second feature of the room.*/
int Latrine::featureTwo(std::vector<Item*> inventory)
{
	int outcome = 0;

	std::cout << "Player uses the bathroom." << std::endl;

	++fTwoHappened;

	return outcome;
}

/* Function adds an item to the vector of items in the room. It receives the player's inventory
* in case the player wishes to drop an item from their inventory into the room. */
void Latrine::addItem(Item* newItem, std::vector<Item*> inventory, int number)
{
	if (number == 0)
	{
		items.push_back(newItem);
		newItem->setLocation(name);
	}
	else
	{
		items.push_back(newItem);

		for (unsigned int i = 0; i < inventory.size(); ++i)
		{
			if (inventory[i]->getName() == newItem->getName())
			{
				inventory.erase(inventory.begin() + i);
				newItem->setLocation(name);
			}
		}
	}
}

/* Function removes an item from the vector of items in the room and adds it to the player's inventory.*/
void Latrine::removeItem(Item* removeItem, std::vector<Item*> inventory)
{
	if (items.size() > 0)
	{
		for (unsigned int i = 0; i < items.size(); ++i)
		{
			if (items[i]->getName() == removeItem->getName())
			{
				inventory.push_back(removeItem);
				items.erase(items.begin() + i);
				removeItem->setLocation("player's inventory");
			}
		}
	}
}

/* Function displays the items currently in the room.*/
void Latrine::itemsInRoom()
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
void Latrine::displayDescrip()
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
void Latrine::displayExits()
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
Room* Latrine::changeRooms(std::vector<Room*> rooms, std::string phrase)
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
