#ifndef _OBIEKT_H
#define _OBIEKT_H

class obiekt
{

public:
	obiekt(int x,int y,char Textura);
	void rysuj();
	virtual void animujobiekt() {}
protected:
	
	int x;
	int y;
	char Textura;	
private:
	void move(int x,int y);
};

#endif
