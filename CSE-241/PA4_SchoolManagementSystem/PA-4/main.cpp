#include "SchoolManagerSystem.h"// included every header files
#include "student.h"
#include "course.h"
#include<cstdlib>
#include<string>
#include<iostream>

using namespace std;
using namespace PA4;                        // using std and PA4 namespaces
int main(){
    SchoolManagerSystem obj1;               // obj1 created
    cout<<"Main Menu"<<endl;                // Main Menu printed for only once 
    obj1.main_menu();                       // main menu called
    return 0;
}

