# # Define the C++ compiler to use
# CC = g++

# # Define any compile-time flags
# CFLAGS = -Wall -g

# # Define the target file (the executable)
# TARGET = Catan

# # Define the C++ source files
# SRCS = Catan.cpp Vertex.cpp Edge.cpp Tile.cpp Player.cpp Board.cpp

# all: $(TARGET)

# $(TARGET): $(SRCS)
# 	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

# clean:
# 	$(RM) $(TARGET)



CXX = clang++

.PHONY: all clean

all: main

main: main.o Catan.o Tile.o Player.o Board.o Vertex.o Edge.o 
	$(CXX) -o $@ $^

main.o: main.cpp Catan.hpp
	$(CXX) -c -o $@ $<

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

clean:
	 rm -f main *.o