#include "obiekt.h"

class wyniki : public obiekt
{
	public:
	wyniki(int srubki,int klucze,int zycia,int x , int y);
int srubki;
int klucze;
int zycia;
const static int wysokosc_tablicy = 1;
virtual void rysuj();
	
};
