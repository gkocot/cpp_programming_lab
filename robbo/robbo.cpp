#include "robbo.h"
#include <windows.h>
#include <iostream>
using namespace std;
robbo::robbo(int x,int y,mapka * mapa) : obiekt(x,y,'R')
{
 czas = GetTickCount();
 m = mapa;

}

void robbo::animujobiekt() {
	// czytaj klawisz
	// przemiesc robbo	
	DWORD teraz;
	teraz = GetTickCount();
	
	if (teraz - czas > 200)
	{
		if (GetKeyState(VK_RIGHT) & 0x8000)
		{
			switch(m->jaki_obiekt_stoi_na_pozycji(x + 1,y))
		{
				case 'T':
				{
					m->kasuj_obiekt( x + 1, y);
					m->srubki--;
					czysc();
					x++;
					rysuj();
					czas = teraz;
					break;
							
				}
				case 'X':
				{
						
					break;
				}
				case 'H':
				{
					
					if (m->srubki == 0)
					{
					czysc();
					x++;
					rysuj();
					czas = teraz;
					m->wygrana = true;
				}
					break;
				
					
				}
				case ' ':
				{
					
					
					czysc();
					x++;
					rysuj();
					czas = teraz;
					break;
					
				}
			}
		}
		
		
		if (GetKeyState(VK_LEFT) & 0x8000)	
		{
			switch(m->jaki_obiekt_stoi_na_pozycji(x - 1,y))
		{
				case 'T':
				{
					m->srubki--;
					czysc();
					x--;
					rysuj();
					czas = teraz;
					break;
							
				}
				case 'X':
				{
						
					break;
				}
				case 'H':
				{
					if (m->srubki == 0)
					{
					czysc();
					x--;
					rysuj();
					czas = teraz;
					m->wygrana = true;
				}
					
					break;
				
					
				}
				case ' ':
				{
					
					
					czysc();
					x--;
					rysuj();
					czas = teraz;
					break;
					
				}
			}
			/*
			if (m->jaki_obiekt_stoi_na_pozycji(x - 1,y) != 'X')
			{
			czysc();
			x--;
			rysuj();
			czas = teraz;
			}
			if (m->jaki_obiekt_stoi_na_pozycji(x - 1,y) != 'T')
			{
			czysc();
			x--;
			rysuj();
			czas = teraz;
			}
			*/
		}
		
		if (GetKeyState(VK_UP) & 0x8000) 
		{
			if (m->jaki_obiekt_stoi_na_pozycji(x ,y - 1) != 'X')
			{
			czysc();
			y--;
			rysuj();
			czas = teraz;
	}
		}
		
		if (GetKeyState(VK_DOWN) & 0x8000)
		{
			if (m->jaki_obiekt_stoi_na_pozycji(x ,y + 1) != 'X')
			{
			czysc();
			y++;
			rysuj();
			czas = teraz;
		}
			
		}
	}	
}

void robbo::czysciana()
{
	
	
	
	
}
