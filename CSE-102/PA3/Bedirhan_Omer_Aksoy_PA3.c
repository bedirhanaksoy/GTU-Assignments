#include <stdio.h>
#include <stdlib.h>

#define p1 0.5      // I defined p1 
#define p2 20       // and p2

void read_input_file_and_fill_arrays(double *all_numbers_in_file, double *place_of_chunks_first_elements, double *size_of_chunks, double *average_of_chunks, int *k, int *j); // it read input file and fill arrays
void put_in_order_arrays(double *all_numbers_in_file, double *place_of_chunks_first_elements, double *size_of_chunks, double *average_of_chunks, int j);    // it put in order arrays according to average of chunks smallest to largest
void print_output_file(double *all_numbers_in_file, double *place_of_chunks_first_elements, double *size_of_chunks, double *average_of_chunks, int j);      // it prints chunks in output file as it expected

int main(){

    int k =0;   // it is count of elements 
    int j =0;   // it is count of chunks
    double all_numbers_in_file[1000];   // it holds all numbers in a que
    double place_of_chunks_first_elements[100]; // it holds the notation of chunk's starting point on the que 
    double size_of_chunks[100]; // it holds size of each chunk
    double average_of_chunks[100]; // it holds average value of each chunk

    read_input_file_and_fill_arrays(all_numbers_in_file, place_of_chunks_first_elements, size_of_chunks, average_of_chunks, &k, &j);    // reads input file and fill arrays
    put_in_order_arrays (all_numbers_in_file, place_of_chunks_first_elements, size_of_chunks, average_of_chunks, j);    // puts in order to print lowest average to highest average
    print_output_file(all_numbers_in_file, place_of_chunks_first_elements, size_of_chunks, average_of_chunks, j);       // prints chunks from lowest average to highest average
    return 0;                    
}

void read_input_file_and_fill_arrays(double *all_numbers_in_file, double *place_of_chunks_first_elements, double *size_of_chunks, double *average_of_chunks, int *k, int *j){
    double a,b,n;   // a is average of current chunk.   b is next possible average of chunk.  n is holder for fscanf, it holds current readed value from file.                 // i sent arguments as double array pointer and integer pointer because we want to change them here and then use these arrays and k,j variables in main function.
    FILE* fp1 = fopen("input.txt","r");  // i declared fp1 file pointer on read mode.  
    while(fscanf(fp1, "%lf",&n)==1){       // this while loop will turn until fscanf cannot converte succesfully %lf to double. For our case, it is EOF because input.txt is error-free. 
        all_numbers_in_file[*k] = n;       // stores every single doubles in it.

        if(*k==0){                         // if it is first element, it assigns first element as first average value, it assigns its notation as 0th element of que and it increments size of the first chunk.
            average_of_chunks[*j] = n;
            place_of_chunks_first_elements[*j]=0;
            size_of_chunks[*j]=1;
        }
        else{                               // after the first cycle, this condition will bi selected in every cycle. 
            a = average_of_chunks[*j];         // current average value of chunk
            b = (a*(size_of_chunks[*j]) + n)/(size_of_chunks[*j]+1);    // next possible average of chunk
            if(!(b > a*(1+p1) || b < a*(1-p1) || a > n*p2 || a < n/p2 )){   // checks the given condition and if it is true 
                size_of_chunks[*j]+=1;                                      // it increments the size of the chunk
                average_of_chunks[*j] = b;                                  // and updates the average of the chunk
            }
            else{                                                           // if the condition is false, it means it starts a new chunk
                *j = *j + 1;                                                // it increments the j in order to store the next chunk's size,position and average values in array's next space.
                place_of_chunks_first_elements[*j] = *k;                    // updates the next chunk's position.
                average_of_chunks[*j]=n;                                    // updates the next chunk's average value (itself).
                size_of_chunks[*j]+=1;                                      // updates the next chunk's size.
            }
        }
        *k+=1;                                                              // increments the current position on que.
    }
    fclose(fp1);                                        
}

void put_in_order_arrays(double *all_numbers_in_file, double *place_of_chunks_first_elements, double *size_of_chunks, double *average_of_chunks, int j){ // it puts in order arrays according to average of chunks smallest to largest
    int temp_numbers,x,y;        // temp_numbers holds the numbers temporarily while we swap numbers from one place to another. x and y is for loops' counters.                     
    for (y=0; y<j+1; y++) {                                     //it counts from zero to size of average values' array.                            
        for (x=y+1; x<j+1; x++) {                                   // it counts from y+1 to the end of array, 
            if(average_of_chunks[y] > average_of_chunks[x]) {       // so it checks wether any values exists which is smaller than the previous elements or not.
                temp_numbers = average_of_chunks[y];                // if any, it swaps the elements and the smaller one becomes first in order.
                average_of_chunks[y] = average_of_chunks[x];  
                average_of_chunks[x] = temp_numbers;           

                temp_numbers = place_of_chunks_first_elements[y];                       // we make the same swapping operation to starting notation array too, because these values are all related and we will use them together to print the output.txt
                place_of_chunks_first_elements[y] = place_of_chunks_first_elements[x];
                place_of_chunks_first_elements[x] = temp_numbers;

                temp_numbers = size_of_chunks[y];                                       // same swapping operation to size of chunks because of the same reason.
                size_of_chunks[y] = size_of_chunks[x];
                size_of_chunks[x] = temp_numbers;
            }     
        }     
    }    

}
void print_output_file(double *all_numbers_in_file, double *place_of_chunks_first_elements, double *size_of_chunks, double *average_of_chunks, int j){  // it prints chunks in output file as it expected
    int x,y,z,p;    // i used z and p to make the code more readable. x and y for for loops.
    FILE* fp2 = fopen("output.txt","w");    // file pointer for output.txt on write mode.
    for(y=0 ; y<=j ; y++){                  // it will turn as much as the amounth of chunks
        z = size_of_chunks[y];  // it is size_of_chunks array's y'th element. Because we print the numbers with respect to size of chunks.
        p = place_of_chunks_first_elements[y];      // it is place of the chunks starting notation's y'th element. We will use this to find our chunk inside of the all_numbers_in_file array.
        for(x=0; x<z ; x++){                             // it will turn as much as the amount of the size of chunks
            fprintf(fp2,"%.4f ",all_numbers_in_file[p++]);      // it prints exactly one chunk 
        }
         fprintf(fp2,"\n");                                     // it passes the new line and the loop continues
    }
    fclose(fp2);
}