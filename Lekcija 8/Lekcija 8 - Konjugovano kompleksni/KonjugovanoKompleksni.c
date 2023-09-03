#include <stdio.h>

typedef struct {
    int im, re;
} Kompleksni;

int konjugovano_kompleksni (Kompleksni *p1, Kompleksni *p2,   Kompleksni *rez) {
    int br_el=0, i, j, k;
    Kompleksni* temp=p1;
    Kompleksni* temp2=rez;
    Kompleksni* temp3;
    Kompleksni* temp4;
    Kompleksni* temp5;
    while(temp<p2) {
        br_el++;
        temp++;
    }
    temp=p1;
    for(i=0; i<br_el; i++) {
        temp2->im=-temp->im;
        temp2->re=temp->re;
        temp2++;
        temp++;
    }
    temp2=rez;
    for(i=0; i<br_el; i++) {
        for(j=i+1; j<br_el; j++) {
            if(j==i+1) temp3=temp2+1;
            if(temp2->re==temp3->re && temp2->im==temp3->im) {
                for(k=j; k<br_el-1; k++) {
                    if(k==j) temp4=temp3;
                    if(k==j) temp5=temp4+1;
                    temp4->re=temp5->re;
                    temp4->im=temp5->im;
                    temp4++;
                    temp5++;
                }
                br_el--;
                j--;
            }
            temp3++;
        }
        temp2++;
    }
    return br_el;
}

int main() {
    Kompleksni kompleksni[10000];
    Kompleksni* pok=kompleksni;
    Kompleksni rezultat[10000];
    int i, n;
    printf("Unesite broj elemenata niza: ");
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        printf("Unesite imaginarni dio %d. broja: ", i+1);
        scanf("%d", &pok->im);
        printf("Unesite realni dio %d. broja: ", i+1);
        scanf("%d", &pok->re);
        pok++;
    }
    pok=kompleksni;
    n=konjugovano_kompleksni(pok, pok+n, rezultat);
    pok=rezultat;
    for(i=0; i<n; i++) {
        printf("(%d,%d) ", pok->im, pok->re);
        pok++;
    }
    return 0;
}



