#include <stdio.h>

void obrni_cifre (int *p, int n) {
    int i;
    int obrnut=0, temp, neg=0;
    for (i=0; i<n; i++) {
    temp=*p;
    if(temp<0) {
        neg=1;
        temp=-temp;
    }
    while (temp>0) {
        obrnut=obrnut*10+temp%10;
        temp /= 10;
    }
    if (neg) obrnut=-obrnut;    
    *p=obrnut;
    p++;
    obrnut=0;
    neg=0;
    }
}

int main() {
    int i, n, niz[1000];
    /*pretpostavimo da broj clanova niza ne prelazi 1000*/
    do {
    printf("Unesite velicinu niza: ");
    scanf("%d", &n);
    } while (n<1 || n>1000);
    printf("Unesite niz: ");
    int *pok=niz;
    for(i=0; i<n; i++) {
        scanf("%d", pok++);
    }
    obrni_cifre(niz, n);
    printf("Niz sa obrnutim ciframa je: ");
    pok=niz;
    for(i=0; i<n; i++) {
        printf("%d ", *pok++);
    }
    return 0;
}


