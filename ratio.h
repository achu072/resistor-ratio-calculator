//Function prototypes for resistor ratio calculations
double getRatioOfTwo(double R1, double R2);
double getRatioOfThree(double R1, double R2, double R3);
int isWithinTolerance(double testRatio, double targetRatio, double tolerance);
void printRatioOfTwo(double ratio, double R1, double R2, FILE *fp, int position);
void printRatioOfThree(double ratio, double R1, double R2, double R3, FILE *fp, int position);
int testRatioOfTwo(int position, double R1, double R2, FILE *fp, double targetRatio, double tolerance);
int testRatioOfThree(int position, double R1, double R2, double R3, FILE *fp, double targetRatio, double tolerance);