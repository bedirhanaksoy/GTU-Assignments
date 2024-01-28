#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include "catalog.h"                                                                    // include necessary libraries and catalog.h

using namespace std;
namespace PA6                                                                           // add all definitions into PA6 namespace
{
    catalog::catalog(){                                                                 // default constructor initialize size and pointer array
        size =0;
        list_of_members = nullptr;
    }
    void catalog::setCatalog(catalog** new_catalog){                                    // sets new catalog 
            list_of_members = nullptr;
            list_of_members = new_catalog;
    }
    catalog** catalog::search_catalog(){                                                // returns catalog pointer array
        return list_of_members;
    }
    int catalog::getSize(){                                                             // returns size
        return size;
    }

    void catalog::add_object_to_catalog(catalog* new_object)                            // adds new object to catalog
    {
        int dup=0;
        for(int i=0;i<size;i++){
            if(list_of_members[i]->getField("title")==new_object->getField("title")){   // chech whether new entry is duplicate or not 
                dup=1;
            }
        }
        if(dup==1){
            throw DuplicateEntry(new_object);                                           // if its duplicate, throws duplicate entry exception and omit that line
        }
        else{                                                                           // else adds new objects address to array
            catalog** tempArray = new catalog*[size + 1];

            for (int i = 0; i < size; i++) {
                tempArray[i] = list_of_members[i];
            }
            tempArray[size] = new_object;
            delete[] list_of_members;
            list_of_members = tempArray;
            size++;
        }   
    }

    void catalog::display(){                                                            // prints every objects elements into file
        for(int i=0;i<size;i++){
            list_of_members[i]->display();
        }
    }
    movie::movie(string ttle, string dir, string yr, string gnr, string strr) : title(ttle), director(dir), genre(gnr), starring(strr)
    {
        year = stoi(yr);                                                                // string type year converts int type with stoi
    }

    int movie::get_year() 
    {
        return year;                                                                    // returns year
    }

    void movie::display() {                                                             // prints title, director, year, genre, starring elements to output file
        ofstream out("output.txt",ios::app);
        out<<"\""<<title<<"\" \""<<director<<"\" \""<<year<<"\" \""<<genre<<"\" \""<<starring<<"\""<<endl;
        out.close();
    }
    string movie::getField(string field) {                                              // returns related element with field variable
        if(field == "title") return title;
        else if(field == "director") return director;
        else if(field == "genre") return genre;
        else if(field == "starring") return starring;
        else return "-1";                                             // if related field doesnt exists, throws wrong command exception
    }

    music::music(string ttle, string artst, string yr, string gnr) : title(ttle),artist(artst),genre(gnr)
    {
        year = stoi(yr);
    }
    int music::get_year() 
    {
        return year;                                                                    
    }

    void music::display() {
        ofstream out("output.txt",ios::app);
        out<<"\""<<title<<"\" \""<<artist<<"\" \""<<year<<"\" \""<<genre<<"\""<<endl;
        out.close();
    }

    string music::getField(string field) {
        if(field == "title") return title;
        else if(field == "artist") return artist;
        else if(field == "genre") return genre;
        else return "-1";
    }

    book::book(string ttle, string authrs, string yr, string tgs) : title(ttle), authors(authrs), tags(tgs)
    {
        year = stoi(yr);
    }
    int book::get_year()
    {
        return year;
    }
    void book::display() {
        ofstream out("output.txt",ios::app);
        out<<"\""<<title<<"\" \""<<authors<<"\" \""<<year<<"\" \""<<tags<<"\""<<endl;
        out.close();
    }
    
    string book::getField(string field){
        if(field == "title") return title;
        else if(field == "authors") return authors;
        else if(field == "tags") return tags;
        else return "-1";
    }
}
