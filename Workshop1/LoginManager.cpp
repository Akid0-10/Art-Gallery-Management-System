#include<iostream>
#include<string>
using namespace std;

#include<mysql/jdbc.h>
using namespace sql;

#include"DatabaseConnection.h"
#include"Login.h"
#include"LoginManager.h"

Login* LoginManager::getLogin()
{
	Login* login = NULL;

	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.preparedStatement("SELECT * FROM Login");

	ResultSet* rs = ps->executeQuery();

	if (rs->next()) {

		login = new Login();

		login->email = rs->getString("Email");
		login->password = rs->getString("Password");
	
	}
	
	delete ps;
	delete rs;
	return login;
}