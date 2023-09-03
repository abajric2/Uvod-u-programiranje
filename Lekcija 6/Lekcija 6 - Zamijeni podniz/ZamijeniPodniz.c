#include <stdio.h>

int* podniz(int *p1, int* p2, const int* q1, const int* q2) {
    int* temp1=p1;
    const int* temp2=q1;
    int* pomocni;
    int brojac=0, br_el2=0, temp=0, podniz=0;
    while(temp2!=q2) {
        br_el2++;
        temp2++;
    }
    temp2=q1;
    do {
        if(*temp1==*temp2) {
            if(temp2==q1) pomocni=temp1;
            brojac++;
            temp2++;
            temp1++;
            temp=1;
        }
        if(temp1==p2 && brojac==br_el2) {
        podniz=1;
        break;
        }
        else if(temp1==p2) break;
        if(temp2==q2 && brojac==br_el2) {
        podniz=1;
        break;
    }
    else if(temp2==q2){
    temp2=q1;
    brojac=0;
    }
        if(*temp1!=*temp2 && temp==1) {
        brojac=0;
        temp2=q1;
        temp=0;
    }
    else if(temp==0){
    temp1++;
    temp=0;
    }
    
} while(temp1!=p2);
if(!podniz) pomocni=NULL;
return pomocni;
}

int zamijeni_podniz(int *p1, int *p2,  const int *q1, const int *q2, const int *r1, const int *r2) {
    int* pok1=p1;
    const int* pok2=q1;
    const int* pok3=r1;
    int br_el1=0, br_el2=0, br_el3=0, n, vel;
    do {
        br_el1++;
        pok1++;
    } while(pok1!=p2);
    pok1=p1;
    do {
        br_el2++;
        pok2++;
    } while(pok2!=q2);
    pok2=q1;
    do {
        br_el3++;
        pok3++;
    } while(pok3!=r2);
    pok3=r1;
    const int* pomocni;
    if(podniz(p1,p2,q1,q2)==NULL) return 0;
    if(br_el2==br_el3) {
        while(podniz(p1,p2,q1,q2)) {
        pok1=podniz(p1,p2,q1,q2);
        while(pok3!=r2) {
        *pok1=*pok3;
        pok1++;
        pok3++;
        }
        pok1=p1;
        pok3=r1;
        }
        return 0;
    }
    int x=0;
    pok1=p1;
    pok3=r1;
    int* pom;
    if(br_el2>br_el3) {
        while(podniz(p1,p2,q1,q2)) {
            x++;
            pok1=podniz(p1,p2,q1,q2);
            while(pok3!=r2) {
                *pok1=*pok3;
                pok1++;
                pok3++;
            }
            pom=pok1+br_el2-br_el3;
            while(pom!=p2) {
                *pok1=*pom;
                pok1++;
                pom++;
            }
            pok3=r1;
        }
        return x*(br_el3-br_el2);
    }
    pok3=r1;
    int* a;
    int* b;
    x=0;
    if(br_el2<br_el3) {
        while(podniz(p1,p2,q1,q2)) {
            x++;
            pok1=podniz(p1,p2,q1,q2);
            a=p2+br_el3-br_el2-1;
            b=p2-1;
            p2=a+1;
            while(b!=pok1+br_el2-1) {
                *a=*b;
                a--;
                b--;
            }
            while(pok3!=r2) {
                *pok1=*pok3;
                pok1++;
                pok3++;
            }
            pok3=r1;
        }
        return x*(br_el3-br_el2);
    }
    return 0;
}

int main() {
    
    return 0;
}


