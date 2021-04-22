#include "FigureSection.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

_Bool FigureSection(struct Shape pol1, struct Shape pol2)
{
    int distSq = (pol1.x - pol2.x) * (pol1.x - pol2.x)
            + (pol1.y - pol2.y) * (pol1.y - pol2.y);
    int radSumSq = (pol1.r + pol2.r) * (pol1.r + pol2.r);
    return !(distSq >= radSumSq);
}
void AllFigureSection(struct Shape* masShape, int countPolygon)
{
    for (int i = 0; i < countPolygon - 1; i++) {
        for (int j = i + 1; j < countPolygon; j++) {
            if (FigureSection(masShape[i], masShape[j])) {
                printf("Figure %d and Figure %d are intersect\n", i + 1, j + 1);
            }
        }
    }
}