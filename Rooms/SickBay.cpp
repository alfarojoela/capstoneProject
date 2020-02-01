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
		"The crew has luckily not had too many members stay here for long.\nYou notice that the room contains medical supplies for the base."
		"\nThere is also a member of the crew current laying on the bed. You can't tell there condition from this distance.\n";
	shortDes = "You return to the sick bay. This is the room where the sick or injured are cared for.\n";
	exitLong = "The hallway which connects to many rooms in the base including the research lab and radio room is from the way you came.\n";
	exitShort = "There is a hallway from the direction you came.\n";
	fOneHappened = 0;
	fTwoHappened = 0;
	roomEntered = 0;
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
