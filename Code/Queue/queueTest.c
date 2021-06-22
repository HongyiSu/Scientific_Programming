// ============================================================================
// Scientific Programming
// Ludwig-Maximilians-Universitaet Muenchen
// Dr. Marcus Mohr
//
// Exercise: Bounded Queue
// ============================================================================

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#include "queue.h"


// -------------
//  Test Driver
// -------------
int main( void ) {

  queue_t queue;
  const int capacity = 4;
  elem_t item;

  initQueue( &queue, capacity );

  // specify operations to happen on queue
  const int numOps = 14;
  typedef char opType[4];
  opType queueOps[14] = { "1.0", "2.0", "3.0", "4.0", "***",  "***",  "***",
                          "5.0", "6.0", "***", "***", "7.0", "***", "***" };

  // check initialisation
  char sep[] = "-------------------------------------------------------";
  printf( "%s\n", sep );
  printf( "              TEST OF QUEUE DATA STRUCTURE\n" );
  printf( "%s\n", sep );

  // print '(A,L1)', ' Queue is empty = ', is_empty( mgt )
  // print '(A,L1)', ' Queue is full  = ', is_full( mgt )
  printf( " Queue is empty = %s\n", is_empty( &queue ) ? "true" : "false" );
  printf( " Queue is full  = %s\n", is_full( &queue ) ? "true" : "false" );

  printf( "%s\n", sep );
  checkStatus( &queue );
  printQueue( &queue, 0, item );

  // execute operations
  for( int k = 0; k < numOps; k++ ) {

    // printf( "operation: '%s':\t", queueOps[k] );
    if( strcmp( queueOps[k], "***" ) == 0 ) {
      item = dequeue( &queue );
      printQueue( &queue, true, item );
      checkStatus( &queue );
    }

    else {
      sscanf( queueOps[k], "%f", &item );
      enqueue( &queue, item );
      printQueue( &queue, false, item );
      checkStatus( &queue );
    }
  }

  printf( "%s\n", sep );
  printf( " Queue is empty = %s\n", is_empty( &queue ) ? "true" : "false" );
  printf( " Queue is full  = %s\n", is_full( &queue ) ? "true" : "false" );
  printf( "%s\n", sep );

}
