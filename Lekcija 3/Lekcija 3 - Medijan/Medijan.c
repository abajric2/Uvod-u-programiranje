#include <stdio.h>

int main() {
    int n, i, min=0, j;
    double rezultati[500], temp, medijan; 
    do {
    printf("Unesite broj studenata: ");
    scanf("%d", &n);
    } while(n<1 || n>500);
    printf("Unesite bodove na ispitu: ");
    for(i=0; i<n; i++) {
        scanf("%lf", &rezultati[i]);
        if(rezultati[i]<0 || rezultati[i]>20) {
            printf("Rezultat ispita nije u trazenom intervalu");
            return 1;
        }
    }
    for(i=0; i<n; i++) {
        min=i;
        for(j=i+1; j<n; j++) {
            if(rezultati[j]<rezultati[min])
            min=j;
        }
        temp=rezultati[i];
        rezultati[i]=rezultati[min];
        rezultati[min]=temp;
    }
    if(n%2!=0) {
        medijan=rezultati[n/2];
    } 
    else {
        medijan=(rezultati[n/2]+rezultati[n/2-1])/2;
    }
    printf("Medijan je: %g", medijan);
    return 0;
}


