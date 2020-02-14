#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX 20000

void move(int pos[]);
double analysis(int trajectory[][MAX],int posmax[], int N);
int main (){
  srand(time(NULL));
  int N, pos[2]={0},posmax[2],trajectory[2][MAX]={0},t;
  FILE* fp;
  double distance;
  do{
    printf("Inserire un valore tra 1000 e 10000\n" );
    scanf("%i",&N);
  }while (N<1000||N>10000);

  for(t=0;t<N;t++){
    trajectory[0][t]=pos[0];
    trajectory[1][t]=pos[1];
    move(pos);
  }
  fp=fopen("walk.dat","w+");
  for(t=0;t<N;t++){
    fprintf(fp,"%i %i\n",trajectory[0][t],trajectory[1][t]);
  }
  fclose(fp);
  distance=analysis(trajectory,posmax,N);
  printf("Numero di passi:%i Distanza Max:%lf Nel punto:(%i,%i)\n",N,distance,posmax[0],posmax[1]);
}

void move(int pos[]){
  int choice;
  choice=rand()%4;
  if (choice==0) {
    pos[0]+=1;//destra
  }
  if (choice==1) {
    pos[1]+=1;//su
  }
  if (choice==2) {
    pos[0]-=1;//sinistra
  }
  if (choice==3) {
    pos[1]-=1;//giù
  }
}

double analysis(int trajectory[][MAX],int posmax[],int N){
  double distance1=0, distance2;
  for(int i=0;i<N;i++){
    distance2=sqrt(pow(trajectory[0][i],2)+pow(trajectory[1][i],2));
    if(distance2>distance1){
      distance1=distance2;
      posmax[0]=trajectory[0][i];
      posmax[1]=trajectory[1][i];
    }
  }

  return distance1;
}
