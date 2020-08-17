#include <stdio.h>
#include <math.h>

#define ROWS 7
#define MAXROW 100
#define COLS12 12
#define COLS24 24
#define MAXCOL 100

#define e12 1
#define e24 2

#define OMEGA "\u03a9"

int main(void){
  
//Create a 7x12 2D areay to store values of E12 series resistors in the range 1 Ohm to 8.2 MegaOhm
double ResistorVal12[ROWS][COLS12] = {1.0, 1.2, 1.5, 1.8, 2.2, 2.7, 3.3, 3.9, 4.7, 5.6, 6.8, 8.2};

//Create a 7x24 2D array to store values of E24 series resistors in the range 1 Ohm to 9.1 MegaOhm
double ResistorVal24[ROWS][COLS24] = {1.0, 1.1, 1.2, 1.3, 1.5, 1.6, 1.8, 2.0, 2.2, 2.4, 2.7, 3.0, 3.3, 3.6, 3.9, 4.3, 4.7, 5.1, 5.6, 6.2, 6.8, 7.5, 8.2, 9.1};

//Ask for user input of required resistor series
int series = 0;
int COLS = 0;

double ResistorVal[MAXROW][MAXCOL] = {0};

printf("Please enter 1 for E12 series resistor values or 2 for E24 series: ");
scanf("%d", &series);

//Build array of resistor values based on selected series
if (series == 1){
  for(int i = 0; i < ROWS; i++){
    for (int j = 0; j < COLS12; j++){
    ResistorVal[i][j] = ResistorVal12[i][j];
    }
  }
    COLS = COLS12;
  } else if (series == 2){
    for(int i = 0; i < ROWS; i++){
    for (int j = 0; j < COLS24; j++){
    ResistorVal[i][j] = ResistorVal24[i][j];
    }
  } 
    COLS = COLS24;
  }


int power = 0;

for (int j = 0; j < COLS; j++){
    for (int i = 1; i < ROWS; i++){
        power++;
        ResistorVal[i][j] = ResistorVal[0][j] * pow(10,power);
    }
    power = 0;
}

//Write array of resistor values to .txt file
FILE *fp;

fp = fopen("ResistorValues.txt","w");

if (fopen == NULL){
    printf("Sorry, could not open file");
}else {
  if (series == 1){
    fprintf(fp, "E12 series resistor values in Ohms as follows:\n\n");
  } else if (series == 2){
    fprintf(fp, "E24 series resistor values in Ohms as follows:\n\n");
  }
    for (int k = 0; k < ROWS; k++){
        for (int h = 0; h < COLS; h++){
        fprintf(fp, "%.1f ",ResistorVal[k][h]);
    }
    fprintf(fp, "\n");
    }
}

fclose(fp);

//Ask for user input of required resistor ratio and tolerance
double ratio = 0;
double tol = 0;
double tolAdj = 0;
double resTest = 0;
int count = 0;

printf("Please enter ratio of R2/R1 required: ");
scanf("%lf", &ratio);

printf("Please specify required tolerance in %%: ");
scanf("%lf", &tol);

tolAdj = tol / 100;

//Set up loop to calculate all possible combinations of resistors and write to .txt file
FILE *resList;

resList = fopen("ResistorCombinations.txt","w");

if (resList == NULL){
    printf("Sorry, could not open file");
}else {
    fprintf(resList, "You can use the following combination of resistors to achieve a ratio of %.4lf with a tolerance of %.2lf%%:\n\n", ratio, tol);
    for (int p = 0; p < ROWS; p++){
        for (int t = 0; t < COLS; t++){
            resTest = ResistorVal[p][t];
            for (int n = 0; n < ROWS; n++){
                for (int m = 0; m < COLS; m++){
                    if ((sqrt(pow(((resTest / ResistorVal[n][m] - ratio) / ratio),2))) <= tolAdj) {
                        count++;
                        fprintf(resList, "%10d.    R2 = %10.1lf %s;    R1 = %10.1lf %s\n", count, resTest, OMEGA, ResistorVal[n][m], OMEGA);
                    }
                }
            }
        }
    }
    fprintf(resList, "\nTotal combinations: %d", count);
}

fclose(resList);

return 0;
}