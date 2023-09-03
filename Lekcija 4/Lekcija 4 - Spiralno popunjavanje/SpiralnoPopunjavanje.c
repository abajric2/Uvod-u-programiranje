#include <stdio.h>

int main() {
    int M, N, i, j, temp=1, mat[100][100];
    int temp1=-1, temp2=-1, temp3, temp4, kraj=0;
    do {
    printf("Unesite broj M: ");
    scanf("%d", &M);
    } while(M<1 || M>100);
    temp3=M;
    temp4=M-1;
    i=M-1;
    j=M;
    do {
        for(j-=1; j>temp1; j--) {
            mat[i][j]=temp;
            if(mat[i][j]==M*M) {
            kraj=1;
            break;
            }
            temp++;
        }
        if(kraj) break;
        j++;
        temp1=j;
        for(i-=1; i>temp2; i--) {
            mat[i][j]=temp;
            if(mat[i][j]==M*M) {
            kraj=1;
            break;
            }
            temp++;
        }
        if(kraj) break;
        i++;
        temp2=i;
        for(j+=1; j<temp3; j++) {
            mat[i][j]=temp;
            if(mat[i][j]==M*M) {
            kraj=1;
            break;
            }
            temp++;
        }
        if(kraj) break;
        j--;
        temp3=j;
        for(i+=1; i<temp4; i++) {
            mat[i][j]=temp;
            if(mat[i][j]==M*M) {
            kraj=1;
            break;
            }
            temp++;
        }
        if(kraj) break;
        i--;
        temp4=i;
    } while(mat[i][j]!=M*M);
    for(i=0; i<M; i++) {
        for(j=0; j<M; j++) {
            printf("%4d", mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}


