/*
  This is header files for Artist table in MySQL
*/

#include <string>
using namespace std;

#ifndef ARTIST_H
#define ARTIST_H

class Artist {
public:
	string name, address;
	int artistID, phoneNo;
};

#endif 
