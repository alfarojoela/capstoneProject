#include "roomRouterFunc.hpp"


/*Based on conditions, calls appropriate roomInteractionFunction.*/
void roomRouter(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector <Room*> &roomList, Parser* parserPtr)
{
	/*Plan is to refactor the code into separate function files for routing which interaction is called.*/
	/*If current player location is the macready room, then roomInteractionMacready will be called.*/
	if (playerLocation->getName() == "macready")
	{
		roomInteractionMacready(commands, playerLocation, playerPtr, roomList, parserPtr);
		return;
	}

	if (playerLocation->getName() == "hallway1")
	{
		roomInteractionHallway1(commands, playerLocation, playerPtr, roomList, parserPtr);
		return;
	}

	if (playerLocation->getName() == "latrine")
	{
		roomInteractionLatrine(commands, playerLocation, playerPtr, roomList, parserPtr);
		return;
	}

	if (playerLocation->getName() == "equipment room")
	{
		roomInteractionEquipmentRoom(commands, playerLocation, playerPtr, roomList, parserPtr);
		return;
	}

	if (playerLocation->getName() == "tool shed")
	{
		roomInteractionToolShed(commands, playerLocation, playerPtr, roomList, parserPtr);
		return;
	}

	if (playerLocation->getName() == "sickBay")
	{
		roomInteractionSickBay(commands, playerLocation, playerPtr, roomList, parserPtr);
		return;
	}

	if (playerLocation->getName() == "radioRoom")
	{
		roomInteractionRadioRoom(commands, playerLocation, playerPtr, roomList, parserPtr);
		return;
	}

	if (playerLocation->getName() == "researchLab")
	{
		roomInteractionResearchLab(commands, playerLocation, playerPtr, roomList, parserPtr);
		return;
	}

	if (playerLocation->getName() == "hallway2")
	{
		roomInteractionHallway2(commands, playerLocation, playerPtr, roomList, parserPtr);
		return;
	}

	if (playerLocation->getName() == "messHall")
	{
		roomInteractionMessHall(commands, playerLocation, playerPtr, roomList, parserPtr);
		return;
	}

	if (playerLocation->getName() == "galley")
	{
		roomInteractionGalley(commands, playerLocation, playerPtr, roomList, parserPtr);
		return;
	}

	if (playerLocation->getName() == "garage")
	{
		roomInteractionGarage(commands, playerLocation, playerPtr, roomList, parserPtr);
		return;
	}

	if (playerLocation->getName() == "dogKennel")
	{
		roomInteractionDogKennel(commands, playerLocation, playerPtr, roomList, parserPtr);
		return;
	}

	if (playerLocation->getName() == "basement")
	{
		roomInteractionBasement(commands, playerLocation, playerPtr, roomList, parserPtr);
		return;
	}

	if (playerLocation->getName() == "conferenceRoom")
	{
		roomInteractionConferenceRoom(commands, playerLocation, playerPtr, roomList, parserPtr);
		return;
	}



}

