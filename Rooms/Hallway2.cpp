/* Project Name : Capstone Project
Class : CS 467
Team : Team Thing - Ryan Alcorn, Joel Alfaro, Neil Gayeta
File : Hallway2.cpp
Description : Class implementation for Hallway2 room.*/

#include "Hallway2.hpp"

/* Function sets the attributes of this room so they can be called by get functions.*/
void Hallway2::setRoom()
{
	name = "hallway2";
	longDes = "You enter a hallway. This room is connected to many rooms in the base. There are currently two of your\n"
		"crewmembers in this room.\n";
	shortDes = "You return one of the hallways. It is connected to many rooms in the base.\n";
	exitLong = "This room is connected to many other rooms at the base. This includes the mess hall, dog kennel,\n"
		" basement, conference room, and garage.\n";
	exitShort = "There are five rooms connected to this room.\n";
	fOneHappened = 0;
	fTwoHappened = 0;
	roomEntered = 0;
}

/* Function returns the name of the room. */
std::string Hallway2::getName()
{
	return name;
}

/* Function returns the long description of the room. */
std::string Hallway2::getLongDescrip()
{
	return longDes;
}

/* Function returns the short description of the room. */
std::string Hallway2::getShortDescrip()
{
	return shortDes;
}

/* Function returns the long version of the exits description of the room. */
std::string Hallway2::getExitLong()
{
	return exitLong;
}

/* Function returns the short version of the exits description of the room. */
std::string Hallway2::getExitShort()
{
	return exitShort;
}

/* Function returns the boolean value that represents whether a feature happened.*/
bool Hallway2::getFeatureOneHap()
{
	return fOneHappened;
}

/* Function returns the boolean value that represents whether a feature happened.*/
bool Hallway2::getFeatureTwoHap()
{
	return fTwoHappened;
}

/* Function performs the action for the first feature of the room.*/
int Hallway2::featureOne(Player* user)
{
	int outcome = 0;

	std::cout << "Player talks to a crew member who doesn't believe what's going on." << std::endl;

	++fOneHappened;

	return outcome;
}

/* Function performs the action for the second feature of the room.*/
int Hallway2::featureTwo(Player* user)
{
	int outcome = 0;

	std::cout << "Player talks to a crew member that is helpful." << std::endl;

	++fTwoHappened;

	return outcome;
}

/* Function adds an item to the vector of items in the room. It receives a Player instance
* in case the player wishes to drop an item from their inventory into the room. */
void Hallway2::addItem(Item* newItem, Player* user, int number)
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
void Hallway2::removeItem(Item* removeItem, Player* user)
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
void Hallway2::itemsInRoom()
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
void Hallway2::displayDescrip()
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
void Hallway2::displayExits()
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
Room* Hallway2::changeRooms(std::vector<Room*> rooms, std::string phrase)
{
	Room* nextRoom = NULL;
	std::string roomName = "";

	if (phrase == "go west" || phrase == "west" || phrase == "go food" || phrase == "food")
	{
		roomName = "messHall";
	}
	else if (phrase == "go south" || phrase == "south" || phrase == "go basement" || phrase == "basement")
	{
		roomName = "basement";
	}
	else if (phrase == "go dog" || phrase == "dog" || phrase == "go kennel" || phrase == "kennel")
	{
		roomName = "dogKennel";
	}
	else if (phrase == "go film" || phrase == "film" || phrase == "go conference" || phrase == "conference")
	{
		roomName = "conferenceRoom";
	}
	else if (phrase == "go east" || phrase == "east" || phrase == "go garage" || phrase == "garage")
	{
		roomName = "garage";
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
