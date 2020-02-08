#target:dependencies

project: *.cpp *.hpp Verbs/*.hpp Verbs/*.cpp Rooms/*.hpp Rooms/*.cpp

	g++ -std=c++0x -w *.cpp Verbs/*.cpp Rooms/*.cpp -o project

clean:
	rm project
