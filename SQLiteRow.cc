#include "SQLiteRow.h"

SQLiteRow::SQLiteRow()
{

}

SQLiteRow::~SQLiteRow()
{

}

bool SQLiteRow::insertRecord( const string& name, const string& data )
{
	row.insert( std::pair( name, data ) );

	return true;
}

string SQLiteRow::getRecord( const string& name )
{
	return row[ name ];
}

string SQLiteRow::formatRowForLog()
{
	string rowNames;
	string rowData;

	for( map< string, string >::iterator it = row.begin(); it != row.end(); ++it )
	{
		rowNames = rowNames + it->first + " "; 
		rowData = rowData + it->second + " ";
	}

	return rowNames + "\n" + rowData;
}

