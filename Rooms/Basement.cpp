/* Project Name : Capstone Project
Class : CS 467
Team : Team Thing - Ryan Alcorn, Joel Alfaro, Neil Gayeta
File : Basement.cpp
Description : Class implementation for Basement room.*/

#include "Basement.hpp"

/* Function sets the attributes of this room so they can be called by get functions.*/
void Basement::setRoom()
{
	name = "basement";
	longDes = "You enter the basement. This area is used for storage. It contains materials that are hazardous.\n"
		"It's also one of the most expansive areas of the base. You see something hunched over in the corner of the room.\n"
		"It looks like a person...\n";
	shortDes = "You return to the basement. This area gives you the creeps.\n";
	exitLong = "There is a hallway which connects to other rooms in the base like the dog kennel from the way you came.\n";
	exitShort = "There is a hallway from the direction you came.\n";
	fOneHappened = 0;
	fTwoHappened = 0;
	roomEntered = 0;
}

/* Function performs the action for the first feature of the room.*/
int Basement::featureOne(Player* user)
{
	int outcome = 0;

	std::cout << "Talk to doppelganger" << std::endl;

	++fOneHappened;

	return outcome;
}

/* Function performs the action for the second feature of the room.*/
int Basement::featureTwo(Player* user)
{
	int outcome = 0;

	std::cout << "Get attacked. Happens second time entering the room." << std::endl;

	++fTwoHappened;

	return outcome;
}

/* Function receives the list of rooms and a phrase from the user. It then selects a room to move to based on
* the phrase. It returns a pointer to that room to main so the game can move to that room. */
Room* Basement::changeRooms(std::vector<Room*> rooms, std::string phrase)
{
	Room* nextRoom = NULL;
	std::string roomName = "";

	if (phrase == "go back" || phrase == "back" || phrase == "go hallway" || phrase == "hallway")
	{
		roomName = "hallway2";
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