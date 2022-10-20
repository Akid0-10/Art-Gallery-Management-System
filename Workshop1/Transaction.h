#include<string>
using namespace std;

#ifndef TRANSACTION_H
#define TRANSACTION_H

class Transaction {
public:
	string  dateSell;
	double sellPrice;
	int paintingID, buyerID, transactionID;
};
#endif // !TRANSACTION_H
