#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Trou{
    double x1, y1, x2, y2, x3, y3, Ip, Ie, Ipe, A, p, e;
}Trou;

Trou NapraviT(double x1, double y1, double x2, double y2, double x3, double y3, Trou trou){
    trou.x1 = x1;
    trou.y1 = y1;
    trou.x2 = x2;
    trou.y2 = y2;
    trou.x3 = x3;
    trou.y3 = y3;
    double b = abs(x2 - x1);
    double h = abs(y2 - y1); 
    trou.A = b*h/2;

    trou.p = (x1+x2+x3)/3;
    trou.e = (y1+y2+y3)/3;

    trou.Ip = b*pow(h,3)/36 + trou.A*pow(trou.e, 2);
    trou.Ie = pow(b, 3)*h/36 + trou.A*pow(trou.p, 2);
    trou.Ipe = pow(b,2)*pow(h,2)/72 + trou.A*trou.e*trou.p;
    if(trou.e<trou.p)
        trou.Ipe *= -1;

    return trou;
}
