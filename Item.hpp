/* Project Name: Capstone Project
   Class: CS 467
   Team: Team Thing- Ryan Alcorn, Joel Alfaro, Neil Gayeta
   File: Item.hpp
   Description: Class header for the item class.*/

#pragma once

#include <iostream>
#include <string>
#include <vector>

class Item {
public:
	Item(std::string newName);
	std::string getName();
	std::string getLocation();
	bool getUse();
	void setLocation(std::string);
	void setUse();

private:
	std::string name;
	std::string location;
	bool singleUse = 0;
};
