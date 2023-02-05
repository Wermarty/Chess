#ifndef SPRITES_H
#define SPRITES_H


#include "SFML/Graphics.hpp"

struct Sprites {
    sf::Sprite board;
    sf::Sprite help;

    sf::Sprite bking;
    sf::Sprite bqueen;
    sf::Sprite bbishop;
    sf::Sprite bknight;
    sf::Sprite brook;
    sf::Sprite bpawn;

    sf::Sprite wking;
    sf::Sprite wqueen;
    sf::Sprite wbishop;
    sf::Sprite wknight;
    sf::Sprite wrook;
    sf::Sprite wpawn;
};

#endif