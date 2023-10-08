#include <iostream>
#include <string>
#include "SQLiteInterface.h"

using namespace std;

int main()
{
	SQLiteInterface* sqliteInterface = new SQLiteInterface( "testDatabase.db" );

	string sql = "SELECT * FROM COMPANY";

	if( !sqliteInterface->runStatement( sql ) )
	{
		std::cout << "Statement failed" << std::endl;
	}
	else
	{
		std::cout << "Successfully ran statement" << std::endl;
	}
	
	delete sqliteInterface;

	return 0;
}
