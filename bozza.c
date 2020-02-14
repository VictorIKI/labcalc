#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(){
  int array[100]={0},i,j=0,k=0;
  for(i=0;i<100;i++){
    array[i]=i;
  }

for(i=0;i<100;i++){
  for(j=1;j<=array[i];j++){
    if(array[i]%j==0){
      k++;
    }
    }

    if(k==2){
      printf("%i numero primo!\n",array[i]);
    }

  k=0;
  }
}
