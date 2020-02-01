/* Project Name : Capstone Project
Class : CS 467
Team : Team Thing - Ryan Alcorn, Joel Alfaro, Neil Gayeta
File : ToolShed.cpp
Description : Class implementation for ToolShed room.*/

#include "ToolShed.hpp"

/* Function sets the attributes of this room so they can be called by get functions.*/
void ToolShed::setRoom()
{
	name = "toolShed";
	longDes = "You make your way towards the tool shed. It is located outside of the base. It is freezing cold outside.\n"
		"Hopefully you can find something worthwhile in there.\n";
	shortDes = "You return to the tool shed. It contains useful equipment.\n";
	exitLong = "The equipment room which leads back into the base is from the way you came.\n";
	exitShort = "The equipment room is from the direction you came.\n";
	fOneHappened = 0;
	fTwoHappened = 0;
	roomEntered = 0;
}

/* Function performs the action for the first feature of the room.*/
int ToolShed::featureOne(Player* user)
{
	int outcome = 0;

	std::cout << "Notice footprints or groaning, get attacked, fight or flee." << std::endl;

	++fOneHappened;

	return outcome;
}

/* Function performs the action for the second feature of the room.*/
int ToolShed::featureTwo(Player* user)
{
	int outcome = 0;
	std::string choice = "";
	std::string response = "incorrect";

	std::cout << "As you make your way towards the tool shed, you notice a glint in the snow.\n" 
		"Your body is getting colder and colder, but there could be something useful there.\n"
		"What do you do?\n\n"
		"1. Head deeper into the snow to obtain the item\n"
		"2. Continue on your path to the tool shed" << std::endl;
	std::cin >> choice;

	while (response == "incorrect")
	{
		std::cout << std::endl;

		if (choice == "1")
		{
			std::cout << "Today's been crazy already why not see what this is! You head towards the glinting item in the snow.\n"
				"The item becomes more clear as you move closer. It is a bottle of Maker's Mark. You could always use more alcohol.\n"
				"You obtain a bottle of Maker's Mark!" << std::endl;

			//Function call to gain Maker's Mark bottle

			response = "correct";
		}
		else if (choice == "2")
		{
			std::cout << "You decide not to risk it and continue on the path to the tool shed." << std::endl;

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
Room* ToolShed::changeRooms(std::vector<Room*> rooms, std::string phrase)
{
	Room* nextRoom = NULL;
	std::string roomName = "";

	if (phrase == "go back" || phrase == "back" || phrase == "go hallway" || phrase == "hallway")
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
