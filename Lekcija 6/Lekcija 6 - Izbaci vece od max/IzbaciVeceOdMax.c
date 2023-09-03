#include <stdio.h>

int izbaci_max_vece (double *niz, int vel) {
    int i, j, broj_ponavljanja=0, max=0, max_i=0;
    double temp;
    for(i=0; i<vel; i++) {
        broj_ponavljanja=0;
        for(j=0; j<vel; j++) {
            if(*(niz+i)==*(niz+j)) broj_ponavljanja++;
        }
            if(broj_ponavljanja>max) {
            max_i=i;
            max=broj_ponavljanja; 
            }
            else if(broj_ponavljanja==max) 
            if(*(niz+max_i)>*(niz+i)) max_i=i;
        }
    
    temp=*(niz+max_i);
    for(i=0; i<vel; i++) {
        if(*(niz+i)>temp) {
            for(j=i; j<vel-1; j++) {
            *(niz+j)=*(niz+j+1);
            }
            vel--;
            i--;
        }
    }
    return vel;
}

int main() {
    int n, i;
    double niz[10000];
    double *pok=niz;
    printf("Unesite velicinu niza: ");
    scanf("%d", &n);
    printf("Unesite niz: ");
    for(i=0; i<n; i++) {
    scanf("%lf", pok++);
    }
    printf("Nakon izbacivanja: ");
    n=izbaci_max_vece(niz, n);
    pok=niz;
    for(i=0; i<n; i++) {
        printf("%g ", *pok++);
    }   
    return 0;
}



