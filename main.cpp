#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

/*Functions accessed by main*/
#include "map.hpp"
#include "intro.hpp"
#include "menu.hpp"
#include "help.hpp"
#include "gameEnd.hpp"

/*action functions after parser translation*/
/*
 * #include "lookAtAction.hpp"
 * #include "look.hpp"
 * #include "useAction.hpp"
 * #include "dropAction.hpp"
 * #include "goAction.hpp"
 * */



/*Player class.  Player object keeps game status such as grit level, victory, death, etc.*/
#include "Player.hpp"

/*Room class*/
#include "Galley.hpp"
#include "Macready.hpp"
#include "Hallway1.hpp"
#include "SickBay.hpp"
#include "Latrine.hpp"

/*Parser class*/
#include "Drink.hpp"
#include "Smell.hpp"
#include "Talk.hpp"
#include "VerbEnum.hpp"
#include "Verb.hpp"

/*REFACTOR FUNCTION LATER*/

/*discard this function.  only a test*/
void joelsbadParser(std::string userInput, std::string (&commands) [3])
{
	if (userInput=="look for booze")
	{
		commands[0] = "look";
		commands[1] = "for";
		commands[1] = "booze";
	}

	if (userInput=="use the computer")
	{
		commands[0] = "use";
		commands[1] = "the";
		commands[2] = "computer";
	}

	if (userInput=="go to hallway")
	{
		commands[0] = "go";
		commands[1] = "to";
		commands[2] = "hallway";
	}

	if (userInput == "look at bed")
	{
		commands[0] = "look";
		commands[1] = "at";
		commands[2] = "bed";
	}
}

void chooseActionMacready(std::string commands[3], Room* playerLocation, Player& rj, Hallway1 &hallway1)
{
	std::cout << "In chooseActionMacready function: " << std::endl;

	std::vector<Item*> rjInventory;


	/*Macready room*/
	if (commands[0] == "look" )
	{
		playerLocation->getLongDescrip();
	}


	if (commands[0] == "look" && commands[1] == "for" && commands[2] == "booze")
	{
		if (playerLocation->getFeatureOneHap() == 1)
		{
			std::cout << "You already checked under the bed and the room.  No booze.  Drat!" << std::endl;
			return;
		}

		if (playerLocation->getFeatureOneHap() == 0)
		{
			playerLocation->featureOne(rjInventory);
			return;
		}
	}

	if (commands[0] == "look" && commands[1] == "at" && commands[2] == "bed")
	{
		std::cout << "The bed is in disarray.  MacReady's quarters are a pig sty." << std::endl;
	}

	if (commands[0] == "look" && commands[1] == "at" && commands[2] == "computer")
	{
		std::cout << "It's a state of the art Commodore 64." << std::endl;
		std::cout << "The CPU is 1.023 MHz!" << std::endl;
		std::cout << "The memory is 64 KB of RAM!" << std::endl;
		std::cout << "This must have set MacReady back by $519.00" << std::endl;
		std::cout << "He is quite the spender." << std::endl;

	}

	if (commands[0] == "use" && commands[1] == "computer")
	{
		if (playerLocation->getFeatureTwoHap()==1)
		{
			std::cout << "You already played with the computer." << std::endl;
			return;
		}

		if (playerLocation->getFeatureTwoHap() == 0)
		{
			playerLocation->featureTwo(rjInventory);
			return;
		}
	}

	if (commands[0] == "go" && commands[1] == "hallway")
	{
		playerLocation = &hallway1;
		std::cout << "You go out to the hallway" << std::endl;
		return;
	}

	if ((commands[0] != "look" && commands[1] != "booze") || 
		(commands[0] != "use" && commands[1] != "computer") || 
		(commands[0] != "go" && commands[1] != "hallway") || (commands[0] != "look" && commands[1] != "at"))
	{
		std::cout << "You can't do that here." << std::endl;
	}
}

int main()
{
intro();
menu();
map();
help();

	/*Creation of Objects*/
	Player rj;
	Macready macready;
	Hallway1 hallway1;
	SickBay sickbay;
	Latrine latrine;
	Galley galley;



	/*Note to self: need to call setRoom function to fill data members before calling functions*/
	/*Alternative to using new command and perhaps preventing memory leaks*/

Room* roomStarter = &macready;
roomStarter->setRoom();

roomStarter = &hallway1;
roomStarter->setRoom();

roomStarter = &sickbay;
roomStarter->setRoom();

roomStarter = &latrine;
roomStarter->setRoom();

roomStarter = &galley;
roomStarter->setRoom();


Room* playerLocation = &macready;

std::string commands[3];
std::string userInput;	

	
/*Loop starts*/
//do {
/*Checks victory status at start of loop.*/
if (rj.getVictory() != 0)
{
gameEnd(rj);
}
playerLocation->displayDescrip();
playerLocation->displayExits();

std::cout << "What do you want to do?" << std::endl;
std::cin >> userInput;

joelsbadParser(userInput, commands);

/*Might refactor the code into separate function files.*/
if (playerLocation->getName() == "macready")
{
	chooseActionMacready(commands, playerLocation, rj, hallway1);
}

if (playerLocation->getName() == "hallway")
{
	/*chooseActionMacready(commands, playerLocation, rj, hallway1);*/
}




//}while(userInput != "exit");

}


