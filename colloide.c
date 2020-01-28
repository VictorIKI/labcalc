#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 1000
#define DX 1

void RandomPath(int r2[]);
void PrintResults(double av_r2[]);

int main(){
  srand(time(NULL));
  int M,r2[N]={0},i,j;
  double av_r2[N]={0.};
  printf("Questo programma simula un moto browniano unidimensionale di un colloide \n");
  do{
    printf("Inserire un numero di colloidi positivo\n");
    scanf("%i",&M );
  }while(M<=0);

  for(i=0;i<M;i++){
    RandomPath(r2);
    for(j=0;j<N;j++){
      av_r2[j]+=r2[j];
    }
  }
  for(j=0;j<N;j++){
    av_r2[j]/=(double)M;
  }
  PrintResults(av_r2);
}

void RandomPath(int r2[]){
  double random,x;
  int i;
  for(i=0;i<N;i++){
    random=(double)rand()/RAND_MAX;
    if(random<0.5){
      x-=DX;
    }else{
      x+=DX;
    }
    r2[i]=i*pow(x,2);
  }
}

void PrintResults(double av_r2[]){
  FILE* fp;
  char filename[15];
  int i;
  sprintf(filename,"sqm_DX_00%i.dat",DX);
  fp=fopen(filename,"w+");
  for (i=0;i<N;i++){
    fprintf(fp,"%i %.5lf\n",i,(double)av_r2[i]/pow(DX,2));
  }
  fclose(fp);
}
