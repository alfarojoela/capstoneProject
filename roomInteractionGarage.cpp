#include "roomInteractionGarage.hpp"


void roomInteractionGarage(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList, Parser* parserPtr)
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
			std::cout << "You notice a bottle of beer on a tool box." << std::endl;
			std::cout << "You don't see anyone's name on it." << std::endl;
			std::cout << "After checking the room for booze, you also notice some other potentially useful items." << std::endl;
		}

		playerLocation->itemsInRoom();
		return;
	}

	if ((commands[0] == "use" && commands[2] == "blood test") || (commands[0] == "look" && commands[1] == "at" && commands[2] == "blood"))
	{
		std::cout << "Now is not the time to do a blood test." << std::endl;
		std::cout << "You are in the Garage by yourself." << std::endl;
		std::cout << "No need to test your own blood." << std::endl;
		return;
	}

	if (commands[0] == "talk")
	{
		std::cout << "There is no one here in the garage for you to speak to." << std::endl;
		std::cout << "Therefore, talking is pointless." << std::endl;
		return;
	}

	if (commands[0] == "drink")
	{
		drink(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "smell" && commands[2] == "case")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "You place your nostrils on the case and inhale deeply." << std::endl;
			std::cout << "It doesn't smell like fuel, so you are fairly certain the flaimethrower does not have a leak." << std::endl;
			return;
		}
	}

	if (commands[0] == "smell" && commands[2] == "snowmobile")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "Although the engine did not turn over, you notice the faint smell of fuel." << std::endl;
			return;
		}
		else
		{
			std::cout << "You observe a very faint smell of fuel. " << std::endl;
			std::cout << "You approach the snowmobile to investigate further." << std::endl;
			playerLocation->featureTwo(playerPtr);
			return;
		}
	}

	if (commands[0] == "drop")
	{
		drop(commands, playerLocation, playerPtr, roomList, 2);
		return;
	}

	if (commands[0] == "attack" && commands[2] == "case")
	{
		std::cout << "You slam your fists agains the case, but only cause yourself pain." << std::endl;
		std::cout << "The case is unaffected." << std::endl;
		return;
	}

	if (commands[0] == "attack" && commands[2] == "snowmobile")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "'You blasted machine!' You scream at the snowmobile.'" << std::endl;
			std::cout << "You give it a kick out of frustration." << std::endl;
			return;
		}

		else
		{
			std::cout << "That could be your only ticket out of here and to safety." << std::endl;
			std::cout << "Why not try to use it first?" << std::endl;
			return;
		}
	}

	if (commands[0] == "eat")
	{
		eat(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "use" && commands[2] == "case")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "You open the case again." << std::endl;
			return;
		}

		else
		{
			playerLocation->featureOne(playerPtr);
		}
	}

	if (commands[0] == "use" && commands[2] == "snowmobile")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "The snowmobile is not working." << std::endl;
			return;
		}

		else
		{
			playerLocation->featureTwo(playerPtr);
		}
	}


	if (commands[0] == "use" && commands[2] == "flamethrower")
	{
		if (playerPtr->checkInventory("flamethrower") == 1)
		{
			std::cout << "You decide to try out the flamethrower in the garage." << std::endl;
			std::cout << "Unfortunately, the snowmobile has a gas leak." << std::endl;
			std::cout << "You cause an explosion and blow yourself up." << std::endl;
			playerPtr->setAlive(0);
			return;
		}

	}

	if (commands[0] == "jump" && commands[2] == "case")
	{
		std::cout << "You jump on the case to get a better look at the room." << std::endl;
		std::cout << "You look up at the ceiling tiles and notice some one has written very faintly on the one above your head." << std::endl;
		std::cout << "It reads, 'Lo Pan was here.' " << std::endl;
		std::cout << "Who is that?" << std::endl;
		std::cout << "A member of the last crew that went back to the States?" << std::endl;
		return;

	}

	if ((commands[0] == "jump" &&  commands[2] == "snowmobile") || (commands[0] == "jump" && commands[2] == "snow mobile"))
	{
		std::cout << "You climb up on a work bench and pretend the snowmobile is a horse." << std::endl;
		std::cout << "You try jumping into the saddle like a cowboy from a movie." << std::endl;
		std::cout << "The handlebars knock the wind out of you and you fall to the floor." << std::endl;
		std::cout << "Enough horsing around!" << std::endl;
		return;

	}

	if (commands[0] == "flee" || commands[1] == "flee" || commands[2] == "flee")
	{

		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "The snowmobile is not working." << std::endl;
			std::cout << "Escaping with it is not possible." << std::endl;
			return;
		}

		else
		{
			playerLocation->featureTwo(playerPtr);
			return;
		}

	}

	if (commands[0] == "break" && commands[2] == "case")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "There is no need to break it as you already opened it with the code." << std::endl;
			return;
		}

		else
		{
			std::cout << "It is too sturdy to break." << std::endl;
			std::cout << "You determine the only way to open it is with the code." << std::endl;

			if (playerPtr->checkInventory("toilet paper"))
			{
				playerLocation->featureOne(playerPtr);
				return;
			}
			std::cout << "You will have to look around the base for the code." << std::endl;
			return;
		}
	}

	if (commands[0] == "look" && commands[1] == "" && commands[2] == "")
	{
		std::string longDescription = playerLocation->getLongDescrip();
		std::cout << longDescription << std::endl;
		return;
	}

	if (commands[0] == "look" && commands[2] == "case")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "The case is now empty." << std::endl;
			return;
		}

		else
		{
			std::cout << "You decide to examine the case and see about getting the flamethrower out." << std::endl;
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

	if ((commands[0] == "current" && commands[2] == "room") || (commands[0] == "map"))
	{
		std::cout << "You are in the Garage." << std::endl;
		mapGarage();
		return;
	}

	/*calls helper go function with playerLocation pointer, list of rooms and room number to go to.*/

	if ((commands[0] == "go" && commands[2] == "hallway2") || (commands[2] == "hallway") || (commands[2] == "west") || (commands[2] == "hallway2") || (commands[2] == "hallway1"))
	{
		go(playerLocation, roomList, 9, playerPtr);
		return;
	}

	if (commands[0] == "take" && commands[2] == "flamethrower")
	{
		if (playerLocation->getFeatureOneHap() == 1 && playerPtr->checkInventory("flamethrower") == 1)
		{
			std::cout << "You already took the flamethrower." << std::endl;
			return;
		}

		if (playerLocation->getFeatureOneHap() == 1 && playerPtr->checkInventory("flamethrower") == 0)
		{
			take(commands, playerLocation, playerPtr, roomList, 0);
			return;
		}

		else
		{
			std::cout << "You decide to examine the case and see about getting the flamethrower out." << std::endl;
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

	std::cout << "You can't do that here." << std::endl;
	return;
}
