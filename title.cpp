#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

#include "player.hpp"


/*Intro function.  Introduces the game and gives user a choice.*/
void intro();
void map();
/*A stand-in for the parser for testing.*/
void interpretString(std::string userInput, std::string verbNoun[]);

/*Function that takes array values and translates to action*/

/*Needs to check player object and room object for valid conditions
 * such as if MacReady is given the command to eat the redherring, but he doesn't have it,
 * the appropriate message needs to go out.  Same thing with the location.
 *
 *
 * */
void action(std::string verbNoun[], Player macready);

void help();

void help()
{
std::cout << "Game commands: " << std::endl;
std::cout << "attack, break, drink, drop, eat," << std::endl;
std::cout << "flee, go, help, inventory, jump," << std::endl;
std::cout <<"look, look at, smell, take, talk, use" << std::endl;
}

void map()
{
std::cout <<"			|-------|		|-----------------|		|--------------|	|--------|"<< std::endl;
std::cout <<"			|Latrine|		|MacReady Quarters|		|Equipment Room|--------|Toolshed|"<< std::endl;
std::cout <<"			|-------|		|-----------------|		|--------------|	|--------|" << std::endl;
std::cout <<"				|			|				|		" << std::endl;
std::cout <<"				|			|				|		" << std::endl;
std::cout <<"				|			|				|		" << std::endl;
std::cout <<"				|			|				|		" << std::endl;
std::cout <<"|--------|		|-----------------------------------------------------------------------------------|	   |----------|" << std::endl;
std::cout <<"|Sick Bay|--------------|--------------------------Hallway 1------------------------------------------------|------|Radio Room|" << std::endl;
std::cout <<"|--------|		|-----------------------------------------------------------------------------------|	   |----------|" << std::endl;
std::cout <<"				|			|				" <<std::endl;
std::cout <<"				|			|				" <<std::endl;
std::cout <<"				|			|				" <<std::endl;
std::cout <<"				|			|				" <<std::endl;
std::cout <<"			|------------|			|" <<std::endl;
std::cout <<"			|Research Lab|			|" <<std::endl;
std::cout <<"			|------------|			|" <<std::endl;
std::cout <<"							|" <<std::endl;
std::cout <<"							|" <<std::endl;
std::cout <<"|---------|	|------------------------------------------------------------------------------------|		|------|" <<std::endl;
std::cout <<"|Mess Hall|-----|-------------------------------Hallway 2--------------------------------------------|----------|Garage|" <<std::endl;
std::cout <<"|---------|	|------------------------------------------------------------------------------------|		|------|" <<std::endl;
std::cout <<"	|			|			|				|" <<std::endl;
std::cout <<"	|			|			|				|" <<std::endl;
std::cout <<"	|			|			|				|" <<std::endl;
std::cout <<"|-------|			|----------|		|--------|			|---------------|" <<std::endl;
std::cout <<"|Galley |			|Dog Kennel|		|Basement|			|Conference Room|" <<std::endl;
std::cout <<"|-------|			|----------|		|--------|			|---------------|" << std::endl;





}





void action(std::string verbNoun[], Player macready)
{






}








void interpretString(std::string userInput, int verbNoun[])
{
if (userInput == "eat")
	{
	verbNoun[0] = 1;	
	}		

verbNoun[1] = 9000;




}



void intro()
{
	int userChoice;

	std::cout << "__________________________________________________________________________________________________________________" << std::endl;

	std::cout << std::endl;
	std::cout << "	*******  *    *  ******      *******   *    *  *******  **    *  ******  *   *                                 " << std::endl;
	std::cout << "	   *     *    *  *     	       *       *    *     *     * *   *  *       *   *                                " << std::endl;
	std::cout << "	   *     ******  ******        *       ******     *     *   * *  *   *** *****                                " << std::endl;
	std::cout << "	   *     *    *  *             *       *    *     *     *    **  *    *    *                              " << std::endl;
	std::cout << "	   *     *    *  ******        *       *    *  *******  *     *  ******    *                                  " << std::endl;
	std::cout << "__________________________________________________________________________________________________________________" << std::endl;

	std::cout << "Welcome to 'THE THINGY' a text-based horror/adventure game inspired by the John Carpenter film 'The Thing' from 1982." << std::endl;
	std::cout << "It's not inspired by the 2011 cash grab. " << std::endl;

	std::cout << "1.  Play game! " << std::endl;
	std::cout << "2.  Quit " << std::endl;

	std::cin >> userChoice;

	do{ 
	if (userChoice == 1)
	{
		std::cout << "Let the games begin!" << std::endl;
		return;
	}

	if (userChoice ==2)
	{
		std::cout << "Sorry to see you go.  Have a nice day! " << std::endl;
		exit(0);
	}

	if(userChoice !=1 && userChoice !=2)
	{
	
		std::cout << "Not a valid choice.  Try again.  Enter 1 to play.  Enter 2 to quit." << std::endl;
		std::cin >> userChoice;
	}

	}while (1);
	
}


int main ()
{
intro();

std::cout << "Game starts here." << std::endl;
std::string userAction;


/*Create player object.*/
Player macready;
Player* playerPtr = &macready;

/*string to hold a verb and noun combo*/
std::string verbNoun [2][100];

map();
do {


std::cin >> userAction;


/*Evaluate userinputted string.  place verb into slot 1.  place noun into slot 2*/
//interpretString(userAction, verbNoun);

/*after string is placed into the array, call action function check conditions for action*/
/**/
//action(verbNoun, playerPtr);




/*Different condition needed at time of finalizaiton of the game.  For now just exit to end loop.*/
} while (userAction != "exit");





}

