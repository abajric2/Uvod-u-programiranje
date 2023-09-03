#include <stdio.h>

char* izbaci_anagrame (char* s1, char* s2) {
    char* temp1=s1;
    char* temp2=s2;
    char* pom2;
    char* pom1;
    char* pom;
    char* temp;
    int brojac2=0, brojac1=0, brojaci2[1000]={0}, brojaci1[1000]={0}, i;
    while(*temp2!='\0') {
        while(!(*temp2>='A' && *temp2<='Z' || *temp2>='a' && *temp2<='z'))
        temp2++;
        if(*temp2=='\0') break;
        pom2=temp2;
        brojac2=0;
        while(*pom2>='A' && *pom2<='Z' || *pom2>='a' && *pom2<='z') {
        brojac2++;
        pom2++;
        }
        pom2=temp2;
        for(i='A'; i<='Z'; i++) {
            brojaci2[i]=0;
            brojaci2[i+'a'-'A']=0;
        }
        for(i=0; i<brojac2; i++) {
            if(*pom2>='A' && *pom2<='Z') brojaci2[*pom2]++;
            else if(*pom2>='a' && *pom2<='z') brojaci2[*pom2-('a'-'A')]++;
            pom2++;
        }
        while(*temp1!='\0') {
            while(!(*temp1>='A' && *temp1<='Z' || *temp1>='a' && *temp1<='z'))
            temp1++;
            if(*temp1=='\0') break;
            pom1=temp1;
            brojac1=0;
            while(*pom1>='A' && *pom1<='Z' || *pom1>='a' && *pom1<='z') {
            brojac1++;
            pom1++;
            }
            i=0;
            if(brojac1==brojac2) {
                pom1=temp1;
                for(i='A'; i<='Z'; i++) {
                    brojaci1[i]=0;
                    brojaci1[i+'a'-'A']=0;
        }
                for(i=0; i<brojac1; i++) {
                    if(*pom1>='A' && *pom1<='Z') brojaci1[*pom1]++;
                    else if(*pom1>='a' && *pom1<='z') brojaci1[*pom1-('a'-'A')]++;
                    pom1++;
            }
            for(i='A'; i<='Z'; i++) {
                if(brojaci1[i]!=brojaci2[i]) break;
            }
            if(i=='Z'+1) {
                temp=temp1+brojac1;
                pom=temp1;
                while(*temp!='\0') {
                    *temp1=*temp;
                    temp++;
                    temp1++;
                }
                *temp1='\0';
                temp1=pom;
            }
        }
        if(i!='Z'+1) temp1+=brojac1;
    }
    temp2+=brojac2;
    temp1=s1;
    }
return s1;
}

int main() {
    printf("Lekcija 7: Stringovi, Izbaci anagrame");
    return 0;
}


