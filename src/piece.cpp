#include <fstream>
#include <sstream>

#include "piece.h"
#include "SFML/Graphics.hpp"
#include "sprites.h"
#include "constants.h"

Piece::Piece(PieceType type, Color color) :
	type{ type },
	color{ color }
	{
	}

