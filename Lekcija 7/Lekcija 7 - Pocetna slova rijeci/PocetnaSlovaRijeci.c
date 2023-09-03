#include <stdio.h>

void pocetna_slova(char* s1, char* s2, int k) {
    int n=0, neslovo=1;
    char* pok;
    while (*s1 != '\0') {
        if (!(*s1>='A' && *s1<='Z' || *s1>='a' && *s1<='z')) {neslovo=1; s1++; }
        else if (neslovo==1) {
        neslovo=0;
        pok=s1;
    while(*s1>='A' && *s1<='Z' || *s1>='a' && *s1<='z') {
        n++;
        s1++;
    }
    if(n>k) {
        *s2=*pok;
        s2++;
    }
    n=0;
    }
}
    *s2='\0';
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
    char s1[100000], s2[100000];
    int k;
    printf("Uneiste recenicu: ");
    unesi(s1,1000);
    printf("Unesite broj k: ");
    scanf("%d", &k);
    pocetna_slova(s1, s2, k);
    printf("Novi string je: %s", s2);
    return 0;
}


