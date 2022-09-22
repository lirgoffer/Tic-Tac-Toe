#include "Cell.h"

Cell::Cell() {     //defolt ctor
    this->cell = ' ';
    this->free = true;
}

void Cell::print() {
    cout << this->cell;
}


char Cell::getCell() const { //retur the cell sign
    return cell;
}

void Cell::setCell(char cell) { //update the cell
    this->cell = cell;
    this->free = false;
}

bool Cell::isFree() const {  //return if free
    return free;
}
