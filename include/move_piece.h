#ifndef MOVE_PIECE_H
#define MOVE_PIECE_H

#include "coord.h"

struct Chessboard;

struct MovePiece{

	MovePiece() = default;
	void reinitialize();
	bool is_possible(const Chessboard& board) const;

private:
	MovePiece(const Coord& from, const Coord& to);
	bool king(const Chessboard& board) const;
	bool queen(const Chessboard& board) const;
	bool rook(const Chessboard& board) const;
	bool bishop(const Chessboard& board) const;
	bool knight(const Chessboard& board) const;
	bool pawn(const Chessboard& board) const;

public:
	Coord from{-1, -1};
	Coord to{-1, -1};
	bool is_empty{ true };

};



#endif