#include "robbo.h"
#include <windows.h>

void robbo_t::interact_with_neighbour(int dx, int dy) {
	switch (level_map->object_type_at(position_x + dx, position_y + dy)) {
		case 'X':
			break;
		case '*':
			level_map->delete_object_at(position_x + dx, position_y + dy);
			missing_screws--;
			level_map->clear_object(this);
			position_x += dx;
			position_y += dy;
			level_map->set_object(this);
			break;
		case 'H':
			if (0 == missing_screws) {
				level_map->delete_object_at(position_x + dx, position_y + dy);
				level_map->clear_object(this);
				position_x += dx;
				position_y += dy;
				level_map->set_object(this);
				level_map->completed = true;
			}
			break;
		default:
			level_map->delete_object_at(position_x + dx, position_y + dy);
			level_map->clear_object(this);
			position_x += dx;
			position_y += dy;
			level_map->set_object(this);
			break;
	}		
}

void robbo_t::move() {
	int now = GetTickCount();

	if (now - last_move_timestamp > 200) {
		if (GetKeyState(VK_UP) & 0x8000) {
			interact_with_neighbour(0, -1);
			last_move_timestamp = now;
		}
		if (GetKeyState(VK_DOWN) & 0x8000) {
			interact_with_neighbour(0, 1);
			last_move_timestamp = now;
		}
		if (GetKeyState(VK_LEFT) & 0x8000) {
			interact_with_neighbour(-1, 0);
			last_move_timestamp = now;			
		}
		if (GetKeyState(VK_RIGHT) & 0x8000) {
			interact_with_neighbour(1, 0);
			last_move_timestamp = now;
		}
	}
}

