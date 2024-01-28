#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN_1 10    /*max lenght of words*/
#define MAX_LEN_2 250   /*max lenght of columns*/
void search_eight_ways_and_print_output(char words[][MAX_LEN_1], char letters[][MAX_LEN_2], int size1, int size2, int search,int col,int row,int len1, int len2);
int main() {
    int col = 0;                                /*      column varable for searching.                                                        */
    int row = 0;                                /*      row variable for searching. */
    int len1,len2;                              /*      lenght variables for each word and column for use program stack more efficiently.    */
    int search=0;                               /*      the number of element that we will search from words[search].                        */
    int i = 0;                                  /*      i and j variables for loops.                                                         */
    int j = 0;
    int size1=0;                                /*      size1 is the count of words inside words[][] string.                                 */
    int size2=0;                                /*      size 2 is the count of lines inside letters[][] string.                              */
    char a[MAX_LEN_1];                          /*      i used a and b strings to calculate size1 and size2.                                 */
    char b[MAX_LEN_2];      
    FILE *f1;                                   /*      file pointers for input1.txt and input2.txt.                                         */
    FILE *f2;                 

    f1 = fopen("input1.txt", "r");              /*      i could not make these operations in a function because i have to calculate the lenght of information it include then i will declare the strings according to lenght of files */
    while(fscanf(f1,"%s",a) == 1){              /*      counter for size 1 */
        size1++;
    }
    char words[size1][MAX_LEN_1];               /*      declare string according to size of input1.txt      */
    fseek(f1,0,SEEK_SET);                       /*      seek to begining of the file                        */

    while(1) {                  

        fscanf(f1, "%s", words[i]);             /*      scan words from file to words[]                     */    

        if(feof(f1)){                           /*      until end of file                                   */
            break;
        }
        i++;
    }
    fclose(f1);         

    f2 = fopen("input2.txt", "r");  
    while(fscanf(f2,"%s",b) == 1){              /*      counter for size 2*/
        size2++;
    }
    char letters[size2][MAX_LEN_2];             /*      declare letters[][] according to size of input2.txt */
    fseek(f2,0,SEEK_SET);                       /*      seek to beggining of file*/
    i=0;

    while(1) {
        
        fscanf(f2, "%s", letters[i]);           /*      scan letters as columns from file to letters[][]*/

        if(feof(f2)){
            break;
        }
        i++;
    }
    fclose(f2);
    /*          it searchs every ways and prints the output     */
    search_eight_ways_and_print_output(words,letters,size1,size2,search,col,row,len1,len2);     
    
    
    

    return 0;
}
void search_eight_ways_and_print_output(char words[][MAX_LEN_1], char letters[][MAX_LEN_2], int size1, int size2, int search,int col,int row,int len1, int len2){
    FILE *f3;
    f3 = fopen("output.txt","w");                                                /*     file pointer for output.txt and open the output.txt in w mode. So we dont have to delete output.txt to try another input2.txt file.     */
    int flag = 1;
    int i,j,k;
    
    for(search=0;search<size1;search++){                                             /*     this for loop prints ways and coordinates wth respect to input1.txt's word order */
        /*east*/                       
        len1 = strlen(words[search]);                                                   /*  lenght of the current word that we are searching    */
        for (row=0; row<=size2;row++){
            len2 = strlen(letters[row]);                                                /*   lenght of the current row                          */
            for(col=0;col<=len2-len1;col++){                                            /*   it moves the flow east way in every column         */
                flag=1;  
                for (i = col; i < col + len1; i++) {                                    
                    if (letters[row][i] != words[search][i-col]) flag = 0;              /*  if the letters dont match, it makes flag 0          */
                }
                if (flag == 1) {
                    fprintf(f3,"%s (%d %d) E \n",words[search],row+1,i-len1+1);         /*  if the flag is not zero, it means its matched and it prints the file the coordinates */
                }   
            }
        }
        /*west*/
        for (row=0; row<=size2;row++){                                                  /*   it moves the flow west way in every column         */
            len2 = strlen(letters[row]);                                                /*   lenght of the current row                          */
            for(col=len2;col>len1-1;col--){  
                flag=1;  
                for (i = col; i > col - len1; i--) {
                    if (letters[row][i] != words[search][col-i]) flag = 0;              /*  if the letters dont match, it makes flag 0          */
                }
                if (flag == 1) {                                                        /*  if the flag is not zero, it means its matched and it prints the file the coordinates */
                    fprintf(f3,"%s (%d %d) W\n",words[search],row+1,i+len1+1);
                }   
            }
        }

        /*North*/
        for(i=0;i<size2;i++){
            if(strlen(letters[i])>len2) len2 = strlen(letters[i]);                      /*   it finds the longest column and make comparisons until that column's end*/
        }
        for(col=0; col<=len2;col++){                                                    /*   it moves the flow north way in every column         */
            for(row=size2;row>len1-1;row--){  
                flag=1;  
                for (i = row; i > row - len1; i--) {
                    if (letters[i][col] != words[search][row-i]) flag = 0;
                }
                if (flag == 1) {
                    fprintf(f3,"%s (%d %d) N\n",words[search],row+1,col+1);
                }   
            }
        }

        /*South*/
        for(col=0; col<len2;col++){
            for(row=0;row<size2-len1;row++){                                             /*   it moves the flow north way in every column         */
                flag=1;                                         
                for (i = row; i < row + len1; i++) {
                    if (letters[i][col] != words[search][i-row]) flag = 0;
                }
                if (flag == 1) {
                    fprintf(f3,"%s (%d %d) S\n",words[search],row+1,col+1);
                }   
            }
        }

        /*South East*/
        for(col=0; col<len2-len1;col++){                                                            /*   it starts from the corner and ends in the opposite corner so there is no overlapping or repetiton of any crossline*/
            for(row=size2-len1;row>=0;row--){  
                flag=1;  
                for (i = row, j = col, k = 0; i < row + len1 || j< col + len1; i++, j++, k++) {     /*   it moves the flow south east way in every column         */
                    if (letters[i][j] != words[search][k]) flag = 0;
                }
                if (flag == 1) {                                                                    /*  if the flag is not zero, it means its matched and it prints the file the coordinates */
                    fprintf(f3,"%s (%d %d) SE\n",words[search],row+1,col+1);
                }   
            }
        }
        /*South West*/
        for(col=len2; col>len1;col--){
            for(row=size2-len1;row>=0;row--){                                                       /*   it moves the flow south west way in every column         */
                flag=1;  
                for (i = row, j = col, k = 0; i < row + len1 || j> col - len1; i++, j--, k++) {
                    if (letters[i][j] != words[search][k]) flag = 0;
                }
                if (flag == 1) {
                    fprintf(f3,"%s (%d %d) SW\n",words[search],row+1,col+1);
                }   
            }
        }

        /*North East*/
        for(col=len2-len1; col>0;col--){                                                            /*   it moves the flow north east way in every column         */
            for(row=size2;row>0;row--){  
                flag=1;  
                for (i = row, j = col, k = 0; i > row - len1|| j < col + len1; i--, j++, k++) {     
                    if (letters[i][j] != words[search][k]) flag = 0;
                }
                if (flag == 1) {
                    fprintf(f3,"%s (%d %d) NE\n",words[search],row+1,col+1);
                }   
            }
        }
        /*North West*/
        for(col=len2; col>len1;col--){                                                              /*   it moves the flow north west way in every column         */
            for(row=0;row<=size2;row++){  
                flag=1;  
                for (i = row, j = col, k = 0; i > row - len1|| j>col  - len1; i--, j--, k++) {
                    if (letters[i][j] != words[search][k]) flag = 0;
                }
                if (flag == 1) {                                                                    /*  if the flag is not zero, it means its matched and it prints the file the coordinates */
                    fprintf(f3,"%s (%d %d) NW\n",words[search],row+1,col+1);
                }   
            }
        }
    }
    fclose(f3);                                                                                     /*  close the output.txt */
    
}



