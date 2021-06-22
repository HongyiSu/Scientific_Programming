// ============================================================================
// Scientific Programming
// Ludwig-Maximilians-Universitaet Muenchen
// Dr. Marcus Mohr
//
// Exercise: Bounded Queue
// ============================================================================
//
// YOUR TASK:
//
// Please implement the body of the following three functions
//
//   - is_full()
//   - is_empty()
//   - dequeue()
//
// =============================================================================

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "queue.h"


// ------------------------------
//  remove head element of queue
// ------------------------------
elem_t dequeue( queue_t* queue ) {
  fprintf( stderr, "PLEASE IMPLEMENT dequeue()!\n" );
  exit( EXIT_FAILURE );
}


// ------------------------------
//  return whether queue is full
// ------------------------------
bool is_full( queue_t* queue ) {
  fprintf( stderr, "PLEASE IMPLEMENT is_full()!\n" );
  exit( EXIT_FAILURE );
};


// -------------------------------
//  return whether queue is empty
// -------------------------------
bool is_empty( queue_t* queue ) {
  fprintf( stderr, "PLEASE IMPLEMENT is_empty()!\n" );
  exit( EXIT_FAILURE );
};


// -------------------------------------
//  set management info for empty queue
// -------------------------------------
void setQueueToEmpty( queue_t* queue ) {
  queue->head     =  0;
  queue->tail     = -1; 
  queue->length   =  0; 
}


// ---------------------
//  initialse our queue
// ---------------------
void initQueue( queue_t* queue, int capacity ) {
  queue->capacity = capacity;
  queue->elem = malloc( capacity * sizeof( elem_t ) );
  if( queue->elem == NULL ) {
    fprintf( stderr, "error in queue initialisation!\n" );
    exit( EXIT_FAILURE );
  }
  setQueueToEmpty( queue );
}


// -----------------
//  clear our queue
// -----------------
void clearQueue( queue_t* queue ) {
  free( queue->elem );
  queue->elem = NULL;
  setQueueToEmpty( queue );
}


// ------------------------------
//  add element to tail of queue
// ------------------------------
void enqueue( queue_t* queue, elem_t new ) {

  if( !is_full( queue ) ) {
    queue->tail = (queue->tail + 1) % queue->capacity;
    queue->elem[ queue->tail ] = new;
    queue->length += 1;
  }
  else {
    fprintf( stderr, "queue capacity exceeded!\n" );
    exit( EXIT_FAILURE );
  }
}


// --------------------
//  pretty print queue
// --------------------
void printQueue( queue_t* queue, bool dequeued, elem_t item ) {

  static int header = 1;

  // on first call print table header
  if ( header ) {
    printf( " length head tail     queue elements\n" );
      header = 0;
  }

  // output managment information
  printf( "%5d   %3d  %3d    ", queue->length, queue->head, queue->tail );

  // empty queue
  if( queue->length == 0 ) {
    for( int k = 1; k <= queue->capacity; k++ ) {
      printf( "***  " );
    }
  }

  // no wrap-around
  else if ( queue->tail >= queue->head ) {
    for( int k = 0; k < queue->head; k++ ) {
      printf( "***  " );
    }
    for( int k = queue->head; k <= queue->tail; k++ ) {
      printf( "%3.1f  ", queue->elem[k] );
    }
    for( int k = queue->tail+1; k < queue->capacity; k++ ) {
      printf( "***  " );
    }
  }

  // with wrap-around
  else {
    for( int k = 0; k <= queue->tail; k++ ) {
      printf( "%3.1f  ", queue->elem[k] );
    }
    for( int k = queue->tail+1; k < queue->head; k++ ) {
      printf( "***  " );
    }
    for( int k = queue->head; k < queue->capacity; k++ ) {
      printf( "%3.1f  ", queue->elem[k] );
    }
  }

  // check for dequeue operation
  if( dequeued ) {
    printf( "[dequeued: %3.1f]\n", item );
  }
  else {
    printf( "\n" );
  }
}


// --------------------
//  check queue status
// --------------------
void checkStatus( queue_t* queue ) {

  int qcap = queue->capacity;
  int qlen = queue->length;
  int head = queue->head;
  int tail = queue->tail;

  if ( ( qlen > qcap ) ||
       ( qlen < 0 ) ||
       ( qlen == 0 && tail != -1 ) ||
       ( qlen != 0 && tail == -1 ) ||
       ( head > qcap ) ||
       ( head < 0 ) ||
       ( tail > qcap ) ||
       ( tail < -1 ) ||
       ( tail != (head + qlen - 1) % qcap ) ) {
    fprintf( stderr, "Queue inconsistent!\n" );
    exit( EXIT_FAILURE );
  }
}
