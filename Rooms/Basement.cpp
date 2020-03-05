/* Project Name : Capstone Project
Class : CS 467
Team : Team Thing - Ryan Alcorn, Joel Alfaro, Neil Gayeta
File : Basement.cpp
Description : Class implementation for Basement room.*/

#include "Basement.hpp"

/* Function sets the attributes of this room so they can be called by get functions.*/
void Basement::setRoom()
{
	name = "basement";
	longDes = "You enter the basement. This area is used for storage. It contains materials that are hazardous.\n"
		"It's also one of the most expansive areas of the base. You see something hunched over in the corner of the room.\n"
		"It looks like a person...You also hear a rattling noise down a hallway to the left.\n";
	shortDes = "You return to the basement. This area gives you the creeps.\n";
	exitLong = "There is a hallway which connects to other rooms in the base like the dog kennel from the way you came.\n";
	exitShort = "There is a hallway from the direction you came.\n";
	fOneHappened = 0;
	fTwoHappened = 0;
	roomEntered = 0;
}

/* Function performs the action for the first feature of the room which allows the user to test another crew member to see if they are infected.*/
int Basement::featureOne(Player* user)
{
	int outcome = 0;
	int number = 0;
	int correctQuestion = 0;
	std::string choice = "";
	std::string response = "incorrect";

	std::cout << "You approach the hunched over figure. As you get closer, it begins to get up.\n"
		"It looks human and when it turns around you recognize the individual.\n"
		"He's an older man with glasses and a balding head. It's Dr. Blair!\n\n"
		"'Don't trust the computer son!', he says, 'It's displaying gibberish.'\n\n"
		"'Computer, what are you talking about?', you say.\n\n"
		"'The computer! That we do our research on. It's gone haywire!', he says.\n"
		"'Everything's going to be fine! Thing was freaking the Captain out.'\n"<< std::endl;

	std::cout << "He looks at you waiting for a response. He's staring at you intently.\n"
		"You notice a gun underneath his lab coat.\n\n"
		"'Doc, you're not looking too good. Did you hit your head?'\n'Mind if I ask you a couple questions to jog your memory?', you say.\n"
		"He nods. Still staring at you intently.\n"<< std::endl;

	//Function uses three while loops to ask questions to the crew member.
	std::cout << "What question do you ask?\n\n"
		"1. Do you remember the Captain's name?\n"
		"2. Do you remember your wive's name?" << std::endl;
	getline(std::cin, choice);

	while (response == "incorrect")
	{
		if (choice == "1")
		{
			std::cout << std::endl;
			std::cout << "'The Captain?!?', he says, 'What kind of stupid question is that?'\n"
				"'We mostly just call him 'Captain', but his real name is Bill.'\n\n"
				"The Captain's name is Bill. That does line up. You decide to ask him another question.\n" << std::endl;

			response = "correct";
		}
		else if (choice == "2")
		{
			std::cout << std::endl;
			std::cout << "'My wife...', he says, 'We've been here so long I can hardly remember her face hehe.'\n"
				"'Uhhhhhh...ummmmmmmmmmmmmm.'\n"
				"He seems to have lost his train of thought. 'That's ok, Doc.', you say, 'You must have hit your head on something.'\n\n"
				"Him not remembering his wife is suspicious, but not enough evidence that something's off.\n"
				"You decide to ask him another question.\n" << std::endl;

			//Increments a counter used to determine if the NPC is lying.
			++correctQuestion;
			response = "correct";
		}
		else
		{
			std::cout << "You have picked an incorrect choice. Please chose again: ";
			getline(std::cin, choice);
		}
	}

	response = "incorrect";

	std::cout << "What question do you ask?\n\n"
		"1. What do you do here on the base?\n"
		"2. What's your degree in?" << std::endl;
	getline(std::cin, choice);

	while (response == "incorrect")
	{
		if (choice == "1")
		{
			std::cout << std::endl;
			std::cout << "'What do I do?!?', he says, 'That's easy. I research.'\n"
				"'We're discovering new things about this ecosystem everyday. The plants and animals and everything else.'\n"
				"His response is correct. You decide to ask him another question.\n" << std::endl;

			response = "correct";
		}
		else if (choice == "2")
		{
			std::cout << std::endl;
			std::cout << "'My degree...', he says, 'Well I'm a researcher here so I studied Biology!.'\n\n"
				"You remember him telling you his degree was in Microbiology.\n"
				"His response was off a little bit, but it's not enough to suspect him of anything fishy.\n"
				"You decide to ask him another question.\n" << std::endl;

			//Increments a counter used to determine if the NPC is lying.
			++correctQuestion;
			response = "correct";
		}
		else
		{
			std::cout << "You have picked an incorrect choice. Please chose again: ";
			getline(std::cin, choice);
		}
	}

	response = "incorrect";

	std::cout << "What question do you ask?\n\n"
		"1. How old are you?\n"
		"2. How many people currently work at the base?" << std::endl;
	getline(std::cin, choice);

	while (response == "incorrect")
	{
		if (choice == "1")
		{
			std::cout << std::endl;
			std::cout << "'How old am I?!?', he says, 'Well I'm getting up there is what I'll say.'\n"
				"'These questions are getting awfully nosey. You look like you could use a drink.'\n"
				"'I hear the Captain's opened some booze in the Mess Hall. You should go check it out.'\n"
				"You could always use some more booze, but he didn't answer the question.\n"<< std::endl;

			//Increments a counter used to determine if the NPC is lying.
			++correctQuestion;
			response = "correct";
		}
		else if (choice == "2")
		{
			std::cout << std::endl;
			std::cout << "'That's easy', he says, 'There's seven crew members right now.'\n\n"
				"'I feel like I'm starting to remember things real well,' he says.\n"
				"'These questions are getting awfully nosey. You look like you could use a drink.'\n"
				"'I hear the Captain's opened some booze in the Mess Hall. You should go check it out.'\n"
				"His response was correct.\n" << std::endl;

			response = "correct";
		}
		else
		{
			std::cout << "You have picked an incorrect choice. Please chose again: ";
			getline(std::cin, choice);
		}
	}

	//Different options play out based on how many correct questions the user asked.
	if (correctQuestion > 1)
	{
		std::cout << "You stare at each other for about ten seconds. Some of his answers are not lining up.\n"
			"As you are contemplating this, he begins to reach for the gun.\n"
			"Before he can grab the gun you decide to act. You decide to punch him in the face.\n"
			"He's an older man so you think you can react quicker.\n" << std::endl;

		number = rand() % 100 + 1;

		//Even if the user asked mostly correct questions there's still a chance of a negative outcome.
		if (number > 20)
		{
			std::cout << "You successfully punch him in the face! He goes flying back a couple of feet.\n"
				"He appears disoriented. You decide to disarm him and take his gun.\n"
				"You obtain a gun!\n"<< std::endl;

			//Increases the variable to get one of the endings of the game.
			user->setDeathWish(5);
			std::cout << "You gain a lot of knowledge about what's going on!\n" << std::endl;

			//Player gains the gun if they successfully attack the other crew member.
			removeItem("gun", user);

			//Checks if the user has the rope. If so, they tie up the other crew member.
			if (user->checkInventory("rope"))
			{
				std::cout << "You decide to tie him up with the rope. Don't want him causing harm to any other crew members.\n"
					"You lose the rope!\n"<< std::endl;

				//Discards the rope since the user used it on the other crew member.
				user->deletePlayerItem("rope");

				//Sets the outcome of the interaction to 4. The user's inventory will be checked to see if they have the appropriate items to test the blood.
				user->setDrOutcome(4);

				//Allows the user to tie up the NPC and check the NPC's blood if they have the appropriate items.
				checkBlood(user);
			}
			else
			{
				std::cout << "After a couple of seconds, the doctor appears to be knocked out.\n"
					"You decide to leave him there for now. You should probably find something to tie him up with though!"<< std::endl;

				//Sets the outcome of the interaction to 3. The user can come back and tie up the doctor. 
				user->setDrOutcome(3);
			}
		}
		else
		{
			std::cout << "He's quicker than you expect. He shoots you in the leg!\n"
				"'You should have just went upstairs. Look what you made me do!,' he says.\n"
				"'I'm going to leave you here for some of my friends. Don't worry, they'll be here soon.'\n"
				"He walks back up the stairs. You feel intense pain in your leg. It is bleeding heavily.\n"
				"You lose three grit!\n" << std::endl;

			//Calls the gritHit function which causes the player to take damage.
			user->gritHit(3);

			//Sets the outcome of the interaction to 2. If the user tries to check the doctor's blood they cannot because they failed the feature.
			user->setDrOutcome(2);
		}
	}
	else if(correctQuestion == 1)
	{
		std::cout << "You decide to listen to him.\n"
			"'I'll be up there in a bit.', he says. 'Got something to take care of real quick around here.'\n"
			"It's weird that he doing things in the basement, but he did answer most of the questions correctly.\n"
			"You decide to leave him to his business." << std::endl;

		//Sets the outcome of the interaction to 1. If the user tries to check the doctor's blood they cannot because they failed the feature.
		user->setDrOutcome(1);
	}
	else
	{
		std::cout << "You decide to listen to him.\n"
			"'I'll be up there in a bit', he says. 'Got something to take care of real quick around here.'\n"
			"It's weird that he doing things in the basement, but he did answer all of the questions correctly.\n"
			"You decide to leave him to his business." << std::endl;

		//Sets the outcome of the interaction to 1. If the user tries to check the doctor's blood they cannot because they failed the feature.
		user->setDrOutcome(1);
	}

	++fOneHappened;

	return outcome;
}

/* Function performs the action for the second feature of the room which is to potentially fight a tentacle.*/
int Basement::featureTwo(Player* user)
{
	int outcome = 0;
	int number = 0;

	std::cout << "You decide to investigate the rattling noise.\n"
		"It sounds distant at first, but gets louder as you progress down the hallway.\n\n"
		"The hallway opens up into a room that contains a bunch of dusty boxes. The center of the room is empty.\n"
		"You notice that's where the sound is coming from. As you approach that area, the sound becomes constant.\n\n"
		"As you are about to step into the center of the room all of a sudden a giant tentacle springs up out of the ground!\n"
		"Its shape isn't consistent and it appears to be switching from different body types including dog and human.\n"
		"It begins to move towards you tearing the ground up as it goes.\n"<< std::endl;

	//Checks if the user has the flamethrower to avoid having them possibly take damage. If not, they have a random percent to get hit 3 times.
	if (user->checkInventory("flamethrower"))
	{
		std::cout << "You pull out the flamethrower. 'This thing won't know what's hit them!', you think.\n"
			"You begin to spray flames out at the monster, but it seems to have no effect at first. It keeps moving towards you.\n\n"
			"As your tank begins to reach half, the monster starts to back up a little bit. It lets out a scream.\n"
			"You continue to spray until the tentacle makes its way back into the ground completely.\n"
			"As it is disappearing into the ground, you notice that the flamethrower has run out of fuel.\n"
			"You lose the flamethrower!\n" << std::endl;

		//Deletes the flamethrower from the player's inventory
		user->deletePlayerItem("flamethrower");

		std::cout << "Even though the flamethrower is gone, you feel safe for now.\n"
			"That was only one piece of a larger being. You have to find a way to permanently destroy it!\n" << std::endl;
	}
	//The chance of dodging the strike goes down after each attack.
	else
	{
		std::cout << "A claw appears on its side and takes a swipe at you!" << std::endl;
		std::cout << "You attempt to dodge out of the way of the claw strike.\n" << std::endl;

		number = rand() % 100 + 1;

		if (number > 50)
		{
			std::cout << "You dive out of the way of the stike, but quickly get back up.\n"
				"As you are doing this, you notice a second claw appear on the left side. It takes a swipe at you!"<< std::endl;
		}
		else
		{
			std::cout << "You try to dive out of the way, but unfornately the claw strikes down on you shoulder.\n"
				"You lose two grit!\n" << std::endl;

			//Player loses health and the function gritHit is called.
			user->gritHit(2);

			if (user->getAlive() != 0)
			{
				std::cout << "You notice a second claw appear on the left side.\n"
					"It takes a swipe at you!" << std::endl;
			}
		}

		if (user->getAlive() != 0)
		{
			std::cout << "You attempt to dodge out of the way of the second claw strike.\n" << std::endl;

			number = rand() % 100 + 1;

			if (number > 40)
			{
				std::cout << "You are able to sidestep the second strike.\nAs you are doing this, the first claw takes another swipe!" << std::endl;
			}
			else
			{
				std::cout << "You try to sidestep the strike, but unfornately the claw strikes down into your side.\n"
					"You lose two grit!\n" << std::endl;

				//Player loses health and the function gritHit is called.
				user->gritHit(2);

				if (user->getAlive() != 0)
				{
					std::cout << "The first claw takes another swipe at you!" << std::endl;
				}
			}
		}

		if (user->getAlive() != 0)
		{
			std::cout << "You attempt to dodge out of the way.\n" << std::endl;

			number = rand() % 100 + 1;

			if (number > 30)
			{
				std::cout << "You suddenly get an urge to flip backwards. You somehow successfully perform a backflip.\n" << std::endl;
			}
			else
			{
				std::cout << "You try to do a backflip, but unfornately the claw slashes your leg.\n"
					"You lose two grit!" << std::endl;

				//Player loses health and the function gritHit is called.
				user->gritHit(2);
			}
		}

		if (user->getAlive() != 0)
		{
			std::cout << "You notice that you're at the edge of the room. You take a couple steps back down into the hallway.\n"
				"The tentacle attempts to follow you but is too large. It screams at you.\n"
				"You feel safe for now.\n"
				"That was only one piece of a larger being. You have to find a way to permanently destroy it!\n" << std::endl;
		}
	}

	if (user->getAlive() != 0)
	{
		//Increases the variable to get one of the endings of the game.
		user->setDeathWish(5);
		std::cout << "You gain a lot of knowledge about what's going on!" << std::endl;
	}

	++fTwoHappened;

	return outcome;
}
