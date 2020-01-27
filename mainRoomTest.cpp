// Main test file for Room and Item classes

#include <iostream>
#include <string.h>
#include <vector>
#include "Galley.hpp"
#include "Macready.hpp"

int main()
{
	//First room tests
	Galley *newGalley = new Galley();
	newGalley->setRoom();

	Item gun("gun", "unknown");
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
	Macready* newStart = new Macready();
	newStart->setRoom();

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
	newStart->displayExits();
}
