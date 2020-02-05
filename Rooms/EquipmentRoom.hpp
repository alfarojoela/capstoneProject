/* Project Name: Capstone Project
   Class: CS 467
   Team: Team Thing- Ryan Alcorn, Joel Alfaro, Neil Gayeta
   File: EquipmentRoom.hpp
   Description: Class header for EquipmentRoom room.*/

#pragma once

#include "Room.hpp"

class EquipmentRoom : public Room {
public:
	int featureOne(Player*);
	int featureTwo(Player*);
	void setRoom();
}; 
