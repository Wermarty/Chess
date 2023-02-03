#ifndef COORD_H
#define COORD_H

struct Coord {
	
	Coord() = default;
	Coord(int x, int y);
	
	int x{};
	int y{};
};

#endif 
