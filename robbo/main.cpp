#include "level_map.h"

int main(int argc, char * argv[]) {
	level_map_t level_map;
	level_map.load(argv[1]);
	level_map.play();

	return 0;
}
