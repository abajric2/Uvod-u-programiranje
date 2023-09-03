#include <stdio.h>

int main() {
    int n, vel=0, temp1, temp2, zadovoljava=0;
    printf("Unesite brojeve (0 za kraj): \n");
    do  {
        scanf("%d", &n);
        if(n==0) break;
        if (n!=0) vel++;
        if(vel==1) temp1=n;
        if(vel==2) temp2=n;
        if(vel>=3 && n==temp1-temp2) zadovoljava++;
        if(vel>=3) {
            temp1=temp2;
            temp2=n;
        }
    } while (vel<=3 || n != 0);
    if(zadovoljava==0) printf("Niti jedan broj ne zadovoljava uslov.");
    else if(zadovoljava%100>=11 && zadovoljava%100<=19) printf("%d brojeva zadovoljava uslov.", zadovoljava);
    else if(zadovoljava%10==1) printf("%d broj zadovoljava uslov.", zadovoljava);
    else if(zadovoljava%10>=2 && zadovoljava%10<=4) printf("%d broja zadovoljava uslov.", zadovoljava);
    else if(zadovoljava%10>=5 && zadovoljava%10<=9 || zadovoljava%10==0) printf("%d brojeva zadovoljava uslov.", zadovoljava);

    return 0;
}


