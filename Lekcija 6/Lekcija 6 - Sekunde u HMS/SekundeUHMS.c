#include <stdio.h>

void sekunde2hms (int s, int *H, int *M, int *S) {

    *H=s/3600;
    *M=(s-(3600 * *H))/60;
    *S=(s-(3600 * *H)-(*M * 60));
}

int main() {
    int H, M, S;
    int s;
    printf("Uneiste sekunde: ");
    scanf("%d", &s);
    sekunde2hms(s, &H, &M, &S);
    printf("Sati, minute i sekunde su: %02d:%02d:%02d", H, M, S);
    return 0;
}

