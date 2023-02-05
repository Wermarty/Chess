#ifndef POSSIBLE_MOVES
#define POSSIBLE_MOVES

#include <vector>

#include "coord.h"
#include "chessboard.h"

struct PossibleMoves {

	PossibleMoves() = default;

	void get_all(const Chessboard& board, const Coord& from);
	bool contain(const Coord& coord) const;
	void clear();

private:
	void possible_mov_pawn  (const Chessboard& board, const Coord& from);
	void possible_mov_knight(const Chessboard& board, const Coord& from);
	void possible_mov_bishop(const Chessboard& board, const Coord& from);
	void possible_mov_rook  (const Chessboard& board, const Coord& from);
	void possible_mov_queen (const Chessboard& board, const Coord& from);
	void possible_mov_king  (const Chessboard& board, const Coord& from);


public:
	std::vector<Coord> possible_moves{};
};




#endif
