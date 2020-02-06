#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#define B 0.001


int main() {
  double vel;
  do{
    printf("Inserire una velocità compresa tra 0 e 35 m/s\n");
    scanf("%lf",&vel);
  }while(vel<0||vel>35);
  
}
