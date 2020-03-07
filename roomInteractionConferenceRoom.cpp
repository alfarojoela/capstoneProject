#include "roomInteractionConferenceRoom.hpp"


void roomInteractionConferenceRoom(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList, Parser* parserPtr)
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
			std::cout << "You notice a bottle of beer beside the projector." << std::endl;
			std::cout << "After checking the room for booze, you also notice some other potentially useful items." << std::endl;
		}
		playerLocation->itemsInRoom();
		return;
	}

	if ((commands[0] == "use" && commands[2] == "blood test") || (commands[0] == "look" && commands[1] == "at" && commands[2] == "blood"))
	{
		std::cout << "Now is not the time to do a blood test." << std::endl;
		std::cout << "You are in the Conference Room by yourself." << std::endl;
		std::cout << "No need to test your own blood." << std::endl;
		return;
	}
	if (commands[0] == "talk")
	{
		std::cout << "You call out to the room." << std::endl;
		std::cout << "No one responds to your calls." << std::endl;
		return;
	}

	if (commands[0] == "drink" && commands[2] == "booze")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "You've had enough of that cheap brand." << std::endl;
			std::cout << "You resolve to find something better." << std::endl;
			return;
		}

		else
		{
			playerLocation->featureOne(playerPtr);
			return;
		}
	}

	if (commands[0] == "drink")
	{
		drink(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "smell" && commands[2] == "booze")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "You decide you are going to smell the bottle of booze on the main table even though you already downed some." << std::endl;
			std::cout << "You are glad you drank gulped it down without savoring it." << std::endl;
			std::cout << "The smell reminds you of floor cleaner." << std::endl;
			return;
		}

		else
		{
			std::cout << "You feel too impatient for that!  Instead..." << std::endl;
			playerLocation->featureOne(playerPtr);
			return;
		}
	}

	if (commands[0] == "smell" && commands[2] == "projector")
	{
		std::cout << "You notice it has the faint smell of cigarettes." << std::endl;
		std::cout << "Some of the crew members have their own films they watch in their quarters while relaxing and smoking." << std::endl;
		return;
	}

	if (commands[0] == "drop")
	{
		drop(commands, playerLocation, playerPtr, roomList, 2);
		return;
	}

	if (commands[0] == "attack" && commands[2] == "booze")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "Although you already had a few swigs off the bottle, you decide to look for something better." << std::endl;
			return;
		}

		else
		{
			std::cout << "You feel an incredible thirst." << std::endl;
			playerLocation->featureOne(playerPtr);
			return;
		}
	}

	if (commands[0] == "attack" && commands[2] == "projector")
	{
		std::cout << "The projector is innocent of any crimes." << std::endl;
		std::cout << "You decide to not attack it." << std::endl;
		return;
	}

	if (commands[0] == "eat")
	{
		eat(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "jump" && commands[2] == "table")
	{
		std::cout << "You jump up on the table to get a better view of the room." << std::endl;
		std::cout << "You notice on the ceiling panel above your head it says, 'Wang Chi was here.' " << std::endl;
		std::cout << "You remember him from a few months ago." << std::endl;
		std::cout << "He left the base and went to San Francisco to open a restaurant." << std::endl;
		return;
	}

	if (commands[0] == "jump" && commands[2] == "projector")
	{
		std::cout << "You don't want to tackle the projector." << std::endl;
		return;
	}

	if (commands[0] == "flee")
	{
		std::cout << "You feel quite safe in the Conference Room." << std::endl;
		std::cout << "There is no one to flee from." << std::endl;
		return;

	}

	if (commands[0] == "break" && commands[2] == "table")
	{
		std::cout << "You feel frustrated and decide to break the table by giving it a karate chop." << std::endl;
		std::cout << "WHACK!" << std::endl;
		std::cout << "You have only succeeded in hurting your hand." << std::endl;
		return;
	}

	if (commands[0] == "break" && commands[2] == "projector")
	{
		std::cout << "You don't want to break the projector." << std::endl;
		std::cout << "It is one of the few things the crew members can rely on for entertainment." << std::endl;
		return;
	}

	if (commands[0] == "look" && commands[1] == "" && commands[2] == "")
	{
		std::string longDescription = playerLocation->getLongDescrip();
		std::cout << longDescription << std::endl;
		return;
	}

	if (commands[0] == "look" && commands[2] == "table")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "It is an ordinary table with the bottle of booze you drank from and some tapes." << std::endl;
			return;
		}

		else
		{
			playerLocation->featureOne(playerPtr);
			return;
		}
	}

	if (commands[0] == "look" && commands[2] == "projector")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "It is a good projector." << std::endl;
			std::cout << "It would just be nice if there was a bigger library of movies to choose from." << std::endl;
			return;
		}

		else
		{
			playerLocation->featureTwo(playerPtr);
			return;
		}
	}

	if (commands[0] == "look" && commands[2] == "tapes")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "You don't feel like watching those movies again." << std::endl;
			return;
		}

		else
		{
			playerLocation->featureTwo(playerPtr);
			return;
		}
	}

	if (commands[0] == "use" && commands[2] == "projector")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "You already watched all the tapes you could find." << std::endl;
			std::cout << "You don't want to sit through them again." << std::endl;
			return;
		}

		else
		{
			playerLocation->featureTwo(playerPtr);
			return;
		}
	}


	if (commands[0] == "look" && commands[1] == "at")
	{
		lookAt(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if ((commands[0] == "go" && commands[2] == "hallway2") || (commands[2] == "hallway") || (commands[2] == "northwest") || (commands[2] == "hallway2") || (commands[2] == "hallway1"))
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
		std::cout << "You are in the Conference Room." << std::endl;
		mapConferenceRoom();
		return;
	}

	/*calls helper go function with playerLocation pointer, list of rooms and room number to go to.*/

	if (commands[0] == "take" && commands[2] == "booze")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "You've had enough of it." << std::endl;
			return;
		}

		else
		{
			playerLocation->featureOne(playerPtr);
		}
	}

	if (commands[0] == "take" && commands[2] == "tapes")
	{
		std::cout << "You would rather leave the tapes in here than take them with you." << std::endl;
		return;
	}

	if (commands[0] == "take")
	{
		take(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if ((commands[0] == "go" && commands[2] == "hallway2") || (commands[0] == "go" && commands[2] == "hallway") || (commands[0] == "go" && commands[2] == "hallway 2") || (commands[2] == "northwest") || (commands[2] == "north"))
	{
		if(commands[2] == "north")
		{
		std::cout << "You probably meant northwest.\nWe'll make the correction to northwest.\n--Team Thingy" <<std::endl;
		}


		go(playerLocation, roomList, 9, playerPtr);
		return;
	}

	if (commands[0] == "go" && commands[2] == "projector")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "You already watched all the tapes you could find." << std::endl;
			std::cout << "You don't want to sit through them again." << std::endl;
			return;
		}

		else
		{
			playerLocation->featureTwo(playerPtr);
			return;
		}
	}

	if (commands[0] == "go" && commands[2] == "table")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "You already drank all the booze you wanted from the bottle on the table." << std::endl;
			return;
		}

		else
		{
			playerLocation->featureOne(playerPtr);
			return;
		}
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


