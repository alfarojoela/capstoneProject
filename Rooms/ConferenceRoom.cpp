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
	int counter = 0;
	std::string choice = "1";
	std::string response = "incorrect";

	std::cout << "You hurry towards the bottle sitting in the middle of the table.\n"
		"You take a swig.\n" << std::endl;

	//While loop runs until the player decides to exit or they take 8 drinks
	while (response == "incorrect" && counter < 8)
	{
		//If the player chose 1, the question is asked again.
		if (choice == "1")
		{
			std::cout << "Keep drinking?\n"
				"1. Yes\n"
				"2. No" << std::endl;
			std::cin >> choice;

			++counter;
		}

		if (choice == "1")
		{
			std::cout << std::endl;
			std::cout << "You take another drink." << std::endl;
		}
		else if (choice == "2")
		{
			std::cout << std::endl;
			std::cout << "You decide you've had enough." << std::endl;

			response = "correct";
		}
		else
		{
			std::cout << "You have picked an incorrect choice. Please chose again: ";
			std::cin >> choice;
		}

		//Lines print out based off of how many drinks the player has had.
		if (counter == 3)
		{
			std::cout << "You feel buzzed now. Getting back to the same level as last night." << std::endl;
		}

		if (counter == 6)
		{
			std::cout << "You feel pretty drunk. Things are getting slower." << std::endl;
		}

		if (counter == 8)
		{
			std::cout << "You pass out.\n"
				"When you wake up, something is standing over you.\n"
				"It looks human, but it's face looks like it's shrieking. There is no noise coming out though.\n"
				"It reaches its hand towards your face! That's the last thing you see." << std::endl;

			//Player drinks too much and dies causing outcome to be set to two
			outcome = 2;
		}
	}
	std::cout << std::endl;

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
		"3. Tape Three" << std::endl;
	std::cin >> choice;

	while (response == "incorrect")
	{
		if (choice == "1")
		{
			std::cout << std::endl;
			std::cout << "You insert the first tape into the machine. It begins to start up.\n"
				"It starts towards the end of one of the comedy movies that were in the inventory on the base.\n"
				"You decide to take twenty and finish the film. That movie is hilarious!\n"
				"After the movie finishes, you decide that it time to move on to investigate further locations of booze.\n"<< std::endl;

			response = "correct";
		}
		else if (choice == "2")
		{
			std::cout << std::endl;
			std::cout << "You insert the second tape into the machine. It begins to start up.\n"
				"It starts up at the beginning of the tape. It appears to be a recording of birds that naturally inhabit this area.\n"
				"You think to yourself 'This is boring' and turn off the projector.\n"
				"You decide that it time to move on to investigate further locations of booze.\n" << std::endl;

			response = "correct";
		}
		else if (choice == "3")
		{
			std::cout << std::endl;
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
