/* Project Name: Capstone Project
   Class: CS 467
   Team: Team Thing- Ryan Alcorn, Joel Alfaro, Neil Gayeta
   File: Latrine.cpp
   Description: Class implementation for Latrine room.*/

#include "Latrine.hpp"

/* Function sets the attributes of this room so they can be called by get functions.*/
void Latrine::setRoom()
{
	name = "latrine";
	longDes = "You enter the latrine. This is the area of the base that contains the restroom.\n"
		"This room usually does not smell good. It's not a room you want to stay in for long,\nbut you think you remember booze being in here."
		" You notice some toilet paper in an odd location in the room.\nYou also have the need to use the restroom.\n";
	shortDes = "You return to the latrine. It's a bathroom.\n";
	exitLong = "The hallway which connects to many rooms in the base including the research lab and sick bay is from the way you came.\n";
	exitShort = "There is a hallway from the direction you came.\n";
	fOneHappened = 0;
	fTwoHappened = 0;
	roomEntered = 0;
}

/* Function performs the action for the first feature of the room. Player can gain the toilet paper from the feature.*/
int Latrine::featureOne(Player* user)
{
	int outcome = 0;
	int index = 0;

	std::cout << "You decide to inspect the toilet paper. It is sprawled on the ground in an abnormal way.\n"
		"Either someone's pulling a prank or something's going on.\n"
		"The writing on the toilet paper appears to be in charcoal. This is weird.\n"
		"There are numbers written on here. 5...3...9...2.\n"
		"Someone wrote the code to the flamethrower locker on here. Odd...\n"<< std::endl;


	//Removes the toilet paper from the room using the removeItem function
	removeItem("toilet paper", user);

	++fOneHappened;

	return outcome;
}

/* Function performs the action for the second feature of the room. Player can get hurt in this function.*/
int Latrine::featureTwo(Player* user)
{
	int outcome = 0;
	int number = 0;
	std::string choice = "";
	std::string response = "incorrect";

	std::cout << "You decide to use the restroom. It was a long night.\n"
		"You begin to hear splashing sounds which causes you to have an uneasy feeling.\n"
		"You finish using the restroom and begin to walk away.\n"
		"As you look back all of the sudden something jumps at you!\n"
		"What do you do?\n\n"
		"1. Attack it with your fists\n"
		"2. Attack it with a weapon\n"
		"3. Attempt to dodge the attack\n" << std::endl;
	getline(std::cin, choice);

	while (response == "incorrect")
	{
		if (choice == "1")
		{
			std::cout << std::endl;
			std::cout << "You attack it with your fists. As the thing flies at you, you notice how small it is.\n"
				"Easy enough to punch. You send it flying back into the wall!\n"
				"Whatever that was, it isn't getting up for a while.\n" << std::endl;

			response = "correct";
		}
		else if (choice == "2")
		{
			std::cout << std::endl;

			//Add function to check if user has specific items to protect themselves
			if (user->checkInventory("gun") || user->checkInventory("flamethrower") || user->checkInventory("axe"))
			{
				std::cout << "You attack the creature with a weapon. It stood no chance!\n"
					"Pieces of the creature scatter across the room. Is this real or are you still dreaming in a drunken stupor?\n" << std::endl;

				//Call function to remove item from inventory or set its singleUse to 1

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
			std::cout << std::endl;
			std::cout << "You attempt to dodge the incoming attack!" << std::endl;
			std::cout << std::endl;

			//Random chance the player will get hurt
			number = rand() % 100 + 1;

			if (number > 50)
			{
				std::cout << "You successfully dodge the attack! The creature flies by you while shrieking.\n"
					"It lands on the ground hard and appears not to be moving.\n"<< std::endl;
			}
			else
			{
				std::cout << "You are too slow! The creature bites you in the shoulder. You feel an intense pain.\n"
					"Reflexively, you grab it and fling it against the wall. The creature appears to stop moving.\n"
					"You lose one health!\n" << std::endl;

				//Outcome set to 1 to call function to lose health
				outcome = 1;
			}

			response = "correct";
		}

		if (choice != "1" && choice != "2" && choice != "3")
		{
			std::cout << "You have picked an incorrect choice. Please chose again: ";
			getline(std::cin, choice);
		}
	}

	++fTwoHappened;

	return outcome;
}
