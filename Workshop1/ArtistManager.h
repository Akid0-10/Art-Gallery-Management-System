#ifndef ARTISTMANAGER_H
#define ARTISTMANAGER_H

class ArtistManager {
public:
	Artist* getID();
	int insertArtist(Artist* artist);
	int updateName(Artist* artist);
	int updateAddress(Artist* artist);
	int updatePhone(Artist* artist);
	Artist* getArtist(int artistID);
	Artist* displayArtist();
};
#endif // !ARTISTMANAGER_H
