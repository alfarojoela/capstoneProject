#include "eatFunc.hpp"

void eat(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList, int roomNumber)
{
	std::string food = commands[2];
	/*bool check = playerPtr->checkInventory(food);*/
	if (playerPtr->checkInventory(food) == 1)
	{
		Item redherring("red herring");
		playerPtr->setGrit("red herring");
	}
	else
		std::cout << "Sorry.  You can't eat what you don't have in your inventory." << std::endl;
}


