// Online C compiler to run C program online
#include <stdio.h>

void main() {
  int i=4;
  
  while(i<=40){
      if(i%2==0){
        i++;
        continue;
      }
      printf("%d ",i);
      i++;
  }
    
}