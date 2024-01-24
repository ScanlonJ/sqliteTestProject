#ifndef __DATABASECONNECTION_H__
#define __DATABASECONNECTION_H__

#include <string>
#include <iostream>
#include <sqlite3.h>
#include "NVString.h"
#include "SQLiteInterface.h"
#include "SQLiteResultSet.h"

using namespace std;

class DatabaseConnection {

public:

	DatabaseConnection();
	~DatabaseConnection();

	void invoke( const string& function, NVString& input );

protected:

	void initializeDatabaseLayout();
	void addMember( NVString& input );
	void updateMemberInfo( NVString& input );
	void addMemberClasses( NVString& input );
	void markClassAttendance( NVString& input );
	void promoteMember( NVString& );

	SQLiteResultSet* selectMembers( NVString& input );
	SQLiteResultSet* selectMemberInfo( NVString& input );
	
	SQLiteInterface* dbInterface;
	
};

#endif
