#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NMAX 2000000
#define NITER 15

double intersezione (double R,double dz);

int main() {
  double R,Volume[NITER+1],dz=0,dzstory[NITER+1];
  srand(time(NULL));
  printf("Questo programma calcola il volume occupato da due cellule durante la mitosi attraverso il metodo montecarlo \n");
  do{
    printf("Inserire un R delle sfere positivo\n");
    scanf("%lf",&R);
  }while(R<0);
  printf("Hai inserito %lf\n",R);
  FILE* fp;
  fp=fopen("Mitosi.dat","w+");
  for(int i=0;i<=NITER;i++){
    Volume[i]=intersezione(R,dz);
    dzstory[i]=dz;
    fprintf(fp,"%.4lf %.4lf\n",dzstory[i],Volume[i]);
    dz+=0.1*R;
  }
  fclose(fp);

}



double intersezione (double R, double dz){
  double x=0,y=0,z=0,Vmc=0,Vcells=0,Vs=0,Vlente=0,Vparal;
  int np=0;
  for(int i=0;i<NMAX;i++){
    x=(double)rand()/RAND_MAX*(2*R)-R;
    y=(double)rand()/RAND_MAX*(2*R)-R;
    z=(double)rand()/RAND_MAX*((2*R+2*dz))-R-dz;
    if(pow(x,2)+pow(y,2)+pow(z-dz,2)<=pow(R,2)||pow(x,2)+pow(y,2)+pow(z+dz,2)<=pow(R,2))
    {
      np++;
    }
  }
  Vs=((double)4/3*M_PI*pow(R,3));
  if(dz<R){
    Vlente=(double)M_PI/12*(4*R+2*dz)*pow(2*R-2*dz,2);
    //printf("minore di R\n" );
  }else if(dz>=R){
    Vlente=0;
    //printf("maggiore di R\n");
  }
  Vcells=2*Vs-Vlente;
  Vparal=(R+R)*(R+R)*(R+R+dz+dz);
  Vmc=Vparal*np/NMAX;
  if(sqrt(pow(Vmc,2)-pow(Vcells,2))/Vcells>0.01){
    printf("Errore troppo alto:%lf\n",sqrt(pow(Vmc,2)-pow(Vcells,2))/Vcells);

  }
  printf("Volume montecarlo=%lf\n",Vmc);
  printf("Volume analitico=%lf\n",Vcells);
  //printf("dz=%lf\n",dz);
  return Vmc;
}
