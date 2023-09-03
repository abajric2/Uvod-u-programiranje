#include <stdio.h>

char* izbaci_max_slovo(char* s) {
    char* poc=s;
    int brojaci[128]={0}, max=0, max_i=0, i;
    int veliko_slovo=0, malo_slovo=0, temp=0;
    while(*poc!='\0') {
        if(*poc>='a' && *poc<='z') brojaci[*poc-('a'-'A')]++;
        else brojaci[*poc]++;
        poc++;
    }
    for(i='A'; i<='Z'; i++) {
        if(brojaci[i]>max) {
            temp++;
            max=brojaci[i];
            max_i=i;
        }
    }
    if(temp) {
    poc=s;
    while(*poc!='\0') {
            if(*poc==max_i || *poc==max_i+'a'-'A') {
                char *q=poc, *r=poc+1;
                while(*q++=*r++);
            } else poc++;
    }
    *poc='\0';
    }
    return s;
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
    char* s=recenica;
    printf("Uneiste tekst: ");
    unesi(recenica, 100000);
    printf("Tekst nakon izbacivanja slova koje se ponavlja najvise puta glasi: \n");
    printf("%s", izbaci_max_slovo(s));
    return 0;
}


