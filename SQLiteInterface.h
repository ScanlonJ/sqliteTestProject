#include <sqlite3.h>
#include <string>
#include <iostream>

using namespace std;

class SQLiteInterface {

public:

	SQLiteInterface( const string& database );
	~SQLiteInterface();

	bool OpenDB( const string& database );
	void closeDB();

	bool runQuery( const string& sql );
	bool runStatement( const string& sql );

protected:

	sqlite3* dbHandle;
	char* SQLiteErrorMsg = 0;
};
