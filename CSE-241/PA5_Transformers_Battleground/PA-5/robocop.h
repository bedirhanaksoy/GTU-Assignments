#ifndef ROBOCOP
#define ROBOCOP

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include "robot.h"                                              // include robot.h
#include "humanic.h"                                            // inclde humanic.h

using namespace std;
namespace PA5
{
    class Humanic;                                              // forward declaration of humanic class
    class RoboCop : public Humanic {                            // derivation of robocop class from humanic class
    public:
        RoboCop() : Humanic(30, 40,false,"robocop") {}          // default constructor
        RoboCop(string name) : Humanic(30,40,false,name){}      // constructor with name argument

        string getType() override;                              // returns type 
        string getName();                                       // returns name
        int getDamage() override;                               // returns damage
    };
}

#endif