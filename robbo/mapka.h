#ifndef _MAPKA_H
#define _MAPKA_H

#include "obiekt.h"


class mapka {
public:
	mapka() : LiczbaKolumn(0),LiczbaWierszy(0) {}
void otworz(char * nazwa_pliku);
int LiczbaWierszy;
int LiczbaKolumn;
	
obiekt **tablicaObiektow;
	
};
#endif
