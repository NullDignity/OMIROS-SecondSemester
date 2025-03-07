#ifndef VEHICLE_H // SIGNIFICANTLY SPEEDS UP CREATION OF CLASSES/OBJECTS

#define VEHICLE_H
    #include <iostream>
    using namespace std;

    class Vehicle {

        private:
            string id;
            int speed, attack, defense, range;
            // mutable int = reverses const for int value

        public:
            Vehicle(); // DEFAULT CONSTRUCTOR
            Vehicle(string, int, int, int, int); // CUSTOM CONSTRUCTOR
            Vehicle(Vehicle &); // COPY CONSTRUCTOR

            void setAll(string, int, int, int, int);
            void setId(string);
            void setSpeed(int);
            void setAttack(int);
            void setDefense(int);
            void setRange(int);
            string getId() const;
            int getSpeed() const;
            int getAttack() const;
            int getDefense() const;
            int getRange() const;
            void print() const;
    };

#endif