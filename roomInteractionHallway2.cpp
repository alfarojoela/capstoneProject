#include "roomInteractionHallway2.hpp"

void roomInteractionHallway2(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList, Parser* parserPtr)
{
	if (commands[0] == "savegame" || commands[0] == "loadgame")
	{
		return;

	}
	/*phrase for looking at room inventory*/
	if (commands[0] == "look" && commands[1] == "for" && commands[2] == "booze")
	{
		std::cout << "You start looking for booze and notice..." << std::endl;
		std::string freeBooze = "beer";

		if (playerLocation->checkItem(freeBooze) != 999)
		{
			std::cout << "There is a case of beer on the floor beside Barry." << std::endl;
			std::cout << "You deduce it isn't Barry's because he is a teetotaler." << std::endl;
			std::cout << "He probably won't mind if you take one." << std::endl;
			std::cout << "After checking the room for booze, you also notice some other potentially useful items." << std::endl;

		}

		playerLocation->itemsInRoom();
		return;
	}

	if ((commands[0] == "use" && commands[2] == "blood test") || (commands[0] == "look" && commands[1] == "at" && commands[2] == "blood"))
	{
		std::cout << "Now is not the time to do a blood test." << std::endl;
		return;
	}

	if (commands[0] == "talk" &&  commands[2] == "jeff")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "He has already left." << std::endl;
			std::cout << "He seems off today." << std::endl;
			return;
		}

		if (playerLocation->getFeatureOneHap() == 0)
		{
			playerLocation->featureOne(playerPtr);
			return;
		}
	}

	if (commands[0] == "talk" && commands[2] == "barry")
	{
		playerLocation->featureTwo(playerPtr);
		return;

	}

	if (commands[0] == "drink")
	{
		drink(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "smell" && commands[2] == "jeff")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "If you wanted to smell him, you missed your chance." << std::endl;
			return;
		}

		else
		{
			std::cout << "You get in close and smell Jeff." << std::endl;
			std::cout << "Everything seems normal about his scent." << std::endl;
			std::cout << "However, he is oblivious to your strange behavior." << std::endl;
			return;
		}
	}

	if (commands[0] == "smell" && commands[2] == "barry")
	{
		std::cout << "You smell Barry." << std::endl;
		std::cout << "Since he works in the galley, he smells a little like the kitchen: a mix of vegetable soup and meatloaf with a bit of dishwater." << std::endl;
		std::cout << "Barry notices your strange behavior of sniffing him." << std::endl;
		std::cout << "He eyes you warily." << std::endl;
		return;
	}

	if (commands[0] == "drop")
	{
		drop(commands, playerLocation, playerPtr, roomList, 2);
		return;
	}

	if (commands[0] == "attack" && commands[2] == "jeff")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "You missed your chance to attack Jeff." << std::endl;
			std::cout << "He has left the room." << std::endl;
			return;
		}

		else
		{
			std::cout << "You clench your fist and cock it back to give Jeff a haymaker." << std::endl;
			std::cout << "Before it lands, his face morphs into a gaping maw of teeth." << std::endl;
			std::cout << "Your fist gets caught in this maw of teeth and is abruptly chewed off." << std::endl;
			std::cout << "The figure formerly known as Jeff approaches you to finish the job." << std::endl;
			playerPtr->setAlive(0);
			return;
		}
	}

	if (commands[0] == "attack" && commands[2] == "barry")
	{
		std::cout << "You clench your fist and cock it back to give Barry a haymaker." << std::endl;
		std::cout << "Barry is quicker and pulls out a meat cleaver and buries it into your skull." << std::endl;
		playerPtr->setAlive(0);
		return;
	}

	if ((commands[0] == "eat" && commands[2] == "barry") || (commands[0] == "eat" && commands[2] == "jeff"))
	{
		std::cout << "Look, I know it's been a few hours since you ate last." << std::endl;
		std::cout << "But that's no reason to try and eat your crew mates." << std::endl;
		std::cout << "Go to the galley or mess hall to look for food." << std::endl;
		return;
	}

	if (commands[0] == "eat")
	{
		eat(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "jump"  && commands[2] == "jeff")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "Jeff has left." << std::endl;
			std::cout << "You missed your chance." << std::endl;
			return;
		}

		else
		{
			std::cout << "You walk up to Jeff nonchalantly." << std::endl;
			std::cout << "You resolve to tackle him." << std::endl;
			std::cout << "He is too quick for you in your hungover condition!" << std::endl;
			std::cout << "Jeff's hands become tentacles and wrap around your neck." << std::endl;
			std::cout << "You struggle to breathe, but the tentacles are too strong." << std::endl;
			std::cout << "Everything goes black." << std::endl;
			return;
		}
	}

	if (commands[0] == "jump" && commands[2] == "barry")
	{

		std::cout << "You walk up to Barry nonchalantly." << std::endl;
		std::cout << "You resolve to tackle him." << std::endl;
		std::cout << "He is too quick for you in your hungover condition!" << std::endl;
		std::cout << "He pulls out a meat tenderizer mallet and bashes you over the head with it." << std::endl;
		std::cout << "You come to and are a tied up in a chair besides Palmer." << std::endl;
		std::cout << "Macready is standing in front of you and holding a petri dish in one hand and copper wire in the other." << std::endl;
		std::cout << "Palmer begins to shake violently and morphs into an inhuman creature." << std::endl;
		std::cout << "He bursts through the ropes holding him down and attacks you." << std::endl;
		std::cout << "Everything goes black." << std::endl;
		playerPtr->setAlive(0);
		return;
	}


	if (commands[0] == "flee"  && commands[2] == "jeff")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "Jeff has already left the room." << std::endl;
			std::cout << "You don't need to flee from him." << std::endl;
			return;
		}

		else
		{
			std::cout << "Jeff didn't seem to notice you at first, but your sprinting away from him has made you quite noticeable." << std::endl;
			std::cout << "He gives chase and tackles you to the ground." << std::endl;
			std::cout << "His face melts away into a huge mouth." << std::endl;
			std::cout << "It closes around you and everything goes black." << std::endl;
			playerPtr->setAlive(0);
			return;
		}
	}

	if (commands[0] == "flee"  && commands[2] == "barry")
	{

		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "Jeff has already left the room." << std::endl;
			std::cout << "You don't need to flee from him." << std::endl;
			return;
		}

		else
		{
			std::cout << "Jeff didn't seem to notice you at first, but your sprinting away from Barry has made you quite noticeable." << std::endl;
			std::cout << "He gives chase and tackles you to the ground." << std::endl;
			std::cout << "His face melts away into a huge mouth." << std::endl;
			std::cout << "It closes around you and everything goes black." << std::endl;
			playerPtr->setAlive(0);
			return;
		}
	}


	if (commands[0] == "break" && commands[2] == "jeff")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "He has already left the hallway." << std::endl;
			std::cout << "You missed your chance." << std::endl;
			return;
		}

		else
		{
			std::cout << "You walk up to Jeff nonchalantly." << std::endl;
			std::cout << "You resolve to break his face for him." << std::endl;
			std::cout << "He is too quick for you in your hungover condition!" << std::endl;
			std::cout << "Jeff's hands become tentacles and wrap around your neck." << std::endl;
			std::cout << "You struggle to breathe, but the tentacles are too strong." << std::endl;
			std::cout << "Everything goes black." << std::endl;
			playerPtr->setAlive(0);
			return;
		}
	}

	if (commands[0] == "break" && commands[2] == "barry")
	{
		std::cout << "You walk up to Barry nonchalantly." << std::endl;
		std::cout << "You resolve to break his face for him." << std::endl;
		std::cout << "He is too quick for you in your hungover condition!" << std::endl;
		std::cout << "He pulls out a meat tenderizer mallet and bashes you over the head with it." << std::endl;
		std::cout << "You come to and are a tied up in a chair besides Palmer." << std::endl;
		std::cout << "Macready is standing in front of you and holding a petri dish in one hand and copper wire in the other." << std::endl;
		std::cout << "Palmer begins to shake violently and morphs into an inhuman creature." << std::endl;
		std::cout << "He bursts through the ropes holding him down and attacks you." << std::endl;
		std::cout << "Everything goes black." << std::endl;
		playerPtr->setAlive(0);
		return;
	}

	if (commands[0] == "look" && commands[1] == "" && commands[2] == "")
	{
		std::string longDescription = playerLocation->getLongDescrip();
		std::cout << longDescription << std::endl;
		return;
	}

	if (commands[0] == "look" && commands[2] == "barry")
	{
		std::cout << "Barry appears to be quite worried." << std::endl;
		std::cout << "You can't blame him." << std::endl;
		std::cout << "You feel the same way." << std::endl;
		return;
	}

	if (commands[0] == "look" && commands[2] == "jeff")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "He has already left the hallway." << std::endl;
			std::cout << "You missed your chance for a second look." << std::endl;
			return;
		}

		else
		{
			std::cout << "His appearance is the same as the Jeff you know." << std::endl;
			std::cout << "But there is something off about his demeanor." << std::endl;
			std::cout << "Something you can't quite put your finger on." << std::endl;
			return;
		}

	}

	if (commands[0] == "look" && commands[1] == "at")
	{
		lookAt(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "room")
	{
		/*Asks pointer to get name*/
		std::cout << "CURRENT ROOM: " << playerLocation->getName() << std::endl;
		return;
	}

	if ((commands[0] == "current" && commands[2] == "room") || (commands[0] == "map"))
	{
		std::cout << "You are in Hallway 2." << std::endl;
		mapHallway2();
		return;
	}

	/*calls helper go function with playerLocation pointer, list of rooms and room number to go to.*/

	if ((commands[0] == "go" && commands[2] == "hallway2") || (commands[2] == "hallway") || (commands[2] == "north") || (commands[2] == "hallway2") || (commands[2] == "hallway1") || (commands[2] == "hallway 1"))
	{
		go(playerLocation, roomList, 1, playerPtr);
		return;
	}

	if ((commands[0] == "go" && commands[2] == "mess hall") || (commands[0] == "go" && commands[2] == "messhall") || (commands[2] == "west"))
	{
		go(playerLocation, roomList, 8, playerPtr);
		return;
	}

	if ((commands[0] == "go" && commands[2] == "garage") || (commands[2] == "east"))
	{
		go(playerLocation, roomList, 10, playerPtr);
		return;
	}

	if ((commands[0] == "go" && commands[2] == "dog kennel") || (commands[0] == "go" && commands[2] == "dogkennel") || (commands[2] == "southwest") || (commands[2] == "south west"))
	{
		go(playerLocation, roomList, 12, playerPtr);
		return;
	}

	if ((commands[0] == "go" && commands[2] == "basement") || (commands[2] == "south"))
	{
		go(playerLocation, roomList, 13, playerPtr);
		return;
	}

	if ((commands[0] == "go"  && commands[2] == "conference room") || (commands[0] == "go" && commands[2] == "conferenceroom") || (commands[2] == "southeast")|| (commands[2] == "south east"))
	{
		go(playerLocation, roomList, 14, playerPtr);
		return;
	}

	if (commands[0] == "take")
	{
		take(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "help")
	{
		help();
		return;
	}

	if (commands[0] == "inventory")
	{
		playerPtr->getInventory();
		return;
	}

	std::cout << "You can't do that here." << std::endl;
	return;
}


