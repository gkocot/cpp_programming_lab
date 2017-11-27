#include <iostream>	
#include <cstdlib>
#include <conio.h>
#include <windows.h>

using namespace std;

class objektnaekranie
{
	protected:
	void movecursor(int x,int y);
	
	
};


class Ekran:public objektnaekranie
{	
public:
	Ekran(int _x, int _y,int _w,int _h): x(_x), y(_y),w(_w),h(_h)  {}
	void rysuj(void);
	
private:
	friend class pilka;
	 int x;
	 int y;	 
	 int w;
	 int h;
};

class pilka:public objektnaekranie
{
public:	
pilka( int _x,int _y, char _Texture,  Ekran *_mojekran ,int _dx=1,int _dy=1): dx(_dx),dy(_dy),x(_x),y(_y),Texture(_Texture),mojekran(_mojekran) {}
void rysuj(void);
void move(void);
private:
	Ekran *mojekran;
	int dx;
	int dy;
	int x;
	int y;
	char Texture;

	
	
};


class Pong
{
public:
	Pong();
	void dzialaj(void);
private:
		Ekran e1;
	Ekran e2;
	pilka p1;
	pilka p2;
	pilka p3;
	pilka p4;

	
	void czysc(void);
};


