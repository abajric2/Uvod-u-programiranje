#include <stdio.h>
#include <math.h>

int minmax2x(float* niz, int vel) {
    float max, min;
    int i;

max=fabs(*niz); 
for(i=1; i<vel; i++) {
    niz++;
    if(fabs(*niz)>max) max=fabs(*niz);
}
for(i=1; i<vel; i++) { 
    niz--;
}
min=fabs(*niz); 
for(i=1; i<vel; i++) {
    niz++;
    if(fabs(*niz)<min) min=fabs(*niz);
}

if(max>2*min) return 1; 
else return 0;          
}

int main() {
    float niz[1000];
    int i, n;
    printf("Uneiste broj clanova niza: ");
    scanf("%d", &n);
    printf("Unesite niz: ");
    for(i=0; i<n; i++) {
        scanf("%f", &niz[i]);
    }
    printf("Rezultat je: %d", minmax2x(niz, n));
    return 0;
}


