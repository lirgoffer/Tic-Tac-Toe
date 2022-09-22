#include "Player.h"

Player::Player() {  //defolt ctor
    this->name = nullptr;
    this->symbol = ' ';
}

Player::Player(char *name, char symbol) { //ctor 

    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->symbol = symbol;
}

Player::~Player() {  //dtor
    delete[] this->name;
}

void Player::print() { //print player
    cout << "player name: " << this->name << "  with symbol: " << this->symbol << endl;
}

int Player::make_move() {  //get move and return it

    int move;
    cout << "choose your move:" << endl;
    cout << "Player name: " << this->name << " with symbol: " << this->symbol << endl;
    cin >> move;
    return move;
}

char *Player::getName() const { //return the name
    return name;
}

void Player::setName(char *name) {  //set the name
    this->name = new char[strlen(name) + 1];
    strcpy(this->name,name);
}

char Player::getSymbol() const {  //return the symbol
    return symbol;
}

void Player::setSymbol(char symbol) {  //set the symbol
    this->symbol = symbol;
}