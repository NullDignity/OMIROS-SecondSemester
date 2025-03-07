#include "GroundSquare.h"

GroundSquare::GroundSquare() {
    setAll("Plain",0,0);
}

void GroundSquare::setAll(string type, int xCoord, int yCoord) {
    this->type = type;
    this->xCoord = xCoord;
    this->yCoord = yCoord;
}

void GroundSquare::setType(string new_type) {
    this->type = new_type;
}

void GroundSquare::setXCoord(int new_xCoord) {
    if (new_xCoord > 0 && new_xCoord < 1000)
        this->xCoord = new_xCoord;
    else
        this->xCoord = 0;
}     

void GroundSquare::setYCoord(int new_yCoord) {
    if (new_yCoord > 0 && new_yCoord < 1000)
        this->yCoord = new_yCoord;
    else
        this->yCoord = 0;
}

void GroundSquare::incrementXCoordBy(int new_xCoord) {
    if (xCoord + new_xCoord > 0 && xCoord + new_xCoord < 1000)
        this->xCoord = xCoord + new_xCoord;
}

void GroundSquare::incrementYCoordBy(int new_yCoord) {
    if (yCoord + new_yCoord > 0 && yCoord + new_yCoord < 1000)
        this->yCoord = yCoord + new_yCoord;
}

string GroundSquare::getType() const {
    return this->type;
}

int GroundSquare::getXCoord() const {
    return this->xCoord;
}

int GroundSquare::getYCoord() const {
    return this->yCoord;
}

void GroundSquare::print() const {
    cout << "Type: " << this->type << endl;
    cout << "X Coordinate: " << this->xCoord << endl;
    cout << "Y CoordinatE: " << this->yCoord << endl;
}