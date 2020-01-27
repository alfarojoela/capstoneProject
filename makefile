#target:dependencies


project: main.cpp menu.cpp intro.cpp map.cpp help.cpp player.cpp Galley.cpp Macready.cpp Item.cpp menu.hpp intro.hpp map.hpp help.hpp player.hpp Room.hpp Galley.hpp Macready.hpp Item.hpp 
	g++ -std=c++0x main.cpp menu.cpp intro.cpp map.cpp help.cpp player.cpp Galley.cpp Macready.cpp Item.cpp -o project

clean:
	rm project
