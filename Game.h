#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Board.h"
#include "Player.h"
using namespace std;

enum statuses {
    win, draw, start
};

class Game {
private:
    Board board;
    Player players[2];
    statuses status;
    char turn;

public:
    Game(char *, char *);
    void play();
    void nextPlayer();
    int playerIndex();
    bool isWinner();  //check win
};
