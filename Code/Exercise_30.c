#include <stdio.h>
#include <stdlib.h> 

int main(){

int i=0;
int j=0;
int N;
printf("input the number of Nodes:");
scanf("%d", &N);
double r;
printf("input the relaxation parameter(0-2):");
scanf("%lf", &r);

//prepare data file for printing
FILE *of=NULL;
of=fopen("Exercise_30.dat","w");
if(of == NULL){
    printf("Problem opening datafile!\n");
    exit(7);
}

//memory allocation
double** array;
double* ptr;
double len=0.0;
len=sizeof(double *)*N+sizeof(double)*N*N;
array=(double **)malloc(len);
if (array == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
ptr = (double*)(array + N);

for(i=0;i<N;i++)
{
    array[i] = (ptr + N*i);
}


//set up BC
for(i=0;i<N;i++){
    array[i][0]=0.0;
   // printf("array[%d][0] = %f\n", i,array[i][0]);
}
for(i=1;i<N;i++){
    array[N-1][i]=1.0;
    //printf("array[%d][%d] = %f\n", N-1,i,array[N-1][i]);
}
for(i=1;i<N;i++){
    array[0][i]=1.0;
    //printf("array[0][%d] = %f\n", i,array[0][i]);
}
for(i=1;i<N-1;i++){
    array[i][N-1]=1.0;
   // printf("array[%d][%d] = %f\n", i,N-1,array[i][N-1]);
}

 // init internal value
 for(i=1;i<N-1;i++){
     for(j=1;j<N-1;j++){
     array[i][j] = 0.0;
     }
     //printf("array[%d][%d]: %f\n",i,j,array[i][j] );}
 }
double sum_0 = 0;
int iter = 0;
while(iter <= 400){
    double correction = 0.0;
    double sum = 0.0;

    for(i=1;i<N-1;i++){
        for(j=1;j<N-1;j++){
            array[i][j] = 0.25*r*(array[i-1][j]+array[i][j-1]+array[i+1][j]+array[i][j+1]);
        }
    }
    iter++;
    for(i=1;i<N-1;i++){
        for(j=1;j<N-1;j++){
            sum += array[i][j];
        }
    }
    correction = sum - sum_0; 
    //relxation
    if(correction <=0.001){
        printf("stable solution reached at iteration: %d (correction<0.001)\n",iter);
        break;
    }
    printf("correction at iteration %d: %f\n", iter, correction);
    fprintf(of,"%d\t%e\n", iter, correction);
    sum_0 = sum;
}

}