#include <iostream>
#include <sqlite3.h>

int main()
{
	sqlite3 *db;
	char *xErrMsg = 0;
	int rc;

	rc = sqlite3_open( "testDatabase.db", &db );

	if( rc )
	{
		std::cout << "Can't open database: %s" << std::endl;
	}
	else
	{
		std::cout << "Opened database successfully" << std::endl;
	}

	sqlite3_close( db );

	return 0;
}
