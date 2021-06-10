// ============================================================================
// This C++ file acts as a sort of factory: It instantiates the generic memory
// functions for typical datatypes by wrapping suitable interface functions
// around them. The latter are marked as extern C so that we can call them
// from our C programs.
// ============================================================================

#include "generic_memory.h"

extern "C" {

#include "memory.h"

  // ---------------
  //  Rank-1 Arrays
  // ---------------

  // (de)allocation of 1d int arrays
  int* array_1d_type_int( idx_t init, idx_t last ) {
    return ARRAY_1D<int>( init, last );
  }

  void free_array_1d_type_int( int* array, idx_t init ) {
    FREE_ARRAY_1D<int>( array, init );
  }

  // (de)allocation of 1d double arrays
  double* array_1d_type_double(idx_t init, idx_t last){
    return ARRAY_1D<double>( init, last );
  }

  void free_array_1d_type_double( double* array, idx_t init ) {
    FREE_ARRAY_1D<double>( array, init );
  }

  // (de)allocation of 1d char arrays
  char* array_1d_type_char(idx_t init, idx_t last){
    return ARRAY_1D<char>( init, last );
  }

  void free_array_1d_type_char( char* array, idx_t init ) {
    FREE_ARRAY_1D<char>( array, init );
  }

  // ---------------
  //  Rank-2 Arrays
  // ---------------

  // (de)allocation of 2d int arrays
  int** array_2d_type_int( idx_t x_init,
			   idx_t y_init,
			   idx_t x_last,
			   idx_t y_last ) {
    return ARRAY_2D<int>( x_init, y_init, x_last, y_last );
  }

  void free_array_2d_type_int( int **array,
			       idx_t x_init,
			       idx_t y_init ) {
    FREE_ARRAY_2D<int>( array, x_init, y_init );
  }


  // (de)allocation of 2d double arrays
  double** array_2d_type_double( idx_t x_init,
				 idx_t y_init,
				 idx_t x_last,
				 idx_t y_last ) {
    return ARRAY_2D<double>( x_init, y_init, x_last, y_last );
  }

  void free_array_2d_type_double( double **array,
				  idx_t x_init,
				  idx_t y_init ) {
    FREE_ARRAY_2D<double>( array, x_init, y_init );
  }


  // (de)allocation of 2d unsigned char arrays
  unsigned char** array_2d_type_unsigned_char( idx_t x_init,
					       idx_t y_init,
					       idx_t x_last,
					       idx_t y_last ) {
    return ARRAY_2D<unsigned char>( x_init, y_init, x_last, y_last );
  }

  void free_array_2d_type_unsigned_char( unsigned char **array,
					 idx_t x_init,
					 idx_t y_init ) {
    FREE_ARRAY_2D<unsigned char>( array, x_init, y_init );
  }

}
