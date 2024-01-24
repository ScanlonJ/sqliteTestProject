#include "SQLiteResultSet.h"

SQLiteResultSet::SQLiteResultSet()
{

}

SQLiteResultSet::~SQLiteResultSet()
{

}

void SQLiteResultSet::insertRecord( SQLiteRow row )
{
	resultSet.push_back( row );
}

SQLiteRow SQLiteResultSet::getNextRecord()
{
	currentIndex++;
	return resultSet[ currentIndex ];
}

SQLiteRow SQLiteResultSet::getRecordByIndex( int index )
{
	return resultSet[ index ];
}

string SQLiteResultSet::formatResultSetForLog()
{
	string output = resultSet[ 0 ].getColumnNames() + "\n";
	
	for( vector< SQLiteRow >::iterator it = resultSet.begin(); it != resultSet.end(); it++ )
	{
		output = output + it->formatRowForLog() + "\n";
	}

	return output;
}

