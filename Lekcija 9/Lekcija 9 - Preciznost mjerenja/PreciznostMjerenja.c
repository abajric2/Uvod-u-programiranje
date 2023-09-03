#include <stdio.h>
#include <math.h>
#define EPSILON 0.00001

int main() {
    int i=0, vel1;
    double mjerenja[10000]; 
    double zadane[10000];
    FILE* prva=fopen("mjerenja.txt", "r");
    if(prva==NULL) {
        printf("Nije uspjelo otvaranje datoteke mjerenja.txt\n");
        return 1;
    }
    while(i<10000 && fscanf(prva, "%lf,", &mjerenja[i])==1) i++;
    fclose(prva);
    vel1=i;
    FILE* druga=fopen("zadane.dat", "rb");
    if(druga==NULL) {
        printf("Nije uspjelo otvaranje datoteke zadane.dat\n");
        return 2;
    }
    int vel2=fread(zadane, sizeof(double), 10000, druga);
    fclose(druga);    
    FILE* izlazna=fopen("provjera.txt", "w");
    if(izlazna==NULL) {
        printf("Nije uspjelo otvaranje datoteke provjera.txt\n");
        return 3;
    }
    i=0;
    int sati=9, minute=0, sekunde=0, tacno=0, brojac_min=0, sekunde_tacno=0;
    double razlika;
    while(i<vel1) {
        if(mjerenja[i]+zadane[i]==0) razlika=0;
        else razlika=(fabs(mjerenja[i]-zadane[i])/((zadane[i]+mjerenja[i])/2.0))*100;
        if(5-razlika>EPSILON || fabs(razlika-5)<EPSILON || (brojac_min==10 && sekunde==sekunde_tacno)) {
            fprintf(izlazna, "%d:%02d:%02d %.2f\n", sati, minute, sekunde, mjerenja[i]);
            if(brojac_min==10) brojac_min=0;
            else tacno=1;
        }
        else tacno=0;
        if(sekunde<60) {
        if(tacno) sekunde_tacno=sekunde;
        sekunde+=15;
        }
        if(sekunde==60) {
            sekunde=0;
            if(minute==60) {
                minute=0;
                sati+=1;
            }
            else {
            minute+=1;
            }
            if(tacno) brojac_min=0;
            else brojac_min++;
        }
        if(minute==60) {
            if(tacno) brojac_min=0;
            else brojac_min++;
            sati+=1;
            minute=0;
            sekunde=0;
        }
        i++;
    }
    fclose(izlazna);
    return 0;
}



