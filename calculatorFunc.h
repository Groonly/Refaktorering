#include <math.h>
#include <stdio.h>
/*Caluculates the the voltages through a circuit, when resistans and current is known*/
double ohmsLag(double r, double i);

double resTot(double r1, double r2, double r3);

double effEnk(double u, double i);

double skenEff(double u, double i);

double aktivEff(double u, double i, double cos);

double skenTreFas(double u, double i);

double aktivTreFas(double u, double i, double cos);
