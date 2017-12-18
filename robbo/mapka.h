#ifndef _MAPKA_H
#define _MAPKA_H

#include "obiekt.h"
#include "wyniki.h"


class mapka {
public:
	mapka() : LiczbaKolumn(0),LiczbaWierszy(0),srubki(0),tablica_wynikow(0,0,0,0,20),wygrana(false) {}
	bool wygrana;
int srubki;
void kasuj_obiekt(int x,int y);
void otworz(char * nazwa_pliku);
int LiczbaWierszy;
int LiczbaKolumn;
void graj();
char jaki_obiekt_stoi_na_pozycji(int x, int y);
private:
wyniki tablica_wynikow;
void rysuj();
void animujgre();	
obiekt **tablicaObiektow;
	
};
#endif
