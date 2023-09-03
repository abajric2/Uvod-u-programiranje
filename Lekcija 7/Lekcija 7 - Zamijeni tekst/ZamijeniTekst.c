#include <stdio.h>

char* zamijeni_tekst(char* str, const char *sta, const char *sa_cim, int cs) {
    char* temp1=str;
    const char* temp2=sta;
    const char* temp3=sa_cim;
    char* pom1;
    char* pomocna;
    const char* pom3;
    int brojac2=0, brojac3=0, br_pon=0;
    while(*temp2!='\0') {
        brojac2++;
        temp2++;
    }
    while(*temp3!='\0') {
        brojac3++;
        temp3++;
    }
    temp2=sta;
    temp3=sa_cim;
    while(*temp1!='\0') {
        temp2=sta;
        br_pon=0;
        pom1=temp1;
        if(cs) {
            while(*temp1!='\0' && *temp2!='\0' && *temp1==*temp2) {
                br_pon++;
                temp1++;
                temp2++;
            }
        }
        else {
            while(*temp1!='\0' && *temp2!='\0' && (*temp1==*temp2
             || (*temp1>='a' && *temp1<='z' && *temp1-('a'-'A')==*temp2)
             || (*temp1>='A' && *temp1<='Z' && *temp1+('a'-'A')==*temp2))) {
                br_pon++;
                temp1++;
                temp2++;
             }
        }
        temp1=pom1;
        if(br_pon==brojac2) {
            pom3=temp3;
            if(brojac2==brojac3) {
                while(*temp3!='\0') {
                    *pom1=*temp3;
                    pom1++;
                    temp3++;
                }
            }
            else if(brojac2<brojac3) {
                pomocna=temp1;
                while(*pomocna!='\0') pomocna++;
                *(pomocna+brojac3-brojac2)='\0';
                pomocna+=brojac3-brojac2-1;
                while(pomocna-(brojac3-brojac2)!=temp1+brojac2-1) {
                    *pomocna=*(pomocna-(brojac3-brojac2));
                    pomocna--;
                }
                while(*temp3!='\0') {
                    *temp1=*temp3;
                    temp1++;
                    temp3++;
                }
                temp1=pom1-1;
            }
            else {
                while(*temp3!='\0') {
                    *pom1=*temp3;
                    pom1++;
                    temp3++;
                }
                pomocna=temp1+brojac2;
                while(*pomocna!='\0') {
                    *pom1=*pomocna;
                    pom1++;
                    pomocna++;
                }
                *pom1='\0';
            }
            temp3=pom3;
        }
        temp1++;
    }
    return str;
}

int main() {
    printf("Lekcija 7: Stringovi, Zamijeni tekst");
    return 0;
}


