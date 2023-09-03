#include <stdio.h>

int maxprost(int* niz, int vel) {
    int i, j, temp=0, br_prostih=0, max=0;
    for(i=0; i<vel; i++) {
        temp=0;
        for(j=2; j<=*(niz+i)/2; j++) {
            if(*(niz+i)%j==0 || *(niz+i)<0) {
                temp=1;
                break;
            }
        }
            if(temp==0 && *(niz+i)!=1) {
                br_prostih++;
                if(*(niz+i)>max) max=*(niz+i);
            }
    }
    if (br_prostih==0) return 0;
    else return max;
}

int main() {
    int n, i, niz[10000];
    int *pok=niz;
    printf("Unesite velicinu niza: ");
    scanf("%d", &n);
    printf("Unesite niz: ");
    for(i=0; i<n; i++) {
        scanf("%d", pok++);
    }
    printf("Najveci prost broj u nizu je: %d", maxprost(niz, n));
    return 0;
}


