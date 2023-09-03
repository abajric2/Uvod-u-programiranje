#include <stdio.h>

int main() {
    int i, j, p, q, r, s, A[10][10], B[10][10], C[10][20];

    printf("Unesite dimenzije matrice A (p q): ");
    scanf("%d%d", &p, &q);
    if(p<=0 || q<=0) {
        printf("Neispravne dimenzije matrice!");
        return 0;
    }
    if(p>10 || q>10) {
        printf("Matrica A je prevelika!");
        return 0;
    }
    printf("Unesite dimenzije matrice B (r s): ");
    scanf("%d%d", &r, &s);
    if(r<=0 || s<=0) {
        printf("Neispravne dimenzije matrice!");
        return 0;
    }
    if(r>10 || s>10) {
        printf("Matrica B je prevelika!");
        return 0;
    }
    if(p!=r) {
        printf("Matrice nisu saglasne za konkatenaciju!");
        return 0;
    }
    printf("Matrica A: \n");
    for(i=1; i<=p; i++) {
        printf("%d. red: ", i);
        for(j=1; j<=q; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    printf("Matrica B: \n");
    for(i=1; i<=r; i++) {
        printf("%d. red: ", i);
        for(j=1; j<=s; j++) {
            scanf("%d", &B[i][j]);
        }
    }
    if(q>=s) {
    for(i=1; i<=p; i++) {
        for(j=1; j<=q; j++) {
            C[i][j]=A[i][j];
            if((j+q)<=(q+s)) C[i][j+q]=B[i][j];
        }
    }    
    }
    else {
        for(i=1; i<=p; i++) {
            for(j=1; j<=s; j++) {
                if(j<=q) C[i][j]=A[i][j];
                C[i][j+q]=B[i][j];
                
            }
        }
    }
    printf("Matrica C: \n");
    for(i=1; i<=p; i++) {
        for(j=1; j<=q+s; j++) {
            printf("%4d", C[i][j]);
        }
        printf("\n");
    }
    return 0;
}


