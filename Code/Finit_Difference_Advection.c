#include <stdio.h>
int main(){
    int nx = 100; //number of grid nodes
    double v = 1.0; //velocity of the advecting chemicals
    double dx = 1.0/100;
    double dt = 0.005;
    double u[nx+1];
    double new_u[nx+1];
    double du[nx];
    //intial setting
    
    for(int i=0; i<=100;i++){
        u[i]=0; //initial field u
        for(int j=20;j<60;j++){
            u[j]=1;
        }
       
        }

    //move the media by distance of 0.5c
    int type = 0; //0=centered, 1=upwind

    for(int i=1; i<=100;i++){
     du[i] = 0.0; //initialie du
     for(int j=1;j<=99;j++){
        if(type==0){
            du[j]=(u[j+1]-u[j-1])/(2.0*dx);
        }
        else if(type==1){
            du[j]=(u[j]-u[j-1])/dx;
        }
        else{
            printf("only input: centered or upwind");
        }
        new_u[j] = u[j]-dt*v*du[j];
     }
    }
    //Boundary Conditions
    new_u[100] = 0;
    new_u[0] = 0;
    printf( "u             new u\n" );
    printf( "-------------------\n" );
    for(int i = 0; i <= 100; i++ ) {
    printf( " %f | %f\n", u[i],new_u[i]);
  }


}