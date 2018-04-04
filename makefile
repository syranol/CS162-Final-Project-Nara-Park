finalProject: main.o Character.o Player.o Monster.o Boss.o Game.o Space.o DeerPark.o SideMap.o TodaJi.o
	g++ main.o Character.o Player.o Monster.o Boss.o Game.o Space.o DeerPark.o SideMap.o TodaJi.o -std=c++11 -o finalProject

main.o: main.cpp
	g++ -c main.cpp -std=c++11

Character.o: Character.cpp Character.hpp
	g++ -c Character.cpp -std=c++11

Player.o: Player.cpp Player.hpp
	g++ -c Player.cpp -std=c++11

Monster.o: Monster.cpp Monster.hpp
	g++ -c Monster.cpp -std=c++11

Boss.o: Boss.cpp Boss.hpp
	g++ -c Boss.cpp -std=c++11

Space.o: Space.cpp Space.hpp
	g++ -c Space.cpp -std=c++11

DeerPark.o: DeerPark.cpp DeerPark.hpp
	g++ -c DeerPark.cpp -std=c++11

Game.o: Game.cpp Game.hpp
	g++ -c Game.cpp -std=c++11

SideMap.o: SideMap.hpp SideMap.cpp
	g++ -c SideMap.cpp -std=c++11

TodaJi.o: TodaJi.cpp TodaJi.hpp
	g++ -c TodaJi.cpp -std=c++11

clean:
	rm *.o finalProject
