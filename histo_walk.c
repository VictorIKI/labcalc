#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 1000
#define DX 1
#define M 10000

int RandomPath();
void PrintResults(double av_r2[]);
void FillHisto(int x,double histo[]);

int main(){
  FILE* fp;
  srand(time(NULL));
  int r2[N]={0},i,j,x,bin=0;
  double histo[N+1]={0};
  printf("Questo programma simula un moto browniano unidimensionale di un colloide \n");

  fp=fopen("histo1.dat","w+");
  for(i=0;i<M;i++){
    x=RandomPath();
    FillHisto(x,histo);
    bin=x-(-N/2);
  }
  for(i=0;i<N;i++){
    histo[i]/=(double)M;
    if(histo[i]!=0){
      fprintf(fp,"%i %lf\n",i-(N/2)+1,histo[i]);
    }

  }
  fclose(fp);
}

int RandomPath(){
  double random;
  int i,x=0;
  for(i=0;i<N;i++){
    random=(double)rand()/RAND_MAX;
    if(random<0.5){
      x+=DX;
    }else{
      x-=DX;
    }
  }
  return x;
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

void FillHisto(int x, double histo[]){
  int bin;
  bin=x-(-N/2);
  histo[bin]++;
}
