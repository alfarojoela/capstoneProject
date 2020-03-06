#include "roomInteractionToolShed.hpp"

void roomInteractionToolShed(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList, Parser* parserPtr)
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
			std::cout << "You notice a bottle of beer in the snow." << std::endl;
			std::cout << "It's like it was waiting for you all along!" << std::endl;
			std::cout << "After checking the room for booze, you also notice some other potentially useful items." << std::endl;
		}

		playerLocation->itemsInRoom();
		return;
	}

	if ((commands[0] == "use" && commands[2] == "blood test") || (commands[0] == "look" && commands[1] == "at" && commands[2] == "blood"))
	{
		std::cout << "It would make sense to do that with a human specimen." << std::endl;
		std::cout << "You are the only human here and there is no reason to test your own blood." << std::endl;
		return;
	}

	if (commands[0] == "talk")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "Are you crazy?" << std::endl;
			std::cout << "That thing attacked you!" << std::endl;
			std::cout << "Why tempt fate and call attention to yourself again?" << std::endl;
			return;
		}

		if (playerLocation->getFeatureOneHap() == 0)
		{
			std::cout << "You may want to get closer to the groaning sound." << std::endl;
			std::cout << "Why don't you go closer to whatever is making that sound?" << std::endl;
			std::cout << "Just a little bit closer..." << std::endl;
			std::cout << "Just a little bit closer..." << std::endl;
			std::cout << "Hahhahaha!" << std::endl;
			return;
		}

	}

	if (commands[0] == "drink")
	{
		drink(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "smell" && commands[1] == "the" && commands[2] == "groaning")
	{
		std::cout << "You don't smell anything decipherable coming from the direction of whatever is groaning." << std::endl;
		std::cout << "You should probably get a little bit closer to whatever is making that sound." << std::endl;
		return;
	}

	if (commands[0] == "smell" && commands[1] == "the" && commands[2] == "shining")
	{
		std::cout << "Whatever is shining out here is not casting off any kind of odor." << std::endl;
		std::cout << "Maybe you should get a little closer." << std::endl;
		return;
	}

	if (commands[0] == "drop")
	{
		drop(commands, playerLocation, playerPtr, roomList, 2);
		return;
	}

	if (commands[0] == "attack" && commands[1] == "the" && commands[2] == "groaning")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "You decide to stay away from whatever is making that sound." << std::endl;
			return;
		}

		else
		{
			std::cout << "You steel yourself to be ready to attack whatever is making that groaning sound." << std::endl;
			std::cout << "You then realize it may be a team member making that sound, and you don't want to attack your teammates." << std::endl;
			std::cout << "So you decide to approach cautiously and be ready for the situation.  Like a Plisskin Snake ready to strike..." << std::endl;
			playerLocation->featureOne(playerPtr);
			return;
		}
	}


	if (commands[0] == "eat" && commands[2] == "snow")
	{
		std::cout << "You grab some snow and stuff it in your mouth." << std::endl;
		std::cout << "Suddenly your face goes numb..." << std::endl;
		std::cout << "Then everything goes black." << std::endl;
		playerPtr->setAlive(0);
		return;
	}

	if (commands[0] == "eat" && commands[1] == "the" &&commands[2] == "groaning")
	{
		std::cout << "Whatever is groaning is still alive." << std::endl;
		std::cout << "It could be human or a wounded animal." << std::endl;
		std::cout << "Whatever it is, you decide that it won't be appetizing." << std::endl;
		std::cout << "But you could at least find out what it is, if you get a little closer to it." << std::endl;
		return;
	}

	if (commands[0] == "eat" && commands[1] == "the" && commands[2] == "shining")
	{
		std::cout << "Whatever is shining, it looks like it is glass.  And you probably don't want to eat glass." << std::endl;
		std::cout << "Maybe you should get closer to get a better look." << std::endl;
		return;
	}

	if (commands[0] == "eat")
	{
		eat(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "use" && commands[1] == "the" && commands[2] == "groaning")
	{
		std::cout << "Whatever is groaning out here doesn't seem useable." << std::endl;
		return;
	}

	if (commands[0] == "use" && commands[1] == "the" && commands[2] == "shining")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "If you want to drink the bottle you found, use the drink command." << std::endl;
			return;
		}

		if (playerLocation->getFeatureTwoHap() == 0)
		{
			std::cout << "You don't know what is shining out here." << std::endl;
			std::cout << "You need to get closer to it first before you can decide if you can drink it." << std::endl;
			return;
		}
	}

	if (commands[0] == "jump" && commands[1] == "on" && commands[2] == "groaning")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "Whatever that thing was, you don't want to tangle with it again." << std::endl;
			std::cout << "You decide to steer clear of it." << std::endl;
			return;
		}

		if (playerLocation->getFeatureOneHap() == 0)
		{
			std::cout << "What are you thinking of doing?" << std::endl;
			std::cout << "Seeing if whatever is making that sound wants to play a game of leap frog?" << std::endl;
			return;
		}
	}


	if (commands[0] == "jump" && commands[1] == "on" && commands[2] == "shining")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "You decide you don't want to jump on the bottle of whiskey." << std::endl;
			std::cout << "It has good whiskey in it, and you don't want to break the bottle." << std::endl;
			return;
		}

		if (playerLocation->getFeatureTwoHap() == 0)
		{
			std::cout << "Not sure why you would want to jump on whatever is shining out here." << std::endl;
			std::cout << "But if you want to try that out, you need to get closer first." << std::endl;
			return;
		}
	}

	if (commands[0] == "flee" &&commands[1] == "from" &&commands[2] == "groaning")
	{

		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "Whatever that thing was, it doesn't seem to be aware of you right now." << std::endl;
			std::cout << "You don't need to flee from it unless you get close to it." << std::endl;
			return;
		}

		if (playerLocation->getFeatureOneHap() == 0)
		{
			std::cout << "As you have approached whatever is groaning, it doesn't seem like you need to flee from it yet." << std::endl;
			std::cout << "Maybe you should get closer to it first?" << std::endl;
			return;
		}
	}

	if (commands[0] == "flee" &&commands[1] == "from" &&commands[2] == "shining")
	{

		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "It was a bottle of Maker's Mark." << std::endl;
			std::cout << "Why would you need to flee from that?" << std::endl;
			return;
		}

		if (playerLocation->getFeatureTwoHap() == 0)
		{
			std::cout << "As you have not approached whatever is groaning, it doesn't seem like you need to flee from it just yet." << std::endl;
			std::cout << "Maybe you should get closer to it first to decide if you need to flee from it?" << std::endl;
			return;
		}
	}


	if (commands[0] == "break" && commands[1] == "the" && commands[2] == "groaning")
	{
		std::cout << "That doesn't make any sense." << std::endl;
		std::cout << "Do you mean you want to attack the thing that's groaning?" << std::endl;
		std::cout << "If so, maybe you should get closer to the thing that's groaning." << std::endl;
		return;
	}

	if (commands[0] == "break" && commands[1] == "the" && commands[2] == "shining")
	{
		std::cout << "If you want to break the thing that's shining, you should probably get closer to it." << std::endl;
		return;
	}

	if (commands[0] == "look" && commands[1] == "" && commands[2] == "")
	{
		std::string longDescription = playerLocation->getLongDescrip();
		std::cout << longDescription << std::endl;
		return;
	}

	if (commands[0] == "look" && commands[1] == "at" && commands[2] == "groaning")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "You strain your eyes in the direction of the groaning." << std::endl;
			std::cout << "You aren't sure what the heck attacked you, but you don't want to tangle with it again." << std::endl;
			return;
		}

		else
		{
			std::cout << "You look off into the distance where you hear the groaning." << std::endl;
			std::cout << "You cannot make out what you are seeing." << std::endl;
			std::cout << "You need to get closer." << std::endl;
			std::cout << "So you cautiously walk in the direction where you hear the groaning." << std::endl;
			std::cout << "It gets louder with each step you take..." << std::endl;
			playerLocation->featureOne(playerPtr);
			return;
		}
	}

	if (commands[0] == "look" && commands[1] == "at" && commands[2] == "shining")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "You already picked up what was shining." << std::endl;
			std::cout << "It was a bottle of Maker's Mark." << std::endl;
			std::cout << "This mystery has already been solved." << std::endl;
			return;
		}

		else
		{
			std::cout << "You stare off into the distance from where the shining is coming from." << std::endl;
			std::cout << "You can't make it out." << std::endl;
			std::cout << "You need to get closer to it to get a better look." << std::endl;
			return;
		}

	}

	if (commands[0] == "look" && commands[1] == "at" && commands[2] == "creature")
	{

		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "You are not sure what it is that just attacked you." << std::endl;
			std::cout << "You are sure it is not of this world." << std::endl;
			std::cout << "Maybe it or one of its kind caused all the carnage in the hallway." << std::endl;
			std::cout << "It has returned to its original spot and continues to groan in the distance." << std::endl;
			return;
		}
	}

	if (commands[0] == "look" && commands[1] == "at")
	{
		lookAt(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "current" && commands[2] == "room")
	{
		std::cout << "CURRENT ROOM: " << playerLocation->getName() << std::endl;
		mapToolShed();
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
		std::cout << "You are near the Tool Shed." << std::endl;
		mapToolShed();
		return;
	}


	/*calls helper go function with playerLocation pointer, list of rooms and room number to go to.*/

	if (commands[0] == "go" && commands[1] == "to" && commands[2] == "equipment room")
	{
		go(playerLocation, roomList, 3, playerPtr);
		return;
	}

	if (commands[0] == "go" && commands[1] == "to" &&commands[2] == "groaning")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "You narrowly escaped death the last time you went in the direction of the groaning." << std::endl;
			std::cout << "You decide to tempt fate again." << std::endl;
			std::cout << "This time the creature gets the upper hand and rips your head off." << std::endl;
			playerPtr->setAlive(0);
			return;
		}

		if (playerLocation->getFeatureOneHap() == 0)
		{
			playerLocation->featureOne(playerPtr);
			return;
		}
	}

	if (commands[0] == "go" && commands[1] == "to" &&commands[2] == "shining")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "You already approached what was shining." << std::endl;
			std::cout << "It was a bottle of Maker's Mark." << std::endl;
			return;
		}

		if (playerLocation->getFeatureTwoHap() == 0)
		{
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

	if (commands[0] == "map")
	{
		map();
		return;
	}

	std::cout << "You can't do that here." << std::endl;
	return;
}

