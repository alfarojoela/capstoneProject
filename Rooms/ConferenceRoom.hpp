/* Project Name: Capstone Project
   Class: CS 467
   Team: Team Thing- Ryan Alcorn, Joel Alfaro, Neil Gayeta
   File: ConferenceRoom.hpp
   Description: Class header for ConferenceRoom room.*/

#pragma once

#include "Room.hpp"

class ConferenceRoom : public Room {
public:
	int featureOne(Player*);
	int featureTwo(Player*);
	void setRoom();
};
