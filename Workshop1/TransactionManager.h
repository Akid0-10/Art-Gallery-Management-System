#ifndef TRANSACTIONMANAGER_H
#define TRANSACTIONMANAGER_H

class TransactionManager {
public:
	Transaction* getID();
	int insertTransaction(Transaction* transaction);
	Transaction* getTransaction(int transactionID);
	Transaction* getAllTransaction();
	Transaction* getSale(string first, string last);
	int getPaintingID(int paintId);
};
#endif // !TRANSACTIONMANAGER_H
