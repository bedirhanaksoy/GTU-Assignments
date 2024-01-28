#include <stdio.h>
#include <stdlib.h>
#define NUMBER_OF_CHARACTERS 27

void find_bigram_x_and_count_of_bigrams(int bigram_x[][NUMBER_OF_CHARACTERS],double* total_bigram_x);      // bigram finder for language_x.txt and finds total number of bigrams in language_x.txt
void find_bigram_of_languages_and_dissimilarities(int bigram_x[][NUMBER_OF_CHARACTERS],int bigram_of_languages[NUMBER_OF_CHARACTERS][NUMBER_OF_CHARACTERS],char filename[][20],int i,double total_bigram_x);    // bigram finder for languages and dissimilarity finder


int main(){
    char filename[5][20] = {"language_1.txt","language_2.txt","language_3.txt","language_4.txt","language_5.txt"};  // file name holder 
    int bigram_x [NUMBER_OF_CHARACTERS][NUMBER_OF_CHARACTERS]= {0};                                                 // bigrams of language_x.txt
    int bigram_of_languages[NUMBER_OF_CHARACTERS][NUMBER_OF_CHARACTERS] = {0};                                      // bigrams of language_12345.txt (same array used multiple times for efficiency)
    double total_bigram_x;                                                      // total number of bigrams in language_x.txt
    int x,y,z;                                                                  // variables for for loops               
    int i=0;                                                                    // variable for increase the filename string one by one 
    find_bigram_x_and_count_of_bigrams(bigram_x,&total_bigram_x);                                               // bigram finder for language_x.txt and finds total number of bigrams in language_x.txt
    for(x=0;x<5;x++){
        find_bigram_of_languages_and_dissimilarities(bigram_x,bigram_of_languages,filename,i,total_bigram_x);   // bigram finder for languages and dissimilarity finder 
        for (y=0;y<NUMBER_OF_CHARACTERS;y++){
            for(z=0;z<NUMBER_OF_CHARACTERS;z++){
                bigram_of_languages[y][z] = 0;                                                                  // resets bigram_of_languages array to use it again for other files
            }
        }
        i++;                                // increase the i value to search next file in filename[i]
    }
    return 0;
}

void find_bigram_x_and_count_of_bigrams(int bigram_x[][NUMBER_OF_CHARACTERS],double* total_bigram_x){       // it reads language_x.txt file only once and stores bigrams in bigrams_x[][] array and it xounts the total bigram number file includes
FILE* fp1;  
    char cur,pre,x,y;
    pre = 0;                                 
    fp1 = fopen("language_x.txt","r");
    
    fscanf(fp1,"%c", & pre);            // read previous letter in the beginning so we can start with pre value in our loop
    while(fscanf(fp1,"%c",&cur)==1){       // reads untill EOF, i checked two character with passing the next character one by one
        if((cur == ' ' || cur == '\t' || cur == '\n' || cur == '\v') && (pre == ' ' || pre == '\t' || pre == '\n' || pre == '\v') ){    // if two serial character is whitespace, it skips to next character without process
          continue;
        }
        else if(cur == '\n') {                                                              // if current character is newline, it skips to next character
            continue; 
        }
        else {
            if(pre == ' ' || pre == '\t' || pre == '\n' || pre == '\v'){                    // if previous value is whitespace, it adds 1 to 27th row cur-97th column of bigram_x[][] (bigram_x[26][cur-97])
                bigram_x[26][cur-97]+=1;
                pre = cur;                                                                  // assign current value to previous value 
            }
            else if(cur == ' ' || cur == '\t' || cur == '\n' || cur == '\v'){               // if current value is whitespace, it adds 1 to 27th column pre-97th row of bigram_x[][] (bigram_x[pre-97][26])
                bigram_x[pre-97][26]+=1;
                pre = cur;                                                                  // assign current value to previous value 
            }
            else{                                                                           // if both characters are letters, it adds 1 to pre-97th row cur-97th column of bigram_x[][]
                bigram_x[pre-97][cur-97]+=1;                                                
                pre = cur;                                                                  // assign current value to previous value 
            } 
        }
    }

    for(x=0;x<NUMBER_OF_CHARACTERS;x++){
        for(y=0;y<NUMBER_OF_CHARACTERS;y++){
            *total_bigram_x = *total_bigram_x + bigram_x[x][y];                             // it counts the total bigram number which languages_x.txt includes by counting bigram_x[][] array. It reads file only once !!!!
        }
    }
}

void find_bigram_of_languages_and_dissimilarities(int bigram_x[][NUMBER_OF_CHARACTERS],int bigram_of_languages[NUMBER_OF_CHARACTERS][NUMBER_OF_CHARACTERS],char filename[][20],int i,double total_bigram_x){ // it reads each file only once and finds dissimilarity with bigram_on_languages[][] array
    FILE* fp2;
    char cur,pre,x,y;
    double total_bigram_of_languages = 0;   // total number of bigrams in language_12345.txt
    double frequency_of_x;                  // frequency of each value in language_x.txt file 
    double frequency_of_languages;          // frequency of each value in language_12345.txt files
    double subtraction_of_frequencies;      // subtraction of frequencies 
    double dissimilarity_value = 0;         // summation of (subtraction of frequencies) -> dissimilarity value
    pre = 0;
    fp2 = fopen(filename[i],"r");
    
    fscanf(fp2,"%c", & pre);
    while(fscanf(fp2,"%c",&cur)==1){

        if((cur == ' ' || cur == '\t' || cur == '\n' || cur == '\v') && (pre == ' ' || pre == '\t' || pre == '\n' || pre == '\v') ){    // if two serial character is whitespace, it skips to next character without process
            continue;
        }
        else if(cur == '\n') {
            continue;                                                                       // if current character is newline, it skips to next character
        }
        else {
            if(pre == ' ' || pre == '\t' || pre == '\n' || pre == '\v'){                    // if previous value is whitespace, it adds 1 to 27th row cur-97th column of bigram_x[][] (bigram_of_languages[26][cur-97])
                bigram_of_languages[26][cur-97]+=1;
                pre = cur;                                                                  // assign current value to previous value
            }
            else if(cur == ' ' || cur == '\t' || cur == '\n' || cur == '\v'){               // if current value is whitespace, it adds 1 to 27th column pre-97th row of bigram_x[][] (bigram_of_languages[pre-97][26])
                bigram_of_languages[pre-97][26]+=1;
                pre = cur;                                                                  // assign current value to previous value
            }
            else{
                bigram_of_languages[pre-97][cur-97]+=1;                                     // if both characters are letters, it adds 1 to pre-97th row cur-97th column of bigram_of_languages[][]
                pre = cur;
            } 
        }
    }
    
    for(x=0;x<27;x++){
        for(y=0;y<27;y++){                                                                           // it counts the total bigram number which languages_x.txt includes by counting bigram_x[][] array. It reads file only once !!!!
            total_bigram_of_languages = total_bigram_of_languages + bigram_of_languages[x][y];      
        }
    }
    
    for (x=0;x<NUMBER_OF_CHARACTERS;x++){
        for(y=0;y<NUMBER_OF_CHARACTERS;y++){
            frequency_of_x = bigram_x[x][y]/total_bigram_x;                                          // frequency of each bigram in language_x.txt file by using bigram_x array. It reads file only once !!!

            frequency_of_languages = bigram_of_languages[x][y]/total_bigram_of_languages;            // frequency of each bigram in language_12345.txt file by using bigram_x array.

            subtraction_of_frequencies = frequency_of_x - frequency_of_languages;                    // subtraction of frequencies of the same bigrams

            if(subtraction_of_frequencies<0.0){                                                      // if subtraction result is negative, it multiplies the result with -1
                subtraction_of_frequencies = subtraction_of_frequencies * (-1.0) ;
            }
            dissimilarity_value = dissimilarity_value + subtraction_of_frequencies;                  // multiplicates the summation of the absolute values of frequencies -> dissimilarity
        }
    }
    printf("%lf\n",dissimilarity_value);                                                             // prints the dissimilarity value
}