#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


char* genFileName( char* bname, int step, int maxsteps );


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


char* genFileName( char* bName, int step, int maxSteps ) {
  
  // Step 1: determine length of composed filename

  // Step 2: allocate memory

  // Step 3: assemble format specification
  char fmt[80];
  // sprintf( fmt, ..... );

  // Step 4: generate filename

  return fName;
}
