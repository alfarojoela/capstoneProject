/* Project Name: Capstone Project
   Class: CS 467
   Team: Team Thing- Ryan Alcorn, Joel Alfaro, Neil Gayeta
   File: Latrine.hpp
   Description: Class header for Latrine room.*/

#pragma once

#include "Room.hpp"

class Latrine : public Room {
public:
	int featureOne(Player*);
	int featureTwo(Player*);
	void setRoom();
};
