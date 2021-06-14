#include <stdio.h>
#include "memory.h"

int main( void ) {

  int xInit = -1;
  int xStop =  1;
  int yInit =  2;
  int yStop =  4;

  int** array = array_2d_type_int( xInit, yInit, xStop, yStop );

  for( int i = xInit; i <= xStop; i++ ) {
    for( int j = yInit; j <= yStop; j++ ) {
      array[i][j] = i+j;
      // printf( "array[%2d][%2d] = %d\n", i, j, array[i][j] );
    }
  }

  int sum = 0;
  for( int i = xInit; i <= xStop; i++ ) {
    for( int j = yInit; j <= yStop; j++ ) {
      sum += array[i][j];
    }
  }
  printf( "summing up array entries gives: %d\n", sum );

  free_array_2d_type_int( array, xInit, yInit );
}

