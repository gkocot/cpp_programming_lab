#ifndef _ROBBO_H
#define _ROBBO_H

#include "obiekt.h"
class robbo : public obiekt
{
	public:
	robbo(int x,int y);
	virtual void animujobiekt();
	private:
	unsigned czas;
	
};

#endif
