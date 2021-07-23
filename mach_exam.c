#include<stdio.h>
int main(){
    int const N=1000; 
    char arr[N];
    int i,j,counter=0;
    for(i=2;i<=N;i++){ 
        arr[i]=1; //initialize arr[] = 1 from indexing 2
        for(j=2;j<=N;j++){
            if(i!=j&&i%j==0){arr[i]=0;} //remove its multiples
        }
        if(arr[i]==1){
            counter+=1; //count how many primes 
        }
    }
    printf("The number of primes: %d\n", counter);
    printf("primes under %d : ", N);
    for(i=2;i<=N;i++){ //2 is the smallest prime number, so start with indexing 2
        if(arr[i]==1){
            printf("%d,", i);
        }
    }
    printf("\n");
}