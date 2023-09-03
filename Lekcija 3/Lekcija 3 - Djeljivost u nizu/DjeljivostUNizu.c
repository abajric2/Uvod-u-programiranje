#include <stdio.h>
#define BROJ_EL 1000

int main() {
    int niz[BROJ_EL], i, sa_pet=0, sa_sedam=0, sa_jedanaest=0;
    printf("Unesite brojeve:\n");

    for(i=0; i<BROJ_EL; i++) {
        scanf("%d", &niz[i]);
        if (niz[i] % 5 == 0) 
        sa_pet++; 
        if (niz[i] % 7 == 0)
        sa_sedam++;
        if (niz[i] % 11 == 0)
        sa_jedanaest++;
        if (niz[i] == -1) break;
    }
    printf("Djeljivih sa 5: %d\n", sa_pet);
    printf("Djeljivih sa 7: %d\n", sa_sedam);
    printf("Djeljivih sa 11: %d\n", sa_jedanaest);        

    
    return 0;
}


