//Finite Difference method for the 1D propagation problems
//doman (x,t) belong [0,1] * [0,0.5]
//time step:0.005; spatial step:0.01, boundary nodes 0 and 100, phi is 0
//v=1
//x belong to [0.1,0.3], phi is 1

#include <stdio.h>
#include<stdlib.h>
int main(){

    unsigned int nx = 100; //number of grid nodes
    double v = 1.0; //velocity of the advecting chemicals
    double dx = 1.0/100.0;
    double dt = 0.005;
    double** phi = NULL; //concentration

    phi = (double**) calloc(100, sizeof(double*));
    if(phi == NULL){
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }
    for(int i=0; i < nx+1;i++){
        phi[i]=(double*)calloc((nx+1),sizeof(double));
        if(phi[i] == NULL){
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
        }
    }
        double d_phi[nx];
    int type; 
    float howLong; 
    printf("choose method, 1 is upwind, 0 is centered\n");
    scanf("%d",&type);
    printf("How long should the simulation time be in seconds?(f.ex. 0.000,0.005, 0.010 ... 0.495, 0.500)\n");
    scanf("%f",&howLong);
    double timeSteps = (howLong-0.005)/dt; 
    printf("Your input is %f seconds, %2.f additional timeSteps needed\n", howLong, timeSteps);
    if(howLong >=0.0 && howLong <= 0.5){
        printf("valid input. total timeSteps is %d\n", (int)(timeSteps+1));
    }
    else{
        printf("invalid input.\n");
    }
    //initial concentration
    for(int i=0; i<10;i++){
      phi[0][i]=0; 
    }
    for(int j=10;j<30;j++){
        phi[0][j]=1;
    }
    for(int k=30;k<101;k++){
        phi[0][k]=0;
    }

    //move the media by distance of 0.5, 
    //initialie d_phi
    for(int i=0; i<nx;i++){
     d_phi[i] = 0.0; 
    }

    
    switch (type)
     {
       case 0:
         for(int i=0; i<=(int)(timeSteps-1);i++){ 
          for(int j=1;j<=nx-1;j++){
            d_phi[j]=(phi[i][j+1]-phi[i][j-1])/(2.0*dx);
            phi[i+1][j] = phi[i][j]-dt*v*d_phi[j];
           }
          }
          break;
        case 1:
         for(int i=0; i<=(int)(timeSteps-1);i++){ 
          for(int j=1;j<=nx-1;j++){
             d_phi[j]=(phi[i][j]-phi[i][j-1])/dx;
             phi[i+1][j] = phi[i][j]-dt*v*d_phi[j];
           } 
          }
          break;
        default:
         printf("only input: 0 or 1");
         break;
    }

    //Boundary Conditions
     phi[(int)timeSteps][100] = 0;
     phi[(int)timeSteps][0] = 0;
     printf( "simulation starts:\n" );
     printf( "!node  phi  new_phi\n" );
      for(int j = 0; j <= 100; j++ ) {
         printf( "%3d   %2.4f   %2.4f\n", j,phi[0][j],phi[(int)timeSteps][j]); 
     }

    FILE* fp = fopen("mydata.txt","w");
    if(fp == NULL){
        fprintf(stderr, "error opening a file\n");
        exit(1);
    }

    for(int j = 0; j <= 100; j++) {
         fprintf(fp,"%f %f %f\n",dx*(double)j, phi[0][j],phi[(int)timeSteps][j]);
    }
   fclose(fp);
}
