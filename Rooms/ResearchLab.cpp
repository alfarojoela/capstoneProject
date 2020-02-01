/* Project Name : Capstone Project
Class : CS 467
Team : Team Thing - Ryan Alcorn, Joel Alfaro, Neil Gayeta
File : ResearchLab.cpp
Description : Class implementation for ResearchLab room.*/

#include "ResearchLab.hpp"

/* Function sets the attributes of this room so they can be called by get functions.*/
void ResearchLab::setRoom()
{
	name = "researchLab";
	longDes = "You enter the research lab. This is an area where the crew conducts research during the mission.\n"
		"You see the doctor in the room inspecting a body.\nThere is also a computer displaying information in the corner of the room.\n";
	shortDes = "You return to the research lab. It's a useful room in the base.\n";
	exitLong = "The hallway which connects to many rooms in the base including the radio room and sick bay is from the way you came.\n";
	exitShort = "There is a hallway from the direction you came.\n";
	fOneHappened = 0;
	fTwoHappened = 0;
	roomEntered = 0;
}

/* Function performs the action for the first feature of the room.*/
int ResearchLab::featureOne(Player* user)
{
	int outcome = 0;

	std::cout << "Player goes on computer that predicts things." << std::endl;

	++fOneHappened;

	return outcome;
}

/* Function performs the action for the second feature of the room.*/
int ResearchLab::featureTwo(Player* user)
{
	int outcome = 0;

	std::cout << "Player interacts with the doctor." << std::endl;

	++fTwoHappened;

	return outcome;
}

/* Function receives the list of rooms and a phrase from the user. It then selects a room to move to based on
* the phrase. It returns a pointer to that room to main so the game can move to that room. */
Room* ResearchLab::changeRooms(std::vector<Room*> rooms, std::string phrase)
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
