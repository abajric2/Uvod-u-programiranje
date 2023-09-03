#include <stdio.h>

void prekopiraj (const int *izvor, int *odrediste, int n) {
    int i;
    for (i=0; i<n; i++) {
        *odrediste=*izvor;
        odrediste++;
        izvor++;
    }
}

int main() {
    int i, n, niz1[100], niz2[100]={0}; 
    /*pretpostavljamo da se ne unosi vise od 100 elemenata niza*/
    int *pok=niz1;
    
    do {
    printf("Unesite broj elemenata niza (ne veci od 100): ");
    scanf("%d", &n);
    } while(n>100 || n<1);
    printf("Unesite izvorni niz: ");
    for(i=0; i<n; i++) {
        scanf("%d", pok++);
    }
    prekopiraj(niz1, niz2, n);
    pok=niz2;
    printf("Prekopiran niz je: ");
    for(i=0; i<n; i++) {
        printf("%d ", *pok++);
    }

    return 0;
}


