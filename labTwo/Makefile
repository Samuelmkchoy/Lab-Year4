#Joseph Kehoe 13/9/2017
#First simple Makefile
#Used to contain commands to compile projects
#Equivalent(?) to a project file in VStudio -- only better!
#See http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/ for info.


CC=g++
CFLAGS= -std=c++11 -pthread
CFILES= Semaphore.cpp rendezvous.cpp


SIMPLE: Semaphore.cpp rendezvous.cpp Semaphore.h
	g++ -std=c++11 -pthread Semaphore.cpp rendezvous.cpp Semaphore.h

YO: $(CFILES)
	g++  -Wall -std=c++17 $(CFILES) -o main

CLEAN:
	rm *.o
