#include <stdio.h>
#include <math.h>

int armstrong(int n) {
    int temp, br_cifara=0, suma=0, c;
    temp=n;
    do {
        temp/=10;
        br_cifara++;
    } while (temp!=0);
    temp=n;
    do{
        c=temp%10;
        temp/=10;
        suma+=pow(c,br_cifara);
    } while(temp!=0);
    if(suma==n) return 1;
    else return 0;
} 

int main() {
    int n;
    printf("Unesite broj n: ");
    scanf("%d", &n);
    printf("Ako je rezultat 1, broj jeste Armstrongov broj, a ako je 0 nije. \nRezultat je: %d", armstrong(n));

    return 0;
}


