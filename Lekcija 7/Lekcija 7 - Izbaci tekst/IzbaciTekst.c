#include <stdio.h>

char* izbaci_tekst(char* str, const char* tekst, int cs) {
    char* p=str;
    const char* q=tekst;
    char* poc;
    char* s=str;
    char pom1, pom2;
    if(*q=='\0') return str;
    while(*str!='\0') {
            p=str;
            poc=str;
            q=tekst;
            if (cs) {
            while(*p==*q) {
                p++;
                q++;
                if(*p=='\0' || *q=='\0') break;
            }
            if(*q=='\0') {
                while(*poc++=*p++);
                str=s;
                continue;
            }
            str++;
            }
            else {
            if(*p>='a' && *p<='z') pom1=*p-('a'-'A');
            else pom1=*p;
            if(*q>='a' && *q<='z') pom2=*q-('a'-'A');
            else pom2=*q;
            while(pom1==pom2) {
                p++;
                q++;
                if(*p>='a' && *p<='z') pom1=*p-('a'-'A');
                else pom1=*p;
                if(*q>='a' && *q<='z') pom2=*q-('a'-'A');
                else pom2=*q;
                if(*p=='\0' || *q=='\0') break;
            }
        if(*q=='\0') {
            while(*poc++=*p++);
            str=s;
            continue;
        }
        str++;
    }       
    }
    return s;
}
int main() {
    printf("Lekcija 7: Stringovi, Izbaci tekst");
    return 0;
}


