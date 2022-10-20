#include<iostream>
#include<string>
using namespace std;

#include<mysql/jdbc.h>
using namespace sql;

#include "DatabaseConnection.h"
#include "Staff.h"
#include "StaffManager.h"

Staff* StaffManager::getId() {

	Staff* staff = NULL;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.preparedStatement("SELECT MAX(StaffID) FROM Staffs");

	ResultSet* rs = ps->executeQuery();

	if(rs->next())
	staff = new Staff();

	staff->staffID = rs->getInt(1);

	delete rs;
	delete ps;
	
	return staff;
}

int StaffManager::insertStaff(Staff* staff)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.preparedStatement("INSERT INTO Staffs VALUES (?,?,?,?,?)");

	ps->setInt(1, staff->staffID);
	ps->setString(2, staff->name);
	ps->setInt(3, staff->phoneNo);
	ps->setString(4, staff->address);
	ps->setDouble(5, staff->salary);

	int status = ps->executeUpdate();

	delete ps;
	return status;
}

Staff* StaffManager::getStaff(int staffID)
{
	Staff* staff = NULL;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.preparedStatement("SELECT * FROM Staffs WHERE StaffID=?");

	ps->setInt(1, staffID);

	ResultSet* rs = ps->executeQuery();

	if (rs->next()) {
		staff = new Staff();

		staff->staffID = rs->getInt(1);
		staff->name = rs->getString(2);
		staff->phoneNo = rs->getInt(3);
		staff->address = rs->getString(4);
		staff->salary = rs->getDouble(5);
	}

	delete rs;
	delete ps;

	return staff;	
}

Staff* StaffManager::displayStaff() {

	Staff* staff = NULL;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.preparedStatement("SELECT * FROM Staffs ORDER BY StaffID ASC");

	ResultSet* rs = ps->executeQuery();

	while (rs->next()) {
		staff = new Staff();


		cout << "\t\tStaff ID     : " << rs->getString(1) << endl;
		cout << "\t\tName         : " << rs->getString(2) << endl;
		cout << "\t\tPhone Number : 0" << rs->getInt(3) << endl;
		cout << "\t\tAddress      : " << rs->getString(4) << endl;
		cout << "\t\tSalary       : RM" << rs->getDouble(5) << endl;
		cout << "\t\t------------------------------\n";
	}

	delete ps;
	delete rs;

	return staff;
}

int StaffManager::updateName(Staff* staff) {

	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.preparedStatement("UPDATE Staffs SET Name=? WHERE StaffID=?");

	ps->setString(1, staff->name);
	ps->setInt(2, staff->staffID);

	int status = ps->executeUpdate();

	delete ps;

	return status;
}

int StaffManager::updateAddress(Staff* staff) {

	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.preparedStatement("UPDATE Staffs SET Address=? WHERE StaffID=?");

	ps->setString(1, staff->address);
	ps->setInt(2, staff->staffID);
	

	int status = ps->executeUpdate();

	delete ps;

	return status;
}

int StaffManager::updatePhoneNo(Staff* staff) {

	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.preparedStatement("UPDATE Staffs SET PhoneNumber=? WHERE StaffID=?");

	ps->setInt(1, staff->phoneNo);
	ps->setInt(2, staff->staffID);

	int status = ps->executeUpdate();

	delete ps;

	return status;
}

int StaffManager::updateSalary(Staff* staff) {

	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.preparedStatement("UPDATE Staffs SET Salary=? WHERE StaffID=?");

	ps->setDouble(1, staff->salary);
	ps->setInt(2, staff->staffID);

	int status = ps->executeUpdate();

	delete ps;

	return status;
}

int StaffManager::deleteStaff(Staff* staff) {

	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.preparedStatement("DELETE FROM Staffs WHERE StaffID=?");

	ps->setInt(1, staff->staffID);

	int status = ps->executeUpdate();

	delete ps;
	return status;
}