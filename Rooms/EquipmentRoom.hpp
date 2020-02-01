/* Project Name: Capstone Project
   Class: CS 467
   Team: Team Thing- Ryan Alcorn, Joel Alfaro, Neil Gayeta
   File: EquipmentRoom.hpp
   Description: Class header for EquipmentRoom room.*/

#pragma once

#include "Room.hpp"

class EquipmentRoom : public Room {
public:
	std::string getName();
	std::string getLongDescrip();
	std::string getShortDescrip();
	std::string getExitLong();
	std::string getExitShort();
	bool getFeatureOneHap();
	bool getFeatureTwoHap();
	int featureOne(Player*);
	int featureTwo(Player*);
	void setRoom();
	void itemsInRoom();
	void addItem(Item*, Player*, int);
	void removeItem(Item*, Player*);
	void displayDescrip();
	void displayExits();
	Room* changeRooms(std::vector<Room*>, std::string);
}; 
