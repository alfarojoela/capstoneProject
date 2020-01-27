/* Project Name: Capstone Project
   Class: CS 467
   Team: Team Thing- Ryan Alcorn, Joel Alfaro, Neil Gayeta
   File: Hallway1.hpp
   Description: Class header for the first Hallway room.*/

#pragma once

#include "Room.hpp"

class Hallway1 : public Room {
public:
	std::string getName();
	std::string getLongDescrip();
	std::string getShortDescrip();
	std::string getExitLong();
	std::string getExitShort();
	bool getFeatureOneHap();
	bool getFeatureTwoHap();
	void featureOne();
	void featureTwo();
	void setRoom();
	void itemsInRoom();
	void addItem(Item*);
	void removeItem(Item*);
	void displayDescrip();
	void displayExits();
	Room* changeRooms(std::vector<Room*>, std::string);
};
