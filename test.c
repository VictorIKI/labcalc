#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
  double x;
  srand48(time(NULL));
  x=(double)lrand48()/RAND_MAX;
  for (int i=0;i<1000;i++){
    printf("%lf\n",x);
  }
}
