#include <stdio.h>

int korijen (int a) {
    int korijen;
    int pomocna=1;
    if (a<0) return -1;
    korijen=a/2+1;
    while (korijen != pomocna) {
        pomocna=korijen;
        korijen=(a/pomocna+pomocna)/2;
    }
    if (a%korijen != 0) return -1;
    return korijen;
}

int main() {
    int a;
    printf("Unesite cijeli broj: ");
    scanf("%d", &a);
    printf("Korijen unesenog broja je: %d", korijen(a));
    return 0;
}


