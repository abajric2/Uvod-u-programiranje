#include <stdio.h>

int daj_sljedeci_broj(int pokusaj) {
    static int donja_gr=0, gornja_gr=100, sr;
    sr=(donja_gr+gornja_gr)/2;
    if(pokusaj==1) donja_gr=sr;
    else if(pokusaj==-1) gornja_gr=sr;
    else if(pokusaj==0) return sr;
    sr=(donja_gr+gornja_gr)/2;
    return sr;
}
int main() {
    int pokusaj=0, temp, greska=0;
    char slovo;
    printf("Zamislite neki broj...\n");
    do {
        if(greska) printf("Da li je taj broj %d? ", temp);
        else printf("Da li je taj broj %d? ", temp=daj_sljedeci_broj(pokusaj));
        greska=0;
        scanf(" %c", &slovo);
        if(slovo=='V') pokusaj=1;
        else if(slovo=='M') pokusaj=-1;
        else if(slovo=='J') {
        pokusaj=0;
        break;
        }
        if(!(slovo=='V' || slovo=='M' || slovo=='J')) { 
        printf("Pogresan unos, probajte ponovo.\n");
        greska=1;
        }
    } while(slovo!='J');
    if(slovo=='J') printf("Pogodio sam!");
    return 0;
}


