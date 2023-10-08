# Basic arguments
RM=rm -f

# Compiler flags:
# -g    - this flag adds debugging information to the executable file
# -Wall - this flag is used to turn on most complier warning
CFLAGS =-g -Wall

# List of libraries
LIBS =-lsqlite3

all: SQLiteTest

SQLiteTest: SQLiteTest.o SQLiteInterface.o
	g++ $(CFLAGS) -o SQLiteTest SQLiteTest.o SQLiteInterface.o $(LIBS)

SQLiteTest.o: test.cc
	g++ $(CFLAGS) -c test.cc -o SQLiteTest.o

SQLiteInterface.o: SQLiteInterface.cc SQLiteInterface.h
	g++ $(CFLAGS) -c SQLiteInterface.cc

clean:
	$(RM) SQLiteTest *.o
