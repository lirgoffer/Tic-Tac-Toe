#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Cell.h"
using namespace std;

class Board {
private:
    Cell *board;
    int size;

public:
    Board(); //defolt ctor
    Board(int size);  //ctor
    Board(const Board &board); //copy ctor
    ~Board();
    void print();
    bool set_symbol(int, char);
    int count_board();
    char get_symbol(int index);
};
