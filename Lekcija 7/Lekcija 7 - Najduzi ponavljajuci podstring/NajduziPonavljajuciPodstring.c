#include <stdio.h>

char* najduzi_pp (char* s1, char* s2) {
    char* temp1=s1;
    char* temp2;
    char* pom1;
    char* pom2;
    char* pom3;
    char* maxp=NULL;
    int max=0, br_pon=0, i;
    while(*temp1!='\0') {
        temp2=temp1;
        while(*temp2!='\0' && (*temp1!=*temp2 || temp1==temp2)) temp2++;
        while(*temp2!='\0') {
            while(*temp2!='\0' && *temp1!=*temp2) temp2++;
            if(*temp2=='\0') break;
            pom2=temp2;
            pom1=temp1;
            i=0;
            br_pon=0;
            while(*pom2!='\0' && i<temp2-temp1 && *pom1==*pom2) {
                br_pon++;
                pom2++;
                pom1++;
                i++;
            }
            temp2++;
            if(br_pon>0 && br_pon==max) {
                i=0;
                pom1=temp1;
                pom2=maxp;
                while(*pom1!='\0' && *pom2!='\0' && i<max) {
                    if(*pom2>*pom1) break;
                    else if(*pom2<*pom1) {
                        maxp=temp1;
                        break;
                    }
                    pom1++;
                    pom2++;
                    i++;
                }
            }
            else if(br_pon>max) {
                max=br_pon;
                maxp=temp1;
            }          
        }
        temp1++;
    }
    if(max==0) {
        *s2='\0';
        return s2;
    }
    pom3=s2;
    for(i=0; i<max; i++) {
        *pom3=*maxp;
        pom3++;
        maxp++;
    }
    *pom3='\0';
    return s2;
}

int main() {
    printf("Lekcija 7: Stringovi, Najduži ponavljajući podstring");
    return 0;
}


