#include <stdio.h>

int main() {
    int n, i, j;
    printf("Unesite n: ");
    scanf("%d", &n);
    if(n<2 || n>10) {
        printf("Uneseni broj nije u intervalu!");
        return 1;
    }
    for(i=1; i<=n; i++) {
        for(j=1; j<=n; j++) {
        printf("%4d", i*j);
        }
        printf("\n");
    }

    return 0;
}


