#include "display.h"
#include "SFML/Graphics.hpp"
#include "sprites.h"
#include "coord.h"
#include "sprites.h"



void Display::piece(const Piece& piece, Coord coord, sf::RenderWindow& window, Sprites& sprites) {
	if (piece.color == Color::White) {
		switch (piece.type) {
		case PieceType::King:
			sprites.wking.setPosition(static_cast<float>(coord.y * SQUARE_WIDTH), static_cast<float>(coord.x * SQUARE_WIDTH));
			window.draw(sprites.wking);
			break;
		case PieceType::Queen:
			sprites.wqueen.setPosition(static_cast<float>(coord.y * SQUARE_WIDTH), static_cast<float>(coord.x * SQUARE_WIDTH));
			window.draw(sprites.wqueen);
			break;
		case PieceType::Rook:
			sprites.wrook.setPosition(static_cast<float>(coord.y * SQUARE_WIDTH), static_cast<float>(coord.x * SQUARE_WIDTH));
			window.draw(sprites.wrook);
			break;
		case PieceType::Bishop:
			sprites.wbishop.setPosition(static_cast<float>(coord.y * SQUARE_WIDTH), static_cast<float>(coord.x * SQUARE_WIDTH));
			window.draw(sprites.wbishop);
			break;
		case PieceType::Knight:
			sprites.wknight.setPosition(static_cast<float>(coord.y * SQUARE_WIDTH), static_cast<float>(coord.x * SQUARE_WIDTH));
			window.draw(sprites.wknight);
			break;
		case PieceType::Pawn:
			sprites.wpawn.setPosition(static_cast<float>(coord.y * SQUARE_WIDTH), static_cast<float>(coord.x * SQUARE_WIDTH));
			window.draw(sprites.wpawn);
			break;		
		}
	}
	else {
		switch (piece.type) {
		case PieceType::King:
			sprites.bking.setPosition(static_cast<float>(coord.y * SQUARE_WIDTH), static_cast<float>(coord.x * SQUARE_WIDTH));
			window.draw(sprites.bking);
			break;
		case PieceType::Queen:
			sprites.bqueen.setPosition(static_cast<float>(coord.y * SQUARE_WIDTH), static_cast<float>(coord.x * SQUARE_WIDTH));
			window.draw(sprites.bqueen);
			break;
		case PieceType::Rook:
			sprites.brook.setPosition(static_cast<float>(coord.y * SQUARE_WIDTH), static_cast<float>(coord.x * SQUARE_WIDTH));
			window.draw(sprites.brook);
			break;
		case PieceType::Bishop:
			sprites.bbishop.setPosition(static_cast<float>(coord.y * SQUARE_WIDTH), static_cast<float>(coord.x * SQUARE_WIDTH));
			window.draw(sprites.bbishop);
			break;
		case PieceType::Knight:
			sprites.bknight.setPosition(static_cast<float>(coord.y * SQUARE_WIDTH), static_cast<float>(coord.x * SQUARE_WIDTH));
			window.draw(sprites.bknight);
			break;
		case PieceType::Pawn:
			sprites.bpawn.setPosition(static_cast<float>(coord.y * SQUARE_WIDTH), static_cast<float>(coord.x * SQUARE_WIDTH));
			window.draw(sprites.bpawn);
			break;
		}
	}
}


void Display::board(sf::RenderWindow& window, const Chessboard& board, Sprites& sprites) {
	window.draw(sprites.board);
	
	for (int i{ 0 }; i < N_ROW; i++) {
		for (int j{ 0 }; j < N_COL; j++) {
			if (board.is_piece({i, j})) {
				piece(board.get_piece({i, j}), {i, j}, window, sprites);
			}
		}
	}
}