#include <stdio.h>

void zaokruzi (double niz[], int n) {
    int i, x, c, neg=0;
    for(i=0; i<n; i++) {
        if(*niz<0) {
            *niz=-*niz;
            neg=1;
        }
        x=*niz*100;
        c=x%10;
        x/=10;
        if(c>=5) {
            x++;
            *niz=(double)x/10;
            if(neg) {
            *niz=-*niz;
            neg=0;
        }
        }
        else {
        *niz=(double)x/10;
        if(neg) {
            *niz=-*niz;
            neg=0;
        }
        }
        niz++;
    }
}

int main() {
    double niz[100000];
    int i, n;
    do {
    printf("Unesite broj elemenata niza (ne veci od 100000): ");
    scanf("%d", &n);
    } while(n<1 || n>100000);
    double *pok=niz;
    printf("Unesite niz: ");
    for(i=0; i<n; i++) {
        scanf("%lf", pok++);
    }
    zaokruzi(niz, n);
    pok=niz;
    printf("Zaokruzen niz je: ");
    for(i=0; i<n; i++) {
        printf("%g ", *pok++);
    }
    return 0;
}


