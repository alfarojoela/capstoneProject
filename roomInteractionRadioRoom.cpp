#include "roomInteractionRadioRoom.hpp"


void roomInteractionRadioRoom(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList, Parser* parserPtr)
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
			std::cout << "You notice a cold one beside the radio equipment." << std::endl;
			std::cout << "It has MacReady's name on it with a message taped to it." << std::endl;
			std::cout << "'Don't drink my beer -RJ' it reads." << std::endl;
			std::cout << "For all you know, MacReady may not be around anymore." << std::endl;
			std::cout << "After checking the room for booze, you also notice some other potentially useful items." << std::endl;

		}

		playerLocation->itemsInRoom();
		return;
	}

	if ((commands[0] == "use" && commands[2] == "blood test") || (commands[0] == "look" && commands[1] == "at" && commands[2] == "blood"))
	{
		std::cout << "Now is not the time to do a blood test." << std::endl;
		std::cout << "You are in the Radio Room by yourself." << std::endl;
		std::cout << "No need to test your own blodo." << std::endl;
		return;
	}

	if (commands[0] == "talk" && commands[1] == "on" && commands[2] == "radio")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "It wasn't working well anyway." << std::endl;
			std::cout << "At least you have some copper wire for you troubles." << std::endl;
			return;
		}

		if (playerLocation->getFeatureOneHap() == 0)
		{
			playerLocation->featureOne(playerPtr);
			return;
		}
	}

	if (commands[0] == "talk" && commands[1] == "on" && commands[2] == "military radio")
	{
		playerLocation->featureTwo(playerPtr);
	}


	if (commands[0] == "drink")
	{
		drink(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "smell" && commands[1] == "the" && commands[2] == "civilian radio")
	{
		std::cout << "It doesn't really smell like much of anything." << std::endl;
		return;
	}

	if (commands[0] == "smell" && commands[1] == "the" && commands[2] == "military radio")
	{
		std::cout << "It doesn't really smell like much of anything." << std::endl;
		return;
	}

	if (commands[0] == "drop")
	{
		drop(commands, playerLocation, playerPtr, roomList, 2);
		return;
	}

	if (commands[0] == "attack" && commands[1] == "the" && commands[2] == "civilian radio")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "Why are you going to take your frustration out on inanimate objects today?" << std::endl;
			std::cout << "Is all that violence really necessary?" << std::endl;
			return;
		}

		else
		{
			std::cout << "Before you attack the radio, why don't you try using it first?" << std::endl;
			return;
		}
	}

	if (commands[0] == "attack" && commands[1] == "the" && commands[2] == "military radio")
	{
		std::cout << "You make a fist to punch the radio, but then think better of it." << std::endl;
		std::cout << "It is after all a radio for contacting the military." << std::endl;
		std::cout << "You aren't sure if there is some law you would be breaking for attacking equipment used to contact the military." << std::endl;
		return;
	}

	if ((commands[0] == "eat" && commands[1] == "the" && commands[2] == "civilian radio") || (commands[0] == "eat" && commands[1] == "the" && commands[2] == "military radio"))
	{
		std::cout << "You remember reading about some guy in the Guinness Book of Records who ate metal and glass object and even a plane." << std::endl;
		std::cout << "You look at the radio and decide you don't have the intenstinal fortitude to do such feats of stupidity." << std::endl;
		return;
	}

	if (commands[0] == "eat")
	{
		eat(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "use" && commands[1] == "the" && commands[2] == "civilian radio")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "You already did that.  At least you got the copperwire for your troubles." << std::endl;
			return;
		}

		if (playerLocation->getFeatureOneHap() == 0)
		{
			playerLocation->featureOne(playerPtr);
			return;
		}
	}

	if (commands[0] == "use" && commands[1] == "the" && commands[2] == "military radio")
	{
		playerLocation->featureTwo(playerPtr);
		return;
	}

	if (commands[0] == "jump" && commands[1] == "on" && commands[2] == "civilian radio")
	{
		std::cout << "You decide to climb up on the desk and jump on the radio." << std::endl;
		std::cout << "You fall off the desk and do a face plant on the floor." << std::endl;
		std::cout << "You suffer a slight concussion." << std::endl;
		playerPtr->gritHit(1);
		return;
	}


	if (commands[0] == "jump" && commands[1] == "on" && commands[2] == "military radio")
	{
		std::cout << "You reconsider jumping on the equipment used to contact the military." << std::endl;
		return;
	}

	if (commands[0] == "flee" &&commands[1] == "from" &&commands[2] == "civilian radio")
	{

		std::cout << "You don't need to be afraid of the radio." << std::endl;
		std::cout << "It won't bite." << std::endl;
		return;
	}

	if (commands[0] == "flee" &&commands[1] == "from" &&commands[2] == "military radio")
	{

		std::cout << "You don't need to be afraid of the radio." << std::endl;
		std::cout << "It won't bite." << std::endl;
		return;
	}


	if (commands[0] == "break" && commands[1] == "the" && commands[2] == "civilian radio")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "You can't do that again." << std::endl;
			return;
		}

		if (playerLocation->getFeatureOneHap() == 0)
		{
			std::cout << "Before you break it, try using it first." << std::endl;
			return;
		}
	}

	if (commands[0] == "break" && commands[1] == "the" && commands[2] == "military radio")
	{
		std::cout << "You decide against breaking the radio used to contact the military." << std::endl;
		std::cout << "What if you need to use it later?" << std::endl;
		return;
	}

	if (commands[0] == "look" && commands[1] == "" && commands[2] == "")
	{
		std::string longDescription = playerLocation->getLongDescrip();
		std::cout << longDescription << std::endl;
		return;
	}

	if (commands[0] == "look" && commands[1] == "at" && commands[2] == "civilian radio")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "It has seen better days." << std::endl;
			std::cout << "It looks like its ready for the junk heap." << std::endl;
			return;
		}

		else
		{
			std::cout << "You are curious about the radio." << std::endl;
			std::cout << "You decide to try and use it." << std::endl;
			playerLocation->featureOne(playerPtr);
			return;
		}
	}

	if (commands[0] == "look" && commands[1] == "at" && commands[2] == "military radio")
	{
		std::cout << "This radio is newer than the civilian radio." << std::endl;
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
		std::cout << "You are in the Radio Room." << std::endl;
		mapRadioRoom();
		return;
	}

	/*calls helper go function with playerLocation pointer, list of rooms and room number to go to.*/

	if ((commands[0] == "go"  && commands[2] == "hallway1") || (commands[2] == "west") || (commands[2] == "hallway 1"))
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


