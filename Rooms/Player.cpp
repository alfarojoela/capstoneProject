#include "Player.hpp"

Player::Player()
{
	grit = 2;
	alive = 1;
	victory = 0;
	std::vector<Item> inventory;
	//Room* currentLocation = NULL;
	gameEnd = 0;

}

void Player::useItem(std::string item)
{
	if (checkInventory(item) == 1)
	{
		std::cout << "You use the " << item << std::endl;
	}
	else
		std::cout << "You don't have " << item << " in your inventory." << std::endl;
}

void Player::setVictory(int victory)
{
	this->victory = victory;
}

int Player::getVictory()
{
	return victory;
}

void Player::setGrit(Item* powerup)
{
	/*Call to item class.  Get data member for item.  And then compare with below.*/
	std::string type = powerup->getName();

	if (type == "Vodka")
	{
		grit = grit + 5;
		return;
	}

	if (type == "Gin")
	{
		grit = grit + 4;
		return;
	}

	if (type == "Whisky")
	{
		grit = grit + 3;
		return;
	}

	if (type == "Tequila")
	{
		grit = grit + 2;
		return;
	}

	if (type == "Beer")
	{
		grit = grit + 1;
		return;
	}

	if (type == "Pabst")
	{
		grit--;
		return;
	}

	if (type == "Mata Rata")
	{
		std::cout << "Not a good idea hitting the Mata Rata Tequila...That's Spanish for Rat Killer.  And apparently it is good at killing people too.";
		setAlive(0);
	}

	if (type == "Red Herring")
	{
		std::cout << "You feel no effect on your grit level...How disappointing.  You feel cheated and that this was an exercise in futility." << std::endl;
		return;
	}

	std::cout << "What are you trying to do?  You can't drink that! And you can't eat it either!" << std::endl;
}

/*Use this for grit checks in game.  Certain circumstances will cause death if it is too high or too low.*/
int Player::getGrit()
{
	return grit;
}

void Player::setAlive(int dead)
{
	alive = dead;

	if (alive == 0)
	{
		std::cout << '\a';
		std::cout << "Gosh darn it!  You died!\n" << std::endl;
		std::cout << "That's it man!  Game over, man!  GAME OVER!" << std::endl;
		exit(0);
	}
}

int Player::getAlive()
{
	return alive;
}


void Player::setInventory(Item* newItem)
{
	inventory.push_back(newItem);
}

/*Allows player to see list of inventory.  Not the same as checkInventory*/
void Player::getInventory()
{
	for (int i = 0; i < inventory.size(); i++)
	{
		Item element = *inventory[i];
		Item* elementPtr = &element;
		std::string elementName = elementPtr->getName();
		std::cout << elementName << std::endl;
	}
}

/*Used to check if player has necessary item to pass test.*/
bool Player::checkInventory(std::string itemNeeded)
{
	for (int i = 0; i < inventory.size(); i++)
	{
		Item element = *inventory[i];
		Item* elementPtr = &element;
		std::string elementName = elementPtr->getName();

		if (elementName == itemNeeded)
		{
			return 1;
		}
		else
			return 0;
	}
}

/*Set location for player.  Starts as null but at start of game points to MacReady's quarters.*/
//	void Player::setLocation(Room* newLocation)
//	{
//		currentLocation = newLocation;
//	}

	/*Gets string name for player's current position on the map.*/
//	std::string Player::getLocation()
//	{
//		std::string roomName = currentLocation->getName();
//		return roomName;
//	}
