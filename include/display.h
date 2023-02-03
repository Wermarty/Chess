#ifndef DISPLAY_H
#define DISPLAY_H

#include "chessboard.h"
#include "piece.h"


struct Display {

	void piece(const Piece& piece, Coord coord, sf::RenderWindow& window, Sprites& sprites);
	void board(sf::RenderWindow& window, const Chessboard& board, Sprites& sprites);
};


#endif