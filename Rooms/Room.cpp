#include "Room.hpp"

/* Function returns the name of the room. */
std::string Room::getName()
{
	return name;
}

/* Function returns the long description of the room. */
std::string Room::getLongDescrip()
{
	return longDes;
}

/* Function returns the short description of the room. */
std::string Room::getShortDescrip()
{
	return shortDes;
}

/* Function returns the long version of the exits description of the room. */
std::string Room::getExitLong()
{
	return exitLong;
}

/* Function returns the short version of the exits description of the room. */
std::string Room::getExitShort()
{
	return exitShort;
}

/* Function returns the boolean value that represents whether a feature happened.*/
bool Room::getFeatureOneHap()
{
	return fOneHappened;
}

/* Function returns the boolean value that represents whether a feature happened.*/
bool Room::getFeatureTwoHap()
{
	return fTwoHappened;
}

/* Function returns the int value that represents the roomEntered variable. */
int Room::getRoomEntered()
{
	return roomEntered;
}

/* Function adds an item to the vector of items in the room.  */
void Room::addItem(Item newItem)
{
	items.push_back(newItem);
}

/* Function removes an item from the vector of items in the room and adds it to the player's inventory.*/
void Room::removeItem(std::string itemToSearch, Player* user)
{
	int result = 0;

	if (items.size() > 0)
	{
		//Calls checkItem to see if the item is in the room inventory. If it is, the index is used to add it to the player's inventory and remove it from the room.
		result = checkItem(itemToSearch);

		if (result != 999)
		{
			user->setInventory(items[result]);
			items.erase(items.begin() + result);
		}
	}
}

/* Function displays the items currently in the room.*/
void Room::itemsInRoom()
{
	if (items.size() > 0)
	{
		std::cout << "The current items in the " << getName() << " are: ";
		for (unsigned int i = 0; i < items.size(); i++)
		{
			if (i != (items.size() - 1))
			{
				std::cout << items[i].getName() << ", ";
			}
			else
			{
				std::cout << items[i].getName() << std::endl;
			}
		}
	}
	else
	{
		std::cout << "There are no items to pick up in the room." << std::endl;
	}
}

/* Function receives a string and checks if an item is in the room's inventory. Returns the index if the item is found. Else returns 999.*/
int Room::checkItem(std::string itemName)
{
	int itemFound = 999;

	if (items.size() > 0)
	{
		for (unsigned int i = 0; i < items.size(); ++i)
		{
			if (items[i].getName() == itemName)
			{
				itemFound = i;
			}
		}
	}

	return itemFound;
}

//Function returns the number of items present in the room's inventory
int Room::numOfItems()
{
	int number = 0;

	if (items.size() > 0)
	{
		number = items.size();
	}

	return number;
}

//Function returns an item at a specific index.
Item* Room::returnItem(int index)
{
	Item* newItem = &items[index];

	return newItem;
}

//Function clears the inventory of the room.
void Room::clearInventory()
{
	items.clear();
}

//Function sets the feature one variable in the loading function.
void Room::setFeatureOne(int newNumber)
{
	fOneHappened = newNumber;
}

//Function sets the feature two variable in the loading function.
void Room::setFeatureTwo(int newNumber)
{
	fTwoHappened = newNumber;
}

//Function sets the roomEntered variable in the loading function.
void Room::setRoomEntered(int newNumber)
{
	roomEntered = newNumber;
}

/* Function displays either the short or long description based off a boolean value.*/
void Room::displayDescrip()
{
	if (roomEntered == 0)
	{
		std::cout << longDes << std::endl;
	}
	else
	{
		std::cout << shortDes << std::endl;
	}
	++roomEntered;
}

/* Function displays the exit descriptions based on whether it is the first time the user entered the room.*/
void Room::displayExits()
{
	if (roomEntered == 1)
	{
		std::cout << exitLong << std::endl;
	}
	else
	{
		std::cout << exitShort << std::endl;
	}
}


void Room::checkBlood(Player* user)
{
	/*Differenet lines and function calls will be executed based off of the items the player has.*/
	if (user->getDrOutcome() == 0)
	{
		std::cout << "Why would you want to check the blood of the doctor?\nHe hasn't done anything suspicious to you." << std::endl;
	}
	else if (user->getDrOutcome() == 1)
	{
		std::cout << "Why would you want to check the blood of the doctor?\nHe answered most if not all of your questions correctly." << std::endl;
	}
	else if (user->getDrOutcome() == 2)
	{
		std::cout << "The doctor isn't here anymore. Remember when he shot you in the leg and took off?" << std::endl;
	}
	else if (user->getDrOutcome() == 3)
	{
		if (user->checkInventory("rope"))
		{
			std::cout << "The doctor is still on the ground knocked out.\nYou decide to tie him up with the rope so he doesn't cause harm to anyone else." << std::endl;

			//Sets the outcome of the interaction to 4. The user's inventory will be checked to see if they have the appropriate items to test the blood.
			user->setDrOutcome(4);

			//Calls a function that will allow the user to test the NPC's blood if they have the appropriate items.
			testItems(user);
		}
		else
		{
			std::cout << "The doctor is still on the ground knocked out.\nYou still need something to tie him up with." << std::endl;
		}
	}
	else if (user->getDrOutcome() == 4)
	{
		//Calls a function that will allow the user to test the NPC's blood if they have the appropriate items.
		testItems(user);
	}
	else if (user->getDrOutcome() == 5)
	{
		std::cout << "You already tested the doctor's blood. He's not human!\n" << std::endl;

		if (user->checkInventory("flamethrower"))
		{
			std::cout << "'This isn't right!', you think. 'I have to do something about this.'\n"
				"You pull out the flamethrower. You begin to pour out flames on the thing pretending to be Dr. Blair.\n"
				"It makes no noise at first, but then wakes up and begins shrieking. It's body begins shaking heavily.\n"
				"You continue to pour on the flames until it stops moving.\nAfter seeing it shake like that, you feel like you made the right choice." << std::endl;

			//Sets the outcome of the interaction to 6. The player has learned all they can from the interaction and destroyed the creature.
			user->setDrOutcome(6);
		}
	}
	else if (user->getDrOutcome() == 6)
	{
		std::cout << "You already found out that the doctor was not human and destroyed it! Good work!" << std::endl;
	}
}

void Room::testItems(Player* user)
{
	//Checks whether the player has specific items to help figure out what's going on.
	if (user->checkInventory("blowtorch") && user->checkInventory("petri dish") && user->checkInventory("copper wire") && user->checkInventory("scalpel"))
	{
		std::cout << "You bend down next to the doctor and notice he's still bleeding from his nose.\n"
			"As you stand up, you hear a clank against the ground.\n"
			"The blowtorch you had been carrying around fell next to the tied up individual.\n"
			"You notice blood on the ground next to the blowtorch.\n\n"
			"You reach to pick up the blowtorch, but accidently pull its trigger while grabbing it.\n"
			"A flame shoots out of the blowtorch and you hear a shriek. The blood isn't there anymore!\n"
			"You don't know a lot about medicine, but that shouldn't happen. You decide to test more of his blood.\n\n"
			"You take the scalpel you received in the sick bay and make a cut on his finger.\n"
			"The blood drips into the petri dish you found earlier.\nYou then take the blowtorch and use it on the copper wire you found earlier.\n"
			"Finally, you insert the copper wire into the petri dish. When you do the blood jumps up and shrieks.\nIt then disappears!\n"
			"'This isn't Dr. Blair!', you think, 'This is something else!'\n" << std::endl;

		//Increases the variable to get one of the endings of the game.
		user->setDeathWish(10);
		std::cout << "You gain a significant amount of knowledge about what's going on!\n" << std::endl;

		if (user->checkInventory("flamethrower"))
		{
			std::cout << "'This isn't right!', you think. 'I have to do something about this.'\n"
				"You pull out the flamethrower. You begin to pour out flames on the thing pretending to be Dr. Blair.\n"
				"It makes no noise at first, but then wakes up and begins shrieking. It's body begins shaking heavily.\n"
				"You continue to pour on the flames until it stops moving.\nAfter seeing it shake like that, you feel like you made the right choice." << std::endl;

			//Sets the outcome of the interaction to 6. The player has learned all they can from the interaction and destroyed the creature.
			user->setDrOutcome(6);
		}
		else
		{
			std::cout << "'So there are things on the base acting like us, but are not us.', you think.\n"
				"You decide to leave it tied up down here." << std::endl;

			//Sets the outcome of the interaction to 5. The player has learned all they can from the interaction but has not destroyed the creature.
			user->setDrOutcome(5);
		}
	}
	else
	{
		std::cout << "He wasn't acting like Dr. Blair. He's bleeding from his nose.\n"
			"There's got to be some way of testing whether or not it is him." << std::endl;
	}
}
