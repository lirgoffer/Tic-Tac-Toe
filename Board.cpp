#include "Board.h"

Board::Board() : board(nullptr), size(0) {} //defolt ctor

Board::Board(int size) { //ctor that get size
    this->size = size;
    this->board = new Cell[size];
}

Board::Board(const Board &other) : size(other.size) {  //copy ctor 
    this->board = new Cell[other.size];
    for (int i = 0; i < size; i++) {
        board[i] = other.board[i];
    }
}

Board::~Board() {  //dtor
    delete[] this->board;

}

void Board::print() {  //print the board

    cout << "     |     |     " << endl;
    cout << "  " << board[0].getCell() << "  |  " << board[1].getCell() << "  |  " << board[2].getCell() << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << board[3].getCell() << "  |  " << board[4].getCell() << "  |  " << board[5].getCell() << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << board[6].getCell() << "  |  " << board[7].getCell() << "  |  " << board[8].getCell() << endl;

    cout << "     |     |     " << endl << endl;
}

bool Board::set_symbol(int index, char symbol) { //check if possibol,update and return if succseed

    if (index >= 0 && index <= 8 && this->board[index].isFree()) {
        this->board[index].setCell(symbol);
        return true;
    }
    return false;
}

int Board::count_board() { //count empty cells
    int counter = 0;
    for (int i = 0; i < 9; i++) {
        if (this->board[i].isFree()) {
            counter++;
        }
    }
    return counter;
}

char Board::get_symbol(int index) { //get the sign of the cell
    return this->board[index].getCell();
}
