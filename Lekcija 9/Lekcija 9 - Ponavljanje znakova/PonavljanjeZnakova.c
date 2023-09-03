#include <stdio.h>

int main() {
    int n, poz=1, temp, c, isti=1;
    printf("Unesite broj: ");
    scanf("%d", &n);
    if(n<1) {
        printf("Pogresan unos");
        return 1;
    }
    FILE* ulaz=fopen("input.txt", "r");
    if(ulaz==NULL) {
        printf("Otvaranje datoteke input.txt nije uspjelo\n");
        return 2;
    }
    FILE* izlaz=fopen("output.txt", "w");
    if(izlaz==NULL) {
        printf("Otvaranje datoteke output.txt nije uspjelo\n");
        return 3;
    }
    int d, temppoz;
    while((c=fgetc(ulaz))!=EOF) {
        if(poz>1) {            
            if(c==temp) isti++;
            else {
                if(isti>=n) {
                    FILE* pomocna=fopen("input.txt", "r");
                    if(pomocna==NULL) {
                        printf("Otvaranje datoteke input.txt nije uspjelo\n");
                        return 4;
                    }
                    temppoz=1;
                    while((d=fgetc(pomocna))!=EOF) {
                        if(temppoz>=poz-isti && temppoz<poz) fputc(d,izlaz);
                        if(ferror(pomocna) || ferror(ulaz) || ferror(izlaz)) {
                            printf("Greska!\n");
                            break;
                        }
                        temppoz++;
                    }
                    fclose(pomocna);
                }
                isti=1;
            }
        }
        temp=c;
        poz++;
    }
    fclose(ulaz);
    if(isti>=n) {
        FILE* pomocna=fopen("input.txt", "r");
        if(pomocna==NULL) {
            printf("Otvaranje datoteke input.txt nije uspjelo\n");
            return 5;
        }
        temppoz=1;
        while((c=fgetc(pomocna))!=EOF) {
            if(temppoz>=poz-isti && temppoz<poz) fputc(c,izlaz);
            if(ferror(pomocna) || ferror(izlaz)) {
                printf("Greska!\n");
                break;
            }
            temppoz++;
        }
        fclose(pomocna);
    }
    fclose(izlaz);
    return 0;
}


