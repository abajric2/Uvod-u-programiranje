#include <stdio.h>

// Korisna stranica da provjerite komplanarnost tacaka
// http://www.ambrsoft.com/TrigoCalc/Plan3D/PointsCoplanar.htm

struct Tacka3d { double x, y, z; };

int komplanarne_tacke (struct Tacka3d t1, struct Tacka3d t2, struct Tacka3d t3, struct Tacka3d t4) {
    double a_x, a_y, a_z, b_x, b_y, b_z, c_x, c_y, c_z;
    if(t1.x==t2.x && t2.x==t3.x && t3.x==t4.x && t1.y==t2.y && t2.y==t3.y && t3.y==t4.y
    && t1.z==t2.z && t2.z==t3.z && t3.z==t4.z) return 0;
    a_x=t2.x-t1.x;
    a_y=t2.y-t1.y;
    a_z=t2.z-t1.z;
    b_x=t3.x-t1.x;
    b_y=t3.y-t1.y;
    b_z=t3.z-t1.z;
    c_x=t4.x-t1.x;
    c_y=t4.y-t1.y;
    c_z=t4.z-t1.z;
    if((a_x*(b_y*c_z-b_z*c_y)-a_y*(b_x*c_z-c_x*b_z)+a_z*(b_x*c_y-c_x*b_y))==0) return 1;
    else return -1;
}

int main() {
    printf("Lekcija 8: Strukture, Komplanarne tačke");
    return 0;
}


