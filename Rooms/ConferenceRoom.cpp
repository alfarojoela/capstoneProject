/* Project Name : Capstone Project
Class : CS 467
Team : Team Thing - Ryan Alcorn, Joel Alfaro, Neil Gayeta
File : ConferenceRoom.cpp
Description : Class implementation for ConferenceRoom room.*/

#include "ConferenceRoom.hpp"

/* Function sets the attributes of this room so they can be called by get functions.*/
void ConferenceRoom::setRoom()
{
	name = "conferenceRoom";
	longDes = "You enter the conference room. This room is primarily used for meetings to discuss matters on the base.\n"
		"You know there's a film projector in this room and you notice a couple of tapes on a table.\n"
		"You also notice a bottle of booze sitting on the main table.\n";
	shortDes = "You return to the conference room. There was booze here.\n";
	exitLong = "There is a hallway which connects to other rooms in the base like the basement from the way you came.\n";
	exitShort = "There is a hallway from the direction you came.\n";
	fOneHappened = 0;
	fTwoHappened = 0;
	roomEntered = 0;
}

/* Function performs the action for the first feature of the room.*/
int ConferenceRoom::featureOne(Player* user)
{
	int outcome = 0;

	std::cout << "Drink alcohol. Possibly drinking too much." << std::endl;

	++fOneHappened;

	return outcome;
}

/* Function performs the action for the second feature of the room.*/
int ConferenceRoom::featureTwo(Player* user)
{
	int outcome = 0;
	std::string choice = "";
	std::string response = "incorrect";

	std::cout << "You decide to watch a film on the projector. Might as well take it easy for a couple minutes.\n"
		"Unforantely all of the tapes are unlabled. Organization is not the crew's strong suite.\n"
		"There are three tapes to choose from. Which one do you choose?\n\n"
		"1. Tape One\n"
		"2. Tape Two\n"
		"3. Tape Three\n" << std::endl;
	std::cin >> choice;

	while (response == "incorrect")
	{
		std::cout << std::endl;

		if (choice == "1")
		{
			std::cout << "You insert the first tape into the machine. It begins to start up.\n"
				"It starts towards the end of one of the comedy movies that were in the inventory on the base.\n"
				"You decide to take twenty and finish the film. That movie is hilarious!\n"
				"After the movie finishes, you decide that it time to move on to investigate further locations of booze.\n"<< std::endl;

			response = "correct";
		}
		else if (choice == "2")
		{
			std::cout << "You insert the second tape into the machine. It begins to start up.\n"
				"It starts up at the beginning of the tape. It appears to be a recording of birds that naturally inhabit this area.\n"
				"You think to yourself 'This is boring' and turn off the projector.\n"
				"You decide that it time to move on to investigate further locations of booze.\n" << std::endl;

			response = "correct";
		}
		else if (choice == "3")
		{
			std::cout << "You insert the third tape into the machine. It begins to start up.\n"
				"There is only black screen for about two minutes. All of the sudden you hear a crumpling noise.\n"
				"You check the machine. It appears that the tape malfunctioned and ruined the machine in the process.\n" << std::endl;

			response = "correct";
		}
		else
		{
			std::cout << "You have picked an incorrect choice. Please chose again: ";
			std::cin >> choice;
		}
	}

	++fTwoHappened;

	return outcome;
}

/* Function receives the list of rooms and a phrase from the user. It then selects a room to move to based on
* the phrase. It returns a pointer to that room to main so the game can move to that room. */
Room* ConferenceRoom::changeRooms(std::vector<Room*> rooms, std::string phrase)
{
	Room* nextRoom = NULL;
	std::string roomName = "";

	if (phrase == "go back" || phrase == "back" || phrase == "go hallway" || phrase == "hallway")
	{
		roomName = "hallway2";
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
