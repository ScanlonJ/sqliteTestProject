#include "NVString.h"

NVString::NVString()
{

}

NVString::~NVString()
{

}

void NVString::insertNVPair( const string& name, const string& data )
{
	nvString.insert( std::pair( name, data ) );
}

string NVString::getValue( const string& node )
{
	return nvString[ node ];
}

string NVString::toLog()
{
	string output;
	for( map< string, string >::iterator it = nvString.begin(); it != nvString.end(); ++it )
	{
		output = output + "{" + it->first + "," + it->second + "}";
	}

	return output;
}
