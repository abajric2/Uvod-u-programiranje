#include <stdio.h>
#include <math.h>

double stepen(double x) {
    static int stepen=1;
    double rez;
    static double temp;
    if(x!=temp && stepen!=1) stepen=1;
    rez=pow(x,stepen);
    stepen++;
    temp=x;
    return rez;
}
void stepenuj_niz(double A[], int s[], int duzina) {
    int i=0, brojac=0;
    double pomocna, temp;
    while(i<duzina) {
        if(i!=0 && A[i]==pomocna) {  /*Provjeravamo da li je novi clan niza jednak prethodnom*/
            if(pomocna!=1) temp=stepen(1); /*Ako jeste, moramo funckiju pozvati nad nekim brojem...*/
            else temp=stepen(2);           /*...koji nije jednak tom broju, jer funckija stepen mora da se restartuje.*/
        }            
        pomocna=A[i];
        while(brojac<s[i]) {
            A[i]=stepen(pomocna);
            brojac++;
        }
        i++;
        brojac=0;
    }
}
int main() {
    int n, i, niz2[10000];
    double niz[10000];
    printf("Unesite velicinu za oba niza: ");
    scanf("%d", &n);
    printf("Unesite niz: ");
    for(i=0; i<n; i++) {
        scanf("%lf", &niz[i]);
    }
    printf("Unesite drugi niz: ");
    for(i=0; i<n; i++) {
        scanf("%d", &niz2[i]);
    }
    stepenuj_niz(niz,niz2,n);
    printf("Nakon stepenovanja niz je: \n");
    for(i=0; i<n; i++) {
        printf("%g ", niz[i]);
    }
    
    return 0;
}


