#include "calculatorFunc.h"
/*Caluculates the the voltages through a circuit, when resistans and current is known*/
double ohms_lag(double r, double i){
    double u = i * r;
    return u;
}
/*Caluculates the the voltages through a circuit, when resistans and current is known*/
double res_tot(double r1, double r2, double r3){
    double rtot= (1/r1) + (1/r2) + (1/r3);
    rtot= 1/rtot;
    return rtot;
}

double eff_enk(double u, double i){
    double p = u * i;
    return p;
}

double sken_eff(double u, double i){
    double s = u * i;
    return s;
}

double aktiv_eff(double u, double i, double cos){
    double p = u * i * cos;
    return p;
}

double sken_3fas(double u, double i){
    double s = u * i * sqrt(3);
    return s;
}

double aktiv_3fas(double u, double i, double cos){
    double p = u * i * sqrt(3) * cos;
    return p;
}
/*Output disered text to prompt, set disered input min and max*/
double get_double(char *outputText, double min, double max){
  double inputValue;
  do{
    printf("%s", outputText);
    scanf("%lf", &inputValue);
  }while(inputValue < min || inputValue > max);

  return inputValue;
}
