#ifndef _WALL_H
#define _WALL_H

#include "object.h"

class wall_t : public object_t {
public:
	wall_t(unsigned x, unsigned y) : object_t(x, y, 'X') {}
};

#endif
