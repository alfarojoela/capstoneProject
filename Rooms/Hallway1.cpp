/* Project Name: Capstone Project
   Class: CS 467
   Team: Team Thing- Ryan Alcorn, Joel Alfaro, Neil Gayeta
   File: Hallway1.cpp
   Description: Class implementation for the first Hallway room.*/

#include "Hallway1.hpp"

   /* Function sets the attributes of this room so they can be called by get functions.*/
void Hallway1::setRoom()
{
	name = "hallway1";
	longDes = "You enter a hallway. This hallway is connected to many of the important rooms inside the base.\n"
		"There appears to be nobody around right now. There is a terrible smell emanating from the room.\n"
		"You notice the floor has a trail of red streaks on it.  The lights are blinking on and off. The room wasn't like this yesterday...\n";
	shortDes = "You enter a hallway. This hallway is connected to many rooms. The lights are blinking on and off. On and off.\n";
	exitLong = "This room is connected to many other rooms in the base.\n"
		"This includes the radio room to the east where members of the crew can contact the outside world,\n"
		"the equipment room to the northeast where the crew stores useful equipement,\n"
		"the sick bay to the west where ill or injured members are taken care of,\n"
		"the research lab to the southwest where members of the crew conduct research on the base,\n"
		"and the latrine to the northwest which is a toilet.\n";
	exitShort = "There are five rooms connected to this hallway. The radio room to the east,\n"
		"the equipment room to the northeast, the sick bay to the west, the research lab to the southwest,\n"
		"and the latrine to the northwest.\n";
	fOneHappened = 0;
	fTwoHappened = 0;
	roomEntered = 0;
}

/* Function performs the action for the first feature of the room.*/
int Hallway1::featureOne(Player* user)
{
	int outcome = 0;

	std::cout << "You decide to check out the blood. The room reeks of an unfamiliar smell. It is not a pleasant smell.\n"
		"The blood is scattered across the wall through the hallway. It looks like a Picasso painting.\n"
		"Or even something out of one of the those horror films. Like the one's that Carpenter guy used to direct.\n"
		"It is a disturbing sight. Something big went down in here...\n"<< std::endl;

	//Increases the variable to get one of the endings of the game.
	user->setDeathWish(1);
	std::cout << "You gain a little bit of knowledge about what's going on!" << std::endl;

	++fOneHappened;

	//Give the axe to the player if this is the first feature they've done in the room.
	if (user->checkInventory("axe") == 0 && getFeatureTwoHap() == 0)
	{
		obtainAxe(user);
	}

	return outcome;
}

/* Function performs the action for the second feature of the room.*/
int Hallway1::featureTwo(Player* user)
{
	int outcome = 0;

	std::cout << "You decide to check out the lights situation. The switch is on the other side of the hallway.\n"
		"You begin to make your way across the hallway. Each time the hallway goes dark, you get an uneasy feeling.\n"
		"Or maybe you're just hungover.\nYou make it to the light switch. It appears to be in functional condition.\n"
		"All of the sudden something rushes past your leg. It felt like a dog, but at the same time unnatural.\n"
		"This place is starting to give you the creeps.\n"<< std::endl;

	//Increases the variable to get one of the endings of the game.
	user->setDeathWish(1);
	std::cout << "You gain a little bit of knowledge about what's going on!" << std::endl;

	++fTwoHappened;

	//Give the axe to the player if this is the first feature they've done in the room.
	if (user->checkInventory("axe") == 0 && getFeatureOneHap() == 0)
	{
		obtainAxe(user);
	}

	return outcome;
}

//Function allows the player to gain an item at the beginning of the game.
void Hallway1::obtainAxe(Player* user)
{
	//Gives different descriptions depending on which feature the function came from.
	if (getFeatureOneHap() == 1 && getFeatureTwoHap() == 0)
	{
		std::cout << "\nAfter seeing the unsettling sight of the blood in the room, you decide to pick up the axe hanging on the wall.\n"
			"You never know what's going to happen. Best be prepared.\n"
			"You obtain an axe!"<< std::endl;
	}
	else if (getFeatureOneHap() == 0 && getFeatureTwoHap() == 1)
	{
		std::cout << "\nAfter having the unsettling feeling of something rush past your leg, you decide to pick up the axe hanging on the wall.\n"
			"You never know what's going to happen. Best be prepared.\n"
			"You obtain an axe!" << std::endl;
	}

	//Removes the axe from the room's inventory and give it to the player.
	removeItem("axe", user);
}
