#include <string>
#include <iostream>
#include <map>

using namespace std;

class SQLiteRow {

public:

	SQLiteRow();
	~SQLiteRow();

	bool insertRecord( const string& name, const string& data );
	string getRecord( const string& name );

	string formatRowForLog();

protected:

	std::map< string, string > row;
};
