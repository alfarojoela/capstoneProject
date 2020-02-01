// Main test file for Room and Item classes

#include <iostream>
#include <string.h>
#include <vector>
#include "Galley.hpp"
#include "Macready.hpp"
#include "Hallway1.hpp"
#include "SickBay.hpp"
#include "Latrine.hpp"
#include "ResearchLab.hpp"
#include "Player.hpp"

int main()
{
	std::vector<Item*> inventory;

	Player* newPlayer = new Player();

	//First room tests
	Galley* newGalley = new Galley();
	newGalley->setRoom();
	Macready* newStart = new Macready();
	newStart->setRoom();
	Hallway1* newHall1 = new Hallway1();
	newHall1->setRoom();
	SickBay* newSick = new SickBay();
	newSick->setRoom();
	Latrine* newLat = new Latrine();
	newLat->setRoom();
	ResearchLab* newLab = new ResearchLab();
	newLab->setRoom();

	std::vector<Room*> rooms;
	rooms.push_back(newGalley);
	rooms.push_back(newStart);
	rooms.push_back(newHall1);
	rooms.push_back(newLat);
	rooms.push_back(newSick);
	rooms.push_back(newLab);

	Item* newItem = new Item("gun");

	newGalley->addItem(newItem, newPlayer, 0);

	newGalley->itemsInRoom();

	std::cout << "The item's location is " << newItem->getLocation() << std::endl;

	newGalley->removeItem(newItem, newPlayer);

	newGalley->itemsInRoom();

	std::cout << "The item's location is " << newItem->getLocation() << std::endl;

	std::cout << std::endl;

	Room* currentRoom = newStart;

	std::cout << "Room name before function call: " << currentRoom->getName() << std::endl;
	currentRoom->featureOne(newPlayer);

	currentRoom = currentRoom->changeRooms(rooms, "go back");

	std::cout << "Room name after function call: " << currentRoom->getName() << std::endl;
	currentRoom->featureOne(newPlayer);

	/*Item gun("gun", "unknown");
	Item flamethrower("flamethrower", "unknown");

	std::cout << "The name of the room is " << newGalley->getName() << ".\n" << std::endl;

	std::cout << "Long Description: ";
	newGalley->displayDescrip();
	std::cout << "Long Exit: ";
	newGalley->displayExits();

	std::cout << "Add Items to galley: " << std::endl;
	newGalley->addItem(&gun);
	newGalley->addItem(&flamethrower);

	std::cout << "The location of the gun is in the " << gun.getLocation() << ".\n" << std::endl;

	newGalley->itemsInRoom();

	std::cout << "Remove gun from galley: " << std::endl;
	newGalley->removeItem(&gun);

	std::cout << "The location of the gun is in the " << gun.getLocation() << ".\n" << std::endl;

	newGalley->itemsInRoom();

	std::cout << "Short Description: ";
	newGalley->displayDescrip();
	std::cout << "Short Exit: ";
	newGalley->displayExits();

	std::cout << "Feature Two: \n";
	newGalley->featureTwo();

	std::cout << std::endl;

	//Second room tests
	std::cout << "The name of the room is " << newStart->getName() << ".\n" << std::endl;

	std::cout << "Long Description: ";
	newStart->displayDescrip();
	std::cout << "Long Exit: ";
	newStart->displayExits();

	std::cout << "Feature One: ";
	newStart->featureOne();

	std::cout << "Feature Two: ";
	newStart->featureTwo();

	std::cout << "Check to see if bool value updated for feature two: ";
	if (newStart->getFeatureTwoHap() == 1)
	{
		std::cout << "Feature two happened and cannot run again.\n" << std::endl;
	}
	else
	{
		std::cout << "Feature two didn't happen yet.\n" << std::endl;
	}

	std::cout << "Short Description: ";
	newStart->displayDescrip();
	std::cout << "Short Exit: ";
	newStart->displayExits();*/
}
