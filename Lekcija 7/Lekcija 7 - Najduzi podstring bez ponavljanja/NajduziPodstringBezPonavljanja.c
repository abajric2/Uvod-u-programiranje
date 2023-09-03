#include <stdio.h>

void najduzi_bp(char* s1, char* s2) {
    char* temp1=s1;
    char* temp2;
    int brojac=1, max=0, i, j;
    char* pom1;
    char* pom2;
    char* maxp=NULL;
    while(*temp1!='\0') {
        while(*temp1!='\0' && !(*temp1>='A' && *temp1<='Z' || *temp1>='a' && *temp1<='z'))
        temp1++;
        if(*temp1=='\0') break;
        temp2=temp1+1;
        brojac=1;
        while(*temp2!='\0' && (*temp2>='A' && *temp2<='Z' || *temp2>='a' && *temp2<='z')) {
            if(*temp2==*temp1 || (*temp1>='A' && *temp1<='Z' && *temp1+'a'-'A'==*temp2) 
            || (*temp1>='a' && *temp1<='z' && *temp1-('a'-'A')==*temp2))
            break;
            brojac++;
            temp2++;
        }
        if(brojac>max) {
            pom1=temp1;
            for(i=0; i<brojac-1; i++) {
                pom2=pom1+1;
                for(j=i+1; j<brojac; j++) {
                    if(*pom2==*pom1 || 
                    (*pom2>='A' && *pom2<='Z' && *pom2+'a'-'A'==*pom1)
                    || (*pom2>='a' && *pom2<='z' && *pom2-('a'-'A')==*pom1)) 
                    break;
                    pom2++;
                }
                if(j<brojac) {
                if(j>max) {
                max=j;
                maxp=temp1;
                }
                break;
                }
                pom1++;
            }
            if(i==brojac-1) {
            max=brojac;
            maxp=temp1;
            }
        }
        temp1++;
    }
    for(i=0; i<max; i++) {
        *s2=*maxp;
        s2++;
        maxp++;
    }
    *s2='\0';
}

int main() {
    printf("Lekcija 7: Stringovi, Najduži podstring bez ponavljanja");
    return 0;
}


