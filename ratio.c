#include <stdio.h>
#include <math.h>
#include "ratio.h"

#define OMEGA "\u03a9"

//Compute ratio of two resistors Ratio = R2/R1
double getRatioOfTwo(double R1, double R2) {
  return (R2/R1);
}

//Compute ratio of three resistors Ratio = R2/(R1 + R3)
double getRatioOfThree(double R1, double R2, double R3) {
  return (R2/(R1 + R3));
}

//Check if ratio is within tolerance (1 = True, 0 = False)
int isWithinTolerance(double testRatio, double targetRatio, double tolerance) {
  double adjTolerance = tolerance / 100;
  if ((sqrt(pow(((testRatio - targetRatio) / targetRatio),2))) <= adjTolerance) {
    return 1;
  } else {
    return 0;
  }
}

//Print ratio to file as a formatted string
void printRatioOfTwo(double ratio, double R1, double R2, FILE *fp, int position) {
  fprintf(fp, "%10d.    R2 = %10.1lf %s;    R1 = %10.1lf %s\n", position, R2, OMEGA, R1, OMEGA);
}

void printRatioOfThree(double ratio, double R1, double R2, double R3, FILE *fp, int position) {
  fprintf(fp, "%10d.    R2 = %10.1lf %s;    R1 = %10.1lf %s;    R3 = %10.1lf %s\n", position, R2, OMEGA, R1, OMEGA, R3, OMEGA);
}

//Test ratio and print to file if within tolerance (return 1 if ratio printed, return 0 if no ratio printed)
int testRatioOfTwo(int position, double R1, double R2, FILE *fp, double targetRatio, double tolerance) {
  double ratio = getRatioOfTwo(R1, R2);
  int isWithin = isWithinTolerance(ratio, targetRatio, tolerance);

  if (isWithin) {
    printRatioOfTwo(ratio, R1, R2, fp, position);
  }

  return isWithin;
}

int testRatioOfThree(int position, double R1, double R2, double R3, FILE *fp, double targetRatio, double tolerance){
  double ratio = getRatioOfThree(R1, R2, R3);
  int isWithin = isWithinTolerance(ratio, targetRatio, tolerance);

  if (isWithin) {
    printRatioOfThree(ratio, R1, R2, R3, fp, position);
  }

  return isWithin;
}