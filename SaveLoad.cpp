#include "SaveLoad.hpp"

//Function saves the data present for each room and the player's data
void SaveLoad::save(Player* user, std::vector<Room*> rooms, std::string locationName)
{
	int playerGrit = 0;
	int alive = 0;
	int victory = 0;
	int gameEnd = 0;
	int bearings = 0;
	int deathWish = 0;
	Room* newRoom;
	Item* newItem;
	//Opens a stream to save the file.
	std::ofstream saveFile("thingSave.txt");

	saveFile << locationName << "\n";

	//Saves the fields of the Player object
	playerGrit = user->getGrit();
	saveFile << playerGrit << "\n";
	alive = user->getAlive();
	saveFile << alive << "\n";
	victory = user->getVictory();
	saveFile << victory << "\n";
	gameEnd = user->getGameEnd();
	saveFile << gameEnd << "\n";
	bearings = user->getBearings();
	saveFile << bearings << "\n";
	deathWish = user->getDeathWish();
	saveFile << deathWish << "\n";

	//Writes the user's inventory into the file if there are items in the inventory. Else, writes a line to help parse the data later.
	if (user->inventoryNumber() > 0)
	{
		for (int i = 0; i < user->inventoryNumber(); ++i)
		{
			newItem = user->returnItem(i);
			saveFile << newItem->getName() << "\n";
		}
		saveFile << "playerInt\n";
	}
	else
	{
		saveFile << "playerInt\n";
	}

	//Writes the name of the items in each room and the room name to the file if the room has items.
	for (int i = 0; i < 15; ++i)
	{
		newRoom = rooms[i];
		saveFile << newRoom->getName() << "\n";
		saveFile << newRoom->getFeatureOneHap() << "\n";
		saveFile << newRoom->getFeatureTwoHap() << "\n";
		saveFile << newRoom->getRoomEntered() << "\n";

		if (newRoom->numOfItems() > 0)
		{
			for (int j = 0; j < newRoom->numOfItems(); ++j)
			{
				newItem = newRoom->returnItem(j);

				saveFile << newItem->getName() << "\n";
			}
		}
		//Writes a line to help parse the data later.
		saveFile << "stop\n";
	}

	//Closes the save file.
	saveFile.close();
}

//Function clears the room and player information and loads data from the file.
Room* SaveLoad::load(Player* user, std::vector<Room*> rooms)
{
	int counter = 1;
	int playerIntEnd = 0;
	int roomBegin = 0;
	int featureOne = 0;
	int featureTwo = 0;
	int roomEntered = 0;
	int roomCounter = 0;
	Room* newRoom;
	Room* playerLocation = NULL;
	std::string line = "";
	//Opens a stream to read data from the file
	std::ifstream loadFile("thingSave.txt");

	std::cout << std::endl;
	std::cout << "Pre-clearing: " << std::endl;
	//Prints out the user inventory and room information
	std::cout << "Grit: " << user->getGrit() << "     Alive: " << user->getAlive() << "     Victory: " << user->getVictory() << 
		"     GameEnd: " << user->getGameEnd() << "     bearings: " << user->getBearings() << "     deathwish: " << user->getDeathWish() << std::endl;
	user->getInventory();
	std::cout << std::endl;
	for (int i = 0; i < 15; ++i)
	{
		newRoom = rooms[i];

		std::cout << newRoom->getName() << " " << newRoom->getFeatureOneHap() << " " << newRoom->getFeatureTwoHap() << " " << newRoom->getRoomEntered() << std::endl;
		newRoom->itemsInRoom();
	}

	//Changes the player's stats for testing
	user->setGritSave(10);
	user->setAlive(2);
	user->setVictory(2);
	user->setGameEnd(1);
	user->setBearings(0);
	user->setDeathWish(5);

	//Clears the user inventory and resets the room's data besides descriptions and names
	user->clearInventory();
	for (int i = 0; i < 15; ++i)
	{
		newRoom = rooms[i];

		newRoom->clearInventory();
		newRoom->setRoom();
	}

	std::cout << std::endl;
	std::cout << "After clear of inventories but before loading. Player stats are changed: " << std::endl;
	std::cout << "Grit: " << user->getGrit() << "     Alive: " << user->getAlive() << "     Victory: " << user->getVictory() <<
		"     GameEnd: " << user->getGameEnd() << "     bearings: " << user->getBearings() << "     deathwish: " << user->getDeathWish() << std::endl;
	//Prints out the user inventory and room information
	user->getInventory();
	std::cout << std::endl;
	for (int i = 0; i < 15; ++i)
	{
		newRoom = rooms[i];

		std::cout << newRoom->getName() << " " << newRoom->getFeatureOneHap() << " " << newRoom->getFeatureTwoHap() << " " << newRoom->getRoomEntered() << std::endl;
		newRoom->itemsInRoom();
	}

	//Runs through the lines in the file.
	if (loadFile.is_open())
	{
		while (loadFile)
		{
			getline(loadFile, line);

			//A counter determines which variable is to be set. The first line is the player's location. The next six are the player's stats.
			if (counter == 1)
			{
				for (int i = 0; i < rooms.size(); ++i)
				{
					if (rooms[i]->getName() == line)
					{
						playerLocation = rooms[i];
					}
				}
			}
			if (counter == 2)
			{
				user->setGritSave(stoi(line));
			}
			else if (counter == 3)
			{
				user->setAlive(stoi(line));
			}
			else if (counter == 4)
			{
				user->setVictory(stoi(line));
			}
			else if (counter == 5)
			{
				user->setGameEnd(stoi(line));
			}
			else if (counter == 6)
			{
				user->setBearings(stoi(line));
			}
			else if (counter == 7)
			{
				user->setDeathWish((stoi(line) - user->getDeathWish()));
			}
			/* Lines after line 7 there could be items that were in the player's inventory. The while loop will add items into the player's inventory until it reaches the
			* line that says playerInt. A counter will then be incremented. */
			else if (counter > 7)
			{
				if (line != "playerInt" && playerIntEnd == 0)
				{
					Item* newItem = new Item(line);
					user->setInventory(*newItem);
				}
				else if (line == "playerInt")
				{
					++playerIntEnd;
				}
				/* Counters determine where the data being read is to be added. The first line is the room name which starts the cycle. 
				* Then the first feature, second feature, room Entered variable are added to the current room. 
				* The rest of the lines will be added to the room's inventory until the line "stop" is reached. 
				* After that every counter will reset to zero and the roomCounter will increment to the next index in the rooms vector to begin adding data
				* to the next room. */
				else
				{
					if (line == "galley" || line == "macready" || line == "hallway1" || line == "hallway2" || line == "latrine" ||
						line == "sickBay" || line == "researchLab" || line == "equipment room" || line == "tool shed" || line == "radioRoom" ||
						line == "messHall" || line == "dogKennel" || line == "basement" || line == "garage" || line == "conferenceRoom")
					{
						roomBegin = 1;
					}
					else if (roomBegin == 1 && featureOne == 0 && featureTwo == 0 && roomEntered == 0)
					{
						rooms[roomCounter]->setFeatureOne(stoi(line));
						++featureOne;
					}
					else if (roomBegin == 1 && featureOne == 1 && featureTwo == 0 && roomEntered == 0)
					{
						rooms[roomCounter]->setFeatureTwo(stoi(line));
						++featureTwo;
					}
					else if (roomBegin == 1 && featureOne == 1 && featureTwo == 1 && roomEntered == 0)
					{
						rooms[roomCounter]->setRoomEntered(stoi(line));
						++roomEntered;
					}
					else if (roomBegin == 1 && featureOne == 1 && featureTwo == 1 && roomEntered == 1 && line != "stop")
					{
						rooms[roomCounter]->addItem(line);
					}
					else if (roomBegin == 1 && featureOne == 1 && featureTwo == 1 && roomEntered == 1 && line == "stop")
					{
						++roomCounter;
						roomBegin = 0;
						featureOne = 0;
						featureTwo = 0;
						roomEntered = 0;
					}
				}
			}
			++counter;
		}
	}

	std::cout << std::endl;
	std::cout << "After loading the file: " << std::endl;
	std::cout << "Grit: " << user->getGrit() << "     Alive: " << user->getAlive() << "     Victory: " << user->getVictory() <<
		"     GameEnd: " << user->getGameEnd() << "     bearings: " << user->getBearings() << "     deathwish: " << user->getDeathWish() << std::endl;
	//Prints out the user inventory and room information
	user->getInventory();
	std::cout << std::endl;
	for (int i = 0; i < 15; ++i)
	{
		newRoom = rooms[i];

		std::cout << newRoom->getName() << " " << newRoom->getFeatureOneHap() << " " << newRoom->getFeatureTwoHap() << " " << newRoom->getRoomEntered() << std::endl;
		newRoom->itemsInRoom();
	}

	loadFile.close();

	return playerLocation;
}
