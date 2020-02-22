/* Project Name: Capstone Project
   Class: CS 467
   Team: Team Thing- Ryan Alcorn, Joel Alfaro, Neil Gayeta
   File: ToolShed.hpp
   Description: Class header for ToolShed room.*/

#pragma once

#include "Room.hpp"

class ToolShed : public Room {
public:
	int featureOne(Player*);
	int featureTwo(Player*);
	void setRoom();
    	void obtainRope(Player*);
    	void weaponAttack(Player*);
};
