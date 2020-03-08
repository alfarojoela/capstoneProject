#include "takeFunc.hpp"

/*Gets a string out of the commands vector.  Sends the string to the room removeItem function with the player pointer.  Room function handles the transition of inventory to player inventory and then deletes the appropriate cell.*/
void take(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList, int roomNumber)
{

	std::string itemToTake = commands[2];

	if (commands[2] == "sardines" || commands[2] == "redherring")
	{
		itemToTake = "red herring";
	}

	if (playerLocation->checkItem(itemToTake) != 999)
	{
		std::cout << "'Zoinks!'you say.  Just like Shaggy from Scooby Doo.  You found the " << itemToTake << std::endl;
		std::cout << "You're taking it with you." << std::endl;
		playerLocation->removeItem(itemToTake, playerPtr);
		return;
	}

	if (playerLocation->checkItem(itemToTake) == 999 && playerLocation->getName() == "macready")
	{
		std::cout << "You can't do that." << std::endl;
		std::cout << "Besides, it's not a good idea trying to take Macready's stuff without asking.  You're liable to get on his wrongside.  And you don't wanna be on his wrongside." << std::endl;
		return;
	}

	if (playerLocation->checkItem(itemToTake) == 999)
	{
		if (playerPtr->checkInventory(itemToTake) == 1)
		{
			std::cout << "It's already in your inventory." << std::endl;
			return;
		}

		std::cout << "You can't take that." << std::endl;
		return;
	}



}


