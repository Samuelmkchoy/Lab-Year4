#Ming Kit Choy
#Makefile used to contain commands to compile helloThreads & mutualEx


#Setting variables
CC = g++ 
CFLAGS = -std=c++11 -pthread 
MUTTFILES = mutualEx.cpp Semaphores.cpp Semaphore.h
HELLO = helloThreads.o Semaphore.o
MUTUAL = mutualEx.o Semaphore.o

#This rule says that each .o file depends on a .cpp file of the same name
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

#rule to run both othe rules
all: helloThreads mutualEx

helloThreads: helloThreads.o Semaphore.o# Add HelloThreads.o & Semaphore.o as a dependency
	$(CC) $(CFLAGS) -o helloThreads $(HELLO) $(CFLAGS) $(DEBUGFLAGS)

mutualEx: mutualEx.o Semaphore.o# Add mutualExclusion.o & Semaphore.o as a dependency
	$(CC) $(CFLAGS) -o mutualEx $(MUTUAL) $(CFLAGS) $(DEBUGFLAGS)

DEBUG: DEBUGFLAGS = -DDEBUG
DEBUG: helloThreads mutualEx

#this is customary and just deletes all .o files
CLEAN:
	rm *.o