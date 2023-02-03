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

int pawn_inc(Color color) {
	return (color == Color::White ? -1 : 1);
}


bool MovePiece::pawn(const Chessboard& board) const {
	
	if (to.x == from.x + pawn_inc(board.get_color(from))) {
		return true;
	}
	
	
	
	return true;
}

bool MovePiece::knight(const Chessboard& board) const {
	return true;
}

bool MovePiece::bishop(const Chessboard& board) const {
	return true;
}

bool MovePiece::rook(const Chessboard& board) const {
	return true;
}

bool MovePiece::queen(const Chessboard& board) const {
	return true;
}

bool MovePiece::king(const Chessboard& board) const {
	return true;
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



