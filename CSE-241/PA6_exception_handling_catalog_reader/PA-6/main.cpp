#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include "exception.h"
#include "catalog.h"                                                                    // include necesssary libraries, catalog.h and exception.h    

using namespace std;
using namespace PA6;                                                                    // use namespace std and PA6


template<typename T>
bool compareElements(const std::pair<T, int>& lhs, const std::pair<T, int>& rhs) {      // comparison function for sorting pairs
    return lhs.first < rhs.first;
}

template<typename T>                                                                    // declare template for passing string or integer 
void sort(const std::vector<T>& elements, catalog& list_of_objects) {                   
    std::vector<std::pair<T, int>> indexedElements;                                     // pair vector for sorting elements
    for (int i = 0; i < elements.size(); ++i) {
        indexedElements.push_back(std::make_pair(elements[i], i));                      // initializing pair
    }
    std::sort(indexedElements.begin(), indexedElements.end(), compareElements<T>);      // std::sort() function takes 3 argument: beginning and end iterators of vector and a comparison function and sorts pair

    int size = list_of_objects.getSize();   
    catalog** new_catalog = new catalog*[size];
    for ( int i=0; i<size;i++){                                                         
        int index = indexedElements[i].second;
        new_catalog[i] = list_of_objects.search_catalog()[index];                       // in order to sorted pairs second index, new catalogs order will be determined
    }
    list_of_objects.setCatalog(new_catalog);                                            // sets new catalog
    list_of_objects.display();                                                          // prints arrays elements in new order to file
}

void read_and_create_objects(catalog& object){                                          // reads from input.txt and create objects

    string firstline;
    string line;
    int first =0;
    ifstream inputFile("data.txt"); 
    ofstream output("output.txt");
    output.close();
    ofstream out("output.txt",ios::app);

    while (getline(inputFile, line))                                                        // read file line by line
    {                  
        string current_line = line; 
        if(first==0){
            firstline = line;
            first++;
            out<<"Catalog Read: "<<line<<endl;                                              // print catalog read mode
            continue;
        }
        try 
        {
            vector<string> tokens;
            istringstream iss(line);
            string token;
            while (getline(iss, token, '"')) {                                                                                  // tokenize lines with quote signs
                tokens.push_back(token);
            }
            if((firstline=="movie" && tokens.size()!=10)||((firstline=="book" || firstline == "music") && tokens.size()!=8)){   // if there is any missing fields, throw an exception and omit that line
                throw MissingField(current_line);
                continue;
            }
            if(firstline=="book"){                                                                                              
                object.add_object_to_catalog(new book(tokens[1],tokens[3],tokens[5],tokens[7]));                                // add objects dynamically while reading file
            }
            else if(firstline=="movie"){
                object.add_object_to_catalog(new movie(tokens[1],tokens[3],tokens[5],tokens[7],tokens[9]));
            }
            else if(firstline=="music"){
                object.add_object_to_catalog(new music(tokens[1],tokens[3],tokens[5],tokens[7]));
            }
            else{
                cout<<"hey"<<endl;
            }
        }
        catch (MissingField e)                                                                                                  // catches missing field exception 
        {
            e.printErrorLine();
        }
        catch (DuplicateEntry e)                                                                                                // catches duplicate entry exception
        {
            e.printErrorLine();
        }
    }
    inputFile.close();
    out.close();
    out<<object.getSize()<<" unique entries"<<endl;                                                                             // prints unique entries count to file
}

void commands(catalog& object){                                                                                                 // reads from commands.txt and writes to output.txt
    string line;
    int first =0;
    ofstream out("output.txt",ios::app);
    ifstream command("commands.txt");
    while(getline(command,line))                                                                                                // runs until EOF
    {
        try
        {    
            string current_line = line;
            vector<string> tokens;
                istringstream iss(line);
                string token;
                while (getline(iss, token, '"')) {
                    tokens.push_back(token);
                }
                if((tokens[0] == "search " && tokens.size()!=4 )||tokens[0] == "sort " && tokens.size()!=2 ){                   // tokenize commands with quote signs. if number of tokens arent valid, throws wrong command exception
                    throw WrongCommand(current_line);
                }
                if(tokens[0]=="search "){                                                                                       // searches for the occurance in given type element in each object
                    int find=0;
                    for(int i=0;i<object.getSize();i++){
                        if(object.search_catalog()[i]->getField(tokens[3]).find(tokens[1]) != std::string::npos){               // if there is occurance with given word, prints the current line and related object to file
                            out<<current_line<<endl;
                            object.search_catalog()[i]->display();
                            find=1;
                        }
                    }
                    if(find==0){                                                                                                // if given object couldnt found, throws wrong command exception
                        throw WrongCommand(current_line);
                    }
                }
                else if(tokens[0]=="sort "){                                                                                    // sorts the pointer array in order to given type 
                    out<<line<<endl;
                    
                    if(tokens[1]=="year"){                                                                                      // if first token is year
                        vector<int> years;
                        for(int i=0;i<object.getSize();i++){
                            years.push_back(object.search_catalog()[i]->get_year());                                            // create a vector of objects years 
                        }
                        sort(years,object);                                                                                     // and sort them
                    }
                    else{                                                                                                       // in other types,      
                        vector<string> field;
                        for(int i=0;i<object.getSize();i++){
                            field.push_back(object.search_catalog()[i]->getField(tokens[1]));                                   // create a vector ob objects related fields
                        }
                        sort(field,object);                                                                                     // and sort them
                    }
                }

        }
        catch(WrongCommand e)       // catches wrong command exception
        {
            e.printErrorLine();
        } 
        catch (const exception& e)  // catches other exceptions
        {
            cout<<e.what()<<endl;
        }
        
    }
    command.close();                // close command.txt and output.txt
    out.close();
}

int main(){
    catalog object;                         // create a catalog object
    read_and_create_objects(object);        // send catalog object to functions
    commands(object);
    return 0;
}