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
#include "lookAtAction.hpp"
#include "look.hpp"
#include "useAction.hpp"
#include "dropAction.hpp"
#include "goAction.hpp"
*/



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
/*Function allows player to get long form explanation of the room again.*/
void look(Player &rj)
{
Room* currentPosition = rj.returnLocation();
std::string longDes = currentPosition->getLongDescrip();
std::cout << longDes<< std::endl;
}




int main()
{
//intro();
//menu();
//map();
//help();

	/*Creation of Objects*/
	Player rj;
	Macready macready;
//	Hallway1 hallway1;
//	SickBay sickbay;
//	Latrine latrine;
//	Galley galley;
		

	/*Pointers to Room objects*/
	Room* roomStarter = &macready;
	roomStarter->setRoom();		
	
	/*Note to self: need to call setRoom function to fill data members before calling functions*/
	Room* currentRoomPtr =&macready;
	rj.setLocation(currentRoomPtr);
	

std::string userInput;	
	
/*Loop starts*/
do {
/*Checks victory status at start of loop.*/
if (rj.getVictory() != 0)
{
gameEnd(rj);
}


//std::string roomName =currentRoomPtr->getName();
//std::cout << "Current Location: " <<roomName << std::endl;

//std::cout << "Room Description: ";
//currentRoomPtr->displayDescrip();

//std::cout << "Room Exits: " ;
//currentRoomPtr->displayExits();

/*input from user.  string*/
std::cout << "Enter choice now: " << std::endl;
std::cin >> userInput;


look(rj);
/*Call example: verbNoun[2]= parser(userInput)*/
/*Example: 'look for booze'.  parser needs to take out 'for'. so what is left is a command and noun.  do we want numbers or strings for return values? strings maybe be easier
 * for human reading and understanding. numbers may be an issue because then a dictonary has to be created and checked.*/

/*thoughts: limit command structure to one command and one noun.  items used in combination with each other could just have
 * an inventory check and then its all automated. Example: instead of 'use petri dish with blood sample and blowtorch' it could just be 'use petri dish' and then a check is done
 * for the other items..  */

/* */

/*call actionFunction.  send arguments: Player Object.*/


//Tests for setting victory and game ending
//rj.setVictory(1);
//rj.setGameEnd(1);


}while(userInput != "exit");

}

