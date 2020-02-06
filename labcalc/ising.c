#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define N 12
#define N2 4096
#define M1 1000
#define M2 10000

//void genconf(int conf[],double energie1[])
double epsilon(int conf[]);
void spinconf(int conf[]);

int main(){
  int conf[N]={0},controllo[2*N+1]={-12,-11,-10,-9,-8,-7,-6,-5,-4,-3,-2,-1,0,1,2,3,4,5,6,7,8,9,10,11,12},frequenza[2*N+1],M;
  double energie1[N2]={0},energie2[10000]={0};;
  int i,i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,i11,i12,iconf,j=0;
  FILE* fp;
  srand(time(NULL));
  //Blocco generazione 4096 configurazioni ed energie
  for(i1=1;i1<=2;i1++){
    for(i2=1;i2<=2;i2++){
      for(i3=1;i3<=2;i3++){
        for(i4=1;i4<=2;i4++){
          for(i5=1;i5<=2;i5++){
            for(i6=1;i6<=2;i6++){
              for(i7=1;i7<=2;i7++){
                for(i8=1;i8<=2;i8++){
                  for(i9=1;i9<=2;i9++){
                    for(i10=1;i10<=2;i10++){
                      for(i11=1;i11<=2;i11++){
                        for(i12=1;i12<=2;i12++){
                          conf[0]=pow(-1.0,i1);
                          conf[1]=pow(-1.0,i2);
                          conf[2]=pow(-1.0,i3);
                          conf[3]=pow(-1.0,i4);
                          conf[4]=pow(-1.0,i5);
                          conf[5]=pow(-1.0,i6);
                          conf[6]=pow(-1.0,i7);
                          conf[7]=pow(-1.0,i8);
                          conf[8]=pow(-1.0,i9);
                          conf[9]=pow(-1.0,i10);
                          conf[10]=pow(-1.0,i11);
                          conf[11]=pow(-1.0,i12);
                          //assegno le energie
                          energie1[iconf]=epsilon(conf);
                          //stampa delle prime dieci configuazioni
                          if(j<10){
                            printf("Configurazione n° %2i",j+1);
                            for (i=0;i<N;i++){
                              printf("|%2i",conf[i]);
                            }
                            printf("| eps: %lf\n",energie1[iconf]);
                            j++;
                          }

                          iconf++;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  //calcolo le frequenze
  for(i=0;i<N2;i++){
    for(j=0;j<2*N+1;j++){
      if(controllo[j]==energie1[i]){
        frequenza[j]++;

      }
    }
  }
  //scrivo su file le frequenze
  fp= fopen("histo1.dat","w+");
  for(j=0;j<2*N+1;j++){
    fprintf(fp,"%i %i\n",controllo[j],frequenza[j]);
  }
  fclose(fp);

  //chiedo il numero di configurazioni da generare
  do{
    printf("Inserire un numero di configurazioni da generare compreso tra %i e %i:",M1,M2);
    scanf("%i",&M);
  }while(M<M1||M>M2);
  j=0;

  //genero le configurazioni casuali e ne calcolo l'energia
  for (i=0;i<M;i++){
    spinconf(conf);
    energie2[i]=epsilon(conf);
    //stampo le prime 10 configurazioni
    if(j<10){
      printf("Configurazione n° %2i",j+1);
      for (i1=0;i1<N;i1++){
        printf("|%2i",conf[i1]);
      }
      printf("| eps: %lf\n",energie2[i]);
      j++;
    }
  }

  for(i=0;i<N2;i++){
    for(j=0;j<2*N+1;j++){
      if(controllo[j]==energie1[i]){
        frequenza[j]++;

      }
    }
  }

  for(i=0;i<N2;i++){
    for(j=0;j<2*N+1;j++){
      if(controllo[j]==energie2[i]){
        frequenza[j]++;

      }
    }
  }

  fp= fopen("histo2.dat","w+");
  for(j=0;j<2*N+1;j++){
    fprintf(fp,"%i %i\n",controllo[j],frequenza[j]);
  }
  fclose(fp);


}

double epsilon(int conf[]){
  int i;
  double eps;
  for(i=0;i<N;i++){
    if(i+1>11){
      eps+=conf[0]*conf[N-1];
    }
    else{eps+=conf[i]*conf[i+1];}
  }
  //eps*=(double)-1/N;
  return eps;
}

void spinconf(int conf[]){
  int i,j;
  for (i=0;i<N;i++){
    j= rand()%2+1;
    conf[i]=pow(-1.0,j);
  }
}

/*void genconf(int conf[][N2],energie1[],double (*f)(int conf[][N2])){
  int i,i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,i11,i12,iconf;
  for(i1=1;i1<=2;i1++){
    for(i2=1;i2<=2;i2++){
      for(i3=1;i3<=2;i3++){
        for(i4=1;i4<=2;i4++){
          for(i5=1;i5<=2;i5++){
            for(i6=1;i6<=2;i6++){
              for(i7=1;i7<=2;i7++){
                for(i8=1;i8<=2;i8++){
                  for(i9=1;i9<=2;i9++){
                    for(i10=1;i10<=2;i10++){
                      for(i11=1;i11<=2;i11++){
                        for(i12=1;i12<=2;i12++){
                            conf[0][iconf]=pow(-1.0,i1);
                            conf[1][iconf]=pow(-1.0,i2);
                            conf[2][iconf]=pow(-1.0,i3);
                            conf[3][iconf]=pow(-1.0,i4);
                            conf[4][iconf]=pow(-1.0,i5);
                            conf[5][iconf]=pow(-1.0,i6);
                            conf[6][iconf]=pow(-1.0,i7);
                            conf[7][iconf]=pow(-1.0,i8);
                            conf[8][iconf]=pow(-1.0,i9);
                            conf[9][iconf]=pow(-1.0,i10);
                            conf[10][iconf]=pow(-1.0,i11);
                            conf[11][iconf]=pow(-1.0,i12);
                          energie1[iconf]=f(conf[][iconf]);
                          iconf++;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}*/
