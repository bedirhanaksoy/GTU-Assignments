#ifndef CATALOG_H
#define CATALOG_H
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include "exception.h"                                                                          // include necessary libraries and exception.h

using namespace std;                                    
namespace PA6                                                                                   // add class declarations into PA6 namespace
{                                   
    class WrongCommand;                                                                         // forward declarations for exceptions
    class DuplicateEntry;                                   
    class MissingField;                                 

    class catalog                                                                               // base class for catalog types
    {                                   
        public:                                 
        catalog();                                                                              // default constructor 
        virtual int get_year(){};                                                               // virtual getyear function for return year
        virtual string getField(string field){};                                                // virtual getField function for return field
        void setCatalog(catalog** new_catalog);                                                 // sets new catalog pointer array
        catalog** search_catalog();                                                             // returns catalog pointer arry
        int getSize();                                                                          // returns size of the pointer array
        void add_object_to_catalog(catalog* new_object);                                        // adds new object address to array
        virtual void display();                                                                 // prints to output.txt


        private:                                    
        catalog** list_of_members;                                                              // catalog type pointer array
        int size;                                                                               // size of the array
    };


    class movie : public catalog                                                                // movie class which derived from catalog
    {
        public:
        movie(string ttle, string dir, string yr, string gnr, string strr);                     // constructor with variables
        int get_year() override;                                                                // overriden functions
        void display() override;
        string getField(string field) override;

        private:                                                                                // title, director, year, genre, starring informations
        string title;
        string director;
        int year;             
        string genre;
        string starring;
    };

    class music : public catalog                                                                // music class which derived from catalog 
    {
        public:
        music(string ttle, string artst, string yr, string gnr);                                // constructor with variables
        int get_year() override;                                                                // overriden functions
        void display() override;
        string getField(string field) override;
        private:                                                                                // title, artist, year, genre informations
        string title;
        string artist;
        int year;             
        string genre;
    };

    class book : public catalog                                                                 // book class which derived from catalog
    {
        public:
        book(string ttle, string authrs, string yr, string tgs);                                // constructor with variables
        int get_year() override;                                                                // overriden function
        void display() override;
        string getField(string field) override;

        private:                                                                                // title, authors, year, genre informations
        string title;
        string authors;
        int year;             
        string tags;
    };

}

#endif