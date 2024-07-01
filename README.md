## Author
- Bar Yechezkel
- Email: baryechezkel@gmail.com

# Catan Game Simulation

This project is a C++ implementation of a basic Catan game simulation. The game includes players, a board, and development cards. The main components are structured into different classes: `Player`, `Board`, and `Catan`.

## Table of Contents
- [Getting Started](#getting-started)
- [Prerequisites](#prerequisites)
- [Building the Project](#building-the-project)
- [Running the Game](#running-the-game)
- [Game Rules and Logic](#game-rules-and-logic)
- [File Descriptions](#file-descriptions)
- [Authors](#authors)

## Getting Started

These instructions will help you set up the project on your local machine.

### Prerequisites

- A C++ compiler supporting C++11 or later
- CMake (optional, but recommended for building)

### Building the Project

To build the project, follow these steps:

1. Clone the repository:
    ```sh
    git clone https://github.com/your-username/catan-game-simulation.git
    ```
2. Navigate to the project directory:
    ```sh
    cd catan-game-simulation
    ```
3. Compile the project using a C++ compiler:
    ```sh
    g++ main.cpp Catan.cpp Player.cpp Board.cpp -o catan-game
    ```
   Alternatively, if you are using CMake:
    ```sh
    mkdir build
    cd build
    cmake ..
    make
    ```

### Running the Game

To run the game, execute the compiled binary:

```sh
./catan-game
