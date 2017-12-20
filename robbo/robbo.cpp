#include "robbo.h"
#include <windows.h>
#include <iostream>
using namespace std;
robbo::robbo(int x,int y,mapka * mapa) : obiekt(x,y,'R')
{
 czas = GetTickCount();
 m = mapa;
 p_x = x;
 p_y = y;

}

void robbo::animujobiekt() {
	// czytaj klawisz
	// przemiesc robbo	
	DWORD teraz;
	teraz = GetTickCount();
	
	if (teraz - czas > 150)
	{
		if (GetKeyState(VK_RIGHT) & 0x8000)
		{
			switch(m->jaki_obiekt_stoi_na_pozycji(x + 1,y))
		{
			case 'K':
				{
					m->kasuj_obiekt( x + 1, y);
					m->klucze--;
					czysc();
					m->przemiesc_obiekt(x,y,x+1,y);
					rysuj();
					czas = teraz;
					break;
							
				}
				case 'D':
				{
					m->zycia--;
					czysc();
				m->przemiesc_obiekt(x,y,p_x,p_y);
				x=p_x;y=p_y;
					rysuj();
					czas = teraz;
					if (m->zycia == 0)
					{
						m->wygrana = true;
					}
					break;		
				}
				case 'T':
				{
					m->kasuj_obiekt( x + 1, y);
					m->srubki--;
					czysc();
					m->przemiesc_obiekt(x,y,x+1,y);
					rysuj();
					czas = teraz;
					break;		
				}
				case 'B':
				{
					if (m->klucze == 0)
				{
					m->kasuj_obiekt( x, y );
					czysc();
					x--;
					rysuj();
					czas = teraz;
					
				}
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
				break;
				case ' ':
				{
					
					
					czysc();
					//x++;
					m->przemiesc_obiekt(x,y,x+1,y);
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
				case 'K':
				{
					m->kasuj_obiekt( x - 1, y);
					m->klucze--;
					czysc();
					x--;;
					rysuj();
					czas = teraz;
					break;
							
				}
				case 'T':
				{
					m->kasuj_obiekt( x - 1, y);
					m->srubki--;
					czysc();
					x--;
					rysuj();
					czas = teraz;
					break;
							
				}
				case 'B':
				{
					
					if (m->klucze == 0)
					{
					m->kasuj_obiekt( x, y );
					czysc();
					x--;
					rysuj();
					czas = teraz;
				}
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
					m->przemiesc_obiekt(x,y,x-1,y);
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
					switch(m->jaki_obiekt_stoi_na_pozycji(x,y - 1))
		{
				case 'K':
				{
					m->kasuj_obiekt( x, y - 1);
					m->klucze--;
					czysc();
					y--;
					rysuj();
					czas = teraz;
					break;
							
				}
				case 'T':
				{
					m->kasuj_obiekt(x, y - 1);
					m->srubki--;
					czysc();
					y--;
					rysuj();
					czas = teraz;
					break;
							
				}
				case 'B':
				{
				
					if (m->klucze == 0)
					{
					m->kasuj_obiekt( x, y );
					czysc();
					m->przemiesc_obiekt(x,y,x,y-1);
					rysuj();
					czas = teraz;
					
					}
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
					y--;
					rysuj();
					czas = teraz;
					m->wygrana = true;
				}
					
					break;
				
					
				}
				case ' ':
				{
					
					
					czysc();
					m->przemiesc_obiekt(x,y,x,y - 1);
					rysuj();
					czas = teraz;
					break;
					
				}
			}
			
				/*	if (m->jaki_obiekt_stoi_na_pozycji(x ,y - 1) != 'X')
				{
				czysc();
				y--;
				rysuj();
				czas = teraz;
				}*/
		}
		
		if (GetKeyState(VK_DOWN) & 0x8000)
		{
						switch(m->jaki_obiekt_stoi_na_pozycji(x ,y + 1))
		{
				case 'K':
				{
					m->kasuj_obiekt( x, y + 1);
					m->klucze--;
					czysc();
					y++;
					rysuj();
					czas = teraz;
					break;
							
				}
				case 'T':
				{
					m->kasuj_obiekt(x, y + 1);
					m->srubki--;
					czysc();
					y++;
					rysuj();
					czas = teraz;
					break;
							
				}
				case 'B':
				{

					if (m->klucze == 0)
					{
						m->kasuj_obiekt( x, y + 1);
					czysc();
					m->przemiesc_obiekt(x,y,x,y+1);
					rysuj();
					czas = teraz;
				}
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
					y++;
					rysuj();
					czas = teraz;
					m->wygrana = true;
				}
					
					break;
				
					
				}
				case ' ':
				{
					
					
					czysc();
				m->przemiesc_obiekt(x,y,x,y + 1);
					rysuj();
					czas = teraz;
					break;
					
				}
			}
		/*	if (m->jaki_obiekt_stoi_na_pozycji(x ,y + 1) != 'X')
			{
			czysc();
			y++;
			rysuj();
			czas = teraz; */
		}	
		
}
}

void robbo::czysciana()
{
	
	
	
	
}
