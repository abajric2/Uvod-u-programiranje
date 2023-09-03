#include <stdio.h>

struct Grad {
    char naziv[20];
    int pozivni_broj;
};

void preslozi_pozivni (struct Grad* gradovi, int vel, int pozivni) {
    int i, j, k;
    struct Grad temp;
    for(i=0; i<vel; i++) {  
        if(gradovi[i].pozivni_broj!=pozivni) {
            for(j=i+1; j<vel; j++) {
                if(gradovi[j].pozivni_broj==pozivni) {
                    temp=gradovi[j];
                    for(k=j; k>i; k--) {
                        gradovi[k]=gradovi[k-1];
                    }
                    gradovi[i]=temp;                     
                    break;               
                }
            }
        }
    }
}

int main() {
    
    return 0;
}

