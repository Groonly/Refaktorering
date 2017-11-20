#include "userIO.h"
/*Scans and return input chooise*/
int menuChoice(void){
int val;
printf("V\x84lj vilka storheter du vill ber\x84kna:\n");
printf("V\x84lj 1 f\x94r: OHMS LAG\n");
printf("V\x84lj 2 f\x94r: Rtot\n");
printf("V\x84lj 3 f\x94r: EFFEKTLAGEN ENKEL\n");
printf("V\x84lj 4 f\x94r: SKENBAR EFFEKT ENFAS\n");
printf("V\x84lj 5 f\x94r: AKTIV EFFEKT/MEDELEFFEKT ENFAS\n");
printf("V\x84lj 6 fvr: SKENBAR EFFEKT 3-FAS\n");
printf("V\x84lj 7 f\x94r: AKTIV EFFEKT 3-FAS\n");
printf("V\x84lj 0 f\x94r: F\x94R ATT AVSLUTA\n");
scanf("%d", &val);
return val;
}

/*Returns choosen hardcoded text*/
char* operationInfo(int choice){
  static char *outputText[10];
  outputText[1] = "Ohms lag sp\x84nningen(volt/V) bet\x84""ckning U lika med Resistansen(Ohm) bet\x84""ckning R\n"
                  "g\x86nger Str\x94mmen(Ampere) med bet\x84""ckningen I. Kort U=R*I. \n\n";

  outputText[2] = "Resistans sammankopplade i parallella kretsar \x84r lika med 1 delat Resistans R total \x84r lika med\n"
                  "Resistans 1/R1 + 1/R2 + 1/R3 d\x86 vi h\x94gst anv\x84nder tre resistanser.\n\n";

  outputText[3] = "Effektlagen enkel f\x86r likstr\x94m \x84r effekten P i Watt (W) lika med sp\x84nningen U i volt(V)\n"
                  "g\x86nger str\x94mmen I i Ampere(A): \n\n";

  outputText[4] = "Skenbar effekt enfas r\x84knas med storheten VA(VoltAmpere) som \x84r lika med sp\x84nningen U i volt(V)\n"
                  "g\x86nger str\x94mmen I i ampere(A)\n\n";

  outputText[5] = "Aktiv medelefdekt enfas \x84r lika med effekt P i watt(W) lika med sp\x84nningen U i volt(V) g\x86nger str\x94mmen I \n"
                  "i Ampere g\x86nger cosinus fi/efkektfaktor < 1:\n\n";

  outputText[6] = "3-fas skenbar effekt \x84r v\x84xelsp\x84nning \x84r skenbar effekt S i voltampere(VA) lika med sp\x84nningen U i volt(V) \n"
                  "g\x86nger str\x94mmen I i ampere(A) g\x86nger roten ur 3 SQRT(3).\n\n";

  outputText[7] = "3-fas skenbar effekt \x84r v\x84xelsp\x84nning \x84r skenbar effekt S i voltampere(VA) lika med sp\x84nningen U i volt(V) \n"
                  "g\x86nger str\x94mmen I i ampere(A) g\x86nger roten ur 3 SQRT(3).\n\n";

  return outputText[choice];
}


/*Outputs disered text to prompt, set disered input min and max*/
double getDouble(char *outputText, double min, double max){
  double inputValue;
  do{
    printf("%s", outputText);
    scanf("%lf", &inputValue);
  }while(inputValue < min || inputValue > max);

  return inputValue;
}
