#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

#include "map.hpp"
#include "intro.hpp"
#include "menu.hpp"
#include "help.hpp"

#include "player.hpp"
#include "Galley.hpp"
#include "Macready.hpp"

int main()
{
intro();
menu();
map();
help();

std::cout << "Game begins!" << std::endl;


	/*Objects*/
	Player jon;
	Macready macready;
	Galley galley;
	Item alcohol("Vodka", "unknown");
	
	Room* currentRoomPtr = &macready;

	jon.setGrit(alcohol);
	jon.getGrit();

	jon.setLocation(currentRoomPtr);

}
