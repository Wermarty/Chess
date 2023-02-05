#include "SFML/Graphics.hpp"
#include <iostream>

#include "constants.h"
#include "piece.h"
#include "chessboard.h"
#include "sprites.h"

Chessboard::Chessboard(){
	
	board.at(0).at(0).emplace(PieceType::Rook, Color::Black);
	board.at(0).at(N_COL - 1).emplace(PieceType::Rook, Color::Black);
	board.at(0).at(1).emplace(PieceType::Knight, Color::Black);
	board.at(0).at(N_COL - 2).emplace(PieceType::Knight, Color::Black);
	board.at(0).at(2).emplace(PieceType::Bishop, Color::Black);
	board.at(0).at(N_COL - 3).emplace(PieceType::Bishop, Color::Black);
	board.at(0).at(3).emplace(PieceType::Queen, Color::Black);
	board.at(0).at(N_COL - 4).emplace(PieceType::King, Color::Black);
	board.at(N_ROW - 1).at(0).emplace(PieceType::Rook, Color::White);
	board.at(N_ROW - 1).at(N_COL - 1).emplace(PieceType::Rook, Color::White);
	board.at(N_ROW - 1).at(1).emplace(PieceType::Knight, Color::White);
	board.at(N_ROW - 1).at(N_COL - 2).emplace(PieceType::Knight, Color::White);
	board.at(N_ROW - 1).at(2).emplace(PieceType::Bishop, Color::White);
	board.at(N_ROW - 1).at(N_COL - 3).emplace(PieceType::Bishop, Color::White);
	board.at(N_ROW - 1).at(3).emplace(PieceType::Queen, Color::White);
	board.at(N_ROW - 1).at(N_COL - 4).emplace(PieceType::King, Color::White);

	for (int i{ 0 }; i < N_COL; i++) {
		board.at(1).at(i).emplace(PieceType::Pawn, Color::Black);
		board.at(N_ROW - 2).at(i).emplace(PieceType::Pawn, Color::White);
	}
}



bool Chessboard::is_piece(const Coord& coord) const{
	return board.at(coord.x).at(coord.y).has_value();
}


bool Chessboard::is_friend(const Coord& from, const Coord& to) const {
	return (is_piece(to) && (get_color(from) == get_color(to)));
}

bool Chessboard::is_enemy(const Coord& from, const Coord& to) const {
	return !(is_piece(to) && (get_color(from) != get_color(to)));
}

Piece Chessboard::get_piece(const Coord& coord) const {
	return board.at(coord.x).at(coord.y).value();
}

Color Chessboard::get_color(const Coord& coord) const{
	return board.at(coord.x).at(coord.y).value().color;
}



Chessboard Chessboard::update(const MovePiece& move_piece) {

	Chessboard new_board{};
	new_board.board = board;

	new_board.board.at(move_piece.to.x).at(move_piece.to.y) = new_board.get_piece(move_piece.from);

	new_board.board.at(move_piece.from.x).at(move_piece.from.y).reset();

	return new_board;
}
