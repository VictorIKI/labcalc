#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10000

void assign(int carte[]);

int main() {
  srand(time(NULL));
  int n,g=0,carte[3]={0};//carte[0]=Asso,carte[1]=Cavallo,carte[2]=Re
  do{
    printf("Inserire un numero di giocate positivo minore di 10000\n");
    scanf("%i",&n);
  }while(n<0||n>N);
  do{
    printf("Inserisci 1 per simulare un giocatore furbo o 2 per un giocatore stupido\n");
    scanf("%i",&g);
  }while(g!=1&&g!=2);
  assign(carte);
}

void assign(int carte[]){
  int i;
  i=rand()%3;
  printf("%i\n",i);
  carte[i]++;
}
