#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include "exception.h"                                          // include necessary libraries and exception.h

using namespace std;

namespace PA6                                                   // add definitions into PA6 namespace
{
    void MissingField::printErrorLine(){                        // prints error message and related line to output.txt
        ofstream out("output.txt",ios::app);
        out<<message<<endl<<line<<endl;
        out.close();
    }
    
    void DuplicateEntry::printErrorLine(){                      // prints error message and related objects elements to output.txt
        ofstream out("output.txt",ios::app);
        out<<message<<endl;
        out.close();
        duplicate->display();
    }

    void WrongCommand::printErrorLine(){                        // prints error message and related line to output.txt
        ofstream out("output.txt",ios::app);
        out<<message<<endl<<line<<endl;
        out.close();
    }
}
