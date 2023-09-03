#include <stdio.h>
#include <math.h>

long faktorijel(int n) {
    int i;
    long fact=1;
    for(i=1; i<=n; i++) {
        fact*=i;
    }
    return fact;
}
double sinus (double x, int n) {
    int i;
    double rez=0;
    for(i=1; i<=n; i++) {
        rez+=(double)((pow(-1,i-1)*pow(x,2*i-1))/faktorijel(2*i-1));
    }
    return rez;
}

int main() {
    double x;
    int n;
    printf("Unesite x: \n");
    scanf("%lf", &x);
    printf("Unesite n: \n");
    scanf("%d", &n);
    printf("sin(x)=%g\n", sin(x));
    printf("sinus(x)=%g\n", sinus(x, n));
    printf("Razlika: %f (%.2f%%).\n", fabs(sin(x)-sinus(x, n)), fabs(sin(x)-sinus(x, n)));
    return 0;
}


