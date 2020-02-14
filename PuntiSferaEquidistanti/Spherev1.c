#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
  double x,y,z,total;
  srand(time(NULL));
  while(pow(x,2)+pow(y,2)+pow(z,2)!=1){
    x=(double)rand()/RAND_MAX*1;
    y=(double)rand()/RAND_MAX*1;
    z=(double)rand()/RAND_MAX*1;
    total=pow(x,2)+pow(y,2)+pow(z,2);
    printf("%lf \n",total);
  }
  printf("%lf %lf %lf",x,y,z);
}
