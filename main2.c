
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
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>
#include "calculatorFunc.h"

int main()
{
    system("chcp 1252");
    system("cls");
    bool exit = false;

    while (exit == false)
    {
        printf("\n");
        int val;
        printf("V�lj vilka storheter du vill ber\x84kna:\n");
        printf("V\x84lj 1 f\x94r: OHMS LAG\n");
        printf("V\x84lj 2 f\x94r: Rtot\n");
        printf("V\x84lj 3 f\x94r: EFFEKTLAGEN ENKEL\n");
        printf("V\x84lj 4 f\x94r: SKENBAR EFFEKT ENFAS\n");
        printf("V\x84lj 5 f\x94r: AKTIV EFFEKT/MEDELEFFEKT ENFAS\n");
        printf("V\x84lj 6 fvr: SKENBAR EFFEKT 3-FAS\n");
        printf("V\x84lj 7 f\x94r: AKTIV EFFEKT 3-FAS\n");
        printf("V\x84lj 0 f\x94r: F\x94R ATT AVSLUTA\n");
        scanf("%d", &val);

        if(val == 1)
        {
            printf("Ohms lag sp�nningen(volt/V) bet�ckning U lika med Resistansen(Ohm) bet�ckning R \n");
            printf("g�nger Str�mmen(Ampere) med bet�ckningen I. Kort U=R*I. \n\n");
            double r, i;
            printf("Skriv resistans R < 20 000ohm: \n ");
            scanf("%lf", &r);
            if(r > 20000)
            {
                printf("F�r h�gt v�rde, f�rs�k igen: \n");
                continue;
            }

            printf("Skriv str�m I < 440 Ampere: \n");
            scanf("%lf", &i);
            if(i > 440)
            {
                printf("F�r h�gt v�rde, f�rs�k igen: \n");
                continue;
            }

            printf("%f V\n", ohms_lag(r, i));

        }
        else if(val == 2)
        {
            printf("Resistans sammankopplade i parallella kretsar �r lika med 1 delat Resistans R total �r lika med\n");
            printf("Resistans 1/R1 + 1/R2 + 1/R3 d� vi h�gst anv�nder tre resistanser.\n\n");
            double r1,r2,r3;
            printf("Skriv resistans R1 < 20 000ohm: \n ");
            scanf("%lf", &r1);
            if(r1 > 20000)
            {
                printf("F�r h�gt v�rde, f�rs�k igen: \n");
                continue;
            }
            printf("Skriv resistans R2 < 20 000ohm: \n ");
            scanf("%lf", &r2);
            if(r2 > 20000)
            {
                printf("F�r h�gt v�rde, f�rs�k igen: \n");
                continue;
            }
            printf("Skriv resistans R3 < 20 000ohm: \n ");
            scanf("%lf", &r3);
            if(r3 > 20000)
            {
                printf("F�r h�gt v�rde, f�rs�k igen: \n");
                continue;
            }
            printf("%f Ohm\n", res_tot(r1, r2, r3));
        }
        else if(val == 3)
        {

            printf("Effektlagen enkel f�r likstr�m �r effekten P i Watt (W) lika med sp�nningen U i volt(V)\n");
            printf("g�nger str�mmen I i Ampere(A): \n\n");
            double u, i;
            printf("Skriv sp�nnngen U i volt(V): \n ");
            scanf("%lf", &u);
            printf("Skriv str�m Ampere I < 440A: \n");
            scanf("%lf", &i);
            if(i > 440)
            {
                printf("F�r h�gt v�rde, f�rs�k igen: \n");
                continue;
            }
            printf("%f W\n", eff_enk(u, i));
        }
        else if(val == 4)
        {

            printf("Skenbar effekt enfas r�knas med storheten VA(VoltAmpere) som �r lika med sp�nningen U i volt(V)\n");
            printf("g�nger str�mmen I i ampere(A)\n\n");
            double u, i;
            printf("Skriv Sp�nningen U i volt: \n ");
            scanf("%lf", &u);
            printf("Skriv str�m I < 440A: \n");
            scanf("%lf", &i);
            if(i > 440)
            {
                printf("F�r h�gt v�rde, f�rs�k igen: \n");
                continue;
            }
            printf("%f VA\n", sken_eff(u, i));
        }
        else if(val == 5)
        {
            printf("Aktiv medelefdekt enfas �r lika med effekt P i watt(W) lika med sp�nningen U i volt(V) g�nger str�mmen I \n");
            printf("i Ampere g�nger cosinus fi/efkektfaktor < 1:\n\n");
            double u, i, cos;
            printf("Skriv sp�nning U i volt: \n ");
            scanf("%lf", &u);
            printf("Skriv str�m I: \n");
            scanf("%lf", &i);
            if(i > 440){
                printf("F�r h�gt v�rde, f�rs�k igen:\n");
                continue;
            }
            printf("Skriv in effektfaktorn cos > 0 && cos < 1:\n");
            scanf("%lf", &cos);
            if (cos < 0 && cos > 1)
            {
                printf("Fel v�rde, f�rs�k igen\n");
                continue;
            }
            printf("%f W\n", aktiv_eff(u, i, cos));
        }
        else if(val == 6)
        {
            printf("3-fas skenbar effekt �r v�xelsp�nning �r skenbar effekt S i voltampere(VA) lika med sp�nningen U i volt(V) \n");
            printf("g�nger str�mmen I i ampere(A) g�nger roten ur 3 SQRT(3).\n\n");
            double u, i;
            printf("Skriv sp�nning U i volt(V) < 400V: \n ");
            scanf("%lf", &u);
            if(u > 400)
            {
                printf("F�r h�gt v�rde, f�rs�k igen: \n");
                continue;
            }

            printf("Skriv str�m I i ampere < 440: \n");
            scanf("%lf", &i);
            if(i > 440)
            {
                printf("F�r h�gt v�rde, f�rs�k igen: \n");
                continue;
            }
            printf("%f VA\n", sken_3fas(u, i));
        }
        else if(val == 7)
        {

            printf("3-fas aktiv effekt �r effekten P i Watt(W) lika med sp�nningen U i volt(V) g�nger str�mmen I i ampere(A)\n");
            printf("g�nger cos < 1 && cos > 0 g�nger roten ur 3 SQRT(3).\n\n");
            double u, i, cos;
            printf("Skriv Sp�nningen U i volt(V): \n ");
            scanf("%lf", &u);
            if(u > 400)
            {
                printf("F�r h�gt v�rde, f�rs�k igen.\n");
                continue;
            }
            printf("Skriv str�m I i ampere(A): \n");
            scanf("%lf", &i);
            if(i > 440)
            {
                printf("F�r h�gt v�rde, f�rs�k igen.\n");
                continue;
            }

            printf("Skriv in effektfaktorn cos > 0 && cos < 1: \n");
            scanf("%lf", &cos);
            if (cos < 0 && cos > 1)
            {
                printf("F�r h�gt v�rde, f�rs�k igen: \n");
                continue;
            }

            printf("%f W\n", aktiv_3fas(u ,i, cos));
        }
        else if (val == 0)
        {
            exit = true;
        }
        else
        {
            printf("Fel alternativ f�rs�k igen!: \n");
        }
    }

    return 0;
}
