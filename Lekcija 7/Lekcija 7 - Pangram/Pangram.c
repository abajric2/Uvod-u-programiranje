#include <stdio.h>

int pangram(const char* s) {
    
    int brojaci[91]={0}, temp=1, i;
    while(*s!='\0') {
        if(*s>='a' && *s<='z') brojaci[*s-('a'-'A')]++;
        else if(*s>='A' && *s<='Z') brojaci[*s]++;
        s++;
    }
    for(i='A'; i<='Z'; i++) {
        if(brojaci[i]==0 && (i=='Q' || (i>='W' && i<='Y'))) {
            temp=2;
        }
        else if(brojaci[i]==0) {
            temp=0;
            break;
        }
    }
    if(temp==2) {
        if(brojaci['Q']==0 && brojaci['X']==0 && brojaci['Y']==0 && brojaci['W']==0)
        temp=2;
        else temp=0;
    }
    if(temp==0) return 0;
    else if(temp==2) return 2;
    else return 1;
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
    char recenica[1000000];
    char* s=recenica;
    printf("Unesite recenicu: ");
    unesi(s,1000000);
    if(pangram(s)==0) printf("Recenica nije pangram ni na jednom alfabetu.");
    else if(pangram(s)==1) printf("Recenica je pangram na engleskom alfabetu.");
    else if(pangram(s)==2) printf("Recenica je pangram na nasem alfabetu.");
    return 0;
}


