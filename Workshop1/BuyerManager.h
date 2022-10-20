#ifndef BUYERMANAGER_H
#define BUYERMANAGER_H

class BuyerManager {
public:
	Buyers* getID();	
	int insertBuyer(Buyers* buyers);
	int updateName(Buyers* buyers);
	int updateAddress(Buyers* buyers);
	int updatePhone(Buyers* buyers);
	Buyers* getBuyer(int buyersID);
	Buyers* displayBuyer();
	Buyers* getName(int buyersID);
};
#endif // !BUYERMANAGER_H
