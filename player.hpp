#pragma once

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

#include "Room.hpp"
#include "Item.hpp"
#include "Macready.hpp"


class Player
{
private:
	int grit;
	bool alive;
	std::vector<Item> inventory;
	Room* currentLocation;

public:
	Player();

	void setGrit(Item powerup);
	int getGrit();

	void setAlive(bool death);
	int getAlive();

	void setInventory(Item newItem);
	void getInventory();

	/*Function for checking if player has necessary item*/
	bool checkInventory(std::string itemNeeded);

	void usePowerUp(std::string powerUp);

	void setLocation(Room* currentLocation);
	std::string getLocation();
};
