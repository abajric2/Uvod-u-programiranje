#include <stdio.h>

int main() {
    int n, cifra, a, b, c, d, e, f, g;
    printf("Unesite broj: ");
    scanf("%d", &n);
    if (n<=-1000000 || n>=1000000) {
    printf("Neispravan unos!");
    return 1;
    }
    printf("Koju cifru zelite kvadrirati: ");
    scanf("%d", &cifra);
    a=n%10;  
    b=n/10; 
    if (b==0) {
        if (cifra==1) {
        printf("Izdvojena cifra je %d, a njen kvadrat je %d", a, a*a);
        return 0; 
        }
        else if(cifra != 1) {
            printf("Neispravna cifra!"); 
            return 0;
        }
    }
    c=b%10; 
    b=b/10;
    if (b==0) {
        if (cifra==1) {
        printf("Izdvojena cifra je %d, a njen kvadrat je %d", c, c*c);
        return 0;
    }
    else if (cifra==2) {
        printf("Izdvojena cifra je %d, a njen kvadrat je %d", a, a*a);
        return 0;
    }
    else if(cifra>2 || cifra <1) {
            printf("Neispravna cifra!"); 
            return 0;
        }
    }
    d=b%10; 
    b=b/10; 
    if(b==0) {
        if (cifra==1) {
        printf("Izdvojena cifra je %d, a njen kvadrat je %d", d, d*d);
        return 0;
    }
    else if (cifra==2) {
        printf("Izdvojena cifra je %d, a njen kvadrat je %d", c, c*c);
        return 0;
    }
    else if (cifra==3) {
        printf("Izdvojena cifra je %d, a njen kvadrat je %d", a, a*a);
        return 0;
    }
    else if(cifra>3 || cifra<1) {
            printf("Neispravna cifra!"); 
            return 0;
        }
    }
    e=b%10; 
    b=b/10; 
    if (b==0) {
        if (cifra==1) {
        printf("Izdvojena cifra je %d, a njen kvadrat je %d", e, e*e);
        return 0;
    }
    else if (cifra==2) {
        printf("Izdvojena cifra je %d, a njen kvadrat je %d", d, d*d);
        return 0;
    }
    else if (cifra==3) {
        printf("Izdvojena cifra je %d, a njen kvadrat je %d", c, c*c);
        return 0;
    }
    else if (cifra==4) {
        printf("Izdvojena cifra je %d, a njen kvadrat je %d", a, a*a);
        return 0;
    }
    else if(cifra>4 || cifra<1) {
            printf("Neispravna cifra!"); 
            return 0;
        }
    }
    f=b%10; 
    b=b/10;
    if (b==0) {
        if (cifra==1) {
        printf("Izdvojena cifra je %d, a njen kvadrat je %d", f, f*f);
        return 0;
    }
    else if (cifra==2) {
        printf("Izdvojena cifra je %d, a njen kvadrat je %d", e, e*e);
        return 0;
    }
    else if (cifra==3) {
        printf("Izdvojena cifra je %d, a njen kvadrat je %d", d, d*d);
        return 0;
    }
    else if (cifra==4) {
        printf("Izdvojena cifra je %d, a njen kvadrat je %d", c, c*c);
        return 0;
    }
    else if (cifra==5) {
        printf("Izdvojena cifra je %d, a njen kvadrat je %d", a, a*a);
        return 0;
    }
    else if(cifra>5 || cifra<1) {
            printf("Neispravna cifra!"); 
            return 0;
        }
    }
    else if (cifra==1) {
        printf("Izdvojena cifra je %d, a njen kvadrat je %d", b, b*b);
        return 0;
    }
    else if (cifra==2) {
        printf("Izdvojena cifra je %d, a njen kvadrat je %d", f, f*f);
        return 0;
    }
    else if (cifra==3) {
        printf("Izdvojena cifra je %d, a njen kvadrat je %d", e, e*e);
        return 0;
    }
    else if (cifra==4) {
        printf("Izdvojena cifra je %d, a njen kvadrat je %d", d, d*d);
        return 0;
    }
    else if (cifra==5) {
        printf("Izdvojena cifra je %d, a njen kvadrat je %d", c, c*c);
        return 0;
    }
    else if (cifra==6) {
        printf("Izdvojena cifra je %d, a njen kvadrat je %d", a, a*a);
        return 0;
    }  
    else if(cifra>6 || cifra <1) {
            printf("Neispravna cifra!"); 
            return 0;
        }
    return 0;
    }
    
    
