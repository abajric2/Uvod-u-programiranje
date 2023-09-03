#include <stdio.h>

typedef struct {
    double x, y, z;
} Vektor3d;

Vektor3d vektorski_proizvod (Vektor3d v1, Vektor3d v2) {
    Vektor3d v3;
    v3.x=v1.y*v2.z-v1.z*v2.y;
    v3.y=v1.z*v2.x-v1.x*v2.z;
    v3.z=v1.x*v2.y-v1.y*v2.x;
    return v3;
}

int main() {
    Vektor3d v1;
    Vektor3d v2;
    Vektor3d v3;
    printf("Unesite vektor v1: ");
    scanf("%lf%lf%lf", &v1.x, &v1.y, &v1.z);
    printf("Unesite vektor v2: ");
    scanf("%lf%lf%lf", &v2.x, &v2.y, &v2.z);
    v3=vektorski_proizvod(v1, v2);
    printf("Vektorski proizvod vektora v1 i v2 je: %g %g %g", v3.x, v3.y, v3.z);
   
    return 0;
}


