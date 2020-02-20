/* Project Name: Capstone Project
   Class: CS 467
   Team: Team Thing- Ryan Alcorn, Joel Alfaro, Neil Gayeta
   File: Latrine.cpp
   Description: Class implementation for Latrine room.*/

#include "Latrine.hpp"

/* Function sets the attributes of this room so they can be called by get functions.*/
void Latrine::setRoom()
{
	name = "latrine";
	longDes = "You enter the latrine. This is the area of the base that contains the restroom.\n"
		"This room usually does not smell good. It's not a room you want to stay in for long,\nbut you think you remember booze being in here."
		" You notice some toilet paper in an odd location in the room.\nYou also have the need to use the restroom.\n";
	shortDes = "You return to the latrine. It's a bathroom.\n";
	exitLong = "The hallway which connects to many rooms in the base including the research lab and sick bay is from the way you came.\n";
	exitShort = "There is a hallway from the direction you came.\n";
	fOneHappened = 0;
	fTwoHappened = 0;
	roomEntered = 0;
}

/* Function performs the action for the first feature of the room. Player can gain the toilet paper from the feature.*/
int Latrine::featureOne(Player* user)
{
	int outcome = 0;
	int index = 0;

	std::cout << "You decide to inspect the toilet paper. It is sprawled on the ground in an abnormal way.\n"
		"Either someone's pulling a prank or something's going on.\n"
		"The writing on the toilet paper appears to be in charcoal. This is weird.\n"
		"There are numbers written on here. 5...3...9...2.\n"
		"Someone wrote the code to the flamethrower locker on here. Odd...\n"<< std::endl;


	//Removes the toilet paper from the room using the removeItem function
	removeItem("toilet paper", user);

	++fOneHappened;

	return outcome;
}

/* Function performs the action for the second feature of the room. Player can get hurt in this function.*/
int Latrine::featureTwo(Player* user)
{
	int outcome = 0;
	int number = 0;
	std::string choice = "";
	std::string response = "incorrect";

	std::cout << "You decide to use the restroom. It was a long night.\n"
		"You begin to hear splashing sounds which causes you to have an uneasy feeling.\n"
		"You finish using the restroom and begin to walk away.\n"
		"As you look back all of the sudden something jumps at you!\n"
		"What do you do?\n\n"
		"1. Attack it with your fists\n"
		"2. Attack it with a weapon\n"
		"3. Attempt to dodge the attack" << std::endl;
	getline(std::cin, choice);

	while (response == "incorrect")
	{
		if (choice == "1")
		{
			std::cout << std::endl;
			std::cout << "You attack it with your fists. As the thing flies at you, you notice how small it is.\n"
				"Easy enough to punch. You send it flying back into the wall!\n"
				"Whatever that was, it isn't getting up for a while.\n" << std::endl;

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

				response = "correct";
			}
			else
			{
				std::cout << "You do not have a weapon to fend off the creature!" << std::endl;
				choice = "3";
			}
		}

		if (choice == "3")
		{
			std::cout << std::endl;
			std::cout << "You attempt to dodge the incoming attack!" << std::endl;
			std::cout << std::endl;

			//Random chance the player will get hurt
			number = rand() % 100 + 1;

			if (number > 50)
			{
				std::cout << "You successfully dodge the attack! The creature flies by you while shrieking.\n"
					"It lands on the ground hard and appears not to be moving.\n"<< std::endl;
			}
			else
			{
				std::cout << "You are too slow! The creature bites you in the shoulder. You feel an intense pain.\n"
					"Reflexively, you grab it and fling it against the wall. The creature appears to stop moving.\n"
					"You lose one grit!\n" << std::endl;

				//Calls the gritHit function to cause the player to lose health.
				user->gritHit(1);
			}

			response = "correct";
		}

		if (choice != "1" && choice != "2" && choice != "3")
		{
			std::cout << "You have picked an incorrect choice. Please chose again: ";
			getline(std::cin, choice);
		}
	}

	++fTwoHappened;

	return outcome;
}

//Function allows the user to attack creatures with a random weapon from their inventory.
void Latrine::weaponAttack(Player* user)
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
		std::cout << "You pull out the gun and attempt to take a shot at the creature.\n" << std::endl;

		randomNumber = rand() % 100 + 1;

		if (randomNumber < 80)
		{
			std::cout << "The shot hits the creature in the forehead. Pieces of whatever was in the creature's brain scatter across the room!\n" << std::endl;
		}
		else
		{
			std::cout << "The shot misses! The creature bites you in the shoulder. You feel an intense pain.\n"
					"Reflexively, you grab it and fling it against the wall. The creature appears to stop moving.\n"
					"You lose one grit!\n" << std::endl;

			//Calls the gritHit function to cause the player to lose health.
			user->gritHit(1);

			std::cout << "You attempt to shoot the gun again at the creature in frustration, but notice that it's broken.\n"
				"You lose the gun!\n" << std::endl;

			//Deletes the gun if the shot missed.
			user->deletePlayerItem("gun");
		}
	}
	else if (checkItem->getName() == "axe")
	{
		std::cout << "You pull out the axe and attempt to cleave the creature.\n" << std::endl;

		randomNumber = rand() % 100 + 1;

		if (randomNumber < 80)
		{
			std::cout << "You swing for the fences and cleave the creature in two.\n"
				"Is this real or are you still dreaming in a drunken stupor?\n" << std::endl;
		}
		else
		{
			std::cout << "The swing misses! The creature bites you in the shoulder. You feel an intense pain.\n"
				"Reflexively, you grab it and fling it against the wall. The creature appears to stop moving.\n"
				"You lose one grit!\n" << std::endl;

			//Calls the gritHit function to cause the player to lose health.
			user->gritHit(1);

			std::cout << "You swung so hard that the axe flung into the wall and broke.\n"
				"You lose the axe!\n" << std::endl;

			//Deletes the axe if the swing missed.
			user->deletePlayerItem("axe");
		}
	}
	else if (checkItem->getName() == "flamethrower")
	{
		std::cout << "You pull out the flamethrower.\n" << std::endl;

		std::cout << "You spray flames through the air engulfing the creature.\n"
			"It's burnt to a nice crisp by the time it reaches you.\nGood thing you had the flamethrower ready when you entered the room!\n" << std::endl;
	}
}
