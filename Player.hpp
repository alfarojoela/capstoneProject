#pragma once

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

/*#include "Room.hpp"*/
#include "Item.hpp"


/*#include "Macready.hpp"*/
/*#include "Hallway1.hpp"*/

class Player
{
private:
	int grit;
	int alive;
	int victory;
	int gameEnd;


	std::vector<Item*> inventory;

public:
	Player();


	void useItem(std::string item);
	void setGrit(Item* powerup);

	int getGrit();
	void setAlive(int dead);

	int getAlive();

	void setInventory(Item* newItem);
	void getInventory();

	int getVictory();
	void setVictory(int victory);

	/*Function for checking if player has necessary item*/
	bool checkInventory(std::string itemNeeded);

	void usePowerUp(std::string powerUp);

	void setGameEnd(int ending);
	int getGameEnd();
	
	void deletePlayerItem(std::string itemNeeded);

	Item transferItem(std::string itemNeeded);

	int getIndex(std::string itemToCheck);
};

