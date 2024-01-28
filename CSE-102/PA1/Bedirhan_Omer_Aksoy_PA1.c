#include <stdio.h>
#include <stdlib.h>
#define NUM_CLASS_1 10  /*Macro of class1 size*/
#define NUM_CLASS_2 10  /*Macro of class2 size*/
#define EPSILON 0.001  /*Epsilon macro for divide-by-zero situations*/

void find_average(double* average_x, double* average_y,int class_size); /* FINDS AVERAGE VALUES OF POINTS THAT USER ENTERS FOR CLASS1 AND CLASS2 */
double slope_of_seperating_line(double average2_x, double average2_y, double average1_y, double average1_x);    /* FINDS SLOPE OF SEPARATING LINE */
void find_the_class_of_test_point(double Slope, double average1x, double average1y, double midpointx, double midpointy); /* FINDS THE CLASS OF TEST POINTS*/

int main() {
    int class1 = NUM_CLASS_1;   /*SIZE OF CLASS1 WE WILL USE THIS VARIABLE TO SEND IN FUNCTION*/
    int class2 = NUM_CLASS_2;   /*SIZE OF CLASS2*/
    double average1_x;          
    double average1_y;
    double average2_x;          /*AVERAGE VALUES OF COORDINATES FOR CLASS1 AND CLASS2*/
    double average2_y;
    double mid_point_x;         /*MIDPOINT'S COORDINATES*/
    double mid_point_y;
    double slope;               /*SLOPE OF SEPARATING LINE*/

    find_average(&average1_x,&average1_y,class1);   /*FIND AVERAGE VALUES OF CLASS1 BY SENDING THE ADRESSES OF AVERAGE VARIABLES TO FUNCTION */
    find_average(&average2_x,&average2_y,class2);   /*AND CLASS 2*/
    mid_point_x = (average1_x + average2_x)/2;      /*FIND MIDPOINT'S COORDINATES*/
    mid_point_y = (average1_y + average2_y)/2;

    slope = slope_of_seperating_line( average2_x, average2_y, average1_y,  average1_x);     /*FIND SLOPE VALUE WITH SLOPE FUNCTION*/
    
    find_the_class_of_test_point(slope, average1_x, average1_y, mid_point_x, mid_point_y);  /*FIND THE CLASSES OF TEST POINTS */

return 0;
}

double slope_of_seperating_line (double average2_x, double average2_y, double average1_y, double average1_x){
    
    double slope_of_connecting_line;    
    double slope_separating_line;

    if(average2_x - average1_x == 0){   /*FOR DIVIDE-BY-ZERO SITUATION WE ADD EPSILON*/
        slope_of_connecting_line = (average2_y - average1_y) / (average2_x - average1_x + EPSILON ); /*SLOPE EQUATION FOR CONNECTING LINE (y2-y1)/(x2-x1)*/
    }
    else{
        slope_of_connecting_line = (average2_y - average1_y) / (average2_x - average1_x ); 
    }
    slope_separating_line = (-1 / (slope_of_connecting_line + EPSILON)); /* MULTIPLICATION OF SLOPES OF PERPENDICULAR LINES EQUALS -1 (m1*m2) = -1 */
    
    return slope_separating_line;
}

void find_average(double* average_x, double* average_y,int class_size) {
    int counter;                /*COUNTER FOR FOR LOOP*/
    double x_coordinate;        /*CLASSES COORDINATES THAT USER WILL ENTER*/
    double y_coordinate;
    double total_x = 0;         /*TOTAL VALUES OF X COORDINATES*/
    double total_y = 0;         /*AND Y VALUES*/
    for(counter=0; counter<class_size; counter++){      /*LOOP WILL TURN FOR THE SIZE OF CLASS TIME*/
        scanf("%lf %lf",&x_coordinate,&y_coordinate);
        total_x = total_x + x_coordinate;               /*FIND TOTAL VALUES OF X COORDINATES*/
        total_y = total_y + y_coordinate;               /*AND TOTAL Y VALUES*/
    }

    *average_x = total_x / class_size;      /*DIVIDE TOTAL VALUES WITH CLASS SIZE TO FIND AVERAGE VALUES*/
    *average_y = total_y / class_size;
}

void find_the_class_of_test_point(double Slope, double average1x, double average1y, double midpointx, double midpointy) {  /*I USED LINE EQUATION TO FIND SEPERATING LINES EQUATION */
    double a,b;                                                                                                             /*   y-y1 -  m*(x-x1) = 0  */
    double x_test_coordinate;
    double y_test_coordinate;
    
    while(scanf("%lf %lf",&x_test_coordinate,&y_test_coordinate) == 2){         /*CHECKS THE ENTERED CHARACTERS WETHER THEY ARE DOUBLES OR NOT*/
        a = (average1y - midpointy) - (Slope * (average1x - midpointx));        /* I ENTERED CLASS1'S POINT TO EQUATION TO COMPARE WITH TESTING POINTS */
        b = (y_test_coordinate - midpointy) - (Slope * (x_test_coordinate - midpointx));    /* PUTS TEST POINTS COORDINATES TO SEPARATING LINE'S EQUATION*/
        if(a * b >0) {      /*IF BOTH POINTS ARE IN THE SAME CLASS, THEIR MULTIPLICATION WILL BE POSITIVE AND WE KNOW THAT THERE WON'T BE ANY POINTS ON THE LINE*/
            printf("Class 1\n");
        }
        else {              /*IF THEY AREN'T IN THE SAME CLASS, THEIR MULTIPLICATION WILL BE NEGATIVE*/
            printf("Class 2\n");
        }
    }
}