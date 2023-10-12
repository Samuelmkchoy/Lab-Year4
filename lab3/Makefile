#Ming Kit Choy
#2-Oct-2023
CC=g++
CPPFILES=Barrier.cpp main.cpp Semaphore.cpp
HFILES=Barrier.h Semaphore.h
OBJFILES=Barrier.o main.o Semaphore.o
CFLAGS= -std=c++11 -pthread -I.

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

ALL: $(OBJFILES) $(HFILES)
	$(CC) -o barrier $(OBJFILES) $(CFLAGS) $(DEBUGFLAGS) 

DEBUG: DEBUGFLAGS = -g -O0 
DEBUG: ALL

CLEAN:
	rm *.o
