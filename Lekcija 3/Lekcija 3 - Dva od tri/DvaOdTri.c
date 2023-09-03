#include <stdio.h>

int main() {
    int i, j, k, n1, niz1[10000], brojaci[10000]={0};
    int niz2[10000], n2, niz3[10000], n3, min1=0, min2=0, min3=0;
    int max1=0, max2=0, max3=0, max=0, min=0, zadovoljava=0;
    
    printf("Unesite broj clanova prvog niza: ");
    scanf("%d", &n1);
    printf("Unesite prvi niz: ");
    for(i=0; i<n1; i++) {
        scanf("%d", &niz1[i]);
    }
    for(i=0; i<n1; i++) {  /*izbacimo clanove koji se ponavljaju radi lakseg poredjenja*/
        for(j=i+1; j<n1; j++) {
            if(niz1[i]==niz1[j]) {
                for(k=j+1; k<n1; k++) {
                    niz1[k-1]=niz1[k];
                }
                j--;
                n1--;
            }
        }
    }
    for(i=0; i<n1; i++) {  /*prebrojimo clanove niza*/
        brojaci[niz1[i]]++;
    }
    if(n1>0) {    /*trazimo najveci i najmanji clan kako bismo imali granice za petlju*/
    max1=niz1[0]; /*koja trazi koji broj se javlja u dva od tri niza*/
    for(i=1; i<n1; i++) {
        if(niz1[i]>max1) max1=niz1[i];
    }
    min1=niz1[0];
    for(i=1; i<n1; i++) {
        if(niz1[i]<min1) min1=niz1[i];
    }
    }
    printf("Unesite broj clanova drugog niza: ");  /*...ista procedura za drugi niz...*/
    scanf("%d", &n2);
    printf("Unesite drugi niz: ");
    for(i=0; i<n2; i++) {
        scanf("%d", &niz2[i]);
    }
    for(i=0; i<n2; i++) {
        for(j=i+1; j<n2; j++) {
            if(niz2[i]==niz2[j]) {
                for(k=j+1; k<n2; k++) {
                    niz2[k-1]=niz2[k];
                }
                j--;
                n2--;
            }
        }
    }
    for(i=0; i<n2; i++) {
        brojaci[niz2[i]]++;
    }
    if(n2>0) {
    max2=niz2[0];
    for(i=1; i<n2; i++) {
        if(niz2[i]>max2) max2=niz2[i];
    }
    min2=niz2[0];
    for(i=1; i<n2; i++) {
        if(niz2[i]<min2) min2=niz2[i];
    }
    }
    printf("Unesite broj clanova treceg niza: ");  /*...za treci isto...*/
    scanf("%d", &n3);
    printf("Unesite treci niz: ");
    for(i=0; i<n3; i++) {
        scanf("%d", &niz3[i]);
    }
    for(i=0; i<n3; i++) {
        for(j=i+1; j<n3; j++) {
            if(niz3[i]==niz3[j]) {
                for(k=j+1; k<n3; k++) {
                    niz3[k-1]=niz3[k];
                }
                j--;
                n3--;
            }
        }
    }
    for(i=0; i<n3; i++) {
        brojaci[niz3[i]]++;
    }
    if(n3>0) {
    max3=niz3[0];
    for(i=1; i<n3; i++) {
        if(niz3[i]>max3) max3=niz3[i];
    }
    min3=niz3[0];
    for(i=1; i<n3; i++) {
        if(niz3[i]<min3) min3=niz3[i];
    }
    }
    max=max1;                 /*Trazimo najveci i najmanji element za sva tri niza*/
    if(max2>max) max=max2;
    if(max3>max) max=max3;
    min=min1;
    if(min2<min) min=min2;
    if(min3<min) min=min3;
    for(i=min; i<=max; i++) {
        if(brojaci[i]==2) zadovoljava++;  /*Provjeravamo koliko clanova se javilo ukupno 2 puta*/
    }
    printf("U dva od tri niza se nalazi %d clanova.", zadovoljava);
    return 0;
}


