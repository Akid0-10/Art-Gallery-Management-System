#include<iostream>
#include<string>
using namespace std;

#include<mysql/jdbc.h>
using namespace sql;

#include "DatabaseConnection.h"
#include "Transaction.h"
#include "TransactionManager.h"

Transaction* TransactionManager::getID() {

	Transaction* transaction = NULL;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.preparedStatement("SELECT MAX(TransactionID) FROM Transactions");

	ResultSet* rs = ps->executeQuery();

	if(rs->next())
	transaction = new Transaction();
	transaction->transactionID = rs->getInt(1);

	delete rs;
	delete ps;
	return transaction;
}

int TransactionManager::insertTransaction(Transaction* transaction) {

	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.preparedStatement("INSERT INTO Transactions VALUES (?,?,?,?,?)");

	ps->setInt(1, transaction->transactionID);
	ps->setInt(2, transaction->buyerID);
	ps->setInt(3, transaction->paintingID);
	ps->setString(4, transaction->dateSell);
	ps->setDouble(5, transaction->sellPrice);

	int status = ps->executeUpdate();

	delete ps;
	return status;
}

Transaction* TransactionManager::getTransaction(int transactionID) {

	Transaction* transaction = NULL;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.preparedStatement("SELECT * FROM Transactions WHERE TransactionID=?");

	ps->setInt(1, transactionID);

	ResultSet* rs = ps->executeQuery();

	while (rs->next()) {
		transaction = new Transaction();

		transaction->transactionID = rs->getInt(1);
		transaction->buyerID = rs->getInt(2);
		transaction->paintingID = rs->getInt(3);
		transaction->dateSell = rs->getString(4);
		transaction->sellPrice = rs->getDouble(5);
	}

	delete ps;
	delete rs;

	return transaction;
}

Transaction* TransactionManager::getAllTransaction() {

	Transaction* transaction = NULL;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.preparedStatement("SELECT * FROM Transactions ORDER BY TransactionID DESC");

	ResultSet* rs = ps->executeQuery();
	int i = 0;

	while (rs->next()) {

		transaction = new Transaction();
		i++;

		cout << "\t\t" << i << ". Transaction ID: " << rs->getInt(1) << endl;
		cout << "\t\t   Buyer ID      : " << rs->getString(2) << endl;
		cout << "\t\t   Painting ID   : " << rs->getString(3) << endl;
		cout << "\t\t   Date          : " << rs->getString(4) << endl;
		cout << "\t\t   Amount paid   : RM" << rs->getDouble(5) << endl;
		cout << "\t\t------------------------------\n";
	}

	delete ps;
	delete rs;

	return transaction;
}

Transaction* TransactionManager::getSale(string first, string last) {

	Transaction* transaction = NULL;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.preparedStatement("SELECT SellPrice FROM Transactions WHERE DateOfSell BETWEEN ? AND ? ORDER BY DateOfSell ASC");

	ps->setString(1, first);
	ps->setString(2, last);


	ResultSet* rs = ps->executeQuery();
	double price = 0, amount = 0;
	int i = 0;
	
	
	while (rs->next()) {
		transaction = new Transaction();

		price = rs->getDouble("SellPrice");
		amount = amount + rs->getDouble("SellPrice");
		i++;
		cout << "\t\t" << i << ". RM" << price << endl;

	}


	cout << "\n\t\tTotal = RM" << amount;
	cout << "\n\t\tAverage sales per month = RM" << amount / 3;

	delete ps;
	delete rs;

	return transaction;
}

int TransactionManager::getPaintingID(int paintId) {

	Transaction* transaction = NULL;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.preparedStatement("SELECT PaintingID FROM Transactions WHERE PaintingID=?");
	
	ps->setInt(1, paintId);

	ResultSet* rs = ps->executeQuery();
	int status = 0;

	while (rs->next()) {
		transaction = new Transaction();
		if (paintId != rs->getInt("PaintingID")) {
			transaction->paintingID = paintId;
			status = 0;
			break;
		}
		else
			status = 1;
	}

	delete rs;
	delete ps;
	return status;
}