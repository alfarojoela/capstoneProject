#include "roomInteractionSickBay.hpp"


void roomInteractionSickBay(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList, Parser* parserPtr)
{
	if (commands[0] == "savegame" || commands[0] == "loadgame")
	{
		return;
	}
	/*phrase for looking at room inventory*/
	if (commands[0] == "look" && commands[1] == "for" && commands[2] == "booze")
	{
		std::cout << "After checking the room for booze, you also notice the following..." << std::endl;

		playerLocation->itemsInRoom();
		return;
	}

	if ((commands[0] == "use" && commands[2] == "blood test") || (commands[0] == "look" && commands[1] == "at" && commands[2] == "blood"))
	{
		std::cout << "Now is not the time to do a blood test." << std::endl;
		return;
	}

	if (commands[0] == "talk" && commands[2] == "crew member")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "Although he attacked you previously, you decide to call out to him to get his attention." << std::endl;
			std::cout << "You try talking to Jack from a safe distance." << std::endl;
			std::cout << "He is nonresponsive." << std::endl;
			return;
		}

		if (playerLocation->getFeatureTwoHap() == 0)
		{
			playerLocation->featureTwo(playerPtr);
			return;
		}
	}

	if (commands[0] == "drink")
	{
		drink(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if (commands[0] == "smell" && commands[2] == "medical supplies")
	{
		std::cout << "The medical supplies have that sterile smell only medical supplies can have." << std::endl;
		return;
	}

	if (commands[0] == "smell" && commands[2] == "crew member")
	{
		std::cout << "You can smell Jack from a good distance." << std::endl;
		std::cout << "He doesn't smell quite right." << std::endl;
		std::cout << "It reminds you of putrefication." << std::endl;
		return;
	}

	if (commands[0] == "drop")
	{
		drop(commands, playerLocation, playerPtr, roomList, 2);
		return;
	}

	if (commands[0] == "attack" && commands[2] == "crew member")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "You are not anxious to tangle with Jack again." << std::endl;
			std::cout << "There was something unnatural about the way he was moving." << std::endl;
			std::cout << "There was an inhuman quality to the way he moved." << std::endl;
			return;
		}

		else
		{
			std::cout << "Although Jack is a crew member, and you have nothing against him, you decide you are going to walk over and punch him in the face." << std::endl;
			playerLocation->featureTwo(playerPtr);
			return;
		}
	}


	if (commands[0] == "eat" && commands[2] == "medical supplies")
	{
		std::cout << "You look through the medical supplies and start eating them although they are for external use only." << std::endl;
		std::cout << "You should have used them as directed." << std::endl;
		playerPtr->setAlive(0);
		return;
	}

	if (commands[0] == "eat" && commands[2] == "crew member")
	{
		std::cout << "What is wrong with you?" << std::endl;
		std::cout << "This game is not a Donner Party simulator!" << std::endl;
		std::cout << "Maybe you should check the galley for food before you think about cannibalism." << std::endl;
		return;
	}

	if (commands[0] == "eat")
	{
		eat(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if ((commands[0] == "use" && commands[2] == "medical supplies") || (commands[0] == "take" && commands[2] =="medical supplies"))
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "You already used the medical supplies." << std::endl;
			return;
		}

		if (playerLocation->getFeatureOneHap() == 0)
		{
			playerLocation->featureOne(playerPtr);
			return;
		}
	}

	if (commands[0] == "use" && commands[2] == "crew member")
	{
		std::cout << "You are not a master manipulator." << std::endl;
		std::cout << "You don't have the charisma to use people." << std::endl;
		return;
	}



	if (commands[0] == "jump"  && commands[2] == "medical supplies")
	{
		std::cout << "There is no point in jumping on the medical supplies." << std::endl;
		return;
	}


	if (commands[0] == "jump" && commands[2] == "crew member")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "Even if you get the jump on the guy this time, you may not walk away from the encounter." << std::endl;
			std::cout << "You decide not to try it." << std::endl;
			return;
		}

		if (playerLocation->getFeatureTwoHap() == 0)
		{
			std::cout << "You consider jumping and tackling a bedridden patient." << std::endl;
			std::cout << "But you decide that would be too cruel." << std::endl;
			return;
		}
	}

	if (commands[0] == "flee" &&commands[2] == "crew member")
	{

		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "You decide to run away from Jack since he attacked you." << std::endl;
			std::cout << "You run back to the hallway." << std::endl;
			go(playerLocation, roomList, 1, playerPtr);
			return;
		}

		if (playerLocation->getFeatureTwoHap() == 0)
		{
			std::cout << "The crew member is bedridden." << std::endl;
			std::cout << "There is no reason to flee from him right now." << std::endl;
			return;
		}
	}

	if (commands[0] == "break" && commands[2] == "medical supplies")
	{
		std::cout << "There is no reason to wase good medical supplies." << std::endl;
		return;
	}

	if (commands[0] == "break"  && commands[2] == "crew member")
	{
		std::cout << "He's already pretty broken up from the look of him." << std::endl;
		std::cout << "There's no need for overkill." << std::endl;
		return;
	}

	if (commands[0] == "look" && commands[1] == "" && commands[2] == "")
	{
		std::string longDescription = playerLocation->getLongDescrip();
		std::cout << longDescription << std::endl;
		return;
	}

	if (commands[0] == "look" && commands[2] == "crew member")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "Jack looked so weak and non-threatening." << std::endl;
			std::cout << "But looks can be deceiving." << std::endl;
			return;
		}

		else
		{
			playerLocation->featureTwo(playerPtr);
			return;
		}
	}

	if (commands[0] == "look" && commands[2] == "medical supplies")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "The medical supplies have been reduced to some opened boxes of bandages, gauze, and used alcohol swabs which you used to clean your wounds." << std::endl;
			return;
		}

		else
		{
			std::cout << "The medical supplies have not been used yet." << std::endl;
			std::cout << "They can be used to clean and dress your wounds." << std::endl;
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

	if ((commands[0] == "current" && commands[2] == "room") || (commands[0] == "map") || (commands[0] == "show"))
	{
		std::cout << "You are in the Sick Bay." << std::endl;
		mapSickBay();
		return;
	}

	/*calls helper go function with playerLocation pointer, list of rooms and room number to go to.*/

	if ((commands[0] == "go"  && commands[2] == "hallway1") || (commands[2] == "east") || (commands[2] == "hallway 1") || (commands[2] == "hallway" ))
	{
		go(playerLocation, roomList, 1, playerPtr);
		return;
	}

	if (commands[0] == "go" && commands[2] == "crew member")
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "Although he was violent and attacked you in your prior encounter with him, you approach Jack again." << std::endl;
			std::cout << "Your efforts are rewarded this time with tentacles popping out of Jack's hands and wrapping around your neck." << std::endl;
			std::cout << "You lose conciousness before Jack's face morphes in a gaping maw of teeth that bites your head off." << std::endl;
			playerPtr->setAlive(0);
			return;
		}

		if (playerLocation->getFeatureOneHap() == 0)
		{
			playerLocation->featureTwo(playerPtr);
			return;
		}
	}

	if ((commands[0] == "take" && commands[2] == "scalpel"))
	{
		if (playerLocation->getFeatureTwoHap() == 0)
		{
			std::cout << "Before taking the scalpel you decide to approach your crew member to ask if the doctor may need it..." << std::endl;
			playerLocation->featureTwo(playerPtr);
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



