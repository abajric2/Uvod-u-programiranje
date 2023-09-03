#include <stdio.h>

int main() {
    int i, j, n, n1, temp, mat[50][50];
    do {
    printf("Unesite dimenziju matrice: \n");
    scanf("%d", &n);
    } while(n<1 || n>50);
    for(i=0; i<n; i++) {
        printf("Unesite elemente %d. reda: \n", i+1);
        for(j=0; j<n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    if(n%2!=0) {
        for(i=0; i<n; i++) {
            n1=n;
            for(j=0; j<n1; j++) {
                if(j>=i) mat[i][j]=mat[i][j+1];
            }
            n1--;
        }
    }
    else if(n%2==0) {
        for(i=0; i<n; i++) {
            n1=n;
            temp=0;
            for(j=0; j<n1; j++) {
                if(i!=j && j!=n-1-i) {
                    mat[i][temp]=mat[i][j];
                    temp++;
                }
            }
            n1-=2;
        }
    }
    printf("Matrica nakon izbacivanja dijagonale:\n");
        for(i=0; i<n; i++) {
            for(j=0; j<n1; j++) {
                printf("%-5d", mat[i][j]);
            }
            printf("\n");
        }
    
    return 0;
}


