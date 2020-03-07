#include "roomInteractionResearchLab.hpp"


void roomInteractionResearchLab(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList, Parser* parserPtr)
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
			std::cout << "You notice a bottle of beer by the computer." << std::endl;
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


	if (commands[0] == "talk" && commands[2] == "doctor")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "The good doctor is no more." << std::endl;
			std::cout << "He is incapable of speaking now." << std::endl;
			return;
		}

		if (playerLocation->getFeatureTwoHap() == 0)
		{
			playerLocation->featureTwo(playerPtr);
			return;
		}
	}

	if (commands[0] == "talk" && commands[2] == "computer")
	{
		std::cout << "Although this computer is more sophisticated than Macready's, it is not voice activated." << std::endl;
		std::cout << "You'll have to use it like any other computer." << std::endl;
		return;
	}

	if (commands[0] == "talk"  && commands[2] == "captain")
	{
		std::cout << "He's not going to be able to tell  you anything." << std::endl;
		std::cout << "As the saying goes, 'Dead men tell no tales.' " << std::endl;
		return;
	}

	if (commands[0] == "drink")
	{
		drink(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "smell"&& commands[2] == "computer")
	{
		std::cout << "It doesn't smell out of the ordinary." << std::endl;
		return;
	}

	if (commands[0] == "smell" && commands[2] == "doctor")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "The smell of the doctor's viscera reminds you of a slaughter house." << std::endl;
			std::cout << "You might want to leave here.  You feel sick." << std::endl;
			return;
		}

		if (playerLocation->getFeatureTwoHap() == 0)
		{
			std::cout << "Before all this happened, you had always wondered what kind of fabric softener the doctor used." << std::endl;
			std::cout << "It has a slight floral scent to it." << std::endl;
			std::cout << "Definitely spring fresh." << std::endl;
			std::cout << "If you survive this mess, you plan on asking the doctor." << std::endl;
			return;
		}
	}

	if (commands[0] == "drop")
	{
		drop(commands, playerLocation, playerPtr, roomList, 2);
		return;
	}

	if (commands[0] == "attack"  && commands[2] == "computer")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "Although the computer had some disturbing news, you don't really want to attack it." << std::endl;
			std::cout << "Don't shoot the messenger as they say." << std::endl;
			return;
		}

		else
		{
			std::cout << "Before you attack the computer, why don't you try using it first?" << std::endl;
			return;
		}
	}

	if (commands[0] == "attack"  && commands[2] == "doctor")
	{
		if (playerLocation->getFeatureTwoHap() == 0)
		{
			std::cout << "Although you are frustrated and hung over, that's no reason to take it out on the doctor." << std::endl;
			std::cout << "You decide to curb your violent tendencies and not attack the doctor." << std::endl;
			return;
		}

		else
		{
			std::cout << "You walk over to the doctor's corpse." << std::endl;
			std::cout << "'Thanks for the warning!'  You scream." << std::endl;
			std::cout << "You decide to not punch the corpse." << std::endl;
			return;

		}
	}

	if (commands[0] == "eat")
	{
		eat(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "use"  && commands[2] == "computer")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "It doesn't seem like the simuation is going to change." << std::endl;
			std::cout << "But you decide to rerun it anyway..." << std::endl;
			playerLocation->featureOne(playerPtr);
			return;
		}

		if (playerLocation->getFeatureOneHap() == 0)
		{
			playerLocation->featureOne(playerPtr);
			return;
		}
	}

	if (commands[0] == "jump" && commands[2] == "doctor")
	{
		std::cout << "You decide against tackling the doctor." << std::endl;
		return;
	}


	if (commands[0] == "jump" && commands[2] == "computer")
	{
		std::cout << "You don't want to take the chance of breaking some pricey equipment." << std::endl;
		return;
	}

	if (commands[0] == "flee"&& commands[2] == "doctor")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "You decide against fleeing from the doctor." << std::endl;
			std::cout << "Instead you check his pulse." << std::endl;
			std::cout << "He is beyond saving." << std::endl;
			return;
		}

		else
		{
			std::cout << "You see the doctor has not noticed you yet." << std::endl;
			std::cout << "You decide to leave the room quietly before he notices." << std::endl;
			std::cout << "Too late!" << std::endl;
			std::cout << "He has noticed you." << std::endl;
			std::cout << "He beckons you over." << std::endl;
			playerLocation->featureTwo(playerPtr);
			return;
		}
	}

	if (commands[0] == "flee" &&commands[2] == "computer")
	{

		std::cout << "You don't need to be afraid of the computer." << std::endl;
		std::cout << "It won't bite." << std::endl;
		return;
	}


	if (commands[0] == "break" && commands[2] == "computer")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "So the computer simulation had some bad news." << std::endl;
			std::cout << "Breaking the computer won't make the news any better." << std::endl;
			return;
		}

		if (playerLocation->getFeatureOneHap() == 0)
		{
			std::cout << "Before you break it, try using it first." << std::endl;
			return;
		}
	}

	if (commands[0] == "break" &&  commands[2] == "doctor")
	{
		std::cout << "Not a viable option." << std::endl;
		return;
	}

	if (commands[0] == "look" && commands[1] == "" && commands[2] == "")
	{
		std::string longDescription = playerLocation->getLongDescrip();
		std::cout << longDescription << std::endl;
		return;
	}

	if (commands[0] == "look" && commands[2] == "doctor")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "The doctor's body is slumped over the table." << std::endl;
			return;
		}

		else
		{
			playerLocation->featureTwo(playerPtr);
			return;
		}
	}

	if (commands[0] == "look"  && commands[2] == "computer")
	{
		playerLocation->featureOne(playerPtr);
		return;

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
		std::cout << "You are in the Research Lab." << std::endl;
		mapResearchLab();
		return;
	}

	/*calls helper go function with playerLocation pointer, list of rooms and room number to go to.*/

	if ((commands[0] == "go" && commands[2] == "hallway1") || (commands[2] == "hallway 1") || (commands[2] == "hallway") || (commands[2] == "northeast") || (commands[2] == "north east"))
	{
		go(playerLocation, roomList, 1, playerPtr);
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


