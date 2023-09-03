#include <stdio.h>

double stepen (double b, int e) {
    double stepen=1;
    
    while (e != 0) {
        if (e<0) {
        stepen*=(1./b);
        e++;
    }
        else {
        stepen*=b;
        e--;
        }
    }
    return stepen;
}

int main() {
    double b, e;
    printf("Unesite bazu: ");
    scanf("%lf", &b);
    printf("Unesite eksponent: ");
    scanf("%lf", &e);
    printf("Rezultat je: %g", stepen(b, e));
    return 0;
}


