#ifndef _OBIEKT_H
#define _OBIEKT_H

class obiekt
{

public:
	obiekt(int x,int y,char Textura);
	virtual void rysuj();
	virtual void animujobiekt() {}
	void czysc();
	char typobiektu();
	void ustaw_pozycje(int _x, int _y) {x = _x; y = _y; }
protected:
	
	int x;
	int y;
	char Textura;	
	void move(int x,int y);
};

#endif
