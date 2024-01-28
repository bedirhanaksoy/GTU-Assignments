#ifndef ROOMBA
#define ROOMBA

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include "robot.h"                                              // include robot.h

using namespace std;
namespace PA5
{
    class Robot;
    class Roomba : public Robot {                               // derivation of roomba class from robot class
    public:
        Roomba() : Robot(3, 10,false,"roomba") {}               // default constructor
        Roomba(string name) : Robot(3,10,false,name){}          // constructor with name argument

        string getType();                                       // returns type
        int getDamage() override;                               // returns damage of roomba
        string getName();                                       // returns specific name of roomba
    };

}
#endif