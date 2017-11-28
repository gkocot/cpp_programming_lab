#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <windows.h>

using namespace std;

class object_t {
public:
	object_t(unsigned x, unsigned y, char t) : position_x(x), position_y(y), texture(t) {}
	void draw(void);
	void clear(void);
	virtual void move(void) {}; // By default objects are static.
	// TBD: Get object type, will be needed by robbo to recognize walls, screws etc.
protected:
	unsigned position_x;
	unsigned position_y;
	char texture;

	void move_cursor(unsigned x, unsigned y);
};

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

class wall_t : public object_t {
public:
	wall_t(unsigned x, unsigned y) : object_t(x, y, 'X') {}
};

class robbo_t : public object_t {
public:
	robbo_t(unsigned x, unsigned y) : object_t(x, y, 'R'), last_move_timestamp(0) {}
	virtual void move(void);
private:
	int last_move_timestamp;
	// TBD: Need reference to level to set it complete.
	// TBD: Number of screws to collect.
};

void robbo_t::move() {
	int now = GetTickCount();

	if (now - last_move_timestamp > 200) {
		if (GetKeyState(VK_UP) & 0x8000) {
			clear();
			position_y -= 1;
			last_move_timestamp = now;
			draw();
		}
		if (GetKeyState(VK_DOWN) & 0x8000) {
			clear();
			position_y += 1;
			last_move_timestamp = now;
			draw();
		}
		if (GetKeyState(VK_LEFT) & 0x8000) {
			clear();
			position_x -= 1;
			last_move_timestamp = now;
			draw();
		}
		if (GetKeyState(VK_RIGHT) & 0x8000) {
			clear();
			position_x += 1;
			last_move_timestamp = now;
			draw();
		}
	}
}

class screw_t : public object_t {
public:
	screw_t(unsigned x, unsigned y) : object_t(x, y, '*') {}
};

class exit_t : public object_t {
public:
	exit_t(unsigned x, unsigned y) : object_t(x, y, 'H') {}
};

class cannon_t : public object_t {
public:
	cannon_t(unsigned x, unsigned y) : object_t(x, y, 'O') {}
	// TBD virtual animate/move
};

class level_map_t {
public:
	level_map_t() : completed(false), width(0), height(0), objects(0) {}
	void load(const char * file_name);
	void play(void);
	// TBD: Destructor.
private:
	bool completed;
	size_t width;	
	size_t height;

	object_t **objects; 	

	void move_objects(void);
	void draw_objects(void);
};

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
	while (in_file.good()) {
		char c;
		in_file.get(c);
		
		switch (c) {
			case 'X':
				*(objects + i + j * width) = new wall_t(i, j);
				break;
			case 'R':
				*(objects + i + j * width) = new robbo_t(i, j); // TBD: Robbo will need reference to the level map so it can recognize walls, screws etc.
				break;
			case '*':
				*(objects + i + j * width) = new screw_t(i, j);
				break;
			case 'H':
				*(objects + i + j * width) = new exit_t(i, j);
				break;
			case '\n':
				i = 0;
				j += 1;
				continue;
			default:
				continue;
		}
		
		i += 1;
	}
	// TBD: Count number of screws, and assign to robbo.
	// TBD: Need reference to robbo.
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
	draw_objects(); // Initial draw, static objects will be drawn only once.
	while (
		!completed &&
		0 == (GetKeyState(VK_ESCAPE) & 0x8000)
	) {
		move_objects();
	}
}

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char * argv[]) {
	level_map_t level_map;
	level_map.load(argv[1]);
	level_map.play();

	return 0;
}
