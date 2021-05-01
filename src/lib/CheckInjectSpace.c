#include "CheckInjectSpace.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double
CheckInjectSpace(int beginSpace, int endSpace, char inputWords[], char atrib)
{
    double atribShape;
    for (int i = beginSpace + 1; i < endSpace; i++) {
        if ((inputWords[i] >= '0' && inputWords[i] <= '9')
            || (inputWords[i] == '.') || (inputWords[i] == '-')) {
            if (flagOverRead == 0) {
                atribShape = atof(&inputWords[i]);
                flagOverRead = 1;
            }
        } else {
            if (atrib == 'x') {
                ErrorX = 1;
            }
            if (atrib == 'y') {
                ErrorY = 1;
            }
            if (atrib == 'r') {
                ErrorR = 1;
            }
            break;
        }
    }
    flagOverRead = 0;
    return atribShape;
}

_Bool FormatCheck(int errX, int errY, int errR, int errShape)
{
    if (errShape > 0 || errX > 0 || errY > 0 || errR > 0) {
        return 0;
    }
    return 1;
}