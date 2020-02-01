#target:dependencies

project: main.cpp Item.cpp Item.hpp ResearchLab.cpp ResearchLab.hpp RadioRoom.cpp RadioRoom.hpp ToolShed.cpp ToolShed.hpp EquipmentRoom.cpp EquipmentRoom.hpp Galley.cpp Galley.hpp Hallway1.cpp Hallway1.hpp Latrine.cpp Latrine.hpp Macready.cpp Macready.hpp Room.hpp SickBay.hpp SickBay.cpp Drink.cpp Drink.hpp Parser.cpp Parser.hpp Smell.hpp Smell.cpp Talk.cpp Talk.hpp VerbEnum.hpp Verb.hpp gameEnd.cpp gameEnd.hpp help.cpp help.hpp intro.cpp intro.hpp map.cpp map.hpp menu.cpp menu.hpp Player.hpp Player.cpp

	g++ -std=c++0x main.cpp Item.cpp ResearchLab.cpp RadioRoom.cpp ToolShed.cpp EquipmentRoom.cpp Galley.cpp Hallway1.cpp Latrine.cpp Macready.cpp SickBay.cpp Drink.cpp Parser.cpp Smell.cpp Talk.cpp gameEnd.cpp help.cpp intro.cpp map.cpp menu.cpp Player.cpp -o project

clean:
	rm project
