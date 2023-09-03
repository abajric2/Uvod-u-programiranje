#include <stdio.h>

void nadovezi(int *p1, const int *q1, const int *q2) {
    int i;
    do {
        *p1=*q1;
        p1++;
        q1++;
    } while (q1 != q2);
}

int main() {
    int i, n1, n2, n, niz1[100], niz2[100];
    /*Pretpostavimo da nizovi ne treba da imaju vise od 100 elemenata*/
    printf("Unesite velicinu prvog niza: ");
    scanf("%d", &n1);
    printf("Unesite elemente prvog niza: ");
    int *pok1=niz1;
    for(i=0; i<n1; i++) {
        scanf("%d", pok1++);
    }
    do {
    printf("Unesite velicinu drugog niza: ");
    scanf("%d", &n2);
    } while(n2>n1); /*ovim osiguravamo da ce prvi niz imati dovoljno 
    mjesta da smjesti sve elemente drugog niza (jer je tako receno u zadatku)*/
    printf("Unesite elemente drugog niza: ");
    int *pok2=niz2;
    for(i=0; i<n2; i++) {
        scanf("%d", pok2++);
    }
    do {
    printf("Uneiste redni broj elementa od kojeg nadovezivanje treba poceti: ");
    scanf("%d", &n);
    } while (n>n1-n2+1); /*ovaj uslov je kako ne bismo izasli iz opsega prvog niza u funckiji*/
    nadovezi(niz1 + (n-1), niz2, niz2+n2);
    pok1=niz1;
    printf("Modificirani niz1 je: ");
    for(i=0; i<n1; i++) { 
    /*uslov i<n1 jer pretpostavljamo (kao sto je receno u zadatku) da prvi
    niz ima dovoljno mjesta da smjesti sve elemente drugog niza*/
    printf("%d ", *pok1++);
    }
    return 0;
}


