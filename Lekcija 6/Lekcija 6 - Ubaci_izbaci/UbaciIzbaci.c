#include <stdio.h>

int suma_cifara(int n) {
    int suma=0;
    if(n<0) n=-n;
    do {
        suma+=n%10;
        n/=10;
    } while(n!=0);
    return suma;
}
int fibonacci_br (int n) {
    int a, b, c;
    b=1;
    if(n==b) return 1;
    c=1;
    while(c<=n) {
        if(c==n) return 1;
        a=b;
        b=c;
        c=a+b;
    }
    return 0;
}

void ubaci(int* niz, int vel) {
    int i, j, temp=0;
    for(i=0; i<vel; i+=2) {
        temp=*(niz+i);
        for(j=vel; j>i; j--) {
            *(niz+j)=*(niz+j-1);
        }
        *(niz+i+1)=suma_cifara(temp);    
        vel++;
    }
}
int izbaci(int* niz, int vel) {
    int i, j;
    for(i=0; i<vel; i++) {
        if(fibonacci_br(*(niz+i))) {
            for(j=i+1; j<vel; j++) {
                *(niz+j-1)=*(niz+j);
            }
            vel--;
            i--;
        }
    }
    return vel;
}

int main() {
    int vel, niz[10000], i;
    printf("Unesite niz od 10 brojeva: ");
    for(i=0; i<10; i++) {
        scanf("%d", niz+i);
    }
    ubaci(niz,10);
    vel=izbaci(niz,20);
    printf("Modificirani niz glasi: ");
    for(i=0; i<vel; i++) {
        printf("%d", *(niz+i));
        if(i<vel-1) printf(", ");
        else printf(".");
    }
    return 0;
}


