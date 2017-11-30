#ifndef _CANNON_H
#dfine _CANNON_H

#include "object.h"

class cannon_t : public object_t {
public:
	cannon_t(unsigned x, unsigned y) : object_t(x, y, 'O') {}
	// TBD virtual animate/move
};

#endif
