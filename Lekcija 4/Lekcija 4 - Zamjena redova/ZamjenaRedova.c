#include <stdio.h>

int main() {
    int i, j, min_red=0, max_red=0, min, max;
    int mat[10][10];
    printf("Unesite elemente matrice: ");
    for(i=0; i<10; i++) {
        for(j=0; j<10; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    max=mat[0][0];
    min=mat[0][0];
    for(i=0; i<10; i++) {
        for(j=0; j<10; j++) {
            if(mat[i][j]>max) {
                max=mat[i][j];
                max_red=i;
            }
            if(mat[i][j]<min) {
                min=mat[i][j];
                min_red=i;
            }
        }
    }
    if(max_red==min_red) {
        printf("Najmanji i najveci element se nalaze u istom redu.");
        return 0;
    }
    int temp;
    for(i=0; i<10; i++) {
        temp=mat[max_red][i];
        mat[max_red][i]=mat[min_red][i];
        mat[min_red][i]=temp;
    }
    printf("Nakon zamjene matrica glasi: ");
    for(i=0; i<10; i++) {
        for(j=0; j<10; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}


