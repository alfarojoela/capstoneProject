/* Project Name: Capstone Project
   Class: CS 467
   Team: Team Thing- Ryan Alcorn, Joel Alfaro, Neil Gayeta
   File: Hallway1.cpp
   Description: Class implementation for the first Hallway room.*/

#include "Hallway1.hpp"

/* Function sets the attributes of this room so they can be called by get functions.*/
void Hallway1::setRoom()
{
	name = "hallway1";
	longDes = "You enter a hallway. This hallway is connected to many of the important rooms inside the base.\n"
		"There appears to be nobody around right now. There is a terrible smell emanating from the room.\n"
		"Along with the smell, the lights are blinking on and off. The room wasn't like this yesterday...\n";
	shortDes = "You enter a hallway. This hallway is connected to many rooms. The lights are blinking on and off. On and off.\n";
	exitLong = "This room is connected to many other rooms at the base.\nThis includes the radio room, equipment room,"
		" sick bay, latrine, and research lab.\n";
	exitShort = "There are five rooms connected to this room.\n";
	fOneHappened = 0;
	fTwoHappened = 0;
	roomEntered = 0;
}

/* Function performs the action for the first feature of the room.*/
int Hallway1::featureOne(Player* user)
{
	int outcome = 0;

	std::cout << "Description of the smell of blood.\n" << std::endl;

	++fOneHappened;

	return outcome;
}

/* Function performs the action for the second feature of the room.*/
int Hallway1::featureTwo(Player* user)
{
	int outcome = 0;

	std::cout << "Event with light blinking on and off." << std::endl;

	++fTwoHappened;

	return outcome;
}
