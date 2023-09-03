#include <stdio.h>

int main() {
    int i, j, A, B;
    double mat[100][100], suma=0;
    do {
    printf("Unesite dimenzije matrice: ");
    scanf("%d%d", &A, &B);
    } while(A<1 || A>100 || B<1 || B>100);
    printf("Unesite elemente matrice: ");
    for(i=0; i<A; i++) {
        for(j=0; j<B; j++) {
            scanf("%lf", &mat[i][j]);
            if(i==0 || i==A-1 || (j==0 && i>0 && i<A-1) || (j==B-1 && i>0 && i<A-1))
            suma+=mat[i][j];
        }
    }
    printf("Suma elemenata na rubu je %.2f", suma);
    
    return 0;
}

