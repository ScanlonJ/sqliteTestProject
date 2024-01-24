#ifndef __SQLITERESULTSET_H__
#define __SQLITERESULTSET_H__

#include <string>
#include <iostream>
#include <vector>
#include "SQLiteRow.h"

using namespace std;

class SQLiteResultSet {

public:

	SQLiteResultSet();
	~SQLiteResultSet();

	void insertRecord( SQLiteRow row );
	SQLiteRow getNextRecord();
	SQLiteRow getRecordByIndex( int index );
	string formatResultSetForLog();

protected:

	int currentIndex;
	std::vector< SQLiteRow > resultSet;
};

#endif
