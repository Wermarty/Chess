#include "move_piece.h"
#include "coord.h"
#include "chessboard.h"
#include <iostream>


MovePiece::MovePiece(const Coord& from, const Coord& to) :
	from{ from },
	to {to}
	{
	}

void MovePiece::reinitialize() {
	from = { -1, -1 };
	to = { -1, -1 };
	is_empty = true;
}



static int pawn_inc(Color color) {
	return (color == Color::White ? -1 : 1);
}
static int pawn_init(Color color) {
	return (color == Color::White ? 6 : 1);
}
static int pawn_end(Color color) {
	return (color == Color::White ? 6 : 1);
}

bool MovePiece::pawn(const Chessboard& board) const {
	int pawn_incr{ pawn_inc(board.get_color(from)) };

	if ((to.x == from.x + pawn_incr ||
		(from.x == pawn_init(board.get_color(from))) && to.x == from.x + (pawn_incr) * 2) &&
		to.y == from.y) {
		return true;
	}

	if (board.is_piece(to) && (board.get_color(from) != board.get_color(to))) {
		if (to.x == from.x + pawn_incr && ((to.y - from.y == 1) || (from.y - to.y == 1))) {
			return true;
		}
	}

	return false;
}

bool MovePiece::knight(const Chessboard& board) const {

	if (board.is_piece(to) && (board.get_color(to) == board.get_color(from))) {
		return false;
	}

	if (((from.x - to.x == 2 || from.x - to.x == -2) &&
		(from.y - to.y == 1 || from.y - to.y == -1)) ||
		((from.x - to.x == 1 || from.x - to.x == -1) &&
		(from.y - to.y == 2 || from.y - to.y == -2)))
	{
		return true;
	}

	return false;
}

bool MovePiece::bishop(const Chessboard& board) const {
	return false;
}

bool MovePiece::rook(const Chessboard& board) const {
	return false;
}

bool MovePiece::queen(const Chessboard& board) const {
	return false;
}

bool MovePiece::king(const Chessboard& board) const {
	return false;
}


bool MovePiece::is_possible(const Chessboard& board) const {
	switch (board.get_piece(from).type) {
	case PieceType::Pawn:
		return pawn(board);
	case PieceType::Knight:
		return knight(board);
	case PieceType::Bishop:
		return bishop(board);
	case PieceType::Rook:
		return rook(board);
	case PieceType::Queen:
		return queen(board);
	case PieceType::King:
		return king(board);
	}

	return false;
}



