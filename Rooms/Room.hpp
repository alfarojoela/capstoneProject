/* Project Name: Capstone Project
   Class: CS 467
   Team: Team Thing- Ryan Alcorn, Joel Alfaro, Neil Gayeta
   File: Room.hpp 
   Description: Abstract parent class for Room children class files.*/

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Item.hpp"

class Room {
public:
	virtual std::string getName() = 0;
	virtual std::string getLongDescrip() = 0;
	virtual std::string getShortDescrip() = 0;
	virtual std::string getExitLong() = 0;
	virtual std::string getExitShort() = 0;
	virtual bool getFeatureOneHap() = 0;
	virtual bool getFeatureTwoHap() = 0;
	virtual int featureOne(std::vector<Item*>) = 0;
	virtual int featureTwo(std::vector<Item*>) = 0;
	virtual void setRoom() = 0;
	virtual void addItem(Item*) = 0;
	virtual void removeItem(Item*) = 0;
	virtual void itemsInRoom() = 0;
	virtual void displayDescrip() = 0;
	virtual void displayExits() = 0;
	virtual Room* changeRooms(std::vector<Room*>, std::string) = 0;

protected:
	std::string name;
	std::string longDes;
	std::string shortDes;
	std::string exitLong;
	std::string exitShort;
	std::vector<Item*> items;
	int roomEntered;
	bool fOneHappened;
	bool fTwoHappened;
};
