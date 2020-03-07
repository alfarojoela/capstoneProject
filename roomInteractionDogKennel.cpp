#include "roomInteractionDogKennel.hpp"

void roomInteractionDogKennel(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList, Parser* parserPtr)
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
			std::cout << "You notice a bottle of beer on a shelf." << std::endl;
			std::cout << "After checking the room for booze, you also notice some other potentially useful items." << std::endl;
		}

		playerLocation->itemsInRoom();
		return;
	}

	if ((commands[0] == "use" && commands[2] == "blood test") || (commands[0] == "look" && commands[1] == "at" && commands[2] == "blood"))
	{
		std::cout << "Now is not the time to do a blood test." << std::endl;
		std::cout << "You are the only human in the Dog Kennel right now." << std::endl;
		return;
	}
	if (commands[0] == "talk" && commands[2] == "panting")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "Whatever that thing was, it looked like a malformed dog, it's scurried off." << std::endl;
			std::cout << "I don't think you will be able to communicate with it in a meaningful way." << std::endl;
			std::cout << "The only language it seems to understand is violence." << std::endl;
			return;
		}

		if (playerLocation->getFeatureOneHap() == 0)
		{
			std::cout << "You call out to whatever is making the panting noise." << std::endl;
			std::cout << "You receive no response." << std::endl;
			return;
		}

	}

	if (commands[0] == "drink")
	{
		drink(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "smell" && commands[2] == "panting")
	{
		std::cout << "The dog kennel smells the same as it always does." << std::endl;
		std::cout << "A bit like mildew and a bit like dog hair." << std::endl;
		return;
	}

	if (commands[0] == "smell" && commands[2] == "shimmering")
	{
		std::cout << "It is not producing any distinctive smell." << std::endl;
		return;
	}

	if (commands[0] == "drop")
	{
		drop(commands, playerLocation, playerPtr, roomList, 2);
		return;
	}

	if (commands[0] == "attack" && commands[2] == "panting")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "Whatever that thing was, you don't want to tangle with it again." << std::endl;
			std::cout << "You reconsider attacking it." << std::endl;
			return;
		}

		if (playerLocation->getFeatureOneHap() == 0)
		{
			std::cout << "You decide you are going to attack whatever is making that panting sound." << std::endl;
			std::cout << "Get them before they get you!" << std::endl;
			playerLocation->featureOne(playerPtr);

			return;
		}
	}

	if (commands[0] == "attack" && commands[2] == "shimmering")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "Petri dishes cannot hurt you." << std::endl;
			return;
		}

		if (playerLocation->getFeatureOneHap() == 0)
		{
			std::cout << "Whatever is shimmering, it looks like an inanimate object." << std::endl;
			std::cout << "It just doesn't make sent to attack it." << std::endl;
			return;
		}
	}

	if (commands[0] == "eat")
	{
		eat(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "jump" && commands[1] == "on" && commands[2] == "panting")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "Whatever that thing was, you don't want to tangle with it again." << std::endl;
			std::cout << "You reconsider attacking it." << std::endl;
			std::cout << "You don't think you can get the jump on it now." << std::endl;
			return;
		}

		if (playerLocation->getFeatureOneHap() == 0)
		{
			std::cout << "You decide you are going to tackle whatever is making that panting sound." << std::endl;
			std::cout << "Time to take out the trash and kick some tail!" << std::endl;
			playerLocation->featureOne(playerPtr);

			return;
		}
	}

	if (commands[0] == "jump" && commands[2] == "shimmering")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "You already retrieved it." << std::endl;
			return;
		}

		if (playerLocation->getFeatureTwoHap() == 0)
		{
			std::cout << "You aren't sure if you can reach it by jumping." << std::endl;
			playerLocation->featureTwo(playerPtr);
			return;
		}
	}

	if (commands[0] == "flee" && commands[2] == "panting")
	{

		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "You decide you don't want to be in the same room with whatever just attacked you." << std::endl;
			std::cout << "You make a run for Hallway 2 ." << std::endl;
			go(playerLocation, roomList, 9, playerPtr);
			return;
		}

		else
		{
			std::cout << "Whatever is panting is freaking you out." << std::endl;
			std::cout << "You make a run for Hallway 2 ." << std::endl;
			go(playerLocation, roomList, 9, playerPtr);
			return;
		}

	}

	if (commands[0] == "break" && commands[2] == "shimmmering")
	{
		std::cout << "Before you break it, maybe you should get a better look at it." << std::endl;
		return;
	}



	if (commands[0] == "look" && commands[1] == "" && commands[2] == "")
	{
		std::string longDescription = playerLocation->getLongDescrip();
		std::cout << longDescription << std::endl;
		return;
	}

	if (commands[0] == "look" && commands[1] == "at" && commands[2] == "panting")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "You could not bear to look at it again." << std::endl;
			std::cout << "It's real nightmare fuel." << std::endl;
			return;
		}

		else
		{
			playerLocation->featureOne(playerPtr);
			return;
		}
	}

	if (commands[0] == "look" && commands[1] == "at" && commands[2] == "shimmering")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "You already picked it up." << std::endl;
			std::cout << "It was a petri dish." << std::endl;
			return;
		}

		else
		{
			playerLocation->featureTwo(playerPtr);
			return;
		}
	}

	if (commands[0] == "use" && commands[2] == "shimmering")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "You already picked it up." << std::endl;
			std::cout << "You can't use it here." << std::endl;
			return;
		}

		else
		{
			std::cout << "To use it, you need to get it first." << std::endl;
			playerLocation->featureTwo(playerPtr);
			return;
		}
	}


	if (commands[0] == "look" && commands[1] == "at")
	{
		lookAt(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if ((commands[0] == "go" && commands[2] == "hallway2") || (commands[2] == "hallway") || (commands[2] == "northeast") || (commands[2] == "hallway2") || (commands[2] == "hallway1"))
	{
		go(playerLocation, roomList, 9, playerPtr);
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
		std::cout << "You are in the Dog Kennel." << std::endl;
		mapDogKennel();
		return;
	}

	/*calls helper go function with playerLocation pointer, list of rooms and room number to go to.*/

	if (commands[0] == "take" && commands[2] == "shimmering")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "You already took it." << std::endl;
			return;
		}

		else
		{
			playerLocation->featureTwo(playerPtr);
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


