/* Project Name: Capstone Project
   Class: CS 467
   Team: Team Thing- Ryan Alcorn, Joel Alfaro, Neil Gayeta
   File: Galley.hpp
   Description: Class header for Galley room.*/

#pragma once

#include "Room.hpp"

class Galley : public Room {
public:
	int featureOne(Player*);
	int featureTwo(Player*);
	void setRoom();
};
