#include <stdio.h>

int iste_cifre(int a, int b) {
    if(a<0) a=-a;
    if(b<0) b=-b;
    int br1=0, br2=0, temp, i;
    int niz1[50], niz2[50], min, k, j;
    temp=a;
    do {
        br1++;       /*Prebrojimo cifre prvog broja*/
        temp/=10;
    } while(temp!=0);
    temp=b;
    do {
        br2++;        /*Prebrojimo cifre drugog broja*/
        temp/=10;
    } while(temp!=0);
    temp=a;
    for(i=0; i<br1; i++) {   /*Kreiramo niz koji se sastoji od cifara broja a*/
        niz1[i]=temp%10;
        temp/=10;
    }
    temp=b;
    for(i=0; i<br2; i++) {   /*...za b takodjer*/
        niz2[i]=temp%10;
        temp/=10;
    }
    for(i=0; i<br1; i++) {
        min=i;
        for(j=i+1; j<br1; j++) {   /*Prepravimo niz da bude u rastucem redoslijedu radi lakseg snalazenja*/
            if(niz1[j]<niz1[min]) 
            min=j;
        }
            temp=niz1[i];
            niz1[i]=niz1[min];
            niz1[min]=temp;
        }
    for(i=0; i<br2; i++) {
        min=i;
        for(j=i+1; j<br2; j++) {
            if(niz2[j]<niz2[min]) 
            min=j;
        }
            temp=niz2[i];
            niz2[i]=niz2[min];
            niz2[min]=temp;
        }

    for(i=0; i<br1; i++) {        /*Iz nizova izbacimo clanove koji se ponavljaju*/
        for(j=i+1; j<br1; j++) {   /*Ako se sastoje od istih cifara, dobit cemo dva identicna niza*/            
        if(niz1[i]==niz1[j]) {
                for(k=j; k<br1-1; k++) {
                    niz1[k]=niz1[k+1];
                }
                br1--;
                j--;
            }
        }
    } 
     for(i=0; i<br2; i++) {
        for(j=i+1; j<br2; j++) {
            if(niz2[i]==niz2[j]) {
                for(k=j; k<br2-1; k++) {
                    niz2[k]=niz2[k+1];
                }
                br2--;
                j--;
            }
        }
    } 
    if(br1!=br2) return 0;    /*Ako finalni nizovi nemaju isti broj clanova, znaci...*/
    int isti=0;               /*...da nisu identicni pa se ne sastoje od istih cifara*/
    for(i=0; i<br1; i++) {
        for(j=0; j<br1; j++) {
            if(niz1[i]==niz2[j]) isti++;  /*Provjeravamo da li su nizovi identicni*/
        }
    }
    if(isti==br1) return 1;      /*Ako se pomocna promjenljiva isti povecala u svakom...*/
    else return 0;               /*...prolasku kroz petlju, znaci da su nizovi identicni*/
}

int main() {
    int a, b;
    printf("Unesite broj a: ");
    scanf("%d", &a);
    printf("Unesite broj b: ");
    scanf("%d", &b);
    if(iste_cifre(a, b)) printf("Brojevi a i b sastoje se od istih cifara!");
    else printf("Brojevi a i b ne sastoje se od istih cifara!");
    return 0;
}


