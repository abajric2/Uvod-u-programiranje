#include <stdio.h>

char* apsolutna (char* relativna, char* tekuci_dir) {
    char* temp1=relativna;
    char* temp2=tekuci_dir;
    char* temp3=NULL;
    char* temp4=NULL;
    int brojac=0, i, dodaj=0, brojac1=0, brojac2=0;
    if(*temp1>='A' && *temp1<='Z' && *(temp1+1)==':') return relativna;
    if(*temp2=='\0') return relativna;
    if(*temp1=='\0') {
        while(*temp2!='\0') {
            *temp1=*temp2;
            temp1++;
            temp2++;
        }
        *temp1=*temp2;
        return relativna;
    }
    while(*temp2!='\0') temp2++;
    temp4=temp2;
    temp2=tekuci_dir;
    if(*temp1!='.') {
        while(*temp2!='\0') {
            brojac++;
            temp2++;
        }
        if(*(temp2-1)!='\\') dodaj=1;
        while(*temp1!='\0') temp1++;
        temp3=temp1-1;
        temp1+=brojac+dodaj;
        *temp1='\0';
        temp1--;
        while(temp3!=relativna && temp1!=relativna) {
            *temp1=*temp3;
            temp1--;
            temp3--;
        }
        *temp1=*temp3;
        temp1=relativna;
        temp2=tekuci_dir;
        i=0;
        while(i<brojac+dodaj) {
            if(i==brojac) {
                *temp1='\\';
                break;
            }
            *temp1=*temp2;
            temp1++;
            temp2++;
            i++;
        }
    }
    else {
        while(*temp1!='\0' && (*temp1=='.' || *temp1=='\\')) {
            if(*temp1!='\0' && *temp1=='.' && *(temp1+1)=='.') {
                temp2=tekuci_dir;
                while(temp2!=temp4) temp2++;
                temp2--;
                if(temp2!=tekuci_dir && *temp2=='\\') temp2--;
                while(temp2!=tekuci_dir && *temp2!='\\') temp2--;
                if(temp2==tekuci_dir) return relativna;
                temp2++;
                temp4=temp2;
                while(*temp1!='\0' && *temp1!='\\') {
                    if(*temp1=='\0') break;
                    temp1++;
                }
                if(*temp1=='\\') temp1++;
            }
            else if(*temp1!='\0' && *temp1=='.' && *(temp1+1)!='.') {
                temp2=tekuci_dir;
                if(!temp4) {
                while(*temp2!='\0') temp2++;
                temp2--;
                if(*temp2!='\\') {
                    *(temp2+2)='\0';
                    *(temp2+1)='\\';
                    temp4=temp2+1;
                }
                else temp4=temp2+1;
                }
                while(*temp1!='\0' && *temp1!='\\') {
                    if(*temp1=='\0') break;
                    temp1++;
                }
                if(*temp1=='\\') temp1++;
            }
            else if(*temp1!='\0') temp1++;
        }
        temp1=relativna;
        temp2=tekuci_dir;
        while(*temp1=='.' || *temp1=='\\') {
            brojac1++;
            temp1++;
        }
        while(temp2!=temp4) {
            brojac2++;
            temp2++;
        }
        temp1=relativna;
        temp2=tekuci_dir;
        if(brojac2>brojac1) {
            while(*temp1!='\0') temp1++;
            temp3=temp1-1;
            temp1+=brojac2-brojac1;
            *temp1='\0';
            temp1--;
            while(temp3!=relativna) {
                *temp1=*temp3;
                temp1--;
                temp3--;
            }
            *temp1=*temp3;
            temp3=relativna;
            while(temp2!=temp4) {
                *temp3=*temp2;
                temp2++;
                temp3++;
            }
        }
        else if(brojac1>brojac2) {
            temp1=relativna+brojac2;
            temp2=relativna;
            while(*temp2=='.' || *temp2=='\\') temp2++;
            while(*temp2!='\0') {
                *temp1=*temp2;
                temp1++;
                temp2++;
            }
            *temp1=*temp2;
            temp1=relativna;
            temp2=tekuci_dir;
            while(temp2!=temp4) {
                *temp1=*temp2;
                temp1++;
                temp2++;
            }
        }
        else if(brojac1==brojac2) {
            while(temp2!=temp4) {
                *temp1=*temp2;
                temp1++;
                temp2++;
            }
        }
    }
    return relativna;
}

int main() {
    
    return 0;
}


