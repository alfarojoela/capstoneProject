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
#include "Player.hpp"

class Room {
public:
	virtual std::string getName();
	virtual std::string getLongDescrip();
	virtual std::string getShortDescrip();
	virtual std::string getExitLong();
	virtual std::string getExitShort();
	virtual bool getFeatureOneHap();
	virtual bool getFeatureTwoHap();
	virtual int featureOne(Player*) = 0;
	virtual int featureTwo(Player*) = 0;
	virtual void setRoom() = 0;
	virtual void addItem(Item*, Player*, int);
	virtual void removeItem(Item*, Player*);
	virtual void itemsInRoom();
	virtual void displayDescrip();
	virtual void displayExits();
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
