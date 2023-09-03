#include <stdio.h>

struct Kurs {
    char valuta[5];
    float vrijednost;
};
int uporedi(char* s1, char* s2) {
    int vel1=0, vel2=0;
    char* temp1=s1;
    char* temp2=s2;
    while(*temp1!='\0') {
        vel1++;
        temp1++;
    }
    while(*temp2!='\0') {
        vel2++;
        temp2++;
    }
    if(vel1!=vel2) return 0;
    temp1=s1;
    temp2=s2;
    while(*temp1!='\0') {
        if(*temp1!=*temp2) return 0;
        temp1++;
        temp2++;
    }
    return 1;
}
double razmjena(struct Kurs* kursna_lista, int vel, char* valuta, double iznos) {
    int i;
    double KM;
    for(i=0; i<vel; i++) {
        if(uporedi(kursna_lista[i].valuta,valuta)) {
            KM=kursna_lista[i].vrijednost*iznos;
            break;
        }
    }
    if(i==vel) return 0;
    return KM;
}
int main() {
    printf("Lekcija 8: Strukture, Kursna lista");
    return 0;
}


