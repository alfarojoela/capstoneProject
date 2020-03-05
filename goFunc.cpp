#include "goFunc.hpp"

/*go function.  helper function for roomInteraction functions.  Takes playerLocation pointer, vector of room pointers, and an int for the roomNumber.*/
/*rooms will be listed 0-14.*/
void go(Room* &playerLocation, std::vector<Room*> &roomList, int roomNumber, Player* &playerPtr)
{
	playerLocation = roomList[roomNumber];
	std::string roomName;

	if (playerLocation->getName() == "macready")
	{
		roomName = "MacReady's Quarters";
		std::cout << "You go to " << roomName << std::endl;
		std::cout << "CURRENT LOCATION: " << roomName << std::endl;
	}

	if (playerLocation->getName() == "hallway1")
	{
		roomName = "Hallway 1";
		std::cout << "You go to " << roomName << std::endl;
		std::cout << "CURRENT LOCATION: " << roomName << std::endl;
	}

	if (playerLocation->getName() == "latrine")
	{
		roomName = "The Latrine";
		std::cout << "You go to " << roomName << std::endl;
		std::cout << "CURRENT LOCATION: " << roomName << std::endl;
	}

	if (playerLocation->getName() == "equipment room")
	{
		roomName = "The Equipment Room";
		std::cout << "You go to " << roomName << std::endl;
		std::cout << "CURRENT LOCATION: " << roomName << std::endl;
	}

	if (playerLocation->getName() == "tool shed")
	{
		roomName = "The Toolshed";
		std::cout << "You go to " << roomName << std::endl;
		std::cout << "CURRENT LOCATION: " << roomName << std::endl;
	}

	if (playerLocation->getName() == "sickBay")
	{
		roomName = "The Sick Bay";
		std::cout << "You go to " << roomName << std::endl;
		std::cout << "CURRENT LOCATION: " << roomName << std::endl;
	}

	if (playerLocation->getName() == "radioRoom")
	{
		roomName = "The Radio Room";
		std::cout << "You go to " << roomName << std::endl;
		std::cout << "CURRENT LOCATION: " << roomName << std::endl;
	}

	if (playerLocation->getName() == "researchLab")
	{
		roomName = "The Research Lab";
		std::cout << "You go to " << roomName << std::endl;
		std::cout << "CURRENT LOCATION: " << roomName << std::endl;
	}

	if (playerLocation->getName() == "hallway2")
	{
		roomName = "Hallway 2";
		std::cout << "You go to " << roomName << std::endl;
		std::cout << "CURRENT LOCATION: " << roomName << std::endl;
	}

	if (playerLocation->getName() == "messHall")
	{
		roomName = "The Mess Hall";
		std::cout << "You go to " << roomName << std::endl;
		std::cout << "CURRENT LOCATION: " << roomName << std::endl;
	}

	if (playerLocation->getName() == "galley")
	{
		roomName = "The Galley";
		std::cout << "You go to " << roomName << std::endl;
		std::cout << "CURRENT LOCATION: " << roomName << std::endl;
	}

	if (playerLocation->getName() == "dogKennel")
	{
		roomName = "The Dog Kennel";
		std::cout << "You go to " << roomName << std::endl;
		std::cout << "CURRENT LOCATION: " << roomName << std::endl;
	}

	if (playerLocation->getName() == "basement")
	{
		roomName = "The Basement";
		std::cout << "You go to " << roomName << std::endl;
		std::cout << "CURRENT LOCATION: " << roomName << std::endl;
	}

	if (playerLocation->getName() == "conferenceRoom")
	{
		roomName = "The Conference Room";
		std::cout << "You go to " << roomName << std::endl;
		std::cout << "CURRENT LOCATION: " << roomName << std::endl;
	}

	playerPtr->setBearings(1);
}
