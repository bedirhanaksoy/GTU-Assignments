#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cstring>

using namespace std;

void random_number_creator(int number[],int count);                 // if user entered -r, function creates random number
void matching_number_checker(int number[],int count);               // for both options(-r and -u), function checks correctness of the user's guess

int main(int argc, char** argv)
{
    int number[9];                                                  // holds the secret number
    int count,i,j,parameter_exist=0;                               
                
    count = strlen(argv[1]);                                        // lenght of the type 
    
    if(count>2 || argc!=3){                                         // checks wether lenght of the type is longer than 2 or total number of the argument is more than 3(programs name - operation type - number)
        cout<<"E0"<<endl;   
        exit(1);
    }

    for( i=0;i<count;i++){                                          // checks wether the type name is valid or not
            if(argv[1][i] == '-' && (argv[1][i+1] != 'u' && argv[1][i+1] != 'r' && argv[1][i+1] != ' ')){
                cout<<"E0"<<endl;
                exit(1);

            }
            else if(argv[1][i] == '-'){                             // if parameter sign exists, flag assigns 1
                parameter_exist = 1;
            } 
    }

    if(parameter_exist == 0){                                       // if parameter sign (-) doesnt exists, prints E0 and exit(1)
        cout<<"E0"<<endl;
        exit(1);
    }
    
    if(argv[1][1] == 'r'){                                          // if the operation is r
        count = (int)argv[2][0] - 48;
        if(count<1 || count>9 || strlen(argv[2])>1){                // if digit is 0 or negative or more than 1, prints E0 and exit(1)
            cout<<"E0"<<endl;
            exit(1);
        }                             
        random_number_creator(number,count);                        // creates random number
        matching_number_checker(number,count);                      // asks user for input and checks the correctness
    }
    else if(argv[1][1] == 'u'){                                     // else if the operation is u
        count = strlen(argv[2]);                                    // lenght of the secret number
        if(argv[2][0] == '0'){                                      // if the number starts with 0, it prints E0 and exit(1)
                cout<<"E0"<<endl;
                exit(1);
        }

        for( i=0;i<count;i++){                                      
            if((int)argv[2][i]<48 || (int)argv[2][i]>57){           // if input includes non-integer values, it prints E2 and exit(1)
                cout<<"E2"<<endl;
                exit(1);
            }
            number[i] = (int)argv[2][i] - 48;                       //if the input is valid, it assigns input to number[] array
        }

        for(i=0;i<count;i++){                                       // if there is repetition in input, it prints E0 and exit(1)
            for(j=0;j<i;j++){
                if(number[i] == number[j]){
                    cout<<"E0"<<endl;
                    exit(1);
                }
            }
        }

        matching_number_checker(number,count);                      // asks user for input and checks the correctness
    }
    return 0;
}
void random_number_creator(int number[],int count){
    int temp,i,k;
    int flag=0;                                                     // flag for checking if there is any repetition or not
        srand(time(0));                                             // for real time using while creating random numbers
        for(i=0;i<count;i++){                                       // turns as many times as the digit number
            temp = rand()%10;
            if(temp==0 && i==0){                                    // if it is the first digit, it creates non-zero value
                while(temp==0){
                    temp = rand()%10;
                }
            }
            for(k=0;k<i;k++){                                       // it compare the next random integer(temp) with all the integers that created randomly previously (number[])
                    if(temp==number[k]) flag = 1;
                }
            while(flag==1){                                         // if it is already in number[], it creates new random number till it will be unique
                flag = 0;
                temp = rand()%10;
                for(k=0;k<i;k++){
                    if(temp==number[k]) flag = 1;
                }
            }
            number[i] = temp;                                       // then the new number assings into the number[] array.
        }
}
void matching_number_checker(int number[],int count){
    char chararray[9];                                              // char array for user input each time
    int guess[9];                                                   // int array for assign the user's guess into it after validation
    int match = 0;                                                  // number of matching numbers in users guess with the secret number
    int exist_but_didnt_match=0;                                    // number of existing numbers in  users guess with the secret number but didnt match
    int i,j,lenght;                                                 // integers for for loops and lenght of the input 
    int retry = 0;                                                  // number of retries

    while(match != count && retry<=100){                            // loop will run until all numbers are matching or user reach 100 attempts
        match = 0;                                                  // resets matching value
        exist_but_didnt_match = 0;                                  // and exist_but_didnt_match value each turn
        cin>>chararray;                                             // take user's guess
       
        lenght = strlen(chararray);                                 // lenght of the input 
        
        for(i=0;i<lenght;i++){                                      // checks wether the input is all integers or not by comparing their ascii values
            if((int)chararray[i]<48 || (int)chararray[i]>57){       // if there is non-integer value exists, it prints E2 and exit(1)
                cout<<"E2"<<endl;
                exit(1);
            }
        }
        if(chararray[0] == '0'){                                    // if numbers first digit is zero, it ptints E0 and exit(1)
            cout<<"E0"<<endl;
            exit(1);
        }
        if(lenght!=count) {                                         // if the lenght of the users guess and the lenght of the secret number doesnt match, it prints E1 and exit(1)
            cout<<"E1"<<endl;
            exit(1);
        }
        for(i=0;i<lenght;i++){                                      // if there is any repetition in users guess, it prints E0 and exit(1)
            for(j=0;j<i;j++){
                if(chararray[i] == chararray[j]){
                    cout<<"E0"<<endl;
                    exit(1);
                }
            }
        }

         for( i=0;i<count;i++){                                      // after the validations, user's input assigns into guess[] array
            guess[i] = (int)chararray[i] - 48;
            
        }

        for(i=0;i<count;i++){                                       
            if(guess[i]==number[i]){                                // if the same digits of the secret number and guess matches, match increases +1
                match++;
            }
            else{                                                   // else, it compares with other digits to check if this number exists in the secret number
                for(j=0;j<count;j++){
                    if(guess[i]==number[j]){                        // if it exists, exist_but_didnt_match increases +1
                        exist_but_didnt_match++;
                    }
                }
            }
        }
        retry++;                                                    // retry value increases +1 at each turn   
        if(match == count) continue;                                // if the guess is correct, it doesnt print the match and exist_but_didnt_match values and while loop ends
        cout<<match<<" "<<exist_but_didnt_match<<"\n";
    }
    if(retry>100) cout<<"FAILED";                                   // if retry value reaches over 100, it prints FAILED
    else if(match == count) cout<<"FOUND "<<retry;                  // else if the user's guess is correct, it prints FOUND and retry value
}
