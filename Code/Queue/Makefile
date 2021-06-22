# Makefile for exercise on bounded queue

CC = gcc
LK = gcc

CFLAGS = -Wall -Wextra -g
LFLAGS = -o runTest

runTest : queue.o queueTest.o
	$(LK) $(LFLAGS) queue.o queueTest.o

#%.o : %.c queue.h
#	$(CC) $(CFLAGS) -c $<

clean :
	@$(RM) -f *.o *~ runTest a.out

.PHONY : clean

# EOF
