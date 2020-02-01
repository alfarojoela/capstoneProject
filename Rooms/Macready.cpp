/* Project Name: Capstone Project
   Class: CS 467
   Team: Team Thing- Ryan Alcorn, Joel Alfaro, Neil Gayeta
   File: Macready.cpp
   Description: Class implementation for Macready room.*/

#include "Macready.hpp"

/* Function sets the attributes of this room so they can be called by get functions.*/
void Macready::setRoom()
{
	name = "macready";
	longDes = "You wake up.\nYour head is killing you. Must have drank too much again...\n"
		"You are not in your quarters. This is MacReady's room. It doesn't look like he's around though.\n"
		"You could search around for more booze. You also notice a computer in the room with a chess game in progress.\n";
	shortDes = "You return to the MacReady's quarters. There's still no booze in here.\n";
	exitLong = "There is a hallway outside this room that leads to other rooms on the base.\nThe base is eerily quiet right now.\n";
	exitShort = "There is a hallway outside this room.\n";
	fOneHappened = 0;
	fTwoHappened = 0;
	roomEntered = 0;
}

/* Function performs the action for the first feature of the room.*/
int Macready::featureOne(Player* user)
{
	int outcome = 0;

	std::cout << "You begin to search the room for booze. It's the only way to stop this headache.\n"
		"You can't see any booze visible at the moment. MacReady's room is a mess though. You decide to search under the bed.\n"
		"You don't find any booze under the bed. You do see a strange object though. It looks like a mask...\n"
		"The mask is white, but looks like someone rubbed clay on a person's face. There are no distinct features on it.\n"
		"You decide to put the mask back under the bed. MacReady's weird.\n"<< std::endl;

	++fOneHappened;

	return outcome;
}

/* Function performs the action for the second feature of the room.*/
int Macready::featureTwo(Player* user)
{
	int outcome = 0;
	std::string choice = "";
	std::string response = "incorrect";

	std::cout << "The computer screen is one of the main sources of light in the room. There is a chess game in progress.\n"
		"The game looks to be about midway through. The taken pieces on both sides seem pretty easily matched.\n"
		"Analysing the screen you see only two viable options. You could take a risk and move you queen down to check.\n"
		"You could also move your knight to block and bait out any incoming attacks towards your king.\n\n"
		"Which do you choose?\n"
		"1. Check the bot's king\n"
		"2. Protect your king" << std::endl;
		std::cin >> choice;

		while (response == "incorrect")
		{
			std::cout << std::endl;

			if (choice == "1")
			{
				std::cout << "You decide to check the king. The best defense is a good offense you think.\n"
					"The computer's queen moves to a new position and puts your king in check and then checkmate.\n"
					"The game flashes 'You lose!' over and over again. Stunned by this sudden defeat you get up to continue your search.\n"
					"As you walk away you think to yourself, 'Screw that computer'." << std::endl;

				response = "correct";
			}
			else if (choice == "2")
			{
				std::cout << "You decide to protect your king. The computer foolishly moves their queen to take your knight.\n"
					"You end up taking their most valuable piece with the bait you set up. A couple of turns later you defeat the computer.\n"
					"You think to yourself, 'I thought MacReady said this game was hard?' and walk away to continue your search." << std::endl;

				response = "correct";
			}
			else
			{
				std::cout << "You have picked an incorrect choice. Please chose again: ";
				std::cin >> choice;
			}
		}

		std::cout << std::endl;

		++fTwoHappened;

		return outcome;
}

/* Function receives the list of rooms and a phrase from the user. It then selects a room to move to based on
* the phrase. It returns a pointer to that room to main so the game can move to that room. */
Room* Macready::changeRooms(std::vector<Room*> rooms, std::string phrase)
{
	Room* nextRoom = NULL;
	std::string roomName = "";

	if (phrase == "go south" || phrase == "south" || phrase == "go back" || phrase == "back")
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
