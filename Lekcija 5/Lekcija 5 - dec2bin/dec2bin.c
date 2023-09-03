#include <stdio.h>
#include <math.h>

int dec2bin (short dec) {
    int bin=0;
    int bin_obrnut=0;
    int rez=0;
    int brojac=0;
    int broj;
    int negativan=0;
    if (dec<0) {
        dec=-dec;
        negativan=1;
    }
    broj=dec;
    while (dec>0) {
    rez=dec%2;
    dec/=2;
    bin_obrnut=bin_obrnut*10+rez;
    brojac++;
    }
    while (bin_obrnut>0) {
        bin=bin*10+bin_obrnut%10;
        bin_obrnut/=10;
    }
    if(broj%4==0) {
        bin=pow(10,brojac-1);
    }
    if (negativan) bin=-bin;

    return bin;
}

int main() {
    short dec;
    do {
    printf("Unesite broj u decimalnom zapisu: ");
    scanf("%hi", &dec);
    } while(dec>1023);
    printf("Binarni zapis unesenog broja je: %d", dec2bin(dec));
    return 0;
}


