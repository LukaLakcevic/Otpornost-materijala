#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Ipro{
    double x1, y1, x2, y2, Ip, Ie, Ipe, A, p, e;
}Ipro;

Ipro NapraviI(double x1, double y1, double x2, double y2, Ipro ipro){
    ipro.x1 = x1;
    ipro.y1 = y1;
    ipro.x2 = x2;
    ipro.y2 = y2;
    ipro.A = 13.2;
    double b = abs(x1) + abs(x2);
    double h = abs(y1) + abs(y2);
    
    ipro.p = b/2;
    ipro.e = h/2;

    if(b == 12){
        ipro.Ip = 318+ipro.A*pow(e, 2);
        ipro.Ie = 27.7+ipro.A*pow(p, 2);
        ipro.Ipe = 0 + ipro.A*p*e;
        if( ipro.p*ipro.e < 0 ){
            ipro.Ipe *= (-1);
        }
    }
    else{
        ipro.Ie = 318+ipro.A*pow(p, 2);
        ipro.Ip = 27.7+ipro.A*pow(e, 2);
        ipro.Ipe = 0 + ipro.A*p*e;
        if( ipro.p*ipro.e < 0 ){
            ipro.Ipe *= (-1);
        }
    }   

   return ipro;
}
