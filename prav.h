#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Prav{
    double x1, y1, x2, y2, Ip, Ie, Ipe, A, p, e;
}Prav;

Prav NapraviP(double x1, double y1, double x2, double y2, Prav prav){
    prav.x1 = x1;
    prav.y1 = y1;
    prav.x2 = x2;
    prav.y2 = y2;
    double b = abs(x1) + abs(x2);
    double h = abs(y1) + abs(y2);

    prav.p = b/2;
    prav.e = h/2;
    prav.A = b*h;
    prav.Ip = b*(pow(h,3))/12 + prav.A*pow(e, 2);
    prav.Ie = pow(b, 3)*h/12 + prav.A*pow(p, 2);
    prav.Ipe = 0 + prav.A*b*h;
    if(prav.p*prav.e < 0)
        prav.Ipe *= (-1);
    

    return prav;
}
