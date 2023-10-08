#include "SQLiteInterface.h"


SQLiteInterface::SQLiteInterface( const string& database )
{
	OpenDB( database );
}

SQLiteInterface::~SQLiteInterface()
{
	closeDB();
}

bool SQLiteInterface::OpenDB( const string& database )
{
	if( database == "" )
	{
		std::cout << "No database file provided" << std::endl;
		return false;
	}
	
	int responseCode = sqlite3_open( database.c_str(), &dbHandle );

	if( responseCode )
	{
		std::cout << "Can't open database file: " << sqlite3_errmsg( dbHandle ) << std::endl;
		return false;
	}
	else
	{
		std::cout << "Opened Database File" << std::endl;
		return true;
	}	
}

void SQLiteInterface::closeDB()
{
	sqlite3_close( dbHandle );
	
}


bool SQLiteInterface::runQuery( const string& sql )
{
	if( sql == "" )
	{
		std::cout << "Unable to run query - No Query Provided" << std::endl;
		return false;
	}

	std::cout << "SQL Query: " << sql << std::endl;
	
	int responseCode = sqlite3_exec( dbHandle, sql.c_str(), NULL, 0, &SQLiteErrorMsg );

	if( responseCode != SQLITE_OK )
	{
		std::cout << "SQL error: " << SQLiteErrorMsg << std::endl;
		sqlite3_free( SQLiteErrorMsg );
		return false;
	}

	return true;
}

// This function does not manage it's own memory. The SQLiteResultSet must be deleted by the caller.
SQLiteResultSet* SQLiteInterface::runStatement( const string& sql )
{
	sqlite3_stmt* stmt;
	SQLiteResultSet* statementResultSet = new SQLiteResultSet();

	if( sql == "" )
	{
		std::cout << "Unable to run query - No Query Provided" << std::endl;
		return statementResultSet;
	}

	std::cout << "SQLQuery: " << sql << std::endl;

	int responseCode = sqlite3_prepare_v2( dbHandle, sql.c_str(), -1, &stmt, NULL );

	if( responseCode != SQLITE_OK )
	{
		std::cout << "Unable to run query - Unable to compile sql: " << sqlite3_errmsg( dbHandle ) << std::endl;
		sqlite3_finalize( stmt );
		return statementResultSet;
	}

	int rowNum = 0;
	while( (responseCode = sqlite3_step( stmt ) ) == SQLITE_ROW )
	{
		SQLiteRow* row = new SQLiteRow();

		int columnCount = sqlite3_column_count( stmt );
		for( int i = 0; i < columnCount; i++ )
		{
			row->insertRecord( sqlite3_column_name( stmt, i ), (const char*) sqlite3_column_text( stmt, i ) );
		}

		std::cout << "Row " << rowNum << " " << row->formatRowForLog() << std::endl;

		statementResultSet->insertRecord( *row );

		delete row;
		rowNum++;

		std::cout << "ResultSet " << statementResultSet->formatResultSetForLog() << std::endl;
	}

	if( responseCode != SQLITE_DONE )
	{
		std::cout << "Unable to run query - Error during query: " << sqlite3_errmsg( dbHandle ) << std::endl;
		return statementResultSet;
	}

	sqlite3_finalize( stmt );

	return statementResultSet;

	
}
