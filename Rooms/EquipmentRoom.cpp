/* Project Name : Capstone Project
Class : CS 467
Team : Team Thing - Ryan Alcorn, Joel Alfaro, Neil Gayeta
File : EquipmentRoom.cpp
Description : Class implementation for EquipmentRoom room.*/

#include "EquipmentRoom.hpp"

/* Function sets the attributes of this room so they can be called by get functions.*/
void EquipmentRoom::setRoom()
{
	name = "equipmentRoom";
	longDes = "You enter the equipment room. The room is currently pitch black. There must be a light switch in here somewhere.\n";
	shortDes = "You return to the equipment room. It contains equipment used on the base.\n";
	exitLong = "The hallway which connects to many rooms in the base including the research lab and sick bay is from the way you came.\n"
		"There is a tool shed located to the east.\n";
	exitShort = "There is a hallway from the direction you came and a tool shed to the east.\n";
	fOneHappened = 0;
	fTwoHappened = 0;
	roomEntered = 0;
}

/* Function performs the action for the first feature of the room.*/
int EquipmentRoom::featureOne(Player* user)
{
	int outcome = 0;

	std::cout << "Player tries to turn on the light switch." << std::endl;

	++fOneHappened;

	return outcome;
}

/* Function performs the action for the second feature of the room.*/
int EquipmentRoom::featureTwo(Player* user)
{
	int outcome = 0;

	std::cout << "Player tries to obtain the blow torch." << std::endl;

	++fTwoHappened;

	return outcome;
}

/* Function receives the list of rooms and a phrase from the user. It then selects a room to move to based on
* the phrase. It returns a pointer to that room to main so the game can move to that room. */
Room* EquipmentRoom::changeRooms(std::vector<Room*> rooms, std::string phrase)
{
	Room* nextRoom = NULL;
	std::string roomName = "";

	if (phrase == "go back" || phrase == "back" || phrase == "go hallway" || phrase == "hallway")
	{
		roomName = "hallway1";
	}
	else if (phrase == "go east" || phrase == "east" || phrase == "go outside" || phrase == "outside" || phrase == "go tools"
		|| phrase == "tools")
	{
		roomName = "toolShed";
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
