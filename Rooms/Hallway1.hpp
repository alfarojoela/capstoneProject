/* Project Name: Capstone Project
   Class: CS 467
   Team: Team Thing- Ryan Alcorn, Joel Alfaro, Neil Gayeta
   File: Hallway1.hpp
   Description: Class header for the first Hallway room.*/

#pragma once

#include "Room.hpp"

class Hallway1 : public Room {
public:
	int featureOne(Player*);
	int featureTwo(Player*);
	void setRoom();
	Room* changeRooms(std::vector<Room*>, std::string);
};
