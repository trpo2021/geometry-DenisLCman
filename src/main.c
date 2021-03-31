#include "lib/Calc_Sq_Perim.h"
#include "lib/CheckInjectSpace.h"
#include "lib/OutputError.h"
#include "lib/OutputInfo.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ErrorShape = 0;
int ErrorX = 0;
int ErrorY = 0;
int ErrorR = 0;
int flagOverRead = 0;

int main(void)
{
    int maxInputLength = 80;
    char inputWords[maxInputLength];
    /*
    struct Shape{
    char *shape;
    double x;
    double y;
    double r;
    double sq;
    double per;
    } obj_shape;
    */
    char shmass[] = "circle";
    int endShape = 0;
    int endCoorx = 0;
    int endCoory = 0;
    int endRad = 0;
    double xShape = 0;
    double yShape = 0;
    double RShape = 0;
    double squarShape = 0;
    double perimShape = 0;

    // int countPolygon = 0;
    // printf("Enter count of shapes:");
    // scanf("%d",&countPolygon);

    // struct Shape masShape[countPolygon];

    fgets(inputWords, maxInputLength, stdin);
    int inputLength = strlen(inputWords);

    for (int i = 0; i < inputLength; i++) {
        if (inputWords[i] == '(') {
            endShape = i;
        }
        if (inputWords[i] == ' ') {
            endCoorx = i;
        }
        if (inputWords[i] == ',') {
            endCoory = i;
        }
        if (inputWords[i] == ')') {
            endRad = i;
        }
    }

    char shape[endShape];
    strncpy(shape, inputWords, endShape);

    if (strcmp(shape, shmass) == 0) {
    } else {
        ErrorShape = 1;
    }
    xShape = CheckInjectSpace(endShape, endCoorx, inputWords, 'x');
    yShape = CheckInjectSpace(endCoorx, endCoory, inputWords, 'y');
    RShape = CheckInjectSpace(endCoory, endRad, inputWords, 'r');

    squarShape = Calc_Sq_Perim(RShape, 1);
    perimShape = Calc_Sq_Perim(RShape, 2);

    if (ErrorShape == 0 && ErrorX == 0 && ErrorY == 0 && ErrorR == 0) {
        OutputInfo(shape, xShape, yShape, RShape, squarShape, perimShape);
    } else {
        OutputError();
    }
}