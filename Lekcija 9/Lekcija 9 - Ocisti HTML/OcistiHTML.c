#include <stdio.h>

int main() {
    int c, otvoren_tag=0, otvoren_entitet=0;
    FILE* ulaz=fopen("index.html", "r");
    if(ulaz==NULL) {
        printf("Datoteka index.html ne postoji");
        return 1;
    }
    FILE* izlaz=fopen("index.txt", "w");
    if(izlaz==NULL) {
        printf("Datoteka index.txt ne postoji");
        fclose(ulaz);
        return 2;
    }
    while((c=fgetc(ulaz))!=EOF) {
        if(!otvoren_tag && c=='<') otvoren_tag=1;        
        if(otvoren_tag && c=='>') otvoren_tag=0;
        if(!otvoren_entitet && c=='&') otvoren_entitet=1;
        if(otvoren_entitet && c==';') otvoren_entitet=0;   
        if(!otvoren_entitet && !otvoren_tag && c!='<' && c!='&' && c!='>' && c!=';') fputc(c,izlaz);
        if(ferror(ulaz) || ferror(izlaz)) {
            printf("Greska");
            break;
        }
    }
    fclose(ulaz);
    fclose(izlaz);
    return 0;
}


