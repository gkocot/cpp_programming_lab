#include <fstream>
#include <windows.h>
#include "level_map.h"
#include "wall.h"
#include "robbo.h"
#include "screw.h"
#include "exit.h"

using namespace std;

void level_map_t::load(const char * file_name) {
	// TBD: Free objects if objects != nullptr_t;
	ifstream in_file(file_name);
	
	width = 0;
	height = 0;
	while (in_file.good()) {
		string s;
		getline(in_file, s);
		width = max(width, s.length());
		height += 1;				
	}
	in_file.seekg(ios_base::beg);
	in_file.clear();
	
	objects = new object_t * [width * height];
	memset(objects, 0, sizeof(object_t *) * width * height);
	
	size_t i = 0;
	size_t j = 0;
	
	unsigned missing_screws = 0;
	robbo_t * robbo;

	while (in_file.good()) {
		char c;
		in_file.get(c);
		
		switch (c) {
			case 'X':
				*(objects + i + j * width) = new wall_t(i, j);
				break;
			case 'R':
				*(objects + i + j * width) = robbo = new robbo_t(i, j, this); // Assumed only one robbo object can be found on the level map.
				break;
			case '*':
				*(objects + i + j * width) = new screw_t(i, j);
				missing_screws++;
				break;
			case 'H':
				*(objects + i + j * width) = new exit_t(i, j);
				break;
			case '\n':
				i = 0;
				j += 1;
				continue;
			default:
				break;
		}
		
		i += 1;
	}
	robbo->missing_screws = missing_screws;
	in_file.close();
}

void level_map_t::move_objects(void) {
	for (size_t i = 0; i < width * height; ++i) {
		object_t * object = *(objects + i);
		if (object != 0) {
			object->move();
		}
	}
}

void level_map_t::draw_objects(void) {
	for (size_t i = 0; i < width * height; ++i) {
		object_t * object = *(objects + i);
		if (object != 0) {
			object->draw();
		}
	}
}

void level_map_t::play(void) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    GetConsoleCursorInfo(consoleHandle, &info);
    
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
    
	draw_objects(); // Initial draw, static objects will be drawn only once.
	while (
		!completed &&
		0 == (GetKeyState(VK_ESCAPE) & 0x8000)
	) {
		move_objects();
	}
}

void level_map_t::clear_object(object_t * obj) {
	unsigned x, y;
	obj->get_position(x, y);	
	*(objects + y * width + x) = 0;
	obj->clear();
}

void level_map_t::delete_object_at(unsigned x, unsigned y) {
	object_t * obj = *(objects + y * width + x);
	
	if (obj) {	
		obj->clear();
		delete obj;
		*(objects + y * width + x) = 0;
	}
}

void level_map_t::set_object(object_t * obj) {
	unsigned x, y;
	obj->get_position(x, y);
	*(objects + y * width + x) = obj;
	obj->draw();
}

char level_map_t::object_type_at(unsigned x, unsigned y) {
	object_t * obj = *(objects + y * width + x);
	if (obj == 0) {
		return ' ';
	}
	else {
		return 	obj->get_type();
	}
}
