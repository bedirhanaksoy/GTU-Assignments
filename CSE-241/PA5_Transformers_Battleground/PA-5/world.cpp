#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include "world.h"                                                          // include world.h

using namespace std;

namespace PA5
{
    void World::placeRobot(Robot* robot, int x, int y) {                    // place robot to grid
        cells[x][y] = robot;
    }

    void World::removeRobot(int x, int y) {                                 // remove robot from grid
        cells[x][y] = nullptr;
    }

    void World::moveRobot(int x, int y, int newX, int newY, World& grid) {  // moves robot in grid
    Robot* robot = grid.getRobot(x, y);
    grid.removeRobot(x, y);
    grid.placeRobot(robot, newX, newY);
}

    Robot* World::getRobot(int x, int y) const {                            // returns robot pointer from given coordinated
    return cells[x][y];
    }
        
    int World::getSize() const {                                            // returns size of the grid
        return size;
    }

    void World::displayGrid() const {                                       // displays grid
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                Robot* robot = cells[i][j];
                if (robot == nullptr) {
                    cout << ".";                                            // if cell is empty, prints dot
                } else {
                    cout << robot->getName()[0];                            // else prints first letter of their name
                }
            }
            cout << endl;
        }
    }

    void World::simulate(int count){                                        // simulation function
        string s;
        int flag = 0;
        int robotCount = count;

        while (robotCount > 1) {                                            // runs until one robot left
            //displayGrid();                                                  // displays grid at the beginning of each round
            cout << "Press Enter for the next round..." << endl;
            getline(cin,s);                                                 // wait user to enter any input
            
            for (int row = 0; row < gridSize; row++) {                      // searchs every cell of grid each round
                for (int col = 0; col < gridSize; col++) {
                    int i = row;
                    int j = col;
                    Robot* currentRobot = getRobot(i, j);                   // gets current robot to make operations more readable
                    if (currentRobot != nullptr && currentRobot->getHitpoints() > 0 && currentRobot->doesFought() == false) {   // checks current robots existence and fight condition
                        flag = 0;                                                                                               // flag for fight condition
                        while(robotCount>1 && currentRobot!=nullptr && flag == 0 && currentRobot->doesFought() == false){       // runs while current robots fight condition is false
                            
                            int dir = rand() % 4;                                                                               // finds random way each round
                            if (dir == 0 && i > 0) {                                                                            // south way option
                                Robot* adjacentRobot = getRobot(i - 1, j);
                                if (adjacentRobot != nullptr && currentRobot!=nullptr && adjacentRobot->doesFought()==false) {  // if cell is occupied, fights with it
                                    if(adjacentRobot->getHitpoints() > 0){                                                      // set fight condition true for current robot
                                    currentRobot->setFought(true);
                                    fight(currentRobot, adjacentRobot, *this);                                                  // calls fight function with these robots and this grid
                                    robotCount--;                                                                               // one robot must die every fight, so it decreases robot count one down
                                    flag = 1;                                                                                   // sets flag 1 
                                    }
                                }
                                else if ( adjacentRobot==nullptr){                                                              // if cell is empty, moves to that cell
                                    moveRobot(i,j,i-1,j,*this);
                                    i--;                                                                                    
                                    currentRobot= getRobot(i,j);                                                                // re-set current robot pointer 
                                }
                            }
                            else if (dir == 1 && i < gridSize - 1) {                                                            // north way option
                                Robot* adjacentRobot = getRobot(i + 1, j);
                                if (adjacentRobot != nullptr && currentRobot!=nullptr && adjacentRobot->doesFought()==false) {
                                    if(adjacentRobot->getHitpoints() > 0){
                                    currentRobot->setFought(true);
                                    fight(currentRobot, adjacentRobot,*this);
                                    robotCount--;
                                    flag = 1;
                                    }
                                }
                                else if (adjacentRobot==nullptr){
                                    moveRobot(i,j,i+1,j,*this);
                                    i++;
                                    currentRobot= getRobot(i,j);
                                }
                            }
                            else if (dir ==2 && j > 0) {                                                                        // west way option
                                Robot* adjacentRobot = getRobot(i, j - 1);
                                if (adjacentRobot != nullptr && currentRobot!=nullptr && adjacentRobot->doesFought()==false) {
                                    if( adjacentRobot->getHitpoints() > 0){
                                    currentRobot->setFought(true);
                                    fight(currentRobot, adjacentRobot,*this);
                                    robotCount--;
                                    flag = 1;
                                    }
                                }
                                else if(adjacentRobot == nullptr){
                                    moveRobot(i,j,i,j-1,*this);
                                    j--;
                                    currentRobot= getRobot(i,j);
                                }
                            }
                            else if(j < gridSize - 1) {                                                                         // east way option
                                Robot* adjacentRobot = getRobot(i, j + 1);
                                if (adjacentRobot != nullptr && currentRobot!=nullptr && adjacentRobot->doesFought()==false) {
                                    if(adjacentRobot->getHitpoints() > 0){
                                    currentRobot->setFought(true);
                                    fight(currentRobot, adjacentRobot,*this);
                                    robotCount--;
                                    flag = 1;
                                    }
                                }

                                else if (adjacentRobot == nullptr){
                                    moveRobot(i,j,i,j+1,*this);
                                    j++;
                                    currentRobot= getRobot(i,j);
                                }
                            }
                            int doesntFoughtCount = 0;
                            for (int i = 0; i < gridSize; i++) {                                                                // checks the only robot left which isn't moved situation
                                    for (int j = 0; j < gridSize; j++) {
                                        if (getRobot(i, j) != nullptr && getRobot(i, j)->getHitpoints() > 0 && getRobot(i,j)->doesFought()==false) {
                                            doesntFoughtCount++;    
                                        }
                                    }
                            }
                            
                            if(robotCount==1){                                                          // if one robot left, declares the winner and returns
                                for (int i = 0; i < gridSize; i++) {
                                    for (int j = 0; j < gridSize; j++) {
                                        if (getRobot(i, j) != nullptr && getRobot(i, j)->getHitpoints() > 0) {
                                            cout << "The winner is: " << getRobot(i, j)->getName() << "!" << endl<<endl;
                                            return;
                                        }
                                    }
                                }
                            }
                            if(doesntFoughtCount == 1) break; // if there is only one robot which doesnt moved, breaks this round
                        }                  
                    }
                }
            }

            for(int i = 0; i<gridSize;i++){                                                     // sets fight condition to false each round
                for(int j=0; j<gridSize;j++){
                    Robot* resetfights = getRobot(i,j);
                    if(resetfights!=nullptr && resetfights->getHitpoints()>0){
                        resetfights->setFought(false);
                    }
                }
            }
        }  
    }


    void World::fight(Robot* attacker, Robot* victim, World& grid) {            // fight function
        
        while(attacker!=nullptr && victim!=nullptr) {                           // runs until one robot dies
            int damage = attacker->getDamage();                                 // attacker gets damage value
            cout << attacker->getName() << "(" << attacker->getHitpoints() << ") hits " << victim->getName() << "(" << victim->getHitpoints() << ") with " << damage << endl;   // damage message
            
            victim->setHitpoints(victim->getHitpoints() - damage);              // victim sets new hitpoint
            cout << "The new hitpoints of " << victim->getName() << " is " << victim->getHitpoints() << endl; // new hitpoint message
            
            if (victim->getHitpoints() <= 0) {                                                                // if victim is dead, will be removed from grid
                cout << victim->getName() << " is dead!" << endl<<endl;                                       // dead message
                int size = grid.getSize();                                                                   
                for (int i = 0; i < size; i++) {
                    for (int j = 0; j < size; j++) {
                        if (grid.getRobot(i, j) == victim) {
                            grid.removeRobot(i, j);                                                          // remove robot from grid
                            victim = nullptr;                                                                // Set victim to nullptr to avoid accessing deleted object
                            return;
                        }
                    }
                    
                }
            }
            else{       // if victim is still alive                                                     
                if(attacker->getName()[0]=='r'){ // if attacker is a roomba, attacks again.
                    damage = attacker->getDamage();                                                         
                    cout << attacker->getName() << "(" << attacker->getHitpoints() << ") hits " << victim->getName() << "(" << victim->getHitpoints() << ") with " << damage << endl; 
                    
                    victim->setHitpoints(victim->getHitpoints() - damage); 
                    cout << "The new hitpoints of " << victim->getName() << " is " << victim->getHitpoints() << endl;
                    
                    if (victim->getHitpoints() <= 0) {
                        cout << victim->getName() << " is dead!" << endl<<endl;
                        
                        // Remove the dead robot from the grid
                        int size = grid.getSize();
                        for (int i = 0; i < size; i++) {
                            for (int j = 0; j < size; j++) {
                                if (grid.getRobot(i, j) == victim) {
                                    grid.removeRobot(i, j);
                                    //delete victim;
                                    victim = nullptr; // Set victim to nullptr to avoid accessing deleted object
                                    return;
                                }
                            }
                            
                        }
                    }
                }
                damage = victim->getDamage(); //victim gets damage value 
                cout << victim->getName() << "(" << victim->getHitpoints() << ") hits " << attacker->getName() << "(" << attacker->getHitpoints() << ") with " << damage << endl;//damage message
                
                attacker->setHitpoints(attacker->getHitpoints() - damage);  // attacker sets new hitpoint
                cout << "The new hitpoints of " << attacker->getName() << " is " << attacker->getHitpoints() << endl;
                
                if (attacker->getHitpoints() <= 0) {                                // if attacker is dead
                    cout << attacker->getName() << " is dead!" << endl<<endl;       // dead message
                    
                    
                    int size = grid.getSize();
                    for (int i = 0; i < size; i++) {
                        for (int j = 0; j < size; j++) {
                            if (grid.getRobot(i, j) == attacker) {
                                grid.removeRobot(i, j);                             // remove the dead robot from the grid
                                attacker = nullptr;                                 // set victim to nullptr to avoid accessing deleted object
                                return;
                            }
                        }
                        
                    }
                }
                if(victim->getName()[0]=='r' && attacker!=nullptr){                                      // if victim is a roomba and attacker is still alive, victim attacks again
                    damage = victim->getDamage();
                    cout << victim->getName() << "(" << victim->getHitpoints() << ") hits " << attacker->getName() << "(" << attacker->getHitpoints() << ") with " << damage << endl;
                    
                    attacker->setHitpoints(attacker->getHitpoints() - damage);
                    cout << "The new hitpoints of " << attacker->getName() << " is " << attacker->getHitpoints() << endl;
                    
                    if (attacker->getHitpoints() <= 0) {
                        cout << attacker->getName() << " is dead!" << endl<<endl;
                        
                        // Remove the dead robot from the grid
                        int size = grid.getSize();
                        for (int i = 0; i < size; i++) {
                            for (int j = 0; j < size; j++) {
                                if (grid.getRobot(i, j) == attacker) {
                                    grid.removeRobot(i, j);
                                    //delete attacker;
                                    
                                    attacker = nullptr; // Set victim to nullptr to avoid accessing deleted object
                                    return;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

