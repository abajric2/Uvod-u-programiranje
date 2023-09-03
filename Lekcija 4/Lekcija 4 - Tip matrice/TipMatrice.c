#include <stdio.h>

int main() {
    int i, j, N, mat[100][100], temp=1;
    do {
    printf("Unesite broj N: ");
    scanf("%d", &N);
    } while(N<1 || N>100);
    printf("Unesite elemente matrice: ");
    for(i=0; i<N; i++) {
        for(j=0; j<N; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    for(i=0; i<N; i++) {
        for(j=0; j<N; j++) {
            if(mat[i][j]!=0) {
                temp=0;
                break;
            }
        }
    }
    if(temp) {
        printf("Nul-matrica");
        return 0;
    }
    temp=1;
    for(i=0; i<N; i++) {
        for(j=0; j<N; j++) {
            if(i==j && mat[i][j]!=1) {
                temp=0; 
                break;
            }
        }
    }
    if(temp) {
        printf("Jedinicna matrica");
        return 0;
    }
    temp=1;
    for(i=0; i<N; i++) {
        for(j=0; j<N; j++) {
            if(i!=j && mat[i][j]!=0) {
                temp=0;
                break;
            }
        }
    }
    if(temp) {
        printf("Dijagonalna matrica");
        return 0;
    }
    temp=1;
    for(i=0; i<N; i++) {
        for(j=0; j<N; j++) {
            if(i>j && mat[i][j]!=0) {
                temp=0;
                break;
            }
        }
    }
    if(temp) {
    printf("Gornja trougaona matrica");
    return 0;
    }
    temp=1;
    for(i=0; i<N; i++) {
        for(j=0; j<N; j++) {
            if(j>i && mat[i][j]!=0) {
                temp=0; 
                break;
            }
        }
    }
    if(temp) {
        printf("Donja trougaona matrica");
        return 0;
    }
    temp=1;
    for(i=0; i<N; i++) {
        for(j=0; j<N; j++) {
            if(i!=N-1-j && mat[i][j]!=0) {
                temp=0;
                break;
            }
        }
    }
    if(temp) {
        printf("Sporedna dijagonalna matrica");
        return 0;
    }
    else printf("Nista od navedenog");
    return 0;
}


