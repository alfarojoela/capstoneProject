/* Project Name: Capstone Project
   Class: CS 467
   Team: Team Thing- Ryan Alcorn, Joel Alfaro, Neil Gayeta
   File: Galley.cpp
   Description: Class implementation for Galley room.*/

#include "Galley.hpp"

/* Function sets the attributes of this room so they can be called by get functions.*/
void Galley::setRoom()
{
	name = "galley";
	longDes = "You enter the galley. This is the area of the base where members of the team prepared their food.\n" 
		"The room usually smells good, but today it smells entirely different. There is more of a rotten smell"
		" in the air.\nYou sense the area where the smell is coming from. You also notice an object on the counter.\n";
	shortDes = "You return to the galley. The area still smells terrible.\n";
	exitLong = "The mess hall is from the direction you came.\nIt is the area of the base where members of the"
		" crew ate their meals together.\n";
	exitShort = "The mess hall is from the direction you came.\n";
	fOneHappened = 0;
	fTwoHappened = 0;
	roomEntered = 0;
}

/* Function performs the action for the first feature of the room.*/
int Galley::featureOne(Player* user)
{
	int outcome = 0;

	std::cout << "Player interacts with the red herring." << std::endl;

	++fOneHappened;

	return outcome;
}

/* Function performs the action for the second feature of the room.*/
int Galley::featureTwo(Player* user)
{
	int outcome = 0;

	std::cout << "You decide to move closer to the smell. This is perhaps the worst smell you have experienced in"
		" a while.\nIt at first doesn't look like something that belongs in the galley.\nYou step closer. The smell gets"
		" more horrible.\nYou step closer. You see that it is just decomposing leftovers. Someone forgot to clean up after themselves." << std::endl;

	++fTwoHappened;

	return outcome;
}
