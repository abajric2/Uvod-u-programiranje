#include <stdio.h>

int main() {

    int niz[100], vel, niz2[1000], vel2, i;
    printf("Unesite velicinu niza: ");
    scanf("%d", &vel);
    printf("Unesite clanove niza: ");
    for (i=0; i<vel; i++) 
        scanf("%d", &niz[i]);
    
    if(vel<1 || vel>100) {
        do {
        printf("Unesite velicinu niza: ");
        scanf("%d", &vel);
        } while(vel<1 || vel>100);
        printf("Unesite clanove niza: ");
        for(i=0; i<vel; i++) {
            do {
            scanf("%d", &niz[i]);
            if(niz[i]<0) printf("Neispravno");
            } while(niz[i]<0);
        }
    }
    else {
        for(i=0; i<vel; i++) {
            if(niz[i]<0) {
                do {
                    printf("Neispravno. Unesite: ");
                    scanf("%d", &niz[i]);
                } while(niz[i]<0);
            }
        }
    }
    int temp, j=0, niz3[100000], brojac=1, k=0;
    for(i=vel-1; i>=0; i--) {
        do {
            temp=niz[i]%10;
            niz[i]/=10;
            niz3[j]=temp;
            j++;
        } while(niz[i]!=0);
    }
    vel2=0;
    int pom;
    for(i=j-1; i>=0; i--) {
        pom=i;
        while(pom!=0 && niz3[pom-1]==niz3[pom]) {
        brojac++;
        pom--;
        }
        niz2[k]=niz3[i];
        niz2[k+1]=brojac;
        k+=2;
        vel2+=2;
        brojac=1;
        if(pom==0) break;
        else i=pom;
    }
    
    printf("Finalni niz glasi:\n");
    for (i=0; i<vel2; i++)
        printf("%d ", niz2[i]);
    return 0;
}


