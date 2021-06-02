// ----------------------------------------------------------------------------
//  Scientific Programming
//  Ludwig-Maximilians-Universitaet Muenchen
//  Dr. Marcus Mohr
//
//  Exercise: Number Conversion
// ----------------------------------------------------------------------------

#include <stdlib.h>
#include <stdio.h>

typedef unsigned int uint;

// ----------------------------------------------------------------
//  Convert a non-negative decimal number to binary representation
// ----------------------------------------------------------------
char* convertBase2( uint decVal ) {

  char* binVal = NULL;
  uint nDigits = 32u;

  // allocate space for string with binary representation
  binVal = (char*) malloc( (nDigits + 1u) * sizeof(char) );
  if( binVal == NULL ) {
    fprintf( stderr, "Memory allocation failed!\n" );
    exit( EXIT_FAILURE );
  }
  
  // Compute binary representation and store as string
  for( uint k = nDigits; k > 0u; --k ) {
    binVal[k-1] = decVal % 2u == 0u ? 'O' : 'L';
    decVal /= 2u;
  }

  // terminate string and return it
  binVal[nDigits] = '\0';
  return binVal;
}

// ---------------------------------------------------------------------
//  Convert a non-negative decimal number to hexadecimal representation
// ---------------------------------------------------------------------
char* convertBase16( uint decVal ) {
  return "implement me!";
}


int main( void ) {

  // generate set of test values
  uint testVals[] = { 0u,
                      17u,
                      255u,
                      256u,
                      512u,
                      1024u,
                      11259375u,
                      1431655765u,
                      2147483647u,
                      2863311530u };

  // print table header
  printf( "   base-10                  base-2                base-16\n" );
  printf( "----------------------------------------------------------\n" );

  // print table rows
  for( uint i = 0; i < 10; i++ ) {
    printf( " %10u | %s | %s\n", testVals[i],
            convertBase2( testVals[i] ), convertBase16( testVals[i] ) );
  }

}
