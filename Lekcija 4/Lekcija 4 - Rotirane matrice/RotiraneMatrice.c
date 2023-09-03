#include <stdio.h>

int main() {
    int sA, vA, sB, vB, i, j, k, l, rotirana;
    double A[100][100], B[100][100], C[100][100];
    printf("Unesite sirinu i visinu matrice A: ");
    scanf("%d%d", &sA, &vA);
    printf("Unesite clanove matrice A: ");
    for(i=0; i<vA; i++) {
        for(j=0; j<sA; j++) {
            scanf("%lf", &A[i][j]);
        }
    }
    printf("Unesite sirinu i visinu matrice B: ");
    scanf("%d%d", &sB, &vB);
    printf("Unesite clanove matrice B: ");
    for(i=0; i<vB; i++) {
        for(j=0; j<sB; j++) {
            scanf("%lf", &B[i][j]);
        }
    }
    if(vA!=sB || sA!=vB) {
        printf("NE\n");;
        return 0;
    }
    k=sB-1;
    l=0;
    for(i=0; i<sB; i++) {
        for(j=0; j<vB; j++) {
            C[k][l]=B[j][i];
            if(l==vB-1) {
                l=0;
                k--;
            }
            else l++;
        }
    }
    rotirana=1;
    for(i=0; i<vA; i++) {
        for(j=0; j<sA; j++) {
            if(A[i][j]!=C[i][j]) rotirana=0;
        }
    }
    if(rotirana) printf("DA\n");
    else printf("NE\n");
    return 0;
}


