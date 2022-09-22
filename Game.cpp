#include "Game.h"


Game::Game(char *name1, char *name2) { 

    this->players[0].setName(name1);  //set name
    this->players[0].setSymbol('X');  //set symbol
    this->players[1].setName(name2);  
    this->players[1].setSymbol('O');

    Board *b = new Board(9); // temp to set new board
    this->board = *b; 

    srand(time(nullptr));  //random choose
    int pr = rand() % 2;
    this->turn = players[pr].getSymbol();
    status = start;  //set status game to start
}

void Game::play() {

    int move = -1;
    while ((status != win) && (status != draw)) { //run the game

        system("cls");
        this->board.print();

        while (!this->board.set_symbol(move - 1, turn)) {  //make the move
            move = this->players[playerIndex()].make_move();  
        }

        if (isWinner()) { //in case of win
            status = win;
            system("cls");
            this->board.print();
            cout << "we have a winner! ";
            players[playerIndex()].print();
        } else if (this->board.count_board() == 0) { //in case of draw
            status = draw;
            system("cls");
            this->board.print();
            cout << "its a draw" << endl;
        }
        nextPlayer(); //change turn
    }
}

void Game::nextPlayer() {  //change the turn
    if (turn == 'X') {
        this->turn = 'O';
    } else {
        this->turn = 'X';
    }
}

int Game::playerIndex() {  //check player index
    if (this->turn == 'X') {
        return 0;
    }
    return 1;
}

bool Game::isWinner() { //check win by situation

    if (this->board.get_symbol(0) == this->turn && this->board.get_symbol(1) == this->turn &&
        this->board.get_symbol(2) == this->turn) {
        return true;
    } else if (this->board.get_symbol(3) == this->turn && this->board.get_symbol(4) == this->turn &&
               this->board.get_symbol(5) == this->turn) {
        return true;
    } else if (this->board.get_symbol(6) == this->turn && this->board.get_symbol(7) == this->turn &&
               this->board.get_symbol(8) == this->turn) {
        return true;
    } else if (this->board.get_symbol(0) == this->turn && this->board.get_symbol(3) == this->turn &&
               this->board.get_symbol(6) == this->turn) {
        return true;
    } else if (this->board.get_symbol(1) == this->turn && this->board.get_symbol(4) == this->turn &&
               this->board.get_symbol(7) == this->turn) {
        return true;
    } else if (this->board.get_symbol(2) == this->turn && this->board.get_symbol(5) == this->turn &&
               this->board.get_symbol(8) == this->turn) {
        return true;
    } else if (this->board.get_symbol(0) == this->turn && this->board.get_symbol(4) == this->turn &&
               this->board.get_symbol(8) == this->turn) {
        return true;
    } else if (this->board.get_symbol(2) == this->turn && this->board.get_symbol(4) == this->turn &&
               this->board.get_symbol(7) == this->turn) {
        return true;
    } else {
        return false;
    }
}

