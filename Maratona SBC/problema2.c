#include <stdio.h>

int main(){
  int e, v;
  int tempohoras, horariobase = 19;
  while(1){
    scanf("%d %d", &e, &v);
    tempohoras = e/v;
    horariobase = horariobase + tempohoras;
  }
 


}