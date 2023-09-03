#include <stdio.h>

int main() {
    int i, j, k, mat1[100][100], br_kolona1=0, temp1=0, br_redova1=0;
    int mat2[100][100], br_kolona2=0, temp2=0, br_redova2=0, mat3[100][100]={0};
    printf("Unesite elemente 1. matrice: ");
    for(i=0; i<100; i++) {
        for(j=0; j<100; j++) {
            scanf("%d", &mat1[i][j]);
            br_kolona1++;
            if(br_kolona1>100) {
                printf("Prekoracena dimenzija matrice!");
                return 0;
            }
            if(mat1[i][j]==-1 || mat1[i][j]==-2) {
                if(i>0 && br_kolona1 != temp1) {
                    printf("Ovo nije matrica!");
                    return 0;
                }
                temp1=br_kolona1;
                br_kolona1=0;
                break;   
            }
        }
        br_redova1++;
        if(br_redova1>100) {
                printf("Prekoracena dimenzija matrice!");
                return 0;
            }
        if(mat1[i][j]==-2) break;
    }
    br_kolona1=temp1-1;
    printf("Unesite elemente 2. matrice: ");
    for(i=0; i<100; i++) {
        for(j=0; j<100; j++) {
            scanf("%d", &mat2[i][j]);
            br_kolona2++;
            if(br_kolona2>100) {
                printf("Prekoracena dimenzija matrice!");
                return 0;
            }
            if(mat2[i][j]==-1 || mat2[i][j]==-2) {
                if(i>0 && br_kolona2 != temp2) {
                    printf("Ovo nije matrica!");
                    return 0;
                }
                temp2=br_kolona2;
                br_kolona2=0;
                break;   
            }
        }
        br_redova2++;
        if(br_redova2>100) {
                printf("Prekoracena dimenzija matrice!");
                return 0;
            }
        if(mat2[i][j]==-2) break;
    }
    br_kolona2=temp2-1;
    if(br_kolona1 != br_redova2) printf("Matrice nisu pogodne za mnozenje.");
    else {
        for(i=0; i<br_redova1; i++) {
            for(j=0; j<br_kolona2; j++) {
                for(k=0; k<br_kolona1; k++) {
                    mat3[i][j]+=mat1[i][k]*mat2[k][j];        
                }
            }
        }
        printf("Matrice su pogodne za mnozenje. Matricni proizvod je: ");
        for(i=0; i<br_redova1; i++) {
            for(j=0; j<br_kolona2; j++) {
                printf("%d ", mat3[i][j]);
            }
            printf("\n");
        }
        
    }  
    return 0;
}


