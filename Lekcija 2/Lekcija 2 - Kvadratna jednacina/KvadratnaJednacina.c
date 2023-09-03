#include <stdio.h>
#include <stdio.h>
#include <math.h>
#define EPSILON 0.001

int main() {
    double a, b, c, x1, x2, rj1, rj2, temp;
    printf("Unesite koeficijente a, b i c: ");
    scanf("%lf%lf%lf", &a, &b, &c);
    if(0-pow(b,2)+4*a*c>EPSILON) {
        printf("Rjesenja su imaginarni brojevi.");
        return 1;
    }
    rj1=(-b-sqrt(pow(b,2)-4*a*c))/(2*a);
    rj2=(-b+sqrt(pow(b,2)-4*a*c))/(2*a);
    if(rj1-rj2>EPSILON) {
        temp=rj1;
        rj1=rj2;
        rj2=temp;
    }
    do {
        printf("Unesite rjesenje x1: ");
        scanf("%lf", &x1);
        if(fabs(x1-rj1)<EPSILON) {
        printf("Tacno\n");
        break;
        }
        if(fabs(x1-rj1)>=0.1 && rj1-x1>EPSILON) printf("Manje\n");
        else if(fabs(x1-rj1)>=0.1 && x1-rj1>EPSILON) printf("Vece\n");
        else if(rj1-x1>EPSILON) printf("Priblizno manje\n");
        else printf("Priblizno vece\n");
    } while(!(fabs(x1-rj1)<EPSILON));
    do {
        printf("Unesite rjesenje x2: ");
        scanf("%lf", &x2);
        if(fabs(x2-rj2)<EPSILON) {
        printf("Tacno\n");
        break;
        }
        if(fabs(x2-rj2)>=0.1 && rj2-x2>EPSILON) printf("Manje\n");
        else if(fabs(x2-rj2)>=0.1 && x2-rj2>EPSILON) printf("Vece\n");
        else if(rj2-x2>EPSILON) printf("Priblizno manje\n");
        else printf("Priblizno vece\n");
    } while(!(fabs(x2-rj2)<EPSILON));

    return 0;
}


