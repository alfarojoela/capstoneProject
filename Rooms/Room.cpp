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
