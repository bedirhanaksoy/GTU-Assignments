#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CARB_CAL_1G 4 /* Number of calories in 1g carbohydrate */
#define PROTEIN_CAL_1G 4 /* Number of calories in 1g protein */
#define FAT_CAL_1G 9 /* Number of calories in 1g fat */
#define WATER_CAL_1G 0 /* Number of calories in 1g water */

void parse_percentage(double* carb, double* protein, double* fat, double* water, int g);
void parse_object(char obj[][30],int *grams,int *n_objects);
void question(char* obj, int g, double* carb, double* protein, double* fat, double* water);

int main(){
    
    int grams[20];
    int g = -1;
    double carb=0;
    double protein=0;
    double fat=0;
    double water=0;
    double total_cal = 0;
    int bytes_read;
    size_t size = 10;
    char *string;

    printf("What is meal ?\n");   
    string = (char *) malloc (size);
    bytes_read = getline (&string, &size, stdin);
    string[bytes_read-1]='\0';
    question(string,g,&carb,&protein,&fat,&water);

    total_cal = (carb*CARB_CAL_1G + protein*PROTEIN_CAL_1G + fat*FAT_CAL_1G);
    g = carb + protein + fat + water;

    printf("Total calories is %.2lf in a %dg %s. %% %.2lf calories from carbs, %% %.2lf calories from proteins, %% %.2lf calories from fats.",total_cal,g,string,((carb*CARB_CAL_1G)/total_cal)*100,((protein*PROTEIN_CAL_1G)/total_cal)*100,((fat*FAT_CAL_1G)/total_cal)*100);
    return 0;
}

void parse_percentage(double* carb, double* protein, double* fat, double* water, int g){
    int i;
    double c,p,f,w;
    int bytes_read;
    size_t size = 30;
    char *string;
    char objects[20][30];
    string = (char *) malloc (size);
    bytes_read = getline (&string, &size, stdin);
    char stream[bytes_read];
    fflush(stdin);
    for(i=0;i<bytes_read-1;i++){
        stream[i] = string[i];
    }
    for(i=0;i<bytes_read;i++){
        if((57<stream[i] || stream[i]<48) && stream[i]!= 46 ){
            stream[i] = ' ';
        }        
    }
    sscanf(stream,"%lf %lf %lf", &c,&p,&f);
    *carb = ((g * c)/100);
    *protein = ((g * p)/100);
    *fat = ((g * f)/100);
    *water = g-(((f+p+c)*g)/100);
}   
void parse_object(char obj[][30],int *grams,int *n_objects){
    int i;
    int j=0;
    int k=0;
    int bytes_read;
    size_t size = 50;
    char *string;
    char objects[20][30];
    int flag = 0;
    string = (char *) malloc (size);
    bytes_read = getline (&string, &size, stdin);

    char stream[bytes_read];
    fflush(stdin);
    for(i=0;i<bytes_read;i++){
        stream[i] = string[i];
    }
    for(i=0;i<bytes_read-1;i++){
        if(stream[i] == ' '){
            continue;
        }
        else if(stream[i] == ','){
            j++;
            k=0;
            continue;
        }
        else if(stream[i] == '\0'){
            continue;
        }
        objects[j][k] = stream[i];
        k++;
    }
    for (i=0;i<j+1;i++){
        int lenght = strlen(objects[i]);
        for(k=0;k<lenght ;k++){
            if(objects[i][k] == '('){
                objects[i][k] = ' ';
                flag = 1;
                for(int z=k+1; z<k+5;z++){
                    if(objects[i][z] == 'g') objects[i][k] = ' ';
                    if(objects[i][z] == ')') objects[i][k] = ' ';
                }
            }
        }
        if(flag ==1){
            sscanf(objects[i],"%s %d",obj[i],&grams[i]);
            obj[i][lenght] = '\0';
        }
        else{
            grams[i] = -1;
            sscanf(objects[i],"%s",obj[i]);
            obj[i][lenght] = '\0';
        }
        flag = 0;
    }
    free(string);
    *n_objects = j+1;
    
}
void question(char* obj, int g, double* carb, double* protein, double* fat, double* water){

    double carb_element = 0;
    double protein_element = 0;
    double fat_element = 0;
    double water_element = 0;

    if(g!=-1){
        printf("List the amount macro nutrients in %s:\n", obj);
        fflush(stdout);
        parse_percentage(&carb_element,&protein_element,&fat_element,&water_element,g);
        *carb = carb_element;
        *protein = protein_element;
        *fat = fat_element;
        *water = water_element;
    }
    else {
        printf("What is %s ?\n",obj);
        fflush(stdout);
        char objects[20][30];
        int grams[20];
        int n_objects;
        parse_object(objects,grams,&n_objects);

        for(int i=0; i<n_objects;i++){
            question(objects[i],grams[i],&carb_element,&protein_element,&fat_element,&water_element);
            *carb = *carb + carb_element;
            *protein = *protein + protein_element;
            *fat = *fat + fat_element;
            *water = *water + water_element;

            carb_element =0;
            protein_element=0;
            fat_element=0;
            water_element=0;
        }
    }
}