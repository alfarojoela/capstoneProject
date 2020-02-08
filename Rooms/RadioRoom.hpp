/* Project Name: Capstone Project
   Class: CS 467
   Team: Team Thing- Ryan Alcorn, Joel Alfaro, Neil Gayeta
   File: RadioRoom.hpp
   Description: Class header for RadioRoom room.*/

#pragma once

#include "Room.hpp"

class RadioRoom : public Room {
public:
	int featureOne(Player*);
	int featureTwo(Player*);
	void setRoom();
};
