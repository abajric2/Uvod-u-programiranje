#include <stdio.h>

int main() {
    int i, niz[100000], brojaci[100000]={0};

    printf("Unesite brojeve: \n");
    for(i=0; i<100000; i++) {
        scanf("%d", &niz[i]);
        if(niz[i]==-1) break;
        if(niz[i]<0 || niz[i]>100) {
            printf("Brojevi moraju biti izmedju 0 i 100!\n");
            i--;
        }
        else brojaci[niz[i]]++;
    }

    for(i=0; i<=100; i++) {
        if(brojaci[i] != 0) printf("Broj %d se javlja %d puta.\n", i, brojaci[i]);
    }

    return 0;
}


