#include <stdio.h>

int matrice_permutacija(double A[100][100], double B[100][100], double C[100][100], int M, int N) {
    int i, j, vel1=0, vel2=0, vel3=0, min=0;
    double niz1[10000], niz2[10000], niz3[10000], temp;
    for(i=0; i<M; i++) {           /*Kreiramo 3 pomocna niza i u njih stavimo elemente matrica*/
        for(j=0; j<N; j++) {
            niz1[vel1]=A[i][j];
            vel1++;
        }
    }
    for(i=0; i<M; i++) {
        for(j=0; j<N; j++) {
            niz2[vel2]=B[i][j];
            vel2++;
        }
    }
    for(i=0; i<M; i++) {
        for(j=0; j<N; j++) {
            niz3[vel3]=C[i][j];
            vel3++;
        }
    }
    for(i=0; i<vel1; i++) {   /*sortiramo nizove tako da budu u rastucem poretku*/
        min=i;
        for(j=i+1; j<vel1; j++) {
            if(niz1[j]<niz1[min]) min=j;
        }
        temp=niz1[i];
        niz1[i]=niz1[min];
        niz1[min]=temp;
    }
    for(i=0; i<vel2; i++) {
        min=i;
        for(j=i+1; j<vel2; j++) {
            if(niz2[j]<niz2[min]) min=j;
        }
        temp=niz2[i];
        niz2[i]=niz2[min];
        niz2[min]=temp;
    }
    for(i=0; i<vel3; i++) {
        min=i;
        for(j=i+1; j<vel3; j++) {
            if(niz3[j]<niz3[min]) min=j;
        }
        temp=niz3[i];
        niz3[i]=niz3[min];
        niz3[min]=temp;
    }
    i=0;
    while(i<vel1) {                      /*Ako su matrice sastavljene od istih elemenata,... */
        if(niz1[i]!=niz2[i]) return 0;   /*...ovo su onda identicni nizovi. Sva 3 niza su iste velicine...*/
        i++;                             /*...jer su matrice istih dimenzija*/
    }                                    /*Ako naidjemo na elemente s istim indeksom koji nisu jednaki...*/
    i=0;                                 /*...onda nije permutacija*/
    while(i<vel2) {
        if(niz2[i]!=niz3[i]) return 0;
        i++;
    }
    return 1;             /*Ako dodje do ove linije nizovi su identicni, pa je permutacija*/

}

int main() {
    int M, N, i, j;
    double A[100][100], B[100][100], C[100][100];
    printf("Unesite duzinu i sirinu za sve tri matrice: ");
    scanf("%d%d", &M, &N);
    printf("Unesite matricu A: ");
    for(i=0; i<M; i++) {
        for(j=0; j<N; j++) {
            scanf("%lf", &A[i][j]);
        }
    }
    printf("Unesite matricu B: ");
    for(i=0; i<M; i++) {
        for(j=0; j<N; j++) {
            scanf("%lf", &B[i][j]);
        }
    }
    printf("Unesite matricu C: ");
    for(i=0; i<M; i++) {
        for(j=0; j<N; j++) {
            scanf("%lf", &C[i][j]);
        }
    }
    if(matrice_permutacija(A,B,C,M,N)) 
    printf("Sve tri matrice sadrze iste elemente sa istim brojem ponavljanja.");
    else printf("Matrice ne sadrze iste elemente sa istim brojem ponavljanja.");
    return 0;
}


