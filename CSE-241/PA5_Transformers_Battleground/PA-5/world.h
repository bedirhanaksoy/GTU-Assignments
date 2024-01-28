#ifndef WORLD_H
#define WORLD_H

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include "robot.h"                                                  // include robot.h and humanic.h
#include "humanic.h"
#include "optimusprime.h"                                           // include all type of robots
#include "bulldozer.h"
#include "roomba.h"
#include "robocop.h"

using namespace std;

namespace PA5
{
const int gridSize = 10;                                            // const grid size (10 for this case)

class World {
private:
    Robot* cells[gridSize][gridSize];                               // robot pointer array
    int size = gridSize;                                            // world size

public:
    World(int gridSize) : size(gridSize) {                          // constructor with grid size, sets every cell nullptr
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                cells[i][j] = nullptr;
            }
        }
    }
    void placeRobot(Robot* robot, int x, int y);                        // place robot to grid
    void removeRobot(int x, int y);                                     // removes robot from grid
    void moveRobot(int x, int y, int newX, int newY, World& grid);      // moves robot from a cell to given coordinates
    Robot* getRobot(int x, int y) const;                                // returuns robot pointer
    int getSize() const;                                                // returns size
    void displayGrid() const;                                           // displays grid
    void fight(Robot* attacker, Robot* victim, World& grid);            // fight loop
    void simulate(int count);                                           // simulation 

};
}
#endif
