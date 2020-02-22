/* Project Name : Capstone Project
Class : CS 467
Team : Team Thing - Ryan Alcorn, Joel Alfaro, Neil Gayeta
File : ResearchLab.cpp
Description : Class implementation for ResearchLab room.*/

#include "ResearchLab.hpp"

/* Function sets the attributes of this room so they can be called by get functions.*/
void ResearchLab::setRoom()
{
	name = "researchLab";
	longDes = "You enter the research lab. This is an area where the crew conducts research during the mission.\n"
		"You see the doctor in the room inspecting a body.\nThere is also a computer displaying information in the corner of the room.\n";
	shortDes = "You return to the research lab. It's a useful room in the base.\n";
	exitLong = "The hallway which connects to many rooms in the base including the radio room and sick bay is from the way you came.\n";
	exitShort = "There is a hallway from the direction you came.\n";
	fOneHappened = 0;
	fTwoHappened = 0;
	roomEntered = 0;
}

/* Function performs the action for the first feature of the room.*/
int ResearchLab::featureOne(Player* user)
{
	int outcome = 0;
	int counter = 0;
	std::string choice = "1";
	std::string response = "incorrect";

	std::cout << "You approach a computer that is currently running a simulation.\n"
		"You decide to sit down. The title of the screen says 'Infection Simulation'\n"<< std::endl;

	//While loop runs until the user enters no or they run through the full computer simulation
	while (response == "incorrect" && counter < 4)
	{
		++counter;

		if (choice == "1")
		{
			std::cout << "Press Enter?\n"
				"1. Yes\n"
				"2. No" << std::endl;
			getline(std::cin, choice);
		}

		if (choice == "2")
		{
			std::cout << std::endl;
			std::cout << "You decide to walk away. You've seen enough from this blasted machine." << std::endl;
			response = "correct";
		}

		if (choice != "1" && choice != "2")
		{
			std::cout << "You have picked an incorrect choice. Please chose again: ";
			getline(std::cin, choice);
		}

		//Different parts of the simulation run based off of the counter that is incremented each time through the loop.
		if (counter == 1 && choice == "1")
		{
			std::cout << std::endl;
			std::cout << "You press enter. A new screen is displayed. It shows a cell by itself at first.\n"
				"All of the sudden another cell appears. This one has tentacles coming out of it.\n"
				"It attacks the cell. The cell changes to look like the second cell and then multiples over and over again.\n"
				"You don't remember biology very well, but this doesn't look good.\n" << std::endl;
		}
		else if (counter == 2 && choice == "1")
		{
			std::cout << std::endl;
			std::cout << "You press enter. A new screen is displayed. It shows a question at first.\n"
				"'Chances of one or more crew members being infected?'\n"
				"'...'\n"
				"'...'\n"
				"'90%'\n\n"
				"'Infected? Infected with what?' you think.\n"
				"This is starting to creep you out.\n" << std::endl;
		}
		else if (counter == 3 && choice == "1")
		{
			std::cout << std::endl;
			std::cout << "You press enter. A new screen is displayed. It shows a map at first.\n"
				"It looks like a map of the world. The same tentacle cell is on the base's location at first.\n"
				"It then begins to spread slowly out into the world. Then quickly until the whole map is covered.\n"
				"'If infection leaves base, days until whole world's population are infected...'\n"
				"'...'\n"
				"'...'\n"
				"'30'\n\n"
				"You are really uncomfortable now.\n" << std::endl;
		}
		else if (counter == 4 && choice == "1")
		{
			std::cout << std::endl;
			std::cout << "You press enter. A new screen is displayed. It shows a couple statements.\n"
				"'Only viable options...'\n"
				"'...'\n"
				"'...'\n"
				"'Destroy the infection and all those infected by it or...'\n"
				"'...'\n"
				"'...'\n"
				"'Destroy the base!'\n\n"
				"After reading this you press enter again. The simulation ends. You decide to get up from the computer.\n"
				"'This is bad. Really bad.' you think." << std::endl;
			response = "correct";
		}
	}
	std::cout << std::endl;

	++fOneHappened;

	return outcome;
}

/* Function performs the action for the second feature of the room.*/
int ResearchLab::featureTwo(Player* user)
{
	int outcome = 0;
	int number = 0;
	std::string choice = "";
	std::string response = "incorrect";

	std::cout << "You approach the doctor.\n"
		"'Look who's finally up? Have a good night there, champ,' he says.\n"
		"You don't respond because you are stunned by the body laid out on the table.\nIt's the captain! It does not look like he's moving.\n"
		"The doctor frowns at you and then says 'Come over here. I need help!'\n\n"
		"You decide to help the doctor and walk over to the table.\n"
		"'My strap broke and I need you to hold the body down here,' he says.\n"
		"You nod and apply the pressure. He reaches over to the table and picks up a bone saw.\n"
		"This is not what you signed up for, but you continue applying pressure. He begins to perform an autopsy.\n\n"
		"You hear the crunch of bones in the captain's chest. Sounds normal to you.\n"
		"All of the sudden the chest gives way. The doctor's arms go through the chest!\nHe says 'What the hell!'. Teeth form in the hole on the chest.\n"
		"They close on the doctor's arms and sever them both.\nBlood begins to spray everywhere! The doctor begins screaming in agony!\n\n"
		"After a couple seconds, he isn't screaming anymore. He slumps over on the table.\n"
		"The thing that is the captain stands up.\n"
		"What do you do?\n\n"
		"1. Attack the creature\n"
		"2. Attempt to flee" << std::endl;
	getline(std::cin, choice);

	while (response == "incorrect")
	{
		if (choice == "1")
		{
			std::cout << std::endl;

			//Add function to check if user has specific items to protect themselves
			if (user->checkInventory("gun") || user->checkInventory("flamethrower") || user->checkInventory("axe"))
			{
				//Calls the weapon attack function
				weaponAttack(user);
			}
			else
			{
				std::cout << "You do not have a weapon to fend off the creature!" << std::endl;
				choice = "2";
			}

			response = "correct";
		}
		
		if (choice == "2")
		{
			std::cout << std::endl;
			std::cout << "You attempt to flee. You think 'I have no chance considering what this thing did to the doctor'.\n"
				"You turn to run. As you turn you hear the creature take a swipe at you.\n" << std::endl;

			//Random chance that the player will take damage
			number = rand() % 100 + 1;

			if (number < 41)
			{
				std::cout << "You run as fast as you've ever run in your life. The swipe misses you!\n"
					"The force of the swing causes the creature to fall over face first into the ground.\n"
					"You take a nearby chair and slam it into the thing a couple of times.\n"
					"After about five hits, it appears to not be moving." << std::endl;
			}
			else
			{
				std::cout << "You run as fast as you've ever run in your life. The swipe hits you! It's claws puncture your shoulder.\n"
					"You lose two grit!\n" << std::endl;

				//Calls the gritHit function to cause the player to lose health.
				user->gritHit(2);

				std::cout << "You reflexively kick backwards causing the creature to fall onto the ground.\n"
					"It appears to not be moving." << std::endl;
			}

			response = "correct";
		}
		
		if(choice != "1" && choice != "2")
		{
			std::cout << "You have picked an incorrect choice. Please chose again: ";
			getline(std::cin, choice);
		}
	}
	std::cout << std::endl;

	++fTwoHappened;

	return outcome;
}

//Function allows the user to attack creatures with a random weapon from their inventory.
void ResearchLab::weaponAttack(Player* user)
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
		std::cout << "You pull out the gun and attempt to take a shot at the thing that used to be the captain.\n" << std::endl;

		randomNumber = rand() % 100 + 1;

		if (randomNumber < 80)
		{
			std::cout << "The shot hits it square in the chest. Blood begins gushing out of the wound.\n"
				"It continues to move towards you! You fire five more rounds into the thing.\n"
				"Most of the shots hit various parts of the captain's body, but one is a headshot.\n"
				"The thing's head explodes. After that shot, it stops moving towards you and falls onto the ground." << std::endl;
		}
		else
		{
			std::cout << "The shot misses! The thing slashes your arm that is holding the gun. Blood starts gushing from your arm.\n"
				"You lose two grit!\n" << std::endl;

			//Calls the gritHit function to cause the player to lose health.
			user->gritHit(2);

			std::cout << "You fire a five more rounds into it point blank. All of the shots hit its chest.\n"
				"After the fifth shot, it falls backwards onto the table it was laying on. It stops moving.\n" << std::endl;

			std::cout << "You notice that the gun has no more rounds in it. This angers you since you don't have any spare bullets.\n"
				"You throw the gun against a nearby wall.\n"
				"You lose the gun!" << std::endl;

			//Deletes the gun if the shot missed.
			user->deletePlayerItem("gun");
		}
	}
	else if (checkItem->getName() == "axe")
	{
		std::cout << "You pull out the axe and attempt to strike the thing.\n" << std::endl;

		randomNumber = rand() % 100 + 1;

		if (randomNumber < 80)
		{
			std::cout << "You hit it square in the chest sending it flying backwards.\n"
				"You walk over to where it landed and swing the axe a couple more times until it stops moving." << std::endl;
		}
		else
		{
			std::cout << "The thing blocks your attack and slashes your arm. Blood begins gushing out of the wound.\n"
				"You lose two grit!\n" << std::endl;

			//Calls the gritHit function to cause the player to lose health.
			user->gritHit(2);

			std::cout << "After the slash, you swing another time. It doesn't block this hit.\n"
				"It falls backwards onto the table it was laying on before. You swing a couple more times until it stops moving.\n" << std::endl;

			std::cout << "After the last swing you hear a clank. You notice the head of the axe has fallen and is separted from the handle.\n"
				"You lose the axe!" << std::endl;

			//Deletes the axe if the swing missed.
			user->deletePlayerItem("axe");
		}
	}
	else if (checkItem->getName() == "flamethrower")
	{
		std::cout << "You pull out the flamethrower.\n" << std::endl;

		std::cout << "You spray flames through the air engulfing whatever this thing is.\n"
			"It continues to move towards you at first, but after about five seconds it falls over.\n"
			"You spray flames on it for about ten more seconds just to be sure.\n"
			"Good thing you had the flamethrower ready when you entered the room!" << std::endl;
	}
}
