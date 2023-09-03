#include <stdio.h>

int main() {
    char x, y;
    int c;
    printf("Unesite znakove x i y: ");
    scanf(" %c %c", &x, &y);
    if(y<x) {
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
        fclose(ulaz);
        printf("Otvaranje datoteke output.txt nije uspjelo\n");
        return 3;
    }
    while((c=fgetc(ulaz))!=EOF) {
        if(c>=x && c<=y) fputc(c, izlaz);
        if(ferror(ulaz) || ferror(izlaz)) {
            printf("Greska\n");
            break;
        }
    }
    fclose(ulaz);
    fclose(izlaz);

    return 0;
}


