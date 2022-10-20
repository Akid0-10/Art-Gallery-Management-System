#include<iostream>
#include<string>
using namespace std;

#include<mysql/jdbc.h>
using namespace sql;

#include"DatabaseConnection.h"
#include"Artist.h"
#include"ArtistManager.h"

Artist* ArtistManager::getID() {

	Artist* artist = NULL;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.preparedStatement("SELECT MAX(ArtistID) FROM Artists");

	ResultSet* rs = ps->executeQuery();

	if(rs->next())
	artist = new Artist();
	artist->artistID = rs->getInt(1);

	delete rs;
	delete ps;
	return artist;
}

int ArtistManager::insertArtist(Artist* artist) {

	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.preparedStatement("INSERT INTO Artists VALUES (?,?,?,?)");

	ps->setInt(1, artist->artistID);
	ps->setString(2, artist->name);
	ps->setInt(3, artist->phoneNo);
	ps->setString(4, artist->address);

	int status = ps->executeUpdate();

	delete ps;
	return status;
}

Artist* ArtistManager::getArtist(int artistID) {

	Artist* artist = NULL;

	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.preparedStatement("SELECT * FROM Artists WHERE ArtistID=?");
	ps->setInt(1, artistID);

	ResultSet* rs = ps->executeQuery();

	if (rs->next()) {

		artist = new Artist();

		artist->artistID = rs->getInt(1);
		artist->name = rs->getString(2);
		artist->phoneNo = rs->getInt(3);
		artist->address = rs->getString(4);
	}

	delete ps;
	delete rs;
	
	return artist;
}

int ArtistManager::updateName(Artist* artist) {

	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.preparedStatement("UPDATE Artists SET Name=? WHERE ArtistID=?");

	ps->setString(1, artist->name);
	ps->setInt(2, artist->artistID);

	int status = ps->executeUpdate();

	delete ps;

	return status;
}

int ArtistManager::updateAddress(Artist* artist) {

	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.preparedStatement("UPDATE Artists SET Address=? WHERE ArtistID=?");

	ps->setString(1, artist->address);
	ps->setInt(2, artist->artistID);

	int status = ps->executeUpdate();

	delete ps;

	return status;
}

int ArtistManager::updatePhone(Artist* artist) {

	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.preparedStatement("UPDATE Artists SET PhoneNumber=? WHERE ArtistID=?");

	ps->setInt(1, artist->phoneNo);
	ps->setInt(2, artist->artistID);

	int status = ps->executeUpdate();

	delete ps;

	return status;
}

Artist* ArtistManager::displayArtist() {

	Artist* artist = NULL;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.preparedStatement("SELECT * FROM Artists ORDER BY ArtistID ASC");

	ResultSet* rs = ps->executeQuery();

	while (rs->next()) {
		artist = new Artist();

		cout << "\t\tArtist ID    : " << rs->getInt(1) << endl;
		cout << "\t\tName         : " << rs->getString(2) << endl;
		cout << "\t\tPhone Number : 0" << rs->getInt(3) << endl;
		cout << "\t\tAddress      : " << rs->getString(4) << endl;
		cout << "\t\t------------------------------" << endl;
	}

	delete ps;
	delete rs;

	return artist;
}