
# Makefile to test oracle connection CSCI 375 TeamWon
# Taken from: CSCI 370: Sample Makefile for OCCI compilation
.EXPORT_ALL_VARIABLES:
	export ORACLE_BASE=/.jonesme/oracle-libraries
	export ORACLE_HOME=/.jonesme/oracle-libraries/instantclient_21_9
	export LD_LIBRARY_PATH=$ORACLE_HOME
	export PATH=$ORACLE_HOME:/usr/local/bin:/bin:/usr/bin:/usr/X11R6/bin:~/bin

G = g++
#Specifies the locations of occi.h headers
CFLAGS = -I$(ORACLE_HOME)/sdk/include
#Specifies the location of oracle programs needed to connect
LFLAGS = -L$(ORACLE_HOME) -locci -m64 -lclntsh
#Resolves "invalid password" bug
AUTH = -D_GLIBCXX_USE_CXX11_ABI=0


# compile the executable
exampleProg: databaseTest.o
	$(G) -o exampleProg databaseTest.o $(LFLAGS)

# The objects
databaseTest.o: databaseTest.cpp
	$(G) -c $(AUTH) $(LFLAGS) databaseTest.cpp $(CFLAGS)

clean:
	rm -f *.o exampleProg


debug: databaseTest.cpp
	g++ -D_GLIBCXX_USE_CXX11_ABI=0 -o databaseTest databaseTest.cpp \
	$(CFLAGS) \
	$(LFLAGS)

# clean:
# 	rm -f databaseTest


# Variables required for using the latest version of Oracle on the lab machines
