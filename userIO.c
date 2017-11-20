#include "userIO.h"
#include "calculatorFunc.h"

/*Handle calls to calculator func*/
void callOperation(int choice){
  double r, r1, r2, r3, i, u, cos;
  enum choices{
    OhmsLag = 1, Rtot = 2, EffektlagenEnkel= 3,
    SkenbarEffektEnfas= 4, AktivEffektEnfas= 5,
    SkenbarEffektTrefas= 6, AktivEffektTrefas= 7,
    KwattPris = 8, Exit= 0
  };
  switch(choice){
    case OhmsLag:
      printf("%s", operationInfo(OhmsLag));
      r = getDouble("Skriv resistans R < 20 000ohm:\n", 0, 20000);
      i = getDouble("Skriv str\x94m I < 440 Ampere::\n", 0, 400);
      printf("%f V\n", ohmsLag(r, i));
      break;
    case Rtot:
      printf("%s",operationInfo(Rtot));
      r1 = getDouble("Skriv resistans R1 < 20 000ohm:\n", 0, 20000);
      r2 = getDouble("Skriv resistans R2 < 20 000ohm:\n", 0, 20000);
      r3 = getDouble("Skriv resistans R3 < 20 000ohm:\n", 0, 20000);
      printf("%f Ohm\n", resTot(r1, r2, r3));
      break;
    case EffektlagenEnkel:
      printf("%s",operationInfo(EffektlagenEnkel));
      u = getDouble("Skriv sp\x84nnngen U i volt(V):\n", 0, 1000000);
      i = getDouble("Skriv str\x94m Ampere I < 440A:\n", 0, 400);
      printf("%f W\n", effEnk(u, i));
      break;
    case SkenbarEffektEnfas:
      printf("%s",operationInfo(SkenbarEffektEnfas));
      u = getDouble("Skriv Sp\x84nningen U i volt:\n", 0, 10000000);
      i = getDouble("Skriv str\x94m Ampere I < 440A:\n", 0, 400);
      printf("%f VA\n", skenEff(u, i));
      break;
    case AktivEffektEnfas:
      printf("%s",operationInfo(AktivEffektEnfas));
      u = getDouble("Skriv Sp\x84nningen U i volt:\n", 0, 10000000);
      i = getDouble("Skriv str\x94m Ampere I < 440A:\n", 0, 400);
      cos = getDouble("Skriv in effektfaktorn cos > 0 && cos < 1:\n", 0, 1);
      printf("%f VA\n", aktivEff(u, i, cos));
      break;
    case SkenbarEffektTrefas:
      printf("%s",operationInfo(SkenbarEffektTrefas));
      u = getDouble("Skriv sp\x84nning U i volt(V) < 400V:\n", 0, 400);
      i = getDouble("Skriv str\x94m Ampere I < 440A:\n", 0, 400);
      printf("%f VA\n", skenTreFas(u, i));
      break;
    case AktivEffektTrefas:
      printf("%s",operationInfo(AktivEffektTrefas));
      u = getDouble("Skriv sp\x84nning U i volt(V) < 400V:\n", 0, 400);
      i = getDouble("Skriv str\x94m Ampere I < 440A:\n", 0, 400);
      cos = getDouble("Skriv in effektfaktorn cos > 0 && cos < 1:\n", 0, 1);
      printf("%f W\n", aktivTreFas(u ,i, cos));
      break;
    case KwattPris:
        printf("%s",operationInfo(KwattPris));
        u = getDouble("F\x94rbrukad Watt:\n", 0, 1000000);
        i = getDouble("Pris per Watt:\n", 0, 400);
        printf("%f Kr/kw", kwattPris(u, i));
        break;
  }
}

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
  printf("V\x84lj 8 f\x94r:Kwatt pris\n");
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

  outputText[8] = "Kwatt pris ber\x84""knas genom att ta förbrukad el Watt / tusen g\x86""er priset du betalar\n";

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
