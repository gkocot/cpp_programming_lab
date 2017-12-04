#ifndef _MAPKA_H
#define _MAPKA_H

#include "obiekt.h"


class mapka {
public:
	mapka() : LiczbaKolumn(0),LiczbaWierszy(0) {}
void otworz(char * nazwa_pliku);
int LiczbaWierszy;
int LiczbaKolumn;
void graj();
private:
void rysuj();
void animujgre();	
obiekt **tablicaObiektow;
	
};
#endif
