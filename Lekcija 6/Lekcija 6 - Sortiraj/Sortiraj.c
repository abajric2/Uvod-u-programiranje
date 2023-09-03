#include <stdio.h>

void sortiraj(double niz[], int n) {
  int i, j;
  double pomocna;
  double *pok=niz;
  double *max_pok=niz;
  double *temp;

  for (i=0; i<n; i++) {
    max_pok=pok;
    temp=pok;
    pok++;
    for(j=i+1; j<n; j++) {
      if(*pok>*max_pok) 
        max_pok=pok;
      pok++;
    }
    pomocna=*temp;
    *temp=*max_pok;
    *max_pok=pomocna;
    pok=temp+1;
  }
}
int main() {
  int i, n;
  double niz[1000];
  double *pok=niz;
  do {
    printf("Unesite broj elemenata niza (ne veci od 1000): ");
    scanf("%d", &n);
  } while (n<0 || n>1000);
  printf("Unesite niz: ");
  for (i=0; i<n; i++)
    scanf("%lf", pok++);
  sortiraj(niz, n);
  pok=niz;
  printf("Sortiran niz je: ");
  for (i=0; i<n; i++) {
    printf("%g ", *pok++);
  }
  return 0;
}
