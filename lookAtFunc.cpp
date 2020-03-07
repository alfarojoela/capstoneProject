#include "lookAtFunc.hpp"

/*lookAt function.  Allows player to look at items in player inventory or room inventory*/
/*Does a check of both inventories to see if item is in inventory.  if it is, matches condition to print out a description.*/
void lookAt(std::string commands[3], Room* &playerLocation, Player* &playerPtr, std::vector<Room*> &roomList, int roomNumber)
{
	std::string item = commands[2];

	if (commands[2] == "sardines" || commands[2] == "redherring")
	{
		item = "red herring";
		std::cout << "You were mistaken.\nIt's a can of Red Herring." << std::endl;
	}


	if (playerPtr->checkInventory(item) == 1 || playerLocation->checkItem(item) != 999)
	{
		if (item == "blowtorch")
		{
			std::cout << "The blow torch can be used for applying flame to things.  It is almost full." << std::endl;
			return;
		}

		if (item == "petri dish")
		{
			std::cout << "It's a plastic dish with a lid." << std::endl;
			std::cout << "You could use it to collect specimens like blood for instance." << std::endl;
			return;
		}

		if (item == "copper wire")
		{
			std::cout << "You have a small spool of copper wire." << std::endl;
			std::cout << "It looks like you could apply flame to it.  And then you could use the wire to apply heat to things." << std::endl;
			return;
		}

		if (item == "blood sample")
		{
			std::cout << "You hold the blood sample up to the light." << std::endl;
			std::cout << "It looks like ordinary human blood, but is it?" << std::endl;
			std::cout << "Maybe there is some kind of test." << std::endl;
			return;
		}

		if (item == "flamethrower")
		{
			std::cout << "You wouldn't want to be on the wrong side of this thing.  It's nearly full.  It has a range of 110 feet." << std::endl;
			std::cout << "It is in fine operating condition." << std::endl;
			return;
		}

		if (item == "gun")
		{
			std::cout << "You aren't quite sure why a gun would be needed at this facility." << std::endl;
			std::cout << "Maybe some people on the team use it to shoot penguins?" << std::endl;
			std::cout << "Whatever reason it's here, you feel a little bit safer with it." << std::endl;
			return;
		}

		if (item == "rope")
		{
			std::cout << "The rope is quite strong and should be able to take a lot of stress." << std::endl;
			return;
		}

		if (item == "scalpel")
		{
			std::cout << "The scalpel's handle fits within your hand.  The bladed end gleams in the light." << std::endl;
			std::cout << "This definitely can be used to cut." << std::endl;
			return;
		}

		if (item == "toilet paper")
		{
			std::cout << "You have the code that someone wrote on the toilet paper: 5932." << std::endl;
			return;
		}

		if ((item == "redherring") || (commands[2] =="red herring") || (commands[2] =="sardines"))
		{
			std::cout << "It is a dented can of red herring.  It looks like it should be edible." << std::endl;
			return;
		}

		if (item == "axe")
		{
			std::cout << "It is a fireaxe in case of emergencies.  It looks sturdy enough to break through doors, barriers, and debris if necessary." << std::endl;
			return;
		}

		if (item == "statue")
		{
			std::cout << "It's a minature of Auguste Rodin's 'The Thinker.' " << std::endl;
			return;
		}

		if (item == "vodka")
		{
			std::cout << "Someone got to this bottle before you did.  There are a few swigs left.  Looking at the clear contents, makes you feel a little thirsty." << std::endl;
			return;
		}

		if (item == "gin")
		{
			std::cout << "You shake the blue bottle.  There is maybe a single serving left of the gin." << std::endl;
			return;
		}

		if (item == "whiskey")
		{
			std::cout << "It's a single malt whiskey.  Aged to perfection in oak casks." << std::endl;
			return;
		}

		if (item == "tequila")
		{
			std::cout << "The tequila is in a strange bottle that resembles a skull.  It looks like a fancy brand.  The label assures smoothness with notes of fruit." << std::endl;
			return;
		}

		if (item == "beer")
		{
			std::cout << "You inspect the bottle of beer.  The bottle is green so you expect a skunky one." << std::endl;
			return;
		}

		if (item == "pabst")
		{
			std::cout << "It's an aluminum can of beer.  The label reads, 'Pabst.'  Your stomach turns at the thought of swilling this down." << std::endl;
			return;
		}

		if (item == "matarata")
		{
			std::cout << "This homemade tequila's container is a plastic gallon jug that looks like it was previously used to keep either distilled water or milk in.  The jug is completely full." << std::endl;
			std::cout << "No one has bothered to touch this yet which makes it immediately suspect." << std::endl;
			return;
		}

		if (item == "red herring")
		{
			std::cout << "It is a dented can of red herring.  It looks like it should be edible." << std::endl;
			return;
		}
	}

	else
	{
		std::cout << "You can't examine that item.  The " << item << " is not in your inventory." << std::endl;
		return;
	}
}


