#include <stdio.h>
#include <stdlib.h>

typedef struct sila{

    double intezitet;
    double smer;
}sila;

typedef struct moment{

    double intezitet;
    double smer;
}moment;

sila NapraviS(double i, double s, sila f){

    f.intezitet = i;
    f.smer = s;
    return f; 
}

moment NapraviM(double i, double s, moment m){

    m.intezitet = i;
    m.smer = s;
    return m; 
}
