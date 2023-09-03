#include <stdio.h>

int main() {
    int n, i, cl1=1, cl=1, pomocna;
    printf("Unesite n: ");
    scanf("%d", &n);
    if(n<1) {
        printf ("Neispravan unos");
        return 0;
    }
    printf("Prvih %d Fibonaccijevih brojeva: ", n);
    if(n==1) {
        printf ("%d", cl1);
        return 0;
    }
    printf("%d ", cl1);
    printf("%d ", cl);
    for (i=0; i<n-2; i++) {
        cl=cl+cl1;
        pomocna=cl-cl1;
        cl1=pomocna;
        printf("%d ", cl);  
    }
    return 0;
}


