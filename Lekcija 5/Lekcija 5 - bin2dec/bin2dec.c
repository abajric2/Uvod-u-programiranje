#include <stdio.h>
#include <math.h>

short bin2dec(int bin) {
    short dec=0;
    int stepen=0;
    short br=0;
    int negativan=0;
    if(bin<0) {
        bin=-bin;
        negativan=1;
    }
    while (bin>0) {
    dec+=(bin%10)*(pow(2,stepen));
    stepen++;
    bin/=10;
    }
    if (negativan) dec=-dec;
    return dec;
}
int main() {
    int bin;
    printf("Unesite broj u binarnom zapisu (ne veci od 1111111111): \n");
    scanf("%d", &bin);
    printf("Decimalan br je: %d", bin2dec(bin));
    return 0;
}


