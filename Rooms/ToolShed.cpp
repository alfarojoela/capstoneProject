/* Project Name : Capstone Project
Class : CS 467
Team : Team Thing - Ryan Alcorn, Joel Alfaro, Neil Gayeta
File : ToolShed.cpp
Description : Class implementation for ToolShed room.*/

#include "ToolShed.hpp"

/* Function sets the attributes of this room so they can be called by get functions.*/
void ToolShed::setRoom()
{
	name = "toolShed";
	longDes = "You make your way towards the tool shed. It is located outside of the base. It is freezing cold outside.\n"
		"Hopefully you can find something worthwhile in there.";
	shortDes = "You return to the tool shed. It contains useful equipment.\n";
	exitLong = "The equipment room which leads back into the base is from the way you came.\n";
	exitShort = "The equipment room is from the direction you came.\n";
	fOneHappened = 0;
	fTwoHappened = 0;
	roomEntered = 0;
}

/* Function returns the name of the room. */
std::string ToolShed::getName()
{
	return name;
}

/* Function returns the long description of the room. */
std::string ToolShed::getLongDescrip()
{
	return longDes;
}

/* Function returns the short description of the room. */
std::string ToolShed::getShortDescrip()
{
	return shortDes;
}

/* Function returns the long version of the exits description of the room. */
std::string ToolShed::getExitLong()
{
	return exitLong;
}

/* Function returns the short version of the exits description of the room. */
std::string ToolShed::getExitShort()
{
	return exitShort;
}

/* Function returns the boolean value that represents whether a feature happened.*/
bool ToolShed::getFeatureOneHap()
{
	return fOneHappened;
}

/* Function returns the boolean value that represents whether a feature happened.*/
bool ToolShed::getFeatureTwoHap()
{
	return fTwoHappened;
}

/* Function performs the action for the first feature of the room.*/
int ToolShed::featureOne(Player* user)
{
	int outcome = 0;

	std::cout << "Notice footprints or groaning, get attacked, fight or flee." << std::endl;

	++fOneHappened;

	return outcome;
}

/* Function performs the action for the second feature of the room.*/
int ToolShed::featureTwo(Player* user)
{
	int outcome = 0;
	std::string choice = "";
	std::string response = "incorrect";

	std::cout << "As you make your way towards the tool shed, you notice a glint in the snow.\n" 
		"Your body is getting colder and colder, but there could be something useful there.\n"
		"What do you do?\n\n"
		"1. Head deeper into the snow to obtain the item\n"
		"2. Continue on your path to the tool shed" << std::endl;
	std::cin >> choice;

	while (response == "incorrect")
	{
		std::cout << std::endl;

		if (choice == "1")
		{
			std::cout << "Today's been crazy already why not see what this is! You head towards the glinting item in the snow.\n"
				"The item becomes more clear as you move closer. It is a bottle of Maker's Mark. You could always use more alcohol.\n"
				"You obtain a bottle of Maker's Mark!" << std::endl;

			response = "correct";
		}
		else if (choice == "2")
		{
			std::cout << "You decide not to risk it and continue on the path to the tool shed." << std::endl;

			response = "correct";
		}
		else
		{
			std::cout << "You have picked an incorrect choice. Please chose again: ";
			std::cin >> choice;
		}
	}
	std::cout << std::endl;

	++fTwoHappened;

	return outcome;
}

/* Function adds an item to the vector of items in the room. It receives a Player instance
* in case the player wishes to drop an item from their inventory into the room. */
void ToolShed::addItem(Item* newItem, Player* user, int number)
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
void ToolShed::removeItem(Item* removeItem, Player* user)
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
void ToolShed::itemsInRoom()
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
void ToolShed::displayDescrip()
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
void ToolShed::displayExits()
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
Room* ToolShed::changeRooms(std::vector<Room*> rooms, std::string phrase)
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
