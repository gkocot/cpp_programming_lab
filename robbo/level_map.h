#ifndef _LEVEL_MAP
#define _LEVEL_MAP

#include <cstddef>
#include "object.h"

class level_map_t {
public:
	bool completed;

	level_map_t() : completed(false), width(0), height(0), objects(0) {}
	void load(const char * file_name);
	void play(void);
	void clear_object(object_t * obj);
	void delete_object_at(unsigned x, unsigned y);
	void set_object(object_t * obj);
	char object_type_at(unsigned x, unsigned y);
	// TBD: Destructor.
private:
	size_t width;	
	size_t height;

	object_t **objects; 	

	//object_t *& object_at(unsigned x, unsigned y) { return *(objects + y * width + x); }
	void move_objects(void);
	void draw_objects(void);
};

#endif
