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
	exitLong = "There is a hallway which connects to other rooms in the base like the mess hall from the way you came(west).\n";
	exitShort = "There is a hallway from the direction you came(west).\n";
	fOneHappened = 0;
	fTwoHappened = 0;
	roomEntered = 0;
}

/* Function performs the action for the first feature of the room where the player can obtain the flamethrower.*/
int Garage::featureOne(Player* user)
{
	int outcome = 0;

	std::cout << "You approach the case containing the flamethrower. This is a powerful tool that could be useful to you.\n"
		"It is currently sitting in a locker since it is also very dangerous to use. Especially inside!\n"
		"You attempt to open the locker with a code.\n"<< std::endl;

	if (user->checkInventory("toilet paper"))
	{
		std::cout << "You pull out the toilet paper you found in the Latrine since it has the code to the locker written on it.\n"
			"You type in 5...\n3...\n9...\n2...\nThe locker opens.\n"
			"'Nothing's going to mess with me now!', you think.\n"
			"You obtain the flamethrower!" << std::endl;

		//Removes the flamethrower from the room's inventory into the player's inventory
		removeItem("flamethrower", user);

		//Allows the user to interact with the feature multiple times compared to other feature functions.
		++fOneHappened;
	}
	else
	{
		std::cout << "You can't quite remember the code. You think it starts with a 5...\n"
			"You input a few codes, but the locker isn't opening.\n"
			"You decide to give up. You're not going to be able to open it right now." << std::endl;
	}

	return outcome;
}

/* Function performs the action for the second feature of the room the player checks if the snowmobile is working.*/
int Garage::featureTwo(Player* user)
{
	int outcome = 0;

	std::cout << "You decide to see if the snowmobile is working. Like many things in the base, this vehicle is older.\n"
		"It has had to be fixed a couple of times, but it has been running recently.\n"
		"It's strange that the other snowmobile is missing...\n"
		"\nYou grab the key from a nearby table and attempt to turn the ignition...\n"
		"The engine begins to start up, but ultimately doesn't crank over.\n"
		"It was a good idea, but it looks like there's no easy way out of this situation."<< std::endl;

	++fTwoHappened;

	return outcome;
}
