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
protected:
	
	int x;
	int y;
	char Textura;	
	void move(int x,int y);
};

#endif
