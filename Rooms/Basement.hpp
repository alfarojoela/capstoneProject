/* Project Name: Capstone Project
   Class: CS 467
   Team: Team Thing- Ryan Alcorn, Joel Alfaro, Neil Gayeta
   File: Basement.hpp
   Description: Class header for Basement room.*/

#pragma once

#include "Room.hpp"

class Basement : public Room {
public:
	int featureOne(Player*);
	int featureTwo(Player*);
	void setRoom();
}; 
