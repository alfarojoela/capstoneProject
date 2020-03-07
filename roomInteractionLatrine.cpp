#include "roomInteractionLatrine.hpp"


void roomInteractionLatrine(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList, Parser* parserPtr)
{
	if (commands[0] == "savegame" || commands[0] == "loadgame")
	{
		return;

	}

	/*Set of commands to check room inventory.  Mainly for testing purposes rather than for the player.  May keep condition to allow player a cheat.  Won't put in help list.*/
	if (commands[0] == "look" && commands[1] == "for" && commands[2] == "booze")
	{
		std::cout << "You start looking for booze and notice..." << std::endl;
		std::string freeBooze = "beer";

		if (playerLocation->checkItem(freeBooze) != 999)
		{
			std::cout << "You notice a bottle of beer in the sink." << std::endl;
			std::cout << "After checking the room for booze, you also notice some other potentially useful items." << std::endl;

		}

		playerLocation->itemsInRoom();
		return;
	}

	if ((commands[0] == "use" && commands[2] == "blood test") || (commands[0] == "look" && commands[1] == "at" && commands[2] == "blood"))
	{
		std::cout << "It would make sense to do that with a human specimen." << std::endl;
		std::cout << "You are the only human here and there is no reason to test your own blood." << std::endl;
		return;
	}

	if (commands[0] == "talk")
	{
		std::cout << "There is no one in the latrine to talk with.  You feel quite lonely now." << std::endl;
		return;
	}

	if (commands[0] == "drink")
	{
		drink(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "smell" && commands[2] == "toilet paper")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "It has the faint smell of charcoal on it.  Probably from the smudged writing on it." << std::endl;
			return;
		}

		else
		{
			playerLocation->featureOne(playerPtr);
			return;
		}
	}

	if (commands[0] == "smell" && commands[2] == "toilet")
	{
		std::cout << "You observe that despite the carnage in the hallway, the toilet smells like it was recently cleaned." << std::endl;
		return;
	}

	if (commands[0] == "drop")
	{
		drop(commands, playerLocation, playerPtr, roomList, 2);
		return;
	}

	if (commands[0] == "attack")
	{
		std::cout << "There's no one and nothing to attack now." << std::endl;
		return;
	}

	if (commands[0] == "eat" && commands[2] == "toilet paper")
	{
		std::cout << "Not a good idea to eat the toilet paper.  You don't want to forget the code that's written on it." << std::endl;
		return;
	}

	if (commands[0] == "eat")
	{
		eat(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "use" && commands[2] == "toilet")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "You don't have to do that right now.  You used the toilet before you got attack by whatever that thing was." << std::endl;
			return;
		}

		else
		{
			playerLocation->featureTwo(playerPtr);
			return;
		}
	}

	if (commands[0] == "use" && commands[2] == "toilet paper")
	{
		std::cout << "You decide against using the toilet paper.  It has a code on it.  The code may come in handy." << std::endl;
		return;
	}

	if (commands[0] == "jump" && commands[2] == "toilet")
	{
		std::cout << "You jump up on the toilet and take a look at the room.  You notice some writing on the wall.  Is it code?  It reads: 'Snake was here.'" << std::endl;
		std::cout << "What kind of name is Snake?" << std::endl;
		return;
	}


	if (commands[0] == "jump" && commands[2] == "toilet paper")
	{
		std::cout << "That just doesn't make any sense.  There is no reason to do that." << std::endl;
		return;
	}

	if (commands[0] == "flee")
	{
		std::cout << "There is nothing to flee from..At least not at this time." << std::endl;
		return;
	}

	if (commands[0] == "break"  && commands[2] == "toilet")
	{
		std::cout << "You decide against it.  'I would sooner destroy a stained glass window than a piece of art like yourself,' you say to the toilet." << std::endl;
		return;
	}

	if (commands[0] == "break" &&  commands[2] == "toilet paper")
	{
		std::cout << "You might need it for later.  Besides, how do you break toilet paper?" << std::endl;
		return;
	}

	if (commands[0] == "look" && commands[1] == "" && commands[2] == "")
	{
		std::string longDescription = playerLocation->getLongDescrip();
		std::cout << longDescription << std::endl;
		return;
	}

	if (commands[0] == "look" && commands[2] == "toilet paper")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "Why did someone write code on the toilet paper?  5392 is written on it.  The code to the flamethrower locker." << std::endl;
			return;
		}

		else
		{
			playerLocation->featureOne(playerPtr);
			return;
		}
	}

	if (commands[0] == "look" && commands[2] == "toilet")
	{
		std::cout << "You behold the majesty of the porcelain throne.  It is a one piece, American Standard Madera, flushing at 1.6 gallons per flush, with an elongated bowl. " << std::endl;
		return;
	}

	if (commands[0] == "look" && commands[2] == "creature")
	{
		if (playerLocation->getFeatureTwoHap() == 0)
		{
			std::cout << "What creature?  What are you talking about?" << std::endl;
			return;
		}

		else
		{
			std::cout << "You are not sure what it is that just attacked you.  But you are sure it is not of this world.  Maybe it or one of its kind caused all the carnage in the hallway." << std::endl;
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

	if (commands[0] == "current" && commands[2] == "room")
	{
		std::cout << "You are in the Latrine." << std::endl;
		mapLatrine();
		return;
	}

	/*calls helper go function with playerLocation pointer, list of rooms and room number to go to.*/

	if ((commands[0] == "go" && commands[2] == "hallway1") || (commands[2] == "southeast"))
	{
		go(playerLocation, roomList, 1, playerPtr);
		return;
	}

	if (commands[0] == "take" && commands[2] == "toilet paper")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "You already added it to your inventory." << std::endl;
			return;
		}

		else
		{
			playerLocation->featureOne(playerPtr);
			return;
		}
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

	if (commands[0] == "map")
	{
		map();
		return;
	}

	std::cout << "You can't do that here." << std::endl;
	return;
}


