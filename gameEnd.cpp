#include "gameEnd.hpp"

void gameEnd(Player &rj )
{
	if(rj.getGameEnd() ==1)
	{
	std::cout << "A noble sacrifice.  Nuking the facility from orbit just to be safe ended up killing The Thingy.  And you and everyone else at the facility.  But at least you saved the world." << std::endl;
	exit(0);
	}


	if(rj.getGameEnd() ==2)
	{
	std::cout << "Congratulations!  You really showed The Thingy who the boss is.  They'll think twice about trying to invade Earth." <<std::endl;
	std::cout << "Thanks for playing." << std::endl;
	exit(0);
	}
}


