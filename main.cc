#include <iostream>
#include <string>
#include "SQLiteInterface.h"
#include "DatabaseConnection.h"
#include "DatabaseDefines.h"

using namespace std;

int main()
{
	/*SQLiteInterface* sqliteInterface = new SQLiteInterface( "testDatabase.db" );

	string sql = "SELECT * FROM COMPANY";

	SQLiteResultSet* result = sqliteInterface->runStatement( sql );

	std::cout << "Results:" << std::endl << result->formatResultSetForLog() << std::endl;
	
	delete sqliteInterface;*/

	DatabaseConnection* dbConnection = new DatabaseConnection();
	NVString* nvString = new NVString();

	dbConnection->invoke( DB_INITIALIZE_DATABASE_LAYOUT, *nvString );

	return 0;
}
