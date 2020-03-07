#include "roomInteractionEquipmentRoom.hpp"


void roomInteractionEquipmentRoom(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList, Parser* parserPtr)
{
	if (commands[0] == "savegame" || commands[0] == "loadgame")
	{
		return;

	}
	/*Set of commands to check room inventory.*/
	if (commands[0] == "look" && commands[1] == "for" && commands[2] == "booze")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "You start looking for booze and notice..." << std::endl;
			std::string freeBooze = "beer";

			if (playerLocation->checkItem(freeBooze) != 999)
			{
				std::cout << "You notice a bottle of beer on the floor." << std::endl;
				std::cout << "Amazingly, it was not broken when all the carnage went down." << std::endl;
				std::cout << "If you want to add it to your inventory, type: 'take beer' " << std::endl;
				std::cout << "After checking the room for booze, you also notice some other potentially useful items." << std::endl;

			}

			playerLocation->itemsInRoom();
			return;
		}

		else
		{
			std::cout << "Turn on the lights before you start looking for booze!" << std::endl;
			std::cout << "You might trip and crack your head." << std::endl;
			return;
		}
	}

	if ((commands[0] == "use" && commands[2] == "blood test") || (commands[0] == "look" && commands[1] == "at" && commands[2] == "blood"))
	{
		std::cout << "It would make sense to do that with a human specimen." << std::endl;
		std::cout << "You are the only human here and there is no reason to test your own blood." << std::endl;
		return;
	}

	if (commands[0] == "talk")
	{
		if (playerLocation->getFeatureOneHap() == 0)
		{
			std::cout << "You call out to the darkness.  'Hello?  Is anyone in here?'  There is no response.  Perhaps you should use the lights." << std::endl;
			return;
		}

		else
		{
			std::cout << "With the lights on, you can see there is no one to talk to." << std::endl;
			return;
		}
	}

	if (commands[0] == "drink")
	{
		drink(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "smell" && commands[1] == "the" && commands[2] == "lights")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "You smell the light switch for some reason.  It smells faintly of the Dorito dust that is still on your fingers from last night's drinking session." << std::endl;
			return;
		}

		else
		{
			std::cout << "Your olfactory acuity is not strong enough to find the lights in the darkn." << std::endl;
			std::cout << "Perhaps you should use the sense of touch instead to feel for the light switch." << std::endl;
			return;
		}
	}

	if (commands[0] == "smell" && commands[1] == "the" && commands[2] == "case")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "The case doesn't smell like anything." << std::endl;
			return;
		}

		else
		{
			std::cout << "Although the room is dark, you remember there is a case in it.  You try to smell it and pick up nothing." << std::endl;
			return;
		}
	}

	if (commands[0] == "drop")
	{
		drop(commands, playerLocation, playerPtr, roomList, 2);
		return;
	}

	if (commands[0] == "attack")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "There's nothing to attack in here." << std::endl;
			return;
		}

		else
		{
			std::cout << "With the lights off you are unsure if there is anything to attack.  You blindly start punching at the darkness.  Your fists connect with nothing." << std::endl;
			return;
		}

	}

	if (commands[0] == "eat" && commands[1] == "the" && commands[2] == "lights")
	{
		std::cout << "Nope.  You can't do that." << std::endl;
		return;
	}

	if (commands[0] == "eat")
	{
		eat(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "use" && commands[1] == "the" && commands[2] == "lights")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "You think about turning the lights off, but reconsider.  It might be a good idea to leave them on for now." << std::endl;
			return;
		}

		else
		{
			playerLocation->featureOne(playerPtr);
			return;
		}
	}

	if (commands[0] == "use" && commands[1] == "the" && commands[2] == "case")
	{
		std::cout << "You fumble with the case.  It appears to be locked." << std::endl;
		return;
	}

	if (commands[0] == "jump" && commands[1] == "on" && commands[2] == "case")
	{
		std::cout << "You jump up and down on the case and fall onto the floor." << std::endl;
		std::cout << "'Ouch,' you exclaim." << std::endl;
		return;
	}

	if (commands[0] == "flee")
	{
		std::cout << "There is nothing to flee from...At least not at this time." << std::endl;
		return;
	}

	if (commands[0] == "break" && commands[1] == "the" && commands[2] == "lights")
	{
		std::cout << "You decide against it.  You might have to come back here.  So it is a good idea to not break the light switch or lights." << std::endl;
		return;
	}

	if (commands[0] == "break" && commands[1] == "the" && commands[2] == "case")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "You already broke into the case." << std::endl;
		}

		else
		{
			playerLocation->featureTwo(playerPtr);
			return;
		}
	}

	if (commands[0] == "look" && commands[1] == "" && commands[2] == "")
	{
		std::string longDescription = playerLocation->getLongDescrip();
		std::cout << longDescription << std::endl;
		return;
	}

	if (commands[0] == "look" && commands[1] == "at" && commands[2] == "lights")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "The lightswitch has a little bit of Dorito dust smeared on it.  You are the culprit." << std::endl;
			return;
		}

		else
		{
			std::cout << "The room is too dark to see the light switch." << std::endl;
			return;
		}
	}

	if (commands[0] == "look" && commands[1] == "at" && commands[2] == "case")
	{
		if (playerLocation->getFeatureOneHap() == 1 && playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "You look at the broken glass from the case.  You have an odd sense of satisfaction about your handy work." << std::endl;
			return;
		}

		if (playerLocation->getFeatureOneHap() == 1 && playerLocation->getFeatureTwoHap() == 0)
		{
			std::cout << "You see the case holding the blowtorch is locked." << std::endl;
			std::cout << "It looks like you could break the glass of the case to get the blowtorch." << std::endl;
			return;
		}


	}

	if (commands[0] == "look" && commands[1] == "at" && commands[2] == "other equipment")
	{
		std::cout << "The other equipment in the room is of no interest to you right now." << std::endl;
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
		std::cout << "You are in the Equipment Room." << std::endl;
		mapEquipmentRoom();
		return;
	}

	/*calls helper go function with playerLocation pointer, list of rooms and room number to go to.*/

	if ((commands[0] == "go" && commands[2] == "hallway2") || (commands[2] == "hallway") || (commands[2] == "southwest") || (commands[2] == "hallway2") || (commands[2] == "hallway1"))
	{
		go(playerLocation, roomList, 1, playerPtr);
		return;
	}

	if ((commands[0] == "go" && commands[2] == "toolshed") || (commands[0] == "go" && commands[2] == "tool shed") || (commands[2] == "east"))
	{
		go(playerLocation, roomList, 4, playerPtr);
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


