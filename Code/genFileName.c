#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


char* genFileName( char* bname, int step, int maxsteps ){
  int bLen = strlen(bname);
  int nLen = (int)log10((double)maxsteps)+1;
  int sLen = bLen + nLen +1 +1 +4;
  sLen++; //string terminater

  //allocate memory
  char* fName = malloc(sLen*sizeof(char));
  if( fName == NULL){
    exit(-1);
  }

  char fmt[80];
  sprintf(fmt, "%%s-%%%d.%dd.data",nLen,nLen);
  //generate filename
  sprintf(fName, fmt, bname, step);
  return fName;
  }


int main( void ) {

  char* fName = NULL;

  fName = genFileName( "iteration", 9, 12 );
  printf( "--> '%s'\n", fName );
  free( fName );

  fName = genFileName( "output", 21, 80 );
  printf( "--> '%s'\n", fName );
  free( fName );

  fName = genFileName( "timestep", 123, 10000 );
  printf( "--> '%s'\n", fName );
  free( fName );

  return EXIT_SUCCESS;
}