#include <stdio.h>

struct Osoba {
    char ime[15];
    char prezime[20];
    int telefon;
};
void unesi(char osoba[], int velicina) {
    char znak = getchar();
    if (znak == '\n') znak = getchar();
    int i = 0;
    while (i < velicina-1 && znak != '\n') {
    osoba[i] = znak;
    i++;
    znak = getchar();
    }
    osoba[i] = '\0';
    }

struct Osoba unos_osobe() {
    struct Osoba o;
    printf("Unesite ime: ");
    unesi(o.ime,15);
    printf("Unesite prezime: ");
    unesi(o.prezime,20);
    printf("Unesite broj telefona: ");
    scanf("%d", &o.telefon);
    return o;
}

void ispis_osobe(struct Osoba osoba) {
    printf("%s %s, Tel: %d\n", osoba.ime, osoba.prezime, osoba.telefon);
}

int main() {
    struct Osoba imenik[100];
    int n=0, izbor=-1, i, j=0;
    while(izbor!=0) {
        printf("Pritisnite 1 za unos, 2 za ispis, 0 za izlaz: ");
        scanf("%d", &izbor);
        switch(izbor) {
            case 1:
            imenik[j]=unos_osobe();
            if(n>100) return 0;
            n++;
            j++;
            break;
            case 2:
            for(i=0; i<n; i++) {
            printf("%d. ", i+1);
            ispis_osobe(imenik[i]);
            }
            break;
            case 0:
            break;
            default:
            printf("Pogresan unos!\n");
        }
    }
    return 0;
}


