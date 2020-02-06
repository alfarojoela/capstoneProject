#include "Player.hpp"

Player::Player()
{
	grit = 2;
	alive = 1;
	victory = 0;
	std::vector<Item> inventory;
	/*Room* currentLocation = NULL;*/
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


void Player::setGrit(std::string powerup)
{
	/*Call to item class.  Get data member for item.  And then compare with below.*/
	/*Item* powerupPtr = &powerup;*/
	/*std::string type = powerupPtr->getName();*/
	std::string type = powerup;
	if (type == "vodka")
	{
		grit = grit + 5;

		std::cout << "You just had some vodka." << std::endl;
		std::cout <<"You feel your resolve strengthened." << std::endl;
		std::cout << "Your grit level is now: " << getGrit() << std::endl;
		deletePlayerItem("vodka");
		return;
	}

	if (type == "gin")
	{
		grit = grit + 4;
		std::cout << "You just had some gin." << std::endl;
		std::cout << "You think of that song by Kiss..." << std::endl;
		std::cout << "'My heater's broken and I am so tired...I need some fuel to build a fire...' You sing." << std::endl;
		std::cout << "Your grit level is now: " << getGrit() << std::endl;
		deletePlayerItem("gin");
		return;
	}

	if (type == "whiskey")
	{
		grit = grit + 3;
		std::cout << "You just had some whiskey." << std::endl;
		std::cout << "You think of that song that Thin Lizzy covered..." << std::endl;
		std::cout << "'Musha rain a dum a doo...There's whisky in the jar, oh...' You sing." << std::endl;
		std::cout << "Your grit level is now: " << getGrit() << std::endl;
		deletePlayerItem("whiskey");
		return;
	}

	if (type == "tequila")
	{
		grit = grit + 2;
		std::cout << "You just had some tequila." << std::endl;
		std::cout << "You think of that song by The Champs..." << std::endl;
		std::cout << "You hum that horn riff from the song and say 'Tequila!'" << std::endl;
		std::cout << "You have the urge to put on some platform shoes, a checkered suit, and a bow tie." << std::endl;
		std::cout << "And dance like a doofus." << std::endl;
		std::cout << "Your grit level is now: " << getGrit() << std::endl;
		deletePlayerItem("tequila");
		return;
	}

	if (type == "beer")
	{
		grit = grit + 1;
		std::cout << "You just had a can of the King of Beers." << std::endl;
		std::cout << "You still feel thirsty." << std::endl;
		std::cout << "Your grit level is now: " << getGrit() << std::endl;
		deletePlayerItem("beer");

		return;
	}

	if (type == "pabst")
	{
		grit--;
		std::cout << "You just had a can of Pabst Blue Ribbon." << std::endl;
		std::cout << "You feel like you are going to throw up." << std::endl;
		std::cout << "Your grit level takes a hit of -1 from the inferior brew." << std::endl;
		std::cout << "Your grit level is now: " << getGrit() << std::endl;
		deletePlayerItem("pabst");

		return;
	}

	if (type == "matarata")
	{
		std::cout << "Not a good idea hitting the Mata Rata Tequila...That's Spanish for Rat Killer.  And apparently it is good at killing people too.";
		setAlive(0);
	}

	if (type == "redherring")
	{
		std::cout << "You eat the Red Herring." << std::endl;
		std::cout << "You feel no effect on your grit level...How disappointing.  You feel cheated and that this was an exercise in futility." << std::endl;
		deletePlayerItem("redherring");

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

void Player::setInventory(Item newItem)
{
	inventory.push_back(newItem);
}

/*Allows player to see list of inventory.  Not the same as checkInventory*/
void Player::getInventory()
{
	for (int i = 0; i < inventory.size(); i++)
	{
		Item element = inventory[i];
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
		Item element = inventory[i];
		Item* elementPtr = &element;
		std::string elementName = elementPtr->getName();

		if (elementName == itemNeeded)
		{
			return 1;
		}

	}
		return 0;


}
/*Takes string and searches the vector.  The Item element is initialized to whatever element the index points at in the inventory vector.*/
/*An Item pointer is declared and assigned to the address of the element so that the data members of the object can be checked with functions*/
/*If the element's name matches the string name, it returns the appropriate Item object.  Function cannot be called unless it passes the item function.*/
Item Player::transferItem(std::string itemNeeded)
{
	for (int i = 0; i < inventory.size(); i++)
	{
		Item element = inventory[i];
		Item* elementPtr = &element;
		std::string elementName = elementPtr->getName();

		if (elementName == itemNeeded)
		{
			return element;
		}
	}
}

/*string of item to drop is sent as an argument.  checks names of items in inventory.  if found, deletes cell where the item is held.*/
void Player::deletePlayerItem(std::string itemNeeded)
{
	std::cout << "INSIDE OBJECT FUNCTION: void Player::deletePlayerItem" << std::endl;
	/*Item* itemNeededPtr = &itemNeeded;*/
	std::string itemToDelete = itemNeeded;

	for (int i = 0; i < inventory.size(); i++)
	{
		Item element = inventory[i];
		Item* elementPtr = &element;
		std::string elementName = elementPtr->getName();

		if (elementName == itemToDelete)
		{
			inventory.erase(inventory.begin()+i);
			return;
		}
	}

	std::cout << "You drop the " << itemNeeded << std::endl;
}

int Player::getIndex(std::string itemToCheck)
{
	for (int i = 0; i < inventory.size(); i++)
	{
		Item element = inventory[i];
		Item* elementPtr = &element;
		std::string elementName = elementPtr->getName();

		if (elementName == itemToCheck)
		{
			return i;
		}
	}
}




void Player::setGameEnd(int ending)
{
	gameEnd = ending;

}




int Player::getGameEnd()
{
	return gameEnd;
}





