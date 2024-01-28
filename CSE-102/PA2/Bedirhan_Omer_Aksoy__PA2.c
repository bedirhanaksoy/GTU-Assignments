#include <stdio.h>
#include <stdlib.h>

void find_repeated_numbers(int* repeated_numbers, int *size,int holder,int i); // THIS FUNCTION FINDS REPEATED NUMBERS AND FILLS REPEATED_NUMBER ARRAY
void find_repetition_number(int* repeated_numbers,int* repetition_counter,int size,int holder,int i); //THIS FUNCTION COUNTS THE NUMBER OF REPETITION AND FILLS REPETITION_COUNTER ARRAY
void put_numbers_in_order(int* repeated_numbers,int* repetition_counter,int size,int i,int j);// THIS FUNCTION PUTS NUMBERS IN ORDER TO THEIR GREATNESS (SMALL TO BIG)

int main (){
    
    int repetition_counter[100]; // THIS ARRAY HOLDS THE NUMBER OF REPETITION AND I DECLARED ITS SIZE 100 BECAUSE IT CAN BE 100 DIFFERENT NUMBER IN INPUT.TXT
    int repeated_numbers[100];   // THIS ARRAY HOLDS REPEATED NUMBERS AND I DECLARED ITS SIZE 100 BECAUSE OF THE SAME REASON
    int holder;                  // IT HOLDS THE NUMBERS TEMPORARILY WHILE WE READ INTEGERS FROM FILE 
    int i,j;                     // I DECLARED THESE INTEGERS BECAUSE I DON'T WANT TO DECLARE OTHER INTEGERS IN FUNCTIONS FOR FOR LOOPS, I SENT THEM INTO FUNCTIONS AS AN ARGUMENT
    int size=0;                  // IT IS SIZE OF OUR ARRAYS 


                                                                
    find_repeated_numbers(repeated_numbers , &size,holder,i);   // I SENT REPEATED_NUMBERS ARRAY AS A (MAYBE NOT THE CORRECT DEFINITION) POINTER TO MODIFY IT INTO FUNCTION, I SENT THE SIZE VARIABLES ADDRESS TO USE IT AGAIN LATER,I SENT HOLDER TO HOLD INTEGERS TEMPORARILY WHILE WE READ NUMBERS FROM FILE AND i VARIABLE IS FOR FOR LOOP.
    find_repetition_number(repeated_numbers , repetition_counter , size , holder,i);  //I SENT REPEATED_NUMBERS TO TAKE THEM ONE BY ONE AND COUNT THE NUMBER OF REPETITION AND FILL REPETITION_COUNTER ARRAY, I SENT ARRAY VARIABLES ITSELF THIS TIME BECAUSE WE KNOW THE SIZE NOW, I SENT THE HOLDER FOR HOLD INTEGERS TEMP. WHILE WE READ FILE, i FOR FOR LOOP.
    put_numbers_in_order(repeated_numbers ,repetition_counter , size,i,j);// I SENT BOTH OF OUR ARRAYS AND THEIR SIZE TO PUT THEM ORDER, i AND j FOR FOR LOOPS 
    
    FILE *fp3 = fopen("output.txt", "w");// I DECLARED OUTPUT.TXT 
    
    for(i=0;i<size;i++){    // IT TURNS AS MANY AS ARRAYS SIZE 
    fprintf(fp3,"%d : %d \n",repeated_numbers[i],repetition_counter[i]);
    }
    fclose(fp3);    // I CLOSED THE OUTPUT.TXT

    return 0;
}
void find_repeated_numbers(int *repeated_numbers, int *size,int holder,int i){ // I SENT THE ADDRESS OF THE ARRAY AND ITS SIZE TO MODIFY IT IN FUNCTION AND USE IT IN MAIN
    int flag = 0;
    FILE* fp1 = fopen("input.txt","r");    // I OPEN INPUT.TXT IN READING MODE 
    while(fscanf(fp1, "%d",&holder)==1){   // THIS LOOP TURNS WHILE FSCANF SUCCESSFULLY CONVERT DATAS INTO INTEGER BEFORE END OF FILE
        if(*size==0){                      // THIS IF BLOCK IS FOR 0TH ELEMENT OF REPEATED_NUMBERS ARRAY. IF IT IS 0TH ELEMENT , HOLDER DIRECTLY DEFINE 0TH (FIRST) ELEMENT OF REPEATED_NUMBERS
            repeated_numbers[*size]=holder;
            *size = *size + 1;             // INCREASES THE SIZE AND MAKE IT 1
        }
        else{                              // FROM NOW ON LOOP WILL ENTER THIS BLOCK 
            for(i=0;i<=*size;i++){         // FIRST IT CHECKS WHETHER THE HOLDER IS ELEMENT OF REPEATED_NUMBERS OR NOT. IF IT IS, IT MAKES FLAG = 1 AND SKIP THAT NUMBER BECAUSE WE WANT TO FIND EACH UNIQUE ELEMENTS NOW
                if(holder == repeated_numbers[i]){
                    flag=1;
                }
            }
            if(flag==0){                   // IF FLAG == 0 IT MEANS THAT HOLDER IS ELEMENT OF REPEATED_NUMBERS AND WE SKIP IT
            repeated_numbers[*size]=holder;
            *size = *size + 1;             // INCREASES SIZE 
            }       
        }
        flag=0;                            // MAKES FLAG = 0 IN EVERY CYCLE
    }
    fclose(fp1);                        
}
void find_repetition_number(int* repeated_numbers,int* repetition_counter,int size,int holder,int i){ //I SENT REPEATED_NUMBERS TO TAKE THEM ONE BY ONE AND COUNT THE NUMBER OF REPETITION AND FILL REPETITION_COUNTER ARRAY, I SENT ARRAY VARIABLES ITSELF THIS TIME BECAUSE WE KNOW THE SIZE NOW, I SENT THE HOLDER FOR HOLD INTEGERS TEMP. WHILE WE READ FILE, i FOR FOR LOOP.
    FILE* fp2 = fopen("input.txt","r");                 // I OPENED INPUT.TXT TO COUNT REPETITIONS OF EACH ELEMENT IN REPEATED_NUMBERS ARRAY
    int counter=0;                                      // COUNTER FOR REPETITIONN
    fseek(fp2,0,SEEK_SET);
    for(i=0;i<size;i++){                                // IT TURNS AS MANY AS ARRAYS SIZE BECAUSE WE WILL CHECK ONLY REPEATED_NUMBERS ARRAY'S ELEMENT'S
        while(fscanf(fp2, "%d",&holder)==1){            // THIS LOOP TURNS WHILE FSCANF SUCCESSFULLY CONVERT DATAS INTO INTEGER BEFORE END OF FILE
            if(holder == repeated_numbers[i]){          // IF HOLDER IS AN ELEMENT OF REPEATED_NUMBERS, COUNTER INCREASES +1 AND IT SCANS ALL THE FILE
                counter+=1;
            }
        }
        repetition_counter[i]=counter;                  //IT ASSIGNS REPETITION_COUNTER'S i'TH ELEMENT AS COUNTER
        counter=0;                                      //RESET THE COUNTER
        fseek(fp2,0,SEEK_SET);                          //TAKE THE CURSOR BEGGINING OF THE FILE TO SCAN WHOLE FILE AGAIN
    }
    fclose(fp2);                                        //CLOSE THE INPUT.TXT
}
void put_numbers_in_order(int* repeated_numbers,int* repetition_counter,int size,int i,int j){// THIS FUNCTION SORTS THEM SMALLEST TO LARGEST IN REPETITION. IF THE REPETITIONS OF NUMBERS ARE SAME, SMALLER ONE COMES FORWARD IN REPEATED_NUMBERS ARRAY
    int temp_numbers;                              // TEMPORARY HOLDER FOR REPLACE THE ELEMENTS 
    for (i=0; i<size; i++) {                                    // IT TURNS AS MANY AS ARRAYS SIZE 
        for (j=i+1; j<size; j++) {                              // IT TURNS AS MANY AS ARRAYS SIZE TOO BUT j STARTS ONE ELEMENT FORWARD FROM i BECAUSE IN THIS LOOP WE COMPARE i'TH ELEMENT WITH THE NUMBERS AFTER i'TH ELEMENT TO SORT THEM SMALLER TO BIGGER
            if(repetition_counter[i] > repetition_counter[j]) { // IT SORTS THE REPETITION COUNTER BECAUSE WE HAVE TO CHECK THE COUNT OF REPETITION FIRSTÇ IF i'TH ELEMENT IS GREATER THAN j'TH ELEMENT (i IS SMALLER THAN j, i'TH ELEMENT WILL BE PRINTED FIRST) i'TH ELEMENT AND j'TH ELEMENT WILL BE SWAPPED. AND WE CHECK EVERY 
                temp_numbers = repetition_counter[i];           
                repetition_counter[i] = repetition_counter[j];  // IT SWAPS i'TH ELEMENT AND j'TH ELEMENT
                repetition_counter[j] = temp_numbers;           

                temp_numbers = repeated_numbers[i];             // ACCORDING TO THEIR COUNT OF REPETITION, WE MAKE THE SAME SORTING OPERATIONS IN REPEATED_NUMBERS ARRAY
                repeated_numbers[i] = repeated_numbers[j];
                repeated_numbers[j] = temp_numbers;
            }     
        }     
    }    
    for(i=0;i<size;i++){                                        // IF THE COUNT OF REPETITIONS ARE SAME, SMALLER ONE WILL APPEAR FIRST 
        for(j=i+1;j<size;j++){
            if (repetition_counter[i] == repetition_counter[j] && repeated_numbers[j] < repeated_numbers[i]) // IF THEIR COUNT OF REPETITION IS SAME, AND i'TH ELEMENT IS BIGGER THAN j'TH ELEMENT(j IS BIGGER THAN i), j'TH ELEMENT AND i'TH ELEMENT WILL BE SWAPPED
            {
                    temp_numbers = repeated_numbers[i];  
                    repeated_numbers[i] = repeated_numbers[j];              //ACCORDING TO THEIR GREATNESS, WE MAKE THE SORTING OPERATIONS IN REPEATED_NUMBERS ARRAY
                    repeated_numbers[j]= temp_numbers;
            }
            
        }
    }
}