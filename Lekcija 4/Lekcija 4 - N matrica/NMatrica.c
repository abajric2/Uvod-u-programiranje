#include <stdio.h>

int main() {
    int n, p, q, i, j, k, l=0;
    int suma[10]={0}, mat[10][5][5], maxsuma, maxi;
    do {
    printf("Unesite broj matrica: ");
    scanf("%d", &n);
    if(n<1 || n>10) printf("Broj matrica mora biti u opsegu [1,10]\n");
    } while(n<1 || n>10);
    do {
        printf("Unesite dimenzije matrice (p q): ");
        scanf("%d%d", &p, &q);
        if(p<1 || q<1 || p>5 || q>5) printf("p i q moraju biti u opsegu [1,5]\n");
    } while(p<1 || q<1 || p>5 || q>5);
    for(i=0; i<n; i++) {
        printf("Matrica br. %d\n", i+1);
        for(j=0; j<p; j++) {
            printf("%d. red: ", j+1);
            for(k=0; k<q; k++) {
                scanf("%d", &mat[i][j][k]);
                suma[l]+=mat[i][j][k];
            }
        }
        l++;
        printf("\n");
    }
    printf("Sume za sve matrice, format \"matrica: suma\":\n");
    for(i=0; i<n; i++) {
        printf("%d: %d", i+1, suma[i]);
        if(i<n-1) printf(", ");
    }
    maxsuma=suma[0];
    maxi=0;
    for(i=1; i<n; i++) {
        if(suma[i]>maxsuma) {
        maxsuma=suma[i];
        maxi=i;
        }
    }
    printf("\nMatrica s najvecom sumom: ");
    for(i=0; i<p; i++) {
        for(j=0; j<q; j++) {
            printf("%4d", mat[maxi][i][j]);
        }
        printf("\n");
    }
    return 0;
}


