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
	longDes = "You enter the latrine. This is the area of the base where that contains the restroom.\n"
		"This room usually does not smell good. It's not a room you want to stay in for long,\nbut you think you remember booze being in here."
		" You notice some toilet paper in an odd location in the room.\nYou also have the need to use the restroom.\n";
	shortDes = "You return to the latrine. It's a bathroom.\n";
	exitLong = "The hallway which connects to many rooms in the base including the research lab and sick bay is from the way you came.\n";
	exitShort = "There is a hallway from the direction you came.\n";
	fOneHappened = 0;
	fTwoHappened = 0;
	roomEntered = 0;
}

/* Function performs the action for the first feature of the room.*/
int Latrine::featureOne(Player* user)
{
	int outcome = 0;

	std::cout << "Player inspects the toilet paper." << std::endl;

	++fOneHappened;

	return outcome;
}

/* Function performs the action for the second feature of the room.*/
int Latrine::featureTwo(Player* user)
{
	int outcome = 0;

	std::cout << "Player uses the bathroom." << std::endl;

	++fTwoHappened;

	return outcome;
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
