#include "lib/Calc_Sq_Perim.h"
#include "lib/CheckInjectSpace.h"
#include "lib/FigureSection.h"
#include "lib/OutputError.h"
#include "lib/OutputInfo.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int ErrorShape;
extern int ErrorX;
extern int ErrorY;
extern int ErrorR;
extern int flagOverRead;

int main(void)
{
    int maxInputLength = 80;
    char inputWords[maxInputLength];

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
    ErrorShape = 0;
    ErrorX = 0;
    ErrorY = 0;
    ErrorR = 0;
    flagOverRead = 0;

    int countPolygon = 0;
    printf("Enter count of shapes:");
    scanf("%d\n", &countPolygon);

    struct Shape masShape[countPolygon];

    for (int i = 0; i < countPolygon; i++) {
        ErrorShape = 0;
        ErrorX = 0;
        ErrorY = 0;
        ErrorR = 0;
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

        struct Shape polygon;
        if (!(ErrorShape > 0 || ErrorX > 0 || ErrorY > 0 || ErrorR > 0)) {
            // strcpy(polygon.shape, shape);
            polygon.x = xShape;
            polygon.y = yShape;
            polygon.r = RShape;
            polygon.sq = squarShape;
            polygon.per = perimShape;
        } else {
            polygon.errX = ErrorX;
            polygon.errY = ErrorY;
            polygon.errR = ErrorR;
            polygon.errShape = ErrorShape;
        }

        if (polygon.errX > 1) {
            polygon.errX = 0;
        }
        if (polygon.errY > 1) {
            polygon.errY = 0;
        }
        if (polygon.errR > 1) {
            polygon.errR = 0;
        }
        if (polygon.errShape > 1) {
            polygon.errShape = 0;
        }
        masShape[i] = polygon;
        ErrorShape = 0;
        ErrorX = 0;
        ErrorY = 0;
        ErrorR = 0;
        polygon.errX = 0;
        polygon.errY = 0;
        polygon.errR = 0;
        polygon.errShape = 0;
        polygon.x = 0;
        polygon.y = 0;
        polygon.r = 0;
        polygon.sq = 0;
        polygon.per = 0;
    }

    for (int i = 0; i < countPolygon; i++) {
        printf("%d shape:\n", i + 1);
        if (!(FormatCheck(
                    masShape[i].errX,
                    masShape[i].errY,
                    masShape[i].errR,
                    masShape[i].errShape))) {
            OutputError(
                    masShape[i].errShape,
                    masShape[i].errX,
                    masShape[i].errY,
                    masShape[i].errR);
        } else {
            OutputInfo(
                    masShape[i].shape,
                    masShape[i].x,
                    masShape[i].y,
                    masShape[i].r,
                    masShape[i].sq,
                    masShape[i].per);
        }
        printf("\n\n\n");
    }
    AllFigureSection(masShape, countPolygon);
}