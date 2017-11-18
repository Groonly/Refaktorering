/*Detta program är en räknare som kan användas för ellära med enbart växelspänningar och växelströmmar. Räknaren
tar upp räkning med spänningar i volt(U), resistanser upp till 20 000/ohm(R).
Ström upp till 440 Ampere(I), effekter P i watt(W). 3 faser upp till 400V mellan faserna.
även tar denna upp Skenbar effekt vid 3-fas och enfas, aktiv effekt vid 3-fas och enfas där cosinus fi/cosinus() används
som effektfaktorn som är mindre än 1 och inte mindre än 0.
Frekvenser i (Hz):  och totala motståndet i parallellkopplade kretsar med max 3 motstånd.
50 Hertz(Hz) Finns det i våra uttag i sverige Vid 50 Hz byter spänningen polaritet och strömmen riktning 100 gånger per
sekund. Spänningen i svenska eluttag pendlar upp och ner från -325 V till +325 V. Att vi talar om 230 V beror på att det
är spänningens(växelström ~) effektivvärde eller roten ur. Spänningen V(U)=Toppvärdet/sqrt(2)=325V/sqrt(2).
OHMS LAG: Spänning i volt(U)=Resistans i ohm(R)*Ström i ampere(I)
RESISTANSTOTAL PARALLELLA RESISTANSER: Rtot=1/R1R2R3
EFFEKTLAGEN ENKEL får likström: Effekt i watt(P)=U*I
SKENBAR EFFEKT ENFAS ~: Skenbar(S/VA)=U*I
AKTIV EFFEKT/MEDELEFFEKT ENFAS ~:P=U*I*cos()
SKENBAR EFFEKT 3-FAS ~: Skenbar S/VA=U*I*sqrt(3)
AKTIV EFFEKT 3-FAS ~: P=U*I*sqrt(3)*cos()
*/

#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include "calculatorFunc.h"
int main()
{
    enum choices{
      OhmsLag = 1, Rtot = 2, EffektlagenEnkel= 3,
      SkenbarEffektEnfas= 4, AktivEffektEnfas= 5,
      SkenbarEffektTrefas= 6, AktivEffektTrefas= 7,
      Exit= 0
    };
    enum choices choice;

    system("cls");
    bool exit = false;
    while (exit == false)
    {
        int val;
        double r, i, u, cos;
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

        switch(val){
          case OhmsLag:
            printf("Ohms lag sp\x84nningen(volt/V) bet\x84""ckning U lika med Resistansen(Ohm) bet\x84""ckning R\n"
            "g\x86nger Str\x94mmen(Ampere) med bet\x84""ckningen I. Kort U=R*I. \n\n");
            r = get_double("Skriv resistans R < 20 000ohm:\n", 0, 20000);
            i = get_double("Skriv str\x94m I < 440 Ampere::\n", 0, 400);
            printf("%f V\n", ohms_lag(r, i));
            break;
          case Rtot:
            printf("Resistans sammankopplade i parallella kretsar \x84r lika med 1 delat Resistans R total \x84r lika med\n"
            "Resistans 1/R1 + 1/R2 + 1/R3 d\x86 vi h\x94gst anv\x84nder tre resistanser.\n\n");
            double r1,r2,r3;
            r1 = get_double("Skriv resistans R1 < 20 000ohm:\n", 0, 20000);
            r2 = get_double("Skriv resistans R2 < 20 000ohm:\n", 0, 20000);
            r3 = get_double("Skriv resistans R3 < 20 000ohm:\n", 0, 20000);
            printf("%f Ohm\n", res_tot(r1, r2, r3));
            break;
          case EffektlagenEnkel:
            printf("Effektlagen enkel f\x86r likstr\x94m \x84r effekten P i Watt (W) lika med sp\x84nningen U i volt(V)\n"
            "g\x86nger str\x94mmen I i Ampere(A): \n\n");
            u = get_double("Skriv sp\x84nnngen U i volt(V):\n", 0, 1000000);
            i = get_double("Skriv str\x94m Ampere I < 440A:\n", 0, 400);
            printf("%f W\n", eff_enk(u, i));
            break;
          case SkenbarEffektEnfas:
            printf("Skenbar effekt enfas r\x84knas med storheten VA(VoltAmpere) som \x84r lika med sp\x84nningen U i volt(V)\n"
            "g\x86nger str\x94mmen I i ampere(A)\n\n");
            u = get_double("Skriv Sp\x84nningen U i volt:\n", 0, 10000000);
            i = get_double("Skriv str\x94m Ampere I < 440A:\n", 0, 400);
            printf("%f VA\n", sken_eff(u, i));
            break;
          case AktivEffektEnfas:
            printf("Skenbar effekt enfas r\x84knas med storheten VA(VoltAmpere) som \x84r lika med sp\x84nningen U i volt(V)\n"
            "g\x86nger str\x94mmen I i ampere(A)\n\n");
            u = get_double("Skriv Sp\x84nningen U i volt:\n", 0, 10000000);
            i = get_double("Skriv str\x94m Ampere I < 440A:\n", 0, 400);
            printf("%f VA\n", sken_eff(u, i));
            break;
          case SkenbarEffektTrefas:
            printf("3-fas skenbar effekt \x84r v\x84xelsp\x84nning \x84r skenbar effekt S i voltampere(VA) lika med sp\x84nningen U i volt(V) \n"
            "g\x86nger str\x94mmen I i ampere(A) g\x86nger roten ur 3 SQRT(3).\n\n");
            u = get_double("Skriv sp\x84nning U i volt(V) < 400V:\n", 0, 400);
            i = get_double("Skriv str\x94m Ampere I < 440A:\n", 0, 400);
            printf("%f VA\n", sken_3fas(u, i));
            break;
          case AktivEffektTrefas:
            printf("3-fas aktiv effekt \x84r effekten P i Watt(W) lika med sp\x84nningen U i volt(V) g\x86nger str\x94mmen I i ampere(A)\n"
            "g\x86nger cos < 1 && cos > 0 g\x86nger roten ur 3 SQRT(3).\n\n");
            u = get_double("Skriv sp\x84nning U i volt(V) < 400V:\n", 0, 400);
            i = get_double("Skriv str\x94m Ampere I < 440A:\n", 0, 400);
            cos = get_double("Skriv in effektfaktorn cos > 0 && cos < 1:\n", 0, 1);
            printf("%f W\n", aktiv_3fas(u ,i, cos));
            break;
          case Exit:
            exit = true;
            break;
          default:
            printf("Fel alternativ f\x94rs\x94k igen!:\n");
        }
    }
    return 0;
}
