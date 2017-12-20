#ifndef _ROBBO_H
#define _ROBBO_H

#include "obiekt.h"
#include "mapka.h"
class robbo : public obiekt
{
	public:
	robbo(int x,int y, mapka* m);
	virtual void animujobiekt();
	void czysciana();
	int p_x;
	int p_y;
	private:
	unsigned czas;
	mapka* m;
	
	
};

#endif
