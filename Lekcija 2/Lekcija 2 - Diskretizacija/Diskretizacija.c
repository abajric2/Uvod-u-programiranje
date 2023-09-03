#include <stdio.h>
#include <math.h>

int main() {
    double n, k, x, i, y;
    printf("Unesite n: ");
    scanf("%lf", &n);
    printf("Unesite korak diskretizacije: ");
    scanf("%lf", &k);
    printf("Unesite pocetnu vrijednost x: ");
    scanf("%lf", &x);
    printf("x     y=f(x)\n");
    printf("------------\n");
    for (i=0; i<n; i++) {
        printf("%.1f   ", x);
        y=pow(x,3)+5*pow(x,2)-7*x+14;
        printf("%.2f\n", y);
        x+=k;
    }
    return 0;
}


