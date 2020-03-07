#include "roomInteractionGalley.hpp"


void roomInteractionGalley(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList, Parser* parserPtr)
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
			std::cout << "You notice a bottle of beer on a counter." << std::endl;
			std::cout << "After checking the room for booze, you also notice some other potentially useful items." << std::endl;
		}

		playerLocation->itemsInRoom();
		return;
	}

	if ((commands[0] == "use" && commands[2] == "blood test") || (commands[0] == "look" && commands[1] == "at" && commands[2] == "blood"))
	{
		std::cout << "Now is not the time to do a blood test." << std::endl;
		std::cout << "You are in the Galley by yourself." << std::endl;
		std::cout << "No need to test your own blood." << std::endl;
		return;
	}

	if (commands[0] == "talk")
	{
		std::cout << "There is no one here in the mess hall." << std::endl;
		std::cout << "Therefore, talking is pointless." << std::endl;
		return;
	}

	if (commands[0] == "drink")
	{
		drink(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "smell" && commands[2] == "counter")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "You've determined the foul odor is not coming from the counter." << std::endl;
			std::cout << "It just had a can of sea food." << std::endl;
			return;
		}

		else
		{
			std::cout << "You are not sure if the bad smell is from the counter or not." << std::endl;
			std::cout << "You decide to get closer for a better whiff." << std::endl;
			playerLocation->featureOne(playerPtr);
			return;
		}
	}

	if (commands[0] == "smell" && commands[2] == "odor")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "You've already determined the bad smell is just rotting leftovers." << std::endl;

			return;
		}
		else
		{
			std::cout << "You decide to investigate the odor more closely." << std::endl;
			playerLocation->featureTwo(playerPtr);
			return;
		}
	}

	if (commands[0] == "drop")
	{
		drop(commands, playerLocation, playerPtr, roomList, 2);
		return;
	}

	if (commands[0] == "attack" && commands[2] == "counter")
	{
		std::cout << "The counter does not look threatening to warrant an attack." << std::endl;
		return;
	}

	if (commands[0] == "attack" && commands[2] == "odor")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "It was just rotting leftovers." << std::endl;
			std::cout << "You decide against eating them." << std::endl;
			return;
		}

		else
		{
			std::cout << "You aren't sure what the smell is, so you go in its direction to investigate." << std::endl;
			std::cout << "Stay frosty." << std::endl;
			playerLocation->featureTwo(playerPtr);
			return;
		}
	}

	if (commands[0] == "eat")
	{
		eat(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "jump" && commands[2] == "counter")
	{
		std::cout << "You jump on the counter to get a better look at the room." << std::endl;
		std::cout << "You look up at the ceiling tiles and notice some one has written very faintly on the one above your head." << std::endl;
		std::cout << "It reads, 'Jack Burton was here.' " << std::endl;
		std::cout << "Who is that?" << std::endl;
		std::cout << "A member of the last crew that went back to the States?" << std::endl;
		return;
	}

	if (commands[0] == "flee")
	{
		std::cout << "What are you going to run away from here in the Galley?" << std::endl;
		std::cout << "Like a chicken, you run back to the mess hall." << std::endl;
		go(playerLocation, roomList, 8, playerPtr);
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

	if (commands[0] == "look"  && commands[2] == "counter")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "The counter has nice marble surface." << std::endl;
			return;
		}

		else
		{
			std::cout << "You decide to examine the counter more closely." << std::endl;
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
		std::cout << "You are in the Galley." << std::endl;
		mapGalley();
		return;
	}

	/*calls helper go function with playerLocation pointer, list of rooms and room number to go to.*/

	if ((commands[0] == "go" && commands[2] == "mess hall") || (commands[0] == "go" && commands[2] == "messhall") || (commands[2] == "north"))
	{
		go(playerLocation, roomList, 8, playerPtr);
		return;
	}

	if (commands[0] == "go" && commands[2] == "odor")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "It was just rotting leftovers." << std::endl;
			std::cout << "You decide against eating them." << std::endl;
			return;
		}

		else
		{
			std::cout << "You aren't sure what the smell is, so you go in its direction to investigate." << std::endl;
			std::cout << "Stay frosty." << std::endl;
			playerLocation->featureTwo(playerPtr);
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


