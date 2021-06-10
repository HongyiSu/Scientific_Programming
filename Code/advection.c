// ---------------------------------------------------------
// Scientific Programming
// Ludwig-Maximilians-Universitaet Muenchen
// Dr. Marcus Mohr, Dr. Jens Weismueller
//
// Exercise: Chemical Tracer in a Pipe
// ---------------------------------------------------------

// This is a simple program that advects some observable phi through a 1d field
// of constant velocities, using first order numerical schemes.

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>


// print usage information
void help( int argc, char** argv ) {
  if( argc == 2 ) {
    printf( "\n Sorry I do not understand the option '%s'\n", argv[1] );
  }
  printf( " Please call the program either without a command-line option" );
  printf( " to run with\n a two-sided difference," );
  printf( " or with --upwind.\n\n" );
}


int main( int argc, char** argv ) {

  // -------------
  //  Setup phase
  // -------------

  // Check command-line options
  bool use_upwind = false;
  printf( " Started program: %s\n", argv[0] );
  switch( argc ) {
  case 1:
    printf( " This simulation run uses a two-sided difference\n" );
    break;
  case 2:
    if( strcmp( argv[1], "--upwind" ) == 0 ) {
      printf( " This simulation run uses a one-sided difference (UPWIND)\n" );
      use_upwind = true;
    }
    else {
      help( argc, argv );
    }
    break;
  default:
    help( argc, argv );
  }

  // Discretisation of spatial domain: We use a total of 99 computational
  // nodes. Together with the two boundary nodes, we get a total of 101.
  const int n = 99;
  const double dx = 1.0 / (double)(n+1);
  int i;
      
  // Variables to discretize the time domain
  const int steps = 100;
  const double dt = 0.005;
  int j;

  // Physical variables
  double phi[n+2];
  double phinew[n+2];
  double v = 1.0;

  // Set up the initial concentration field (box on [0.1,0.3])
  for( i = 0; i <= n+1; i++ ) {
    phi[i] = 0.0;
  }
  for( i = (int)round(0.1/dx); i <= (int)round(0.3/dx); i++ ) {
    phi[i] = 1.0;
  }

  // Set up the boundary conditions
  phi[0] = 0.0;
  phi[n+1] = 0.0;

  // Prepare datafile for storing initial and final state
  FILE *of = NULL;
  if( use_upwind ) {
    of = fopen( "advectionOneSidedDifference.dat", "w" );
  }
  else {
    of = fopen( "advectionTwoSidedDifference.dat", "w" );
  }
  if( of == NULL ) {
    printf( "Problem opening datafile!\n" );
    exit( EXIT_FAILURE );
  }

  // Store initial concentration state in file
  for( i = 0; i <= n+1; i++ ) {
    fprintf( of, "%e\t%e\n", (double)i * dx, phi[i] );
  }

  // ---------------------------------------------
  //  Approach #1: two-sided (central) difference
  // ---------------------------------------------
  if( !use_upwind ) {

    // Advect phi through the domain
    for( j = 1; j <= steps; j++ ) {

      // Calculate the new field phi using a two-sided
      // spatial finite difference
      for( i = 1; i <= n; i++ ) {
        phinew[i] = phi[i] - ( 0.5 * dt / dx ) * v * ( phi[i+1] - phi[i-1] );
      }

      // Write the new field back into phi
      // for( i = 1; i <= n; i++ ) {
      //  phi[i] = phinew[i];
      // }
      // ... or shorter (and potentially faster for long arrays)
      memcpy( phi+1, phinew+1, n * sizeof(double) );
    }
  }

  // ------------------------------------------
  //  Approach #2: one-sided upwind difference
  // ------------------------------------------
  else {

    // Advect phi through the domain
    for( j = 1; j <= steps; j++ ) {

      // Calculate the new field phi using
      // a one-sided upwind finite difference
      for( i = 1; i <= n; i++ ) {
        phinew[i] = phi[i] - ( dt / dx ) * v * ( phi[i] - phi[i-1] );
      }

      // Write the new field back into phi
      memcpy( phi+1, phinew+1, n * sizeof(double) );
    }
  }

  // Write out two blank lines for gnuplot and then the final field
  fprintf( of, "\n\n" );
  for( i = 0; i <= n+1; i++ ) {
    fprintf( of, "%e\t%e\n", (double)i * dx, phi[i] );
  }

  // close datafile
  fclose( of );

}         
