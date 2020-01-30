/* Project Name: Capstone Project
   Class: CS 467
   Team: Team Thing- Ryan Alcorn, Joel Alfaro, Neil Gayeta
   File: Macready.hpp
   Description: Class header for Macready room.*/

#pragma once

#include "Room.hpp"

class Macready : public Room {
public:
	std::string getName();
	std::string getLongDescrip();
	std::string getShortDescrip();
	std::string getExitLong();
	std::string getExitShort();
	bool getFeatureOneHap();
	bool getFeatureTwoHap();
	int featureOne(std::vector<Item*>);
	int featureTwo(std::vector<Item*>);
	void setRoom();
	void itemsInRoom();
	void addItem(Item*, std::vector<Item*>, int);
	void removeItem(Item*, std::vector<Item*>);
	void displayDescrip();
	void displayExits();
	Room* changeRooms(std::vector<Room*>, std::string);
};
