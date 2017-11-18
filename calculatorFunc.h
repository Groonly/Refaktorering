#include <math.h>
#include <stdio.h>
/*Caluculates the the voltages through a circuit, when resistans and current is known*/
double ohms_lag(double r, double i);

double res_tot(double r1, double r2, double r3);

double eff_enk(double u, double i);

double sken_eff(double u, double i);

double aktiv_eff(double u, double i, double cos);

double sken_3fas(double u, double i);


double aktiv_3fas(double u, double i, double cos);

double get_double(char *outputText, double min, double max);
