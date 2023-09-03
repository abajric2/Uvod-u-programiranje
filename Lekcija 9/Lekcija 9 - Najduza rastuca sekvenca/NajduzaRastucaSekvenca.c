#include <stdio.h>

int main() {
    int c, poz=1, brojac=0, temp, max_poz=1, temp_poz=1, max=0;
    FILE* ulaz=fopen("ulaz.txt", "r");
    if(ulaz==NULL) {
        printf("Otvaranje datoteke ulaz.txt nije uspjelo\n");
        return 1;
    }
    while((c=fgetc(ulaz))!=EOF) {
        if(poz>1 && c==temp+1) {
            if(brojac==0) temp_poz=poz-1;
            brojac++;
        }
        else if(brojac) {
            if(brojac>max) {
            max=brojac;
            max_poz=temp_poz;
            }
            brojac=0;
        }
        else brojac=0;
        temp=c;
        poz++;
    }
    max++;
    fclose(ulaz);
    poz=1;
    FILE* ulazna=fopen("ulaz.txt", "r");
    if(ulazna==NULL) {
        printf("Otvaranje datoteke ulaz.txt nije uspjelo\n");
        return 2;
    }
    FILE* izlaz=fopen("izlaz.txt", "w");
    if(izlaz==NULL) {
        printf("Otvaranje datoteke izlaz.txt nije uspjelo\n");
        fclose(ulazna);
        return 3;
    }
    while((c=fgetc(ulazna))!=EOF) {
        if(poz>=max_poz && poz<max_poz+max) {
        fputc(c, izlaz);
        if(ferror(ulazna) || ferror(izlaz)) {
            printf("Greska!");
            break;
        }
        }
        poz++;
    }
    fclose(ulazna);
    fclose(izlaz);
    return 0;
}


