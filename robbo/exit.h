#ifndef _EXIT_H
#define _EXIT_H

#include "object.h"

class exit_t : public object_t {
public:
	exit_t(unsigned x, unsigned y) : object_t(x, y, 'H') {}
};

#endif
