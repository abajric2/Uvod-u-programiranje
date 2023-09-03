#include <stdio.h>

char* popuni_lijevo (char* str, int n) {
    char* poc=str;
    char* q;
    int duz_stringa=0, i;
    while(*poc != '\0') {
    duz_stringa++;
    poc++;
    }
    if(duz_stringa>=n) return str;  
    poc=str;
    q=poc+n;
    *q='\0';
    q--;
    for(i=0; i<n; i++) {
        if(duz_stringa>0) {
        *q=*(poc+duz_stringa-1);
        }
        else *q=' ';
        duz_stringa--;
        q--;
    }
    return str;
}
char* popuni_desno (char* str, int n) {
    char* poc=str;
    char* q;
    int duz_stringa=0, i;
    while(*poc != '\0') {
    duz_stringa++;
    poc++;
    }
    if(duz_stringa>=n) return str;  
    poc=str;
    q=poc+duz_stringa;
    for(i=0; i<n-duz_stringa; i++) {
        *q=' ';
        q++;
    }
    *q='\0';
    return str;
}
int main() {
    printf("Lekcija 7: Stringovi, Popuni lijevo i desno");
    return 0;
}


