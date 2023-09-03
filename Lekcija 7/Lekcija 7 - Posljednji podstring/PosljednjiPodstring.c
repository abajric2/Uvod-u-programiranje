#include <stdio.h>

int pronadji_posljednji (const char *str, const char *trazi) {
    int brojac=0, n=-1, duz_stringa=0, duz_podstringa=0;
    const char* p=str;
    const char* q=trazi;
    while(*p != '\0') {
        duz_stringa++;
        p++;
    }
    while(*q != '\0') {
        duz_podstringa++;
        q++;
    }    
    if(duz_stringa<duz_podstringa) return n;
    while(*str != '\0') {
        p=str;
        q=trazi;      
        while (*p++ == *q++) {
        if(*q == '\0') {
        n=brojac;
        break;
        }
        } 
    str++;
    brojac++;
    }
    return n;
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
    char string[100000], podstring[30];
    printf("Unesite string: ");
    unesi(string,100000);
    printf("Unesite podstring: ");
    unesi(podstring,30);
    printf("Indeks je: %d", pronadji_posljednji(string,podstring));
    return 0;
}


