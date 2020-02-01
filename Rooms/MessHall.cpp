/* Project Name : Capstone Project
Class : CS 467
Team : Team Thing - Ryan Alcorn, Joel Alfaro, Neil Gayeta
File : MessHall.cpp
Description : Class implementation for MessHall room.*/

#include "MessHall.hpp"

/* Function sets the attributes of this room so they can be called by get functions.*/
void MessHall::setRoom()
{
	name = "messHall";
	longDes = "You enter the mess hall. This is the area of the base where the crew would gather to share their meals together\n"
		"and share stories. This is one of the larger rooms in the base considering it has to seat all of the crew members.\n"
		"You notice what looks like an untouched meal on one of the tables. There's also a bottle of booze on another table.\n";
	shortDes = "You return to the mess hall. The room where the crew ate their meals together.\n";
	exitLong = "A hallway which connects to many rooms in the base including the conference room and garage is east of you.\n"
		"The galley is also south of your location.";
	exitShort = "There is a hallway to the east and the galley to the south.\n";
	fOneHappened = 0;
	fTwoHappened = 0;
	roomEntered = 0;
}

/* Function performs the action for the first feature of the room.*/
int MessHall::featureOne(Player* user)
{
	int outcome = 0;

	std::cout << "Player eats the food in the room." << std::endl;

	++fOneHappened;

	return outcome;
}

/* Function performs the action for the second feature of the room.*/
int MessHall::featureTwo(Player* user)
{
	int outcome = 0;

	std::cout << "Player finds the empty booze bottle. Eats angry." << std::endl;

	++fTwoHappened;

	return outcome;
}

/* Function receives the list of rooms and a phrase from the user. It then selects a room to move to based on
* the phrase. It returns a pointer to that room to main so the game can move to that room. */
Room* MessHall::changeRooms(std::vector<Room*> rooms, std::string phrase)
{
	Room* nextRoom = NULL;
	std::string roomName = "";

	if (phrase == "go east" || phrase == "east" || phrase == "go hallway" || phrase == "hallway")
	{
		roomName = "hallway2";
	}
	else if (phrase == "go south" || phrase == "south" || phrase == "go galley" || phrase == "galley")
	{
		roomName = "galley";
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
