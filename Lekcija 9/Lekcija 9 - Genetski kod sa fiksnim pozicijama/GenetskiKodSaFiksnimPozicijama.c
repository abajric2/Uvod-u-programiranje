#include <stdio.h>

int main() {
    int c, brojac=0, poz=1;
    FILE* ulaz=fopen("genetski_kod.txt", "r");
    if(ulaz==NULL) {
        printf("Otvaranje datoteke genetski_kod.txt nije uspjelo\n");
        return 1;
    }
    while((c=fgetc(ulaz))!=EOF) {
    brojac++;
    if(!(c==65 || c==67 || c==71 || c==84)) {
        printf("Pogresan format\n");
        return 2;
    }
    }
    fclose(ulaz);
    if(brojac%3!=0 || brojac==0) {
    printf("Pogresan format\n");
    return 3;
    }
    int temp1, temp2, temp3, zadovoljava=0, maxpoz=1, max=1;
    brojac=1;
    ulaz=fopen("genetski_kod.txt", "r");
    while((c=fgetc(ulaz))!=EOF) {
        if(poz>3) {
            if(zadovoljava==3) {
                zadovoljava=0;
                brojac++;
                if(brojac>max) {
                    max=brojac;
                    maxpoz=poz-brojac*3;
                }
            }
            if(poz%3==1 && c==temp1) zadovoljava++;
            else if(poz%3==2 && c==temp2) zadovoljava++;
            else if(poz%3==0 && c==temp3) zadovoljava++;
            if(poz%3==0 && zadovoljava<3) {
            zadovoljava=0;
            brojac=1;
            }
        }
        if(poz%3==1) temp1=c;
        if(poz%3==2) temp2=c;
        if(poz%3==0) temp3=c;
        poz++;
    }
    if(zadovoljava==3) {
        brojac++;
        if(brojac>max) {
            maxpoz=poz-brojac*3;
        }
    }
    fclose(ulaz);
    ulaz=fopen("genetski_kod.txt", "r");
    if(ulaz==NULL) {
        printf("Otvaranje datoteke genetski_kod.txt nije uspjelo\n");
        return 4;
    }
    poz=1;
    while((c=fgetc(ulaz))!=EOF) {
        if(poz>=maxpoz && poz<maxpoz+3) printf("%c", c);
        poz++;
    }
    printf("\n");
    return 0;
}


