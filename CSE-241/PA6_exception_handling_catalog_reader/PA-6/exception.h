#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include "catalog.h"                                                    // include necessary libraries and catalog.h

using namespace std;

namespace PA6                                                           // add class declarations into PA6 namespace
{
    class catalog;                                                      // forward declaraton for catalog class        
    class Exception                                                     // declaration for base class
    {

    };

    class MissingField : public Exception                               // missingfield class 
    {
        public:
        MissingField(string error_line) : line(error_line){}
        void printErrorLine();

        private:
        string message = "Exception: missing field: ";
        string line;
    };

    class DuplicateEntry : public Exception                             // duplicateentry class
    {
        public:
        DuplicateEntry(catalog* dup) : duplicate(dup){}
        void printErrorLine();

        private:
        string message = "Exception: duplicate entry: ";
        catalog* duplicate;
    };

    class WrongCommand : public Exception                               // wrong command class
    {
        public:
        WrongCommand(string error_line) : line(error_line){}
        void printErrorLine();
        
        private:
        string message = "Exception: command is wrong: ";
        string line;
    };
}
#endif