#include<iostream>
#include<fstream>                                               // fstream for file operations 
#include<vector>                                                // vector for vector operations 
#include<cstdlib>

using namespace std;

class ppmImage                                               // ppmImage class is whole program
{
    public:

    ppmImage();
    ppmImage(string filename);
    ppmImage(int column, int row);

    int write_file(const string destination_ppm_file_name) const;
    int read_file(const string source_ppm_file_name);
    int read_individual_pixel(int row, int column, int channel);         // reads individual pixel value
    void change_individual_pixel(int row, int column, int channel, int new_value);
    void print_dimensions();
    int get_width() const;
    int get_height() const;

    int& operator()(int row, int column, int channel);

    friend ppmImage operator +(const ppmImage& given_image1, const ppmImage& given_image2);     // summation operator as a friend function
    friend ppmImage operator -(const ppmImage& given_image1, const ppmImage& given_image2);     // subtraction operator as a friend function
    friend ostream& operator <<(ostream& out, const ppmImage& given_image);     // print operator as a friend function
     

    private:

    int width;                                                  // width of the ppm 
    int height;                                                 // height of the ppm
    int max_value;                                              // max value of the image
    string magic_number;                                        // magic number of the image 
    vector<vector<vector<int>>> rgb;                            // RED GREEN BLUE values of the ppm
};

ppmImage operator+( const ppmImage& given_image1, const ppmImage& given_image2) 
{
    ppmImage sum;                                                                                   // sum object to represent result of the summation
    int sum_value,i,j,k;
    if(given_image1.height!=given_image2.height || given_image1.width!=given_image2.width){         // if dimensions of the given objects are different, it returns an empty object
       return sum;
    }
    else{
        for(i=0;i<given_image1.height;i++){                                                         
            vector<vector<int>> row;
            for(j=0;j<given_image1.width;j++){
                vector<int> pixel;
                for(k=0;k<3;k++){
                    sum_value = given_image1.rgb[i][j][k] + given_image2.rgb[i][j][k];              // sum value equals to summation of two pixels channel values
                    if(sum_value>given_image1.max_value) sum_value = given_image1.max_value;        // if result of the summation is greater than max value. it equalizes to the max value
                    pixel.push_back(sum_value);                                                     // pushes back to pixel vector each channel
                }
                row.push_back(pixel);                                                               // pushes back to row vector each pixel
            }
            sum.rgb.push_back(row);                                                                 // pushes back to rgb vector of sum object each row
        }
        sum.height = given_image1.height;                                                           // equalize every features from given objects to sum object 
        sum.width = given_image1.height;
        sum.magic_number = given_image1.magic_number;
        sum.max_value = given_image1.max_value;
    }
    return sum;                                                                                     // returns sum object
}

ppmImage operator-( const ppmImage& given_image1, const ppmImage& given_image2) 
{
    ppmImage sub;
    int sub_value,i,j,k;
    if(given_image1.height!=given_image2.height || given_image1.width!=given_image2.width){         // if sizes arent same, returns empty object
        return sub;
    }
    else{
        for(i=0;i<given_image1.height;i++){
            vector<vector<int>> row;
            for(j=0;j<given_image1.width;j++){
                vector<int> pixel;
                for(k=0;k<3;k++){
                    sub_value = given_image1.rgb[i][j][k] - given_image2.rgb[i][j][k];              // sub value equals to subtraction of given objects same pixels channel values
                    if(sub_value<0) sub_value = 0;                                                  // if sub value is less than zero, it equalize it as zero 
                    pixel.push_back(sub_value);                                                     // pushes back each channel value to pixel vector 
                }
                row.push_back(pixel);                                                               // pushes back each pixel vectors to row vector
            }
            sub.rgb.push_back(row);                                                                 // pushes back each row vectors to sub object's rgb vector
        }   
        sub.height = given_image1.height;                                                           // equalizes every features from given objects to sum object
        sub.width = given_image1.height;
        sub.magic_number = given_image1.magic_number;
        sub.max_value = given_image1.max_value;
    }
    return sub;
}

ostream& operator <<(ostream& out, const ppmImage& given_image)                                     // returns a reference of given object as an ostream 
{
    // Print image details
    out << given_image.magic_number << endl;                                                        // ostream reference to prints magic number
    out << given_image.width <<" "<<given_image.height << endl;                                     // width and height
    out << given_image.max_value << endl;                                                           // max value
   
    for (int i = 0; i < given_image.height; i++) {  
        
        for (int j = 0; j < given_image.width; j++) {
            
            for (int k = 0; k < 3; k++) {
                out << given_image.rgb[i][j][k];                                                    // rgb values of each pixels
                out << " ";
            }
        }
        out << endl;
    }
    return out;
}

int& ppmImage::operator()( int row, int column, int channel)
{
    return rgb[row][column][channel];                                                               // it allows to change the value of a specific channel of a pixel
}

int read_ppm(const string source_ppm_file_name, ppmImage& destination_object);                                      // file reader standalone function

int write_ppm(const string destination_ppm_file_name, const ppmImage& source_object);                               // file writer function

int test_addition(const string filename_image1, const string filename_image2, const string filename_image3);        // tests sum operator

int test_subtraction(const string filename_image1, const string filename_image2, const string filename_image3);     // tests sub operator

int test_print(const string filename_image1);                                                                       // tests ostream operator

int swap_channels(ppmImage& image_object_to_be_modified, int swap_choice);                                          // tests referance operator

ppmImage single_color(const ppmImage& source, int color_choice);                                                    // returns an object which contains only one color channel of given source object

bool isFileEmpty(string filename);


int main(int argc, char** argv){
    
    int choice,a,b,c;
    string filename1,filename2,filename3;
    if(argc<3){
        cout<<"Insufficient count of arguments. exit(1)"<<endl;                                                     // if the count of arguments are less than three, it means user didnt entered any file name
        exit(1);
    }
    else if(argc==3){                                                                                               // if argv has 3 elements, assigns argv[2] to filename1
        filename1 = argv[2];
    }
    else if(argc==4){                                                                                               // if argv has 4 elements, assigns argv[3] to filename2
        filename1 = argv[2];
        filename2 = argv[3];
    }
    else if(argc==5){                                                                                               // if argv has 5 elements, assigns argv[4] to filename3
        filename1 = argv[2];
        filename2 = argv[3];
        filename3 = argv[4];
    }

    choice = (int)argv[1][0]-48;                                                                                    // typecasts the argv[1] value to integer to take choice value

    if(choice==1){
        if(argc<5){                                                                                                 // if count of arguments are less than 5, user didnt entered 3 file names
            cout<<"Insufficient count of arguments. exit(1)"<<endl;
            exit(1);
        }
        ifstream myfile;
        myfile.open(filename1);                                                                                     // checks first files existance
        if(!myfile){
            cout<<"First file cannot found. exit(1)"<<endl;
            exit(1);
        }
        myfile.close();
        myfile.open(filename2);
        if(!myfile){                                                                                                // checks second files existance
            cout<<"Second file cannot found. exit(1)"<<endl;
            exit(1);
        }
        myfile.close();
    
        a = test_addition(filename1,filename2,filename3);                                                           // adds those files and if it is succesfull it returns 1, else returns 0
        }
    else if(choice==2){                                                                                             // if count of arguments are less than 5, user didnt entered 3 file names
        if(argc<5){
            cout<<"Insufficient count of arguments. exit(1)"<<endl;
            exit(1);
        }
        ifstream myfile;
        myfile.open(filename1);
        if(!myfile){                                                                                                // checks the existence of the first file
            cout<<"First file cannot found. exit(1)"<<endl;
            exit(1);
        }
        myfile.close();
        myfile.open(filename2);
        if(!myfile){                                                                                                // checks the existence of the second file
            cout<<"Second file cannot found. exit(1)"<<endl;
            exit(1);
        }
        myfile.close();

        a = test_subtraction(filename1,filename2,filename3);                                                        // subtracts those files and if its succesfull it returns 1, else returns 0
        }
    else if(choice==3){ 
        ppmImage swap;                                                                                              // creates an object called swap
        a = read_ppm(filename1,swap);                                                                               // reads file1 and fills swap object 
        b = swap_channels(swap,2);                                                                                  // swaps green and blue values for each pixels
        c = write_ppm(filename2,swap);                                                                              // writes the swapped version of file1 to file2
        }
    else if(choice==4){                                                                                             
        ppmImage swap;                                                                                              // creates an object called swap
        a = read_ppm(filename1,swap);                                                                               // reads file1 and fills swap object
        b = swap_channels(swap,3);                                                                                  // swaps green and blue values for each pixels
        c = write_ppm(filename2,swap);                                                                              // writes the swapped version of file1 to file2
        }
    else if(choice==5){
        ppmImage single;                                                                                            
        a = read_ppm(filename1,single);                                                                             // reads file1 and fill single object 
        single = single_color(single,1);                                                                            // single_color function returns the ppmImage object which contains only red data of file1
        b = write_ppm(filename2,single);                                                                            // writes the new version of file1 to file2 
    }
    else if(choice==6){
        ppmImage single;
        a = read_ppm(filename1,single);                                                                             // reads file1 and fill single object
        single = single_color(single,2);                                                                            // single_color function returns the ppmImage object which contains only green data of file1
        b = write_ppm(filename2,single);                                                                            // writes the new version of file1 to file2
    }
    else if(choice==7){
        ppmImage single;
        a = read_ppm(filename1,single);                                                                             // reads file1 and fill single object
        single = single_color(single,3);                                                                            // single_color function returns the ppmImage object which contains only blue data of file1
        b = write_ppm(filename2,single);                                                                            // writes the new version of file1 to file2
        
    }
    else if(choice==8){
        a = test_print(filename1);                                                                                   // prints the file to output stream with using overloaded << operator, if its printed succesfully returns 1, else 0                                                                                        
    }
    return 0;
}

ppmImage::ppmImage(){                                                                                               // default constructor, initializes an empty object
    width = 0;
    height = 0;
    magic_number = "P3";
    max_value = 255;
}

ppmImage::ppmImage(int first_dimension, int second_dimension){                  // constructor which initialize a white ppm image with given dimensions

    max_value = 255;
    width = first_dimension;
    height = second_dimension;
    magic_number = "P3";
                    
    for (int i = 0; i < second_dimension; i++) {
            vector<vector<int>> row;                            // i didnt want to use dynamic array or vector which is forbidden, so i created each row, pixel and value vectors seperately and push_back to rgb 3d vector every time.
            for (int j = 0; j < first_dimension; j++) {
                vector<int> pixel;                              // declare each pixel vector 
                for (int k = 0; k < 3; k++) {                   // loop turns 3 times for each r g b values
                    pixel.push_back(max_value);                     // and push_back them to pixel vector each turn
                }
                row.push_back(pixel);                           // and push_back pixel vector to row vector each pixel turn
            }
            rgb.push_back(row);                                 // and push_bach row vector to rgb vector each row turn
        }
}


ppmImage::ppmImage(string filename){                            // constructor which initialize the object with given ppm file
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
    else{
        cout<<"File cannot found. exit(1)"<<endl;
        exit(1);

    }       
}

int ppmImage::write_file(const string destination_ppm_file_name) const
{
    ofstream write(destination_ppm_file_name);                                       // opens file in writing mode
    write << magic_number << endl;                                  // writes magic number on first line
    write << width <<" "<< height <<endl;                           // writes width and height on the next line
    write << max_value << endl;                                     // writes max value on the next line
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            for (int k = 0; k < 3; k++) {
                write <<rgb[i][j][k] <<" ";                        // writes r g b values in order to their height and width values  
            }
        }
        write <<endl;                                               // makes new line after printing every row
    }
    write.close();   
    if(!cout){
        return 0;
    }
    else { return 1; }
}

int ppmImage::read_file(const string source_ppm_file_name)      // reads ppm file and fills the object
{
    ifstream read(source_ppm_file_name);                                    // open file in reading mode
    if (read.is_open()) {                                       // check if file exists                
        read >>magic_number >>width >>height >>max_value;   // read file and determine magic number, width, height and max value of out object.
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
            rgb.push_back(row);                                // and push_bach row vector to rgb vector each row turn
        }
        read.close();                                           // close the file
        return 1;
    }   
    else{
        return 0;
    }
}

int ppmImage::read_individual_pixel(int row, int column, int channel)                               // returns a channel value of a particular pixel
{
    return (rgb[row][column][channel]);                                                         
}

void ppmImage::change_individual_pixel(int row, int column, int channel, int new_value){            // changes a particular pixel
    rgb[row][column][channel] = new_value;
}

void ppmImage::print_dimensions(){                                                                  // prints dimensions
    cout<<width<<" "<<height<<endl;
}

int ppmImage::get_width() const                                                                     // returns width value
{
    return width;
}

int ppmImage::get_height() const                                                                    // returns height value
{
    return height;
}

int read_ppm(const string source_ppm_file_name, ppmImage &destination_object)                       // reads from source ppm file and fills destination object and returns 0 or 1 according to success or fail
{
    return destination_object.read_file(source_ppm_file_name);
}

int write_ppm(const string destination_ppm_file_name, const ppmImage &source_object)                // fills destination ppm file from source object and returns 0 or 1 according to success or fail
{
    return source_object.write_file(destination_ppm_file_name);
}

int test_addition(const string filename_image1, const string filename_image2, const string filename_image3)     // tests addition and returns 0 or 1 according to succes or fail
{
    ppmImage left_hand_operand(filename_image1);
    ppmImage right_hand_operand(filename_image2);
    ppmImage result;
    result = left_hand_operand + right_hand_operand;
    int return_val = result.write_file(filename_image3);
    return return_val;
}

int test_subtraction(const string filename_image1, const string filename_image2, const string filename_image3)  // tests subtraction and returns 0 or 1 according to success or fail
{
    ppmImage left_hand_operand(filename_image1);
    ppmImage right_hand_operand(filename_image2);
    ppmImage result;
    result = left_hand_operand - right_hand_operand;
    int return_val = result.write_file(filename_image3);
    return return_val;
}

int test_print(const string filename_image1)                                                                    // tests overloaded << operator and returns 0 or 1 according to success or fail
{   
    ppmImage printfile(filename_image1);
    if(isFileEmpty(filename_image1)){                                                                           // checks whether the file is empty or not, if it is empty, returns 1
        return 1;       
    }
    else{
        cout<<printfile;
        if(!cout) return 0;
        else return 1;
    }
}

int swap_channels(ppmImage &image_object_to_be_modified, int swap_choice)                                                       // swaps two particular channels of each pixels of an object
{
    ppmImage test_class = image_object_to_be_modified;                                                                          // copies given object to temp one 
    int temp,height,width;
    height = image_object_to_be_modified.get_height();
    width = image_object_to_be_modified.get_width();
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(swap_choice==1){                                                                                                 // if choice is 1, it swaps red and green channels 
                temp = image_object_to_be_modified.read_individual_pixel(i,j,0);
                image_object_to_be_modified(i,j,0) = image_object_to_be_modified.read_individual_pixel(i,j,1);
                image_object_to_be_modified(i,j,1) = temp;
            }
            else if(swap_choice==2){                                                                                            // if choice is 2, it swaps red and blue channels
                temp = image_object_to_be_modified.read_individual_pixel(i,j,0);    
                image_object_to_be_modified(i,j,0) = image_object_to_be_modified.read_individual_pixel(i,j,2);
                image_object_to_be_modified(i,j,2) = temp;
            }
            else if(swap_choice==3){                                                                                            // if choice is 3, it swaps green and blue channels
                temp = image_object_to_be_modified.read_individual_pixel(i,j,1);
                image_object_to_be_modified(i,j,1) = image_object_to_be_modified.read_individual_pixel(i,j,2);
                image_object_to_be_modified(i,j,2) = temp;
            }
        }
    }
    for(int i=0;i<height;i++){                                                                                                  // validates the correctness of the swap operation by comparing every swapped value
        for(int j=0;j<width;j++){
            if(swap_choice==1){
                if(test_class.read_individual_pixel(i,j,0) != image_object_to_be_modified.read_individual_pixel(i,j,1)
                    || test_class.read_individual_pixel(i,j,1)!=image_object_to_be_modified.read_individual_pixel(i,j,0)){
                        return 0;                                                                                               // if any value doesnt match, swap operation is unsuccessful, returns 0
                    }
            }
            else if(swap_choice==2){
                if(test_class.read_individual_pixel(i,j,0) != image_object_to_be_modified.read_individual_pixel(i,j,2)
                    || test_class.read_individual_pixel(i,j,2)!=image_object_to_be_modified.read_individual_pixel(i,j,0)){
                        return 0;
                    }
            }
            else if(swap_choice==3){
                if(test_class.read_individual_pixel(i,j,1) != image_object_to_be_modified.read_individual_pixel(i,j,2)
                    || test_class.read_individual_pixel(i,j,2)!=image_object_to_be_modified.read_individual_pixel(i,j,1)){
                        return 0;
                    }
            }
        }
    }
    return 1;
}

ppmImage single_color(const ppmImage &source, int color_choice)
{
    ppmImage result = source;                                           // result object initializes as the source object 
    int height = source.get_height();                                   
    int width = source.get_width();

    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(color_choice==1){                                        // if color choice is 1, red channel remains and other channels of that particular pixel equalizes to 0
                result(i,j,1)=0;
                result(i,j,2)=0;
            }
            else if(color_choice==2){                                   // if color choice is 2, green channel remains and other channels of that particular pixel equalizes to 0
                result(i,j,0)=0;
                result(i,j,2)=0;
            }
            else if(color_choice==3){                                   // if color choice is 3, blue channel remains and other channels of that particular pixel equalizes to 0
                result(i,j,0)=0;
                result(i,j,1)=0;
            }
        }
    }
    return result;                                                      // returns the modified object
}

bool isFileEmpty(string filename) {                                     // checks wether the given file is empty or not
    ifstream file(filename);
    return file.peek() == ifstream::traits_type::eof();
}