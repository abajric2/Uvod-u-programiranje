#include <stdio.h>

double niz[100];
int vel, zapisano;

void unesi_niz() {
    int i;
    for(i=0; i<100; i++) {
        scanf("%lf", &niz[i]);
        if(niz[i]==-1) break;
    }
    vel=i;
    FILE* datoteka=fopen("niz.bin", "wb");
    if(datoteka==NULL) {
        printf("Greska pri otvaranju datoteke\n");
    }
    zapisano=fwrite(niz, sizeof(double), vel, datoteka);
    if(ferror(datoteka)) {
        printf("Greska prilikom pisanja datoteke.\n");
        printf("Zapisano je %d clanova niza: ", zapisano);
    }
    fclose(datoteka);
}
double srednja_vrijednost() {
    int i;
    double suma=0;
    if(zapisano==0) return 0;
    FILE* datoteka=fopen("niz.bin", "rb");
    if(datoteka==NULL) {
        printf("Greska pri otvaranju datoteke.");
        return 0;
    }
    int ucitano=fread(niz, sizeof(double), zapisano, datoteka);
    for(i=0; i<ucitano; i++) {
        suma+=niz[i];
    }
    fclose(datoteka);
    return suma/ucitano;
}
int main() {
    unesi_niz();
    printf("%g\n", srednja_vrijednost());
    return 0;
}


