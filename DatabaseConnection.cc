#include "DatabaseConnection.h"
#include "DatabaseDefines.h"

DatabaseConnection::DatabaseConnection()
{
	std::cout << "DatabaseConnection()" << std::endl;
	dbInterface = new SQLiteInterface( "testDatabase.db" );
}

DatabaseConnection::~DatabaseConnection()
{
	std::cout << "~DatabaseConnection()" << std::endl;
	delete dbInterface;
}

void DatabaseConnection::invoke( const string& function, NVString& input )
{
	std::cout << "DatabaseConnection::invoke" << std::endl;

	if( function == DB_INITIALIZE_DATABASE_LAYOUT )
		initializeDatabaseLayout();
	else if( function == DB_ADD_MEMBER )
		addMember( input );
	else if( function == DB_UPDATE_MEMBER_INFO )
		updateMemberInfo( input );
	else if( function == DB_ADD_MEMBER_CLASSES )
		addMemberClasses( input );
	else if( function == DB_MARK_CLASS_ATTENDANCE )
		markClassAttendance( input );
	else if( function == DB_PROMOTE_MEMBER )
		promoteMember( input );
	else if( function == DB_SELECT_MEMBERS )
		selectMembers( input );
	else if( function == DB_SELECT_MEMBER_INFO )
		selectMemberInfo( input );
}

void DatabaseConnection::initializeDatabaseLayout()
{
	std::cout << "DatabaseConnection::initializeDatabaseLayout" << std::endl;

	string membersTableSQL = string( "CREATE TABLE IF NOT EXISTS Members" ) +
		" (ID INTEGER PRIMARY KEY AUTOINCREMENT," +
		" Name TEXT);";

	string memberInfoTableSQL = string( "CREATE TABLE IF NOT EXISTS MemberInfo" ) +
		" (MemberID INTEGER PRIMARY KEY," +
		" Name TEXT," +
		" DateOfBirth TEXT," +
		" JoinDate TEXT);";

	string memberContactInfoTableSQL = string( "CREATE TABLE IF NOT EXISTS MemberContactInfo" ) +
		" (MemberID INTEGER PRIMARY KEY," +
		" Name TEXT," +
		" Email TEXT," +
		" PhoneNumber TEXT," +
		" Relation TEXT);";

	string memberBeltInfoTableSQL = string( "CREATE TABLE IF NOT EXISTS MemberBeltInfo" ) +
		" (MemberID INTEGER PRIMARY KEY," +
		" BeltLevel TEXT," +
		" DateOfLastTest TEXT," +
		" ClassesSinceLastTest TEXT);";

	string memberClassInfoSQL = string( "CREATE TABLE IF NOT EXISTS MemberClassInfo" ) +
		" (MemberID INTEGER PRIMARY KEY," +
		" ClassesPurchased INTEGER," +
		" ClassesAttended INTEGER);";
	

	string classTrackingTableSQL = string( "CREATE TABLE IF NOT EXISTS ClassTracking" ) +
		" (ClassTime Integer PRIMARY KEY," +
		" NumberOfStudents INTEGER," +
		" ListOfStudentIDs TEXT);";

	string statementSQL = membersTableSQL +
		memberInfoTableSQL +
		memberContactInfoTableSQL +
		memberBeltInfoTableSQL +
		memberClassInfoSQL +
		classTrackingTableSQL;

	dbInterface->runQuery( statementSQL );
	
}

void DatabaseConnection::addMember( NVString& input )
{

}

void DatabaseConnection::updateMemberInfo( NVString& input )
{

}

void DatabaseConnection::addMemberClasses( NVString& input )
{

}

void DatabaseConnection::markClassAttendance( NVString& input )
{

}

void DatabaseConnection::promoteMember( NVString& )
{

}

//Not Memory safe. The caller must delete the SQLiteResultSet.
SQLiteResultSet* DatabaseConnection::selectMembers( NVString& input )
{
	string sql = "SELECT * FROM Members";

	SQLiteResultSet* result = dbInterface->runStatement( sql );

	return result;
}

SQLiteResultSet* DatabaseConnection::selectMemberInfo( NVString& input )
{
	string sql = string( "SELECT" ) +
		" a.Name," +
		" b.DateOfBirth," +
		" b.JoinDate," +
		" c.Email," +
		" c.PhoneNumber," +
		" c.Relation," +
		" d.BeltLevel," +
		" d.DateOfLastTest," +
		" d.ClassesSinceLastTest," +
		" e.ClassesPurchased," +
		" e.ClassesAttended" +
		" FROM Members AS a" +
		" LEFT JOIN MemberInfo AS b ON a.MemberID = b.MemberID" +
		" LEFT JOIN MemberContactInfo AS c ON a.MemberID = c.MemberID" +
		" LEFT JOIN MemberBeltInfo AS d ON a.MemberID = d.MemberID" +
		" LEFT JOIN MemberClassInfo AS e ON a.MemberID = d.MemberID" +
		" WHERE a.MemberID = " + input.getValue( NV_MEMBER_ID );

	SQLiteResultSet* result = dbInterface->runStatement( sql );

	return result;
}
