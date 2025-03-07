#ifndef CARD_H

#define CARD_H
    #include <iostream>
    #include <cstdlib>
    #include <string>
    using namespace std;

    class Card {
        private:
            string color;
            string shape;
            int number;
            string symbol;

        public:
            Card(string, int);
            void setCardShape(string);
            void setCardNumber(int);
            void setCardSymbol(int);
            void setCardColor(string);
            string getCardColor() const;
            string getCardShape() const;
            int getCardNumber() const;
            string getCardSymbol() const;
            ~Card();
    };

#endif