/* Project Name : Capstone Project
Class : CS 467
Team : Team Thing - Ryan Alcorn, Joel Alfaro, Neil Gayeta
File : ToolShed.cpp
Description : Class implementation for ToolShed room.*/

#include "ToolShed.hpp"

/* Function sets the attributes of this room so they can be called by get functions.*/
void ToolShed::setRoom()
{
	name = "toolShed";
	longDes = "You make your way towards the tool shed. It is located outside of the base. It is freezing cold outside.\n"
		"Hopefully you can find something worthwhile in there. You begin to hear groaning coming from the west.\n"
		"You also notice something shining in the snow to the east.\n";
	shortDes = "You return to the tool shed. It used to contain useful equipment.\n";
	exitLong = "The equipment room which leads back into the base is from the way you came.\n";
	exitShort = "The equipment room is from the direction you came.\n";
	fOneHappened = 0;
	fTwoHappened = 0;
	roomEntered = 0;
}

/* Function performs the action for the first feature of the room.*/
int ToolShed::featureOne(Player* user)
{
	int outcome = 0;
	int number = 0;
	int alive = 0;
	std::string choice = "";
	std::string response = "incorrect";

	//Used to determine which text displays since the two features happen outside.
	if (getFeatureTwoHap() == 1)
	{
		std::cout << "You head back outside and go west towards groaning noise. It could be an injured member of the base." << std::endl;
	}
	else
	{
		std::cout << "You head west towards the groaning noise. It could be an injured member of the base." << std::endl;
	}

	std::cout << "You walk for about two minutes before you see a hunched over figure about 20 feet ahead of you.\n"
		"You call out 'Hey there, you alright?'\n"
		"No response...\n\n"
		"You take about five more steps and stop. All of the sudden the figure turns around and charges you.\n"
		"What do you do?\n\n"
		"1. Attack the figure with your fists\n"
		"2. Attack the figure with a weapon\n"
		"3. Attempt to dodge the incoming attack and flee"<< std::endl;
	std::cin >> choice;

	while (response == "incorrect")
	{
		if (choice == "1")
		{
			std::cout << std::endl;

			std::cout << "You think to yourself 'There's no way I'm outrunning this!'\n"
				"You decide to sidestep the attack and punch the creature in the side as it is running by.\n" << std::endl;

			number = rand() % 100 + 1;

			if (number < 40)
			{
				std::cout << "You perform your maneuver to perfection. The creature is surprised by your sudden movement and tries to pivot.\n"
					"That along with the punch you throw sends it flying five feet into the snow.\n"
					"While it is on the ground, you decide its best to flee. You make your way back to the path towards the tool shed.\n" << std::endl;

				++alive;
			}
			else
			{
				std::cout << "You attempt to perform the move you thought up but are too slow!\n"
					"The creature catches you in the side with one of its claws.\n"
					"It drags you down into the snow. The last thing you see is its face!\nIt looks like are human face but its features are melting away.\n"<< std::endl;

				//Call function to kill player
			}

			response = "correct";
		}
		else if (choice == "2")
		{
			std::cout << std::endl;

			//Add function to check if user has specific items to protect themselves
			if (user->checkInventory("gun") || user->checkInventory("flamethrower") || user->checkInventory("axe"))
			{
				std::cout << "You attack the creature with a weapon. It is surprised by your sudden attack!\n"
					"Realizing it is in danger, the creature runs off towards the direction you found it at.\n"
					"You head back to the trail that leads to the tool shed.\n"<< std::endl;

				++alive;
			}
			else
			{
				std::cout << "You do not have a weapon to fend off the creature!" << std::endl;
				choice = "3";
			}

			response = "correct";
		}
		
		if (choice == "3")
		{
			std::cout << std::endl;

			number = rand() % 100 + 1;

			if (number < 25)
			{
				std::cout << "You begin sprinting back towards the trail that leads to the tool shed.\n"
					"After about fifty feet, you look back. The creature isn't following you. It must have got lost in the snow!\n"
					"You make it back to the trail safely.\n" << std::endl;

				++alive;
			}
			else
			{
				std::cout << "You attempt to outrun the creature. Unfornately, you are too slow!\n"
					"The creature catches up to you and slashes you in the side with one of its claws.\n"
					"It drags you down into the snow. The last thing you see is its face!\nIt looks like are human face but its features are melting away.\n" << std::endl;

				//Call function to kill player
			}

			response = "correct";
		}

		if(choice != "1" && choice != "2" && choice != "3")
		{
			std::cout << "You have picked an incorrect choice. Please chose again: ";
			std::cin >> choice;
		}
	}

	//Used to determine whether the user obtains the rope based on if they've already been to the room.
	if (alive > 0 && user->checkInventory("rope") == 0)
	{
		obtainRope(user);
	}
	else if (alive > 0 && user->checkInventory("rope") == 1)
	{
		std::cout << "You make it to the tool shed. There are not many useful items left here.\n" << std::endl;
	}

	++fOneHappened;

	return outcome;
}

/* Function performs the action for the second feature of the room where the player could obtain an item or die.*/
int ToolShed::featureTwo(Player* user)
{
	int outcome = 0;
	int number = 0;
	int alive = 0;
	std::string choice = "";
	std::string response = "incorrect";

	//Used to determine which text displays since the two features happen outside.
	if (getFeatureOneHap() == 1)
	{
		std::cout << "You head back outside and go east towards the glint in the snow." << std::endl;
	}
	else
	{
		std::cout << "You head east towards the glint in the snow." << std::endl;
	}

	std::cout << "Your body is getting colder and colder, but there could be something useful there.\n"
		"What do you do?\n\n"
		"1. Head deeper into the snow to obtain the item\n"
		"2. Turn back to the path headed towards the tool shed" << std::endl;
	std::cin >> choice;

	while (response == "incorrect")
	{
		if (choice == "1")
		{
			std::cout << std::endl;
			std::cout << "Today's been crazy already why not see what this is! You head towards the glinting item in the snow.\n" << std::endl;
				
			number = rand() % 100 + 1;

			if (number > 50)
			{
				std::cout << "The item becomes more clear as you move closer. It is a bottle of Maker's Mark whiskey!\nYou could always use more alcohol.\n"
					"You obtain a bottle of whiskey!" << std::endl;

				++alive;

				//Calls function to remove whiskey from the room and add it to the player's inventory.
				removeItem("whiskey", user);
			}
			else
			{
				std::cout << "You head further into the snow. All of the sudden a gust of wind blows through.\n"
					"You get turned around and don't know the direction of the item or the base.\n"
					"You wander further and further away until you can't feel anything anymore." << std::endl;

				//Call function to kill player
			}

			response = "correct";
		}
		else if (choice == "2")
		{
			std::cout << std::endl;
			std::cout << "You decide not to risk it and continue on the path to the tool shed." << std::endl;

			++alive;
			response = "correct";
		}
		else
		{
			std::cout << "You have picked an incorrect choice. Please chose again: ";
			std::cin >> choice;
		}
	}
	std::cout << std::endl;

	//Used to determine whether the user obtains the rope based on if they've already been to the room.
	if (alive > 0 && user->checkInventory("rope") == 0)
	{
		obtainRope(user);
	}
	else if (alive > 0 && user->checkInventory("rope") == 1)
	{
		std::cout << "You make it to the tool shed. There are not many useful items left here.\n" << std::endl;
	}

	++fTwoHappened;

	return outcome;
}

//Function allows the user to obtain a rope if they make it to the tool shed
void ToolShed::obtainRope(Player* user)
{
	std::cout << "You reach the tool shed. The place looks ramshackled. Someone else has been here before you.\n"
		"You don't see many useful items in the room. The only item that could potentially help you is a rope.\n"
		"You obtain a rope!\n" << std::endl;

	removeItem("rope", user);
}
