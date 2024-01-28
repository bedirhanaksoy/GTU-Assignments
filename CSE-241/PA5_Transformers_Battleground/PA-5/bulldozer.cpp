#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include "bulldozer.h"                         // include bulldozer.h

using namespace std;

namespace PA5
{   
    string Bulldozer::getType()  {             // returns type of robot              
        return "Bulldozer";     
    }
    string Bulldozer::getName(){                // returns specific name of bulldozer
        return Robot::getName();
    }
    int Bulldozer::getDamage() {                // returns damage of bulldozer
        int damage = Robot::getDamage();
        return damage;
    }
}
