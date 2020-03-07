#include "roomInteractionBasement.hpp"

void roomInteractionBasement(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList, Parser* parserPtr)
{
	if (commands[0] == "savegame" || commands[0] == "loadgame")
	{
		return;
	}
	/*phrase for looking at room inventory*/
	if (commands[0] == "look" && commands[1] == "for" && commands[2] == "booze")
	{
		std::cout << "You start looking for booze and notice..." << std::endl;
		playerLocation->itemsInRoom();
		return;
	}

	if ((commands[0] == "talk" && commands[2] == "figure" && playerPtr->getDrOutcome() == 0) || (commands[0] == "talk" && commands[2] == "hunched" && playerPtr->getDrOutcome() == 0)
		|| (commands[0] == "talk" && commands[2] == "thing" && playerPtr->getDrOutcome() == 0) || (commands[0] == "talk" && commands[2] == "shape"&& playerPtr->getDrOutcome() == 0)
		|| (commands[0] == "talk" && commands[2] == "doctor"&& playerPtr->getDrOutcome() == 0) || (commands[0] == "talk" && commands[2] == "person"&& playerPtr->getDrOutcome() == 0)
		|| (commands[0] == "talk" && commands[2] == "blair"&& playerPtr->getDrOutcome() == 0))
	{
		playerLocation->featureOne(playerPtr);
		return;
	}

	if ((commands[0] == "talk" && commands[2] == "figure" && playerPtr->getDrOutcome() == 1) || (commands[0] == "talk" && commands[2] == "hunched" && playerPtr->getDrOutcome() == 1)
		|| (commands[0] == "talk" && commands[2] == "thing" && playerPtr->getDrOutcome() == 1) || (commands[0] == "talk" && commands[2] == "shape"&& playerPtr->getDrOutcome() == 1)
		|| (commands[0] == "talk" && commands[2] == "doctor"&& playerPtr->getDrOutcome() == 1) || (commands[0] == "talk" && commands[2] == "person"&& playerPtr->getDrOutcome() == 1)
		|| (commands[0] == "talk" && commands[2] == "blair"&& playerPtr->getDrOutcome() == 1))
	{
		std::cout << "After your talk with the doctor, you feel assured that he is at least mostly ok." << std::endl;
		std::cout << "You decide to leave him to his business." << std::endl;
		return;
	}

	if ((commands[0] == "talk" && commands[2] == "figure" && playerPtr->getDrOutcome() == 2) || (commands[0] == "talk" && commands[2] == "hunched" && playerPtr->getDrOutcome() == 2)
		|| (commands[0] == "talk" && commands[2] == "thing" && playerPtr->getDrOutcome() == 2) || (commands[0] == "talk" && commands[2] == "shape"&& playerPtr->getDrOutcome() == 2)
		|| (commands[0] == "talk" && commands[2] == "doctor"&& playerPtr->getDrOutcome() == 2) || (commands[0] == "talk" && commands[2] == "person"&& playerPtr->getDrOutcome() == 2)
		|| (commands[0] == "talk" && commands[2] == "blair"&& playerPtr->getDrOutcome() == 2))
	{
		std::cout << "The doctor shot you and ran off." << std::endl;
		std::cout << "What are you going to talk to him about? " << std::endl;
		std::cout << "'Why did you shoot me, Doc?'" << std::endl;
		return;
	}

	if ((commands[0] == "talk" && commands[2] == "figure" && playerPtr->getDrOutcome() > 2 && playerPtr->getDrOutcome() < 6) ||
		(commands[0] == "talk" && commands[2] == "hunched" && playerPtr->getDrOutcome() > 2 && playerPtr->getDrOutcome() < 6)
		|| (commands[0] == "talk" && commands[2] == "thing" && playerPtr->getDrOutcome() > 2 && playerPtr->getDrOutcome() < 6) ||
		(commands[0] == "talk" && commands[2] == "shape"&& playerPtr->getDrOutcome() > 2 && playerPtr->getDrOutcome() < 6)
		|| (commands[0] == "talk" && commands[2] == "doctor"&& playerPtr->getDrOutcome() > 2 && playerPtr->getDrOutcome() < 6) ||
		(commands[0] == "talk" && commands[2] == "person"&& playerPtr->getDrOutcome() > 2 && playerPtr->getDrOutcome() < 6)
		|| (commands[0] == "talk" && commands[2] == "blair"&& playerPtr->getDrOutcome() > 2 && playerPtr->getDrOutcome() < 6)
		)
	{
		std::cout << "The docotr is unresponsive." << std::endl;
		return;
	}

	if ((commands[0] == "talk" && commands[2] == "figure" && playerPtr->getDrOutcome() == 6) || (commands[0] == "talk" && commands[2] == "hunched" && playerPtr->getDrOutcome() == 6)
		|| (commands[0] == "talk" && commands[2] == "thing" && playerPtr->getDrOutcome() == 6) || (commands[0] == "talk" && commands[2] == "shape"&& playerPtr->getDrOutcome() == 6)
		|| (commands[0] == "talk" && commands[2] == "doctor"&& playerPtr->getDrOutcome() == 6) || (commands[0] == "talk" && commands[2] == "person"&& playerPtr->getDrOutcome() == 6)
		|| (commands[0] == "talk" && commands[2] == "blair"&& playerPtr->getDrOutcome() == 6))
	{
		std::cout << "That is a hoot and holler!" << std::endl;
		std::cout << "Whatever it was, you can't talk to it now because it is a smoldering heap of burning remains." << std::endl;
		return;
	}
	
	if (commands[0] == "drink")
	{
		drink(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if ((commands[0] == "smell" && commands[2] == "figure" && playerPtr->getDrOutcome() == 6) || (commands[0] == "smell" && commands[2] == "hunched" && playerPtr->getDrOutcome() == 6)
		|| (commands[0] == "smell" && commands[2] == "thing" && playerPtr->getDrOutcome() == 6) || (commands[0] == "smell" && commands[2] == "shape"&& playerPtr->getDrOutcome() == 6)
		|| (commands[0] == "smell" && commands[2] == "doctor"&& playerPtr->getDrOutcome() == 6) || (commands[0] == "smell" && commands[2] == "person"&& playerPtr->getDrOutcome() == 6)
		|| (commands[0] == "smell" && commands[2] == "blair"&& playerPtr->getDrOutcome() == 6))
	{
		std::cout << "The room is filled with a not unpleasent smell of cooked meat." << std::endl;
		std::cout << "Whatver was posing as the doctor, its species does smell appetizing when it is cooking." << std::endl;
		std::cout << "You wonder if this species could be harvested as an alternative to conventional sources of animal protein." << std::endl;
		return;
	}

	if ((commands[0] == "smell" && commands[2] == "figure" && playerPtr->getDrOutcome() == 2) || (commands[0] == "smell" && commands[2] == "hunched" && playerPtr->getDrOutcome() == 2)
		|| (commands[0] == "smell" && commands[2] == "thing" && playerPtr->getDrOutcome() == 2) || (commands[0] == "smell" && commands[2] == "shape"&& playerPtr->getDrOutcome() == 2)
		|| (commands[0] == "smell" && commands[2] == "doctor"&& playerPtr->getDrOutcome() == 2) || (commands[0] == "smell" && commands[2] == "person"&& playerPtr->getDrOutcome() == 2)
		|| (commands[0] == "smell" && commands[2] == "blair"&& playerPtr->getDrOutcome() == 2))
	{
		std::cout << "You didn't notice any bizarre smells about the guy before he shot you." << std::endl;
		std::cout << "He didn't smell drunk." << std::endl;
		return;
	}

	if ((commands[0] == "smell" && commands[2] == "figure" && playerPtr->getDrOutcome() == 0) || (commands[0] == "smell" && commands[2] == "hunched" && playerPtr->getDrOutcome() == 0)
		|| (commands[0] == "smell" && commands[2] == "thing" && playerPtr->getDrOutcome() == 0) || (commands[0] == "smell" && commands[2] == "shape"&& playerPtr->getDrOutcome() == 0)
		|| (commands[0] == "smell" && commands[2] == "doctor"&& playerPtr->getDrOutcome() == 0) || (commands[0] == "smell" && commands[2] == "person"&& playerPtr->getDrOutcome() == 0)
		|| (commands[0] == "smell" && commands[2] == "blair"&& playerPtr->getDrOutcome() == 0))
	{
		std::cout << "You start sniffing the air to check if the doctor smells different than usual." << std::endl;
		std::cout << "You notice nothing out of the ordinary about him." << std::endl;
		std::cout << "He is oblvious to your strange behavior." << std::endl;
		return;
	}

	if ((commands[0] == "smell" && commands[2] == "figure") || (commands[0] == "smell" && commands[2] == "hunched")
		|| (commands[0] == "smell" && commands[2] == "thing") || (commands[0] == "smell" && commands[2] == "shape")
		|| (commands[0] == "smell" && commands[2] == "doctor") || (commands[0] == "smell" && commands[2] == "person")
		|| (commands[0] == "smell" && commands[2] == "blair"))
	{
		std::cout << "The doctor doesn't smell like he has been drinking." << std::endl;
		std::cout << "The only alcohol you smell is the stuff on your own clothes and coming out of your own pores." << std::endl;
		return;
	}

	if (commands[0] == "drop")
	{
		drop(commands, playerLocation, playerPtr, roomList, 2);
		return;
	}

	if ((commands[0] == "attack" && commands[2] == "figure") || (commands[0] == "attack" && commands[2] == "hunched")
		|| (commands[0] == "attack" && commands[2] == "thing") || (commands[0] == "attack" && commands[2] == "shape")
		|| (commands[0] == "attack" && commands[2] == "doctor") || (commands[0] == "attack" && commands[2] == "person")
		|| (commands[0] == "attack" && commands[2] == "blair"))
	{
		std::cout << "You walk up ready with a sucker punch." << std::endl;
		std::cout << "Whatever it is, it looks like Dr. Blair, but the familiar face melts away into a maw of teeth." << std::endl;
		std::cout << "The teeth enclose around your face and you see only darkness." << std::endl;
		playerPtr->setAlive(0);
	}


	if ((commands[0] == "eat" && commands[2] == "figure" && playerPtr->getDrOutcome() == 6) || (commands[0] == "eat" && commands[2] == "hunched" && playerPtr->getDrOutcome() == 6)
		|| (commands[0] == "eat" && commands[2] == "thing" && playerPtr->getDrOutcome() == 6) || (commands[0] == "eat" && commands[2] == "shape"&& playerPtr->getDrOutcome() == 6)
		|| (commands[0] == "eat" && commands[2] == "doctor"&& playerPtr->getDrOutcome() == 6) || (commands[0] == "eat" && commands[2] == "person"&& playerPtr->getDrOutcome() == 6))
	{
		std::cout << "Smelling the burnt heap of remains, and noting no one else is around, you grab hunk of burning meat and have a few bites." << std::endl;
		std::cout << "It isn't bad." << std::endl;
		std::cout << "It could use some salt and pepper." << std::endl;
		std::cout << "And since this wasn't human, technically you are not a cannibal." << std::endl;
		std::cout << "You have the higher moral ground here." << std::endl;
		return;
	}

	if ((commands[0] == "eat" && commands[2] == "figure") || (commands[0] == "eat" && commands[2] == "hunched" && playerPtr)
		|| (commands[0] == "eat" && commands[2] == "thing") || (commands[0] == "eat" && commands[2] == "shape")
		|| (commands[0] == "eat" && commands[2] == "doctor") || (commands[0] == "eat" && commands[2] == "person")
		|| (commands[0] == "eat" && commands[2] == "blair"))
	{
		std::cout << "There is a time and place to eat." << std::endl;
		std::cout << "This isn't the right time for that right now." << std::endl;
		return;
	}

	if ((commands[0] == "jump" && commands[2] == "figure") || (commands[0] == "jump" && commands[2] == "hunched")
		|| (commands[0] == "jump" && commands[2] == "thing") || (commands[0] == "jump" && commands[2] == "shape")
		|| (commands[0] == "jump" && commands[2] == "doctor") || (commands[0] == "jump" && commands[2] == "person")
		|| (commands[0] == "jump" && commands[2] == "blair"))
	{
		std::cout << "You plan to get the jump on 'em." << std::endl;
		std::cout << "In your hungover state, you are too slow!" << std::endl;
		std::cout << "Whatever it is that you were going to jump, it looks like Dr. Blair, but the familiar face melts away into a maw of teeth." << std::endl;
		std::cout << "The teeth enclose around your face and you see only darkness." << std::endl;
		playerPtr->setAlive(0);
	}

	if ((commands[0] == "flee" && commands[2] == "figure"  && playerPtr->getDrOutcome() == 0) || (commands[0] == "flee" && commands[2] == "hunched" && playerPtr->getDrOutcome() == 0)
		|| (commands[0] == "flee" && commands[2] == "thing" &&playerPtr->getDrOutcome() == 0) || (commands[0] == "flee" && commands[2] == "shape" && playerPtr->getDrOutcome() == 0)
		|| (commands[0] == "flee" && commands[2] == "doctor" && playerPtr->getDrOutcome() == 0) || (commands[0] == "flee" && commands[2] == "person" && playerPtr->getDrOutcome() == 0)
		|| (commands[0] == "flee" && commands[2] == "blair" && playerPtr->getDrOutcome() == 0))
	{
		if (playerLocation->getFeatureTwoHap() == 0)
		{
			std::cout << "You decide to flee and face whatever that rattling noise is instead." << std::endl;
			return;
		}

		else
		{
			std::cout << "You decide to bolt and run." << std::endl;
			std::cout << "Courage isn't your strong suit." << std::endl;
			go(playerLocation, roomList, 9, playerPtr);
			return;
		}

	}

	if ((commands[0] == "flee" && commands[2] == "figure") || (commands[0] == "flee" && commands[2] == "hunched")
		|| (commands[0] == "flee" && commands[2] == "thing") || (commands[0] == "flee" && commands[2] == "shape")
		|| (commands[0] == "flee" && commands[2] == "doctor") || (commands[0] == "flee" && commands[2] == "person")
		|| (commands[0] == "flee" && commands[2] == "blair"))
	{
		if (playerLocation->getFeatureTwoHap() == 0)
		{
			std::cout << "You decide to flee and face whatever that rattling noise is instead." << std::endl;
			return;
		}

		else
		{
			std::cout << "You decide to bolt and run." << std::endl;
			std::cout << "Courage isn't your strong suit." << std::endl;
			go(playerLocation, roomList, 9, playerPtr);
			return;
		}

	}

	if ((commands[0] == "break" && commands[2] == "figure") || (commands[0] == "break" && commands[2] == "hunched")
		|| (commands[0] == "break" && commands[2] == "thing") || (commands[0] == "break" && commands[2] == "shape")
		|| (commands[0] == "break" && commands[2] == "doctor") || (commands[0] == "break" && commands[2] == "person")
		|| (commands[0] == "break" && commands[2] == "blair"))
	{
		std::cout << "You walk up ready with a sucker punch." << std::endl;
		std::cout << "Whatever it is, it looks like Dr. Blair, but the familiar face melts away into a maw of teeth." << std::endl;
		std::cout << "The teeth enclose around your face and you see only darkness." << std::endl;
		playerPtr->setAlive(0);
	}

	if (commands[0] == "look" && commands[1] == "" && commands[2] == "")
	{
		std::string longDescription = playerLocation->getLongDescrip();
		std::cout << longDescription << std::endl;
		return;
	}

	if (commands[0] == "look" && commands[1] == "at")
	{
		lookAt(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	if ((commands[0] == "look" && commands[2] == "figure" && playerPtr->getDrOutcome() == 0) || (commands[0] == "look" && commands[2] == "hunched" && playerPtr->getDrOutcome() == 0)
		|| (commands[0] == "look" && commands[2] == "thing" && playerPtr->getDrOutcome() == 0) || (commands[0] == "look" && commands[2] == "shape"&& playerPtr->getDrOutcome() == 0)
		|| (commands[0] == "look" && commands[2] == "doctor"&& playerPtr->getDrOutcome() == 0) || (commands[0] == "look" && commands[2] == "person"&& playerPtr->getDrOutcome() == 0)
		|| (commands[0] == "look" && commands[2] == "blair"&& playerPtr->getDrOutcome() == 0))
	{
		playerLocation->featureOne(playerPtr);
		return;
	}

	if ((commands[0] == "look" && commands[2] == "figure" && playerPtr->getDrOutcome() == 1) || (commands[0] == "look" && commands[2] == "hunched" && playerPtr->getDrOutcome() == 1)
		|| (commands[0] == "look" && commands[2] == "thing" && playerPtr->getDrOutcome() == 1) || (commands[0] == "look" && commands[2] == "shape"&& playerPtr->getDrOutcome() == 1)
		|| (commands[0] == "look" && commands[2] == "doctor"&& playerPtr->getDrOutcome() == 1) || (commands[0] == "look" && commands[2] == "person" && playerPtr->getDrOutcome() == 1)
		|| (commands[0] == "look" && commands[2] == "blair" && playerPtr->getDrOutcome() == 1))
	{
		std::cout << "Dr. Blair seems a little distracted." << std::endl;
		std::cout << "So Dr. Blair is acting a little weird." << std::endl;
		std::cout << "He mostly answered all your stupid questions correctly." << std::endl;
		return;
	}

	if ((commands[0] == "look" && commands[2] == "figure" && playerPtr->getDrOutcome() == 2) || (commands[0] == "look" && commands[2] == "hunched" && playerPtr->getDrOutcome() == 2)
		|| (commands[0] == "look" && commands[2] == "thing" && playerPtr->getDrOutcome() == 2) || (commands[0] == "look" && commands[2] == "shape"&& playerPtr->getDrOutcome() == 2)
		|| (commands[0] == "look" && commands[2] == "doctor"&& playerPtr->getDrOutcome() == 2) || (commands[0] == "look" && commands[2] == "person"&& playerPtr->getDrOutcome() == 2)
		|| (commands[0] == "look" && commands[2] == "blair"&& playerPtr->getDrOutcome() == 2))
	{
		std::cout << "You can't get a second look at Dr. Blair." << std::endl;
		std::cout << "He shot you and ran off." << std::endl;
		return;
	}

	if ((commands[0] == "look" && commands[2] == "figure" && playerPtr->getDrOutcome() == 6) || (commands[0] == "look" && commands[2] == "hunched" && playerPtr->getDrOutcome() == 6)
		|| (commands[0] == "look" && commands[2] == "thing" && playerPtr->getDrOutcome() == 6) || (commands[0] == "look" && commands[2] == "shape"&& playerPtr->getDrOutcome() == 6)
		|| (commands[0] == "look" && commands[2] == "doctor"&& playerPtr->getDrOutcome() == 6) || (commands[0] == "look" && commands[2] == "doctor"&& playerPtr->getDrOutcome() == 6)
		|| (commands[0] == "look" && commands[2] == "blair"&& playerPtr->getDrOutcome() == 6))
	{
		std::cout << "The sight of burning remains takes you back to family cook outs and barbecues from your childhood." << std::endl;
		return;
	}

	if ((commands[0] == "look" && commands[2] == "figure") || (commands[0] == "look" && commands[2] == "hunched")
		|| (commands[0] == "look" && commands[2] == "thing") || (commands[0] == "look" && commands[2] == "shape")
		|| (commands[0] == "look" && commands[2] == "doctor") || (commands[0] == "look" && commands[2] == "person")
		|| (commands[0] == "look" && commands[2] == "blair"))
	{
		std::cout << "He looks like Dr. Blair, but you are convinced it isn't really him." << std::endl;
		return;
	}

	if ((commands[0] == "use" && commands[2] == "blood test") || (commands[0] == "look" && commands[1] == "at" && commands[2] == "blood"))
	{
		playerLocation->checkBlood(playerPtr);
	}

	if ((commands[0] == "go" && commands[2] == "hallway2") ||(commands[2] == "hallway") || (commands[2] == "north") || (commands[2] == "hallway2") || (commands[2] == "hallway1"))
	{
		std::cout << "Whatever was making that noise isn't here right now..." << std::endl;
		go(playerLocation, roomList, 9, playerPtr);
		return;
	}

	if ((commands[0] == "talk" && commands[2] == "rattling") || (commands[0] == "talk" && commands[2] == "rattling nosie") || (commands[0] == "talk" && commands[2] == "thing")
		|| (commands[0] == "talk" && commands[2] == "creature") || (commands[0] == "talk" && commands[2] == "dog"))

	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "That thing attacked you, and now you want to have a conversation with it?" << std::endl;
			std::cout << "Bad idea." << std::endl;
			std::cout << "You stupidly go back to Hallway 2 to converse with the creature." << std::endl;
			std::cout << "Thankfully it isn't there, and you go back to the Basement." << std::endl;
			return;
		}

		else
		{
			std::cout << "You call out in the direction of the rattling noise." << std::endl;
			std::cout << "Maybe whoever made that noise can't hear you." << std::endl;
			std::cout << "So you climb the steps out of the basement." << std::endl;
			playerLocation->featureTwo(playerPtr);
			return;
		}
	}


	if ((commands[0] == "smell" && commands[2] == "rattling") || (commands[0] == "smell" && commands[2] == "rattling nosie") || (commands[0] == "smell" && commands[2] == "thing")
		|| (commands[0] == "smell" && commands[2] == "creature") || (commands[0] == "smell" && commands[2] == "dog"))
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "You decide it would be foolish to go back and try to smell the creature that attacked you." << std::endl;
			return;
		}

		else
		{
			std::cout << "You must think you are part bloodhound." << std::endl;
			std::cout << "You smell the air in the direction of the rattling noise." << std::endl;
			std::cout << "Your sense of smell is not that strong." << std::endl;
			std::cout << "You can't smell it." << std::endl;
			return;
		}
	}

	if ((commands[0] == "attack" && commands[2] == "rattling") || (commands[0] == "attack" && commands[2] == "rattling nosie") || (commands[0] == "attack" && commands[2] == "thing")
		|| (commands[0] == "attack" && commands[2] == "creature") || (commands[0] == "attack" && commands[2] == "dog"))
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "That thing attacked you, and now you want to go for round two with it?" << std::endl;
			std::cout << "Bad idea." << std::endl;
			std::cout << "You stupidly go back to Hallway 2 to attack the creature." << std::endl;
			std::cout << "The creature pounces on you and rips your head off this time." << std::endl;
			playerPtr->setAlive(0);
			return;
		}

		else
		{
			std::cout << "You are not sure what is making that noise." << std::endl;
			std::cout << "But you are convinced you are ready to tangle with it if necessary." << std::endl;
			playerLocation->featureTwo(playerPtr);
			return;
		}
	}

	if ((commands[0] == "eat" && commands[2] == "rattling") || (commands[0] == "eat" && commands[2] == "rattling nosie") || (commands[0] == "eat" && commands[2] == "thing")
		|| (commands[0] == "eat" && commands[2] == "creature") || (commands[0] == "eat" && commands[2] == "dog"))
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "That thing attacked you, and now you want to go for round two with it?" << std::endl;
			std::cout << "Bad idea." << std::endl;
			std::cout << "You stupidly go back to Hallway 2 to hunt the creature for food." << std::endl;
			std::cout << "The creature pounces on you and rips your head off this time." << std::endl;
			playerPtr->setAlive(0);
			return;
		}

		else
		{
			std::cout << "You decide you don't want to eat what was making the rattling sound." << std::endl;
			std::cout << "At least not at this time." << std::endl;
			return;
		}
	}

	if ((commands[0] == "use" && commands[2] == "rattling") || (commands[0] == "use" && commands[2] == "rattling nosie") || (commands[0] == "use" && commands[2] == "thing")
		|| (commands[0] == "use" && commands[2] == "creature") || (commands[0] == "use" && commands[2] == "dog"))
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "That thing attacked you, and now you want to go for round two with it?" << std::endl;
			std::cout << "You stupidly go back to Hallway 2 to attempt capturing the creature." << std::endl;
			std::cout << "'If I can capture the creature and train it, it may be useful,' you think." << std::endl;
			std::cout << "The creature pounces on you and rips your head off this time." << std::endl;
			playerPtr->setAlive(0);
			return;
		}

		else
		{
			std::cout << "There is no way to tell if the source of the rattling noise will be useful to you." << std::endl;
			return;
		}
	}

	if ((commands[0] == "jump" && commands[2] == "rattling") || (commands[0] == "jump" && commands[2] == "rattling nosie") || (commands[0] == "jump" && commands[2] == "thing")
		|| (commands[0] == "jump" && commands[2] == "creature") || (commands[0] == "jump" && commands[2] == "dog"))
	{

		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "That thing attacked you, and now you want to go for round two with it?" << std::endl;
			std::cout << "You stupidly go back to Hallway 2 to attempt to get the jump on the creature." << std::endl;
			std::cout << "'You want payback!" << std::endl;
			std::cout << "The creature pounces on you and rips your head off this time." << std::endl;
			playerPtr->setAlive(0);
			return;
		}

		else
		{
			std::cout << "You decide to approach whatever is making the noise cautiously." << std::endl;
			std::cout << "You want to get the jump on it." << std::endl;
			playerLocation->featureTwo(playerPtr);
			return;
		}
	}

	if ((commands[0] == "flee" && commands[2] == "rattling") || (commands[0] == "flee" && commands[2] == "rattling nosie") || (commands[0] == "flee" && commands[2] == "thing")
		|| (commands[0] == "flee" && commands[2] == "creature") || (commands[0] == "flee" && commands[2] == "dog"))
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "You being here and not in Hallway 2 is kind of like having fleed from whatever that was, isn't it?" << std::endl;
			return;
		}

		else
		{
			std::cout << "Whatever is making that noise is in Hallway 2." << std::endl;
			std::cout << "You are in the Basement." << std::endl;
			std::cout << "There really isn't a need to flee." << std::endl;
			return;
		}

	}

	if ((commands[0] == "break" && commands[2] == "rattling") || (commands[0] == "break" && commands[2] == "rattling nosie") || (commands[0] == "break" && commands[2] == "thing")
		|| (commands[0] == "break" && commands[2] == "creature") || (commands[0] == "break" && commands[2] == "dog"))
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "That thing attacked you, and now you want to go for round two with it?" << std::endl;
			std::cout << "Bad idea." << std::endl;
			std::cout << "You stupidly go back to Hallway 2 to attack the creature." << std::endl;
			std::cout << "The creature pounces on you and rips your head off this time." << std::endl;
			playerPtr->setAlive(0);
			return;
		}

		else
		{
			std::cout << "You are not sure what is making that noise." << std::endl;
			std::cout << "But you are convinced you are ready to tangle with it if necessary." << std::endl;
			playerLocation->featureTwo(playerPtr);
			return;
		}
	}

	if ((commands[0] == "look at" && commands[2] == "rattling") || (commands[0] == "look at" && commands[2] == "rattling nosie") || (commands[0] == "look at" && commands[2] == "thing")
		|| (commands[0] == "look at" && commands[2] == "creature") || (commands[0] == "look at" && commands[2] == "dog"))

	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "You never want to look at that thing again." << std::endl;
			std::cout << "You decide to not go looking for it." << std::endl;
			return;
		}

		else
		{
			std::cout << "You are not sure what is making that noise." << std::endl;
			std::cout << "You plan on getting a look at it." << std::endl;
			playerLocation->featureTwo(playerPtr);
			return;
		}
	}

	if ((commands[0] == "go" && commands[2] == "rattling") || (commands[0] == "go" && commands[2] == "rattling nosie") || (commands[0] == "go" && commands[2] == "thing")
		|| (commands[0] == "go" && commands[2] == "creature") || (commands[0] == "go" && commands[2] == "dog"))
	{
		if (playerLocation->getFeatureTwoHap() == 1)
		{
			std::cout << "That thing attacked you, and now you want to go for round two with it?" << std::endl;
			std::cout << "Bad idea." << std::endl;
			std::cout << "You stupidly go back to Hallway 2 to attack the creature." << std::endl;
			std::cout << "The creature pounces on you and rips your head off this time." << std::endl;
			playerPtr->setAlive(0);
			return;
		}

		else
		{
			std::cout << "You are not sure what is making that noise." << std::endl;
			std::cout << "You choose to go to whatever is making that sound." << std::endl;
			playerLocation->featureTwo(playerPtr);
			return;
		}
	}

	if (commands[0] == "room")
	{
		/*Asks pointer to get name*/
		std::cout << "CURRENT ROOM: " << playerLocation->getName() << std::endl;
		return;
	}

	if ((commands[0] == "current" && commands[2] == "room") || (commands[0] == "map"))
	{
		std::cout << "You are in the Basement. " << std::endl;
		mapBasement();
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

	if (commands[0] == "eat")
	{
		eat(commands, playerLocation, playerPtr, roomList, 0);
		return;
	}

	std::cout << "You can't do that here." << std::endl;
	return;
}


