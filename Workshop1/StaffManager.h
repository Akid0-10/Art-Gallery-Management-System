#ifndef STAFFMANAGER_Hs
#define STAFFMANAGER_H

class StaffManager
{
public:
	Staff* getId();
	int insertStaff(Staff* staff);
	int updateName(Staff* staff);
	int updateSalary(Staff* staff);
	int updateAddress(Staff* staff);
	int updatePhoneNo(Staff* staff);
	int deleteStaff(Staff* staff);
	Staff* getStaff(int staffID);
	Staff* displayStaff();
};
#endif // !STAFFMANAGER_H
