#ifndef _OBJECT_H
#define _OBJECT_H

class object_t {
public:
	object_t(unsigned x, unsigned y, char t) : position_x(x), position_y(y), texture(t) {}
	void draw(void);
	void clear(void);
	virtual void move(void) {}; // By default objects are static.
	void get_position(unsigned & x, unsigned & y) { x = position_x; y = position_y; }
	char get_type(void) { return texture; }

protected:
	unsigned position_x;
	unsigned position_y;
	char texture;

	void move_cursor(unsigned x, unsigned y);
};

#endif
