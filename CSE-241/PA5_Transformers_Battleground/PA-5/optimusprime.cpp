#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include "optimusprime.h"                                               // include optimusprime.h

using namespace std;

namespace PA5{                                                          // every definition and class is under pa5 namespace

    string OptimusPrime::getType() {
        return "OptimusPrime";                                          // type of the robot
    }
    
    int OptimusPrime::getDamage() {                                     // override of the virtual getDamage() function
        int damage = Humanic::getDamage();                              // calls humanic::getDamage() to get additional humanic damage
        if (rand() % 100 < 15) {                                        // calculates randomize of the strong attack
            cout << "Strong attack! Damage is doubled!" << endl;
            damage *= 2;
        }
        return damage;
    }
    string OptimusPrime::getName(){                                     // Name of the specific optimus prime etc.(optimusprime_0 , optimusprime_1 ...)
        return Robot::getName();
    }

}
