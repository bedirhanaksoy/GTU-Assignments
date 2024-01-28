#ifndef OPTIMUSPRIME
#define OPTIMUSPRIME

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include "robot.h"                                                      // include robot.h and humanic.h
#include "humanic.h"

using namespace std;

namespace PA5
{
    class Humanic;                                                      // forward declaration of the Humanic class

    class OptimusPrime : public Humanic {                               // Derived from humanic class
    public:
        OptimusPrime() : Humanic(100, 100,false,"optimusprime") {}      // default constructor
        OptimusPrime(string name): Humanic(100,100,false,name){}        // constructor which declared with its name
        string getType() override;                                      // get type function
        int getDamage() override;                                       // overriden getDamage function
        string getName();                                               // returns name of specific optimusprime object
    };

}

#endif