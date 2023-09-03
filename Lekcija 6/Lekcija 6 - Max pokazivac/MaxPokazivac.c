#include <stdio.h>

int *max_el(int *p1, int *p2) {
    int i=0, vel=0, max=0, max_i=0;   
    int *temp=p1;
    while(temp!=p2) {
        if(*temp>max) {
        max=*temp;
        max_i=i;
        }
        else if(*temp==max) max_i=i;
        i++;
        temp++;
    }
    i=0;
    while(p1!=p2) {
        if(i==max_i) break;
        i++;
        p1++;
    }
    return p1;
}
int *min_el(int *q1, int *q2) {
    int i=0, min=0, min_i=0;   
    int *temp=q1;
    while(temp!=q2) {
        if(*temp<min) {
        min=*temp;
        min_i=i;
        }
        else if (*temp==min) min_i=i;
        i++;
        temp++;
    }
    i=0;
    while(q1!=q2) {
        if(i==min_i) break;
        i++;
        q1++;
    }
    return q1;
}
int main() {
    
    return 0;
}


