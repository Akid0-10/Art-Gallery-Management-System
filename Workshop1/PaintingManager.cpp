#include<iostream>
#include<string>
#include<sstream>
using namespace std;

#include<mysql/jdbc.h>
using namespace sql;

#include "DatabaseConnection.h"
#include "Painting.h"
#include "PaintingManager.h"

int PaintingManager::insertPainting(Painting* painting)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.preparedStatement("INSERT INTO Paintings VALUES (?,?,?,?)");

	ps->setInt(1, painting->paintingID);
	ps->setString(2, painting->name);
	ps->setString(3, painting->artist);
	ps->setDouble(4, painting->price);
	
	

	
	int status = ps->executeUpdate();

	delete ps;
	return status;
}

Painting* PaintingManager::getPainting(int paintingID) {

	Painting* painting = NULL;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.preparedStatement("SELECT * FROM Paintings WHERE PaintingID=?");

	ps->setInt(1, paintingID);

	ResultSet* rs = ps->executeQuery();

	while (rs->next()) {

		painting = new Painting();

		painting->paintingID = rs->getInt(1);
		painting->name = rs->getString(2);
		painting->artist = rs->getString(3);
		painting->price = rs->getDouble(4);
	}

	delete ps;
	delete rs;

	return painting;
}

Painting* PaintingManager::getName(int paintingID) {

	Painting* painting = NULL;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.preparedStatement("SELECT Name FROM Paintings WHERE PaintingID=?");

	ps->setInt(1, paintingID);

	ResultSet* rs = ps->executeQuery();

	if (rs->next()) {
		painting = new Painting();

		painting->name = rs->getString("Name");
	}

	delete ps;
	delete rs;

	return painting;
}

Painting* PaintingManager::getID() {

	Painting* painting = NULL;

	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.preparedStatement("SELECT MAX(PaintingID) FROM Paintings");

	ResultSet* rs = ps->executeQuery();

	if(rs->next())
	painting = new Painting();

	painting->paintingID = rs->getInt(1);


	delete rs;
	delete ps;

	return painting;
}
