#include <stdio.h>

int main() {
    int i, j, n, mat[50][50];
    do {
        printf("Unesite n: ");
        scanf("%d", &n);
    } while (n<1 || n>50);
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            mat[i][j]=j-i;
            printf("%5d", mat[i][j]);
        }
        printf("\n");
    }    
    return 0;
}

