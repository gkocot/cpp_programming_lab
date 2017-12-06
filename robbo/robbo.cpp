#include "robbo.h"
#include <windows.h>


robbo::robbo(int x,int y) : obiekt(x,y,'R')
{
 czas = GetTickCount();

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
		czysc();
		x++;
		rysuj();
		czas = teraz;
	}
	
	if (GetKeyState(VK_LEFT) & 0x8000)	
	{
	czysc();
		x--;
		rysuj();
		czas = teraz;
	}
	
	if (GetKeyState(VK_UP) & 0x8000) 
	{
		czysc();
		y--;
		rysuj();
		czas = teraz;
	
	}
	
	if (GetKeyState(VK_DOWN) & 0x8000)
	{
		czysc();
		y++;
		rysuj();
		czas = teraz;
		
	}
}


	
}
