#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001

int main() {
    int i, n, j, pomocna;
    double niz[200], ubaceni;
    int niz2[200], temp, brojaci[200]={0};
    do {
    printf("Unesite broj clanova niza: ");
    scanf("%d", &n);
    } while(n<1 || n>100);
    printf("Unesite niz: ");
    for(i=0; i<n; i++) {
        scanf("%lf", &niz[i]);
    }
    pomocna=n;
    for(i=0; i<n-1; i++) {
        if(n==2*pomocna-1) break;
        if(fabs(niz[i+1]-2*niz[i])<EPSILON && i!=n-1) {
            ubaceni=(niz[i]+niz[i+1])/2;
            for(j=n; j>i; j--)  
                niz[j]=niz[j-1];
            n++;
            niz[i+1]=ubaceni;
        }
    }
    printf("Nakon ubacivanja niz glasi: \n");
    for(i=0; i<n; i++) {
        printf("%g ", niz[i]);
    }
    int min=0;
    int max=0;
    for(i=0; i<n; i++) {
        temp=(int)(niz[i]*10);
        niz2[i]=temp%10;
        if(niz2[i]<min) min=niz2[i];
        if(niz2[i]>max) max=niz2[i];
        brojaci[niz2[i]]++;
    }
    for(i=min; i<=max; i++) {
        if(brojaci[i]!=0) printf("\nCifra %d se ponavlja %d puta.", i, brojaci[i]);
    }

    return 0;
}


