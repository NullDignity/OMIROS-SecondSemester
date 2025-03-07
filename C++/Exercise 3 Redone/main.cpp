#include "Vehicle.h"

int main() {
    Vehicle player1; // GIVES DEFAULT VALUES FROM DEFAULT CONSTRUCTOR
    Vehicle player2("Tank",30,50,60,80); // GIVES CUSTOM VALUES FROM CUSTOM CONSTRUCTOR
    Vehicle player3(player2);
    player1.print();
    player2.print();
    player3.print();
    return 0;
}