#include <stdio.h>

int main() {
    int c, poz=1, temp, d, temppoz, i, e, temppoz2;
    char pomocni[]="href=\"";
    FILE* ulaz=fopen("index.html", "r");
    if(ulaz==NULL) {
        printf("Datoteka index.html ne postoji\n");
        return 1;
    }
    FILE* izlaz=fopen("linkovi.txt", "w");
    if(izlaz==NULL) {
        printf("Otvaranje datoteke linkovi.txt nije uspjelo\n");
        return 2;
    }
    int zadovoljava=0, otvoren=0, zavrseno=0;
    while((c=fgetc(ulaz))!=EOF) {
        if(otvoren && c=='>') {
            otvoren=0;
            zavrseno=0;
        }
        if(poz>1 && temp=='<' && c=='a' && !otvoren) otvoren=1;
        if(otvoren && !zavrseno) {
                FILE* temp=fopen("index.html", "r");
                if(temp==NULL) {
                    printf("Otvaranje datoteke index.html nije uspjelo\n");
                    return 2;
                }
                temppoz=1;
                i=0;
                while((d=fgetc(temp))!=EOF) {
                    if(temppoz>poz && d=='>') break;
                    if(temppoz>poz && !zavrseno) {
                        if(zadovoljava==6) {
                            temppoz2=1;
                            FILE* temp2=fopen("index.html", "r");
                            if(temp2==NULL) {
                                printf("Otvaranje datoteke index.html nije uspjelo\n");
                                return 3;
                            }
                            while((e=fgetc(temp2))!=EOF) {
                                if(temppoz2>=temppoz && e=='"') break;
                                if(temppoz2>=temppoz && e!='"') fputc(e,izlaz);
                                temppoz2++;
                            }
                            fputc(10,izlaz);
                            zavrseno=1;
                            fclose(temp2);
                            zadovoljava=0;
                            i=0;
                        }
                        else if(i<6 && d==pomocni[i]) {
                            zadovoljava++;
                            i++;
                        }
                        else {
                            zadovoljava=0;
                            i=0;
                        }
                    }
                    temppoz++;
                }
                fclose(temp);
            }
        temp=c;
        poz++;
    }
    fclose(ulaz);
    fclose(izlaz);
    return 0;
}


