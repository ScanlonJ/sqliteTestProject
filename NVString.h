#ifndef __NVSTRING_H__
#define __NVSTRING_H__

#include <string>
#include <iostream>
#include <map>

using namespace std;

class NVString {

public:

	NVString();
	~NVString();

    void insertNVPair( const string& name, const string& data );

	string getValue( const string& node );
	string toLog();
	
protected:

	std::map< string, string > nvString;
};

#endif
