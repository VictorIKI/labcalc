#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void aggiorna (int cell[]);
int conta(int cell[],int t);

int main (){
  int cell[50],cell2[50],nt,p,t,k;
  srand(time(NULL));
  do{
    printf("Inserire un numero di passi per l'evoluzione compresa tra 1 e 100:\n");
    scanf("%i",&nt);
  }while(nt<1||nt>100);

  do{
    printf("Inserire una probabilità p compresa tra 0 e 30:");
    scanf("%i",&p);
  }while(p>30||p<0);

  for (int i=0;i<50;i++){
    if(rand()%100<p){
      cell[i]=1;
      cell2[i]=1;
    }else{
      cell[i]=0;
      cell2[i]=0;
    }
  }

  for(t=0;t<nt;t++){
    aggiorna(cell);
    k=conta(cell,t);
    for(int i=0;i<50;i++){
      printf("|%i",cell[i]);
    }
    printf("\n");
  }
  printf("__________________________\n");
  printf("Numero di passi effettuati:%i\nNumero di elementi non nulli iniziali:%i\nNumero di elementi non nulli finali:%i\n",nt,conta(cell2,t),conta(cell,t));
}


void aggiorna (int cell[]){
  int cellcopy[50],i;
  for (i=0;i<50;i++){
    cellcopy[i]=cell[i];
  }
  for (i=1;i<49;i++){
    if(cellcopy[i-1]!=cellcopy[i+1]&&cellcopy[i]==0){cell[i]=1;}
    else if(cellcopy[i-1]!=cellcopy[i+1]&&cellcopy[i]==1){cell[i]=0;}
  }
}

int conta(int cell[],int t){
  int i,k=0;
  for(i=0;i<50;i++){
    if(cell[i]==1){
      k++;
    }
  }
  printf("t=%i celle vive=%i\n",t,k);
  return k;
}
