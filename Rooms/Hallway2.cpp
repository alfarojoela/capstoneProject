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
	exitLong = "This room is connected to other rooms in the base.\nThis includes the mess hall, dog kennel,"
		" basement, conference room, and garage.\n";
	exitShort = "There are five rooms connected to this room.\n";
	fOneHappened = 0;
	fTwoHappened = 0;
	roomEntered = 0;
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
