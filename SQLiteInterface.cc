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

bool SQLiteInterface::runStatement( const string& sql )
{
	sqlite3_stmt* stmt;

	if( sql == "" )
	{
		std::cout << "Unable to run query - No Query Provided" << std::endl;
		return false;
	}

	std::cout << "SQLQuery: " << sql << std::endl;

	int responseCode = sqlite3_prepare_v2( dbHandle, sql.c_str(), -1, &stmt, NULL );

	if( responseCode != SQLITE_OK )
	{
		std::cout << "Unable to run query - Unable to compile sql: " << sqlite3_errmsg( dbHandle ) << std::endl;
		sqlite3_finalize( stmt );
		return false;
	}

	int rowNum = 0;
	while( (responseCode = sqlite3_step( stmt ) ) == SQLITE_ROW )
	{
		rowNum++;
		std::cout << "TEST OUTPUT: " << sqlite3_column_text( stmt, 0 ) << std::endl;
		std::cout << "TEST OUTPUT: " << sqlite3_column_text( stmt, 1 ) << std::endl;
		std::cout << "TEST OUTPUT: " << sqlite3_column_text( stmt, 2 ) << std::endl;
		std::cout << "TEST OUTPUT: " << sqlite3_column_text( stmt, 3 ) << std::endl;
	}

	if( responseCode != SQLITE_DONE )
	{
		std::cout << "Unable to run query - Error during query: " << sqlite3_errmsg( dbHandle ) << std::endl;
		return false;
	}

	sqlite3_finalize( stmt );

	return true;

	
}
