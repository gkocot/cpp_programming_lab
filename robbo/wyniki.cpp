#include "wyniki.h"
#include <iostream>
using namespace std;

wyniki::wyniki(int s,int k,int z,int x,int y) : obiekt(x,y,'X')
{
	srubki = s;
	klucze = k;
	zycia = z;
	
}


void wyniki::rysuj()
{
	
	move(x,y);
	cout << "Ilosc srubek : "<<srubki<<" "<<"ilosc kluczy : "<<klucze<<" "<<"ilosc zyc : "<<zycia;
	
	
	
	
}
