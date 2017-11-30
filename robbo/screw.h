#ifndef _SCREW_H
#define _SCREW_H

#include "object.h"

class screw_t : public object_t {
public:
	screw_t(unsigned x, unsigned y) : object_t(x, y, '*') {}
};

#endif
