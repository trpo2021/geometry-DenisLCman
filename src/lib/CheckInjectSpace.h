#ifndef CHECKINJECTSPACE_H_
#define CHECKINJECTSPACE_H_

int ErrorShape;
int ErrorX;
int ErrorY;
int ErrorR;
int flagOverRead;

double
CheckInjectSpace(int beginSpace, int endSpace, char InputWords[], char atrib);

_Bool FormatCheck(int errX, int errY, int errR, int errShape);
#endif
