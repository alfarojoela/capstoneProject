#include "dropFunc.hpp"

/*Function called from roomInteraction function if drop command is sent.*/
void drop(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList, int roomNumber)
{
	std::string itemToCheck = commands[2];

	if (commands[2] == "sardines" || commands[2] == "redherring")
	{
		itemToCheck = "red herring";
	}


	if (playerPtr->checkInventory(itemToCheck) == 1)
	{
		Item itemToDrop = playerPtr->transferItem(itemToCheck);
		Item* itemToDropPtr = &itemToDrop;
		int number = playerPtr->getIndex(itemToCheck);
		playerLocation->addItem(itemToDrop);
		playerPtr->deletePlayerItem(itemToCheck);
		std::cout << "You dropped the " << itemToCheck << std::endl;
		std::cout << "Don't believe me?" << std::endl;
		std::cout << "Check your inventory." << std::endl;
		return;
	}
	else
		std::cout << "You can't drop what's not in your inventory. " << std::endl;
}

