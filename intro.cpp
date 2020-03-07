#include <stdlib.h>

#include "intro.hpp"

void intro()
{
/*Read up on escape sequences to clear screen.https://stackoverflow.com/questions/4062045/clearing-terminal-in-linux-with-c-code*/
std::cout << "\033[2J\033[1;1H";

	std::cout << "\033[1;41m*******  *    *  ******      *******   *    *  *******  **    *  ******  *   *\033[0m\n";
	std::cout << "\033[1;41m   *     *    *  *             *       *    *     *     * *   *  *       *   *\033[0m\n";
	std::cout << "\033[1;41m   *     ******  ******        *       ******     *     *   * *  *   *** *****\033[0m\n";
	std::cout << "\033[1;41m   *     *    *  *             *       *    *     *     *    **  *    *    *  \033[0m\n";
	std::cout << "\033[1;41m   *     *    *  ******        *       *    *  *******  *     *  ******    *  \033[0m\n";
	std::cout << "Welcome to 'THE THINGY' a text-based horror/adventure game inspired by the John Carpenter film 'The Thing' from 1982." << std::endl;
	std::cout << "It's not inspired by the 2011 cash grab. " << std::endl;


	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Let the game begin..." << std::endl;
	std::cout << "________________________________________________________________________________________________________" << std::endl;


}
