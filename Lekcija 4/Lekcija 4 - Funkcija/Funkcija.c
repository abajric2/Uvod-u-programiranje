#include <stdio.h>

int main() {
    int n, i, j, mat[100][100];
    printf("Crtat cemo funkciju y + x = n. ");
    do {
    printf("Unesite n: ");
    scanf("%d", &n);
    } while(n<=0 || n>20);
    for(i=0; i<=11; i++) {
        for(j=0; j<=21; j++) {
            if(i>=0 && i<=10 && j==0) mat[i][j]=10-i;
            else if(i==11 && j>=1 && j<=21) mat[i][j]=j-1;
            else if(i>(10-n) && i<10 && j>1 && j<=(20-n) && (i-j)==(10-n-1)) mat[i][j]=-1;
            else if(i==11 && j==0) mat[i][j]=-2;
            else if(j==1 && i>=0 && i<=10) mat[i][j]=-3;
            else if(i==10 && j>=2 && j<=21) mat[i][j]=-4;
            else if(j<=n+1+i-10) mat[i][j]=-5;
        }
    }
 
    for(i=0; i<=11; i++) {
        for(j=0; j<=21; j++) {
            if(i==0 && j==0) printf("%d", mat[i][j]);
            else if(i>0 && i<=10 && j==0) printf("%d ", mat[i][j]);
            else if(mat[i][j]==-3) printf("+");
            else if(i==11 && j>=1 && j<=10) printf("  %d", mat[i][j]);
            else if(i==11 && j>10 && j<=21) printf(" %d", mat[i][j]);
            else if(mat[i][j]==-4) printf("  +"); 
            else if(mat[i][j]==-1 && j<=10) printf("  *");
            else if(mat[i][j]==-1 && j>10) printf(" *");
            else if(mat[i][j]==-5) printf("   ");
        } 
        printf("\n");
    }

    return 0;
}


