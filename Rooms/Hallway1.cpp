/* Project Name: Capstone Project
   Class: CS 467
   Team: Team Thing- Ryan Alcorn, Joel Alfaro, Neil Gayeta
   File: Hallway1.cpp
   Description: Class implementation for the first Hallway room.*/

#include "Hallway1.hpp"

   /* Function sets the attributes of this room so they can be called by get functions.*/
void Hallway1::setRoom()
{
	name = "Hallway 1";
	longDes = "You enter a hallway. This hallway is connected to many of the important rooms inside the base.\n"
		"There appears to be nobody around right. There is a terrible smell emanating from the room.\n"
		"Along with the smell, the lights are blinking on and off. The room wasn't like this yesterday...\n";
	shortDes = "You enter a hallway. This hallway is connected to many rooms. The lights are blinking on and off. On and off.\n";
	exitLong = "This room is connected to many other rooms at the base. This includes the radio room, equipment room,\n"
		" sick bay, latrine, and research lab.\n";
	exitShort = "There are five rooms connected to this room.\n";
	fOneHappened = 0;
	fTwoHappened = 0;
	roomEntered = 0;
}

/* Function returns the name of the room. */
std::string Hallway1::getName()
{
	return name;
}

/* Function returns the long description of the room. */
std::string Hallway1::getLongDescrip()
{
	return longDes;
}

/* Function returns the short description of the room. */
std::string Hallway1::getShortDescrip()
{
	return shortDes;
}

/* Function returns the long version of the exits description of the room. */
std::string Hallway1::getExitLong()
{
	return exitLong;
}

/* Function returns the short version of the exits description of the room. */
std::string Hallway1::getExitShort()
{
	return exitShort;
}

/* Function returns the boolean value that represents whether a feature happened.*/
bool Hallway1::getFeatureOneHap()
{
	return fOneHappened;
}

/* Function returns the boolean value that represents whether a feature happened.*/
bool Hallway1::getFeatureTwoHap()
{
	return fTwoHappened;
}

/* Function performs the action for the first feature of the room.*/
void Hallway1::featureOne()
{
	std::cout << "Description of the smell of blood.\n" << std::endl;

	++fOneHappened;
}

/* Function performs the action for the second feature of the room.*/
void Hallway1::featureTwo()
{

	std::cout << "Event with light blinking on and off." << std::endl;

	++fTwoHappened;
}

/* Function adds an item to the vector of items in the room.*/
void Hallway1::addItem(Item* newItem)
{
	items.push_back(newItem);
	newItem->setLocation(name);
}

/* Function removes an item from the vector of items in the room.*/
void Hallway1::removeItem(Item* removeItem)
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
void Hallway1::itemsInRoom()
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
void Hallway1::displayDescrip()
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
void Hallway1::displayExits()
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
* the phrase. It then returns a pointer to that room to main so the game can move to that room. */
Room* Hallway1::changeRooms(std::vector<Room*> rooms, std::string phrase)
{
	Room* nextRoom = NULL;
	std::string roomName = "";

	if (phrase == "go west" || phrase == "west" || phrase == "go sick bay" || phrase == "sick bay")
	{
		roomName = "Sick Bay";
	}
	else if (phrase == "go east" || phrase == "east" || phrase == "go radio" || phrase == "radio")
	{
		roomName = "Radio Room";
	}
	else if (phrase == "go booze" || phrase == "booze" || phrase == "go latrine" || phrase == "latrine")
	{
		roomName = "Latrine";
	}
	else if (phrase == "go research" || phrase == "research" || phrase == "go doctor" || phrase == "doctor")
	{
		roomName = "Research Lab";
	}
	else if (phrase == "go equipment" || phrase == "equipment" || phrase == "go get items" || phrase == "get items")
	{
		roomName = "Equipment Room";
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
