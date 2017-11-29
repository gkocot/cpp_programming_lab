#include <iostream>	
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include "pilka.h"

void objektnaekranie::movecursor(int x,int y)
{
	COORD coord;
	coord.X = x;
  	coord.Y = y;
 	SetConsoleCursorPosition(
    	GetStdHandle( STD_OUTPUT_HANDLE ),
    	coord
	);
	
}

void Ekran::rysuj(void)
{
	
movecursor(x,y);
	
	for(int i = 0 ;i < w;i++)
	{
		cout <<"x";
	}
	
	

	for(int j = 1; j < h-1;j++)
	{
		movecursor(x,y+j);
		cout <<"x";
		movecursor(x+w-1,y+j);
		cout <<"x";
		
	}
	
movecursor(x,y+h-1);
for(int i = 0 ;i < w;i++)
	{
		cout <<"x";
	}
	
}

void pilka::move(void)
{
	if(x == mojekran->x + 1 ||
		x == mojekran->x + mojekran->w - 2)	
	{
		dx = -dx;
	}

	if(y == mojekran->y + 1 ||
		y == mojekran->y + mojekran->h - 2)	
	{
		dy = -dy;
	}

	movecursor(x,y);
	cout << ' ';

	x = x + dx;
	y = y + dy;
}

void pilka::rysuj(void)

{	
	movecursor(x,y);
	cout <<Texture;
}


Pong::Pong(): e1(0,0,30,15) , e2(30,0,30,20) ,p1(5,5,'O',&e1),p2(7,10,'O',&e1),p3(35,10,'O',&e2),p4(40,5,'O',&e2)
{
	czysc();
}

void Pong::czysc(void)
{
	system("cls");
}

void Pong::dzialaj(void) {
	e1.rysuj();
	e2.rysuj();	
	while(!kbhit())
	{
			p1.move();
		p2.move();
		p3.move();
		p4.move();
		p1.rysuj();
		p2.rysuj();
		p3.rysuj();
		p4.rysuj();
		Sleep(200);
	}

}
