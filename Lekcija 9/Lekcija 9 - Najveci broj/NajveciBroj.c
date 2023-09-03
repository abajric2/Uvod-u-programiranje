#include <stdio.h>

int main() {
    int broj=0, max=0, c, cifra=0, neg=0, i=0;

    FILE* ulaz=fopen("zadatak.txt", "r");
    if(ulaz==NULL) {
        printf("Otvaranje datoteke zadatak.txt nije uspjelo\n");
        return 1;
    }
    FILE* izlaz=fopen("rjesenje.txt", "w");
    if(izlaz==NULL) {
        fclose(ulaz);
        printf("Otvaranje datoteke rjesenje.txt nije uspjelo\n");
        return 2;
    }
    while((c=fgetc(ulaz)) != EOF) {
        if(!(c>='0' && c<='9') && neg && broj!=0) broj=-broj;
        if(c=='-') neg=1;
        if(!(c>='0' && c<='9') && cifra) i++;
        if(i==1) {
            max=broj;
            i++;
        }
        if(c>='0' && c<='9') {
            broj=broj*10+(c-'0');
            cifra=1;
        }
        else cifra=0;
        if(broj!=0 && broj>max && i>1 && !cifra) max=broj;
        if(!cifra && c!='-') neg=0;
        if(!cifra) broj=0;
    }
    if(i==0) max=broj;
    fprintf(izlaz, "%d", max);
    fclose(ulaz);
    fclose(izlaz);

    return 0;
}


