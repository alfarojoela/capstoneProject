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
	exitLong = "This room is connected to many other rooms in the base.\nThis includes the radio room, equipment room,"
		" sick bay, latrine, and research lab.\n";
	exitShort = "There are five rooms connected to this hallway.\n";
	fOneHappened = 0;
	fTwoHappened = 0;
	roomEntered = 0;
}

/* Function performs the action for the first feature of the room.*/
int Hallway1::featureOne(Player* user)
{
	int outcome = 0;

	std::cout << "You decide to check out the blood. The room reeks of an unfamiliar smell. It is not a pleasant smell.\n"
		"The blood is scattered across the wall through the hallway. It looks like a Picasso painting.\n"
		"Or even something out of one of the those horror films. Like the one's that Carpenter guy used to direct.\n"
		"It is a disturbing sight. Something big went down in here...\n"<< std::endl;

	++fOneHappened;

	return outcome;
}

/* Function performs the action for the second feature of the room.*/
int Hallway1::featureTwo(Player* user)
{
	int outcome = 0;

	std::cout << "You decide to check out the lights situation. The switch is on the other side of the hallway.\n"
		"You begin to make your way across the hallway. Each time the hallway goes dark, you get an uneasy feeling.\n"
		"Or maybe you're just hungover.\nYou make it to the light switch. It appears to be in functional condition.\n"
		"All of the sudden something rushes past your leg. It felt like a dog, but at the same time unnatural.\n"
		"This place is starting to give you the creeps.\n"<< std::endl;

	++fTwoHappened;

	return outcome;
}
