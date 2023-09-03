#include <stdio.h>

int main() {
    int n, i, j;
    double mat[30][30];
    double maxO1, maxO2, maxO3, maxO4;
    double minO1, minO2, minO3, minO4;
    printf("Unesite broj n: ");
    scanf("%d", &n);
    if(n<3 || n>30) {
        printf("Unos pogresan!");
        return 1;
    }
    for(i=0; i<n; i++) {
        printf("Unesite elemente %d. reda: ", i+1);
        for(j=0; j<n; j++) {
            scanf("%lf", &mat[i][j]);
        }
    }
    maxO1=mat[0][1];
    minO1=mat[0][1];
    maxO2=mat[1][0];
    minO2=mat[1][0];
    maxO3=mat[1][n-1];
    minO3=mat[1][n-1];
    maxO4=mat[n-1][1];
    minO4=mat[n-1][1];
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            if(j>i && i<-j+n-1) {
                if(mat[i][j]>maxO1) maxO1=mat[i][j];
                if(mat[i][j]<minO1) minO1=mat[i][j];
            }
            if(j>i && i>-j+n-1) {
                if(mat[i][j]>maxO3) maxO3=mat[i][j];
                if(mat[i][j]<minO3) minO3=mat[i][j];
            }
            if(j<i && i<-j+n-1) {
                if(mat[i][j]>maxO2) maxO2=mat[i][j];
                if(mat[i][j]<minO2) minO2=mat[i][j];
            }
            if(j<i && i>-j+n-1) {
                if(mat[i][j]>maxO4) maxO4=mat[i][j];
                if(mat[i][j]<minO4) minO4=mat[i][j];
            }
        }
    }
    if(maxO1==maxO4 && minO3==minO2) {
        printf("\nMatrica je simetricna!\n");
    }
    else printf("\nMatrica nije simetricna!\n");
    printf("Elementi: O1 = %.3f, O2 = %.3f, O3 = %.3f, O4 = %.3f", maxO1, minO2, minO3, maxO4);
    return 0;
}


