#include <stdio.h>
#include <math.h>

struct Tacka {
    int x,y;
};
struct Trougao {
    struct Tacka A,B,C;
};
int rastojanje (struct Tacka t1, struct Tacka t2) {
    return pow(t2.x-t1.x,2)+pow(t2.y-t1.y,2);
}
int izbaci_pravougle(struct Trougao* t, int vel) {
    int i, j;
    for(i=0; i<vel; i++) {
        if((rastojanje(t[i].A,t[i].B)==rastojanje(t[i].A,t[i].C)+rastojanje(t[i].B,t[i].C))
        || (rastojanje(t[i].A,t[i].C)==rastojanje(t[i].A,t[i].B)+rastojanje(t[i].B,t[i].C))
        || (rastojanje(t[i].B,t[i].C)==rastojanje(t[i].A,t[i].B)+rastojanje(t[i].A,t[i].C))) {
            for(j=i; j<vel-1; j++) {
                t[j]=t[j+1];
            }
            vel--;
            i--;
        }
    }
    return vel;
}
int main() {
    struct Trougao trouglovi[100000];
    int n, i;
    printf("Unesite broj trouglova: ");
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        printf("Unesite koordinate tacke A %d. trougla: ", i+1);
        scanf("%d%d", &trouglovi[i].A.x, &trouglovi[i].A.y);
        printf("Unesite koordinate tacke B %d. trougla: ", i+1);
        scanf("%d%d", &trouglovi[i].B.x, &trouglovi[i].B.y);
        printf("Unesite koordinate tacke C %d. trougla: ", i+1);
        scanf("%d%d", &trouglovi[i].C.x, &trouglovi[i].C.y);
    }
    n=izbaci_pravougle(trouglovi, n);
    printf("Nakon izbacivanja pravouglih trouglova: \n");
    for(i=0; i<n; i++) {
        printf("Trougao %d: (%d,%d)-(%d,%d)-(%d,%d)\n", i, 
        trouglovi[i].A.x, trouglovi[i].A.y, trouglovi[i].B.x,
        trouglovi[i].B.y, trouglovi[i].C.x, trouglovi[i].C.y);
    }
    return 0;
}


