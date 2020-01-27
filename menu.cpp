#include "menu.hpp"

void menu()
{
	int userChoice;


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


