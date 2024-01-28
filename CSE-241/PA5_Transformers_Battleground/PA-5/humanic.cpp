#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include "humanic.h"                                                                    // include humanic.h

using namespace std;

namespace PA5
{
    string Humanic::getType(){                                                          // returns type of humanic
        return "Humanic";
    }

    int Humanic::getDamage() {                                                          // calculates humanic damage and gets robot::getDamage default damage and returns addition of them
        int damage = Robot::getDamage();
        if (rand() % 10 == 0) {
            cout << "Tactical nuke attack! Additional 50 damage points!" << endl;
            damage += 50;
        }
        return damage;
    }

}
