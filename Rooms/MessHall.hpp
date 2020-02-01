/* Project Name: Capstone Project
   Class: CS 467
   Team: Team Thing- Ryan Alcorn, Joel Alfaro, Neil Gayeta
   File: MessHall.hpp
   Description: Class header for MessHall room.*/

#pragma once

#include "Room.hpp"

class MessHall : public Room {
public:
	int featureOne(Player*);
	int featureTwo(Player*);
	void setRoom();
	Room* changeRooms(std::vector<Room*>, std::string);
};
