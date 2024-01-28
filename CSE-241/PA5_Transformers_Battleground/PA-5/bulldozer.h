#ifndef BULLDOZER
#define BULLDOZER

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include "robot.h"                                          // include robot.h
using namespace std;

namespace PA5
{
    class Robot;                                            // forward declaration of Robot class

    class Bulldozer : public Robot {                        // derivation of bulldozer class from robot class
    public:
        Bulldozer() : Robot(50, 200,false,"bulldozer") {}   // default constructor for bulldozer
        Bulldozer(string name) : Robot(50,200,false,name){} // constructor with name argument

        string getType()override;                           // returns type 
        string getName()override;                           // returns name (bulldozer_0 , bulldozer_1 , ...)
        int getDamage()override;                            // returns damage 
    };

}

#endif