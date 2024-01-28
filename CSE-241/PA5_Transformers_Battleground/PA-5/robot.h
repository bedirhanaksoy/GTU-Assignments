#ifndef ROBOT_H
#define ROBOT_H

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

namespace PA5
{
    class Robot {
private:
    int strength;                           // strenght of robot
    int hitpoints;                          // hitpoint of robot
    string name;                            // name of robot
    bool fighted;                           // fight condition of robot

public:
    Robot(int newStrength, int newHitpoints,bool fight,string name) : strength(newStrength), hitpoints(newHitpoints), fighted(fight), name(name) {} // constructor with arguments
    int getStrength() const;                                    // returns strenght of robot
    int getHitpoints() const;                                   // returns hitpoint of robot
    virtual void setHitpoints(int newHitpoints);                // sets hitpoint of robot
    virtual string getType();                                   // returns type of robot
    virtual string getName();                                   // returns specific name of each robot (optimusprime_1 , robocop_5 , ...)
    virtual int getDamage();                                    // returns default damage of robot
    virtual bool doesFought();                                  // returns fight condition
    virtual void setFought(bool condition);                     // sets fight condition
};


}
#endif