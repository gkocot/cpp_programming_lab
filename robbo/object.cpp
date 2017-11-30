#include "object.h"
#include <windows.h>
#include <iostream>

using namespace std;

void object_t::move_cursor(unsigned x, unsigned y) {
	COORD coord;
	coord.X = x;
  	coord.Y = y;
 	SetConsoleCursorPosition(
    	GetStdHandle(STD_OUTPUT_HANDLE),
    	coord
	);
}

void object_t::draw(void) {
	move_cursor(position_x, position_y);
	cout << texture;	
}

void object_t::clear(void) {
	move_cursor(position_x, position_y);
	cout << ' ';	
}
