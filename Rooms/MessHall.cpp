/* Project Name : Capstone Project
Class : CS 467
Team : Team Thing - Ryan Alcorn, Joel Alfaro, Neil Gayeta
File : MessHall.cpp
Description : Class implementation for MessHall room.*/

#include "MessHall.hpp"

/* Function sets the attributes of this room so they can be called by get functions.*/
void MessHall::setRoom()
{
	name = "messHall";
	longDes = "You enter the mess hall. This is the area of the base where the crew would gather to share their meals together\n"
		"and share stories. This is one of the larger rooms in the base considering it has to seat all of the crew members.\n"
		"You notice what looks like an untouched meal on one of the tables. There's also a bottle of booze on another table.\n";
	shortDes = "You return to the mess hall. The room where the crew ate their meals together.\n";
	exitLong = "A hallway which connects to many rooms in the base including the conference room and garage is east of you.\n"
		"The galley is also south of your location.\n";
	exitShort = "There is a hallway to the east and the galley to the south.\n";
	fOneHappened = 0;
	fTwoHappened = 0;
	roomEntered = 0;
}

/* Function performs the action for the first feature of the room where the player can get food to gain health.*/
int MessHall::featureOne(Player* user)
{
	int outcome = 0;
	std::string choice = "";
	std::string response = "incorrect";

	std::cout << "You make your way over to the food. It's a plate of spaghetti!\n"
		"You are extremely hungry right now.\n"
		"What do you do?\n\n"
		"1. Eat the food\n"
		"2. Walk away"<< std::endl;
	std::cin >> choice;

	while (response == "incorrect")
	{
		if (choice == "1")
		{
			std::cout << std::endl;
			std::cout << "You decide to eat the spaghetti. After taking the first bite you can tell it has been sitting out for a bit.\n"
				"It's still slightly warm and helps with the hangover. You take 15 minutes to eat the plate of spaghetti.\n"
				"You gain one health!"<< std::endl;

			//Player gains a health through function call or by outcome being set to 3
			outcome = 3;

			response = "correct";
		}
		else if (choice == "2")
		{
			std::cout << std::endl;
			std::cout << "You decide to not eat the food. It isn't booze, who cares?" << std::endl;

			response = "correct";
		}
		else
		{
			std::cout << "You have picked an incorrect choice. Please chose again: ";
			std::cin >> choice;
		}
	}
	std::cout << std::endl;

	++fOneHappened;

	return outcome;
}

/* Function performs the action for the second feature of the room where the player could potentally gain a bottle of gin or get hurt.*/
int MessHall::featureTwo(Player* user)
{
	int outcome = 0;
	int number = 0;
	std::string choice = "";
	std::string response = "incorrect";

	std::cout << "You approach the bottle of booze. As you get closer you notice that it is empty.\n"
		"This feels you with anger.\n"
		"What do you do?\n\n"
		"1. Throw the bottle against the wall\n"
		"2. Decide it's not worth it and walk away"<< std::endl;
	std::cin >> choice;

	while (response == "incorrect")
	{
		if (choice == "1")
		{
			std::cout << std::endl;
			std::cout << "You are so angry! You grab the top of the bottle." << std::endl;

			//Random chance the player will get hurt or obtain an item
			number = rand() % 100 + 1;

			if (number > 50)
			{
				std::cout << "You chuck the bottle against the wall. It shatters and pieces fly everywhere.\n"
					"As you are walking away, you notice a bottle of Beef Eater Gin behind a counter.\n"
					"You pick it up. You obtain a bottle of gin!" << std::endl;

				removeItem("gin", user);
			}
			else
			{
				std::cout << "You chuck the bottle against the wall. It shatters and pieces fly everywhere.\n"
					"A piece ricochets back at you cutting your arm.\n"
					"You lose one health!" << std::endl;

				//Outcome set to 1 to call function to lose health
				outcome = 1;
			}

			response = "correct";
		}
		else if (choice == "2")
		{
			std::cout << std::endl;
			std::cout << "You decide to walk away and not take your anger out on a random bottle.\n"
				"As you are walking away, you notice a bottle of Beef Eater Gin behind a counter.\n"
				"You pick it up. You obtain a bottle of gin!"<< std::endl;

			removeItem("gin", user);

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
