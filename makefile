# Basic arguments
RM=rm -f

# Compiler flags:
# -g    - this flag adds debugging information to the executable file
# -Wall - this flag is used to turn on most complier warning
CFLAGS =-g -Wall

# List of libraries
LIBS =-lsqlite3

DEPENDS = SQLiteTest.o SQLiteRow.o SQLiteResultSet.o SQLiteInterface.o

all: SQLiteTest

SQLiteTest: $(DEPENDS)
	g++ $(CFLAGS) -o SQLiteTest $(DEPENDS) $(LIBS)

SQLiteTest.o: test.cc
	g++ $(CFLAGS) -c test.cc -o SQLiteTest.o

SQLiteInterface.o: SQLiteInterface.cc SQLiteInterface.h
	g++ $(CFLAGS) -c SQLiteInterface.cc

SQLiteResultSet.o: SQLiteResultSet.cc SQLiteResultSet.h
	g++ $(CFLAGS) -c SQLiteResultSet.cc

SQLiteRow.o: SQLiteRow.cc SQLiteRow.h
	g++ $(CFLAGS) -c SQLiteRow.cc

clean:
	$(RM) SQLiteTest *.o
