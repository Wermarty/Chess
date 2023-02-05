#ifndef DIRECTION_H
#define DIRECTION_H

enum class Dir {
	Up,
	Down,
	Left,
	Right,
	U_L,
	U_R,
	D_L,
	D_R
};

struct Direction {
	int x{};
	int y{};

	Direction(Dir dir);


};


#endif