#include <stdio.h>
int main(){
char fmt[80];
//fName = genFileName( "iteration", 9, 12 );
for(int i=0;i<=12;i++){
   int n = sprintf(fmt, "iteration%02d.data",i);
   printf("%s\n",fmt);
  }
//fName = genFileName( "output", 21, 80 );
for(int i=0;i<=80;i++){
   int n = sprintf(fmt, "output%02d.data",i);
   printf("%s\n",fmt);
  }
//fName = genFileName( "timestep", 123, 10000 );
for(int i=0;i<=10000;i++){
   int n = sprintf(fmt, "timestep%05d.data",i);
   printf("%s\n",fmt);
  }
}