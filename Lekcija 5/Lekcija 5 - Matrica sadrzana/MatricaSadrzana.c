#include <stdio.h>

int matrica_sadrzana(int mat1[100][100], int V1, int S1, int mat2[100][100], int V2, int S2) {
    int i, j, k, l, sadrzan=0, min=0, max=0;
    int brojaci1[10000]={0}, brojaci2[10000]={0};
    if(S2>S1 || V2>V1) return 0; /*ako matrica B ima bar jednu vecu dimenziju, ne moze biti podmatrica*/
    for(i=0; i<V2; i++) {
        for(j=0; j<S2; j++) {
            for(k=0; k<V1; k++) {
                for(l=0; l<S1; l++) {
                    if(mat2[i][j]==mat1[k][l]) {
                    sadrzan=1;
                    }
                }
            }
            if(!sadrzan) return 0; /*Ako se u matrici A ne pojavljuje niti jednom dati element*/
            sadrzan=0;             /*iz B, znamo da nije podmatrica*/
        }
    }
    return 1;   /*Ako dodje do ove linije sigurno jeste podmatrica*/
}
int main() {
    int m1, n1, m2, n2, i, j;
    int mat1[100][100], mat2[100][100];
    printf("Unesite duzinu i sirinu matrice A: ");
    scanf("%d%d", &m1, &n1);
    printf("Unesite matricu A: ");
    for(i=0; i<m1; i++) {
        for(j=0; j<n1; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }
    printf("Unesite duzinu i sirinu matrice B: ");
    scanf("%d%d", &m2, &n2);
    printf("Unesite matricu B: ");
    for(i=0; i<m2; i++) {
        for(j=0; j<n2; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }
    if(matrica_sadrzana(mat1, m1, n1, mat2, m2, n2))
    printf("Matrica B je sadrzana u matrici A.");
    else printf("Matrica B nije sadrzana u matrici A.");
    return 0;
}


