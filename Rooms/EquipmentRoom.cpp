/* Project Name : Capstone Project
Class : CS 467
Team : Team Thing - Ryan Alcorn, Joel Alfaro, Neil Gayeta
File : EquipmentRoom.cpp
Description : Class implementation for EquipmentRoom room.*/

#include "EquipmentRoom.hpp"

/* Function sets the attributes of this room so they can be called by get functions.*/
void EquipmentRoom::setRoom()
{
	name = "equipmentRoom";
	longDes = "You enter the equipment room. The room is currently pitch black. There must be a light switch in here somewhere.\n";
	shortDes = "You return to the equipment room. It contains equipment used on the base.\n";
	exitLong = "The hallway which connects to many rooms in the base including the research lab and sick bay is from the way you came.\n"
		"There is a tool shed located to the east.\n";
	exitShort = "There is a hallway from the direction you came and a tool shed to the east.\n";
	fOneHappened = 0;
	fTwoHappened = 0;
	roomEntered = 0;
}

/* Function performs the action for the first feature of the room. Player could die in the function.*/
int EquipmentRoom::featureOne(Player* user)
{
	int outcome = 0;
	int number = 0;
	std::string choice = "";
	std::string response = "incorrect";

	std::cout << "You can either find the light switch and turn it on or progress through the room in the dark.\n"
		"You do know this room very well since you work in here frequently.\n"
		"What do you do?\n\n"
		"1. Find the light switch\n"
		"2. Progress through the room in the dark\n"<< std::endl;
	std::cin >> choice;

	while (response == "incorrect")
	{
		if (choice == "1")
		{
			std::cout << std::endl;
			std::cout << "You know there's gotta be a light switch on the wall next to you.\n"
				"You reach around the wall in an attempt to find it.\n"
				"You hear a scream somewhere off in the base. This urges you even more to find the switch.\n"
				"After about 20 seconds you find the switch!\n\n"
				"You see the room contains a lot of different equipment. Most isn't useful to you right now.\n"
				"You do see a blow torch in a glass case across the room."<< std::endl;

			response = "correct";
		}
		else if (choice == "2")
		{
			std::cout << std::endl;
			std::cout << "You attempt to cross the room through the dark!\n" << std::endl;

			//Random chance that the player will die or make it to the other side of the room
			number = rand() % 100 + 1;

			if (number < 21)
			{
				std::cout << "You slowly make your way across the room.\n"
					"About midway through the room, you hear a scream somewhere off in the base!\n"
					"You ignore it and make it to the other side. Your hand touches the wall on top of a light switch.\n"
					"You turn on the lights and see a blow torch in a glass case next to you." << std::endl;
			}
			else
			{
				std::cout << "You slowly make your way across the room.\n"
					"About midway through the room, you hear a scream somewhere off in the base!\n"
					"You focus on the intense cry. So much so that you trip.\n"
					"You feel a sharp pain and then nothing!" << std::endl;

				//Outcome set to 2 which means player death and game over
				outcome = 2;
			}

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

/* Function performs the action for the second feature of the room. Player could potentally die in the function.*/
int EquipmentRoom::featureTwo(Player* user)
{
	int outcome = 0;
	int index = 0;
	int number = 0;
	std::string choice = "";
	std::string response = "incorrect";

	std::cout << "You approach the case containing the blow torch. It is in a glass case.\n"
		"What do you do?\n\n"
		"1. Break it with your fist\n"
		"2. Ignore the case\n";
	//Checks if the user has the axe to unlock a secret option
	if (user->checkInventory("axe"))
	{
		std::cout << "3. Use the axe\n" << std::endl;
		std::cin >> choice;
	}
	else
	{
		std::cin >> choice;
	}

	while (response == "incorrect")
	{
		if (choice == "1")
		{
			std::cout << std::endl;
			std::cout << "You attempt to break the glass with your fists!\n" << std::endl;

			//Random chance that the player dies
			number = rand() % 100 + 1;

			if (number < 21)
			{
				std::cout << "You successfully break the glass! Somehow you don't even cut yourself!\n"
					"You obtain the blow torch!" << std::endl;

				//Removes the blow torch from the room using the removeItem function
				removeItem("blow torch", user);
			}
			else
			{
				std::cout << "You break the glass but severely cut yourself in the process!\n"
					"You reach for the blow torch, but stumble as blood gushes out of your arm.\n"
					"You feel very dizzy and then feel nothing." << std::endl;

				//Outcome set to 2 which means player death and game over
				outcome = 2;
			}

			response = "correct";
		}
		else if (choice == "2")
		{
			std::cout << std::endl;
			std::cout << "You decide to ignore the blow torch. It isn't booze anyways!" << std::endl;

			response = "correct";
		}
		else if (user->checkInventory("axe") && choice == "3")
		{
			std::cout << std::endl;
			std::cout << "You decide to break the glass with the axe you found. You take a step back and take a swing.\n"
				"The glass shatters easily and falls to the ground.\n"
				"You obtain the blow torch!" << std::endl;

			//Removes the blow torch from the room using the removeItem function
			removeItem("blow torch", user);

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
