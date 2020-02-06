// Main test file for Room and Item classes

#include <iostream>
#include <string.h>
#include <vector>
#include <time.h>
#include "ConferenceRoom.hpp"
#include "Galley.hpp"
#include "Macready.hpp"
#include "MessHall.hpp"
#include "Hallway1.hpp"
#include "Hallway2.hpp"
#include "SickBay.hpp"
#include "Latrine.hpp"
#include "ResearchLab.hpp"
#include "EquipmentRoom.hpp"
#include "RadioRoom.hpp"
#include "ToolShed.hpp"
#include "DogKennel.hpp"
#include "Basement.hpp"
#include "Garage.hpp"
#include "Player.hpp"

int main()
{
	srand(time(NULL));
	std::vector<Item> inventory;

	Player* newPlayer = new Player();

	Item toiletPaper("toilet paper");
	Item blowTorch("blow torch");
	Item scapel("scapel");
	Item petri("petri dish");
	Item gun("gun");
	Item axe("axe");
	Item gin("gin");
	Item* ptr = &axe;

	newPlayer->setInventory(ptr);

	//First room tests
	Galley* newGalley = new Galley();
	newGalley->setRoom();
	Macready* newStart = new Macready();
	newStart->setRoom();
	Hallway1* newHall1 = new Hallway1();
	newHall1->setRoom();
	Hallway2* newHall2 = new Hallway2();
	newHall2->setRoom();
	SickBay* newSick = new SickBay();
	newSick->setRoom();
	newSick->addItem(scapel);
	Latrine* newLat = new Latrine();
	newLat->setRoom();
	newLat->addItem(toiletPaper);
	ResearchLab* newLab = new ResearchLab();
	newLab->setRoom();
	EquipmentRoom* newEquip = new EquipmentRoom();
	newEquip->setRoom();
	newEquip->addItem(blowTorch);
	ToolShed* newTool = new ToolShed();
	newTool->setRoom();
	RadioRoom* newRadio = new RadioRoom();
	newRadio->setRoom();
	MessHall* newMess = new MessHall();
	newMess->setRoom();
	newMess->addItem(gin);
	DogKennel* newDog = new DogKennel();
	newDog->setRoom();
	newDog->addItem(petri);
	Basement* newBase = new Basement();
	newBase->setRoom();
	Garage* newGar = new Garage();
	newGar->setRoom();
	ConferenceRoom* newCon = new ConferenceRoom();
	newCon->setRoom();

	std::vector<Room*> rooms;
	rooms.push_back(newGalley);
	rooms.push_back(newStart);
	rooms.push_back(newHall1);
	rooms.push_back(newHall2);
	rooms.push_back(newLat);
	rooms.push_back(newSick);
	rooms.push_back(newLab);
	rooms.push_back(newEquip);
	rooms.push_back(newTool);
	rooms.push_back(newRadio);
	rooms.push_back(newMess);
	rooms.push_back(newDog);
	rooms.push_back(newBase);
	rooms.push_back(newGar);
	rooms.push_back(newCon);

	Room* newRoom;

	for (unsigned int i = 0; i < rooms.size(); ++i)
	{
		newRoom = rooms[i];
		std::cout << "The name of the room is " << newRoom->getName() << std::endl;
		newRoom->displayDescrip();
		newRoom->displayExits();
	}

	newDog->featureOne(newPlayer);

	newDog->itemsInRoom();
	std::cout << "Player's inventory: ";
	newPlayer->getInventory();
	std::cout << std::endl;
	newDog->featureTwo(newPlayer);
	newDog->itemsInRoom();
	std::cout << "Player's inventory: ";
	newPlayer->getInventory();
	std::cout << std::endl;
}

