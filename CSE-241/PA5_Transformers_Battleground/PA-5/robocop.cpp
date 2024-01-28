#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

#include "robocop.h"                                // include robocop.h

using namespace std;        

namespace PA5{
    string RoboCop::getType() {                     // returns type of robocop
        return "RoboCop";
    }
    string RoboCop::getName(){                      // returns specific name of specific robocop (roboccp_0, robocop_1 ...)
        return Robot::getName();
    }
    int RoboCop::getDamage(){                       // returns humanic classes damage ( humanic::getDamage() calculates the double attack and adds default damage and returns)
        int damage = Humanic::getDamage();
        return damage;
    }
}
