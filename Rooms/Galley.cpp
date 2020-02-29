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
		" in the air.\nYou sense the area where the smell is coming from. You also notice some food on the counter.\n";
	shortDes = "You return to the galley. The area still smells terrible.\n";
	exitLong = "The mess hall is from the direction you came.\nIt is the area of the base where members of the"
		" crew ate their meals together.\n";
	exitShort = "The mess hall is from the direction you came.\n";
	fOneHappened = 0;
	fTwoHappened = 0;
	roomEntered = 0;
}

/* Function performs the action for the first feature of the room which allows the user to gain the red herring.*/
int Galley::featureOne(Player* user)
{
	int outcome = 0;
	std::string choice = "";
	std::string response = "incorrect";

	std::cout << "You head over to counter to inspect the food. It looks like a can of sardines.\n"
		"Pick it up?\n\n"
		"1. Pick up the can of sardines\n"
		"2. Ignore it"<< std::endl;
	getline(std::cin, choice);

	while (response == "incorrect")
	{
		if (choice == "1")
		{
			std::cout << std::endl;
			std::cout << "You decide to pick up the can.\n"
				"It's not your favorite food, but it's probably edible.\n"
				"You obtain the can of sardines!" << std::endl;

			//Removes the red herring item from the room and adds it to the player's inventory.
			removeItem("red herring", user);

			response = "correct";
		}
		else if (choice == "2")
		{
			std::cout << std::endl;
			std::cout << "You decide to not pick up the can of sardines. That stuff is nasty." << std::endl;

			response = "correct";
		}
		else
		{
			std::cout << "You have picked an incorrect choice. Please chose again: ";
			getline(std::cin, choice);
		}
	}

	++fOneHappened;

	return outcome;
}

/* Function performs the action for the second feature of the room which allows the user to smell something in the room.*/
int Galley::featureTwo(Player* user)
{
	int outcome = 0;

	std::cout << "You decide to move closer to the smell. This is perhaps the worst smell you have experienced in a while.\n"
		"It's sitting on a plate, but it doesn't look like food.\n\n"
		"You step closer. The smell gets more horrible...\n\n"
		"You step closer. You begin to really contemplate why you are doing this. It clearly isn't booze.\n\n"
		"You step closer. You see that it is just decomposing leftovers. Someone forgot to clean up after themselves." << std::endl;

	++fTwoHappened;

	return outcome;
}
