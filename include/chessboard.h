#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <SFML/Graphics.hpp>
#include <array>
#include <optional>

#include "piece.h"
#include "coord.h"
#include "sprites.h"
#include "constants.h"
#include "move_piece.h"



using Tile_t = std::optional<Piece>;

struct Chessboard {

	Chessboard();

	bool is_piece(const Coord& coord) const;
	bool is_friend(const Coord& from, const Coord& to) const;
	bool is_enemy(const Coord& from, const Coord& to) const;
	Color get_color(const Coord& coord) const;
	Piece get_piece(const Coord& coord) const;
	Chessboard update(const MovePiece& move_piece);


	std::array< std::array<Tile_t, N_COL>, N_ROW> board{};
};

#endif