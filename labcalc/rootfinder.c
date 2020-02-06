#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 5000

int rootfinder(double s[],int i,double x,double ds);

int main(){
  int i=0,n=0;
  double x,ds,s[N]={0.},errorinocarino;
  do{
    printf("Scegli un numero reale positivo x \n");
    scanf("%lf",&x);
  }while (x<=0);
  do{
    printf("Scegli un ds maggior di %lf \n",x/N);
    scanf("%lf",&ds);
  }while (ds<=x/N);
  n=rootfinder(s,i,x,ds);
  printf("%i\n",n);
  if(s[i]*s[i]-x<pow(10,-6)){
    printf("%lf %lf %lf \n",s[n],sqrt(x),abs(s[n]-sqrt(x))/sqrt(x));
  }

}


int rootfinder(double s[],int i,double x,double ds){
  int n;
  for(i=0;i<N;i++){
    if(s[i]*s[i]<x){
      s[i+1]=s[i]+ds;
      n++;
      printf("%lf\n",s[i]);
    }
    else{return n;}
  }
  return n;
}
