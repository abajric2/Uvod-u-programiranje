#include <stdio.h>

int provjeri(int matrica[100][100], int V) {
    int i, j, temp=0;
    for(i=0; i<V; i++) {
        for(j=0; j<100; j++) {
            if(matrica[i][j]==-1) {
            temp=1;
            break;
            }
            if(matrica[i][j]<=0) return 0;
        }
        if(!temp) return 0;
        temp=0;
    }
    return 1;
}
int fibonacci_br(int n) {
    int a, b, c;
    a=0;
    b=1;
    c=a+b;
    if(n==b || n==a) return 1;
    while(c<=n) {
        if(c==n) return 1;
        a=b;
        b=c;
        c=a+b;
    }   
    return 0;
}
int fibonacci_matrica(int matrica[100][100], int V) {
    int i, j, temp=1;
    for(i=0; i<V; i++)  {
        for(j=0; j<100; j++) {
            if(matrica[i][j]==-1) break;
            if(!fibonacci_br(matrica[i][j])) return 0;
            if(j>=2 && matrica[i][j]!=matrica[i][j-1]+matrica[i][j-2]) return 0;
        }
    }
    return 1;
}
int main() {
    int visina, mat[100][100], i, j; 
    do {
    printf("Unesite visinu matrice: ");
    scanf("%d", &visina);
    } while(visina<=0);
    printf("Unesite matricu: \n");
    for(i=0; i<visina; i++) {
        for(j=0; j<100; j++) {
            do {
            scanf("%d", &mat[i][j]);
            } while(mat[i][j]<-1 || mat[i][j]==0);
            if(mat[i][j]==-1) break;
        }
    }
    if(provjeri(mat,visina)) printf("Matrica je validna.\n");
    else printf("Matrica nije validna.\n");
    if(provjeri(mat,visina) && fibonacci_matrica(mat, visina)) printf("Matrica je Fibonacci matrica.\n");
    else printf("Matrica nije Fibonacci matrica.\n");

    return 0;
}


