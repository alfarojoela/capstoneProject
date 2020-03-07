#include "roomInteractionHallway1.hpp"


void roomInteractionHallway1(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList, Parser* parserPtr)
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
			std::cout << "You notice a bottle of beer on the floor." << std::endl;
			std::cout << "What luck it didn't break during the outbreak of carnage." << std::endl;
			std::cout << "After checking the room for booze, you also notice some other potentially useful items." << std::endl;
		}

		playerLocation->itemsInRoom();
		return;
	}

	if ((commands[0] == "use" && commands[2] == "blood test") || (commands[0] == "look" && commands[1] == "at" && commands[2] == "blood"))
	{
		std::cout << "Though this room does have its share of blood, none of it is fresh." << std::endl;
		std::cout << "Also you aren't sure of the source of blood." << std::endl;
		std::cout << "Without this information, it wouldn't be helpful to run a test." << std::endl;
		return;
	}

	if (commands[0] == "talk")
	{
		std::cout << "There is no one in the hallway to talk to except yourself.  So you try to have a conversation, but it doesn't work out so well." << std::endl;
		std::cout << "Maybe you could leave this room to find someone to talk to?" << std::endl;
		return;
	}

	if (commands[0] == "drink")
	{
		drink(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "smell" && commands[2] == "floor")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "'What happened here?'  You wonder aloud." << std::endl;
			return;
		}

		else
		{
			std::cout << "The hallway has a faint metallic smell to it.  You now realize you have been smelling fresh spilt blood.  You now see tha the hallway is charged with a desperate violence..." << std::endl;
			playerLocation->featureOne(playerPtr);
			return;
		}
	}

	if (commands[0] == "smell" && commands[2] == "lights")
	{
		std::cout << "You tilt your head up to point your nostrils up at the ceiling and away from the terrible smell.  Some of the flourescent lights burned out and are stinking up the place.  It reminds you of burnt marshmallows on a campfire." << std::endl;
		return;
	}

	if (commands[0] == "drop")
	{
		drop(commands, playerLocation, playerPtr, roomList, 1);
		return;
	}

	if (commands[0] == "attack")
	{
		std::cout << "There's no one and nothing to attack now." << std::endl;
		return;
	}

	if (commands[0] == "eat")
	{
		eat(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "use" && commands[2] == "lights")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "The lighst continue to flicker on and off..." << std::endl;
			return;
		}

		else
		{
			playerLocation->featureTwo(playerPtr);
			return;
		}
	}

	if (commands[0] == "use" &&  commands[2] == "floor")
	{
		std::cout << "You are already using the floor to stand on.  What other possible use could it be to you?" << std::endl;
		return;
	}

	if (commands[0] == "jump" && commands[2] == "floor")
	{
		std::cout << "You jump up and down on the floor.  It seems stable." << std::endl;
		return;
	}


	if (commands[0] == "jump" && commands[2] == "lights")
	{
		std::cout << "That just doesn't make any sense.  There is no way you can do that." << std::endl;
		return;
	}

	if (commands[0] == "flee")
	{
		std::cout << "There is nothing to flee from." << std::endl;
		return;
	}

	if (commands[0] == "break"  && commands[2] == "floor")
	{
		std::cout << "The floor is linoleum glued to concrete.  There is no way you are going to be able to break it." << std::endl;
		return;
	}

	if (commands[0] == "break" && commands[2] == "lights")
	{
		std::cout << "That is a bad idea.  Breaking the lights is going to make this room completely dark.  You could trip over something and crack your head!" << std::endl;
		return;
	}

	if (commands[0] == "look" && commands[1] == "" && commands[2] == "")
	{
		std::string longDescription = playerLocation->getLongDescrip();
		std::cout << longDescription << std::endl;
		return;
	}

	if (commands[0] == "look" && commands[2] == "floor")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "You realize now that the trail of red streaks on the floor is blood." << std::endl;
			return;
		}

		else
		{
			std::cout << "You take a closer look at the floor..." << std::endl;
			playerLocation->featureOne(playerPtr);
			return;
		}
	}

	if (commands[0] == "look" && commands[2] == "lights")
	{
		std::cout << "The lights flicker on and off.  Maybe you should use the lights." << std::endl;
		return;
	}

	if (commands[0] == "look" && commands[1] == "at")
	{
		lookAt(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "room")
	{
		std::cout << "CURRENT ROOM: " << playerLocation->getName() << std::endl;
		return;
	}

	if ((commands[0] == "current" && commands[2] == "room") || (commands[0] == "map"))
	{
		std::cout << "You are in Hallway 1. " << std::endl;
		mapHallway1();
		return;
	}

	/*calls helper go function with playerLocation pointer, list of rooms and room number to go to.*/

	if ((commands[0] == "go" && commands[2] == "latrine") || (commands[2] == "northwest"))
	{
		go(playerLocation, roomList, 2, playerPtr);
		return;
	}

	if ((commands[0] == "go" && commands[2] == "macready") || (commands[2] == "north"))
	{
		go(playerLocation, roomList, 0, playerPtr);
		return;
	}

	if ((commands[0] == "go" && commands[2] == "equipment room") || (commands[0] == "go" && commands[2] == "equipmentroom") || (commands[2] == "northeast"))
	{
		go(playerLocation, roomList, 3, playerPtr);
		return;
	}

	if ((commands[0] == "go" && commands[2] == "radio room") || (commands[0] == "go" && commands[2] == "radioroom") || (commands[2] == "east"))
	{
		go(playerLocation, roomList, 6, playerPtr);
		return;
	}

	if ((commands[0] == "go" && commands[2] == "hallway2") || (commands[2] == "south") || (commands[0] == "go" && commands[2] == "hallway1"))
	{
		go(playerLocation, roomList, 9, playerPtr);
		return;
	}

	if ((commands[0] == "go" && commands[2] == "research lab") || (commands[0] == "go" && commands[2] == "researchlab") || (commands[2] == "southwest"))
	{
		go(playerLocation, roomList, 7, playerPtr);
		return;
	}

	if ((commands[0] == "go" && commands[2] == "sickbay") || (commands[0] == "go" && commands[2] == "sick bay") || (commands[2] == "west"))
	{
		go(playerLocation, roomList, 5, playerPtr);
		return;
	}

	if ((commands[0] == "take" && commands[2] == "axe"))
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


