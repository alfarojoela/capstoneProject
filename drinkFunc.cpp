#include "drinkFunc.hpp"

void drink(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList, int roomNumber)
{
	std::string beverage = commands[2];
	/*bool check = playerPtr->checkInventory(food);*/
	if (playerPtr->checkInventory(beverage) == 1)
	{
		playerPtr->setGrit(beverage);
		return;
	}

	std::cout << "Sorry.  You can't drink what you don't have in your inventory." << std::endl;
	return;
}


