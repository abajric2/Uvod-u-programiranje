#include <stdio.h>

void unesi(char niz[], int velicina) {
    char znak = getchar();
    if (znak == '\n') znak = getchar();
    int i = 0;
    while (i < velicina-1 && znak != '\n') {
    niz[i] = znak;
    i++;
    znak = getchar();
    }
    niz[i] = '\0';
    }

int main() {
    char ime[256];
    int c, brojac=0, rijec=0, i=0, max=0, temp=0, pomocna, max_pozicija, d, br=0;
    printf("Unesite naziv datoteke: ");
    unesi(ime, 255);
    FILE* ulaz=fopen(ime, "r");
    if(!ulaz) {
        printf("Datoteka %s ne postoji", ime);
        return 1;
    }
    while((c=fgetc(ulaz))!=EOF) {
        if(!(c>='A' && c<='Z' || c>='a' && c<='z') && rijec) {
            temp=1;
            if(brojac>max) {
                max=brojac;
                max_pozicija=pomocna;
            }
            brojac=0;
            rijec=0;
        }
        if(c>='A' && c<='Z' || c>='a' && c<='z') {
            if(!rijec) pomocna=i;
            brojac++;
            rijec=1;
        }
        i++;
    }
    fclose(ulaz);
    if(temp==0) {
        max=brojac;
        max_pozicija=0;
    }
    i=0;
    ulaz=fopen(ime, "r");
    while((d=fgetc(ulaz))!=EOF) {
        if(i>=max_pozicija && br<max) {
        printf("%c", d);
        br++;
        }
        i++;
    }
    fclose(ulaz);
    return 0;
}


