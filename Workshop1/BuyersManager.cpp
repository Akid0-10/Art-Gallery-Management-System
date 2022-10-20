#include<iostream>
#include<string>
using namespace std;

#include<mysql/jdbc.h>
using namespace sql;

#include "DatabaseConnection.h"
#include "Buyers.h"
#include "BuyerManager.h"

Buyers* BuyerManager::getID() {

	Buyers* buyer = NULL;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.preparedStatement("SELECT MAX(BuyersID) FROM Buyers");

	ResultSet* rs = ps->executeQuery();

	if (rs->next())
		buyer = new Buyers();
	buyer->buyersID = rs->getInt(1);

	delete rs;
	delete ps;
	return buyer;
}

int BuyerManager::insertBuyer(Buyers* buyers) {

	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.preparedStatement("INSERT INTO Buyers VALUES (?,?,?,?)");

	ps->setInt(1, buyers->buyersID);
	ps->setString(2, buyers->name);
	ps->setInt(3, buyers->phoneNo);
	ps->setString(4, buyers->address);

	int status = ps->executeUpdate();

	delete ps;
	return status;
}

Buyers* BuyerManager::getBuyer(int buyersID) {

	Buyers* buyers = NULL;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.preparedStatement("SELECT * FROM Buyers WHERE BuyersID=?");

	ps->setInt(1, buyersID);

	ResultSet* rs = ps->executeQuery();
	
	while (rs->next()) {
		buyers = new Buyers();

		buyers->buyersID = rs->getInt(1);
		buyers->name = rs->getString(2);
		buyers->phoneNo = rs->getInt(3);
		buyers->address = rs->getString(4);
	}

	delete ps;
	delete rs;

	return buyers;
}

int BuyerManager::updateName(Buyers* buyers) {

	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.preparedStatement("UPDATE Buyers SET Name=? WHERE BuyersID=?");

	ps->setString(1, buyers->name);
	ps->setInt(2, buyers->buyersID);

	int status = ps->executeUpdate();

	delete ps;

	return status;
}

int BuyerManager::updateAddress(Buyers* buyers) {

	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.preparedStatement("UPDATE Buyers SET Address=? WHERE BuyersID=?");

	ps->setString(1, buyers->address);
	ps->setInt(2, buyers->buyersID);

	int status = ps->executeUpdate();

	delete ps;
	return status;
}

int BuyerManager::updatePhone(Buyers* buyers) {

	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.preparedStatement("UPDATE Buyers SET PhoneNumber=? WHERE BuyersID=?");

	ps->setInt(1, buyers->phoneNo);
	ps->setInt(2, buyers->buyersID);

	int status = ps->executeUpdate();

	delete ps;
	return status;
}

Buyers* BuyerManager::displayBuyer() {

	Buyers* buyers = NULL;
	DatabaseConnection dbconn;
	PreparedStatement* ps = dbconn.preparedStatement("SELECT * FROM Buyers ORDER BY BuyersID ASC");

	ResultSet* rs = ps->executeQuery();

	while (rs->next()) {
		buyers = new Buyers();

		cout << "\t\tBuyer ID     : " << rs->getString(1) << endl;
		cout << "\t\tName         : " << rs->getString(2) << endl;
		cout << "\t\tPhone Number : 0" << rs->getInt(3) << endl;
		cout << "\t\tAddress      : " << rs->getString(4) << endl;
		cout << "\t\t------------------------------" << endl;
	}

	delete ps;
	delete rs;

	return buyers;
}

Buyers* BuyerManager::getName(int buyersID) {

	Buyers* buyers = NULL;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.preparedStatement("SELECT Name FROM Buyers WHERE BuyersID=?");

	ps->setInt(1, buyersID);

	ResultSet* rs = ps->executeQuery();

	if (rs->next()) {
		buyers = new Buyers();

		buyers->name = rs->getString("Name");
	}

	delete ps;
	delete rs;
	
	return buyers;
}