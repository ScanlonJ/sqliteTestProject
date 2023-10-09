#ifndef __SQLITEINTERFACE_H__
#define __SQLITEINTERFACE_H__

#include <sqlite3.h>
#include <string>
#include <iostream>
#include "SQLiteResultSet.h"

using namespace std;

class SQLiteInterface {

public:

	SQLiteInterface( const string& database );
	~SQLiteInterface();

	bool OpenDB( const string& database );
	void closeDB();

	bool runQuery( const string& sql );
	SQLiteResultSet* runStatement( const string& sql );

protected:

	sqlite3* dbHandle;
	char* SQLiteErrorMsg = 0;
};

#endif
