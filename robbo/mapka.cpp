#include "mapka.h"
#include "sciana.h"
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

void mapka::otworz(char * nazwa_pliku)
{
	string Linia;
	ifstream plik(nazwa_pliku);		
	
	while( !plik.eof() )
        {
            getline( plik, Linia );
            LiczbaKolumn = max<int>(LiczbaKolumn, Linia.length());
        	LiczbaWierszy++;
        }
        
        tablicaObiektow = new obiekt * [LiczbaKolumn * LiczbaWierszy];
        
        plik.seekg(0, ios::beg);
        
        int x = 0;
        int y = 0;
        while( !plik.eof() )
        
        {
        	char znak;
            plik.get (znak);
           if (znak =='x')
           {
           	*(tablicaObiektow + x + y * LiczbaKolumn)  = new Sciana(x,y);
           	
           	
           }
            if (znak =='R')
           {
           	*(tablicaObiektow + x + y * LiczbaKolumn)  = new roboo(x,y);
           	
           }
           
           if (LiczbaKolumn > x
           
        }
        
        
        
        
        
 plik.close(); 
        
}

