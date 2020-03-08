#include "roomInteractionMessHall.hpp"

void roomInteractionMessHall(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList, Parser* parserPtr)
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
			std::cout << "You notice a bottle of beer all alone on a table." << std::endl;
			std::cout << "It looks lonely." << std::endl;
			std::cout << "Maybe you should take it with you and give it a good home." << std::endl;
			std::cout << "After checking the room for booze, you also notice the following..." << std::endl;

		}

		playerLocation->itemsInRoom();
		return;
	}

	if ((commands[0] == "use" && commands[2] == "blood test") || (commands[0] == "look" && commands[1] == "at" && commands[2] == "blood"))
	{
		std::cout << "Now is not the time to do a blood test." << std::endl;
		std::cout << "You are in the Mess Hall by yourself." << std::endl;
		std::cout << "No need to test your own blood." << std::endl;
		return;
	}


	if (commands[0] == "talk")
	{
		std::cout << "There is no one here in the mess hall." << std::endl;
		std::cout << "Therefore, talking is pointless." << std::endl;
		return;
	}

	if (commands[0] == "drink" && commands[2] == "booze")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "It was just a bitter disappointment." << std::endl;
			return;
		}
		else
		{
			std::cout << "You decide to get closer to drink from the bottle." << std::endl;
			playerLocation->featureTwo(playerPtr);
			return;
		}
	}

	if (commands[0] == "drink")
	{
		drink(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "smell" && commands[2] == "meal")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "It was a semi-warm plate of spaghetti." << std::endl;
			std::cout << "It hit the spot though." << std::endl;
			return;
		}

		else
		{
			std::cout << "You smell basil, oregano, onions, and garlic." << std::endl;
			std::cout << "You get closer to investigate futher." << std::endl;
			playerLocation->featureOne(playerPtr);
			return;
		}
	}

	if (commands[0] == "smell" && commands[2] == "booze")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "There isn't any point in doing that." << std::endl;
			return;
		}
		else
		{
			std::cout << "You decide to get closer to sniff the bottle further." << std::endl;
			playerLocation->featureTwo(playerPtr);
			return;
		}
	}

	if (commands[0] == "drop")
	{
		drop(commands, playerLocation, playerPtr, roomList, 2);
		return;
	}

	if (commands[0] == "attack" && commands[2] == "meal")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "You already attacked that harmless plate of spaghetti." << std::endl;
			return;
		}

		else
		{
			std::cout << "You decide you are going to attack the untouched meal with gusto." << std::endl;
			playerLocation->featureOne(playerPtr);
			return;
		}
	}

	if (commands[0] == "attack" && commands[2] == "booze")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "That was just bitter disappointment." << std::endl;
			return;
		}

		else
		{
			std::cout << "You decide you are going to attack that bottle of booze with gusto and swig it all down." << std::endl;
			playerLocation->featureTwo(playerPtr);
			return;
		}
	}

	if (commands[0] == "eat" && commands[2] == "meal")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "You already attacked that harmless plate of spaghetti." << std::endl;
			return;
		}

		else
		{
			std::cout << "You decide you are going to eat the untouched meal." << std::endl;
			playerLocation->featureOne(playerPtr);
			return;
		}
	}

	if (commands[0] == "eat")
	{
		eat(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "jump" && commands[2] == "meal")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "That just won't be helpful at this time." << std::endl;
			return;
		}

		else
		{
			std::cout << "As you are hungry, you refrain from jumping on the plate of food." << std::endl;
			return;
		}
	}

	if (commands[0] == "jump"  && commands[2] == "booze")
	{
		std::cout << "You decide against it." << std::endl;
		return;
	}


	if (commands[0] == "flee")
	{
		std::cout << "What are you going to run away from here in the mess hall?" << std::endl;
		std::cout << "There is no one and nothing to flee from." << std::endl;
		return;
	}

	if (commands[0] == "break")
	{
		std::cout << "What did it ever do to you?" << std::endl;
		return;
	}

	if (commands[0] == "look" && commands[1] == "" && commands[2] == "")
	{
		std::string longDescription = playerLocation->getLongDescrip();
		std::cout << longDescription << std::endl;
		return;
	}

	if (commands[0] == "look" && commands[2] == "meal")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "It looks like spaghetti was on the menu for today." << std::endl;
			return;
		}

		else
		{
			std::cout << "You decide to approach the meal to find out what it is." << std::endl;
			playerLocation->featureOne(playerPtr);
			return;
		}
	}

	if (commands[0] == "look"  && commands[2] == "booze")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "That was just bitter disappointment." << std::endl;
			return;
		}

		else
		{
			std::cout << "What could be in the bottle?" << std::endl;
			std::cout << "You approach the bottle to investigate further." << std::endl;
			playerLocation->featureOne(playerPtr);
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

	if ((commands[0] == "current" && commands[2] == "room") || (commands[0] == "map") || (commands[0] == "show"))
	{
		std::cout << "You are in the Mess Hall." << std::endl;
		mapMessHall();
		return;
	}

	/*calls helper go function with playerLocation pointer, list of rooms and room number to go to.*/

	if ((commands[0] == "go"  && commands[2] == "hallway2") || (commands[2] == "hallway") || (commands[2] == "hallway 2") || (commands[2] == "east"))
	{
		go(playerLocation, roomList, 9, playerPtr);
		return;
	}

	if ((commands[0] == "go"  && commands[2] == "galley") || (commands[2] == "south"))
	{
		go(playerLocation, roomList, 11, playerPtr);
		return;
	}

	if ((commands[0] == "take" && commands[2] == "gin") ||(commands[0] == "take" && commands[2] == "booze") || (commands[0] == "take" && commands[2] == "bottle"))
	{
		if (playerLocation->getFeatureTwoHap() == 0)
		{
			playerLocation->featureTwo(playerPtr);
			return;
		}

		else
		{
			take(commands, playerLocation, playerPtr, roomList, 0);
			return;
		}
	}

	if ((commands[0] == "take" && commands[2] == "meal") || (commands[0] == "take" && commands[2] == "spaghetti"))
	{
		if (playerLocation->getFeatureOneHap() == 0)
		{
			playerLocation->featureOne(playerPtr);
			return;
		}

		else
		{
			take(commands, playerLocation, playerPtr, roomList, 0);
			return;
		}
	}

	if ((commands[0] == "take" && commands[2] == "gin") || (commands[0] == "take" && commands[2] == "booze") || (commands[0] == "take" && commands[2] == "bottle"))
	{
		if (playerLocation->getFeatureOneHap() == 0)
		{
			playerLocation->featureOne(playerPtr);
			return;
		}

		else
		{
			take(commands, playerLocation, playerPtr, roomList, 0);
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

	std::cout << "You can't do that here." << std::endl;
	return;
}



