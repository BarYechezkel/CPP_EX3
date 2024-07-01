

CXX = clang++

.PHONY: all clean

all: catan

catan: main.o Catan.o Tile.o Player.o Board.o Vertex.o Edge.o Knight.o RoadBuilding.o Monopoly.o YearOfPlenty.o VictoryPoint.o
	$(CXX) -o $@ $^

main.o: main.cpp Catan.hpp
	$(CXX) -c -o $@ main.cpp

Catan.o: Catan.cpp
	$(CXX) -c -o $@ $<
	
Player.o: Player.cpp Player.hpp
	$(CXX) -c -o $@ $<			

Board.o: Board.cpp Board.hpp
	$(CXX) -c -o $@ $<

Tile.o: Tile.cpp Tile.hpp
	$(CXX) -c -o $@ $<

Vertex.o: Vertex.cpp Vertex.hpp
	$(CXX) -c -o $@ $<

Edge.o: Edge.cpp Edge.hpp
	$(CXX) -c -o $@ $<

Knight.o: Knight.cpp Knight.hpp
	$(CXX) -c -o $@ $<

RoadBuilding.o: RoadBuilding.cpp RoadBuilding.hpp
	$(CXX) -c -o $@ $<

Monopoly.o: Monopoly.cpp Monopoly.hpp
	$(CXX) -c -o $@ $<

YearOfPlenty.o: YearOfPlenty.cpp YearOfPlenty.hpp
	$(CXX) -c -o $@ $<

VictoryPoint.o: VictoryPoint.cpp VictoryPoint.hpp
	$(CXX) -c -o $@ $<

	
Test.o: Test.cpp
	$(CXX) -c -o $@ $<

test: Test.o Catan.o Tile.o Player.o Board.o Vertex.o Edge.o Knight.o RoadBuilding.o Monopoly.o YearOfPlenty.o VictoryPoint.o
	$(CXX) -o test $^
	./test


clean:
	 rm -f catan test *.o