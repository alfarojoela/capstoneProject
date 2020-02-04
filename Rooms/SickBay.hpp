/* Project Name: Capstone Project
   Class: CS 467
   Team: Team Thing- Ryan Alcorn, Joel Alfaro, Neil Gayeta
   File: SickBay.hpp
   Description: Class header for SickBay room.*/

#pragma once

#include "Room.hpp"

class SickBay : public Room {
public:
	int featureOne(Player*);
	int featureTwo(Player*);
	void setRoom();
}; 
