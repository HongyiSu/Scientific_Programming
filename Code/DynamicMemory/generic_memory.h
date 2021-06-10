//
// GENERIC C++ functions for handling dynamic memory (de)allocation
// for arrays in 1D, 2D and 3D
//

#include <stdlib.h>
#include <stdio.h>
#include "types.h"

#define ERROR_MEMORY (-6)


/* ----------------------------------------------------------------------------
   NAME:   ARRAY_1D
   ^^^^

   TASK:
   ^^^^
   The generic function allocates memory for a one dimensional vector of
   objects specified by the template T. The entries of the field are
   initialized to zero. The pointer handed back is equipped with an offset
   to make the entries easily  accessible. Therefore the field ranges are
   [init .. last].

   INTERFACE:
   ^^^^^^^^^
   init ..... first index of vector
   last ..... final index of vector

   RETURN VALUE:
   ^^^^^^^^^^^^
   The routine returns a pointer (with offset) to the vector of objects
---------------------------------------------------------------------------- */
template <typename T>
T* ARRAY_1D( idx_t init, idx_t last )
{

  T *tmp;
  
  /* Allocate memory */
  tmp = (T*) calloc( last - init + 1, sizeof(T) );
  if ( tmp == NULL ) {
    fprintf( stderr, "Error in ARRAY_1D !!!\n" );
    fprintf( stderr, "Could not allocate %lu objectes of size %lu\n\n",
	     last - init + 1, (idx_t)sizeof(T) );
    exit(ERROR_MEMORY);
  }

  /* Arrange offset */
  tmp -= init;

  /* We are finished */
  return tmp;
}


/* ----------------------------------------------------------------------------
   NAME:   FREE_ARRAY_1D
   ^^^^

   TASK:
   ^^^^
   The generic function deallocates memory for a one dimensional vector of
   objects specified by the template T. The entries of the field are
   initialized to zero. The vector is assumed to posses an offset, so that
   its ranges are [init .. last].

   INTERFACE:
   ^^^^^^^^^
   array .... pointer (with offset) to the vector
   init ..... first index of vector

   RETURN VALUE:
   ^^^^^^^^^^^^
   The routine does not have a return value
---------------------------------------------------------------------------- */
template <typename T>
void FREE_ARRAY_1D( T* array, idx_t init )
{
  free ( array + init );
}


/* ----------------------------------------------------------------------------
   NAME:   ARRAY_2D
   ^^^^

   TASK:
   ^^^^
   The function allocates memory for a two dimensional field of objects
   specified by the template T. The entries of the field are initialized
   to zero.

   The memory is allocated in one big block, but is made accessible in the
   form of pointer to vector of pointers to T.

   The field is provided with an offset in both directions to make it easily
   accessible. Therefore the field ranges are [x_init..x_last] and
   [y_init..y_last].

   INTERFACE:
   ^^^^^^^^^
   x_init ..... first position for first index
   y_init ..... first position for second index
   x_last ..... final position for first index
   y_last ..... final position for second index

   RETURN VALUE:
   ^^^^^^^^^^^^
   The routine returns a pointer (with offset) to a vector of pointers to T
---------------------------------------------------------------------------- */
template <typename T>
T** ARRAY_2D( idx_t x_init, idx_t y_init,
	      idx_t x_last, idx_t y_last )
{

  idx_t k, x_size, y_size;
  T **tmp;

  /* Determine field sizes in the two dimensions and perform range check */
  x_size = x_last - x_init + 1;
  y_size = y_last - y_init + 1;
  if ( ( x_size * y_size ) / y_size != x_size ) {
    fprintf( stderr, "Error in ARRAY_2D (level 0)!!!\n" );
    fprintf( stderr, "Product of xrange with yrange is larger than " );
    fprintf( stderr, "ULONG_MAX\n\n" );
    exit(ERROR_MEMORY);
  }

  /* Allocate memory for data and pointers */
  tmp = (T**) calloc( x_size, sizeof(T*) );
  if ( tmp == NULL ) {
    fprintf( stderr, "Error in ARRAY_2D (level 1)!!!\n" );
    fprintf( stderr, "Could not allocate %lu pointers of size %lu\n\n",
	     x_size, (idx_t)sizeof(T*) );
    exit(ERROR_MEMORY);
  }

  /* Arrange offset for first index */
  tmp -= x_init;

  /* Allocate array itself */
  tmp[x_init] = (T*) calloc( x_size*y_size, sizeof(T) );
  if ( tmp[x_init] == NULL ) {
    fprintf( stderr, "Error in ARRAY_2D (2)!!!\n\n" );
    fprintf( stderr, "Could not allocate %lu objects of size %lu\n\n",
	     x_size*y_size, (idx_t)sizeof(T) );
    exit(ERROR_MEMORY);
  }

  /* Arrange offset for second index */
  tmp[x_init] -= y_init;


  /* Set remaining pointers */
  for ( k = 1; k < x_size; k++ ) {
    tmp[x_init+k] = tmp[x_init] + k*y_size;
  }

  /* We are finished */
  return tmp;
}


/* ----------------------------------------------------------------------------
   NAME:   FREE_ARRAY_2D
   ^^^^

   TASK:
   ^^^^
   De-allocate memory previously allocated by a call to ARRAY_2D

   INTERFACE:
   ^^^^^^^^^
   array ...... pointer (with offset) to the 2D array structure
   x_init ..... first position for first index
   y_init ..... first position for second index

   RETURN VALUE:
   ^^^^^^^^^^^^
   The routine does not have a return value
---------------------------------------------------------------------------- */
template <typename T>
void FREE_ARRAY_2D( T** array, idx_t x_init,
		    idx_t y_init )
{

  free ( array[ x_init ] + y_init );
  free ( array + x_init );

}


/* ----------------------------------------------------------------------------
   NAME:   ARRAY_3D
   ^^^^

   TASK:
   ^^^^
   The routine allocates memory for a three dimensional field of objects
   whose type is determined by the template T. The entries of the field are
   initialized to zero.

   The memory is allocated in one big block, but is made accessible in the
   form of pointer to vector of pointers to vector of pointers of T.

   The field is provided with an offset in all three directions to make it
   easily accessible. Therefore the field ranges are [x_init..x_last],
   [y_init..y_last] and [z_init..z_last].

   INTERFACE:
   ^^^^^^^^^
   x_init ..... first position for first index
   y_init ..... first position for second index
   z_init ..... first position for third index
   x_last ..... final position for first index
   y_last ..... final position for second index
   z_last ..... final position for third index

   RETURN VALUE:
   ^^^^^^^^^^^^
   First pointer of the array "object"
---------------------------------------------------------------------------- */
template <typename T>
T*** ARRAY_3D( idx_t x_init, idx_t y_init,
	       idx_t z_init, idx_t x_last,
	       idx_t y_last, idx_t z_last )
{
  idx_t k, x_size, y_size, z_size;
  T ***tmp;

  /* Determine field sizes in all three dimensions */
  x_size = x_last - x_init + 1;
  y_size = y_last - y_init + 1;
  z_size = z_last - z_init + 1;

  /* perform range checks */
  if ( ( x_size * y_size ) / y_size != x_size ) {
    fprintf( stderr, "Error in ARRAY_3D (level 0)!!!\n" );
    fprintf( stderr, "Product of xrange with yrange is larger than " );
    fprintf( stderr, "ULONG_MAX\n\n" );
    exit(ERROR_MEMORY);
  }
  if ( ( x_size * y_size * z_size ) / z_size != x_size * y_size ) {
    fprintf( stderr, "Error in ARRAY_3D (level 0)!!!\n" );
    fprintf( stderr, "Product xrange * yrange * zrange is larger than " );
    fprintf( stderr, "ULONG_MAX\n\n" );
    exit(ERROR_MEMORY);
  }

  /* Allocate first pointer level */
  tmp = (T***) calloc( x_size, sizeof(T**) );
  if ( tmp == NULL ) {
    fprintf( stderr, "Error in ARRAY_3D (1)!!!\n" );
    fprintf( stderr, "Could not allocate %lu pointers of size %lu\n\n",
	     x_size, (idx_t)sizeof(T**) );
    exit(ERROR_MEMORY);
  }

  /* Arrange offset for first index */
  tmp -= x_init;

  /* Allocate second pointer level */
  tmp[x_init] = (T**) calloc( x_size*y_size, sizeof(T*) );
  if ( tmp[x_init] == NULL ) {
    fprintf( stderr, "Error in ARRAY_3D (2)!!!\n" );
    fprintf( stderr, "Could not allocate %lu pointers of size %lu\n\n",
	     x_size*y_size, (idx_t)sizeof(T*) );
  }

  /* Arrange offset for second index */
  tmp[x_init] -= y_init;

  /* Allocate memory for objects */
  tmp[x_init][y_init] = (T*) calloc( x_size*y_size*z_size, sizeof(T) );
  if ( tmp[x_init][y_init] == NULL ) {
    fprintf( stderr, "Error in ARRAY_3D (3)!!!\n" );
    fprintf( stderr, "Could not allocate %lu objects of size %lu\n\n",
	     x_size*y_size*z_size, (idx_t)sizeof(T) );
    exit(ERROR_MEMORY);
  }

  /* Arrange offset for third index */
  tmp[x_init][y_init] -= z_init;

  /* Set pointers */
  for ( k = 1; k < x_size; k++ ) {
    tmp[x_init+k] = tmp[x_init] + k*y_size;
  }

  for ( k = 1; k < x_size*y_size; k++ ) {
    tmp[x_init][y_init+k] = tmp[x_init][y_init] + k*z_size;
  }

  return tmp;
}


/* ----------------------------------------------------------------------------
   NAME:   FREE_ARRAY_3D
   ^^^^

   TASK:
   ^^^^
   De-allocate memory previously allocated by a call to ARRAY_3D

   INTERFACE:
   ^^^^^^^^^
   array ...... pointer (with offset) to the 3D array structure
   x_init ..... first position for first index
   y_init ..... first position for second index
   z_init ..... first position for third index

   RETURN VALUE:
   ^^^^^^^^^^^^
   The routine does not have a return value
---------------------------------------------------------------------------- */
template <typename T>
void FREE_ARRAY_3D( T*** array, idx_t x_init,
		    idx_t y_init, idx_t z_init )
{

  free ( array[ x_init ][ y_init ] + z_init );
  free ( array[ x_init ] + y_init );
  free ( array + x_init );

}
