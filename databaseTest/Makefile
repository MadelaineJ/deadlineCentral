#
## Makefile to test oracle connection CSCI 375 TeamWon
## Taken from: CSCI 370: Sample Makefile for OCCI compilation
#

G = g++-4.9
CFLAGS = -I/usr/local/lib/Oracle/instantclient_11_2/sdk/include
LFLAGS = -L/usr/local/lib/Oracle/instantclient_11_2 -locci -lociei

exampleProg: databaseTest.o
	$(G) $(LFLAGS) -o exampleProg databaseTest.o

databaseTest.o: databaseTest.cpp
	$(G) -c $(CFLAGS) databaseTest.cpp

clean:
	rm -f *.o exampleProg