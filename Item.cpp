/* Project Name: Capstone Project
   Class: CS 467
   Team: Team Thing- Ryan Alcorn, Joel Alfaro, Neil Gayeta
   File: Item.hpp
   Description: Class implementation for the item class.*/

#include "Item.hpp"

/* Constructor for an item object.*/
Item::Item(std::string newName, std::string newLocation)
{
	name = newName;
	location = newLocation;
}

/* Function returns the name of the item. */
std::string Item::getName()
{
	return name;
}

/* Function returns the location of the item. */
std::string Item::getLocation()
{
	return location;
}

bool Item::getUse()
{
	return singleUse;
}

void Item::setLocation(std::string newLoc)
{
	location = newLoc;
}

void Item::setUse()
{
	singleUse = 1;
}
