# Basic arguments
RM=rm -f

# Compiler flags:
# -g    - this flag adds debugging information to the executable file
# -Wall - this flag is used to turn on most complier warning
CFLAGS =-g -Wall

# List of libraries
LIBS =-lsqlite3

DEPENDS = DesktopAttendanceTracker.o SQLiteRow.o SQLiteResultSet.o SQLiteInterface.o NVString.o DatabaseConnection.o

all: DesktopAttendanceTracker

DesktopAttendanceTracker: $(DEPENDS)
	g++ $(CFLAGS) -o DesktopAttendanceTracker $(DEPENDS) $(LIBS)

DesktopAttendanceTracker.o: main.cc
	g++ $(CFLAGS) -c main.cc -o DesktopAttendanceTracker.o

SQLiteInterface.o: SQLiteInterface.cc SQLiteInterface.h
	g++ $(CFLAGS) -c SQLiteInterface.cc

SQLiteResultSet.o: SQLiteResultSet.cc SQLiteResultSet.h
	g++ $(CFLAGS) -c SQLiteResultSet.cc

SQLiteRow.o: SQLiteRow.cc SQLiteRow.h
	g++ $(CFLAGS) -c SQLiteRow.cc

NVString.o: NVString.cc NVString.h
	g++ $(CFLAGS) -c NVString.cc

DatabaseConnection.o: DatabaseConnection.cc DatabaseConnection.h
	g++ $(CFLAGS) -c DatabaseConnection.cc

clean:
	$(RM) DesktopAttendanceTracker *.o
