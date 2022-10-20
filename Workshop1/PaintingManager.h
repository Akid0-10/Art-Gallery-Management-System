#ifndef PAINTINGMANAGER_H
#define PAINTINGMANAGER_H

class PaintingManager
{
public:
	int insertPainting(Painting* painting);
	Painting* getPainting(int paintingID);
	Painting* getName(int paintingID);
	Painting* getID();
};
#endif // !PAINTINGMANAGER_H
