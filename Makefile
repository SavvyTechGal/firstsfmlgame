output: main.o Window.o WorkingDirectory.o Bitmask.o Input.o Game.o
	g++ main.o Window.o WorkingDirectory.o Bitmask.o Input.o Game.o -o game-app -lsfml-graphics -lsfml-audio -lsfml-network -lsfml-window -lsfml-system
main.o: main.cpp
	g++ -c main.cpp

Window.o: Window.cpp Window.hpp
	g++ -c Window.cpp

WorkingDirectory.o: WorkingDirectory.cpp WorkingDirectory.hpp
	g++ -c WorkingDirectory.cpp

Bitmask.o: Bitmask.cpp Bitmask.hpp
	g++ -c Bitmask.cpp

Input.o: Input.cpp Input.hpp
	g++ -c Input.cpp

Game.o: Game.cpp Game.hpp
	g++ -c Game.cpp

clean:
	rm *.o game-app