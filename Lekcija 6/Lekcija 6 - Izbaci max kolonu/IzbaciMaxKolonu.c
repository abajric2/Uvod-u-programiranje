#include <stdio.h>

int max(int matrica[100][100], int visina, int sirina) {
    int i, j, k, l, temp, br_ponavljanja=0, max_pon=0, max;
    max=matrica[0][0];
    for(i=0; i<visina; i++) {
        for(j=0; j<sirina; j++) {
            temp=matrica[i][j];
            for(k=0; k<visina; k++) {
                for(l=0; l<sirina; l++) {
                    if(matrica[k][l]==temp) br_ponavljanja++;
                }
            }
            if(br_ponavljanja>max_pon) {
            max_pon=br_ponavljanja;
            max=matrica[i][j];
        }
        else if(br_ponavljanja==max_pon) {
            if(matrica[i][j]<max) max=matrica[i][j];
        }
        br_ponavljanja=0;
    }
}
return max;
}
int izbaci_kolone(int matrica[100][100], int visina, int sirina, int N) {
    int i, j, k, l;
    for(i=0; i<sirina; i++) {
        for(j=0; j<visina; j++) {
            if(matrica[j][i]==N) {
            for(k=0; k<visina; k++) {
                for(l=i; l<sirina-1; l++) {
                    matrica[k][l]=matrica[k][l+1];
                }
            }
            sirina--;
            if(sirina==0) break;
            j=-1;
            i=0;
        }
    }
    if (sirina==0) break;
}
return sirina;
}
int main() {
    int V, S, mat[100][100], i, j, N, brojac=0;
    printf("Unesite sirinu i visinu matrice: ");
    scanf("%d%d", &S, &V);
    for(i=0; i<V; i++) {
        printf("Unesite elemente %d. reda: ", i+1);
        for(j=0; j<S; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    do {
    brojac++;
    N=max(mat, V, S);
    S=izbaci_kolone(mat,V,S,N);
    if(S==0) {
    printf("Nakon %d. prolaza matrica je prazna!", brojac);
    break;
    }
    else printf("Nakon %d. prolaza matrica glasi: ", brojac);
    for(i=0; i<V; i++) {
        for(j=0; j<S; j++) {
            printf("%3d", mat[i][j]);
        }
        printf("\n");
    }
    } while(S!=0);
    return 0;
}


