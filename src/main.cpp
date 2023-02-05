#include "SFML/Graphics.hpp"
#include <iostream>
#include <variant>

#include "config.h"
#include "piece.h"
#include "sprites.h"
#include "chessboard.h"
#include "display.h"
#include "constants.h"
#include "possible_moves.h"
#include "move_piece.h"

#pragma region variables

//Config
extern Config config{ "config.txt" };

//Texture
sf::Texture tex_board{};
sf::Texture tex_next{};

sf::Texture tex_wrook{};
sf::Texture tex_wknight{};
sf::Texture tex_wbishop{};
sf::Texture tex_wqueen{};
sf::Texture tex_wking{};
sf::Texture tex_wpawn{};

sf::Texture tex_brook{};
sf::Texture tex_bking{};
sf::Texture tex_bbishop{};
sf::Texture tex_bqueen{};
sf::Texture tex_bknight{};
sf::Texture tex_bpawn{};

//Piece managment
sf::Vector2i cursor_coord;

#pragma endregion variables



using game_t = std::vector<Chessboard>;


int main()
{
    Display display{};
    Sprites sprites{};

    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Test");
    sf::Event e;


    //config.print();

    //Loading sprites
    if (!tex_board.loadFromFile(config.board)) {
        throw std::runtime_error("Couldn't open board texture\n");
    }
    sprites.board.setTexture(tex_board);

    if (!tex_next.loadFromFile(config.help)) {
        throw std::runtime_error("Couldn't open help_img texture\n");
    }
    sprites.help.setTexture(tex_next);

    if (!tex_wking.loadFromFile(config.pieces, sf::IntRect(0 * SQUARE_WIDTH, 0 * SQUARE_WIDTH, SQUARE_WIDTH, SQUARE_WIDTH))) {
        throw std::runtime_error("Couldn't open pieces texture\n");
    }
    sprites.wking.setTexture(tex_wking);
    tex_wqueen.loadFromFile(config.pieces, sf::IntRect(1 * SQUARE_WIDTH, 0 * SQUARE_WIDTH, SQUARE_WIDTH, SQUARE_WIDTH));
    sprites.wqueen.setTexture(tex_wqueen);
    tex_wbishop.loadFromFile(config.pieces, sf::IntRect(2 * SQUARE_WIDTH, 0 * SQUARE_WIDTH, SQUARE_WIDTH, SQUARE_WIDTH));
    sprites.wbishop.setTexture(tex_wbishop);
    tex_wknight.loadFromFile(config.pieces, sf::IntRect(3 * SQUARE_WIDTH, 0 * SQUARE_WIDTH, SQUARE_WIDTH, SQUARE_WIDTH));
    sprites.wknight.setTexture(tex_wknight);
    tex_wrook.loadFromFile(config.pieces, sf::IntRect(4 * SQUARE_WIDTH, 0 * SQUARE_WIDTH, SQUARE_WIDTH, SQUARE_WIDTH));
    sprites.wrook.setTexture(tex_wrook);
    tex_wpawn.loadFromFile(config.pieces, sf::IntRect(5 * SQUARE_WIDTH, 0 * SQUARE_WIDTH, SQUARE_WIDTH, SQUARE_WIDTH));
    sprites.wpawn.setTexture(tex_wpawn);

    tex_bking.loadFromFile(config.pieces, sf::IntRect(0 * SQUARE_WIDTH, 1 * SQUARE_WIDTH, SQUARE_WIDTH, SQUARE_WIDTH));
    sprites.bking.setTexture(tex_bking);
    tex_bqueen.loadFromFile(config.pieces, sf::IntRect(1 * SQUARE_WIDTH, 1 * SQUARE_WIDTH, SQUARE_WIDTH, SQUARE_WIDTH));
    sprites.bqueen.setTexture(tex_bqueen);
    tex_bbishop.loadFromFile(config.pieces, sf::IntRect(2 * SQUARE_WIDTH, 1 * SQUARE_WIDTH, SQUARE_WIDTH, SQUARE_WIDTH));
    sprites.bbishop.setTexture(tex_bbishop);
    tex_bknight.loadFromFile(config.pieces, sf::IntRect(3 * SQUARE_WIDTH, 1 * SQUARE_WIDTH, SQUARE_WIDTH, SQUARE_WIDTH));
    sprites.bknight.setTexture(tex_bknight);
    tex_brook.loadFromFile(config.pieces, sf::IntRect(4 * SQUARE_WIDTH, 1 * SQUARE_WIDTH, SQUARE_WIDTH, SQUARE_WIDTH));
    sprites.brook.setTexture(tex_brook);
    tex_bpawn.loadFromFile(config.pieces, sf::IntRect(5 * SQUARE_WIDTH, 1 * SQUARE_WIDTH, SQUARE_WIDTH, SQUARE_WIDTH));
    sprites.bpawn.setTexture(tex_bpawn);



    window.setFramerateLimit(60);

    
    game_t game;
    game.emplace_back();

    Chessboard board = game.back();
    Color current_player = Color::White;

    MovePiece move_piece{};
    PossibleMoves possible_moves{};

    while (window.isOpen()) {
        


        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed) {
                window.close();
            }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                
                cursor_coord = sf::Mouse::getPosition(window);

                int x{ cursor_coord.y / SQUARE_WIDTH };
                int y{ cursor_coord.x / SQUARE_WIDTH };

                if ((-1 < x && x < N_ROW) && (-1 < y && y < N_ROW)) {

                    if (move_piece.is_empty && board.is_piece({ x, y })) {
                        if (current_player == board.get_color({ x, y })) {
                            move_piece.from = { x, y };
                            move_piece.is_empty = false;
                            if (config.need_help) {
                                std::cout << "bonjour";
                                possible_moves.get_all(board, move_piece.from);
                                std::cout << "bondoir";
                            }

                        }
                    }

                    else if (!move_piece.is_empty) {
                        if (board.is_piece({ x, y }) && (board.get_color({ x, y }) == board.get_color(move_piece.from)) ) {
                            move_piece.from = { x, y };

                            possible_moves.clear();
                            possible_moves.get_all(board, move_piece.from);
                        }
                        else {
                            move_piece.to = { x, y };
                            if ( (config.need_help ? possible_moves.contain(move_piece.to) : move_piece.is_possible(board)) ) {

                                game.emplace_back(board.update(move_piece));
                                board = game.back();
                                current_player = (current_player == Color::White ? Color::Black : Color::White);

                                move_piece.reinitialize();
                                possible_moves.clear();
                            }
                        }
                    }
                }

                
                
                std::cout << "From : (" << move_piece.from.x << ", " << move_piece.from.y << ")\n";
                std::cout << std::endl;
            }


            


        }




        display.board(window, sprites);
        if (config.need_help) {
            display.help(window, possible_moves, sprites);
        }
        display.pieces(window, board, sprites);
        window.display();
        window.clear();




    }

    return 0;
}
