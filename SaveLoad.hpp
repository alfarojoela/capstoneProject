#pragma once

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "Room.hpp"
#include "Player.hpp"
#include "Item.hpp"

class SaveLoad {
public:
	void save(Player*, std::vector<Room*>, std::string);
	Room* load(Player*, std::vector<Room*>);
};
