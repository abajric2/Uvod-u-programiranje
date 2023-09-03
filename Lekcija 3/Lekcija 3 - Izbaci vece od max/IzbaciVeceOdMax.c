#include <stdio.h>

int main() {
    double niz[100];
    int i, vel;
    
    printf("Unesite broj clanova niza: ");
    scanf("%d",&vel);
    printf("Unesite clanove niza: ");
    for(i=0; i<vel; i++)
        scanf("%lf", &niz[i]);
    double temp;
    int j, max_i=0, max=0, br_ponavljanja=0;
    for(i=0; i<vel; i++) {
        br_ponavljanja=0;
        for(j=0; j<vel; j++) {
            if(niz[i]==niz[j]) br_ponavljanja++;
        }
        if(br_ponavljanja>max) {
            max=br_ponavljanja;
            max_i=i;
        }
        else if(br_ponavljanja==max) {
            if(niz[max_i]>niz[i]) max_i=i;
    }
    }
    temp=niz[max_i];
    for(i=0; i<vel; i++) {
        if(niz[i]>temp) {
            for(j=i+1; j<vel; j++) {
                niz[j-1]=niz[j];
            }
            i--;
            vel--;
        }
    }
    printf("Nakon izbacivanja niz glasi:\n");
    for (i=0; i<vel; i++)
        printf("%g ", niz[i]);
    return 0;
}


