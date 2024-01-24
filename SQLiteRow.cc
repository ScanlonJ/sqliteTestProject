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
	string rowData;

	for( map< string, string >::iterator it = row.begin(); it != row.end(); ++it )
	{
		rowData = rowData + it->second + " ";
	}

	return rowData;
}

string SQLiteRow::getRowData()
{
	string rowData;

	for( map< string, string >::iterator it = row.begin(); it != row.end(); ++it )
	{
		rowData = rowData + it->second + "|";
	}

	return rowData;
}

string SQLiteRow::getColumnNames()
{
	string rowNames;

	for( map< string, string >::iterator it = row.begin(); it != row.end(); ++it )
	{
		rowNames = rowNames + it->first + "|";
	}

	return rowNames;
}
