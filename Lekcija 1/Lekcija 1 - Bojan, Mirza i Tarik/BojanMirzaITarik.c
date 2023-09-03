#include <stdio.h>

int main() {
    double parc1_T, parc2_T, prisustvo_T, zadace_T, zavrsni_T, suma_T=0, ocjena_T;
    double parc1_B, parc2_B, prisustvo_B, zadace_B, zavrsni_B, suma_B=0, ocjena_B;
    double parc1_M, parc2_M, prisustvo_M, zadace_M, zavrsni_M, suma_M=0, ocjena_M;

    printf("Unesite bodove za Tarika: \n");
    printf("I parcijalni ispit: \n");
    scanf("%lf", &parc1_T);
    if(parc1_T>20 || parc1_T<0) {
        printf("Neispravan broj bodova\n");
        return 1;
    }
    suma_T=parc1_T;
    printf("II parcijalni ispit: \n");
    scanf("%lf", &parc2_T);
    if(parc2_T>20 || parc2_T<0) {
        printf("Neispravan broj bodova\n");
        return 1;
    }
    suma_T+=parc2_T;
    printf("Prisustvo: \n");
    scanf("%lf", &prisustvo_T);
    if(prisustvo_T>10 || prisustvo_T<0) {
        printf("Neispravan broj bodova\n");
        return 1;
    }
    suma_T+=prisustvo_T;
    printf("Zadace: \n");
    scanf("%lf", &zadace_T);
    if(zadace_T>10 || zadace_T<0) {
        printf("Neispravan broj bodova\n");
        return 1;
    }
    suma_T+=zadace_T;
    printf("Zavrsni ispit: \n");
    scanf("%lf", &zavrsni_T);
    if(zavrsni_T>40 || zavrsni_T<0) {
        printf("Neispravan broj bodova\n");
        return 1;
    }
    suma_T+=zavrsni_T;

    printf("Unesite bodove za Bojana: \n");
    printf("I parcijalni ispit: \n");
    scanf("%lf", &parc1_B);
    if(parc1_B>20 || parc1_B<0) {
        printf("Neispravan broj bodova\n");
        return 1;
    }
    suma_B=parc1_B;
    printf("II parcijalni ispit: \n");
    scanf("%lf", &parc2_B);
    if(parc2_B>20 || parc2_B<0) {
        printf("Neispravan broj bodova\n");
        return 1;
    }
    suma_B+=parc2_B;
    printf("Prisustvo: \n");
    scanf("%lf", &prisustvo_B);
    if(prisustvo_B>10 || prisustvo_B<0) {
        printf("Neispravan broj bodova\n");
        return 1;
    }
    suma_B+=prisustvo_B;
    printf("Zadace: \n");
    scanf("%lf", &zadace_B);
    if(zadace_B>10 || zadace_B<0) {
        printf("Neispravan broj bodova\n");
        return 1;
    }
    suma_B+=zadace_B;
    printf("Zavrsni ispit: \n");
    scanf("%lf", &zavrsni_B);
    if(zavrsni_B>40 || zavrsni_B<0) {
        printf("Neispravan broj bodova\n");
        return 1;
    }
    suma_B+=zavrsni_B;

    printf("Unesite bodove za Mirzu: \n");
    printf("I parcijalni ispit: \n");
    scanf("%lf", &parc1_M);
    if(parc1_M>20 || parc1_M<0) {
        printf("Neispravan broj bodova\n");
        return 1;
    }
    suma_M=parc1_M;
    printf("II parcijalni ispit: \n");
    scanf("%lf", &parc2_M);
    if(parc2_M>20 || parc2_M<0) {
        printf("Neispravan broj bodova\n");
        return 1;
    }
    suma_M+=parc2_M;
    printf("Prisustvo: \n");
    scanf("%lf", &prisustvo_M);
    if(prisustvo_M>10 || prisustvo_M<0) {
        printf("Neispravan broj bodova\n");
        return 1;
    }
    suma_M+=prisustvo_M;
    printf("Zadace: \n");
    scanf("%lf", &zadace_M);
    if(zadace_M>10 || zadace_M<0) {
        printf("Neispravan broj bodova\n");
        return 1;
    }
    suma_M+=zadace_M;
    printf("Zavrsni ispit: \n");
    scanf("%lf", &zavrsni_M);
    if(zavrsni_M>40 || zavrsni_M<0) {
        printf("Neispravan broj bodova\n");
        return 1;
    }
    suma_M+=zavrsni_M;

    if(suma_T<55) ocjena_T=5;
    else if(suma_T>=55 && suma_T<65) ocjena_T=6;
    else if(suma_T>=65 && suma_T<75) ocjena_T=7;
    else if(suma_T>=75 && suma_T<85) ocjena_T=8;
    else if(suma_T>=85 && suma_T<92) ocjena_T=9;
    else if(suma_T>=92 && suma_T<=100) ocjena_T=10;

    if(suma_B<55) ocjena_B=5;
    else if(suma_B>=55 && suma_B<65) ocjena_B=6;
    else if(suma_B>=65 && suma_B<75) ocjena_B=7;
    else if(suma_B>=75 && suma_B<85) ocjena_B=8;
    else if(suma_B>=85 && suma_B<92) ocjena_B=9;
    else if(suma_B>=92 && suma_B<=100) ocjena_B=10;

    if(suma_M<55) ocjena_M=5;
    else if(suma_M>=55 && suma_M<65) ocjena_M=6;
    else if(suma_M>=65 && suma_M<75) ocjena_M=7;
    else if(suma_M>=75 && suma_M<85) ocjena_M=8;
    else if(suma_M>=85 && suma_M<92) ocjena_M=9;
    else if(suma_M>=92 && suma_M<=100) ocjena_M=10;

    if(ocjena_T==5 && ocjena_B==5 && ocjena_M==5)
    printf("Nijedan student nije polozio.\n");
    else if(ocjena_T>5 && ocjena_B==5 && ocjena_M==5
    || ocjena_B>5 && ocjena_T==5 && ocjena_M==5
    || ocjena_M>5 && ocjena_B==5 && ocjena_T==5)
    printf("Jedan student je polozio.\n");
    else if(ocjena_T==5 && ocjena_B>5 && ocjena_M>5
    || ocjena_B==5 && ocjena_T>5 && ocjena_M>5
    || ocjena_M==5 && ocjena_B>5 && ocjena_T>5)
    printf("Dva studenta su polozila.\n");
    else {
        printf("Sva tri studenta su polozila.\n");
        if(ocjena_T==ocjena_M && ocjena_M==ocjena_B)
        printf("Sva tri studenta imaju istu ocjenu.\n");
        else if(ocjena_T==ocjena_M && ocjena_M!=ocjena_B
        || ocjena_T==ocjena_B && ocjena_M!=ocjena_B
        || ocjena_B==ocjena_M && ocjena_M!=ocjena_T)
        printf("Dva od tri studenta imaju istu ocjenu.\n");
        else printf("Svaki student ima razlicitu ocjenu.\n");
    }
    return 0;
}


