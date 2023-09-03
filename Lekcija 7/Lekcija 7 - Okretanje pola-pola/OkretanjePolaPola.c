#include <stdio.h>

char *okreni(char* rijec) {
    int i, sr, br_slova=0;
    char *p=rijec, temp;
    while(*p != '\0') {
        br_slova++;
        p++;
    }
    if(br_slova%2==0) {
        sr=br_slova/2;
    for(i=0; i<sr/2; i++) {
        temp=*(rijec+sr-1-i);
        *(rijec+sr-1-i)=*(rijec+i);
        *(rijec+i)=temp;
        temp=*(rijec+br_slova-1-i);
        *(rijec+br_slova-1-i)=*(rijec+sr+i);
        *(rijec+sr+i)=temp;
    }
    }
    if(br_slova%2 != 0) {
        sr=br_slova/2;
        for(i=0; i<sr/2;i++) {
            temp=*(rijec+sr-1-i);
            *(rijec+sr-1-i)=*(rijec+i);
            *(rijec+i)=temp;
            temp=*(rijec+br_slova-1-i);
            *(rijec+br_slova-1-i)=*(rijec+sr+1+i);
            *(rijec+sr+1+i)=temp;
        }
    }
    *(rijec+br_slova)='\0';
return rijec;
}
void unesi(char niz[], int velicina) {
    char znak = getchar();
    if (znak == '\n') znak = getchar();
    int i = 0;
    while (i < velicina-1 && znak != '\n') {
    niz[i] = znak;
    i++;
    znak = getchar();
    }
    niz[i] = '\0';
    }

int main() {
    char rijec[100000];
    printf("Uneiste rijec: ");
    unesi(rijec,100000);
    printf("%s", okreni(rijec));
    
    return 0;
}


