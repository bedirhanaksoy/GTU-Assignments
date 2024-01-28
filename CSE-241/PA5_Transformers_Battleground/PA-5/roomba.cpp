#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include "roomba.h"                                     // include hoomba.h

using namespace std;
namespace PA5
{
    string Roomba::getType() {                          // returns type of roomba
        return "roomba";
    }
    int Roomba::getDamage() {                           // returns damage of the roomba
        int damage = Robot::getDamage();
        return damage;
    }
    string Roomba::getName(){                           // returns name of roomba
        return Robot::getName();
    }
}
