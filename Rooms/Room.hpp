/* Project Name: Capstone Project
   Class: CS 467
   Team: Team Thing- Ryan Alcorn, Joel Alfaro, Neil Gayeta
   File: Room.hpp 
   Description: Abstract parent class for Room children class files.*/

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h> 
#include "../Item.hpp"
#include "../Player.hpp"

class Room {
public:
	virtual std::string getName();
	virtual std::string getLongDescrip();
	virtual std::string getShortDescrip();
	virtual std::string getExitLong();
	virtual std::string getExitShort();
	virtual bool getFeatureOneHap();
	virtual bool getFeatureTwoHap();
	virtual int getRoomEntered();
	virtual int featureOne(Player*) = 0;
	virtual int featureTwo(Player*) = 0;
	virtual int checkItem(std::string);
	virtual int numOfItems();
	virtual Item* returnItem(int);
	virtual void clearInventory();
	virtual void setFeatureOne(int);
	virtual void setFeatureTwo(int);
	virtual void setRoomEntered(int);
	virtual void itemsInRoom();
	virtual void setRoom() = 0;
	virtual void addItem(Item);
	virtual void removeItem(std::string, Player*);
	virtual void displayDescrip();
	virtual void displayExits();
	void checkBlood(Player*);
	void testItems(Player*);

protected:
	std::string name;
	std::string longDes;
	std::string shortDes;
	std::string exitLong;
	std::string exitShort;
	std::vector<Item> items;
	int roomEntered;
	bool fOneHappened;
	bool fTwoHappened;
};
