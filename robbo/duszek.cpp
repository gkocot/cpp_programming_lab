#include "duszek.h"
#include <windows.h>
duszek::duszek(int x,int y, mapka* mapa) : obiekt(x,y,'D')
{
predkosc_x = 1;
predkosc_y = 1;	
czas = GetTickCount();
m = mapa;
	
}
	
	
/*	switch( rand() % 4 ) {
 
            case 0: 
                // go up
                cout << "up" << endl;
                break;
            case 1:
                // go down
                cout << "down" << endl;
                break;
            case 2:
                // go left
                cout << "left" << endl;
                break;
            default:
                // go right
                cout << "right" << endl;
                break;
               }    
*/		


void duszek::animujobiekt() {
	// czytaj klawisz
	// przemiesc robbo	
	DWORD teraz;
	teraz = GetTickCount();
	
	if (teraz - czas > 500)
	{
		
		{
			switch(m->jaki_obiekt_stoi_na_pozycji(x + predkosc_x,y))
		{
			
			case 'X':
				{
					
					predkosc_x = -predkosc_x;
					
						
					break;
				}
#if 1				
				case 'R':
				{
					
				m->zycia--;				
				m->przemiesc_obiekt(x + predkosc_x,y,2,2);
					if (m->zycia == 0)
					{
						m->wygrana = true;
					}
				
				
				
			/*	
				czysc();
				m->przemiesc_obiekt(x,y,x + predkosc_x,y);
					//x = x + predkosc_x;
					rysuj();
					czas = teraz;
*/
				}
#endif				
				case ' ':
				{	
				
					czysc();
					m->przemiesc_obiekt(x,y,x + predkosc_x,y);
					//x = x + predkosc_x;
					rysuj();
					czas = teraz;
					
					break;
					
				}
			}
		}	
	}
}
		

