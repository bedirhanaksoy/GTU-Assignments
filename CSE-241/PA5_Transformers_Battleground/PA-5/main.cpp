#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include "world.h"                              // include world.h
#include "robot.h"                              // include robot.h
#include "humanic.h"                            // include humanic.h
#include "optimusprime.h"                       // include optimusprime.h
#include "robocop.h"                            // include robocop.h
#include "roomba.h"                             // include roomba.h
#include "bulldozer.h"                          // include bulldozer.h

using namespace std;
using namespace PA5;                            // using namespace PA5 which created in cpp and header files

int main() {
    srand(time(0));                                                                                 // randomize time
    const int initialCountOfEachRobotType = 5;                                                      // initial count of each robot type
    World grid(gridSize);                                                                           // world object declaration
    

    int robotCount = 0;
    int totalRobotCount=0;                                                                          // total number of robots
    int flag =0;
    int i=0;                                                                                        // number of robot type
    while(robotCount < initialCountOfEachRobotType){                                                // runs until each robot placed properly
        std::string basename = "OptimusPrime";                                                      // base name 
        int x = rand() % gridSize;                                                                  // randomize the initial x coordinate
        int y = rand() % gridSize;                                                                  // randomize the initial y coordinate
        if(grid.getRobot(x, y) == NULL){                                                            // if coordinate is null, object will be created on this coordinate
            i++;                                                                                    
            std::string name = basename + "_" + std::to_string(i);                                  // adds number of robot to at the end of the basename 
            robotCount++;
            totalRobotCount++;
            grid.placeRobot(new OptimusPrime(name),x,y);                                            // place robot to empty cell
        }
    }
                                                                                     
    i=0;                                                                                            // reset number of robot type
    robotCount=0;
    while(robotCount < initialCountOfEachRobotType){                                                // runs until each robot placed properly 
        std::string basename = "Robocop";                                                           // base name
        int x = rand() % gridSize;                                                                  // randomize the initial x coordinate
        int y = rand() % gridSize;                                                                  // randomize the initial y coordinate
        if(grid.getRobot(x, y) == NULL){                                                            // if coordinate is null, object will be created on this coordinate
            i++;                                                                                        
            std::string name = basename + "_" + std::to_string(i);                                  // adds number of robot to at the end of the basename                 
            robotCount++;               
            totalRobotCount++;                                                                
            grid.placeRobot(new RoboCop(name),x,y);                                                 // place robot to empty cell                    
        }
    }
    i=0;                                                                                            // reset number of robot type
    robotCount=0;
    while(robotCount < initialCountOfEachRobotType){                                                // runs until each robot placed properly
        std::string basename = "Bulldozer";                                                         // base name
        int x = rand() % gridSize;                                                                  // randomize the initial x coordinate
        int y = rand() % gridSize;                                                                  // randomize the initial y coordinate
        if(grid.getRobot(x, y) == NULL){                                                            // if coordinate is null, object will be created on this coordinate
            i++;
            std::string name = basename + "_" + std::to_string(i);                                  // adds number of robot to at the end of the basename
            robotCount++;
            totalRobotCount++;
            grid.placeRobot(new Bulldozer(name),x,y);                                               // place robot to empty cell
        }
    }
    robotCount=0;
    i=0;                                                                                            // reset number of robot type
    while(robotCount < initialCountOfEachRobotType){                                                // runs until each robot placed properly
        std::string basename = "roomba";                                                            // base name
        int x = rand() % gridSize;                                                                  // randomize the initial x coordinate
        int y = rand() % gridSize;                                                                  // randomize the initial y coordinate
        if(grid.getRobot(x, y) == NULL){                                                            // if coordinate is null, object will be created on this coordinate
            i++;
            std::string name = basename + "_" + std::to_string(i);                                  // adds number of robot to at the end of the basename
            robotCount++;
            totalRobotCount++;
            grid.placeRobot(new Roomba(name),x,y);                                                  // place robot to empty cell
        }
    }                                                                                
    grid.simulate(totalRobotCount);                                                                 // simulate the grid
    return 0;
}
