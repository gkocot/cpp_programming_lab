#include "obiekt.h"
#include <windows.h>
#include <iostream>

using namespace std;
obiekt::obiekt(int x,int y,char Textura)
{
	this->x = x;
	this->y = y;
	this->Textura = Textura;
}

void obiekt::czysc()
{
	move(x,y);
	cout << ' ';
	
	
}


void obiekt::rysuj()
{
	move(x,y);
	cout << Textura;
	
}


void obiekt::move(int x, int y) {
	COORD coord;
	coord.X = x;
  	coord.Y = y;
 	SetConsoleCursorPosition(
    	GetStdHandle(STD_OUTPUT_HANDLE),
    	coord
	);
}

