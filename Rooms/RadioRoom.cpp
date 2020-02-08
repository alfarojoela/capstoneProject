/* Project Name : Capstone Project
Class : CS 467
Team : Team Thing - Ryan Alcorn, Joel Alfaro, Neil Gayeta
File : RadioRoom.cpp
Description : Class implementation for RadioRoom room.*/

#include "RadioRoom.hpp"

/* Function sets the attributes of this room so they can be called by get functions.*/
void RadioRoom::setRoom()
{
	name = "radioRoom";
	longDes = "You enter the radio room. This room contains the radio equipment along with other advanced equipment used on the base.\n"
		"You see the radio equipment in the corner of the room.\n";
	shortDes = "You return to the radio room. It contains equipement to contact the outside world.\n";
	exitLong = "The hallway which connects to many rooms in the base including the research lab and sick bay is from the way you came.\n";
	exitShort = "There is a hallway from the direction you came.\n";
	fOneHappened = 0;
	fTwoHappened = 0;
	roomEntered = 0;
}

/* Function performs the action for the first feature of the room.*/
int RadioRoom::featureOne(Player* user)
{
	int outcome = 0;

	std::cout << "Player tries to use the radio." << std::endl;

	++fOneHappened;

	return outcome;
}

/* Function performs the action for the second feature of the room.*/
int RadioRoom::featureTwo(Player* user)
{
	int outcome = 0;

	std::cout << "Player decides to destroy the base." << std::endl;

	++fTwoHappened;

	return outcome;
}
