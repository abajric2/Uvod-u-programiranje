#include <stdio.h>

int main() {
    int N, i, j;
    do {
    printf("Unesite broj N: ");
    scanf("%d", &N);
    if(!(N%4==0 && N>=8)) printf("Neispravno N!\n");
    } while(!(N%4==0 && N>=8));
    for(i=0; i<N; i++) {
        for(j=0; j<N; j++) {
            if(i<N/2 && j<N/2) {
                if(i==j) printf("\\");
                else if(i+j==N/2-1) printf("/");
                else printf(" ");
            }
            else if(i>=N/2 && j<N/2) {
                if(i==N/2 && j==0 || i==N/2 && j==N/2-1
                || i==N-1 && j==0 || i==N-1 && j==N/2-1)
                printf("+");
                else if(i==N/2 || i==N-1) printf("-");
                else if(j==0 || j==N/2-1) printf("|");
                else printf(" ");
            }
            else if(i<N/2 && j>=N/2) {
                if(i==0 && j==N/2 || i==0 && j==N-1
                || i==N/2-1 && j==N/2 || i==N/2-1 && j==N-1)
                printf("+");
                else if(i==0 || i==N/2-1) printf("-");
                else if(j==N/2 || j==N-1) printf("|");
                else printf(" ");
            }
            else if(i>=N/2 && j>=N/2) {
                if(i==(3*N)/4 && i==j || i==(3*N)/4 && j==i-1
                || i==(3*N)/4-1 && i==j || i==(3*N)/4-1 && j==i+1)
                printf("+");
                else if(i==(3*N)/4 || i==(3*N)/4-1) printf("-");
                else if(j==(3*N)/4 || j==(3*N)/4-1) printf("|");
                else printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}


