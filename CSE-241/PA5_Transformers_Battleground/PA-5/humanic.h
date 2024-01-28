#ifndef HUMANIC_H
#define HUMANIC_H

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include "robot.h"                                  // include robot.h
using namespace std;

namespace PA5
{
    class Robot;                                    // forward declaration of Robot
        
    class Humanic : public Robot {                  // derivation of humanic from Robot
    public:
        Humanic(int newStrength, int newHitpoints, bool fight, string name) : Robot(newStrength, newHitpoints, fight,name) {}   // constructor with arguments
        string getType() override;         // returns type (didnt used)
        int getDamage() override;          // returns addition of default damage and humanic damage
    };

}
#endif