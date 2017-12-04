#include "mapka.h"
#include "sciana.h"
#include "robbo.h"
#include "sciana.h"
#include "wyjscie.h"
#include "znajdzka.h"
#include <string>
#include <fstream>
#include <algorithm>
#include <windows.h>

#include <iostream>
using namespace std;

void mapka::otworz(char * nazwa_pliku)
{
	string Linia;
	ifstream plik(nazwa_pliku);		
	
	while( !plik.eof() )
        {
        	//Linia.clear();
            getline( plik, Linia );
            LiczbaKolumn = max<int>(LiczbaKolumn, Linia.length());
        	LiczbaWierszy++;
           //cout << Linia << endl;
           //cout << LiczbaKolumn << endl;
           //cout << LiczbaWierszy << endl;
        }
        
        tablicaObiektow = new obiekt * [LiczbaKolumn * LiczbaWierszy];
        //memset(tablicaObiektow, 0, sizeof(obiekt *) * LiczbaKolumn * LiczbaWierszy);
        for (int i=0; i<LiczbaKolumn * LiczbaWierszy; ++i) {
        	tablicaObiektow[i] = 0;	
        }
        
        plik.seekg(0, ios::beg);
        
        int x = 0;
        int y = 0;
        while( !plik.eof() )
        
        {
        	char znak;
            plik.get (znak);
           if (znak =='X')
           {
           	*(tablicaObiektow + x + y * LiczbaKolumn)  = new Sciana(x,y);
           	// tworzenie obiektu robbo w tablicy dynamicznej 
           }
            if (znak =='R')
           {
           	*(tablicaObiektow + x + y * LiczbaKolumn)  = new robbo(x,y);
           	
           }           
           
            if (znak =='H')
           {
           	*(tablicaObiektow + x + y * LiczbaKolumn)  = new wyjscie(x,y);
           	
           }
            if (znak =='T')
           {
           	*(tablicaObiektow + x + y * LiczbaKolumn)  = new znajdzka(x,y);
           }
        
		    if (znak == '\n' )
           {
           	
           	x = 0;
           	y = y + 1;
           	
           }
           else 
           {

           	x =x +1;
           }
        }      
 plik.close();       
}

void mapka::rysuj()
{
	
	for (int i=0;i<LiczbaKolumn * LiczbaWierszy;i++)
	{
		if (tablicaObiektow[i] != 0) {
		tablicaObiektow[i]->rysuj();
	}
		
		
	}
	
	
	
}
void mapka::animujgre()
{
	
	for (int i=0;i<LiczbaKolumn * LiczbaWierszy;i++)
	{
		if (tablicaObiektow[i] != 0) {
		tablicaObiektow[i]->animujobiekt();
	}
		
		
	}
	
	
	
}


void mapka::graj()
{

	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); // pobiera z windows h uchwyt z standardowego wyjscia
    CONSOLE_CURSOR_INFO info; 
    GetConsoleCursorInfo(consoleHandle, &info);  //pobieramy informacje o kursorze
    
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
    
rysuj();
	while (
	//	!completed &&
		0 == (GetKeyState(VK_ESCAPE) & 0x8000) //najstarszy bit informuje ze klawisz nacisniety najlmodszy ze klaWISZ JEst w stanie przelaczonym
	) {
		
		animujgre();
		
	}
}	
		
		
	
	
	
	




