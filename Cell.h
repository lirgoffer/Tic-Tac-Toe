#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Cell {
private:
    char cell;
    bool free;

public:
    Cell(); 
    void print();
    char getCell() const; //getter
    void setCell(char cell); //setter
    bool isFree() const;
};
