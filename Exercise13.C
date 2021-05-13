#include <stdio.h>
int main(){
  const float a=0.0;
  const float b=4.0;
  const float n=40.0;
  const float a_0=-6.0;
  const float a_1=11.0;
  const float a_2=-6.0;
  const float a_3=1.0;
  float x_k[40];
  float p_k[40];
  for(int k=1;k<=n;k++)
    {
      x_k[k]=a+(float)k*(b-a)/n;
      p_k[k]=a_3*x_k[k]*x_k[k]*x_k[k]+a_2*x_k[k]*x_k[k]+a_1*x_k[k]+a_0;
      printf("k= %d,x_k= %2f,p_xk= %2f\n",k,x_k[k],p_k[k]);
  

  }


}
