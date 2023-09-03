#include <stdio.h>

char* prebroji (const char* tekst, char* slova) {
    const char* p=tekst;
    char* q=slova;
    int brojaci[91]={0}, max=0, i;
    while(*p!='\0') {
        if(*p>='a' && *p<='z') brojaci[*p-('a'-'A')]++;
        else if(*p>='A' && *p<='Z') brojaci[*p]++;
        p++;
    }
    for(i='A'; i<='Z'; i++) {
        if(brojaci[i]>max) {
            max=brojaci[i];      
        }
    }
    for(i='A'; i<='Z'; i++) {
        if(max==0) break;
        if(i=='Z' && brojaci['Z']==max) {
            *q='Z';
            q++;
            max--;
            i='A';
            i--;
        }
        else if(i=='Z' && brojaci['Z']!=max) {
        max--;
        i='A';
        i--;
        }
        else if (brojaci[i]==max) {
        *q=i;
        q++;
        }
    }
    *q='\0';
    return slova;
}

int main() {
    
    return 0;
}


