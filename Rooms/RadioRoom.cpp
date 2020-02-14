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
		"You see the radio equipment in the corner of the room.\nThere is also equipment on the other side of the room used to speak with the military.\n";
	shortDes = "You return to the radio room. It contains equipement to contact the outside world.\n";
	exitLong = "The hallway which connects to many rooms in the base including the research lab and sick bay is from the way you came.\n";
	exitShort = "There is a hallway from the direction you came.\n";
	fOneHappened = 0;
	fTwoHappened = 0;
	roomEntered = 0;
}

/* Function performs the action for the first feature of the room where the player can interact with the radio.*/
int RadioRoom::featureOne(Player* user)
{
	int outcome = 0;
	int rightAnswer = 0;
	std::string choice = "";
	std::string response = "incorrect";

	std::cout << "You approach the radio system. Since the base is performing advanced research, the equipment here is advanced.\n"
		"You do not have good knowledge of this technology.\nEven so, it could be useful to contact someone considering what's been going on.\n"
		"There are many buttons to press and knobs to turn on the system.\n"
		"You turn the system on by pressing the power button.\n"
		"What do you do next?\n\n"
		"1. Press the big grey button that says STANDBY\n"
		"2. Press the black button that says TALK"<< std::endl;
	getline(std::cin, choice);

	while (response == "incorrect")
	{
		if (choice == "1")
		{
			std::cout << std::endl;
			std::cout << "You push the button that says STANDBY. All of the sudden you here static.\n"
				"It seems like the radio's functioning correctly." << std::endl;

			//Increments a counter that displays additional text at the end of the function if the requirements are met.
			++rightAnswer;

			response = "correct";
		}
		else if (choice == "2")
		{
			std::cout << std::endl;
			std::cout << "You press the black button that says TALK. Nothing happens.\n"
				"You were not expecting this result. You get frustrated. It's been a long day.\n"
				"In a fit of rage you get up and slam the chair into the radio.\n"
				"The radio explodes and sparks fly out. You get hit in the arm.\n"
				"You lose one grit!\n"<< std::endl;

			//Calls the gritHit function to cause the player to lose health.
			user->gritHit(1);

			std::cout << "After everything calms down you notice some copper wire sticking out of the wreckage of the system.\n"
				"You decide to pick it up.\n"
				"You obtain copper wire!\n" << std::endl;

			//Removes the copper wire from the room and gives it to the player.
			removeItem("copper wire", user);

			response = "correct";
		}
		else
		{
			std::cout << "You have picked an incorrect choice. Please chose again: ";
			getline(std::cin, choice);
		}
	}

	response = "incorrect";

	//If statement runs if the player performed the first action correctly
	if (rightAnswer == 1)
	{
		std::cout << "What do you do next?\n\n"
			"1. Move the big knob to the left\n"
			"2. Move the big knob to the right" << std::endl;
		getline(std::cin, choice);

		while (response == "incorrect")
		{
			if (choice == "1")
			{
				std::cout << std::endl;
				std::cout << "You turn the knob to the left. The static goes away.\n"
					"Sounds like you found the correct channel and can speak to someone now." << std::endl;

				//Increments a counter that displays additional text at the end of the function if the requirements are met.
				++rightAnswer;

				response = "correct";
			}
			else if (choice == "2")
			{
				std::cout << std::endl;
				std::cout << "You turn the knob to the right. Nothing happens.\n"
					"You were not expecting this result. You get frustrated. It's been a long day.\n"
					"In a fit of rage you get up and slam the chair into the radio.\n"
					"The radio explodes and sparks fly out. You get hit in the arm.\n"
					"You lose one grit!\n" << std::endl;

				//Calls the gritHit function to cause the player to lose health.
				user->gritHit(1);

				std::cout << "After everything calms down you notice some copper wire sticking out of the wreckage of the system.\n"
					"You decide to pick it up.\n"
					"You obtain copper wire!\n" << std::endl;

				//Removes the copper wire from the room and gives it to the player.
				removeItem("copper wire", user);

				response = "correct";
			}
			else
			{
				std::cout << "You have picked an incorrect choice. Please chose again: ";
				getline(std::cin, choice);
			}
		}
	}

	//If statement runs if the player performed the first and second action correctly
	if (rightAnswer == 2)
	{
		std::cout << "You press the button that says TALK. 'Hello, anyone out there?', you say.\n"
			"You hear nothing for about twenty seconds.\n\n'Hei hvem er dette' you hear coming back from the radio.\n"
			"You don't understand this language. It must be from one of the other bases around here.\n\n"
			"'We need help over! Something weird is going on. This is the American base', you say.\n"
			"'Det myrdet alle! Hjelppppppppp!', the voice says. The voice starts out normal and then begins to scream.\n"
			"The screaming lasts for about twenty seconds and then dies down.\n\n"
			"You wait for about a minute longer, but hear nothing.\n"
			"Something must be going on at their base too. Is it a Russian attack, you think?\n" << std::endl;

		std::cout << "You turn the knob a full cycle through, but get no other channels.\n"
			"You decide to leave the radio equipment alone.\n\n"
			"You notice some copper wire on the ground next to your chair. You decide to pick it up.\n"
			"You obtain copper wire!\n" << std::endl;

		//Removes the copper wire from the room and gives it to the player.
		removeItem("copper wire", user);
	}

	++fOneHappened;

	return outcome;
}

/* Function performs the action for the second feature of the room.*/
int RadioRoom::featureTwo(Player* user)
{
	int outcome = 0;

	std::cout << "Feature Two: Player decides to destroy the base." << std::endl;

	++fTwoHappened;

	return outcome;
}
