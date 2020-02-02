/* Project Name : Capstone Project
Class : CS 467
Team : Team Thing - Ryan Alcorn, Joel Alfaro, Neil Gayeta
File : Garage.cpp
Description : Class implementation for Garage room.*/

#include "Garage.hpp"

/* Function sets the attributes of this room so they can be called by get functions.*/
void Garage::setRoom()
{
	name = "garage";
	longDes = "You enter the garage. This area contains the snowmobiles used in excursions outside of the base.\n"
		"There is currently one snowmobile in the room. It could be a potential means of escape.\n"
		"There are other bases located nearby...\nThere is also a locker containing a flamethrower.\n";
	shortDes = "You return to the garage. The area where the snowmobiles are stored.\n";
	exitLong = "There is a hallway which connects to other rooms in the base like the mess hall from the way you came.\n";
	exitShort = "There is a hallway from the direction you came.\n";
	fOneHappened = 0;
	fTwoHappened = 0;
	roomEntered = 0;
}

/* Function performs the action for the first feature of the room.*/
int Garage::featureOne(Player* user)
{
	int outcome = 0;

	std::cout << "Use the code to get the flamethrower" << std::endl;

	++fOneHappened;

	return outcome;
}

/* Function performs the action for the second feature of the room.*/
int Garage::featureTwo(Player* user)
{
	int outcome = 0;

	std::cout << "You decide to see if the snowmobile is working. Like many things in the base, this vehicle is older.\n"
		"It has had to be fixed a couple of times, but it has been running recently.\n"
		"It's strange that the other snowmobile is missing...\n"
		"You grab the key from a nearby table and attempt to turn the ignition...\n"
		"The engine begins to start up, but ultimately doesn't crank over.\n"
		"It was a good idea, but it looks like there's no easy way out of this situation.\n"<< std::endl;

	++fTwoHappened;

	return outcome;
}

/* Function receives the list of rooms and a phrase from the user. It then selects a room to move to based on
* the phrase. It returns a pointer to that room to main so the game can move to that room. */
Room* Garage::changeRooms(std::vector<Room*> rooms, std::string phrase)
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
