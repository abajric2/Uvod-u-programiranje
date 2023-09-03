#include <stdio.h>

int main() {

    int i, j, k=0, l, brojac1=0, brojac2=0, brojac3=0, temp;
    double niz1[50], niz2[50], niz3[50], pomocni[50];

    printf("Unesite elemente 1.niza (-1 kraj): \n");
    for(i=0; i<50; i++) {
        scanf("%lf", &niz1[i]);
        if(niz1[i]==-1) break;
        brojac1++;       
    }

    printf("Unesite elemente 2.niza (-1 kraj): \n");
    for(i=0; i<50; i++) {
        scanf("%lf", &niz2[i]);
        if(niz2[i]==-1) break;
        brojac2++;       
    }

    for(i=0; i<brojac1; i++) {
        pomocni[i]=niz1[i];
        for(j=0; j<brojac2; j++) {
            temp=0;
            for(l=0; l<i; l++) {
                if(pomocni[l]==niz1[i]) temp=1;
            } 
            if(temp) break;
            if(niz1[i]==niz2[j]) {                
                niz3[k]=niz2[j];
                brojac3++;
                k++;
                break;
                }
            }
        }
        
        if(brojac3==0) 
        printf("Presjek unesenih nizova je prazan skup!");
        else {
        printf("Presjek unesenih nizova je: ");
        for(i=0; i<brojac3; i++) {
            printf("%g", niz3[i]);
            if(i<brojac3-1) printf(", ");
        }
        }

    return 0;
}


