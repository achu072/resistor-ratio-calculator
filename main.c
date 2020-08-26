#include <stdio.h>
#include <math.h>
#include "ratio.h"

//Define maximum array parameters
#define ROWS 7      //universal
#define COLS12 12   //E12 array
#define COLS24 24   //E24 array
//***add further resistor arrays here if required*** 

//Dimensions of user selected array
#define MAXROW 100
#define MAXCOL 100

//Define user inputs
#define e12 1
#define e24 2
//***add further resistor arrays here if required***

int main(void){
   
//Create array of base resistor values 
double ResistorVal12[ROWS][COLS12] = {1.0, 1.2, 1.5, 1.8, 2.2, 2.7, 3.3, 3.9, 4.7, 5.6, 6.8, 8.2};    //E12 series

double ResistorVal24[ROWS][COLS24] = {1.0, 1.1, 1.2, 1.3, 1.5, 1.6, 1.8, 2.0, 2.2, 2.4, 2.7, 3.0, 3.3, 3.6, 3.9, 4.3, 4.7, 5.1, 5.6, 6.2, 6.8, 7.5, 8.2, 9.1};         //E24 series
//***add further resistor arrays here if required***

//Get user input to select required array
int series = 0;
int COLS = 0;
int power = 0;

double ResistorVal[MAXROW][MAXCOL] = {0};

printf("Please enter 1 for E12 series resistor values or 2 for E24 series:\n");                       //***add further resistor arrays here if required***
scanf("%d", &series);

//Build array of resistor values based on selected series
if (series == 1) {
  for(int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS12; j++) {
    ResistorVal[i][j] = ResistorVal12[i][j];
    }
  }
    COLS = COLS12;
  } else if (series == 2) {
    for(int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS24; j++) {
    ResistorVal[i][j] = ResistorVal24[i][j];
    }
  } 
    COLS = COLS24;
  }
  //***add further resistor arrays here if required***

for (int j = 0; j < COLS; j++) {
    for (int i = 1; i < ROWS; i++) {
        power++;
        ResistorVal[i][j] = ResistorVal[0][j] * pow(10,power);
    }
    power = 0;
}

//Write array of resistor values to .txt file
FILE *resistorValues;

resistorValues = fopen("ResistorValues.txt","w");

if (resistorValues == NULL) {
    printf("Sorry, could not open file");
}else {
  if (series == 1) {
    fprintf(resistorValues, "E12 series resistor values in Ohms as follows:\n\n");
  } else if (series == 2) {
    fprintf(resistorValues, "E24 series resistor values in Ohms as follows:\n\n");
  }
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
        fprintf(resistorValues, "%.1f ",ResistorVal[i][j]);
    }
    fprintf(resistorValues, "\n");
    }
}
//***add further resistor arrays here if required***
fclose(resistorValues);

//Ask for user input of required resistor ratio and tolerance
double targetRatio = 0;
double tolerance = 0;
double R1 = 0;
double R2 = 0;
double R3 = 0;
int position = 1;

printf("Please enter ratio of R2/R1 required:\n");
scanf("%lf", &targetRatio);

printf("Please specify required tolerance in %%:\n");
scanf("%lf", &tolerance);

//Set up loop to calculate all possible combinations of resistors and write to .txt file
FILE *outputValues;

outputValues = fopen("ResistorCombinations.txt","w");

if (outputValues == NULL) {
    printf("Sorry, could not open file");
}else {
    fprintf(outputValues, "You can use the following combination of resistors R2/R1 to achieve a ratio of %.4lf with a tolerance of %.2lf%%:\n\n", targetRatio, tolerance);
    for (int i = 0; i < ROWS; i++) {
      for (int j = 0; j < COLS; j++) {
         for (int h = 0; h < ROWS; h++) {
           for (int k = 0; k < COLS; k++) {
             R2 = ResistorVal[i][j];
             R1 = ResistorVal[h][k];

            int isOK = testRatioOfTwo(position, R1, R2, outputValues, targetRatio, tolerance);

            if (isOK) {
              position++;
            }
           }
         }
      }
    }
    fprintf(outputValues, "\nTotal combinations: %d\n\n", (position -1));

    if (position == 1) {
      fprintf(outputValues, "You can use the following combination of resistors R2/(R1 + R3) to achieve a ratio of %.4lf with a tolerance of %.2lf%%:\n\n", targetRatio, tolerance);
      for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
           for (int h = 0; h < ROWS; h++) {
             for (int k = 0; k < COLS; k++) {
               for (int l = 0; l < ROWS; l++) {
                 for (int m = 0; m < COLS; m++) {
                    R2 = ResistorVal[i][j];
                    R1 = ResistorVal[h][k];
                    R3 = ResistorVal[l][m];

                    int isOK = testRatioOfThree(position, R1, R2, R3, outputValues, targetRatio, tolerance);

                    if (isOK) {
                    position++;
                    }
                 }
               }
             }
           }
        }
      }
      fprintf(outputValues, "\nTotal combinations: %d\n\n", (position -1));
    }
}

fclose(outputValues);

return 0;
}