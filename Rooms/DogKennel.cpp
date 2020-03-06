/* Project Name : Capstone Project
Class : CS 467
Team : Team Thing - Ryan Alcorn, Joel Alfaro, Neil Gayeta
File : DogKennel.cpp
Description : Class implementation for DogKennel room.*/

#include "DogKennel.hpp"

/* Function sets the attributes of this room so they can be called by get functions.*/
void DogKennel::setRoom()
{
	name = "dogKennel";
	longDes = "You enter the dog kennel. The base had 7 dogs that were housed in this room.\n"
		"There isn't seven dogs here now. You hear panting from the corner of the room. You can investigate that.\n"
		"You also notice something shimmering on a shelf in another corner of the room.\n";
	shortDes = "You return to the dog kennel. Where'd all the dogs go?\n";
	exitLong = "There is a hallway which connects to other rooms in the base like the conference room from the way you came(northeast).\n";
	exitShort = "There is a hallway from the direction you came(northeast).\n";
	fOneHappened = 0;
	fTwoHappened = 0;
	roomEntered = 0;
}

/* Function performs the action for the first feature of the room.*/
int DogKennel::featureOne(Player* user)
{
	int outcome = 0;
	std::string choice = "";
	std::string response = "incorrect";

	std::cout << "You decide to investigate the noise you heard. You never know, it could be an injured crew member.\n"
		"The noise is coming from the corner of the room. You begin to head over to it.\n"
		"The noise begins to change from a panting sound to a growl. Low at first.\n\n"
		"The growl begins to get louder the closer you get.\n"
		"All of the sudden something jumps out at you!\n"
		"What do you do?\n\n"
		"1. Attack it with your fists\n"
		"2. Attack it with a weapon\n"
		"3. Attempt to flee"<< std::endl;
	getline(std::cin, choice);

	while (response == "incorrect")
	{
		if (choice == "1")
		{
			std::cout << std::endl;
			std::cout << "You attack it with your fists. You have no formal training in any discipline.\n"
				"You're surprised that you connect with a hit. The thing appears to be a dog, but malformed.\n"
				"It scurries off after the hit.\n"
				"You do notice that the creature scratched you pretty good on the arm. Blood is gushing from a cut.\n"
				"You lose two grit!\n"<< std::endl;

			//Calls the gritHit function to cause the player to lose health.
			user->gritHit(2);

			if (user->getAlive() != 0)
			{
				//Increases the variable to get one of the endings of the game.
				user->setDeathWish(2);
				std::cout << "You gain some knowledge about what's going on!" << std::endl;
			}

			response = "correct";
		}
		else if (choice == "2")
		{
			std::cout << std::endl;
			//Add function to check if user has specific items to protect themselves
			if (user->checkInventory("gun") || user->checkInventory("flamethrower") || user->checkInventory("axe"))
			{
				//Calls the weapon attack function
				weaponAttack(user);

				if (user->getAlive() != 0)
				{
					//Increases the variable to get one of the endings of the game.
					user->setDeathWish(4);
					std::cout << "You gain a decent amount of knowledge about what's going on!" << std::endl;
				}

				response = "correct";
			}
			else
			{
				std::cout << "You do not have a weapon to fend off the creature! You decide to attack it with your fists." << std::endl;
				choice = "1";
			}
		}
		
		if (choice == "3")
		{
			std::cout << std::endl;
			std::cout << "You attempt to flee. You do not like the sounds this thing is making!\n"
				"Unfornately you are too slow. The creature barrels into your legs knocking you over.\n"
				"You hit your head on the wall nearby!\n"
				"The creature stands over you and the last thing you see is the creature's teeth going for your neck..." << std::endl;

			//Calls the gritHit function which causes the player to die since they picked a bad choice.
			user->gritHit(user->getGrit());

			response = "correct";
		}
		
		if(choice != "1" && choice != "2" && choice != "3")
		{
			std::cout << "You have picked an incorrect choice. Please chose again: ";
			getline(std::cin, choice);
		}
	}

	++fOneHappened;

	return outcome;
}

/* Function performs the action for the second feature of the room.*/
int DogKennel::featureTwo(Player* user)
{
	int outcome = 0;
	int number = 0;
	std::string choice = "";
	std::string response = "incorrect";

	std::cout << "You head towards the corner where you see a shimmering object.\n"
		"It's on a shelf that is too tall for you to grab just standing up. You could jump for it.\n"
		"What do you do?\n\n"
		"1. Jump for the object\n"
		"2. Ignore the object" << std::endl;
	getline(std::cin, choice);

	while (response == "incorrect")
	{
		if (choice == "1")
		{
			std::cout << std::endl;
			std::cout << "You attempt to jump for the object.\n" << std::endl;

			number = rand() % 100 + 1;

			if (number > 30)
			{
				std::cout << "You jump and grab the object while landing perfectly.\n"
					"You are surprised by how spry you are considering how hungover you are." << std::endl;
			}
			else
			{
				std::cout << "You jump and grab the object, but fall awkwardly.\n"
					"You land heavily on your knee. The pain is intense!\n"
					"You lose one grit!" << std::endl;

				//Calls the gritHit function to cause the player to lose health.
				user->gritHit(1);
			}

			if (user->getAlive() != 0)
			{
				std::cout << "You obtain a petri dish!" << std::endl;
			}

			//Removes the petri dish from the room using the removeItem function
			removeItem("petri dish", user);

			response = "correct";
		}
		else if (choice == "2")
		{
			std::cout << std::endl;
			std::cout << "You decide to ignore the object. Doesn't look like booze anyways!" << std::endl;

			response = "correct";
		}
		else
		{
			std::cout << "You have picked an incorrect choice. Please chose again: ";
			getline(std::cin, choice);
		}
	}

	++fTwoHappened;

	return outcome;
}

//Function allows the user to attack creatures with a random weapon from their inventory.
void DogKennel::weaponAttack(Player* user)
{
	int numOfWeapons = 0;
	int number = 0;
	int randomNumber = 0;
	int finalIndex = 0;
	Item* checkItem;
	std::vector<int> weaponIndex;

	//For loop finds the indexes of the weapons in the user's inventory and adds them to an int vector.
	for (unsigned int i = 0; i < user->inventoryNumber(); ++i)
	{
		checkItem = user->returnItem(i);
		if (checkItem->getName() == "gun" || checkItem->getName() == "flamethrower" || checkItem->getName() == "axe")
		{
			weaponIndex.push_back(i);
			++numOfWeapons;
		}
	}

	//A random number is chosen based off of the number of weapons that the user has.
	number = rand() % numOfWeapons;
	finalIndex = weaponIndex[number];

	//The weapon who's index was chosen is set as checkItem
	checkItem = user->returnItem(finalIndex);

	/*Based off of which weapon was selected different dialogue is displayed. There is a chance the player will take damage and lose the weapon
	* for each weapon besides the flamethrower. */
	if (checkItem->getName() == "gun")
	{
		std::cout << "You pull out the gun and attempt to take a shot at the thing.\n" << std::endl;

		randomNumber = rand() % 100 + 1;

		if (randomNumber < 80)
		{
			std::cout << "The shot hits what appears to be a dog-like creature in the neck.\n"
				"Blood begins gushing out of the wound. It continues to crawl towards you!\n"
				"You fire a couple more rounds into the creature until it stops moving.\n\n"
				"On closer inspection, it looks like one of the dogs but with a couple interesting features.\n"
				"There is a tentacle coming out of it's back and it only has three legs.\n"
				"There's a stump where the fourth leg should be. It looks like it was growing that leg!\n"<< std::endl;
		}
		else
		{
			std::cout << "The shot misses! The dog-like thing bites you on the leg. You feel an intense pain!\n"
				"You lose two grit!\n" << std::endl;

			//Calls the gritHit function to cause the player to lose health.
			user->gritHit(2);

			if (user->getAlive() != 0)
			{
				std::cout << "You fire a couple more rounds into it to get it off. Its grip loosens and it falls over.\n"
					"On closer inspection, it looks like one of the dogs but with a couple interesting features.\n"
					"There is a tentacle coming out of it's back and it only has three legs.\n"
					"There's a stump where the fourth leg should be. It looks like it was growing that leg!\n" << std::endl;

				std::cout << "You notice that the gun has no more rounds in it. This angers you since you don't have any spare bullets.\n"
					"You throw the gun against a nearby wall.\n"
					"You lose the gun!\n" << std::endl;

				//Deletes the gun if the shot missed.
				user->deletePlayerItem("gun");
			}
		}
	}
	else if (checkItem->getName() == "axe")
	{
		std::cout << "You pull out the axe and attempt to cleave the creature.\n" << std::endl;

		randomNumber = rand() % 100 + 1;

		if (randomNumber < 80)
		{
			std::cout << "You swing for the fences and send the creature flying back from the direction it came.\n"
				"You walk over to where it landed. It appears to not be moving.\n\n"
				"On closer inspection, it looks like one of the dogs but with a couple interesting features.\n"
				"There is a tentacle coming out of it's back and it only has three legs.\n"
				"There's a stump where the fourth leg should be. It looks like it was growing that leg!\n" << std::endl;
		}
		else
		{
			std::cout << "The swing misses! The dog-like thing bites you on the leg. You feel an intense pain!\n"
				"You lose two grit!\n" << std::endl;

			//Calls the gritHit function to cause the player to lose health.
			user->gritHit(2);

			if (user->getAlive() != 0)
			{
				std::cout << "You hammer downward a couple times to get it off you. Its grip loosens and it falls over.\n"
					"On closer inspection, it looks like one of the dogs but with a couple interesting features.\n"
					"There is a tentacle coming out of it's back and it only has three legs.\n"
					"There's a stump where the fourth leg should be. It looks like it was growing that leg!\n" << std::endl;

				std::cout << "You got so distracted by the intense pain that you now notice the head of the axe has separated from the handle.\n"
					"You lose the axe!\n" << std::endl;

				//Deletes the axe if the swing missed.
				user->deletePlayerItem("axe");
			}
		}
	}
	else if (checkItem->getName() == "flamethrower")
	{
		std::cout << "You pull out the flamethrower.\n" << std::endl;

		std::cout << "You spray flames through the air engulfing whatever this thing is.\n"
			"It's burnt to a nice crisp midway through its jump.\n\n"
			"You walk towards its burning corpse to inspect it. You can't really tell what it is.\n"
			"It looks to be about the size of a dog though.\n"
			"Good thing you had the flamethrower ready when you entered the room!\n" << std::endl;
	}
}
