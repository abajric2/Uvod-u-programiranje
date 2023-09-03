#include <stdio.h>

int main() {
    
    int hh, mm, dan;
    double kolicina_pas, pas_meso, pas_ostalo, kolicina_macka, kolicina_kornjaca;
    printf("Unesite trenutno vrijeme (hh:mm): ");
    scanf("%d:", &hh);
    scanf("%d", &mm);
    
    if (hh<0 || hh>23 || mm<0 || mm>60) {
    return 1; 
    }

    printf("Unesite redni broj dana u sedmici: ");
    scanf("%d", &dan);

    if(hh<8) {
        printf ("Ljubimci ne smiju jesti prije 8:00h!");
        return 0;
    }

    if(dan<1 || dan>7) {
        return 1;
    }

    kolicina_pas=(double)(hh+mm+dan)/34;
    pas_meso=kolicina_pas/3;
    pas_ostalo=kolicina_pas-pas_meso;
    kolicina_macka=(double)(2*hh)/40+(double)dan/7;
    kolicina_kornjaca=(double)(7+hh)/(dan+154);

    if(hh>=18) {
        printf("Pas ce dobiti %d kreker/a.\n", dan*7);
    }
    else {
        printf ("Pas ce pojesti %.2fkg hrane, od toga %.2fkg mesa i %.2fkg ostale hrane.\n", kolicina_pas, pas_meso, pas_ostalo);
    }
    printf("Macka ce pojesti %.2fkg hrane.\n", kolicina_macka);
    printf("Kornjaca ce pojesti %.2fkg hrane.\n", kolicina_kornjaca);
    if(dan==4) 
    printf("Kornjaca ce dobiti i kalcij posto je cetvrtak.");
    return 0;
}

