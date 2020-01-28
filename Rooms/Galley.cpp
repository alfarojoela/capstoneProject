/* Project Name: Capstone Project
   Class: CS 467
   Team: Team Thing- Ryan Alcorn, Joel Alfaro, Neil Gayeta
   File: Galley.cpp
   Description: Class implementation for Galley room.*/

#include "Galley.hpp"

/* Function sets the attributes of this room so they can be called by get functions.*/
void Galley::setRoom()
{
	name = "galley";
	longDes = "You enter the galley. This is the area of the base where members of the team prepared their food.\n" 
		"The room usually smells good, but today it smells entirely different. There is more of a rotten smell"
		" in the air.\nYou sense the area where the smell is coming from. You also notice an object on the counter.\n";
	shortDes = "You return to the galley. The area still smells terrible.\n";
	exitLong = "The mess hall is from the direction you came. It is the area of the base where members of the"
		" crew ate their meals together.\n";
	exitShort = "The mess hall is from the direction you came.\n";
	fOneHappened = 0;
	fTwoHappened = 0;
	roomEntered = 0;
}

/* Function returns the name of the room. */
std::string Galley::getName()
{
	return name;
}

/* Function returns the long description of the room. */
std::string Galley::getLongDescrip()
{
	return longDes;
}

/* Function returns the short description of the room. */
std::string Galley::getShortDescrip()
{
	return shortDes;
}

/* Function returns the long version of the exits description of the room. */
std::string Galley::getExitLong()
{
	return exitLong;
}

/* Function returns the short version of the exits description of the room. */
std::string Galley::getExitShort()
{
	return exitShort;
}

/* Function returns the boolean value that represents whether a feature happened.*/
bool Galley::getFeatureOneHap()
{
	return fOneHappened;
}

/* Function returns the boolean value that represents whether a feature happened.*/
bool Galley::getFeatureTwoHap()
{
	return fTwoHappened;
}

/* Function performs the action for the first feature of the room.*/
void Galley::featureOne()
{
	std::cout << "Player interacts with the red herring." << std::endl;

	++fOneHappened;
}

/* Function performs the action for the second feature of the room.*/
void Galley::featureTwo()
{
	std::cout << "You decide to move closer to the smell. This is perhaps the worst smell you have experienced in"
		" a while.\nIt at first doesn't look like something that belongs in the galley.\nYou step closer. The smell gets"
		" more horrible.\nYou step closer. You see that it is just decomposing leftovers. Someone forgot to clean up after themselves." << std::endl;

	++fTwoHappened;
}

/* Function adds an item to the vector of items in the room.*/
void Galley::addItem(Item* newItem)
{
	items.push_back(newItem);
	newItem->setLocation(name);
}

/* Function removes an item from the vector of items in the room.*/
void Galley::removeItem(Item* removeItem)
{
	if (items.size() > 0)
	{
		for (int i = 0; i < items.size(); ++i)
		{
			if (items[i]->getName() == removeItem->getName())
			{
				items.erase(items.begin() + i);
				removeItem->setLocation("player's inventory");
			}
		}
	}
}

/* Function displays the items currently in the room.*/
void Galley::itemsInRoom()
{
	if (items.size() > 0)
	{
		std::cout << "The current items in the " << getName() << " are: ";
		for (int i = 0; i < items.size(); i++)
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
void Galley::displayDescrip()
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
void Galley::displayExits()
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
Room* Galley::changeRooms(std::vector<Room*> rooms, std::string phrase)
{
	Room* nextRoom = NULL;
	std::string roomName = "";

	if (phrase == "go north" || phrase == "north" || phrase == "go back" || phrase == "back")
	{
		roomName = "messHall";
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
