#include <stdio.h>

struct Tacka {
    double x,y;
};

struct Pravougaonik {
    struct Tacka dolje_lijevo;
    struct Tacka gore_desno;
};

struct Pravougaonik min_pravougaonik (struct Tacka* t, int vel) {
    struct Pravougaonik p;
    double min_x, max_x, min_y, max_y;
    int i;
    min_x=t[0].x;
    max_x=t[0].x;
    min_y=t[0].y;
    max_y=t[0].y;
    for(i=1; i<vel; i++) {
        if(t[i].x<min_x) min_x=t[i].x;
        if(t[i].x>max_x) max_x=t[i].x;
        if(t[i].y<min_y) min_y=t[i].y;
        if(t[i].y>max_y) max_y=t[i].y;
    }
    p.dolje_lijevo.x=min_x;
    p.dolje_lijevo.y=min_y;
    p.gore_desno.x=max_x;
    p.gore_desno.y=max_y;
    return p;
}

int main() {
    int n, i;
    struct Tacka t[10000];
    struct Pravougaonik p;
    printf("Unesite broj tacaka: ");
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        printf("Unesite koordinate x i y tacke %d: ", i+1);
        scanf("%lf%lf", &t[i].x, &t[i].y);
    }
    p=min_pravougaonik(t, n);
    printf("Minimalni pravougaonik za ove tacke ima uglove: \n(%g,%g) - (%g,%g)", p.dolje_lijevo.x, p.dolje_lijevo.y, p.gore_desno.x, p.gore_desno.y);
    return 0;
}


