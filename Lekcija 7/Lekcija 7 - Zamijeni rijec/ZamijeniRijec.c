#include <stdio.h>

char* zamijeni_rijec(char* str, const char *sta, const char *sa_cim, int cs) {
    char* temp_str=str;
    const char* temp_sta=sta;
    const char* temp_sa_cim=sa_cim;
    const char* temp_sa_cim1;
    char* temp_str1;
    char* temp;
    int brojac1=0, brojac2=0, pon;
    while(*temp_sta!='\0') {
        brojac1++;
        temp_sta++;
    }
    while(*temp_sa_cim!='\0') {
        brojac2++;
        temp_sa_cim++;
    }
    temp_sta=sta;
    temp_sa_cim=sa_cim;
    while(*temp_str!='\0') {
        temp_sta=sta;
        pon=0;
        temp_str1=temp_str;
        if(!cs) 
            while(*temp_str!='\0' && *temp_sta!='\0' && 
            (*temp_str==*temp_sta || (*temp_str>='A' && *temp_str<='Z' && *temp_str+'a'-'A'==*temp_sta)
            || (*temp_str>='a' && *temp_str<='z' && *temp_str-('a'-'A')==*temp_sta))) {
            pon++;
            temp_str++;
            temp_sta++;
        }
        else 
        while(*temp_str!='\0' && *temp_sta!='\0' && *temp_str==*temp_sta) {
            pon++;
            temp_str++;
            temp_sta++;
        }
        temp_str=temp_str1;
        if(pon==brojac1 && (temp_str==str || *(temp_str-1)==' ') 
        && (*(temp_str+brojac1)=='\0' || *(temp_str+brojac1)==' ' || *(temp_str+brojac1)=='.')) {
            temp_sa_cim1=temp_sa_cim;
            if(brojac1==brojac2) 
                while(*temp_sa_cim!='\0') {
                    *temp_str1=*temp_sa_cim;
                    temp_str1++;
                    temp_sa_cim++;
                }
            else if(brojac1>brojac2) {
                while(*temp_sa_cim!='\0') {
                    *temp_str1=*temp_sa_cim;
                    temp_str1++;
                    temp_sa_cim++;
                }
                temp=temp_str+brojac1;
                do {
                    *temp_str1=*temp;
                    temp++;
                    temp_str1++;
                } while(*temp!='\0');
            }
            else {
                temp=temp_str;
                while(*temp!='\0') temp++;
                *(temp+brojac2-brojac1)='\0';
                temp+=brojac2-brojac1-1;
                while(temp-(brojac2-brojac1)!=temp_str+brojac1-1) {
                *temp=*(temp-(brojac2-brojac1));
                temp--;
                }
                while(*temp_sa_cim!='\0') {
                *temp_str=*temp_sa_cim;
                temp_str++;
                temp_sa_cim++;
                }
                temp_str=temp_str1-1;
            }
            temp_sa_cim=temp_sa_cim1;
        }
        temp_str++;
    }
    return str;
}
int main() {
    printf("Lekcija 7: Stringovi, Zamijeni riječ");
    return 0;
}


