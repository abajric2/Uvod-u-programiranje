#include <stdio.h>
#include<math.h>

void oduzmi_cifre (int niz[], int vel) {
    int i, j=0, temp, cifra, rez, pom, niz1;
    for(i=0; i<vel; i++) {
        pom=0;
        temp=0;
        niz1=niz[i];
        if(niz1<0) niz1=-niz1;
        temp=niz1%10;
        niz1/=10;
        if(niz1==0) {
            niz[i]=0;
        }
        else {
        do {
            cifra=temp-niz1%10;
            if(cifra<0) cifra=-cifra;
            temp=niz1%10;
            niz1/=10;
            rez=pow(10,j)*cifra+pom;
            j++;
            pom=rez;
            
        } while(niz1!=0);
        j=0;
        niz[i]=rez;
        }
    }
}

int main() {
    int i, n, niz[100];
    printf("Unesite broj elemenata niza: ");
    scanf("%d", &n);
    printf("Uneiste niz brojeva: ");
    for(i=0; i<n; i++) {
        scanf("%d", &niz[i]);
    }
    printf("Rezultujuci niz je: ");
    oduzmi_cifre(niz,n);
    for(i=0; i<n; i++) {
        printf("%d, ", niz[i]);
    }

    return 0;
}


