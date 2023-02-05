#include <iostream>
#include <vector>

#include "move_piece.h"
#include "possible_moves.h"
#include "coord.h"
#include "chessboard.h"
#include "direction.h"

static int pawn_inc(Color color) {
	return (color == Color::White ? -1 : 1);
}
static int pawn_init(Color color) {
	return (color == Color::White ? 6 : 1);
}

void PossibleMoves::get_all(const Chessboard& board, const Coord& from) {
	switch (board.get_piece(from).type) {
	case PieceType::Pawn:
		return possible_mov_pawn(board, from);
	case PieceType::Knight:
		return possible_mov_knight(board, from);
	case PieceType::Bishop:
		return possible_mov_bishop(board, from);
	case PieceType::Rook:
		return possible_mov_rook(board, from);
	case PieceType::Queen:
		return possible_mov_queen(board, from);
	case PieceType::King:
		return possible_mov_king(board, from);
	}
}

bool PossibleMoves::contain(const Coord& coord) const {
	for (Coord possible_coord : possible_moves) {
		if (coord.x == possible_coord.x && coord.y == possible_coord.y) {
			return true;
		}
	}
	return false;
}

void PossibleMoves::clear() {
	possible_moves.erase(possible_moves.begin(), possible_moves.end());
}

void PossibleMoves::possible_mov_pawn(const Chessboard& board, const Coord& from) {
	int pawn_incr{ pawn_inc(board.get_color(from)) };

	//Go 1 further
	if (!board.is_piece({ from.x + pawn_incr, from.y })) {
		possible_moves.emplace_back(from.x + pawn_incr, from.y);
	}

	//Go 2 further (first move)
	if (from.x == pawn_init(board.get_color(from))) {
		if (!board.is_piece({from.x + 2 * pawn_incr, from.y})){
			possible_moves.emplace_back(from.x + 2 * pawn_incr, from.y);
		}
	}

	//Eat pieces
	if (from.y == 0) {
		if (board.is_piece({ from.x + pawn_incr, from.y + 1 }) &&
			(board.get_color({ from.x + pawn_incr, from.y + 1 }) != board.get_color(from))) {
			possible_moves.emplace_back(from.x + pawn_incr, from.y + 1);
		}
	}
	else if (from.y == N_COL - 1) {
		if (board.is_piece({ from.x + pawn_incr, from.y - 1 }) &&
			(board.get_color({ from.x + pawn_incr, from.y - 1 }) != board.get_color(from))) {
			possible_moves.emplace_back(from.x + pawn_incr, from.y - 1);
		}
	}
	else {
		if (board.is_piece({ from.x + pawn_incr, from.y + 1 }) &&
			(board.get_color({ from.x + pawn_incr, from.y + 1 }) != board.get_color(from))) {
			possible_moves.emplace_back(from.x + pawn_incr, from.y + 1);
		}
		if (board.is_piece({ from.x + pawn_incr, from.y - 1 }) &&
			(board.get_color({ from.x + pawn_incr, from.y - 1 }) != board.get_color(from))) {
			possible_moves.emplace_back(from.x + pawn_incr, from.y - 1);
		}
	}		
}

void PossibleMoves::possible_mov_knight(const Chessboard& board, const Coord& from) {
	if (from.x - 1 >= 0 && from.y - 2 >= 0) {
		if (!board.is_friend(from, { from.x - 1, from.y - 2 })) {
			possible_moves.emplace_back(from.x - 1, from.y - 2);
		}
	}
	if (from.x - 1 >= 0 && from.y + 2 < N_COL) {
		if (!board.is_friend(from, { from.x - 1, from.y + 2 })) {
			possible_moves.emplace_back(from.x - 1, from.y + 2);
		}
	}
	if (from.x + 1 < N_ROW && from.y - 2 >= 0) {
		if (!board.is_friend(from, { from.x + 1, from.y - 2 })) {
			possible_moves.emplace_back(from.x + 1, from.y - 2);
		}
	}
	if (from.x + 1 < N_ROW && from.y + 2 < N_COL) {
		if (!board.is_friend(from, { from.x + 1, from.y + 2 })) {
			possible_moves.emplace_back(from.x + 1, from.y + 2);
		}
	}
	if (from.x - 2 >= 0 && from.y - 1 >= 0) {
		if (!board.is_friend(from, { from.x - 2, from.y - 1 })) {
			possible_moves.emplace_back(from.x - 2, from.y - 1);
		}
	}
	if (from.x - 2 >= 0 && from.y + 1 < N_ROW) {
		if (!board.is_friend(from, { from.x - 2, from.y + 1 })) {
			possible_moves.emplace_back(from.x - 2, from.y + 1);
		}
	}
	if (from.x + 2 < N_COL && from.y - 1 >= 0) {
		if (!board.is_friend(from, { from.x + 2, from.y - 1 })) {
			possible_moves.emplace_back(from.x + 2, from.y - 1);
		}
	}
	if (from.x + 2 < N_COL && from.y + 1 < N_ROW) {
		if (!board.is_friend(from, { from.x + 2, from.y + 1 })) {
			possible_moves.emplace_back(from.x + 2, from.y + 1);
		}
	}
}



void PossibleMoves::possible_mov_bishop(const Chessboard& board, const Coord& from) {
	line(board, from, { Dir::U_L });
	line(board, from, { Dir::U_R });
	line(board, from, { Dir::D_L });
	line(board, from, { Dir::D_R });
}

void PossibleMoves::possible_mov_rook(const Chessboard& board, const Coord& from) {
	line(board, from, { Dir::Up });
	line(board, from, { Dir::Down });
	line(board, from, { Dir::Left });
	line(board, from, { Dir::Right });
}

void PossibleMoves::possible_mov_queen(const Chessboard& board, const Coord& from) {
	line(board, from, { Dir::Up });
	line(board, from, { Dir::Down });
	line(board, from, { Dir::Left });
	line(board, from, { Dir::Right });
	line(board, from, { Dir::U_L });
	line(board, from, { Dir::U_R });
	line(board, from, { Dir::D_L });
	line(board, from, { Dir::D_R });
}

void PossibleMoves::possible_mov_king(const Chessboard& board, const Coord& from) {
	if (from.x - 1 >= 0 && from.y - 1 >= 0) {
		if (!board.is_friend(from, { from.x - 1, from.y - 1 })) {
			possible_moves.emplace_back(from.x - 1, from.y - 1);
		}
	}
	if (from.x - 1 >= 0) {
		if (!board.is_friend(from, { from.x - 1, from.y })) {
			possible_moves.emplace_back(from.x - 1, from.y);
		}
	}
	if (from.x - 1 >= 0 && from.y + 1 < N_COL) {
		if (!board.is_friend(from, { from.x - 1, from.y + 1 })) {
			possible_moves.emplace_back(from.x - 1, from.y + 1);
		}
	}
	if (from.y - 1 >= 0) {
		if (!board.is_friend(from, { from.x, from.y - 1 })) {
			possible_moves.emplace_back(from.x, from.y - 1);
		}
	}
	if (from.y + 1 < N_COL) {
		if (!board.is_friend(from, { from.x, from.y + 1 })) {
			possible_moves.emplace_back(from.x, from.y + 1);
		}
	}
	if (from.x + 1 < N_ROW && from.y - 1 >= 0) {
		if (!board.is_friend(from, { from.x + 1, from.y - 1 })) {
			possible_moves.emplace_back(from.x + 1, from.y - 1);
		}
	}
	if (from.x + 1 < N_ROW) {
		if (!board.is_friend(from, { from.x + 1, from.y })) {
			possible_moves.emplace_back(from.x + 1, from.y);
		}
	}
	if (from.x + 1 < N_ROW && from.y + 1 < N_COL) {
		if (!board.is_friend(from, { from.x + 1, from.y + 1 })) {
			possible_moves.emplace_back(from.x + 1, from.y + 1);
		}
	}
}

void PossibleMoves::line(const Chessboard& board, const Coord& from, const Direction& dir) {
	Coord inc{ from };
	inc.x += dir.x;
	inc.y += dir.y;
	while ((inc.x >= 0 && inc.x < N_ROW && inc.y >= 0 && inc.y < N_COL)  && !board.is_piece(inc)) {
		possible_moves.emplace_back(inc);
		inc.x += dir.x;
		inc.y += dir.y;
	}
	if ((inc.x >= 0 && inc.x < N_ROW && inc.y >= 0 && inc.y < N_COL) && !board.is_enemy(from, inc)) {
		possible_moves.emplace_back(inc);
	}
}
