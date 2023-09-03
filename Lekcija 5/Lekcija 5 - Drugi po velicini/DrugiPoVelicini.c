#include <stdio.h>

int drugi(int niz[], int vel) {
    int i, max=0, max_i, temp=0, j, pomocna=0;
    max=niz[0];
    max_i=0;
    for(i=1; i<vel; i++) {
        if(niz[i]>max) {
        max=niz[i];
        max_i=i;
    }
    }
    for(i=0; i<vel; i++) {
        if(niz[i]<max) {
            pomocna=1;
            temp=niz[i];
            max_i=i;
            for(j=0; j<vel; j++) {
                if(niz[j]>temp && niz[j]<max) {
                max_i=j;
                temp=niz[j];
                }
            }
            if(j==vel) break;
        }    
    }
    if(!pomocna) return -1;
    return max_i;
}

int main() {
    int i=0, niz[100], index;
    printf("Unesite niz brojeva: ");
    for(i=0; i<100; i++) {
        scanf("%d", &niz[i]);
        if(niz[i]==-1) break;
    }   
    index=drugi(niz,i);
    if(index!=-1) printf("Indeks drugog po velicini je: %d", index);
    else printf("Svi clanovi niza su isti.");
    return 0;
}


