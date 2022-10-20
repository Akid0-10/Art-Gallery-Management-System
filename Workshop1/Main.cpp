//    This is the main source files where the system is being coded and combined with its database.

#include<iostream>
#include<string>
#include<iomanip>
#include<sstream>
#include<chrono>
#include"Login.h"
#include"LoginManager.h"
#include "Staff.h"
#include "StaffManager.h"
#include "Painting.h"
#include "PaintingManager.h"
#include "Artist.h"
#include "ArtistManager.h"
#include "Buyers.h"
#include "BuyerManager.h"
#include "Transaction.h"
#include "TransactionManager.h"

using namespace std;

//All of function header for function definition that were used in this system
int menu(int o);
int loginMenuStaff(int o);
int loginMenu(int o);
int staff(int o);
int paint(int o);
int client(int o);
int addStaff(int o);
int viewStaff(int o);
int searchStaff(int o);
int updateStaff(int o, int id);
int updateName(int o, int id);
int updateAddress(int o, int id);
int updatePhone(int o, int id);
int updateSalary(int o, int id);
int deleteStaff(int o);
int addPainting(int o);
int searchPainting(int o);
int sellPainting(int o);
int receipt(int o, int t);
int totalSale(int o);
int listTransaction(int o);
int artist(int o);
int buyer(int o);
int addArtist(int o);
int searchArtist(int o);
int updateArtist(int o, int id);
int updateArtistName(int o, int id);
int updateArtistAddress(int o, int id);
int updateArtistPhone(int o, int id);
int listArtist(int o);
int addBuyer(int o);
int searchBuyer(int o);
int updateBuyer(int o, int id);
int updateBuyerName(int o, int id);
int updateBuyerAddress(int o, int id);
int updateBuyerPhone(int o, int id);
int listBuyer(int o);

//This is main function
int main() {

	//Initialize option to zero which will be user input for their choice
	int option = 0;

	//Calling the menu function with option as the parameter
	menu(option);

}

//Main menu function
int menu(int o) {

	//Display the list of choice for user to choose
	cout << "\t\t---------------------------------------"
		"\n\t\t|    Art Gallery Management System    |" << endl;
	cout << "\t\t---------------------------------------" << endl;
	cout << "\t\t1. Staff Management" << "\n\t\t2. Painting Management" << endl;
	cout << "\t\t3. Clients Management" << endl;
	cout << "\t\t4. Exit" << endl;

	//Prompt user to enter their choice based on the number
	cout << "\n\t\tPlease enter your option: ";
	cin >> o;

	//To prevent from going to new line after user input
	cout << "\033[F";

	//User option will be used as switch to proceed with the system
	switch (o) {

	//The system will take user to staff menu if their choice is 1
	case 1: {

		//Clear the console screen
		system("cls");

		//Call staff function
		loginMenuStaff(o);

		//Jump out of switch statement
		break;
	}

	//The system will take user to paint menu when they choose 2
	case 2: {
		system("cls");
		paint(o);
		break;
	}

	//The system will redirect to client menu when the input is 3
	case 3: {
		system("cls");
		client(o);
		break;
	}
	case 4: {
		exit(0);
	}

	//For the user input that did not meet any match
	default: {

		//Display their input is wrong
		cout << "\t\tWRONG INPUT!!! Please try again...\n\t\t";

		//Pause the screen and wait for user key press to continue
		system("pause");
		system("cls");

		//Call the menu function which will prompt user to make their input again
		menu(o);
	}
	}

	//Return the o value
	return o;
}
//This is login menu for manager when accessing the staff section
int loginMenuStaff(int o) {

	string emails, passwords, pass;

	//Since the staff information is condfidential, it can only be accessed by manager through login process.

	cout << "\t\tRESTRICTED ACCESS ONLY FOR MANAGER" << endl;
	cout << "\t\tPlease enter the Login Details...." << endl;
	cout << "\n\t\tEmail: ";
	cin >> emails;
	cout << "\t\tPassword: ";
	cin >> passwords;

	//Get the login information from database
	LoginManager loginManager;
	Login* login = loginManager.getLogin();

	//Validate the login process. The staff section can be accessed only when the email and password matched with the database one.
	if ((emails == login->email) && (passwords == login->password)) {     //Both emails and password matched
		system("cls");
		staff(0);
	}
	else if ((emails == login->email) && (passwords != login->password)) {   //Only emails matched
		cout << "\n\n\t\tIncorrect password!!!. Please try again\n\t\t";
		system("pause");
		system("cls");
		loginMenuStaff(0);
	}
	else if ((emails != login->email) && (passwords != login->password)) {     //Both emails and password are wrong
		cout << "\n\n\t\tWrong emails and password!!! Make sure the emails is correct\n\t\t";
		system("pause");
		system("cls");
		loginMenuStaff(0);
	}
	else {
		cout << "\n\n\t\tWrong emails and password!!! Make sure the emails is correct\n\t\t";
		system("pause");
		system("cls");
		loginMenuStaff(0);
	}
}

int loginMenu(int o) {

	string emails, passwords, pass;

	//Since the staff information is condfidential, it can only be accessed by manager through login process.

	cout << "\t\tRESTRICTED ACCESS ONLY FOR MANAGER" << endl;
	cout << "\t\tPlease enter the Login Details...." << endl;
	cout << "\n\t\tEmail: ";
	cin >> emails;
	cout << "\t\tPassword: ";
	cin >> passwords;

	//Get the login information from database
	LoginManager loginManager;
	Login* login = loginManager.getLogin();

	//Validate the login process. The staff section can be accessed only when the email and password matched with the database one.
	if ((emails == login->email) && (passwords == login->password)) {     //Both emails and password matched
		system("cls");
		if (o == 0)
			totalSale(0);
		else if (o == 1)
			listTransaction(0);
	}
	else if ((emails == login->email) && (passwords != login->password)) {   //Only emaills matched
		cout << "\n\n\t\tIncorrect password!!!. Please try again\n\t\t";
		system("pause");
		system("cls");
		loginMenuStaff(0);
	}
	else if ((emails != login->email) && (passwords != login->password)) {     //Both emails and password are wrong
		cout << "\n\n\t\tWrong emails and password!!! Make sure the emails is correct\n\t\t";
		system("pause");
		system("cls");
		loginMenuStaff(0);
	}
}

//Staff menu function
int staff(int o) {

	int id = 0;

	//Display the staff menu
	cout << "\t\t----------------------------\n\t\t|      Staff Management    |" << endl;
	cout << "\t\t----------------------------" << endl;
	cout << "\t\t1. Add Staff" << endl;
	cout << "\t\t2. View Staff Information" << endl;
	cout << "\t\t3. Search Staff\n\t\t4. Update Staff" << endl;
	cout << "\t\t5. Delete Staff\n\t\t6. Return to main menu" << endl;

	//Prompt user to input their option
	cout << "\n\t\tPlease enter your option: ";
	cin >> o;

	//Stay in the same line after the user input
	cout << "\033[F";

	//Switch statement that will be executed based on user option
	switch (o) {

	//User input 1
	case 1: {

		//Clear the console screen
		system("cls");

		//Calling function addStaff
		addStaff(o);

		//Jump out of switch statement
		break;
	}
	case 2: {
		system("cls");
		viewStaff(o);
		break;
	}
	case 3: {
		system("cls");
		searchStaff(o);
		break;
	}
	case 4: {
		system("cls");
		cout << "\t\t------------------------" << endl;
		cout << "\t\t|    Staff Updating    |" << endl;
		cout << "\t\t------------------------" << endl;
		cout << "\t\tStaff ID for the update: ";
		cin >> id;
		updateStaff(o, id);
		break;
	}
	case 5: {
		system("cls");
		deleteStaff(o);
		break;
	}
	case 6: {
		system("cls");
		menu(o);
		break;
	}

	//User wrong input that does not match any case
	default: {

		//Display that their input is wrong
		cout << "\t\tWRONG INPUT!!! Please try again...\n\t\t";

		//Pause the system and wait for user key press to continue
		system("pause");
		system("cls");

		//Calling staff function for user to make their input again
		staff(o);
	}
	}

	//Return o value
	return o;
}

//Menu for the painting
int paint(int o) {

	//Display the menu for paint
	cout << "\t\t--------------------------" << endl;
	cout << "\t\t|   Painting Management  |" << endl;
	cout << "\t\t--------------------------" << endl;
	cout << "\t\t1. Add painting" << endl;
	cout << "\t\t2. Search Painting\n\t\t3. Sell Painting" << endl;
	cout << "\t\t4. Total sales\n\t\t5. List of Transaction" << endl;
	cout << "\t\t6. Return to main menu" << endl;

	//Prompt for the user input
	cout << "\n\t\tPlease enter your option: ";
	cin >> o;

	//Go back to the input line after the user input
	cout << "\033[F";

	//Switch statement using user option to select case to be executed
	switch (o) {

	//User input is 1
	case 1: {

		//Clear the console screen
		system("cls");

		//Call the addPainting function
		addPainting(o);

		//Jump out of switch statement
		break;
	}

	//User input is 2
	case 2: {
		system("cls");
		searchPainting(o);
		break;
	}
	case 3: {
		system("cls");
		sellPainting(o);
		break;
	}
	case 4: {
		system("cls");
		loginMenu(0);
		break;
	}
	case 5: {
		system("cls");
		loginMenu(1);
	}
	case 6: {
		system("cls");
		menu(o);
		break;
	}

	//User input is wrong and did not match any case
	default: {

		//Display that their input is wrong
		cout << "\t\tWRONG INPUT!!! Please try again...\n\t\t";

		//Pause the system and wait for user key press to continue
		system("pause");
		system("cls");

		//Call the paint function for user to make their input again
		paint(o);
	}
	}

	//Return o value
	return o;
}

//Client menu
int client(int o) {

	//Display the menu 
	cout << "\t\t---------------------------"
		"\n\t\t|    Client Management    |" << endl;
	cout << "\t\t---------------------------" << endl;
	cout << "\t\t1. Artist Information" << endl;
	cout << "\t\t2. Buyers Information" << endl;
	cout << "\t\t3. Return to main menu" << endl;

	//Prompt user to input
	cout << "\n\t\tPlease enter your option: ";
	cin >> o;

	//Go back to the input line after input is made
	cout << "\033[F";

	//Switch statement using user input to determine which case to be execute
	switch (o) {

	//User input is 1
	case 1: {

		//Clear the console screen
		system("cls");

		//Call the artist function
		artist(o);

		//Jump out of switch statement
		break;
	}

	//User input is 2
	case 2: {
		system("cls");
		buyer(o);
		break;
	}
	case 3: {
		system("cls");
		menu(o);
		break;
	}

	//User input did not match any of the case
	default: {

		//Display that user input is wrong
		cout << "\t\tWRONG INPUT!!! Please try again...\n\t\t";

		//Pause the system and wait for user key press to continue
		system("pause");
		system("cls");

		//Call the client function for the user to redo the input
		client(o);
	}
	}

	//Return the o value
	return o;
}

//This function will add the staff to mySql database
int addStaff(int o) {

	StaffManager staffManager;
	int staffId = 100;

	cout << "\t\t-----------------------" << endl;
	cout << "\t\t|      New Staff      |" << endl;
	cout << "\t\t-----------------------" << endl;

	Staff* stafff = staffManager.getId();

	if (stafff->staffID != NULL ) {
		staffId = stafff->staffID;
		staffId++;
	}
	else
		staffId = 100;

	Staff* staffs = new Staff();
	
	staffs->staffID = staffId;
	cout << "\t\tName         : ";
	cin.ignore();
	getline(cin, staffs->name);
	cout << "\t\tPhone Number : ";
	cin >> staffs->phoneNo;
	cout << "\t\tAddress      : ";
	cin.ignore();
	getline(cin, staffs->address);
	cout << "\t\tSalary       : RM";
	cin >> staffs->salary;

	int status = staffManager.insertStaff(staffs);

	if (status != 0)
		cout << "\n\t\tSuccess" << endl;
	else
		cout << "\n\t\tFail" << endl;


	cout << "\n\t\tAdd more staff (Yes=1/No=0) : ";
	cin >> o;

	switch (o) {
	case 1: {
		system("cls");
		addStaff(o);
		break;
	}
	case 0: {
		system("cls");
		staff(o);
		break;
	}
	}

	return o;
}

int viewStaff(int o) {

	StaffManager staffManager;

	cout << "\t\t------------------------------\n\t\t|       Staff's Registry     |" << endl;
	cout << "\t\t------------------------------" << endl;

	Staff* staffs = staffManager.displayStaff();

	cout << "\n\t\t";
	system("pause");
	system("cls");
	staff(o);

	return 0;
}

int searchStaff(int o) {

	int id;

	cout << "\t\t-----------------------------" << endl;
	cout << "\t\t|     Staff Search by ID    |" << endl;
	cout << "\t\t-----------------------------" << endl;
	cout << "\t\tStaff ID: ";
	cin >> id;

	StaffManager staffManager;
	Staff* staffs = staffManager.getStaff(id);

	system("cls");
	cout << "\t\t------------------------\n\t\t|      Staff Detail    |" << endl;
	cout << "\t\t------------------------" << endl;
	cout << "\t\tStaff ID     : " << staffs->staffID << endl;
	cout << "\t\tName         : " << staffs->name << endl;
	cout << "\t\tPhone Number : 0" << staffs->phoneNo << endl;
	cout << "\t\tAddress      : " << staffs->address << endl;
	cout << "\t\tSalary       : RM" << staffs->salary << endl;

	cout << "\n\t\tContinue search (YES=1, N0=0) : ";
	cin >> o;
	cout << "\033[F";

	switch (o) {
	case 0: {
		system("cls");
		staff(o);
		break;
	}
	case 1: {
		system("cls");
		searchStaff(o);
		break;
	}
	}
	return o;
}

int updateStaff(int o, int id) {

	system("cls");
	cout << "\t\t----------------------------" << endl;
	cout << "\t\t|     Update Selection     |" << endl;
	cout << "\t\t----------------------------" << endl;

	cout << "\t\t1. Name\n\t\t2. Phone Number" << endl;
	cout << "\t\t3. Address\n\t\t4. Salary" << endl;
	cout << "\t\t5. Return to Staff" << endl;

	cout << "\n\t\tPlease enter your option: ";
	cin >> o;
	cout << "\033[F";

	switch (o) {
	case 1: {
		system("cls");
		updateName(o, id);
		break;
	}
	case 2: {
		system("cls");
		updatePhone(o, id);
		break;
	}
	case 3: {
		system("cls");
		updateAddress(o, id);
		break;
	}
	case 4: {
		system("cls");
		updateSalary(o, id);
		break;
	}
	case 5: {
		system("cls");
		staff(o);
	}
	default: {
		cout << "\t\tWRONG INPUT!!! Please try again...\n\t\t";
		system("pause");
		system("cls");
		updateStaff(o, id);
	}
	}

	return o;
}

int updateName(int o, int id){

	Staff* update = new Staff();

	cout << "\t\t-------------------------" << endl;
	cout << "\t\t|      Update Name      |" << endl;
	cout << "\t\t------------------------" << endl;

	update->staffID = id;

	cout << "\t\tNew Name: ";
	cin.ignore();
	getline(cin, update->name);

	StaffManager staffManager;
	int status = staffManager.updateName(update);

	if (status != 0)
		cout << "\n\t\tSuccess" << endl;
	else
		cout << "\n\t\tFail" << endl;

	cout << "\n\t\t";
	system("pause");
	system("cls");
	updateStaff(o, id);

	return o;
}

int updatePhone(int o, int id) {

	Staff* update = new Staff();

	cout << "\t\t---------------------------" << endl;
	cout << "\t\t|   Update Phone Number   |" << endl;
	cout << "\t\t---------------------------" << endl;

	update->staffID = id;

	cout << "\t\tNew Phone Number : ";
	cin.ignore();
	cin >> update->phoneNo;

	StaffManager staffManager;
	int status = staffManager.updatePhoneNo(update);

	if (status != 0)
		cout << "\n\t\tSuccess" << endl;
	else
		cout << "\n\t\tFail" << endl;

	cout << "\t\t";
	system("pause");
	system("cls");
	updateStaff(o, id);

	return 0;
}

int updateAddress(int o, int id) {

	Staff* update = new Staff();

	cout << "\t\t--------------------------" << endl;
	cout << "\t\t|     Update Address     |" << endl;
	cout << "\t\t--------------------------" << endl;

	update->staffID = id;

	cout << "\t\tNew Address : ";
	cin.ignore();
	getline(cin, update->address);

	StaffManager staffManager;
	int status = staffManager.updateAddress(update);

	if (status != 0)
		cout << "\n\t\tSuccess" << endl;
	else
		cout << "\n\t\tFail" << endl;

	cout << "\n\t\t";
	system("pause");
	system("cls");
	updateStaff(o, id);

	return 0;
}

int updateSalary(int o, int id){

	Staff* update = new Staff();

	cout << "\t\t-------------------------" << endl;
	cout << "\t\t|     Update Salary     |" << endl;
	cout << "\t\t-------------------------" << endl;

	update->staffID = id;

	cout << "\t\tNew Salary: RM";
	cin.ignore();
	cin >> update->salary;

	StaffManager staffManager;
	int status = staffManager.updateSalary(update);

	if (status != 0)
		cout << "\n\t\tSuccess" << endl;
	else
		cout << "\n\t\tFail" << endl;

	cout << "\n\t\t";
	system("pause");
	system("cls");
	updateStaff(o, id);

	return o;
}

int deleteStaff(int o) {
	
	Staff* remove = new Staff();

	cout << "\t\t----------------------------" << endl;
	cout << "\t\t|      Staff Deletion      |" << endl;
	cout << "\t\t----------------------------" << endl;

	cout << "\t\tStaff ID: ";
	cin >> remove->staffID;

	StaffManager staffManager;
	int status = staffManager.deleteStaff(remove);

	if (status != 0)
		cout << "\n\t\tSuccess" << endl;
	else
		cout << "\n\t\tFail" << endl;

	cout << "\t\t";
	system("pause");
	system("cls");
	staff(o);

	return o;
}

int addPainting(int o) {

	PaintingManager paintingManager;

	cout << "\t\t----------------------------" << endl;
	cout << "\t\t|     Add New Painting     |" << endl;
	cout << "\t\t----------------------------" << endl;


	int paintId = 100;

	Painting* paintings = paintingManager.getID();

	if (paintings->paintingID != NULL) {
		paintId = paintings->paintingID;
		paintId++;
	}
	else
		paintId = 100;

	Painting* painting = new Painting();

	painting->paintingID = paintId;

	
	cout << "\t\tName        : ";
	cin.ignore();
	getline(cin, painting->name);
	cout << "\t\tArtist      : ";
	getline(cin, painting->artist);
	cout << "\t\tPrice       : RM";
	cin >> painting->price;
	
	int status = paintingManager.insertPainting(painting);
	if (status != 0)
		cout << "\n\t\tSuccess" << endl;
	else
		cout << "\n\t\tFail" << endl;

	cout << "\n\t\tAdd more painting (Yes=1/No=0) : ";
	cin >> o;

	switch (o) {
	case 1: {
		system("cls");
		addPainting(o);
		break;
	}
	case 0: {
		system("cls");
		paint(o);
		break;
	}
	}

	return o;
}

int searchPainting(int o) {

	int id = 0;
	
	cout << "\t\t-----------------------------" << endl;
	cout << "\t\t|   Search Painting by ID   |" << endl;
	cout << "\t\t-----------------------------" << endl;

	cout << "\t\tPainting ID: ";
	cin >> id;

	PaintingManager paintingManager;
	Painting* painting = paintingManager.getPainting(id);

	system("cls");
	cout << "\t\t-------------------------\n\t\t|    Painting Detail    |" << endl;
	cout << "\t\t-------------------------" << endl;
	cout << "\t\tPainting ID : " << painting->paintingID << endl;
	cout << "\t\tName        : " << painting->name << endl;
	cout << "\t\tArtist      : " << painting->artist << endl;
	cout << "\t\tPrice       : RM" << painting->price << endl;

	cout << "\n\t\tContinue searching? (YES=1, NO=0) : ";
	cin >> o;
	cout << "\033[F";

	switch (o) {
	case 0: {
		system("cls");
		paint(o);
		break;
	}
	case 1: {
		system("cls");
		searchPainting(o);
		break;
	}
	}
	return o;
}

int sellPainting(int o) {

	TransactionManager transactionManager;
	int id = 0, paintId = 0;
	string buyerId = "", paintingId = "";

	cout << "\t\t---------------------------" << endl;
	cout << "\t\t|      Sell Painting      |" << endl;
	cout << "\t\t---------------------------" << endl;

	Transaction* transaction = transactionManager.getID();

	if (transaction->transactionID != NULL) {
		id = transaction->transactionID;
		id++;
	}
	else
		id = 1000;
	
	Transaction* transactions = new Transaction();
	transactions->transactionID = id;
	int t = transactions->transactionID;
	cout << "\t\tBuyer ID          : ";
	cin.ignore();
	getline(cin, buyerId);
	stringstream conv(buyerId);
	conv >> transactions->buyerID;
	cout << "\t\tPainting ID       : ";
	cin >> paintId;
	int stat = transactionManager.getPaintingID(paintId);
	if (stat > 0) {
		cout << "\n\t\tThis painting is already sold\n\t\t";
		system("pause");
		system("cls");
		sellPainting(0);
	}
	
	transactions->paintingID = paintId;
	cout << "\t\tDate (YYYY-MM-DD) : ";
	cin.ignore();
	getline(cin, transactions->dateSell);
	cout << "\t\tSell Price        : RM";
	cin >> transactions->sellPrice;

	int status = transactionManager.insertTransaction(transactions);

	if (status != 0)
		cout << "\n\t\tSuccess" << endl;
	else
		cout << "\n\t\tFail" << endl;

	cout << "\n\t\tMore Transactions (YES=1, NO=0) : ";
	cin >> o;

	switch (o) {
	case 0: {
		system("cls");
		receipt(o, t);
		break;
	}
	case 1: {
		system("cls");
		receipt(o, t);
		system("pause");
		system("cls");
		sellPainting(o);
		break;
	}
	}

	return o;
}

int receipt(int o, int t) {
	
	TransactionManager transactionManager;
	Transaction* transaction = transactionManager.getTransaction(t);

	cout << "\t\t-------------------------------\n\t\t"
		"|         AG Art Gallery      |" << endl;
	cout << "\t\t-------------------------------" << endl;
	cout << "\t\tTransaction ID : " << transaction->transactionID << endl;
	cout << "\t\tBuyer ID       : " << transaction->buyerID << endl;

	int id = transaction->buyerID;
	BuyerManager buyerManager;
	Buyers* buyer = buyerManager.getName(id);

	cout << "\t\tName           : " << buyer->name << endl;
	cout << "\t\tPainting ID    : " << transaction->paintingID << endl;

	int id1 = transaction->paintingID;
	PaintingManager paintingManager;
	Painting* painting = paintingManager.getName(id1);

	cout << "\t\tPainting Name  : " << painting->name << endl;
	cout << "\t\tDate           : " << transaction->dateSell << endl;
	cout << "\t\tPrice          : RM" << transaction->sellPrice << endl;
	cout << "\t\t-------------------------------" << endl;
	cout << "\t\t  Thank you for your purchase\n"
		"\t\t        HAVE A GOOD DAY" << endl;
	cout << "\t\t-------------------------------" << endl;
	cout << "\n\t\t";

	if (o == 0) {
		system("pause");
		system("cls");
		paint(o);
	}

	return o;
}

int totalSale(int o) {

	string first = "", last = "";
	int option;
	TransactionManager transactionManager;

	cout << "\t\t-------------------------------------------------------\n\t\t";
	cout << "|        Total Sales Based on Quarter Of The 2022     |" << endl;
	cout << "\t\t-------------------------------------------------------" << endl;
	cout << "\t\t1. First Quarter(Q1): \n\t\t2. Second Quarter(Q2):" << endl;
	cout << "\t\t3. Third Quarter(Q3): \n\t\t4. Fourth Quarter(Q4): " << endl;
	cout << "\n\t\tPlease enter your option: ";
	cin >> option;

	switch (option) {

	case 1: {
		first = "2022-01-01";
		last = "2022-03-31";
		system("cls");
		cout << "\t\t|       Total Sales Q1 "
			<< first << " to " << last << "    |" << endl;
		Transaction* transaction = transactionManager.getSale(first, last);
		break;
	}
	case 2: {
		first = "2020-04-01";
		last = "2020-06-30";
		system("cls");
		cout << "\t\t|       Total Sales Q2 "
			<< first << " to " << last << "    |" << endl;
		Transaction* transaction = transactionManager.getSale(first, last);
		break;
	}
	case 3: {
		first = "2022-07-01";
		last = "2022-09-30";
		system("cls");
		cout << "\t\t|       Total Sales Q3 "
			<< first << " to " << last << "    |" << endl;
		Transaction* transaction = transactionManager.getSale(first, last);
	}
	case 4: {
		first = "2022-10-01";
		last = "2022-12-31";
		system("cls");
		cout << "\t\t|       Total Sales Q4 "
			<< first << " to " << last << "    |" << endl;
		Transaction* transaction = transactionManager.getSale(first, last);
		break;
	}
	default: {
		cout << "\n\t\tWRONG INPUT!!! Please Try Again...\n\t\t";
		system("pause");
		system("cls");
		totalSale(0);
	}
	}


	cout << "\n\t\t";
	system("pause");
	system("cls");
	paint(o);
	return o;
}

int listTransaction(int o) {

	TransactionManager transactionManager;

	cout << "\t\t------------------------------\n"
		"\t\t|  List of All Transactions  |" << endl;
	cout << "\t\t------------------------------" << endl;

	Transaction* transaction = transactionManager.getAllTransaction();
	
	cout << "\n\t\t";
	system("pause");
	system("cls");
	paint(o);

	return o;
}

int artist(int o) {

	int id = 0;

	cout << "\t\t----------------------\n\t\t|\tArtist\t     |" << endl;
	cout << "\t\t----------------------" << endl;
	cout << "\t\t1. Add Artist" << endl;
	cout << "\t\t2. Search Artist\n\t\t3. Update Artist" << endl;
	cout << "\t\t4. List of Artist\n\t\t5. Return to client" << endl;
	cout << "\n\t\tPlease enter your option: ";
	cin >> o;
	cout << "\033[F";

	switch (o) {
	case 1: {
		system("cls");
		addArtist(o);
		break;
	}
	case 2: {
		system("cls");
		searchArtist(o);
		break;
	}
	case 3: {
		system("cls");
		cout << "\t\t-------------------------" << endl;
		cout << "\t\t|    Artist Updating    |" << endl;
		cout << "\t\t-------------------------" << endl;
		cout << "\t\tArtist ID for the update: ";
		cin >> id;
		updateArtist(o, id);
		break;
	}
	case 4: {
		system("cls");
		listArtist(o);
		break;
	}
	case 5: {
		system("cls");
		client(o);
		break;
	}
	default: {
		cout << "\t\tWRONG INPUT!!! Please try again...\n\t\t";
		system("pause");
		system("cls");
		artist(o);
	}
	}

	return o;
}

int buyer(int o) {

	int id = 0;

	cout << "\t\t----------------------\n\t\t|        Buyer       |" << endl;
	cout << "\t\t----------------------" << endl;
	cout << "\t\t1. Add buyer" << endl;
	cout << "\t\t2. Search buyer\n\t\t3. Update Buyer" << endl;
	cout << "\t\t4. List of Buyers\n\t\t5. Return to client" << endl;
	cout << "\n\t\tPlease enter your option: ";
	cin >> o;
	cout << "\033[F";

	switch (o) {
	case 1: {
		system("cls");
		addBuyer(o);
		break;
	}
	case  2: {
		system("cls");
		searchBuyer(o);
		break;
	}
	case 3: {
		system("cls");
		cout << "\t\t------------------------" << endl;
		cout << "\t\t|    Buyer Updating    |" << endl;
		cout << "\t\t------------------------" << endl;
		cout << "\t\tBuyer ID for the update: ";
		cin >> id;
		updateBuyer(o, id);
		break;
	}
	case 4: {
		system("cls");
		listBuyer(o);
		break;
	}
	case 5: {
		system("cls");
		client(o);
		break;
	}
	default: {
		cout << "\t\tWRONG INPUT!!! Please try again...\n\t\t";
		system("pause");
		system("cls");
		buyer(o);
	}
	}

	return o;
}

int addArtist(int o) {

	ArtistManager artistManager;
	int id = 0;

	cout << "\t\t----------------------" << endl;
	cout << "\t\t|     Add Artist     |" << endl;
	cout << "\t\t----------------------" << endl;

	Artist* artist1 = artistManager.getID();

	if (artist1->artistID != NULL) {
		id = artist1->artistID;
		id++;
	}
	else
		id = 100;

	Artist* artists = new Artist();

	artists->artistID = id;
	cout << "\t\tName         : ";
	cin.ignore();
	getline(cin, artists->name);
	cout << "\t\tPhone Number : ";
	cin.ignore();
	cin >> artists->phoneNo;
	cout << "\t\tAddress      : ";
	cin.ignore();
	getline(cin, artists->address);

	int status = artistManager.insertArtist(artists);
	if (status != 0)
		cout << "\n\t\tSuccess" << endl;
	else
		cout << "\n\t\tFail" << endl;

	cout << "\n\t\tAdd more artist (YES=1, NO=0): ";
	cin >> o;
	switch (o) {
	case 1: {
		system("cls");
		addArtist(o);
		break;
	}
	case 0: {
		system("cls");
		artist(o);
		break;
	}
	}
	
	return o;
}

int searchArtist(int o) {

	int id = 0;

	cout << "\t\t---------------------------" << endl;
	cout << "\t\t|   Search Artist by ID   |" << endl;
	cout << "\t\t---------------------------" << endl;

	cout << "\t\tArtist ID: ";
	cin >> id;

	ArtistManager artistManager;
	Artist* artists = artistManager.getArtist(id);

	system("cls");
	cout << "\t\t------------------------\n\t\t|      Artist Detail   |" << endl;
	cout << "\t\t------------------------" << endl;
	cout << "\t\tArtist ID    : " << artists->artistID << endl;
	cout << "\t\tName         : " << artists->name << endl;
	cout << "\t\tPhone Number : 0" << artists->phoneNo << endl;
	cout << "\t\tAddress      : " << artists->address << endl;

	cout << "\n\t\tContinue search (YES=1, N0=0) : ";
	cin >> o;
	cout << "\033[F";

	switch (o) {
	case 0: {
		system("cls");
		artist(o);
		break;
	}
	case 1: {
		system("cls");
		searchArtist(o);
		break;
	}
	}

	return o;
}

int updateArtist(int o, int id) {

	system("cls");
	cout << "\t\t----------------------------" << endl;
	cout << "\t\t|     Update Selection     |" << endl;
	cout << "\t\t----------------------------" << endl;

	cout << "\t\t1. Name\n\t\t2. Phone Number" << endl;
	cout << "\t\t3. Address\n\t\t4. Return to artist" << endl;

	cout << "\n\t\tPlease enter your option: ";
	cin >> o;
	cout << "\033[F";

	switch (o) {
	case 1: {
		system("cls");
		updateArtistName(o, id);
		break;
	}
	case 2: {
		system("cls");
		updateArtistPhone(o, id);
		break;
	}
	case 3: {
		system("cls");
		updateArtistAddress(o, id);
		break;
	}
	case 4: {
		system("cls");
		artist(o);
		break;
	}
	default: {
		cout << "\t\tWRONG INPUT!!! Please try again...\n\t\t";
		system("pause");
		system("cls");
		updateArtist(o, id);
	}
	}

	return o;
}

int updateArtistName(int o, int id) {

	Artist* update = new Artist();

	cout << "\t\t-----------------------" << endl;
	cout << "\t\t|     Update Name     |" << endl;
	cout << "\t\t-----------------------" << endl;
	
	update->artistID = id;
	
	cout << "\t\tNew Name: ";
	cin.ignore();
	getline(cin, update->name);

	ArtistManager artistManager;
	int status = artistManager.updateName(update);

	if (status != 0)
		cout << "\n\t\tSuccess" << endl;
	else
		cout << "\n\t\tFail" << endl;

	cout << "\n\t\t";
	system("pause");
	system("cls");
	updateArtist(o, id);

	return o;
}

int updateArtistAddress(int o, int id) {

	Artist* update = new Artist();

	cout << "\t\t--------------------------" << endl;
	cout << "\t\t|     Update Address     |" << endl;
	cout << "\t\t--------------------------" << endl;

	update->artistID = id;

	cout << "\t\tNew Address: ";
	cin.ignore();
	getline(cin, update->address);

	ArtistManager artistManager;
	int status = artistManager.updateAddress(update);

	if (status != 0)
		cout << "\n\t\tSuccess" << endl;
	else
		cout << "\n\t\tFail" << endl;

	cout << "\t\t";
	system("pause");
	system("cls");
	updateArtist(o, id);

	return o;
}

int updateArtistPhone(int o, int id) {

	Artist* update = new Artist();

	cout << "\t\t-------------------------------" << endl;
	cout << "\t\t|     Update Phone Number     |" << endl;
	cout << "\t\t-------------------------------" << endl;

	update->artistID = id;

	cout << "\t\tNew Phone Number: ";
	cin.ignore();
	cin >> update->phoneNo;

	ArtistManager artistManager;
	int status = artistManager.updatePhone(update);

	if (status != 0)
		cout << "\n\t\tSuccess" << endl;
	else
		cout << "\n\t\tFail" << endl;

	cout << "\t\t";
	system("pause");
	system("cls");
	updateArtist(o, id);

	return o;
}

int listArtist(int o) {

	ArtistManager artistManager;

	cout << "\t\t------------------------------\n\t\t|        List of Artist      |" << endl;
	cout << "\t\t------------------------------" << endl;

	Artist* artists = artistManager.displayArtist();

	cout << "\n\t\t";
	system("pause");
	system("cls");
	artist(o);

	return o;
}

int addBuyer(int o) {
	
	BuyerManager buyerManager;
	int id = 0;

	cout << "\t\t-----------------------" << endl;
	cout << "\t\t|      New Buyer      |" << endl;
	cout << "\t\t-----------------------" << endl;

	Buyers* buyer1 = buyerManager.getID();

	if (buyer1->buyersID != NULL) {
		id = buyer1->buyersID;
		id++;
	}
	else
		id = 1000;

	Buyers* buyers = new Buyers();
	buyers->buyersID = id;
	cout << "\t\tName         : ";
	cin.ignore();
	getline(cin, buyers->name);
	cout << "\t\tPhone Number : ";
	cin.ignore();
	cin >> buyers->phoneNo;
	cout << "\t\tAddress      : ";
	cin.ignore();
	getline(cin, buyers->address);


	int status = buyerManager.insertBuyer(buyers);

	if (status != 0)
		cout << "\n\t\tSuccess" << endl;
	else
		cout << "\n\t\tFail" << endl;

	cout << "\n\t\tAdd another buyer (YES=1, NO=0): ";
	cin >> o;

	switch (o) {
	case 0: {
		system("cls");
		buyer(o);
		break;
	}
	case 1: {
		system("cls");
		addBuyer(o);
		break;
	}
	}

	return o;
}

int searchBuyer(int o) {

	int id = 0;

	cout << "\t\t----------------------------" << endl;
	cout << "\t\t|    Search Buyer by ID    |" << endl;
	cout << "\t\t----------------------------" << endl;

	cout << "\t\tBuyer ID: ";
	cin >> id;

	BuyerManager buyerManager;
	Buyers* buyers = buyerManager.getBuyer(id);

	system("cls");

	cout << "\t\t------------------------\n\t\t|     Buyer Detail     |" << endl;
	cout << "\t\t------------------------" << endl;
	cout << "\t\tBuyer ID     : " << buyers->buyersID << endl;
	cout << "\t\tName         : " << buyers->name << endl;
	cout << "\t\tPhone Number : 0" << buyers->phoneNo << endl;
	cout << "\t\tAddress      : " << buyers->address << endl;

	cout << "\n\t\tContinue Searching? (YES=1, NO=0) : ";
	cin >> o;

	switch (o) {
	case 0: {
		system("cls");
		buyer(o);
		break;
	}
	case 1: {
		system("cls");
		searchBuyer(o);
		break;
	}
	}
	return 0;
}

int updateBuyer(int o, int id) {

	system("cls");
	cout << "\t\t----------------------------" << endl;
	cout << "\t\t|     Update Selection     |" << endl;
	cout << "\t\t----------------------------" << endl;

	cout << "\t\t1. Name\n\t\t2. Phone Number" << endl;
	cout << "\t\t3. Address\n\t\t4. Return to Buyer" << endl;

	cout << "\n\t\tPlease enter your option: ";
	cin >> o;
	cout << "\033[F";

	switch (o) {
	case 1: {
		system("cls");
		updateBuyerName(o, id);
		break;
	}
	case 2: {
		system("cls");
		updateBuyerPhone(o, id);
		break;
	}
	case 3: {
		system("cls");
		updateBuyerAddress(o, id);
		break;
	}
	case 4: {
		system("cls");
		buyer(o);
		break;
	}
	default: {
		cout << "\t\tWRONG INPUT!!! Please try again...\n\t\t";
		system("pause");
		system("cls");
		updateBuyer(o, id);
	}
	}

	return o;
}

int updateBuyerName(int o, int id) {

	Buyers* update = new Buyers();

	cout << "\t\t-----------------------" << endl;
	cout << "\t\t|     Update Name     |" << endl;
	cout << "\t\t-----------------------" << endl;

	update->buyersID = id;

	cout << "\t\tNew Name: ";
	cin.ignore();
	getline(cin, update->name);

	BuyerManager buyerManager;
	int status = buyerManager.updateName(update);

	if (status != 0)
		cout << "\n\t\tSuccess" << endl;
	else
		cout << "\n\t\tFail" << endl;

	cout << "\n\t\t";
	system("pause");
	system("cls");
	updateBuyer(o, id);

	return o;
}

int updateBuyerAddress(int o, int id) {

	Buyers* update = new Buyers();

	cout << "\t\t----------------------" << endl;
	cout << "\t\t|   Address Update   |" << endl;
	cout << "\t\t----------------------" << endl;

	update->buyersID = id;

	cout << "\t\tNew Address: ";
	cin.ignore();
	getline(cin, update->address);

	BuyerManager buyerManager;
	int status = buyerManager.updateAddress(update);

	if (status != 0)
		cout << "\n\t\tSuccess" << endl;
	else
		cout << "\n\t\tFail" << endl;

	cout << "\n\t\t";
	system("pause");
	system("cls");
	updateBuyer(o, id);

	return o;
}

int updateBuyerPhone(int o, int id) {

	Buyers* update = new Buyers();

	cout << "\t\t-----------------------------" << endl;
	cout << "\t\t|    Phone Number Update    |" << endl;
	cout << "\t\t-----------------------------" << endl;

	update->buyersID = id;

	cout << "\t\tNew Phone Number: ";
	cin.ignore();
	cin >> update->phoneNo;

	BuyerManager buyerManager;
	int status = buyerManager.updatePhone(update);

	if (status != 0)
		cout << "\n\t\tSuccess" << endl;
	else
		cout << "\n\t\tFail" << endl;

	cout << "\n\t\t";
	system("pause");
	system("cls");
	updateBuyer(o, id);

	return o;
}

int listBuyer(int o) {
	BuyerManager buyerManager;

	cout << "\t\t------------------------------\n\t\t|        List of Buyers      |" << endl;
	cout << "\t\t------------------------------" << endl;

	Buyers* buyers = buyerManager.displayBuyer();

	cout << "\n\t\t";
	system("pause");
	system("cls");
	buyer(o);

	return o;
}
