# file: Makefile
# author: Ted Baker
# revision: $Revision: 1.2 $
# last modified by $Author: cop4610 $ on $Date: 2002/04/07 19:34:00 $

PROGRAMS= prog4c testrandc
CXXHEADERS=simulator_class.h events_class.h random_class.h
SOURCES= simulator_class.cc random_class.cc events_class.cc prog4_class.cc testrand_class.cc
CXXOBJECTS=simulator_class.o events_class.o random_class.o
CFLAGS=-g -ansi -pedantic -Wall -DDEBUG

default: $(PROGRAMS)
$(OBJECTS): $(HEADERS)

$(CXXOBJECTS): $(CXXHEADERS)

.cc.o:
	g++ -c $(CFLAGS) -o $@ $<
prog4c: prog4_class.o $(CXXOBJECTS)
	g++ -o prog4c prog4_class.o $(CXXOBJECTS) -lm -lstdc++
# -lm is needed to tell the linker to include the math library
#     which contains natural logarithm function needed by random.c

testrandc: random_class.o testrand_class.o
	g++ -o testrandc testrand_class.o random_class.o -lm

clean:
	rm -f simulator *.o *~ $(PROGRAMS) *# 
