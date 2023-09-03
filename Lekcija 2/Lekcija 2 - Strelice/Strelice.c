#include <stdio.h>

int main() {
    int n, i, j;
    printf("Unesite n: ");
    scanf("%d", &n);
    if(n<2) {
        printf("Neispravan unos");
        return 1;
    }
    for(i=0; i<=2*n-2; i++) {
        for(j=0; j<=2*n; j++) {
            if(j<n && j<=i && j<=2*n-2-i 
            || j>n && j>=2*n-i && j>=i+2) printf("*");
            else printf(" ");
        }
        printf("\n");
    }
    return 0;
}


