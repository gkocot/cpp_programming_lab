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
	private:
	unsigned czas;
	mapka* m;
	
	
};

#endif
