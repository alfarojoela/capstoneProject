/* Project Name : Capstone Project
Class : CS 467
Team : Team Thing - Ryan Alcorn, Joel Alfaro, Neil Gayeta
File : Hallway2.cpp
Description : Class implementation for Hallway2 room.*/

#include "Hallway2.hpp"

/* Function sets the attributes of this room so they can be called by get functions.*/
void Hallway2::setRoom()
{
	name = "hallway2";
	longDes = "You enter a hallway. This room is connected to many rooms in the base. There are currently two of your\n"
		"crewmembers in this room, Jeff and Barry.\n";
	shortDes = "You return one of the hallways. It is connected to many rooms in the base.\n"
		"Both men that were here before are gone.\n";
	exitLong = "This room is connected to other rooms in the base.\nThis includes the mess hall, dog kennel,"
		" basement, conference room, and garage.\n";
	exitShort = "There are five rooms connected to this room.\n";
	fOneHappened = 0;
	fTwoHappened = 0;
	roomEntered = 0;
}

/* Function performs the action for the first feature of the room.*/
int Hallway2::featureOne(Player* user)
{
	int outcome = 0;

	std::cout << "You approach one of the two crewmembers, Jeff. He's not someone you usually hang out with during downtown.\n"
		"He's a little bit too serious.\n\n"
		"You say, 'Hey Jeff, you know what's going on? I woke up in MacReady's room.'\n'I've heard screaming and seen strange things around the base.'\n\n"
		"'It's nothing. Just the dogs causing a bit of trouble again.'\n'You're probably still drunk. How can you trust what you've seen?', says Jeff.\n\n"
		"'Don't listen to this guy', Barry chimes in pointing at Jeff. 'There's something off about him right now'.\n"
		"You stare at them both. They look like they usually do. You notice Jeff staring intently at Barry.\n\n"
		"Jeff says, 'You two can fret about the dogs all you want. I'm going to go get some shuteye.'\n"
		"'I suggest you do the same, drunkern' he says pointing at you.\n"
		"Jeff exits the room. The guy's usually a jerk, but today he seems like it moreso.\n" << std::endl;

	++fOneHappened;

	return outcome;
}

/* Function performs the action for the second feature of the room.*/
int Hallway2::featureTwo(Player* user)
{
	int outcome = 0;

	//Different NPC dialogues happen based on which feature is chosen first
	if (getFeatureOneHap() == 1)
	{
		std::cout << "You approach Barry. He's one of the more chill members of the base.\n"
			"'Something's off with Jeff, man.', he says.\n'He came in the room and stared at me for a couple of minutes before you showed up.'\n\n"
			"He continues, 'There's something going on here. I got a bad feeling.'\n"
			"'I don't think I can trust anyone besides you.'\n"
			"You stare at him. He's acting more normal than Jeff was.\n\n"
			"'You look like you're trying to figure things out. I know some things that can help you.', he says.\n"
			"'And it appears you've had a long night so you might not remember everything right now.'\n" << std::endl;
	}
	else
	{
		std::cout << "You approach Barry. He's one of the more chill members of the base.\n"
			"'There's something going on here. I got a bad feeling.', he says.\n"
			"'You look like you're trying to figure things out. I know some things that can help you.'\n"
			"'And it appears you've had a long night so you might not remember everything right now.'\n" << std::endl;
	}

	//Gives a hint to the user if they don't have the flamethrower
	if (!user->checkInventory("flamethrower"))
	{
		std::cout << "Barry says, 'You remember where the flamethrower is?'\nIt's in the garage, but you have to remember the code to open the locker.'\n"
			"'I don't know the code. I'm only a chef. They don't trust me with that information.'\n" << std::endl;
	}

	std::cout << "Barry says, 'If something crazy is going on, you can contact the military.'\n"
		"'Our research is too valuable to fall into enemy hands. You can reach them in the radio room.'\n"
		"'I'm sure they'd be able to help us out.'\n"
		"'Let me know what you find out. I'm really scared, man.'\n"
		"He does not look well. It's probably best to go investigate the rest of the base.\n" << std::endl;

	++fTwoHappened;

	return outcome;
}
