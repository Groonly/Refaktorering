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
#include "userIO.h"

int main()
{
    enum choices{
      OhmsLag = 1, Rtot = 2, EffektlagenEnkel= 3,
      SkenbarEffektEnfas= 4, AktivEffektEnfas= 5,
      SkenbarEffektTrefas= 6, AktivEffektTrefas= 7,
      Exit= 0
    };
    double r, r1, r2, r3, i, u, cos;
    bool exit = false;
    system("cls");
    while (exit == false)
    {
        switch(menuChoice()){
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
          case Exit:
            exit = true;
            break;
          default:
            printf("Fel alternativ f\x94rs\x94k igen!:\n");
        }
    }
    return 0;
}
