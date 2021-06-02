// Brief demonstration of simple file usage:
// opening, writing to and closing a text file

#include <stdio.h>
#include <stdlib.h>

int main( void ) {

  // opaque file handle
  FILE* of = NULL;

  // open file for formatted writing
  of = fopen( "test.data", "w" );

  // check if it worked
  if( of == NULL ) {
    fprintf( stderr, "Problem opening output file!\n" );
    exit( EXIT_FAILURE );
  }

  // writing to the file works like printing messages
  double var = 5.0;
  fprintf( of, "Value stored in var is %e\n", var );

  // close file and check for errors
  if( fclose( of ) != 0 ) {
    fprintf( stderr, "Problem closing output file!\n" );
  }
}
