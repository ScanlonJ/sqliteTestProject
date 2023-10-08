#include <iostream>
#include <string>
#include "SQLiteInterface.h"

using namespace std;

int main()
{
	SQLiteInterface* sqliteInterface = new SQLiteInterface( "testDatabase.db" );

	string sql = "SELECT * FROM COMPANY";

	SQLiteResultSet* result = sqliteInterface->runStatement( sql );

	std::cout << "Results:" << std::endl << result->formatResultSetForLog() << std::endl;
	
	delete sqliteInterface;

	return 0;
}
