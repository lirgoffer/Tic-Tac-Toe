#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Board.h"
using namespace std;

class Player {
private:
    char *name;
    char symbol;
    Player(Player &); //copy ctor

public:
    Player(); //defolt ctor
    Player(char *, char); //ctor
    ~Player();
    char *getName() const; 
    void setName(char *);
    char getSymbol() const;
    void setSymbol(char);
    void print();
    int make_move();

};
