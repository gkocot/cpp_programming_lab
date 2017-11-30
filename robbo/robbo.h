#ifndef _ROBBO_H
#define _ROBBO_H

#include "object.h"
#include "level_map.h"

class robbo_t : public object_t {
public:
	unsigned missing_screws;

	robbo_t(unsigned x, unsigned y, level_map_t * _level_map) :
		object_t(x, y, 'R'),
		missing_screws(0),
		last_move_timestamp(0),
		level_map(_level_map) {}
	virtual void move(void);
private:
	int last_move_timestamp;
	level_map_t * level_map;
	
	void interact_with_neighbour(int dx, int dy);
};

#endif
