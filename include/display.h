#ifndef DISPLAY_H
#define DISPLAY_H

#include <vector>

#include "chessboard.h"
#include "piece.h"
#include "possible_moves.h"


struct Display {

	void board (sf::RenderWindow& window, Sprites& sprites);
	void help  (sf::RenderWindow& window, const PossibleMoves& possible_moves, Sprites& sprites);
	void pieces(sf::RenderWindow& window, const Chessboard& board, Sprites& sprites);
};


#endif