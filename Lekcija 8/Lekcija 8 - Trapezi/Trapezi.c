#include <stdio.h>
#include <math.h>

struct Tacka {
    double x,y;
};
struct Trapez {
    struct Tacka A,B,C,D;
};
double duzina_stranice(struct Tacka t1, struct Tacka t2) {
    return sqrt(pow(t2.x-t1.x,2)+pow(t2.y-t1.y,2));
}
double obim(struct Trapez t) {
    return duzina_stranice(t.A,t.B)+duzina_stranice(t.B,t.C)
    +duzina_stranice(t.C,t.D)+duzina_stranice(t.A,t.D);
}
double povrsina(struct Trapez t) {
    double m, h, p;
    m=(duzina_stranice(t.A,t.B)+duzina_stranice(t.C,t.D))/2;
    if(duzina_stranice(t.A,t.B)==duzina_stranice(t.C,t.D)) /*ako su a i c jednake, to je kvadrat ili pravougaonik*/
    return duzina_stranice(t.A,t.B)*duzina_stranice(t.A,t.D);
    h=sqrt(pow(duzina_stranice(t.B,t.C),2)
    -(pow(((pow(duzina_stranice(t.A,t.B),2)+pow(duzina_stranice(t.B,t.C),2)+
    pow(duzina_stranice(t.C,t.D),2)-2*duzina_stranice(t.A,t.B)*duzina_stranice(t.C,t.D)
    -pow(duzina_stranice(t.A,t.D),2))/(2*duzina_stranice(t.A,t.B)-2*duzina_stranice(t.C,t.D))),2)));
    p=m*h;
    return p;
}
void trapezi(struct Trapez* t, int n, double *obimi, double *povrsine) {
    int i;
    for(i=0; i<n; i++) {
        obimi[i]=obim(t[i]);
    }
    for(i=0; i<n; i++) {
        povrsine[i]=povrsina(t[i]);
    }
}

int main() {
    printf("Lekcija 8: Strukture, Trapezi");
    return 0;
}


