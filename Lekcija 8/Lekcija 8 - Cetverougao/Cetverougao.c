#include <stdio.h>
#include <math.h>

struct Tacka {
    int x,y;
};
struct Cetverougao {
    struct Tacka A,B,C,D;
};
struct Tacka unos_tacke() {
    struct Tacka t;
    printf("Unesite koordinate tacke (x,y): ");
    scanf("%d,%d", &t.x, &t.y);
    return t;
}
struct Cetverougao unos_cetverougla() {
    struct Cetverougao c;
    printf("Unesite koordinate vrha cetverougla(x,y): ");
    scanf("%d,%d", &c.A.x, &c.A.y);
    printf("Unesite koordinate vrha cetverougla(x,y): ");
    scanf("%d,%d", &c.B.x, &c.B.y);
    printf("Unesite koordinate vrha cetverougla(x,y): ");
    scanf("%d,%d", &c.C.x, &c.C.y);
    printf("Unesite koordinate vrha cetverougla(x,y): ");
    scanf("%d,%d", &c.D.x, &c.D.y);
    return c;
}
double udaljenost(struct Tacka t1, struct Tacka t2) {
    return sqrt((double)(pow(t2.x-t1.x,2)+pow(t2.y-t1.y,2)));
}
int pravougaonik(struct Cetverougao c) {
    if(udaljenost(c.A,c.B)==udaljenost(c.C,c.D) && udaljenost(c.A,c.D)==udaljenost(c.B,c.C) 
    || udaljenost(c.A,c.C)==udaljenost(c.B,c.D) && udaljenost(c.B,c.C)==udaljenost(c.A,c.D)) return 1;
    else return 0;
}
int kvadrat(struct Cetverougao c) {
    if(udaljenost(c.A,c.B)==udaljenost(c.C,c.D) && udaljenost(c.A,c.D)==udaljenost(c.B,c.C) 
    && udaljenost(c.A,c.B)==udaljenost(c.A,c.C) || udaljenost(c.A,c.C)==udaljenost(c.B,c.D) 
    && udaljenost(c.B,c.C)==udaljenost(c.A,c.D) && udaljenost(c.A,c.C)==udaljenost(c.A,c.B)
    || udaljenost(c.A,c.C)==udaljenost(c.B,c.D) && udaljenost(c.B,c.C)==udaljenost(c.A,c.D) 
    && udaljenost(c.A,c.D)==udaljenost(c.A,c.B)) return 1;
    else return 0;
}
int tacka_u_cetverouglu (struct Tacka t, struct Cetverougao c) {
    struct Tacka dolje_lijevo;
    struct Tacka gore_desno;
    dolje_lijevo.x=c.A.x;
    dolje_lijevo.y=c.A.y;
    gore_desno.x=c.A.x;
    gore_desno.y=c.A.y;
    if(c.B.x<c.A.x) dolje_lijevo.x=c.B.x;
    if(c.C.x<c.A.x) dolje_lijevo.x=c.C.x;
    if(c.D.x<c.A.x) dolje_lijevo.x=c.D.x;
    if(c.B.y<c.A.y) dolje_lijevo.y=c.B.y;
    if(c.C.y<c.A.y) dolje_lijevo.y=c.C.y;
    if(c.D.y<c.A.y) dolje_lijevo.y=c.D.y;
    if(c.B.x>c.A.x) gore_desno.x=c.B.x;
    if(c.C.x>c.A.x) gore_desno.x=c.C.x;
    if(c.D.x>c.A.x) gore_desno.x=c.D.x;
    if(c.B.y>c.A.y) gore_desno.y=c.B.y;
    if(c.C.y>c.A.y) gore_desno.y=c.C.y;
    if(c.D.y>c.A.y) gore_desno.y=c.D.y;
    if(t.x>dolje_lijevo.x && t.y>dolje_lijevo.y && t.x<gore_desno.x && t.y<gore_desno.y) return 1;
    else return 0;
}
int filtriraj_tacke (struct Tacka* t, int vel, struct Cetverougao c) {
    int i, j;
    for(i=0; i<vel; i++) {
        if(tacka_u_cetverouglu(t[i], c)==0) {
            for(j=i; j<vel-1; j++) {
            t[j]=t[j+1];
            }
        vel--;
        i--;
        }
    }
    return vel;
}
int udaljenost_od_koordinatnog_pocetka (struct Tacka t) {
    return sqrt(pow(t.x,2)+pow(t.y,2));    
}
void sortiraj_tacke(struct Tacka* tacke, int vel) {
    int i, min_d, j;
    struct Tacka temp;
    for(i=0; i<vel; i++) {
        min_d=i;
        for(j=i+1; j<vel; j++) {
            if(udaljenost_od_koordinatnog_pocetka(tacke[j])<udaljenost_od_koordinatnog_pocetka(tacke[min_d]))
            min_d=j;
        }
        temp=tacke[i];
        tacke[i]=tacke[min_d];
        tacke[min_d]=temp;
    }
}

int main() {
    struct Tacka tacke[100];
    struct Cetverougao c;  
    struct Tacka* p=tacke;
    int n, i;
    printf("Unesite broj tacaka: ");
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        printf("Unesite %d. tacku: \n", i+1);
        tacke[i]=unos_tacke();
    }
    printf("Unesite cetverougao: \n");
    c=unos_cetverougla();
    if(pravougaonik(c)) printf("Ovo je pravougaonik.\n");
    else printf("Ovo nije pravougaonik.\n");
    if(kvadrat(c)) printf("Ovo je kvadrat.\n");
    else printf("Ovo nije kvadrat.\n");
    n=filtriraj_tacke(p,n,c);
    p=tacke;
    sortiraj_tacke(p, n);
    for(i=0; i<n; i++) {
        printf("(%d,%d)", tacke[i].x, tacke[i].y);
        if(i<n-1) printf(",");
    }
    return 0;
}


