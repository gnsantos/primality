#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "rabinFunctions.h"

static void getParameters(int* t, unsigned long* c, unsigned long n);
static unsigned long modExp(unsigned long m, unsigned long e, unsigned long n);

Boolean millerRabinTest(unsigned long n, int s){
  int i,j, t=0, aux;
  unsigned long c = 0, a = 0, r0, r1;

  if((n % 2 == 0 && n != 2) || n == 1 )
    return FALSE;
  if(n == 2) return TRUE;
  
  getParameters(&t, &c, n);  
  
  srand(time(NULL));
  for(i = 0; i < s; i++){
    a = rand()%(n-4) + 2;
    r0 = modExp(a, c, n);   
    r1 = (r0 * r0)%n;
    for(j= 0; j < t; j++){
      if(r1 == 1 && r0 != 1 && r0 != n-1)
	return FALSE;
      aux = r1;
      r1 = (r1*r1)%n;
      r0 = aux;
    }
    if(r1 != 1) return FALSE;
  }
  return TRUE;
}

static void getParameters(int* t, unsigned long* c, unsigned long n){
  int x = n-1, aux = 0;
  while(x%2 == 0){
    x/=2;
    aux++;
  }
  *t = aux;
  *c = (n-1)/(pow(2,aux));
}

static unsigned long modExp(unsigned long m, unsigned long e, unsigned long n){
  unsigned long temp = 1;
  int j;
  int b;
  for(j = log2(e); j >= 0; j--){
    temp = (temp*temp)%n;
    b = (e & (1 << j)) >> j;
    if(b == 1)
      temp = (temp*m)%n;
  }
  return temp;
}
