#include <stdio.h>

int main() {

    int i, j, k, l, m, n, M, N, O, P, cl, pomocna=0, matA[100][100], matB[100][100], brojac=0;

    do {
        printf("Unesite dimenzije matrice A: \n");
        scanf("%d%d", &M, &N);
        if (M<1 || M>100 || N<1 || N>100) 
        printf("Neispravan unos!\n");
    } while (M<1 || M>100 || N<1 || N>100);

    printf("Unesite clanove matrice: ");
    for(i=0; i<N; i++) {
        for(j=0; j<M; j++) {
            scanf("%d", &matA[i][j]);
        }
    }
    
    printf("Unesite dimenzije matrice B: ");
    scanf("%d%d", &O, &P);
    printf("Unesite clanove matrice: ");
    for(i=0; i<P; i++) {
        for(j=0; j<O; j++) {
            scanf("%d", &matB[i][j]);
        }
    }
    if (M*N != O*P) {
        printf("NE");
        return 0;
    }
    
    for(i=0; i<N; i++) {
        for(j=0; j<M; j++) {
            cl=matA[i][j];
            for(k=0; k<N; k++) {
                for(l=0; l<M; l++) {
                    if(matA[k][l]==cl)
                    brojac++;
                }
            }
            for(m=0; m<P; m++) {
                for(n=0; n<O; n++) {
                    if(matA[i][j]==matB[m][n])
                    brojac--;
                }
            }
            if (brojac != 0) {
                pomocna=1;
                break;
            }
        }
        if (pomocna) break;
    }
    if (pomocna==0) printf("DA");
    else printf("NE");

    return 0;
}


