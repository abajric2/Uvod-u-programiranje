#include <stdio.h>

int isti_brojevi(int n1, int n2) {
    int br_cifara1=0, br_cifara2=0, i, j, temp;
    int niz1[50], niz2[50], min;
    if(n1<0) n1=-n1;
    if(n2<0) n2=-n2;
    temp=n1;
    do {
        br_cifara1++;    /*prebrojavamo cifre prvog broja*/
        temp/=10;
    } while(temp!=0);
    temp=n2;
    do {
        br_cifara2++;   /*prebrojavamo cifre drugog broja*/
        temp/=10;
    } while(temp!=0);
    if(br_cifara1!=br_cifara2) return 0;
    temp=n1;
    for(i=0; i<br_cifara1; i++) {  /*kreiramo pomocni niz koji se sastoji od cifara prvog br*/
        niz1[i]=temp%10;
        temp/=10;
    }
    temp=n2;
    for(i=0; i<br_cifara2; i++) {   /*...za drugi isto...*/
        niz2[i]=temp%10;
        temp/=10;
    }
    for(i=0; i<br_cifara1; i++) {   /*oba niza stavljamo u rastuci redoslijed*/
        min=i;
        for(j=i+1; j<br_cifara1; j++) {
            if(niz1[j]<niz1[min]) min=j;
        }
        temp=niz1[i];
        niz1[i]=niz1[min];
        niz1[min]=temp;
    }
    for(i=0; i<br_cifara2; i++) {
        min=i;
        for(j=i+1; j<br_cifara2; j++) {
            if(niz2[j]<niz2[min]) min=j;
        }
        temp=niz2[i];
        niz2[i]=niz2[min];
        niz2[min]=temp;
    }
    i=0;
    do {
        if(niz1[i]!=niz2[i]) return 0;   /*provjeravamo da li su nizovi identicni*/
        i++;       
    } while(i<br_cifara1);
    return 1;                          /*ako dodje do ove linije identicni su*/
}

int* istecifre(int* niz, int vel, int* p) {
    int* pok=p+1;
    int* pok1=niz+vel;
    while(pok!=pok1) {
        if(isti_brojevi(*pok,*p)) return pok;
        pok++;
    } 
    pok=niz;
    pok1=p;
    while(pok!=pok1) {
        if(isti_brojevi(*pok,*p)) return pok;
        pok++;
    } 
    return p;
}

int main() {
    
    return 0;
}


