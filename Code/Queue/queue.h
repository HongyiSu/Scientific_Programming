// ============================================================================
// Scientific Programming
// Ludwig-Maximilians-Universitaet Muenchen
// Dr. Marcus Mohr
//
// Exercise: Bounded Queue
// ============================================================================


// datatype of queue elements
typedef float elem_t;

// datatype for queue itself
typedef struct {
  elem_t* elem;
  int capacity;   // capacity of queue
  int head;       // index of head of queue
  int tail;       // index of tail of queue
  int length;     // current length of queue
} queue_t;


// function prototypes
bool is_full( queue_t* queue );
bool is_empty( queue_t* queue );
void enqueue( queue_t* queue, elem_t new );
elem_t dequeue( queue_t* queue );

void initQueue( queue_t* queue, int capacity );
void clearQueue( queue_t* queue );
void setQueueToEmpty( queue_t* queue );

void printQueue( queue_t* queue, bool dequeued, elem_t item );
void checkStatus( queue_t* queue );

// ============================================================================
