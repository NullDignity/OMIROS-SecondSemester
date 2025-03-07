#include "Card.h"

Card::Card(string shape, int number) {
    setCardShape(shape);
    setCardNumber(number);
}

void Card::setCardShape(string shape) {
    if (shape == "Heart") {
        this->shape = "\3";
        setCardColor("red");
    } else if (shape == "Diamond") {
        this->shape = "\4";
        setCardColor("red");
    } else if (shape == "Club") {
        this->shape = "\5";
        setCardColor("black");
    } else if (shape == "Spade") {
        this->shape = "\6";
        setCardColor("black");
    } else {
        this->shape = "Wrong Shape";
        setCardColor("black");
    }
}

void Card::setCardNumber(int number) {
    if (number > 13 || number < 0)
        this->number = 0;
    else
        this->number = number;
    setCardSymbol(this->number);
}

void Card::setCardSymbol(int symbol) {
    switch (symbol) {
        case 0:
            this->symbol = "\0";
            break;
        case 1:
            this->symbol = "A";
            break;
        case 10:
            this->symbol = "1";
            break;
        case 11:
            this->symbol = "J";
            break;
        case 12:
            this->symbol = "Q";
            break;
        case 13:
            this->symbol = "K";
            break;
        default:
            this->symbol = to_string(symbol);
    }
}

void Card::setCardColor(string color) {
    if (color == "red")
        system("Color F4");
    else
        system("Color F0");
    this->color = color;
}

string Card::getCardColor() const {
    return this->color;
}

string Card::getCardShape() const {
    return this->shape;
}

int Card::getCardNumber() const {
    return this->number;
}

string Card::getCardSymbol() const {
    return this->symbol;
}

Card::~Card() {
    cout << "\nThe card will now be destroyed. \n";
}