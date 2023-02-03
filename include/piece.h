#ifndef PIECE_H
#define PIECE_H

#include <string>

#include "SFML/Graphics.hpp"
#include "sprites.h"



enum class Color {
	White,
	Black
};

enum class PieceType {
	King,
	Queen, 
	Rook,
	Bishop,
	Knight,
	Pawn
};

struct Piece {
	Piece(PieceType type, Color color);


	PieceType type{};
	Color color{};

};

#endif
