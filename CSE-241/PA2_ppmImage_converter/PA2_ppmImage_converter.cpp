#include<iostream>
#include<fstream>                                               // fstream for file operations 
#include<vector>                                                // vector for vector operations 

using namespace std;

class ImageEditor                                               // ImageEditor class is whole program
{
    public:
    void main_menu();                                           // main menu function 
    void open_an_image();                                       // open an image menu function
    void save_image_data();                                     // save image menu function
    void convert_to_grayscale();                                // grayscale conversion function

    private:
    int width;                                                  // width of the ppm 
    int height;                                                 // height of the ppm
    int max_value;                                              // max value of the image
    string magic_number;                                        // magic number of the image 
    vector<vector<vector<int>>> rgb;                            // RED GREEN BLUE values of the ppm
};

int main(){
    ImageEditor image;                                          // declaration of the image object
    image.main_menu();                                          // calling main menu function 
}

void ImageEditor::main_menu(){          
    int opt,flag=0;                                             // opt is option that choosen by user and flag is a flag for determine an image is opened or not 
    while(1){                                                   // while(1) loop for print the current menu until user enters zero
        cout<<"MAIN MENU\n"                                     // MAIN MENU
        <<"0 - Exit\n"
        <<"1 - Open An Image(D)\n"
        <<"2 - Save Image Data(D)\n"
        <<"3 - Scripts(D)\n";
        cin>>opt;                                               // takes the selected menu from user
        if(opt == 0){                                           // if opt == 0, exits program
            exit(1);
        }
        else if(opt == 1){                                      // if opt == 1, calls open an image menu and turns flag to 1
            this-> open_an_image();
            flag=1;
        }
        else if(opt == 2 && flag==1){
            this-> save_image_data();                           // if opt == 2 and flag == 1, calls save image data menu
        }
        else if(opt == 3 && flag==1){
            this-> convert_to_grayscale();                      // if opt == 3 and flag == 1, calls convert to grayscale menu 
        }
    }
}

void ImageEditor::open_an_image() {
    int opt, i, j, k;                                                       // opt is for users option and i,j,k for for loops
    string filename;                                                        // string for file name
    while(1){                                                               // while(1) loop for print the current menu until user enters zero
        cout << "OPEN AN IMAGE MENU\n"                                      // OPEN AN IMAGE MENU
            << "0 - UP\n"
            << "1 - Enter The Name Of The Image File\n";
        cin >> opt;                                                         // take option from user

        if (opt == 0) return;                                               // if option is zero, it turns to MAIN MENU
        else if (opt == 1) {                                                // if option is one, it takes the file name
                cin >> filename;
                ifstream read(filename);                                    // open file in reading mode
                if (read.is_open()) {                                       // check if file exists
                
                    read >> magic_number >> width >> height >> max_value;   // read file and determine magic number, width, height and max value of out object.
                    for (int i = 0; i < height; i++) {
                        vector<vector<int>> row;                            // i didnt want to use dynamic array or vector which is forbidden, so i created each row, pixel and value vectors seperately and push_back to rgb 3d vector every time.
                        for (int j = 0; j < width; j++) {
                            vector<int> pixel;                              // declare each pixel vector 
                            for (int k = 0; k < 3; k++) {                   // loop turns 3 times for each r g b values
                                int value;                                  // value represents r g b each turn
                                read >> value;                              // read r g b values one by one 
                                pixel.push_back(value);                     // and push_back them to pixel vector each turn
                            }
                            row.push_back(pixel);                           // and push_back pixel vector to row vector each pixel turn
                        }
                        rgb.push_back(row);                                 // and push_bach row vector to rgb vector each row turn
                    }
                    read.close();                                           // close the file
                }   
                
        }
    }
}

void ImageEditor::save_image_data(){
    int opt;                                                                // for users option
    while(1){                                                               // while(1) loop for printing the current menu until users enters 0
        cout<<"SAVE IMAGE DATA MENU\n"                                      // SAVE IMAGE DATA MENU
            <<"0 - UP\n"
            <<"1 - Enter A File Name\n";
        cin>>opt;                                                           // take opt from user
        if(opt==0) return;                                                  // if opt equals zero, it turns to MAIN MENU
        else if(opt==1){                                                    // if opt == 1, it takes file name from user
            string filename;
            cin>>filename;
            ofstream write(filename);                                       // opens file in writing mode
        
            write << magic_number << endl;                                  // writes magic number on first line
            write << width <<" "<< height <<endl;                           // writes width and height on the next line
            write << max_value << endl;                                     // writes max value on the next line
            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width; j++) {
                    for (int k = 0; k < 3; k++) {
                        write << rgb[i][j][k] <<" ";                        // writes r g b values in order to their height and width values  
                    }
                }
                write <<endl;                                               // makes new line after printing every row
            }
            write.close();                                                  // closes the file
        }
    }
}

void ImageEditor::convert_to_grayscale(){
    int opt,flag = 0;
    double coe1,coe2,coe3,value1,value2,value3,total;                               // coe variables for coefficients and value variables for values after multiplying with coefficients and total variable for total values of addition of values
    while(1){                                                                       // while(1) loop for printing current menu until user enters 0
        cout<<"CONVERT TO GRAYSCALE MENU\n"
            <<"0 - UP\n"
            <<"1 - Enter Coefficients For RED GREEN And BLUE Channels.\n";
        cin>>opt;                                                                   // take opt from user
        if(opt==0) return;                                                          // if its zero, it turns to MAIN MENU
        else if (opt == 1){                                                         // if opt is 1, it takes coefficients
            do{                                                                     // while coefficients are out of range, it asks user for valid coefficients
                if(!(cin>>coe1>>coe2>>coe3)){                                       // if doubles doesnt converted into doubles successfully, this if statement will run
                    cin.clear();                                                    // Clear the error flag
                    cin.ignore(10000, '\n');                                        // Ignore remaining characters in the input buffer until the end of the line
                    flag = 0;                                                       // it means input is invalid, it will cause run the loop again and take new coefficients
                }
                else if(coe1<1 && coe2<1 && coe3<1 && coe1>=0 && coe2>=0 && coe3>=0){    // if they are in range, it makes operations and save new values of rgb vector in memory
                    flag = 1;                                                            // it means input is valid and it wont ask input for user again
                    for (int i = 0; i < height; i++) {                             
                        for (int j = 0; j < width; j++) {
                            for (int k = 0; k < 3; k++) {
                                if(k==0){
                                    value1 = rgb[i][j][k] * coe1;                   // for each RED value, it multiplies the red coefficient and assign it to value1
                                }
                                else if(k==1){
                                    value2 = rgb[i][j][k] * coe2;                   // for each GREEN value, it multiplies the green coefficient and assign it to value2
                                }
                                else if(k==2){
                                    value3 = rgb[i][j][k] * coe3;                   // for each BLUE value, it multiplies the blue coefficient and assign it to value3
                                }
                            }
                            total = value1 + value2 + value3;                       // finds the total value of the new values and assigns it to total variable
                            if(total > max_value){
                                total = max_value;                                  // if total is greater than max value, total will be equalized to max value
                            }
                            for (int k = 0; k < 3; k++) {
                            rgb[i][j][k] = total;                                   // total values of the pixels assigns into each pixels 
                            }
                        }
                    }
                }
            }
            while(flag ==0 || coe1<0 || coe2<0 || coe3<0 || coe1>=1 || coe2>=1 || coe3>=1);     // if its not valid, do statement will be performed again
        }
    }
}