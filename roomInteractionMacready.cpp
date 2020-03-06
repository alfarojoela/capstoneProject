#include "roomInteractionMacready.hpp"

/*Function to interact with macready room*/
/*Based on commands within array, conditions are set up to control interactions with room.*/
/*If a condition is met a room function is called for more interaction.  return is then used to get back to the main function.*/
/*If no conditions are met, it moves to the bottom of the function and a message is printed that whatever the user typed cannot be done.*/

void roomInteractionMacready(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList, Parser* parserPtr)
{
	if (commands[0] == "savegame" || commands[0] == "loadgame")
	{
		return;

	}
	/*helper phrase.*/
	if (commands[0] == "look" && commands[1] == "for" && commands[2] == "booze")
	{
		std::cout << "You start looking for booze and notice..." << std::endl;
		std::string freeBooze = "beer";

		if (playerLocation->checkItem(freeBooze) != 999)
		{
			std::cout << "You notice a bottle of beer on the floor." << std::endl;
			std::cout << "You don't think MacReady will miss it." << std::endl;
			std::cout << "He thinks this one is nasty." << std::endl;
			std::cout << "After checking the room for booze, you also notice some other potentially useful items." << std::endl;
		}

		playerLocation->itemsInRoom();
		return;
	}

	if ((commands[0] == "use" && commands[2] == "blood test") || (commands[0] == "look" && commands[1] == "at" && commands[2] == "blood"))
	{
		std::cout << "Hmm..." << std::endl;
		std::cout << "There's no one around to do a blood test on." << std::endl;
		std::cout << "And you have no reason to test your blood." << std::endl;
		return;
	}

	if (commands[0] == "talk")
	{
		std::cout << "There is no one in Macready's quarters to talk to except yourself.  So you try to have a conversation, but it doesn't work out so well." << std::endl;
		std::cout << "Maybe you should leave the room to find someone to talk to." << std::endl;
		return;
	}

	if (commands[0] == "drink")
	{
		drink(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "smell" && commands[1] == "the" && commands[2] == "bed")
	{
		std::cout << "You take a deep whiff from the bed...It smells like a chimp sleeps here.  And you should know because you worked a summer at the zoo once." << std::endl;
		return;
	}

	if (commands[0] == "smell" && commands[1] == "the" && commands[2] == "computer")
	{
		std::cout << "It smells like a new computer.  The chimpesque odor of Macready's room has not had the opportunity to be absorbed by the computer yet." << std::endl;
		return;
	}

	if (commands[0] == "drop")
	{
		drop(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "attack")
	{
		std::cout << "The room is full of inanimate objects.  There's no one and nothing to attack." << std::endl;
		return;
	}

	if (commands[0] == "eat")
	{
		eat(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "use" && commands[1] == "the" && commands[2] == "computer")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "You already played with the computer." << std::endl;
			return;
		}

		if (playerLocation->getFeatureTwoHap() == 0)
		{
			playerLocation->featureTwo(playerPtr);
			return;
		}
	}

	if (commands[0] == "use" && commands[1] == "the" && commands[2] == "bed")
	{
		std::cout << "You consider taking a nap in Macready's bed.  But then reconsider.  You don't wanna smell like a chimp." << std::endl;
		return;
	}

	if (commands[0] == "jump" && commands[1] == "on" && commands[2] == "bed")
	{
		std::cout << "You climb onto Macready's bed and start jumping on it to test the springs.  You hear something snap and stop your jumping." << std::endl;
		std::cout << "You have the benefit of plausible deniability.  If he complains about a broken bed, you are just going to deny all knowledge." << std::endl;
		return;
	}

	if (commands[0] == "jump" && commands[1] == "on" && commands[2] == "computer")
	{
		std::cout << "The computer is not meant for jumping on.  You can't do that here." << std::endl;
		return;
	}

	if (commands[0] == "flee")
	{
		std::cout << "The room is full of inanimate objects.  There is nothing to flee from." << std::endl;
		return;
	}

	if (commands[0] == "break" && commands[2] == "computer")
	{
		std::cout << "You're jealous of Macready's outstanding computer and for a split second you consider breaking it out of spite." << std::endl;
		std::cout << "However, you come to your senses and decide not to break Macready's computer." << std::endl;
		return;
	}

	if (commands[0] == "break" && commands[2] == "bed")
	{
		std::cout << "You don't want to break Macready's bed.  That will get you on his wrongside." << std::endl;
		return;
	}

	if (commands[0] == "look" && commands[1] == "" && commands[2] == "")
	{
		std::string longDescription = playerLocation->getLongDescrip();
		std::cout << longDescription << std::endl;
		return;
	}

	if (commands[0] == "look" &&  commands[2] == "bed")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "You already checked under the bed and the room.  No booze.  Drat!" << std::endl;
			return;
		}

		if (playerLocation->getFeatureOneHap() == 0)
		{
			std::cout << "You look at Macready's bed.  It's not made." << std::endl;
			playerLocation->featureOne(playerPtr);
			return;
		}
	}

	if (commands[0] == "look" && commands[2] == "computer")
	{
		std::cout << "It's a state of the art Commodore 64." << std::endl;
		std::cout << "The CPU is 1.023 MHz!" << std::endl;
		std::cout << "The memory is 64 KB of RAM!" << std::endl;
		std::cout << "This must have set MacReady back by $519.00" << std::endl;
		std::cout << "He is quite the spender." << std::endl;
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

	if (commands[0] == "current" && commands[2] == "room")
	{
		std::cout << "You are in Macreqdy's Quarters." << std::endl;
		mapMacready();
		return;
	}

	/*calls helper go function with playerLocation pointer, list of rooms and room number to go to.*/
	if (commands[0] == "go" && commands[1] == "to" && commands[2] == "hallway1")
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

	if (commands[0] == "map")
	{
		map();
		return;
	}

	std::cout << "You can't do that here." << std::endl;
	return;
}

