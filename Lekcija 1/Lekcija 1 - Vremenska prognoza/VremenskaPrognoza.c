#include <stdio.h>

int main() {
    int tempS, tempM, tempB;
    int kisaS=0, snijegS=0, suncanoS=0;
    int AnjaS=1, ElmaS=1, UnaS=1;
    int kisaM=0, snijegM=0, suncanoM=0;
    int AnjaM=1, ElmaM=1, UnaM=1;
    int kisaB=0, snijegB=0, suncanoB=0;
    int AnjaB=1, ElmaB=1, UnaB=1;
    char padavineS, padavineM, padavineB;
    printf("Unesite prognozu za Sarajevo: \n");
    printf("Temperatura: ");
    scanf("%d", &tempS);
    printf("Padavine (D/N): ");
    scanf(" %c", &padavineS);
    if(padavineS=='d' || padavineS=='D') {
        if(tempS>0) kisaS=1;
        else snijegS=1;
    }
    else if(padavineS=='n' || padavineS=='N') {
        suncanoS=1;
    }
    else {
    printf("Pogresan unos.");
    return 1;
    }
    if(suncanoS==1 || snijegS==1) AnjaS=1;
    else if(kisaS) AnjaS=0;
    if(tempS>=30 || tempS<=-5) ElmaS=0; 
    if(kisaS==1 || snijegS==1 || tempS>=5 && tempS<=20) UnaS=0;
    printf("Unesite prognozu za Mostar: \n");
    printf("Temperatura: ");
    scanf("%d", &tempM);
    printf("Padavine (D/N): ");
    scanf(" %c", &padavineM);
    if(padavineM=='d' || padavineM=='D') {
        if(tempM>0) kisaM=1;
        else snijegM=1;
    }
    else if(padavineM=='n' || padavineM=='N') {
        suncanoM=1;
    }
    else {
    printf("Pogresan unos.");
    return 1;
    }
    if(suncanoM==1 || snijegM==1) AnjaM=1;
    else if(kisaM) AnjaM=0;
    if(tempM>=30 || tempM<=-5) ElmaM=0; 
    if(kisaM==1 || snijegM==1 || tempM>=5 && tempM<=20) UnaM=0;
    printf("Unesite prognozu za Bihac: \n");
    printf("Temperatura: ");
    scanf("%d", &tempB);
    printf("Padavine (D/N): ");
    scanf(" %c", &padavineB);
    if(padavineB=='d' || padavineB=='D') {
        if(tempB>0) kisaB=1;
        else snijegB=1;
    }
    else if(padavineB=='n' || padavineB=='N') {
        suncanoB=1;
    }
    else {
    printf("Pogresan unos.");
    return 1;
    }
    if(suncanoB==1 || snijegB==1) AnjaB=1;
    else if(kisaB) AnjaB=0;
    if(tempB>=30 || tempB<=-5) ElmaB=0; 
    if(kisaB==1 || snijegB==1 || tempB>=5 && tempB<=20) UnaB=0;
    if(AnjaS==1 && ElmaS==1 && UnaS==1) {
    printf("Drugarice idu u Sarajevo.");
    return 0;
    }
    else if(AnjaM==1 && ElmaM==1 && UnaM==1) {
        printf("Drugarice idu u Mostar.");
        return 0;
    }
    else if(AnjaB==1 && ElmaB==1 && UnaB==1) {
        printf("Drugarice idu u Bihac.");
        return 0;
    }
    else if(AnjaS==1 && ElmaS==1 && UnaS==0) {
        printf("Anja i Elma mogu u Sarajevo.");
        return 0;
    }
    else if(AnjaS==1 && UnaS==1 && ElmaS==0) {
        printf("Anja i Una mogu u Sarajevo.");
        return 0;
    }
    else if(AnjaS==0 && ElmaS==1 && UnaS==1) {
        printf("Elma i Una mogu u Sarajevo.");
        return 0;
    }
    else if(AnjaM==1 && ElmaM==1 && UnaM==0) {
        printf("Anja i Elma mogu u Mostar.");
        return 0;
    }
    else if(AnjaM==1 && UnaM==1 && ElmaM==0) {
        printf("Anja i Una mogu u Mostar.");
        return 0;
    }
    else if(AnjaM==0 && ElmaM==1 && UnaM==1) {
        printf("Elma i Una mogu u Mostar.");
        return 0;
    }
    else if(AnjaB==1 && ElmaB==1 && UnaB==0) {
        printf("Anja i Elma mogu u Bihac.");
        return 0;
    }
    else if(AnjaB==1 && UnaB==1 && ElmaB==0) {
        printf("Anja i Una mogu u Bihac.");
        return 0;
    }
    else if(AnjaB==0 && ElmaB==1 && UnaB==1) {
        printf("Elma i Una mogu u Bihac.");
        return 0;
    }
    else printf("Ne odgovara niti jedan grad.");
    return 0;
}


