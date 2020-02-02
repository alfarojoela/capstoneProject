/* Project Name: Capstone Project
   Class: CS 467
   Team: Team Thing- Ryan Alcorn, Joel Alfaro, Neil Gayeta
   File: Garage.hpp
   Description: Class header for Garage room.*/

#pragma once

#include "Room.hpp"

class Garage : public Room {
public:
	int featureOne(Player*);
	int featureTwo(Player*);
	void setRoom();
	Room* changeRooms(std::vector<Room*>, std::string);
};
