// ============================================================================
// Header file for C programs providing function prototypes
// ============================================================================

#include "types.h"

#ifndef MEMORY_H_INCL
#define MEMORY_H_INCL

// ---------------
//  Rank-1 Arrays
// ---------------

int* array_1d_type_int( idx_t init, idx_t last );
void free_array_1d_type_int( int* array, idx_t init );

double* array_1d_type_double(idx_t init, idx_t last);
void free_array_1d_type_double( double* array, idx_t init );

char* array_1d_type_char(idx_t init, idx_t last );
void free_array_1d_type_char( char* array, idx_t init );

// ---------------
//  Rank-2 Arrays
// ---------------
int** array_2d_type_int( idx_t x_init,
                         idx_t y_init,
                         idx_t x_last,
                         idx_t y_last );
void free_array_2d_type_int( int **array,
                             idx_t x_init,
                             idx_t y_init );

double** array_2d_type_double( idx_t x_init,
                               idx_t y_init,
                               idx_t x_last,
                               idx_t y_last );
void free_array_2d_type_double( double **array,
                                idx_t x_init,
                                idx_t y_init );

unsigned char** array_2d_type_unsigned_char( idx_t x_init,
                                             idx_t y_init,
                                             idx_t x_last,
                                             idx_t y_last );

void free_array_2d_type_unsigned_char( unsigned char **array,
                                       idx_t x_init,
                                       idx_t y_init );

#endif
