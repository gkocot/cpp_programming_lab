#include "obiekt.h"
#include "mapka.h"

class duszek: public obiekt
{
	public:
	duszek(int x,int y,mapka* mapa);
	virtual void animujobiekt();
	unsigned czas;
	mapka* m;
	int predkosc_x;
	int predkosc_y;
	
};
