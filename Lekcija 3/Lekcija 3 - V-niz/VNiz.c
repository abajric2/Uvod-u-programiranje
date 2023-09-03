#include <stdio.h>

int main() {
    int i=0, niz[100], br_el=0, min_index, min, temp1, temp2;
    for(i=0; i<100; i++) {
        scanf("%d", &niz[i]);
        if(br_el==100) break;
        if(niz[i]==-1) break;
        br_el++;
    }
    if(br_el<3) {
        printf("Nedovoljno elemenata");
        return 0;
    }
    min_index=0;
    min=niz[0];
    for(i=1; i<br_el; i++) {
        if(niz[i]<min) {
        min=niz[i];
        min_index=i;
        }
    }
    if(min_index==0 || min_index==(br_el-1)) {
        printf("Niz nije v-niz.");
        return 0;
    }
    temp1=1;
    for(i=0; i<min_index; i++) {
        if((i+1)>=min_index) break;
        else if(niz[i+1]>=niz[i]) temp1=0;
    }
    temp2=1;
    for(i=(min_index+1); i<br_el; i++) {
        if((i+1)>=br_el) break;
        else if(niz[i+1]<=niz[i]) temp2=0;
    }    
    if(temp1==1 && temp2==1) 
    printf("Niz je v-niz");
    else 
    printf("Niz nije v-niz");

    return 0;
}


