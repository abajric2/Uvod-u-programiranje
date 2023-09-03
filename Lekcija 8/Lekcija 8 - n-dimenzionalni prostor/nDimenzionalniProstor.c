#include <stdio.h>
#include <math.h>

struct Tacka {
    double koordinata[100];
};

int izbaci_najblize(struct Tacka* t, int vel, int n) {
    int i, j, k, min_i=0, min_j=0;
    double d=0, min=0;
    if(vel==0 || vel==1) return vel; 
    /*Ako je niz prazan ili sadrzi samo jednu tacku ne mozemo racunati udaljenost*/   
    for(i=0; i<vel; i++) {           
        for(j=i+1; j<vel; j++) {
            d=0;
            for(k=0; k<n; k++) {
                d+=pow(t[j].koordinata[k]-t[i].koordinata[k],2);
            }
            d=sqrt(d);
            if(i==0 && j==1) {
            min=d;
            min_i=i;
            min_j=j;
            }
            if(d<min) {
                min=d;
                min_i=i;
                min_j=j;
            }
        }
    }
    for(i=0; i<vel; i++) {
        if(i==min_i || i==min_j) {
            if(i==min_i) {
            min_i=-1;
            min_j--;
            }
            else if(i==min_j) min_j=-1;
            for(j=i; j<vel-1; j++) {
                t[j]=t[j+1];
            } 
            vel--;
            i--;
        }
    }
    return vel;
}

int main() {
    printf("Lekcija 8: Strukture, n-dimenzionalni prostor");
    return 0;
}


