#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include "robot.h"                                                              // include robot.h


using namespace std;

namespace PA5
{
    int Robot::getStrength() const {                                            // returns strenght of robot
        return strength;
    }

    int Robot::getHitpoints() const {                                           // returns hitpoint of robot
        return hitpoints;
    }
    void Robot::setHitpoints(int newHitpoints) {                                // sets new hitpoint of robot object
        hitpoints = newHitpoints;
    }

    string Robot::getType(){                                                    
        return "Robot";
    }
    string Robot::getName() {                                                   // returns robots name
        return name;
    }  
    int Robot::getDamage() {                                                    // returns default damage
        int damage = rand() % strength + 1;
        cout << getName() << " attacks for " << damage << " points!" << endl;
        return damage;
    }
    bool Robot::doesFought(){                                                   // returns fight condition true or false
        return fighted;
    }
    void Robot::setFought(bool condition){                                      // sets fight condition true or false
        fighted = condition;
    }


}