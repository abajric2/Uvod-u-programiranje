#include <stdio.h>

int daj_prost () {
    static int n=2;
    int nije_prost=1, i;
    while (nije_prost) {
        nije_prost=0;
        for(i=2; i*i<=n; i++) {
            if(n%i==0) nije_prost=1;
        }
        n++;
    }
    return n-1;
}

int main() {
    int A, B, i, suma=0;
        do {
        printf("Unesite brojeve A i B: ");
        scanf("%d%d", &A, &B);
        if(A>=B) printf("A nije manje od B.\n");
        else if(A<1) printf("A nije prirodan broj.\n");
        else if(B<1) printf("B nije priordan broj.\n");
    } while(A>=B || A<1 || B<1);
    do {
        i=daj_prost();
        if(i>A && i<B) suma+=i;
    } while (i<B);
    printf("Suma prostih brojeva izmedju %d i %d je %d.", A, B, suma);
    return 0;
}


