/* Project Name : Capstone Project
Class : CS 467
Team : Team Thing - Ryan Alcorn, Joel Alfaro, Neil Gayeta
File : DogKennel.cpp
Description : Class implementation for DogKennel room.*/

#include "DogKennel.hpp"

/* Function sets the attributes of this room so they can be called by get functions.*/
void DogKennel::setRoom()
{
	name = "dogKennel";
	longDes = "You enter the dog kennel. The base had 7 dogs that were housed in this room.\n"
		"There isn't seven dogs here now. You hear panting from the corner of the room. You can investigate that.\n"
		"You also notice something glinting on a shelf in another corner of the room.\n";
	shortDes = "You return to the dog kennel. Where'd all the dogs go?\n";
	exitLong = "There is a hallway which connects to other rooms in the base like the conference room from the way you came.\n";
	exitShort = "There is a hallway from the direction you came.\n";
	fOneHappened = 0;
	fTwoHappened = 0;
	roomEntered = 0;
}

/* Function performs the action for the first feature of the room.*/
int DogKennel::featureOne(Player* user)
{
	int outcome = 0;

	std::cout << "Investigate the panting noise. Dog jumps out at you. Attack with fists or item. If you flee you die." << std::endl;

	++fOneHappened;

	return outcome;
}

/* Function performs the action for the second feature of the room.*/
int DogKennel::featureTwo(Player* user)
{
	int outcome = 0;

	std::cout << "Try to jump to get the item off the shelf." << std::endl;

	++fTwoHappened;

	return outcome;
}

/* Function receives the list of rooms and a phrase from the user. It then selects a room to move to based on
* the phrase. It returns a pointer to that room to main so the game can move to that room. */
Room* DogKennel::changeRooms(std::vector<Room*> rooms, std::string phrase)
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
