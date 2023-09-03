#include <stdio.h>
#include <math.h>

int main() {
    int n, i;
    double x, f=0, razlika;
    do {
    printf("Unesite broj x: ");
    scanf("%lf", &x);
    if(x<=-1 || x>=1) printf("Greska.\n");
    } while(x<=-1 || x>=1);
    do {
    printf("Unesite broj n: ");
    scanf("%d", &n);
    if(n<1) printf("Greska.\n");
    } while(n<1);
    for(i=1; i<=n; i++) {
        f+=((pow(-1,i-1)*pow(x,i))/i);
    }
    if(x==0) razlika=0; 
    /*Za ove vrijednosti dobije se ln1, a to je 0. U datoj formuli takodjer se dobije 0.
    Dakle, razlika je 0 pa preskacemo sljedecu formulu zbog dijeljenja sa 0.*/
    else razlika=((f-log(1+x))*100)/log(1+x);
    printf("Izracunata vrijednost: %6f\n", f);
    printf("Bibliotecna funkcija: %6f\n", log(1+x));
    printf("Razlika u postotcima: %.2f%%", razlika);
    return 0;
}


