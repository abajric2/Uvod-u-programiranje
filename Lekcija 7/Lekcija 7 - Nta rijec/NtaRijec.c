#include <stdio.h>

void nta_rijec(const char* str, char* rijec, int n) {
    int nije_slovo=1, br_rijeci=0;
    while(*str != '\0') {
        if (!(*str>='A' && *str<='Z' || *str>='a' && *str<='z'))
        nije_slovo=1;
        else if (nije_slovo==1) {
            nije_slovo=0;
            br_rijeci++;
            if(br_rijeci==n) {
                while (*str>='A' && *str<='Z' || *str>='a' && *str<='z') {
                *rijec=*str;
                rijec++;
                str++;
                }
                *rijec='\0';                
                return;
            }
        }
        str++;
    }
    if(n>br_rijeci) *rijec='\0';
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
    char recenica[100], rijec[20];
    int n;

    printf("Unesite recenicu: ");
    unesi(recenica,100);
    printf("Unesite koju rijec po redu zelite izdvojiti: ");
    scanf("%d", &n);
    nta_rijec(recenica, rijec, n);
    printf("Izdvojena rijec je: ");
    printf("%s", rijec);

    return 0;
}


