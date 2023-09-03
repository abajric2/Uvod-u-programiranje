#include <stdio.h>

void ispisi_unazad(const char *str) {

    if(*str) {
        ispisi_unazad(str+1);
        printf("%c", *str);
    }
}

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
    char recenica[100000];
    printf("Uneiste recenicu: ");
    unesi(recenica, 100000);
    ispisi_unazad(recenica);
    return 0;
}


