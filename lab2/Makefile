#Ming Kit Choy
#First simple Makefile
#Used to contain commands to compile projects
#Equivalent(?) to a project file in VStudio -- only better!
#See http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/ for info.


CC=g++
CFLAGS= -std=c++11 -pthread
CPPFILES=Semaphore.cpp rendezvous.cpp

RENDEZVOUS:	rendezvous.cpp
	$(CC) $(CFLAGS) $(CPPFILES) -Wall -o rendezvous

CLEAN:
	rm *.o
