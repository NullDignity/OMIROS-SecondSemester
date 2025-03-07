#ifndef GROUNDSQUARE_H

#define GROUNDSQUARE_H
    #include <iostream>
    using namespace std;

    class GroundSquare {
        private:
            string type;
            int xCoord, yCoord;
        public:
            GroundSquare();
            void setAll(string,int,int);
            void setType(string new_type);
            void setXCoord(int new_xCoord);
            void setYCoord(int new_yCoord);
            void incrementXCoordBy(int new_xCoord);
            void incrementYCoordBy(int new_yCoord);
            string getType() const;
            int getXCoord() const;
            int getYCoord() const;
            void print() const;
    };

#endif