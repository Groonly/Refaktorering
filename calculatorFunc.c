#include "calculatorFunc.h"
/*Calculates Voltage when resistance and current is known */
double ohmsLag(double r, double i){
    return i * r;
}
/*Calculates resistance for three resistors in parallel*/
double resTot(double r1, double r2, double r3){
    return 1/((1/r1) + (1/r2) + (1/r3));
}
/*Calculates power when voltage and current is known*/
double effEnk(double u, double i){
    return u * i;
}
/**/
double skenEff(double u, double i){
    return u * i;
}
double aktivEff(double u, double i, double cos){
    return u * i * cos;
}
double skenTreFas(double u, double i){
    return u * i * sqrt(3);
}
double aktivTreFas(double u, double i, double cos){
    return u * i * sqrt(3) * cos;
}
