#include <stdio.h>

int obrnut (int n) {
    int obrnut_br=0;
    int neg=0;

    if(n<0) {
        neg=1;
        n=-n;
    }
    while (n>0) {
        obrnut_br=obrnut_br*10+n%10;
        n /= 10;
    } 
    if (neg) obrnut_br=-obrnut_br;
    return obrnut_br;
}

int main() {
    int n;

    scanf("%d", &n);
    printf("Obrnut broj je: %d", obrnut(n));

    return 0;
}


