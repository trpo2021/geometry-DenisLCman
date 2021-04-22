#ifndef FIGURESECTION_H_
#define FIGURESECTION_H_

struct Shape {
    char* shape;
    double x;
    double y;
    double r;
    double sq;
    double per;
    int errX;
    int errY;
    int errR;
    int errShape;
};

_Bool FigureSection(struct Shape pol1, struct Shape pol2);
void AllFigureSection(struct Shape* masShape, int countPolygon);
#endif