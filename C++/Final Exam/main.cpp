#include "Card.h"

#include <ctime>

void random_card(void) {

    unsigned random;
    string generated_shape;
    char empty_char;
    int generated_number;

    random = rand()%4;
    switch (random) {
        case 0:
            generated_shape = "Heart";
            break;
        case 1:
            generated_shape = "Diamond";
            break;
        case 2:
            generated_shape = "Club";
            break;
        default:
            generated_shape = "Spade";
    }
    
    random = rand()%13;
    random++;

    Card displayed_card(generated_shape, generated_number = random);
    if (displayed_card.getCardNumber() == 10)
        empty_char = '0';
    else
        empty_char = ' '; 

    cout << " ______________________\n";
    cout << "|                      |\n";
    cout << "| " << displayed_card.getCardSymbol() << empty_char << "                   |\n";
    cout << "| " << displayed_card.getCardShape() << "                    |\n";
    cout << "|                      |\n";
    cout << "|                      |\n";
    cout << "|                      |\n";
    cout << "|          " << displayed_card.getCardSymbol() << empty_char << "          |\n";
    cout << "|                      |\n";
    cout << "|                      |\n";
    cout << "|                      |\n";
    cout << "|                      |\n";
    cout << "|                  " << displayed_card.getCardShape() << "   |\n";
    cout << "|                  " << displayed_card.getCardSymbol() << empty_char << "  |\n";
    cout << " _______________________\n";
}

int main () {
    srand(time(NULL));
    random_card();

    system("PAUSE");
    return 0;
}