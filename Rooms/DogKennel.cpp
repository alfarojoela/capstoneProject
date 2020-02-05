/* Project Name : Capstone Project
Class : CS 467
Team : Team Thing - Ryan Alcorn, Joel Alfaro, Neil Gayeta
File : DogKennel.cpp
Description : Class implementation for DogKennel room.*/

#include "DogKennel.hpp"

/* Function sets the attributes of this room so they can be called by get functions.*/
void DogKennel::setRoom()
{
	name = "dogKennel";
	longDes = "You enter the dog kennel. The base had 7 dogs that were housed in this room.\n"
		"There isn't seven dogs here now. You hear panting from the corner of the room. You can investigate that.\n"
		"You also notice something glinting on a shelf in another corner of the room.\n";
	shortDes = "You return to the dog kennel. Where'd all the dogs go?\n";
	exitLong = "There is a hallway which connects to other rooms in the base like the conference room from the way you came.\n";
	exitShort = "There is a hallway from the direction you came.\n";
	fOneHappened = 0;
	fTwoHappened = 0;
	roomEntered = 0;
}

/* Function performs the action for the first feature of the room.*/
int DogKennel::featureOne(Player* user)
{
	int outcome = 0;
	std::string choice = "";
	std::string response = "incorrect";

	std::cout << "You decide to investigate the noise you heard. You never know, it could be an injured crew member.\n"
		"The noise is coming from the corner of the room. You begin to head over to it.\n"
		"The noise begins to change from a panting sound to a growl. Low at first.\n"
		"The growl begins to get louder the closer you get.\n"
		"All of the sudden something jumps out at you!\n"
		"What do you do?\n\n"
		"1. Attack it with your fists\n"
		"2. Attack it with a weapon\n"
		"3. Attempt to flee\n"<< std::endl;
	std::cin >> choice;

	while (response == "incorrect")
	{
		std::cout << std::endl;

		if (choice == "1")
		{
			std::cout << "You attack it with your fists. You have no formal training in any discipline.\n"
				"But you're surprised that you connect with a hit. The creature appears to be a dog, but malformed.\n"
				"It scurries off after the hit.\n"
				"You do notice that the creature scratched you pretty good on the arm. Blood is gushing from a cut.\n"
				"You lose one health!"<< std::endl;

			//Outcome set to 1 to call function to lose health
			outcome = 1;

			response = "correct";
		}
		else if (choice == "2")
		{
			if (choice == "2")
			{
				std::cout << "You attack the creature with the weapon. It stood no chance.\n"
					"It only takes one swift blow and the growling has ceased. Its body lays on the floor below you."<< std::endl;

				//Call function to remove item from inventory

				response = "correct";
			}
			else
			{
				std::cout << "You do not have a weapon to fend off the creature!" << std::endl;
				choice = "3";
			}
		}
		
		if (choice == "3")
		{
			std::cout << "You attempt to flee. You do not like the sounds this creature is making!\n"
				"Unfornately you are too slow. The creature barrels into your legs knocking you over.\n"
				"You hit your head on the wall nearby!\n"
				"The creature stands over you and the last thing you see is the creature's teeth going for your neck..." << std::endl;

			//Outcome set to 2 which means player death and game over
			outcome = 2;

			response = "correct";
		}
		
		if(choice != "1" && choice != "2" && choice != "3")
		{
			std::cout << "You have picked an incorrect choice. Please chose again: ";
			std::cin >> choice;
		}
	}
	std::cout << std::endl;

	++fOneHappened;

	return outcome;
}

/* Function performs the action for the second feature of the room.*/
int DogKennel::featureTwo(Player* user)
{
	int outcome = 0;
	int number = 0;
	std::string choice = "";
	std::string response = "incorrect";

	std::cout << "You head towards the corner where you see a shimmering object.\n"
		"It's on a shelf that is too tall for you to grab just standing up. You could jump for it.\n"
		"What do you do?\n\n"
		"1. Jump for the object\n"
		"2. Ignore the object\n" << std::endl;
	std::cin >> choice;

	while (response == "incorrect")
	{
		std::cout << std::endl;

		if (choice == "1")
		{
			std::cout << "You attempt to jump for the object." << std::endl;

			number = rand() % 100 + 1;

			if (number > 30)
			{
				std::cout << "You jump and grab the object while landing perfectly.\n"
					"You are surprised by how spry you are considering how hungover you are." << std::endl;
			}
			else
			{
				std::cout << "You jump and grab the object, but fall awkwardly.\n"
					"You land heavily on your knee. The pain is intense.\n"
					"You lose one health!" << std::endl;

				//Outcome set to 1 to call function to lose health
				outcome = 1;
			}

			std::cout << "You obtain a petri dish!" << std::endl;

			response = "correct";
		}
		else if (choice == "2")
		{
			std::cout << "You decide to ignore the object. Doesn't look like booze anyways!" << std::endl;

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
