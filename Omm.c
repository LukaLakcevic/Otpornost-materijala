#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "prav.h"
#include "trou.h"
#include "Ipro.h"


int main(){

    printf("Dobro dosili \n");
    printf("Upozorenje! Program ne funkcionise za figure koje treba oduzeti.\n");
    double bp, bt, bi, Ip = 0, Ie = 0, Ipe = 0, Ix, Iy, Ixy, I1, I2, i1, i2, A = 0, p, e, a;
    printf("Broj pravougaonika: ");
    scanf("%lf", &bp);
    printf("Unseite broj trouglova: ");
    scanf("%lf", &bt);
    printf("Unesite broj I120 profila: ");
    scanf("%lf", &bi);
    double x1, y1, x2, y2, x3, y3;
    Prav pr;
    Trou t;
    Ipro ip;

    Prav nizP[(int)bp];
    Trou nizT[(int)bt];
    Ipro nizI[(int)bi];

    if(bp > 0){
    printf("Pravougaonici:\n");
    for(int i = 0; i < bp; i++){
        printf("Unesite redom: x koordinatu donju levu, y koordinatu donju levu, x koordinatu gornju desnu, y koordinatu gornju desnu:  ");
        scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2) ;       
        nizP[i] = NapraviP(x1, y1, x2, y2, pr);
        A += nizP[i].A;
        Ip += nizP[i].Ip;
        Ie += nizP[i].Ie;
        Ipe += nizP[i].Ipe;
        p += (nizP[i].p*nizP[i].A);
        e += (nizP[i].e*nizP[i].A);
    } 
    }

    if(bt > 0){
    printf("Trouglovi:\n");
     for(int i = 0; i < bt; i++){
        printf("Unesite koordinate sva 3 temena trougla, tako da je prva tacka kraj katete baze, druga kraj katete visine i treca naspramna hipotenuzi: ");
        scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);      
        nizT[i] = NapraviT(x1, y1, x2, y2, x3, y3, t);
        A += nizT[i].A;
        Ip += nizT[i].Ip;
        Ie += nizT[i].Ie;
        Ipe += nizT[i].Ipe;
        p += (nizT[i].p*nizT[i].A);
        e += (nizT[i].e*nizT[i].A);
    } 
    }

    if(bi > 0){
    printf("Iprofili:\n");
     for(int i = 0; i < bp; i++){
        printf("Unesite redom: x koordinatu donju levu, y koordinatu donju levu, x koordinatu gornju desnu, y koordinatu gornju desnu:  ");
        scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);        
        nizI[i] = NapraviI(x1, y1, x2, y2, ip);
        A += nizI[i].A;
        Ip += nizI[i].Ip;
        Ie += nizI[i].Ie;
        Ipe += nizI[i].Ipe;
        p += (nizI[i].p*nizI[i].A);
        e += (nizI[i].e*nizI[i].A);
    }
    }

    p /= A;
    e /= A;
      
    Ix = Ip - A*pow(e,2);
    Iy = Ie - A*pow(p, 2);
    Ixy = Ipe - A*p*e;
    
    I1 = (Ix+Iy)/2 + sqrt(pow((Ix-Iy), 2) + 4*Ixy)/2;
    I2 = (Ix+Iy)/2 - sqrt(pow((Ix-Iy), 2) + 4*Ixy)/2;

    a = atan((2*Ixy/(Ix-Iy))*(-1)); 
    a /= 2;

    i1 = sqrt(I1/A);
    i2 = sqrt(I2/A);

    printf("Povrsina figure: %f\n", A);
    printf("Koordinate tezista: (%f %f)\n", p, e);
    printf("AKisjalni momenti: Ipsi: %f,  Ieta: %f,  Ipsieta:%f \n", Ip, Ie, Ipe);
    printf("AKisjalni momenti: Ix: %f,  Iy: %f,  Ixy:%f \n", Ix, Iy, Ixy);
    printf("ugao: %f\n", a);
    printf("Aksijalni momenti: I1: %f, I2: %f\n", I1, I2);
    printf("i1: %f, i2: %f\n", i1, i2);   
    
   return 0;
 }
