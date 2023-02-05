#include "direction.h"


Direction::Direction(Dir dir) {
	switch (dir) {
	case Dir::Up:
		x = -1; y = 0;
		break;
	case Dir::Down:
		x = 1; y = 0;
		break;
	case Dir::Left:
		x = 0; y = -1;
		break;
	case Dir::Right:
		x = 0; y = 1;
		break;
	case Dir::U_L:
		x = -1; y = -1;
		break;
	case Dir::U_R:
		x = -1; y = 1;
		break;
	case Dir::D_L:
		x = 1; y = -1;
		break;
	case Dir::D_R:
		x = 1; y = 1;
		break;
	}
}