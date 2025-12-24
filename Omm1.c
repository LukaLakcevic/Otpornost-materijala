#include <stdio.h>
#include <stdlib.h>
#include "Sila.h"

int main(int argc, int** argv){

    printf("Program funkcioniše samo za I20 profil poprečni presek!\n");
    printf("0 podrazumeva negativan smer, 1 pozitivan, pratite konvencije!\n");
    printf("Ovaj kod nema funkcije sa kontinualnim opterećenjima!\n");
    //Poprecbi presek:
    int *l = (int*)malloc(3*sizeof(int));
    printf("Unesite ukupnu dužinu grede: ");
    scanf("%d", &l[0]);
    printf("Unesite dužinu na kojoj se nalazi prvi oslonac od levog kraja grede: ");
    scanf("%d", &l[1]);
    printf("Unesite dužinu na kojoj se nalazi drugi oslonac od levog kraja grede: ");
    scanf("%d", &l[2]);
    for(int i = 0; i <= sizeof(l)/sizeof(int); i++)
        printf("%d ", l[i]);
    printf("\n");

    int fn;
    printf("Uneti broj sila: ");
    scanf("%d", &fn);
    double inte, smer, sumF = 0, sumM = 0;
    sila f;
    moment m;
    sila nizF[fn+2];
    
    printf("Unesite broj momenata: ");
    int mn;
    scanf("%d", &mn);
    printf("A\n");
    moment* nizM = (moment*)malloc((mn+fn+1)*sizeof(moment));
    for(int i = fn; i < fn+mn; i++){
        printf("Unesite redom intezitet pa smer momenta: ");
        scanf("%lf %lf", &inte, &smer);
        nizM[i] = NapraviM(inte, smer, m);
        if(nizM[i].smer < 0)
            sumM -= nizM[i].intezitet;
        else
            sumM += nizM[i].intezitet;
    }

    l = (int*)realloc(l, fn*sizeof(int));
    for(int i = 0; i < fn; i++){
        printf("Unesite redom intezitet i smer dejstva sile, a potom rastojanje iste od levog kraja nosaca: ");
        scanf("%lf %lf %d", &inte, &smer, &l[i+3]);
        nizF[i+2] = NapraviS(inte, smer, f);
        printf("Sila: %lf %lf %d\n", nizF[i+2].intezitet, nizF[i+2].smer, l[i+3]);
        if(l[1] - l[i+3] < 0 && nizF[i+2].smer == 1){
            nizM[i] = NapraviM((-l[i+3] + l[1]) * nizF[i+2].intezitet, 1, m);
        }
        else if(l[1] - l[i+3] < 0 && nizF[i+2].smer == 0){
            nizM[i] = NapraviM((-l[i+3] + l[1]) * nizF[i+2].intezitet, 0, m);
        }else if(l[1] - l[i+3] > 0 && nizF[i+2].smer == 0){
            nizM[i] = NapraviM((l[i+3] - l[1]) * nizF[i+2].intezitet, 0, m);
        }
        else if(l[1] - l[i+3] > 0 && nizF[i+2].smer == 1){
            nizM[i] = NapraviM((l[i+3] - l[1]) * nizF[i+2].intezitet, 1, m);
        }
        if(nizM[i].smer == 0)
            sumM -= nizM[i].intezitet;
        else
            sumM += nizM[i].intezitet;
        if(nizF[i].smer == 0)
            sumF -= nizF[i+2].intezitet;
        else
            sumF += nizF[i+2].intezitet;
    }

    printf("%lf\n", sumM);
    if(sumM < 0)
        nizF[1] = NapraviS(sumM, 0, f);
    else
        nizF[1] = NapraviS(sumM, 1, f);
    if(nizF[1].smer == 0)
        sumF -= nizF[1].intezitet;
    else
        sumF += nizF[1].intezitet; 
    if(sumF < 0)
        nizF[0] = NapraviS(sumF, 0, f);
    else
        nizF[0] = NapraviS(sumF, 1, f);
    double maxM = 0, maxF = 0;
    
    for(int i = 0; i < fn; i++){
        if(maxF < abs(nizF[i].intezitet))
            maxF = abs(nizF[i].intezitet);                
    }

    for(int i = 0; i < mn+fn-1; i++){
        if(maxM < abs(nizM[i].intezitet))
            maxM = abs(nizM[i].intezitet);                
    }

    
    printf("%lf\n", maxF);
    printf("%lf\n", maxM);
        
    double sigma = maxM/214;
    double tau = (maxF/2140)*(125/4);      

    printf("Intezitet normalnog napona: %lf\n", sigma);
    printf("Intezitet tangecijalnog napona: %lf\n", tau);

    free(l);
    free(nizM);   

    return 0;
}
